//
//  NIMRTSConferenceManagerProtocol.h
//  NIMAVChat
//
//  Created by Netease.
//  Copyright (c) 2016 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMAVChatDefs.h"
NS_ASSUME_NONNULL_BEGIN

@class NIMRTSConference;
@class NIMRTSConferenceData;

/**
 *  多方实时会话相关回调
 */
@protocol NIMRTSConferenceManagerDelegate <NSObject>

@optional


/**
 *  预订多方实时会话结果回调
 *
 *  @param conference 预订的会话
 *  @param result     结果. nil 表示预订成功
 */
- (void)onReserveConference:(NIMRTSConference *)conference
                     result:(nullable NSError *)result;

/**
 *  加入多方实时会话结果回调
 *
 *  @param conference 加入的会话
 *  @param result     结果. nil 表示加入成功
 */
- (void)onJoinConference:(NIMRTSConference *)conference
                  result:(nullable NSError *)result;


/**
 *  离开了多人实时会话（发生了错误）
 *
 *  @param conference 离开的会话
 *  @param error      错误信息
 */
- (void)onLeftConference:(NIMRTSConference *)conference
                   error:(NSError *)error;


/**
 *  用户加入了多方实时会话
 *
 *  @param uid        用户 id
 *  @param conference 用户加入的会话
 */
- (void)onUserJoined:(NSString *)uid
          conference:(NIMRTSConference *)conference;

/**
 *  用户离开了多方实时会话
 *
 *  @param uid        用户 id
 *  @param conference 用户离开的会话
 *  @param reason     用户离开的原因
 */
- (void)onUserLeft:(NSString *)uid
        conference:(NIMRTSConference *)conference
            reason:(NIMRTSConferenceUserLeaveReason)reason;

@end

/**
 *  实时会话协议
 */
@protocol NIMRTSConferenceManager <NSObject>


/**
 *  预订多方实时会话
 *
 *  @param conference 需要预订的会话
 * 
 *  @return 接口调用的结果. 该结果只是表示当前这个函数调用是否成功,需要后续的回调才能判断预订会话是否成功
 */
- (nullable NSError *)reserveConference:(NIMRTSConference *)conference;

/**
 *  加入多方实时会话
 *
 *  @param conference 需要加入的会话
 *
 *  @return 接口调用的结果. 该结果只是表示当前这个函数调用是否成功,需要后续的回调才能判断加入会话是否成功
 */
- (nullable NSError *)joinConference:(NIMRTSConference *)conference;

/**
 *  离开多方实时会话
 *
 *  @param conference 需要离开的会话
 *
*  @return 接口调用的结果
 *
 */
- (nullable NSError *)leaveConference:(NIMRTSConference *)conference;


/**
 *  发送多方实时会话数据
 *
 *  @param data 需要发送的实时会话数据, 数据长度不允许超过50KB, 推荐不超过4KB; 发送数据的周期建议控制在50ms以上
 *
 *  @return 是否允许发送
 *
 *  @discussion 被叫在响应请求之前不要调用挂断接口
 */
- (BOOL)sendRTSData:(NIMRTSConferenceData *)data;

/**
 *  添加多方实时会话委托
 *
 *  @param delegate 多方实时会话委托
 */
- (void)addDelegate:(id<NIMRTSConferenceManagerDelegate>)delegate;

/**
 *  移除多方实时会话委托
 *
 *  @param delegate 多方实时会话委托
 */
- (void)removeDelegate:(id<NIMRTSConferenceManagerDelegate>)delegate;
@end

NS_ASSUME_NONNULL_END
