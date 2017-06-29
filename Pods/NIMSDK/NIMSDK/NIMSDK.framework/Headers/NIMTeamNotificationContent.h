//
//  NIMTeamNotificationContent.h
//  NIMLib
//
//  Created by Netease
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMNotificationContent.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  群操作类型
 */
typedef NS_ENUM(NSInteger, NIMTeamOperationType){
    /**
     *  邀请成员
     */
    NIMTeamOperationTypeInvite          = 0,
    /**
     *  移除成员
     */
    NIMTeamOperationTypeKick            = 1,
    /**
     *  离开群
     */
    NIMTeamOperationTypeLeave           = 2,
    /**
     *  更新群信息
     */
    NIMTeamOperationTypeUpdate          = 3,
    /**
     *  解散群
     */
    NIMTeamOperationTypeDismiss         = 4,
    /**
     *  高级群申请加入成功
     */
    NIMTeamOperationTypeApplyPass       = 5,
    /**
     *  高级群群主转移群主身份
     */
    NIMTeamOperationTypeTransferOwner   = 6,
    /**
     *  添加管理员
     */
    NIMTeamOperationTypeAddManager      = 7,
    /**
     *  移除管理员
     */
    NIMTeamOperationTypeRemoveManager   = 8,
    /**
     *  高级群接受邀请进群
     */
    NIMTeamOperationTypeAcceptInvitation= 9,
    
    /**
     *  群内禁言/解禁
     */
    NIMTeamOperationTypeMute            = 10,
    
};


/**
 *  群信息更新字段
 */
typedef NS_ENUM(NSInteger, NIMTeamUpdateTag){
    /**
     *  群名
     */
    NIMTeamUpdateTagName            = 3,
    /**
     *  群简介
     */
    NIMTeamUpdateTagIntro           = 14,
    /**
     *  群公告
     */
    NIMTeamUpdateTagAnouncement     = 15,
    /**
     *  群验证方式
     */
    NIMTeamUpdateTagJoinMode        = 16,
    /**
     *  客户端自定义拓展字段
     */
    NIMTeamUpdateTagClientCustom    = 18,
    /**
     *  服务器自定义拓展字段
     *  @discussion SDK 无法直接修改这个字段, 请调用服务器接口
     */
    NIMTeamUpdateTagServerCustom    = 19,
    /**
     *  头像
     */
    NIMTeamUpdateTagAvatar          = 20,
    /**
     *  被邀请模式
     */
    NIMTeamUpdateTagBeInviteMode    = 21,
    /**
     *  邀请权限
     */
    NIMTeamUpdateTagInviteMode      = 22,
    /**
     *  更新群信息权限
     */
    NIMTeamUpdateTagUpdateInfoMode  = 23,
    /**
     *  更新群客户端自定义拓展字段权限
     */
    NIMTeamUpdateTagUpdateClientCustomMode = 24,
    /**
     *  群全体禁言
     *  @discussion SDK 无法直接修改这个字段, 请调用服务器接口
     */
    NIMTeamUpdateTagMuteMode       = 100
    
};



/**
 *  群通知内容
 */
@interface NIMTeamNotificationContent : NIMNotificationContent
/**
 *  操作发起者ID
 */
@property (nullable,nonatomic,copy,readonly)     NSString    *sourceID;

/**
 *  操作类型
 */
@property (nonatomic,assign,readonly)   NIMTeamOperationType  operationType;

/**
 *  被操作者ID列表
 */
@property (nullable,nonatomic,copy,readonly)   NSArray<NSString *> *targetIDs;

/**
 *  群通知下发的自定义扩展信息
 */
@property (nullable,nonatomic,readonly)   NSString *notifyExt;

/**
 *  额外信息
 *  @discussion 群更新时 attachment 为 NIMUpdateTeamInfoAttachment，
 *              禁言时 attachment 为  NIMMuteTeamMemberAttachment
 */
@property (nullable,nonatomic,strong,readonly)   id attachment;
@end


/**
 *  更新群信息的额外信息
 */
@interface NIMUpdateTeamInfoAttachment : NSObject

/**
 *  群内修改的信息键值对
 */
@property (nullable,nonatomic,copy,readonly)   NSDictionary<NSNumber *,NSString *>    *values;
@end


/**
 *  禁言通知的额外信息
 */
@interface NIMMuteTeamMemberAttachment : NSObject

/**
 *  是否被禁言
 *  @discussion YES 为禁言，NO 为 解除禁言
 */
@property (nonatomic,assign,readonly)   BOOL    flag;
@end



NS_ASSUME_NONNULL_END
