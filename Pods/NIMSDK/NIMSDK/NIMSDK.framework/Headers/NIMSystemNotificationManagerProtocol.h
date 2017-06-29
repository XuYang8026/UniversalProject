//
//  NIMSystemNotificationManager.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NIMSession;
@class NIMSystemNotification;
@class NIMCustomSystemNotification;
@class NIMSystemNotificationFilter;

/**
 *  系统通知block
 *
 *  @param error 错误,如果成功则error为nil
 */
typedef void(^NIMSystemNotificationHandler)(NSError * __nullable error);

/**
 *  系统通知回调
 */
@protocol NIMSystemNotificationManagerDelegate <NSObject>
@optional

#pragma mark - 系统通知
/**
 *  收到系统通知回调
 *
 *  @param notification 系统通知
 */
- (void)onReceiveSystemNotification:(NIMSystemNotification *)notification;


/**
 *  系统通知数量变化
 *
 *  @param unreadCount 总系统通知未读数目
 */
- (void)onSystemNotificationCountChanged:(NSInteger)unreadCount;


#pragma mark - 自定义系统通知

/**
 *  收到自定义通知回调
 *  @discussion 这个通知是由开发者服务端/客户端发出,由我们的服务器进行透传的通知,SDK不负责这个信息的存储
 *  @param notification 自定义通知
 */
- (void)onReceiveCustomSystemNotification:(NIMCustomSystemNotification *)notification;


@end

/**
 *  系统通知协议
 */
@protocol NIMSystemNotificationManager <NSObject>
/**
 *  获取本地存储的系统通知
 *
 *  @param notification 当前最早系统消息,没有则传入nil
 *  @param limit        最大获取数
 *
 *  @return 系统消息列表
 */
- (nullable NSArray<NIMSystemNotification *> *)fetchSystemNotifications:(nullable NIMSystemNotification *)notification
                                                                  limit:(NSInteger)limit;


/**
 *  获取本地存储的系统通知
 *
 *  @param notification 当前最早系统消息,没有则传入nil
 *  @param limit        最大获取数
 *  @param filter       过滤器
 *
 *  @return 系统消息列表
 */
- (nullable NSArray<NIMSystemNotification *> *)fetchSystemNotifications:(nullable NIMSystemNotification *)notification
                                                                  limit:(NSInteger)limit
                                                                 filter:(nullable NIMSystemNotificationFilter *)filter;

/**
 *  未读系统消息数
 *
 *  @return 未读系统消息数
 */
- (NSInteger)allUnreadCount;

/**
 *  未读系统消息数
 *
 *  @param filter 过滤器
 *
 *  @return 未读系统消息数
 */
- (NSInteger)allUnreadCount:(nullable NIMSystemNotificationFilter *)filter;

/**
 *  删除单条系统消息
 *
 *  @param notification 系统消息
 */
- (void)deleteNotification:(NIMSystemNotification *)notification;

/**
 *  删除所有系统消息
 */
- (void)deleteAllNotifications;


/**
 *  删除所有命中过滤器的系统消息
 *
 *  @param filter 过滤器
 */
- (void)deleteAllNotifications:(nullable NIMSystemNotificationFilter *)filter;

/**
 *  标记单条系统消息为已读
 *
 *  @param notification 系统消息
 */
- (void)markNotificationsAsRead:(NIMSystemNotification *)notification;

/**
 *  标记所有系统消息为已读
 */
- (void)markAllNotificationsAsRead;

/**
 *  标记所有命中过滤器的系统消息为已读
 *
 *  @param filter 过滤器
 */
- (void)markAllNotificationsAsRead:(nullable NIMSystemNotificationFilter *)filter;


/**
 *  发送自定义系统通知
 *
 *  @param notification 系统通知
 *  @param session      接收方
 *  @param completion   发送结果回调
 *  @discussion 仅支持个人和群。聊天室不支持
 */
- (void)sendCustomNotification:(NIMCustomSystemNotification *)notification
                     toSession:(NIMSession *)session
                    completion:(nullable NIMSystemNotificationHandler)completion;

/**
 *  添加系统消息通知委托
 *
 *  @param delegate 系统通知回调
 */
- (void)addDelegate:(id<NIMSystemNotificationManagerDelegate>)delegate;

/**
 *  移除系统消息通知委托
 *
 *  @param delegate 系统通知回调
 */
- (void)removeDelegate:(id<NIMSystemNotificationManagerDelegate>)delegate;
@end

NS_ASSUME_NONNULL_END
