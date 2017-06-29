//
//  NIMRTSOption.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 *  实时会话的附带选项, 用于发起和响应
 */
@interface NIMRTSOption : NSObject

/**
 *  扩展消息, 仅在发起会话时有效, 用于开发者在主被叫之间沟通额外信息
 */
@property (nullable,nonatomic, copy) NSString *extendMessage;

/**
 *  结束网络通话时自动停止AudioSession, 默认为 YES
 */
@property (nonatomic, assign) BOOL autoDeactivateAudioSession;

/**
 *  语音降噪, 默认为 YES
 */
@property (nonatomic, assign) BOOL audioDenoise;

/**
 *  人声检测, 默认为 YES
 */
@property (nonatomic, assign) BOOL voiceDetect;

/**
 期望发送高清语音, 只有在通话的所有的参与者都设置为高清语音时才生效。开启该选项后蓝牙耳机将不能使用
 */
@property (nonatomic, assign) BOOL preferHDAudio;

/**
 服务器录制语音
 */
@property (nonatomic, assign) BOOL serverRecordAudio;

/**
 服务器录制实时会话数据
 */
@property (nonatomic, assign) BOOL serverRecordData;

/**
 *  始终持续呼叫, 用于设置被叫离线时是否仍然需要持续呼叫, 默认为 YES
 */
@property (nonatomic, assign)   BOOL          alwaysKeepCalling;

/**
 *  实时会话请求是否附带推送
 *  @discussion 默认为YES。将这个字段设为NO，实时会话请求将不再有苹果推送通知。
 */
@property (nonatomic,assign)    BOOL          apnsInuse;

/**
 *  推送是否需要角标计数
 *  @discussion 默认为YES。将这个字段设为NO，实时会话请求将不再对角标计数。
 */
@property (nonatomic,assign)    BOOL          apnsBadge;

/**
 *  推送是否需要带前缀(一般为昵称)
 *  @discussion 默认为YES。将这个字段设为NO，推送消息将不带有前缀(xx:)。
 */
@property (nonatomic,assign)    BOOL          apnsWithPrefix;

/**
 *  apns推送文案
 *  @discussion 默认为nil，用户可以设置当前通知的推送文案
 */
@property (nullable,nonatomic,copy)      NSString      *apnsContent;

/**
 *  apns推送声音文件
 *  @discussion 默认为nil，用户可以设置当前通知的推送声音。该设置会覆盖apnsPayload中的sound设置
 */
@property (nullable,nonatomic,copy)      NSString      *apnsSound;

/**
 *  apns推送Payload
 *  @discussion 可以通过这个字段定义自定义通知的推送Payload,支持字段参考苹果技术文档,最多支持2K
 */
@property (nullable,nonatomic,copy)      NSDictionary   *apnsPayload;


@end

NS_ASSUME_NONNULL_END
