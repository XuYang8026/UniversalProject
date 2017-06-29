//
//  NIMTeamDefs.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015年 Netease. All rights reserved.
//

#ifndef NIMLib_NIMTeamDefs_h
#define NIMLib_NIMTeamDefs_h


/**
 *  群类型
 */
typedef NS_ENUM(NSInteger, NIMTeamType){
    /**
     *  普通群
     */
    NIMTeamTypeNormal       = 0,
    /**
     *  高级群
     */
    NIMTeamTypeAdvanced     = 1,
};

/**
 *  群验证方式
 */
typedef NS_ENUM(NSInteger, NIMTeamJoinMode) {
    /**
     *  允许所有人加入
     */
    NIMTeamJoinModeNoAuth    = 0,
    /**
     *  需要验证
     */
    NIMTeamJoinModeNeedAuth  = 1,
    /**
     *  不允许任何人加入
     */
    NIMTeamJoinModeRejectAll = 2,
};

/**
 *  邀请模式
 */
typedef NS_ENUM(NSInteger, NIMTeamInviteMode) {
    /**
     *  只有管理员/群主可以邀请他人入群
     */
    NIMTeamInviteModeManager    = 0,
    /**
     *   所有人可以邀请其他人入群
     */
    NIMTeamInviteModeAll        = 1,
};




/**
 *  被邀请模式
 */
typedef NS_ENUM(NSInteger, NIMTeamBeInviteMode) {
    /**
     *  需要被邀请方同意
     */
    NIMTeamBeInviteModeNeedAuth    = 0,
    /**
     *   不需要被邀请方同意
     */
    NIMTeamBeInviteModeNoAuth  = 1,
};


/**
 *  群信息修改权限
 */
typedef NS_ENUM(NSInteger, NIMTeamUpdateInfoMode) {
    /**
     *  只有管理员/群主可以修改
     */
    NIMTeamUpdateInfoModeManager    = 0,
    /**
     *  所有人可以修改
     */
    NIMTeamUpdateInfoModeAll  = 1,
};


/**
 *  修改群客户端自定义字段权限
 */
typedef NS_ENUM(NSInteger, NIMTeamUpdateClientCustomMode) {
    /**
     *  只有管理员/群主可以修改
     */
    NIMTeamUpdateClientCustomModeManager    = 0,
    /**
     *  所有人可以修改
     */
    NIMTeamUpdateClientCustomModeAll  = 1,
};


/**
 *  申请入群状态
 */
typedef NS_ENUM(NSInteger, NIMTeamApplyStatus) {
    /**
     *  无效状态
     */
    NIMTeamApplyStatusInvalid,
    /**
     *  已经在群里
     */
    NIMTeamApplyStatusAlreadyInTeam,
    /**
     *  申请等待通过
     */
    NIMTeamApplyStatusWaitForPass,
    
};


/**
 *  群成员类型
 */
typedef NS_ENUM(NSInteger, NIMTeamMemberType){
    /**
     *  普通群员
     */
    NIMTeamMemberTypeNormal = 0,
    /**
     *  群拥有者
     */
    NIMTeamMemberTypeOwner = 1,
    /**
     *  群管理员
     */
    NIMTeamMemberTypeManager = 2,
    /**
     *  申请加入用户
     */
    NIMTeamMemberTypeApply   = 3,
};


#endif
