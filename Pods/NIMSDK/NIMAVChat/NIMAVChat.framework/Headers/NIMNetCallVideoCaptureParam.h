//
//  NIMNetCallVideoCaptureParam.h
//  NIMAVChat
//
//  Created by fenric on 17/3/24.
//  Copyright © 2017年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CMSampleBuffer.h>
#import "NIMAVChatDefs.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  视频数据处理Block
 *
 *  @param sampleBuffer 摄像头采集到的视频原始数据
 */
typedef void(^NIMNetCallVideoSampleBufferHandler)(CMSampleBufferRef sampleBuffer);

/**
 *  音视频视频采集参数
 */
@interface NIMNetCallVideoCaptureParam : NSObject

/**
 *  期望的发送视频质量
 *  @discussion SDK可能会根据具体机型运算性能和协商结果调整为更合适的清晰度，导致该设置无效（该情况通常发生在通话一方有低性能机器时）
 */
@property (nonatomic,assign)    NIMNetCallVideoQuality   preferredVideoQuality;

/**
 *  视频采集画面格式, 默认是 420f
 */
@property (nonatomic, assign) NIMNetCallVideoCaptureFormat format;

/**
 *  使用后置摄像头开始视频, 默认是 YES
 */
@property (nonatomic, assign) BOOL startWithBackCamera;

/**
 *  初始打开摄像头, 默认是 YES
 */
@property (nonatomic, assign) BOOL startWithCameraOn;

/**
 视频采集方向. 该设置会改变采集到的视频画面的角度, 主要用于支持互动直播时的横屏直播: 主播以各种角度手持设备直播, 并设置为该角度的 '视频采集方向', 拉流播放器就可以以正常的角度观看直播.
 
 @discussion 在视频通话场景中, 如果播放端关闭 '自动旋转远端画面', 画面将以采集到的角度展现; 如果播放端开启 '自动旋转远端画面', 无论 '视频采集方向' 如何设置, 播放的画面都是正常的角度
 */
@property (nonatomic, assign) NIMVideoOrientation videoCaptureOrientation;

/**
 *  视频发送帧率
 */
@property (nonatomic, assign) NIMNetCallVideoFrameRate videoFrameRate;


/**
 *  本地采集的视频数据回调，供上层实现美颜等功能
 */
@property (nullable, nonatomic, copy) NIMNetCallVideoSampleBufferHandler  videoHandler;



@end

NS_ASSUME_NONNULL_END

