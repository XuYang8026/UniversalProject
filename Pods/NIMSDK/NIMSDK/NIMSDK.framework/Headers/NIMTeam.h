//
//  NIMTeam.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMTeamDefs.h"


NS_ASSUME_NONNULL_BEGIN

/**
 *  群组信息
 */
@interface NIMTeam : NSObject
/**
 *  群ID
 */
@property (nullable,nonatomic,copy,readonly)      NSString *teamId;

/**
 *  群名称
 */
@property (nullable,nonatomic,copy)               NSString *teamName;

/**
 *  群头像
 */
@property (nullable,nonatomic,copy)               NSString *avatarUrl;

/**
 *  群缩略头像
 *  @discussion 仅适用于使用云信上传服务进行上传的资源，否则无效。
 */
@property (nullable,nonatomic,copy)               NSString *thumbAvatarUrl;

/**
 *  群类型
 */
@property (nonatomic,assign,readonly)    NIMTeamType type;

/**
 *  群拥有者ID
 *  @discussion 普通群拥有者就是群创建者,但是高级群可以进行拥有信息的转让
 */
@property (nullable,nonatomic,copy,readonly)      NSString *owner;

/**
 *  群介绍
 */
@property (nullable,nonatomic,copy)              NSString *intro;

/**
 *  群公告
 */
@property (nullable,nonatomic,copy)              NSString *announcement;

/**
 *  群成员人数
 *  @discussion 这个值表示是上次登录后同步下来群成员数据,并不实时变化,必要时需要调用fetchTeamInfo:completion:进行刷新
 */
@property (nonatomic,assign,readonly)   NSInteger memberNumber;

/**
 *  群等级
 *  @discussion 目前群人数主要是限制群人数上限
 */
@property (nonatomic,assign,readonly)    NSInteger level;

/**
 *  群创建时间
 */
@property (nonatomic,assign,readonly)    NSTimeInterval createTime;

/**
 *  群验证方式
 *  @discussion 只有高级群有效
 */
@property (nonatomic,assign)   NIMTeamJoinMode joinMode;

/**
 *  群邀请权限
 *  @discussion 只有高级群有效
 */
@property (nonatomic,assign)    NIMTeamInviteMode inviteMode;

/**
 *  被邀请模式
 *  @discussion 只有高级群有效
 */
@property (nonatomic,assign)    NIMTeamBeInviteMode beInviteMode;

/**
 *  修改群信息权限
 *  @discussion 只有高级群有效
 */
@property (nonatomic,assign)    NIMTeamUpdateInfoMode updateInfoMode;

/**
 *  修改群客户端自定义字段权限
 *  @discussion 只有高级群有效
 */
@property (nonatomic,assign)    NIMTeamUpdateClientCustomMode updateClientCustomMode;


/**
 *  群服务端自定义信息
 *  @discussion 应用方可以自行拓展这个字段做个性化配置,客户端不可以修改这个字段
 */
@property (nullable,nonatomic,copy,readonly)      NSString *serverCustomInfo;


/**
 *  群客户端自定义信息
 *  @discussion 应用方可以自行拓展这个字段做个性化配置,客户端可以修改这个字段
 */
@property (nullable,nonatomic,copy,readonly)     NSString *clientCustomInfo;


/**
 *  群消息是否需要通知
 *  @discussion 这个设置影响群消息的 APNS 推送
 */
@property (nonatomic,assign,readonly)   BOOL notifyForNewMsg;


/**
 *  群组是否正在全员禁言
 *  @discussion 只有高级群有效
 */
- (BOOL)inAllMuteMode;


@end

NS_ASSUME_NONNULL_END


