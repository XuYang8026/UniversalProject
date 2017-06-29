//
//  NIMChatroomNotificationContent.h
//  NIMLib
//
//  Created by Netease
//  Copyright © 2016年 Netease. All rights reserved.
//

#import "NIMNotificationContent.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  聊天室操作类型
 */
typedef NS_ENUM(NSInteger, NIMChatroomEventType){
    /**
     *  成员进入聊天室
     */
    NIMChatroomEventTypeEnter         = 301,
    /**
     *  成员离开聊天室
     */
    NIMChatroomEventTypeExit          = 302,
    /**
     *  成员被拉黑
     */
    NIMChatroomEventTypeAddBlack      = 303,
    /**
     *  成员被取消拉黑
     */
    NIMChatroomEventTypeRemoveBlack   = 304,
    /**
     *  成员被设置禁言
     */
    NIMChatroomEventTypeAddMute       = 305,
    /**
     *  成员被取消禁言
     */
    NIMChatroomEventTypeRemoveMute    = 306,
    /**
     *  设置为管理员
     */
    NIMChatroomEventTypeAddManager    = 307,
    /**
     *  移除管理员
     */
    NIMChatroomEventTypeRemoveManager = 308,
    /**
     *  设置为固定成员
     */
    NIMChatroomEventTypeAddCommon     = 309,
    /**
     *  取消固定成员
     */
    NIMChatroomEventTypeRemoveCommon  = 310,
    /**
     *  聊天室被关闭
     */
    NIMChatroomEventTypeClosed        = 311,
    /**
     *  聊天室信息更新
     */
    NIMChatroomEventTypeInfoUpdated   = 312,
    /**
     *  聊天室成员被踢
     */
    NIMChatroomEventTypeKicked        = 313,
    /**
     *  聊天室成员被临时禁言
     */
    NIMChatroomEventTypeAddMuteTemporarily   = 314,
    /**
     *  聊天室成员被解除临时禁言
     */
    NIMChatroomEventTypeRemoveMuteTemporarily = 315,
    /**
     *  聊天室成员主动更新了聊天室的角色信息
     */
    NIMChatroomEventTypeMemberUpdateInfo = 316,
    /**
     *  聊天室通用队列变更的通知
     */
    NIMChatroomEventTypeQueueChange = 317,
    /**
     *  聊天室被禁言了，只有管理员可以发言,其他人都处于禁言状态
     */
    NIMChatroomEventTypeRoomMuted = 318,
    /**
     *  聊天室不在禁言状态
     */
    NIMChatroomEventTypeRoomUnMuted = 319,
};

/**
 *  通知事件包含的聊天室成员
 */
@interface NIMChatroomNotificationMember : NSObject
/**
 *  聊天室成员ID
 */
@property (nullable,nonatomic,copy,readonly) NSString *userId;
/**
 *  聊天室成员昵称
 */
@property (nullable,nonatomic,copy,readonly) NSString *nick;

@end


/**
 *  聊天室通知内容
 */
@interface NIMChatroomNotificationContent : NIMNotificationContent

/**
 *  聊天室通知事件类型
 */
@property (nonatomic,assign,readonly) NIMChatroomEventType eventType;

/**
 *  操作者
 */
@property (nullable,nonatomic,copy,readonly) NIMChatroomNotificationMember *source;

/**
 *  被操作者
 */
@property (nullable,nonatomic,copy,readonly) NSArray<NIMChatroomNotificationMember *> *targets;

/**
 *  通知信息
 */
@property (nullable,nonatomic,copy,readonly) NSString *notifyExt;

/**
 *  拓展信息
 *  @discusssion 不同的聊天室通知有不同的扩展信息
 *               NIMChatroomEventTypeAddMuteTemporarily/NIMChatroomEventTypeRemoveMuteTemporarily 类型: 拓展信息为NSNumber，表示临时禁言时长
 *
 *               NIMChatroomEventTypeEnter 类型: 扩展信息为 NSDictionary , KEY 值为 NIMChatroomEventInfoMutedKey ，NIMChatroomEventInfoTempMutedKey, NIMChatroomEventInfoTempMutedDurationKey
 *
 */
@property (nullable,nonatomic,copy,readonly) id ext;

@end

/**
 *  是否是禁言状态
 */
extern NSString *const NIMChatroomEventInfoMutedKey;

/**
 *  是否为临时禁言状态
 */
extern NSString *const NIMChatroomEventInfoTempMutedKey;

/**
 *  临时禁言时长
 */
extern NSString *const NIMChatroomEventInfoTempMutedDurationKey;



NS_ASSUME_NONNULL_END
