//
//  NIMNotificationObject.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import "NIMMessageObjectProtocol.h"
#import "NIMTeamNotificationContent.h"
#import "NIMNetCallNotificationContent.h"
#import "NIMChatroomNotificationContent.h"
#import "NIMUnsupportedNotificationContent.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  通知对象
 */
@interface NIMNotificationObject : NSObject<NIMMessageObject>
/**
 *  通知内容
 */
@property (nonatomic,strong,readonly)    NIMNotificationContent  *content;

/**
 *  通知类型
 */
@property (nonatomic,assign,readonly) NIMNotificationType notificationType;

@end

NS_ASSUME_NONNULL_END