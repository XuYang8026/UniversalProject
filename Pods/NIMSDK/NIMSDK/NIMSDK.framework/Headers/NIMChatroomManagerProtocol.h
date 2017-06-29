//
//  NIMChatroomManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NIMMessage;
@class NIMChatroom;
@class NIMChatroomEnterRequest;
@class NIMChatroomUpdateRequest;
@class NIMChatroomMemberInfoUpdateRequest;
@class NIMChatroomMember;
@class NIMChatroomMemberRequest;
@class NIMChatroomMemberUpdateRequest;
@class NIMChatroomMemberKickRequest;
@class NIMChatroomMembersByIdsRequest;
@class NIMChatroomQueueUpdateRequest;
@class NIMChatroomQueueRemoveRequest;
@class NIMHistoryMessageSearchOption;
/**
 *  聊天室网络请求回调
 *
 *  @param error 错误信息
 */
typedef void(^NIMChatroomHandler)(NSError * __nullable error);

/**
 *  聊天室成员请求回调
 *
 *  @param error  错误信息
 *  @param member 更新后的聊天室成员信息
 */
typedef void(^NIMChatroomMemberHandler)(NSError * __nullable error,NIMChatroomMember * __nullable member);

/**
 *  进入聊天室请求回调
 *
 *  @param error    错误信息
 *  @param chatroom 聊天室信息
 *  @param me       自己在聊天室内的信息
 */
typedef void(^NIMChatroomEnterHandler)(NSError * __nullable error,NIMChatroom * __nullable chatroom,NIMChatroomMember * __nullable me);


/**
 *  聊天室信息请求回调
 *
 *  @param error    错误信息
 *  @param chatroom 聊天室信息
 */
typedef void(^NIMChatroomInfoHandler)(NSError * __nullable error,NIMChatroom * __nullable chatroom);

/**
 *  聊天室成员组网络数据回调
 *
 *  @param error 错误信息
 */
typedef void(^NIMChatroomMembersHandler)(NSError * __nullable error, NSArray<NIMChatroomMember *> * __nullable members);


/**
 *  聊天室队列数据回调
 *
 *  @param error 错误信息
 */
typedef void(^NIMChatroomQueueInfoHandler)(NSError * __nullable error, NSArray<NSDictionary<NSString *, NSString *> *> * __nullable info);


/**
 *  聊天室队列移除元素回调
 *
 *  @param error 错误信息
 */
typedef void(^NIMChatroomQueueRemoveHandler)(NSError * __nullable error, NSDictionary<NSString *, NSString *> * __nullable element);



/**
 *  拉取服务器聊天消息记录block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param messages 读取的消息列表
 */
typedef void(^NIMFetchChatroomHistoryBlock)(NSError * __nullable error,NSArray<NIMMessage *> * __nullable messages);



/**
 *  聊天室连接状态
 */
typedef NS_ENUM(NSInteger, NIMChatroomConnectionState) {
    /**
     *  正在进入
     */
    NIMChatroomConnectionStateEntering        = 0,
    /**
     *  进入聊天室成功
     */
    NIMChatroomConnectionStateEnterOK         = 1,
    /**
     *  进入聊天室失败
     */
    NIMChatroomConnectionStateEnterFailed      = 2,
    /**
     *  和聊天室失去连接
     */
    NIMChatroomConnectionStateLoseConnection   = 3,
};

/**
 *  聊天室被踢原因
 */
typedef NS_ENUM(NSInteger, NIMChatroomKickReason) {
    /**
     *  聊天室已经解散
     */
    NIMChatroomKickReasonInvalidRoom     = 1,
    /**
     *  被聊天室管理员踢出
     */
    NIMChatroomKickReasonByManager       = 2,
    /**
     *  多端被踢
     */
    NIMChatroomKickReasonByConflictLogin = 3,
    /**
     *  被拉黑
     */
    NIMChatroomKickReasonBlacklist       = 5,
    
};


/**
 *  聊天室管理器回调
 */
@protocol NIMChatroomManagerDelegate <NSObject>

@optional
/**
 *  被踢回调
 *
 *  @param roomId   被踢的聊天室Id
 *  @param reason   被踢原因
 */
- (void)chatroom:(NSString *)roomId beKicked:(NIMChatroomKickReason)reason;


/**
 *  聊天室连接状态变化
 *
 *  @param roomId 聊天室Id
 *  @param state  当前状态
 */
- (void)chatroom:(NSString *)roomId connectionStateChanged:(NIMChatroomConnectionState)state;

/**
 *  聊天室自动登录出错
 *
 *  @param roomId 聊天室Id
 *  @param error  自动登录出错原因
 */
- (void)chatroom:(NSString *)roomId autoLoginFailed:(NSError *)error;

@end

/**
 *  聊天室管理器
 */
@protocol NIMChatroomManager <NSObject>

/**
 *  进入聊天室
 *
 *  @param request    进入聊天室请求
 *  @param completion 进入完成后的回调
 */
- (void)enterChatroom:(NIMChatroomEnterRequest *)request
           completion:(nullable NIMChatroomEnterHandler)completion;

/**
 *  离开聊天室
 *
 *  @param roomId     聊天室ID
 *  @param completion 离开聊天室的回调
 */
