//
//  NIMRTSConferenceData.h
//  NIMAVChat
//
//  Created by Netease on 16/10/27.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NIMRTSConference;

NS_ASSUME_NONNULL_BEGIN

/**
 *  多方实时会话数据
 */
@interface NIMRTSConferenceData : NSObject

/**
 *  数据属于的会话会话信息
 */
@property (nonatomic, copy) NIMRTSConference   *conference;

/**
 *  数据属于的会话会话信息
 *  @discussion 发送的数据长度不允许超过50KB, 推荐不超过4KB，发送周期建议控制在50ms以上
 */
@property (nonatomic, strong) NSData *data;

/**
 *  数据的发送者或接收者
 *  @discussion 在发送数据时填写接收者，填 nil 表示广播数据；接收数据时该字段表示数据的发送者
 */
@property (nullable, nonatomic, copy) NSString *uid;

@end

NS_ASSUME_NONNULL_END
