//
//  NIMRTSRecordingInfo.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMRTSManagerProtocol.h"


NS_ASSUME_NONNULL_BEGIN
/**
 *  实时会话录制服务信息
 */
@interface NIMRTSRecordingInfo : NSObject

/**
 *  录制文件的服务类型
 */
@property (nonatomic, readonly, assign) NIMRTSService service;

/**
 *  录制存储文件名
 */
@property (nonatomic, readonly, copy) NSString *recordFileName;

@end


NS_ASSUME_NONNULL_END