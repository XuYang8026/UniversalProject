//
//  NIMTeamMember.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMTeamDefs.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  群成员信息
 */
@interface NIMTeamMember : NSObject
/**
 *  群ID
 */
@property (nullable,nonatomic,copy,readonly)         NSString *teamId;

/**
 *  群成员ID
 */
@property (nullable,nonatomic,copy,readonly)         NSString *userId;

/**
 *  邀请者ID
 *  @dicusssion 此字段仅当该成员为自己时有效。不允许查看其他群成员的邀请者
 */
@property (nullable,nonatomic,copy,readonly)         NSString *invitor;

/**
 *  群成员类型
 */
@property (nonatomic,assign)                NIMTeamMemberType  type;


/**
 *  群昵称
 */
@property (nullable,nonatomic,copy)         NSString *nickname;


/**
 *  被禁言
 */
@property (nonatomic,assign,readonly)       BOOL isMuted;

/**
 *  进群时间
 */
@property (nonatomic,assign,readonly)       NSTimeInterval createTime;


/**
 *  新成员群自定义信息
 */
@property (nullable,nonatomic,copy)        NSString *customInfo;

@end

NS_ASSUME_NONNULL_END