- (void)exitChatroom:(NSString *)roomId
          completion:(nullable NIMChatroomHandler)completion;


/**
 *  查询服务器保存的聊天室消息记录
 *
 *  @param roomId  聊天室ID
 *  @param option  查询选项
 *  @param result   完成回调
 */
- (void)fetchMessageHistory:(NSString *)roomId
                     option:(NIMHistoryMessageSearchOption *)option
                     result:(nullable NIMFetchChatroomHistoryBlock)result;


/**
 *  获取聊天室信息
 *
 *  @param roomId     聊天室ID
 *  @param completion 获取聊天室信息的回调
 *  @discussion 只有已进入聊天室才能够获取对应的聊天室信息
 */
- (void)fetchChatroomInfo:(NSString *)roomId
               completion:(nullable NIMChatroomInfoHandler)completion;


/**
 *  修改聊天室信息
 *
 *  @param request    聊天室修改请求
 *  @param completion 修改后完成的回调
 */
- (void)updateChatroomInfo:(NIMChatroomUpdateRequest *)request
                completion:(nullable NIMChatroomHandler)completion;


/**
 *  修改自己在聊天室内的个人信息
 *
 *  @param request    个人信息更新请求
 *  @param completion 修改完成后的回调
 */
- (void)updateMyChatroomMemberInfo:(NIMChatroomMemberInfoUpdateRequest *)request
                        completion:(nullable NIMChatroomHandler)completion;


/**
 *  获取聊天室成员
 *
 *  @param request    获取成员请求
 *  @param completion 请求完成回调
 */
- (void)fetchChatroomMembers:(NIMChatroomMemberRequest *)request
                  completion:(nullable NIMChatroomMembersHandler)completion;


/**
 *  根据用户ID获取聊天室成员信息
 *
 *  @param request    获取成员请求
 *  @param completion 请求完成回调
 */
- (void)fetchChatroomMembersByIds:(NIMChatroomMembersByIdsRequest *)request
                       completion:(nullable NIMChatroomMembersHandler)completion;


/**
 *  标记为聊天室管理员
 *
 *  @param request    更新请求
 *  @param completion 请求回调
 */
- (void)markMemberManager:(NIMChatroomMemberUpdateRequest *)request
               completion:(nullable NIMChatroomHandler)completion;

/**
 *  标记为聊天室普通成员
 *
 *  @param request    更新请求
 *  @param completion 请求回调
 */
- (void)markNormalMember:(NIMChatroomMemberUpdateRequest *)request
              completion:(nullable NIMChatroomHandler)completion;

/**
 *  更新用户聊天室黑名单状态
 *
 *  @param request    更新请求
 *  @param completion 请求回调
 */
- (void)updateMemberBlack:(NIMChatroomMemberUpdateRequest *)request
               completion:(nullable NIMChatroomHandler)completion;


/**
 *  更新用户聊天室静言状态
 *
 *  @param request    更新请求
 *  @param completion 请求回调
 */
- (void)updateMemberMute:(NIMChatroomMemberUpdateRequest *)request
              completion:(nullable NIMChatroomHandler)completion;



/**
 *  更新用户聊天室临时禁言状态
 *
 *  @param request    更新请求
 *  @param duration   临时禁言时长，单位为妙
 *  @param completion 请求回调
 */
- (void)updateMemberTempMute:(NIMChatroomMemberUpdateRequest *)request
                    duration:(unsigned long long)duration
                  completion:(nullable NIMChatroomHandler)completion;
/**
 *  将特定成员踢出聊天室
 *
 *  @param request    踢出请求
 *  @param completion 请求回调
 */
- (void)kickMember:(NIMChatroomMemberKickRequest *)request
        completion:(nullable NIMChatroomHandler)completion;


/**
 *  更新聊天室通用队列
 *
 *  @param request    聊天室队列请求
 *  @param completion 请求回调
 */
- (void)updateChatroomQueueObject:(NIMChatroomQueueUpdateRequest *)request
                       completion:(nullable NIMChatroomHandler)completion;


/**
 *  移除聊天室队列元素
 *
 *  @param request    拉取请求
 *  @param completion 请求回调
 */
- (void)removeChatroomQueueObject:(NIMChatroomQueueRemoveRequest *)request
                       completion:(nullable NIMChatroomQueueRemoveHandler)completion;


/**
 *  获取聊天室通用队列
 *
 *  @param roomId     聊天室ID
 *  @param completion 请求回调
 */
- (void)fetchChatroomQueue:(NSString *)roomId
                completion:(nullable NIMChatroomQueueInfoHandler)completion;


/**
 *  删除聊天室通用队列
 *
 *  @param roomId     聊天室ID
 *  @param completion 请求回调
 */
- (void)dropChatroomQueue:(NSString *)roomId
               completion:(nullable NIMChatroomHandler)completion;



/**
 *  添加通知对象
 *
 *  @param delegate 通知对象
 */
- (void)addDelegate:(id<NIMChatroomManagerDelegate>)delegate;

/**
 *  移除通知对象
 *
 *  @param delegate 通知对象
 */
- (void)removeDelegate:(id<NIMChatroomManagerDelegate>)delegate;

@end


NS_ASSUME_NONNULL_END
