//
//  NIMCreateTeamOption.h
//  NIMLib
//
//  Created by Netease
//  Copyright © 2016 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMTeamDefs.h"

/**
 *  创建群选项
 */
@interface NIMCreateTeamOption : NSObject
/**
 *  群名
 */
@property (nullable,nonatomic,copy)      NSString        *name;
/**
 *  群类型
 *  @discussion 默认为普通群
 */
@property (nonatomic,assign)    NIMTeamType     type;

/**
 *  群头像
 */
@property (nullable,nonatomic,copy)      NSString        *avatarUrl;

/**
 *  群简介
 */
@property (nullable,nonatomic,copy)      NSString        *intro;

/**
 *  群公告
 */
@property (nullable,nonatomic,copy)      NSString        *announcement;

/**
 *  客户端自定义信息
 */
@property (nullable,nonatomic,copy)      NSString        *clientCustomInfo;

/**
 *  邀请他人的附言
 *  @discussion 高级群有效，普通群无需附言
 */
@property (nullable,nonatomic,copy)      NSString        *postscript;

/**
 *  群验证模式
 *  @discussion 只有高级群有效，默认为 NIMTeamJoinModeNoAuth
 */
@property (nonatomic,assign)    NIMTeamJoinMode joinMode;

/**
 *  群邀请权限
 *  @discussion 只有高级群有效，默认为 NIMTeamInviteModeManager
 */
@property (nonatomic,assign)    NIMTeamInviteMode inviteMode;


/**
 *  被邀请模式
 *  @discussion 只有高级群有效，默认为 NIMTeamBeInviteModeNeedAuth
 */
@property (nonatomic,assign)    NIMTeamBeInviteMode beInviteMode;

/**
 *  修改群信息权限
 *  @discussion 只有高级群有效，默认为 NIMTeamUpdateInfoModeManager
 */
@property (nonatomic,assign)    NIMTeamUpdateInfoMode updateInfoMode;

/**
 *  修改群客户端自定义字段权限
 *  @discussion 只有高级群有效，默认为 NIMTeamUpdateClientCustomModeManager
 */
@property (nonatomic,assign)    NIMTeamUpdateClientCustomMode updateClientCustomMode;


@end