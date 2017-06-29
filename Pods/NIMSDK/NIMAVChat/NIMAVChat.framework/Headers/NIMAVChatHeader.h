//
//  NIMAVChatHeader.h
//  NIMAVChat
//
//  Created by Netease
//  Copyright © 2017年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  NIMAVChat SDK
 */
@interface NIMAVChatSDK : NSObject

/**
 *  获取SDK实例
 *
 *  @return NIMAVChatSDK实例
 */
+ (instancetype)sharedSDK;

/**
 *  网络通话管理类
 */
@property (nonatomic,strong,readonly)   id<NIMNetCallManager> netCallManager;

/**
 *  实时会话管理类（点对点）
 */
@property (nonatomic,strong,readonly)   id<NIMRTSManager> rtsManager;

/**
 *  多方实时会话管理类
 */
@property (nonatomic,strong,readonly)   id<NIMRTSConferenceManager> rtsConferenceManager;

/**
 音视频实时会话网络探测管理类
 */
@property (nonatomic,strong,readonly)   id<NIMAVChatNetDetectManager> avchatNetDetectManager;


@end

NS_ASSUME_NONNULL_END

