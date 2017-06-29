//
//  NIMConversationManager.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NIMMessage;
@class NIMSession;
@class NIMRecentSession;
@class NIMHistoryMessageSearchOption;
@class NIMMessageSearchOption;



/**
 *  读取服务器消息记录block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param messages 读取的消息列表
 */
typedef void(^NIMFetchMessageHistoryBlock)(NSError * __nullable error,NSArray<NIMMessage *> * __nullable messages);

/**
 *  更新本地消息Block
 *
 *  @param error  错误,如果成功则error为nil
 */
typedef void(^NIMUpdateMessageBlock)(NSError * __nullable error);


/**
 *  标记远端会话Block
 *
 *  @param error  错误,如果成功则error为nil
 */
typedef void(^NIMRemoveRemoteSessionBlock)(NSError * __nullable error);


/**
 *  搜索本地消息记录Block
 *
 *  @param error  错误,如果成功则error为nil
 *  @param messages 读取的消息列表
 *  @discussion 只有在传入参数错误时才会有error产生
 */
typedef void(^NIMSearchMessageBlock)(NSError * __nullable error,NSArray<NIMMessage *> * __nullable messages);

/**
 *  全局搜索本地消息记录Block
 *
 *  @param error      错误,如果成功则error为nil
 *  @param messages   读取的消息列表
 */
typedef void(^NIMGlobalSearchMessageBlock)(NSError * __nullable error,NSDictionary<NIMSession *,NSArray<NIMMessage *> *> * __nullable messages);

/**
 *  会话管理器回调
 */
@protocol NIMConversationManagerDelegate <NSObject>

@optional

/**
 *  增加最近会话的回调
 *
 *  @param recentSession    最近会话
 *  @param totalUnreadCount 目前总未读数
 *  @discussion 当新增一条消息，并且本地不存在该消息所属的会话时，会触发此回调。
 */
- (void)didAddRecentSession:(NIMRecentSession *)recentSession
           totalUnreadCount:(NSInteger)totalUnreadCount;

/**
 *  最近会话修改的回调
 *
 *  @param recentSession    最近会话
 *  @param totalUnreadCount 目前总未读数
 *  @discussion 触发条件包括: 1.当新增一条消息，并且本地存在该消息所属的会话。
 *                          2.所属会话的未读清零。
 *                          3.所属会话的最后一条消息的内容发送变化。(例如成功发送后，修正发送时间为服务器时间)
 *                          4.删除消息，并且删除的消息为当前会话的最后一条消息。
 */
- (void)didUpdateRecentSession:(NIMRecentSession *)recentSession
              totalUnreadCount:(NSInteger)totalUnreadCount;

/**
 *  删除最近会话的回调
 *
 *  @param recentSession    最近会话
 *  @param totalUnreadCount 目前总未读数
 */
- (void)didRemoveRecentSession:(NIMRecentSession *)recentSession
              totalUnreadCount:(NSInteger)totalUnreadCount;

/**
 *  单个会话里所有消息被删除的回调
 *
 *  @param session 消息所属会话
 */
- (void)messagesDeletedInSession:(NIMSession *)session;

/**
 *  所有消息被删除的回调
 *
 */
- (void)allMessagesDeleted;


@end

/**
 *  会话管理器
 */
@protocol NIMConversationManager <NSObject>

/**
 *  删除某条消息
 *
 *  @param message 待删除的聊天消息
 */
- (void)deleteMessage:(NIMMessage *)message;

/**
 *  删除某个会话的所有消息
 *
 *  @param session 待删除会话
 *  @param removeRecentSession 是否移除对应的会话项  YES则移除,NO则不移除。
 */
- (void)deleteAllmessagesInSession:(NIMSession *)session
               removeRecentSession:(BOOL)removeRecentSession;

/**
 *  删除所有会话消息
 *
 *  @param removeRecentSessions 是否移除会话项,YES则移除,NO则不移除，但会将所有会话项设置成已删除状态
 *  @discussion 调用这个接口只会触发allMessagesDeleted这个回调，其他针对单个recentSession的回调都不会被调用
 */
- (void)deleteAllMessages:(BOOL)removeRecentSessions;


/**
 *  删除某个最近会话
 *
 *  @param recentSession 待删除的最近会话
 *  @discussion 异步方法，删除最近会话，但保留会话内消息
 */
- (void)deleteRecentSession:(NIMRecentSession *)recentSession;


/**
 *  设置一个会话里所有消息置为已读
 *
 *  @param session 需设置的会话
 *  @discussion 异步方法，消息会标记为设置的状态
 */
- (void)markAllMessagesReadInSession:(NIMSession *)session;


