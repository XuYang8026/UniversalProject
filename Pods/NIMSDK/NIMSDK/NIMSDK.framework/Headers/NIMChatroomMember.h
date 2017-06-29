//
//  NIMChatroomMember.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  聊天室用户类型
 */
typedef NS_ENUM(NSInteger, NIMChatroomMemberType) {
    /**
     *  游客
     */
    NIMChatroomMemberTypeGuest   = -2,
    /**
     *  受限用户
     */
    NIMChatroomMemberTypeLimit   = -1,
    /**
     *  普通用户
     */
    NIMChatroomMemberTypeNormal  = 0,
    /**
     *  创建者
     */
    NIMChatroomMemberTypeCreator = 1,
    /**
     *  管理员
     */
    NIMChatroomMemberTypeManager = 2,
};

/**
 *  聊天室用户
 */
@interface NIMChatroomMember : NSObject

/**
 *  用户ID
 */
@property (nullable,nonatomic,copy)   NSString *userId;

/**
 *  聊天室内的昵称字段，由用户进聊天室时提交。
 */
@property (nullable,nonatomic,copy)   NSString *roomNickname;

/**
 *  聊天室内的头像字段，由用户进聊天室时提交。
 */
@property (nullable,nonatomic,copy)   NSString *roomAvatar;

/**
 *  用户在聊天室内的头像缩略图
 *  @discussion 仅适用于使用云信上传服务进行上传的资源，否则无效。
 */

@property (nullable,nonatomic,copy,readonly)  NSString    *roomAvatarThumbnail;

/**
 *  聊天室内预留给开发者的扩展字段，由用户进聊天室时提交。
 */
@property (nullable,nonatomic,copy)   NSString *roomExt;

/**
 *  用户类型
 */
@property (nonatomic,assign) NIMChatroomMemberType type;

/**
 *  是否被禁言
 */
@property (nonatomic,assign) BOOL isMuted;

/**
 *  是否被临时禁言
 *  @discussion 临时禁言和禁言属性无相关性
 */
@property (nonatomic,assign) BOOL isTempMuted;

/**
 *  临时禁言剩余时长
 */
@property (nonatomic,assign) unsigned long long tempMuteDuration;

/**
 *  是否被拉黑
 */
@property (nonatomic,assign) BOOL isInBlackList;

/**
 *  是否在线， 仅特殊成员才可能离线, 对游客用户而言只能是在线
 */
@property (nonatomic,assign) BOOL isOnline;

/**
 *  进入聊天室的时间点
 */
@property (nonatomic,assign) NSTimeInterval enterTimeInterval;

@end

NS_ASSUME_NONNULL_END
