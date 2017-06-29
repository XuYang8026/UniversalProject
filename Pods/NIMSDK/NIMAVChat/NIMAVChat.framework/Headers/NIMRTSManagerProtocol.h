//
//  NIMRTSManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMAVChatDefs.h"

NS_ASSUME_NONNULL_BEGIN

@class NIMRTSOption;
@class NIMRTSRecordingInfo;

/**
 *  发起实时会话请求Block
 *
 *  @param error 发起结果, 如果成功 error 为 nil
 *  @param sessionID 发起的实时会话的 ID
 *  @param channelID 实时会话内部使用的通道号, 对应服务器白板时长消息抄送里的 channelId. 仅在 error 为 nil 时有效
 */
typedef void(^NIMRTSRequestHandler)(NSError * __nullable error,NSString * __nullable sessionID,UInt64 channelID);

/**
 *  响应实时会话请求Block
 *
 *  @param error  响应实时会话请求, 如果成功 error 为 nil
 *  @param sessionID 响应的实时会话的 ID
 *  @param channelID 实时会话内部使用的通道号, 对应服务器白板时长消息抄送里的 channelId. 仅在 error 为 nil 时有效
 */
typedef void(^NIMRTSResponseHandler)(NSError * __nullable error,NSString * __nullable sessionID,UInt64 channelID);


/**
 *  实时会话服务
 */
typedef NS_ENUM(NSInteger, NIMRTSService){
    /**
     *  包含可靠数据传输服务
     */
    NIMRTSServiceReliableTransfer    = 1,
    /**
     *  包含实时语音沟通服务
     */
    NIMRTSServiceAudio               = 4,
};

/**
 *  实时会话状态
 */
typedef NS_ENUM(NSInteger, NIMRTSStatus){
    /**
     *  已连接
     */
    NIMRTSStatusConnect,
    /**
     *  已断开
     */
    NIMRTSStatusDisconnect,
};

/**
 *  实时会话相关回调
 */
@protocol NIMRTSManagerDelegate <NSObject>

@optional

/**
 *  被叫收到实时会话请求
 *
 *  @param sessionID 实时会话ID
 *  @param caller 主叫帐号
 *  @param types 服务类型, NIMRTSService的组合
 *  @param extendMessage 附加信息
 */
- (void)onRTSRequest:(NSString *)sessionID
                from:(NSString *)caller
            services:(NSUInteger)types
             message:(nullable NSString *)extendMessage;

/**
 *  主叫收到被叫实时会话响应
 *
 *  @param sessionID 实时会话ID
 *  @param callee 被叫帐号
 *  @param accepted 是否接听
 *
 *  @discussion 被叫拒绝接听时, 主叫不需要再调用termimateRTS:接口
 */
- (void)onRTSResponse:(NSString *)sessionID
                 from:(NSString *)callee
             accepted:(BOOL)accepted;

/**
 *  对方结束实时会话
 *
 *  @param sessionID 实时会话ID
 *  @param user   对方帐号
 */
- (void)onRTSTerminate:(NSString *)sessionID
                    by:(NSString *)user;

/**
 *  这通呼入的实时会话请求已经被该帐号其他端处理
 *
 *  @param sessionID 实时会话ID
 *  @param accepted 是否被接听
 */
- (void)onRTSResponsedByOther:(NSString *)sessionID
                     accepted:(BOOL)accepted;
/**
 *  实时会话状态反馈
 *
 *  @param sessionID 实时会话ID
 *  @param type 实时会话服务类型
 *  @param status 通话状态, 收到NIMRTSStatusDisconnect时无需调用terminate:结束该会话
 *  @param error 出错信息, 正常连接和断开时为nil
 */
- (void)onRTS:(NSString *)sessionID
      service:(NIMRTSService)type
       status:(NIMRTSStatus)status
        error:(nullable NSError *)error;

/**
 *  收到实时会话数据
 *
 *  @param sessionID 实时会话ID
 *  @param data 收到的实时会话数据
 *  @param user 发送实时会话数据的用户
 *  @param channel 收发实时数据的服务通道
 */
