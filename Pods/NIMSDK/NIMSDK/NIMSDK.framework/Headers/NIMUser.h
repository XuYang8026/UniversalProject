//
//  NIMUser.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NIMUserInfo;

/**
 *  好友操作类型
 */
typedef NS_ENUM(NSInteger, NIMUserOperation){
    /**
     *  添加好友
     *  @discussion 直接添加为好友,无需验证
     */
    NIMUserOperationAdd     =   1,
    /**
     *  请求添加好友
     */
    NIMUserOperationRequest =   2,
    /**
     *  通过添加好友请求
     */
    NIMUserOperationVerify  =   3,
    /**
     *  拒绝添加好友请求
     */
    NIMUserOperationReject  =   4,
};

/**
 *  用户性别
 */
typedef NS_ENUM(NSInteger, NIMUserGender) {
    /**
     *  未知性别
     */
    NIMUserGenderUnknown,
    /**
     *  性别男
     */
    NIMUserGenderMale,
    /**
     *  性别女
     */
    NIMUserGenderFemale,
};

/**
 *  云信用户
 */
@interface NIMUser : NSObject

/**
 *  用户Id
 */
@property (nullable,nonatomic,copy)   NSString    *userId;

/**
 *  备注名，长度限制为128个字符。
 */
@property (nullable,nonatomic,copy)   NSString    *alias;

/**
 *  扩展字段
 */
@property (nullable,nonatomic,copy)   NSString  *ext;

/**
 *  用户资料，仅当用户选择托管信息到云信时有效
 *  用户资料除自己之外，不保证其他用户资料实时更新
 *  其他用户资料更新的时机为: 1.调用 - (void)fetchUserInfos:completion: 方法刷新用户
 *                        2.收到此用户发来消息
 *                        3.程序再次启动，此时会同步好友信息
 */
@property (nullable,nonatomic,strong,readonly) NIMUserInfo *userInfo;

/**
 *  是否需要消息提醒
 *
 *  @return 是否需要消息提醒
 */
- (BOOL)notifyForNewMsg;

/**
 *  是否在黑名单中
 *
 *  @return 是否在黑名单中
 */

- (BOOL)isInMyBlackList;

@end


/**
 *  用户资料，仅当用户选择托管信息到云信时有效
 */
@interface NIMUserInfo : NSObject

/**
 *  用户昵称
 */
@property (nullable,nonatomic,copy,readonly) NSString *nickName;

/**
 *  用户头像
 */
@property (nullable,nonatomic,copy,readonly) NSString *avatarUrl;

/**
 *  用户头像缩略图
 *  @discussion 仅适用于使用云信上传服务进行上传的资源，否则无效。
 */
@property (nullable,nonatomic,copy,readonly) NSString *thumbAvatarUrl;

/**
 *  用户签名
 */
@property (nullable,nonatomic,copy,readonly) NSString *sign;

/**
 *  用户性别
 */
@property (nonatomic,assign,readonly) NIMUserGender gender;

/**
 *  邮箱
 */
@property (nullable,nonatomic,copy,readonly) NSString *email;

/**
 *  生日
 */
@property (nullable,nonatomic,copy,readonly) NSString *birth;

/**
 *  电话号码
 */
@property (nullable,nonatomic,copy,readonly) NSString *mobile;

/**
 *  用户自定义扩展字段
 */
@property (nullable,nonatomic,copy,readonly) NSString *ext;


@end

/**
 *  好友请求
 */
@interface NIMUserRequest : NSObject
/**
 *  目标用户ID
 */
@property (nonatomic,copy)      NSString            *userId;

/**
 *  操作类型
 */
@property (nonatomic,assign)    NIMUserOperation    operation;

/**
 *  附言
 */
@property (nullable,nonatomic,copy)      NSString            *message;

@end

NS_ASSUME_NONNULL_END
