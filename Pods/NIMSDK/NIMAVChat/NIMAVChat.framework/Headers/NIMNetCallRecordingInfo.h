//
//  NIMNetCallRecordingInfo.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMRTSManagerProtocol.h"


NS_ASSUME_NONNULL_BEGIN
/**
 *  网络通话服务器录制服务信息
 */
@interface NIMNetCallRecordingInfo : NSObject

/**
 *  录制文件对应的 call id
 */
@property (nonatomic, readonly, assign) UInt64 callID;

/**
 *  录制存储音频文件名
 */
@property (nonatomic, readonly, copy) NSString *audioRecordFileName;

/**
 *  录制存储视频文件名
 */
@property (nonatomic, readonly, copy) NSString *videoRecordFileName;

@end


NS_ASSUME_NONNULL_END