- (void)onRTSReceive:(NSString *)sessionID
                data:(NSData *)data
                from:(NSString *)user
              withIn:(NIMRTSService)channel;

/**
 *  收到实时会话控制信息
 *
 *  @param controlInfo 控制信息
 *  @param user 发送指令的用户
 *  @param sessionID   实时会话ID
 */
- (void)onRTSControl:(NSString *)controlInfo
                from:(NSString *)user
          forSession:(NSString *)sessionID;

/**
 *  实时会话录制信息
 *
 *  @param info 录制信息
 *  @param sessionID   实时会话ID
 */
- (void)onRTSRecordingInfo:(NIMRTSRecordingInfo *)info
                forSession:(NSString *)sessionID;


/**
 *  语音网络状态
 *
 *  @param status 网络状态
 *  @param user   网络状态对应的用户；如果是自己，表示自己的发送网络状态
 */
- (void)onRTSAudioNetStatus:(NIMNetCallNetStatus)status
                       user:(NSString *)user;

@end

/**
 *  实时会话协议
 */
@protocol NIMRTSManager <NSObject>

/**
 *  主叫发起实时会话请求
 *
 *  @param callees 被叫帐号列表, 当前版本只支持一个被叫
 *  @param types  实时会话服务类型, NIMRTSService的组合, 如果要同时发起可靠传输通道和音频通话, 使用 NIMRTSServiceReliableTransfer | NIMRTSServiceAudio
 *  @param option 发起会话附带的选项, 可以是nil
 *  @param completion  发起实时会话结果回调
 *
 *  @return 发起的实时会话ID
 */
- (NSString *)requestRTS:(NSArray<NSString *> *)callees
                services:(NSUInteger)types
                  option:(nullable NIMRTSOption *)option
              completion:(nullable NIMRTSRequestHandler)completion;

/**
 *  被叫响应实时会话请求
 *
 *  @param sessionID 实时会话ID
 *  @param accept  是否接听
 *  @param option  接收会话附带的选项, 可以是nil
 *  @param completion  响应呼叫结果回调
 *
 */
- (void)responseRTS:(NSString *)sessionID
             accept:(BOOL)accept
             option:(nullable NIMRTSOption *)option
         completion:(nullable NIMRTSResponseHandler)completion;

/**
 *  挂断实时会话
 *
 *  @param sessionID 需要挂断的实时会话ID
 *
 *  @discussion 被叫在响应请求之前不要调用挂断接口
 */
- (void)terminateRTS:(NSString *)sessionID;

/**
 *  从指定通道发送数据
 *
 *  @param data 需要发送的实时会话数据, 数据长度不允许超过50KB, 推荐不超过4KB; 发送数据的周期建议控制在50ms以上
 *  @param sessionID 实时会话ID
 *  @param userID 发送数据目标用户名, nil表示广播给所有用户
 *  @param service 实时会话服务类型
 *
 *  @return 是否允许发送
 *
 *  @discussion 被叫在响应请求之前不要调用挂断接口
 */
- (BOOL)sendRTSData:(NSData *)data
               from:(NSString *)sessionID
                 to:(NSString *)userID
               with:(NIMRTSService)service;

/**
 *  发送实时会话控制指令
 *
 *  @param controlInfo 控制信息, 自定义实现
 *  @param sessionID   实时会话ID
 */
- (void)sendRTSControl:(NSString *)controlInfo
            forSession:(NSString *)sessionID;

/**
 *  设置当前实时会话静音模式
 *
 *  @param mute 是否开启静音
 *
 */
- (void)setMute:(BOOL)mute;

/**
 *  设置当前实时会话扬声器模式
 *
 *  @param useSpeaker 是否开启扬声器
 *
 */
- (void)setSpeaker:(BOOL)useSpeaker;

/**
 *  添加实时会话委托
 *
 *  @param delegate 实时会话委托
 */
- (void)addDelegate:(id<NIMRTSManagerDelegate>)delegate;

/**
 *  移除实时会话委托
 *
 *  @param delegate 实时会话委托
 */
- (void)removeDelegate:(id<NIMRTSManagerDelegate>)delegate;
@end

NS_ASSUME_NONNULL_END
