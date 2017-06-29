//
//  NIMPushNotificationSetting.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  推送消息显示类型
 */
typedef NS_ENUM(NSInteger, NIMPushNotificationDisplayType){
    /**
     *  显示详情
     */
    NIMPushNotificationDisplayTypeDetail = 1,
    /**
     *  不显示详情
     */
    NIMPushNotificationDisplayTypeNoDetail = 2,
};


/**
 *  消息推送免打扰参数设置
 */
@interface NIMPushNotificationSetting : NSObject
/**
 *  推送消息显示类型
 */
@property (nonatomic,assign)    NIMPushNotificationDisplayType     type;

/**
 *  推送消息是否开启免打扰 YES表示开启免打扰
 */
@property (nonatomic,assign)    BOOL    noDisturbing;

/**
 *  免打扰开始时间:小时
 */
@property (nonatomic,assign) NSUInteger noDisturbingStartH;

/**
 *  免打扰开始时间:分
 */
@property (nonatomic,assign) NSUInteger noDisturbingStartM;

/**
 *  免打扰结束时间:小时
 */
@property (nonatomic,assign) NSUInteger noDisturbingEndH;

/**
 *  免打扰结束时间:分
 */
@property (nonatomic,assign) NSUInteger noDisturbingEndM;

@end


/**
 *  自定义消息推送配置项
 */
@interface NIMPushNotificationMultiportConfig : NSObject

/**
 *  桌面端在线时是否需要发送推送给手机端
 *  @discussion 默认为 YES，即需要推送,桌面端包括 PC，web 等...
 */
@property (nonatomic,assign)    BOOL    shouldPushNotificationWhenPCOnline;

@end


NS_ASSUME_NONNULL_END