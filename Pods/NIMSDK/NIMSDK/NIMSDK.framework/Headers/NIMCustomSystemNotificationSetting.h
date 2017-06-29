//
//  NIMCustomNotificationSetting.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2015年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 *  自定义系统通知配置
 */
@interface NIMCustomSystemNotificationSetting : NSObject

/**
 *  系统通知是否需要被计入苹果推送通知的未读计数
 *  @discussion 默认为YES。默认情况下，用户收到的自定义系统通知会在应用图标上累计未读。
 */
@property (nonatomic,assign)    BOOL        shouldBeCounted;
/**
 *  消息是否需要苹果推送
 *  @discussion 默认为YES。将这个字段设为NO，消息将不再有苹果推送通知。
 */
@property (nonatomic,assign)    BOOL        apnsEnabled;
/**
 *  苹果推送是否需要带前缀(一般为昵称)
 *  @discussion 默认为NO。将这个字段设为YES，推送消息将带有前缀(xx:)。
 */
@property (nonatomic,assign)    BOOL        apnsWithPrefix;

@end


NS_ASSUME_NONNULL_END