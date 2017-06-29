//
//  NIMUserManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NIMUserRequest;
@class NIMUser;

/**
 *  好友操作Block
 *
 *  @param error 错误信息
 */
typedef void(^NIMUserBlock)(NSError * __nullable error);

/**
 *  用户信息获取Block,返回NIMUser列表
 *
 *  @param error 错误信息
 */
typedef void(^NIMUserInfoBlock)(NSArray<NIMUser *> * __nullable users,NSError * __nullable error);



/**
 *  用户信息修改字段
 */
typedef NS_ENUM(NSInteger, NIMUserInfoUpdateTag) {
    /**
     *  用户昵称
     */
    NIMUserInfoUpdateTagNick   = 3,
    /**
     *  用户头像
     */
    NIMUserInfoUpdateTagAvatar = 4,
    /**
     *  用户签名
     */
    NIMUserInfoUpdateTagSign   = 5,
    /**
     *  用户性别。请使用指定枚举,如 {@(NIMUserInfoUpdateTagGender) : @(NIMUserGenderMale)}
     */
    NIMUserInfoUpdateTagGender = 6,
    /**
     *  用户邮箱。请使用合法邮箱
     */
    NIMUserInfoUpdateTagEmail  = 7,
    /**
     *  用户生日。具体格式为yyyy-MM-dd
     */
    NIMUserInfoUpdateTagBirth  = 8,
    /**
     *  用户手机号。请使用合法手机号
     */
    NIMUserInfoUpdateTagMobile = 9,
    /**
     *  扩展字段
     */
    NIMUserInfoUpdateTagExt = 10,
};

/**
 *  好友协议委托
 */
@protocol NIMUserManagerDelegate <NSObject>

@optional

/**
 *  好友状态发生变化 (在线)
 *
 *  @param user 用户对象
 */
- (void)onFriendChanged:(NIMUser *)user;

/**
 *  黑名单列表发生变化 (在线)
 */
- (void)onBlackListChanged;

/**
 *  静音列表发生变化 (在线)
 */
- (void)onMuteListChanged;

/**
 *  用户个人信息发生变化 (在线)
 *
 *  @param user 用户对象
 *  @discussion 出于性能和上层 APP 处理难易度的考虑，本地调用批量接口获取用户信息时不触发当前回调。
 */
- (void)onUserInfoChanged:(NIMUser *)user;

@end

/**
 *  好友协议
 */
@protocol NIMUserManager <NSObject>

/**
 *  添加好友
 *
 *  @param request    添加好友请求
 *  @param completion 完成回调
 */
- (void)requestFriend:(NIMUserRequest *)request
           completion:(nullable NIMUserBlock)completion;

/**
 *  删除好友
 *
 *  @param userId      好友Id
 *  @param completion  完成回调
 */
- (void)deleteFriend:(NSString *)userId
          completion:(nullable NIMUserBlock)completion;

/**
 *  返回我的好友列表
 *
 *  @return NIMUser列表
 */
- (nullable NSArray<NIMUser *> *)myFriends;


/**
 *  判断是否是我的好友
 *
 *  @param userId 用户Id
 *
 *  @return 是否是我的好友 (云信关系)
 */
- (BOOL)isMyFriend:(NSString *)userId;


/**
 *  添加用户到黑名单
 *
 *  @param userId          用户Id
 *  @param completion      完成回调
 */
- (void)addToBlackList:(NSString *)userId
            completion:(NIMUserBlock)completion;

/**
 *  将用户从黑名单移除
 *
 *  @param userId        用户Id
 *  @param completion    完成回调
 */
- (void)removeFromBlackBlackList:(NSString *)userId
                      completion:(NIMUserBlock)completion;

/**
 *  判断用户是否已被拉黑
 *
 *  @param userId 用户Id
 *
 *  @return 是否已被拉黑
 */
- (BOOL)isUserInBlackList:(NSString *)userId;

/**
 *  返回所有在黑名单中的用户列表
 *
 *  @return 黑名单成员NIMUser列表
 */
- (nullable NSArray<NIMUser *> *)myBlackList;


/**
 *  设置消息提醒
 *
 *  @param notify       是否提醒
 *  @param userId       用户Id
 *  @param completion   完成回调
 */
- (void)updateNotifyState:(BOOL)notify
                  forUser:(NSString *)userId
               completion:(nullable NIMUserBlock)completion;


/**
 *  是否需要消息通知
 *
 *  @param userId 用户Id
 *
 *  @return 是否需要消息通知
 */
- (BOOL)notifyForNewMsg:(NSString *)userId;

/**
 *  静音列表
 *
 *  @return 返回被我设置为取消消息通知的NIMUser列表
 */
- (nullable NSArray<NIMUser *> *)myMuteUserList;


/**
 *  从云信服务器批量获取用户资料
 *
 *  @param users       用户id列表
 *  @param completion  用户信息回调
 *
 *  @discussion 需要将用户信息交给云信托管，此接口才有效。调用此接口，不会触发 - (void)onUserInfoChanged: 回调。
 *              该接口会将获取到的用户信息缓存在本地，所以需要避免此接口的滥调，导致存储过多无用数据到本地而撑爆缓存:如在聊天室请求请求每个聊天室用户数据将造成缓存过大而影响程序性能
 *              本接口一次最多支持 150 个用户信息获取
 */
- (void)fetchUserInfos:(NSArray<NSString *> *)users
            completion:(nullable NIMUserInfoBlock)completion;


/**
 *  从本地获取用户资料
 *
 *  @param  userId 用户id
 *
 *  @return NIMUser
 *
 *  @discussion 需要将用户信息交给云信托管，且数据已经正常缓存到本地，此接口才有效。
 *              用户资料除自己之外，不保证其他用户资料实时更新
 *              其他用户资料更新的时机为: 1.调用 - (void)fetchUserInfos:completion: 方法刷新用户
 *                                    2.收到此用户发来消息
 *                                    3.程序再次启动，此时会同步好友信息
 */
- (nullable NIMUser *)userInfo:(NSString *)userId;


/**
 *  修改自己与目标用户的关系
 *
 *  @param user       目标用户
 *  @param completion 修改结果回调
 *  @discussion  这个接口提供了备注名的修改以及一些扩展。这些值是基于当前用户和目标用户关系的，
 *               同一个目标用户的的属性字段会随着登录用户的改变而改变。
 *
 */
- (void)updateUser:(NIMUser *)user
        completion:(nullable NIMUserBlock)completion;


/**
 *  修改自己的用户资料
 *
 *  @param values      需要更新的用户信息键值对
 *  @param completion  修改结果回调
 *
 *  @discussion   这个接口可以一次性修改多个属性,如昵称,头像等,传入的数据键值对是 {@(NIMUserInfoUpdateTag) : NSString},
 *                无效数据将被过滤。一些字段有修改限制，具体请参看 NIMUserInfoUpdateTag 的相关说明
 */
- (void)updateMyUserInfo:(NSDictionary<NSNumber *,NSString *> *)values
              completion:(nullable NIMUserBlock)completion;

/**
 *  添加好友委托
 *
 *  @param delegate 好友委托
 */
- (void)addDelegate:(id<NIMUserManagerDelegate>)delegate;

/**
 *  移除好友委托
 *
 *  @param delegate 好友委托
 */
- (void)removeDelegate:(id<NIMUserManagerDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
