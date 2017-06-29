//
//  NIMRevokeMessageNotification.h
//  NIMLib
//
//  Created by amao on 2016/10/27.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NIMSession;
@class NIMMessage;


/**
 * 撤回通知
 */
@interface NIMRevokeMessageNotification : NSObject

/**
 * 撤回消息发起者
 */
@property (nonatomic,copy,readonly)    NSString    *fromUserId;

/**
 * 撤回消息所属会话
 */
@property (nonatomic,copy,readonly)    NIMSession   *session;

/**
 * 撤回消息时间点
 * @discussion 这里的时间点指的是被撤回的那条消息到底服务器的时间，而不是撤回指令到达服务器的时间点
 */
@property (nonatomic,assign,readonly)   NSTimeInterval timestamp;


/**
 * 撤回消息内容
 * @discussion 当撤回消息未被当前设备接收时，这个字段为 nil
 */
@property (nullable,nonatomic,strong,readonly)   NIMMessage *message;

@end


NS_ASSUME_NONNULL_END
