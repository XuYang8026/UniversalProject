//
//  NIMNotificationContent.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 *  通知类型
 */
typedef NS_ENUM(NSInteger, NIMNotificationType){
    
    /**
     *  未被支持的通知类型
     *  @discussion 由于系统升级，旧版本的 SDK 可能无法解析新版本数据,所有无法解析的新通知显示为未被支持
     */
    NIMNotificationTypeUnsupport       = 0,
    /**
     *  群通知
     */
    NIMNotificationTypeTeam            = 1,
    /**
     *  网络电话通知
     */
    NIMNotificationTypeNetCall         = 2,
    /**
     *  聊天室通知
     */
    NIMNotificationTypeChatroom        = 3,
};



/**
 *  系统通知内容基类
 */
@interface NIMNotificationContent : NSObject
/**
 *  通知内容类型
 *
 *  @return 通知内容类型
 */
- (NIMNotificationType)notificationType;
@end

NS_ASSUME_NONNULL_END