//
//  NIMSubscribeRequest.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2017 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  事件订阅请求
 */
@interface NIMSubscribeRequest : NSObject

/**
 *  事件类型，1～99999 为云信保留类型，自定义的订阅事件请选择此范围以外的类型, 预定义事件定义见 NIMSubscribeSystemEventType
 */
@property (nonatomic, assign) NSInteger type;


/**
 *  订阅的有效期，范围为 60 秒到 30 天， 数值单位为秒， 超出时间则自动取消订阅，
 */
@property (nonatomic, assign) NSTimeInterval expiry;


/**
 *  订阅后是否立刻同步事件状态值
 *  @discussion 默认为NO,，如果填 YES ，则会收到事件回调 - (void)onRecvSubscribeEvent:
 */
@property (nonatomic, assign) BOOL syncEnabled;


/**
 *  发布事件者的 Id 数组，最多 100 个
 *  @discussion 由于同一个事件可能由不同的用户发出，只能订阅数组内用户发布的事件。
 */
@property (nonatomic, copy) NSArray *publishers;



@end

NS_ASSUME_NONNULL_END
