//
//  NIMAVChatNetDetectManagerProtocol.h
//  NIMAVChat
//
//  Created by Netease.
//  Copyright (c) 2016 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMAVChatDefs.h"
NS_ASSUME_NONNULL_BEGIN

@class NIMAVChatNetDetectResult;

/**
 网络探测结果 Block

 @param result 网络探测的结果
 */
typedef void(^NIMAVChatNetDetectCompleteBlock)(NIMAVChatNetDetectResult *result);

/**
 *  音视频实时会话网络探测管理类
 */
@protocol NIMAVChatNetDetectManager <NSObject>

/**
 *  开始网络探测任务
 *
 *  @param completion 任务完成 block
 *
 *  @return 开始的网络探测任务的 id，可以用该 id 停止该任务，如果返回 0 表示开始失败
 */
- (UInt64)startDetectTask:(nullable NIMAVChatNetDetectCompleteBlock)completion;

/**
 *  停止网络探测任务
 *
 *  @param taskId 需要停止的任务的 id
 */
- (void)stopDetectTask:(UInt64)taskId;

/**
 *  获得 SDK 网络探测 log 文件路径
 *
 *  @return 网络探测 log 文件路径
 */
- (NSString *)logFilepath;

@end

NS_ASSUME_NONNULL_END
