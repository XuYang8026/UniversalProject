//
//  NIMEventSubscribeManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2017 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NIMSubscribeEvent;
@class NIMSubscribeRequest;

NS_ASSUME_NONNULL_BEGIN

/**
 *  事件普通回调
 *
 *  @param error 错误信息,如果成功,error 为 nil
 *  @param event 事件，填充了发布的时间
 */
typedef void(^NIMEventSubscribeBlock)(NSError * __nullable error, NIMSubscribeEvent * __nullable event);

/**
 *  订阅/取消订阅事件回调
 *
 *  @param error 错误信息,如果成功,error 为 nil,
 *  @param failedPublishers 失败的发布者 Id, 为 nil 则全部订阅/取消订阅成功
 */
typedef void(^NIMEventSubscribeResponseBlock)(NSError * __nullable error, NSArray * __nullable failedPublishers);


/**
 *  事件查询回调
 *
 *  @param error   错误信息,如果成功,error 为 nil,
 *  @param results NIMSubscribeResult 数组 本账号订阅的事件详情，包括订阅了谁，订阅的时间以及有效期等等
 */
typedef void(^NIMEventSubscribeQueryBlock)(NSError * __nullable error, NSArray * __nullable results);


/**
 *  订阅回调
 */
@protocol NIMEventSubscribeManagerDelegate <NSObject>

@optional

/**
 *  收到所订阅的事件的回调
 *  @param events 广播的事件 NIMSubscribeEvent 列表
 */
- (void)onRecvSubscribeEvents:(NSArray *)events;


@end

/**
 *  事件订阅协议
 */
@protocol NIMEventSubscribeManager <NSObject>

/**
 *  发布事件
 *
 *  @param event 需要广播的事件，事件可被其他人订阅
 *  @param completion 完成回调
 */
- (void)publishEvent:(NIMSubscribeEvent *)event
          completion:(nullable NIMEventSubscribeBlock)completion;


/**
 *  订阅事件
 *
 *  @param request 订阅请求
 *  @param completion 完成回调
 *  @discussion 请求中必需填写 type，expiry，publishers 字段
 */
- (void)subscribeEvent:(NIMSubscribeRequest *)request
            completion:(nullable NIMEventSubscribeResponseBlock)completion;


/**
 *  取消订阅事件
 *
 *  @param request 取消订阅请求
 *  @param completion 完成回调
 *  @discussion 请求中必须填写 type 字段 ， 如果不填写 publishers 字段，则取消指定事件的全部订阅关系
 */
- (void)unSubscribeEvent:(NIMSubscribeRequest *)request
              completion:(nullable NIMEventSubscribeResponseBlock)completion;


/**
 *  查询订阅事件
 *
 *  @param request 查询请求
 *  @param completion 完成回调
 *  @discussion 请求中必须填写 type 字段 和 publishers 字段
 */
- (void)querySubscribeEvent:(NIMSubscribeRequest *)request
                 completion:(nullable NIMEventSubscribeQueryBlock)completion;


/**
 *  添加通知对象
 *
 *  @param delegate 通知对象
 */
- (void)addDelegate:(id<NIMEventSubscribeManagerDelegate>)delegate;

/**
 *  移除通知对象
 *
 *  @param delegate 通知对象
 */
- (void)removeDelegate:(id<NIMEventSubscribeManagerDelegate>)delegate;


@end

NS_ASSUME_NONNULL_END
