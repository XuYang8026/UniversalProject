//
//  NIMAVChatNetDetectResult.h
//  NIMAVChat
//
//  Created by Netease on 16/12/16.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 网络探测任务结果
 */
@interface NIMAVChatNetDetectResult : NSObject

/**
 任务 id
 */
@property (nonatomic,assign,readonly)  UInt64 taskId;

/**
 任务执行结果，如果没有错误则为 nil
 */
@property (nonatomic,strong,readonly)  NSError *error;

/**
 丢包率百分比
 */
@property (nonatomic,assign,readonly)  NSInteger lossRate;

/**
 rtt 最大值
 */
@property (nonatomic,assign,readonly)  NSInteger rttMaximal;

/**
 rtt 最小值
 */
@property (nonatomic,assign,readonly)  NSInteger rttMinimal;

/**
 rtt 平均值
 */
@property (nonatomic,assign,readonly)  NSInteger rttAverage;

/**
 rtt 偏差
 */
@property (nonatomic,assign,readonly)  NSInteger rttMeanDeviation;

/**
 扩展信息
 */
@property (nonatomic,copy,readonly)    NSString *expandInfo;

@end
