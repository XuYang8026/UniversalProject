//
//  NIMRTSConference.h
//  NIMAVChat
//
//  Created by Netease on 16/10/27.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NIMRTSConferenceData;

NS_ASSUME_NONNULL_BEGIN

/**
 *  多方实时会话接收数据处理 Handler
 *
 *  @param data 预订或者加入的多人会议
 */
typedef void(^NIMRTSConferencReceiveDataHandler)(NIMRTSConferenceData *data);

/**
 *  多方实时会话
 */
@interface NIMRTSConference : NSObject

/**
 *  实时会话名称
 *
 *  @discussion 相同的实时会话名称, 只在会话使用完以后才可以重复使用, 开发者需要保证不会出现重复预订某会话名称而不使用的情况
 */
@property (nonatomic,copy) NSString   *name;

/**
 *  扩展信息
 *  @discussion 用于在会话的创建和加入之间传递额外信息, 仅在创建会话时设置有效
 */
@property (nullable,nonatomic,copy) NSString   *ext;

/**
 *  接收数据处理
 */
@property (nullable,nonatomic,copy) NIMRTSConferencReceiveDataHandler dataHandler;

/**
 *  服务器录制开关
 */
@property (nonatomic, assign) BOOL serverRecording;

/**
 *  多方实时会话对应的当前 channel id, 在成功加入会话以后可以获取到
 */
@property (nonatomic,readonly) UInt64   channelID;

/**
 *  服务器录制文件名
 */
@property (nullable,nonatomic,copy, readonly) NSString   *serverRecordName;


@end

NS_ASSUME_NONNULL_END