/**
 *  更新本地已存的消息记录
 *
 *  @param message 需要更新的消息
 *  @param session 需要更新的会话
 *  @param completion 完成后的回调
 *  @discussion 为了保证存储消息的完整性,提供给上层调用的消息更新接口只允许更新如下字段:所有消息的本地拓展字段(LocalExt)和自定义消息的消息对象(messageObject)
 */
- (void)updateMessage:(NIMMessage *)message
           forSession:(NIMSession *)session
           completion:(nullable NIMUpdateMessageBlock)completion;


/**
 *  写入消息
 *
 *  @param message 需要更新的消息
 *  @param session 需要更新的消息
 *  @param completion 完成后的回调
 *  @discussion 当保存消息成功之后，会收到 NIMChatManagerDelegate 中的 onRecvMessages: 回调。目前支持消息类型:NIMMessageTypeText,NIMMessageTypeTip,NIMMessageTypeCustom
 */
- (void)saveMessage:(NIMMessage *)message
         forSession:(NIMSession *)session
         completion:(nullable NIMUpdateMessageBlock)completion;




/**
 *  从本地db读取一个会话里某条消息之前的若干条的消息
 *
 *  @param session 消息所属的会话
 *  @param message 当前最早的消息,没有则传入nil
 *  @param limit   个数限制
 *
 *  @return 消息列表，按时间从小到大排列
 */
- (nullable NSArray<NIMMessage *> *)messagesInSession:(NIMSession *)session
                                              message:(nullable NIMMessage *)message
                                                limit:(NSInteger)limit;


/**
 *  根据消息Id获取消息
 *
 *  @param session    消息所属会话结合
 *
 *  @param messageIds 消息Id集合
 *
 *  @return 消息列表,按时间从小到大排列
 */
- (nullable NSArray<NIMMessage *> *)messagesInSession:(NIMSession *)session
                                           messageIds:(NSArray<NSString *> *)messageIds;

/**
 *  获取所有未读数
 *  @discussion 只能在主线程调用,包括忽略提醒的会话
 *  @return 未读数
 */
- (NSInteger)allUnreadCount;

/**
 *  获取所有最近会话
 *  @discussion 只能在主线程调用
 *  @return 最近会话列表
 *  @discussion SDK 以 map 的形式保存 sessions，调用这个方法是将进行排序，数据量较大 (上万) 时会比较耗时。
 */
- (nullable NSArray<NIMRecentSession *> *)allRecentSessions;


/**
 *  根据当前 session 返回对应的最近会话信息
 *
 *  @param session 会话
 *
 *  @return 最近会话信息，如果找不到则返回 nil
 */
- (nullable NIMRecentSession *)recentSessionBySession:(NIMSession *)session;


/**
 *  从服务器上获取一个会话里某条消息之前的若干条的消息
 *
 *  @param session 消息所属的会话
 *  @param option  搜索选项
 *  @param result  读取的消息列表结果
 *  @discussion    此接口不支持查询聊天室消息，聊天室请参考 NIMChatroomManagerProtocol 中的查询消息接口。
 *
 */
- (void)fetchMessageHistory:(NIMSession *)session
                     option:(NIMHistoryMessageSearchOption *)option
                     result:(nullable NIMFetchMessageHistoryBlock)result;



/**
 *  搜索本地会话内消息
 *
 *  @param session 消息所属的会话
 *  @param option  搜索选项
 *  @param result  读取的消息列表结果
 *
 */
- (void)searchMessages:(NIMSession *)session
                option:(NIMMessageSearchOption *)option
                result:(nullable NIMSearchMessageBlock)result;

/**
 *  全局搜索本地消息
 *
 *  @param option 搜索选项
 *  @param result 读取的消息内容
 */
- (void)searchAllMessages:(NIMMessageSearchOption *)option
                   result:(nullable NIMGlobalSearchMessageBlock)result;



/**
 *  删除服务器端最近会话
 *
 *  @param sessions   需要删除的会话列表，内部只能是NIMSession
 *  @param completion 完成的回调
 *  @discussion       调用这个接口成功后，当前会话之前的消息都不会漫游到其他端
 */
- (void)deleteRemoteSessions:(NSArray<NIMSession *> *)sessions
                  completion:(nullable NIMRemoveRemoteSessionBlock)completion;


/**
 *  更新最近会话的本地扩展
 *
 *  @param ext           扩展信息
 *  @param recentSession 要更新的最近会话
 *  @discussion          此扩展不会漫游到其他端,上层需要保证 NSDictionary 可以转换为 JSON。
 */
- (void)updateRecentLocalExt:(nullable NSDictionary *)ext
               recentSession:(NIMRecentSession *)recentSession;

/**
 *  添加通知对象
 *
 *  @param delegate 通知对象
 */
- (void)addDelegate:(id<NIMConversationManagerDelegate>)delegate;

/**
 *  删除通知对象
 *
 *  @param delegate 通知对象
 */
- (void)removeDelegate:(id<NIMConversationManagerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END



