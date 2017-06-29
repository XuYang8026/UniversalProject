//
//  NIMSDKConfig.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NIMNotificationObject;

/**
 *  SDK 配置委托
 */
@protocol NIMSDKConfigDelegate <NSObject>

@optional

/**
 *  是否需要忽略某个通知
 *
 *  @param notification 通知对象
 *
 *  @return 是否通知
 */
- (BOOL)shouldIgnoreNotification:(NIMNotificationObject *)notification;

@end

/**
 *  NIM SDK 配置项目
 */
@interface NIMSDKConfig : NSObject

/**
 *  返回配置项实例
 *
 *  @return 配置项
 */
+ (instancetype)sharedConfig;


/**
 *  是否在收到消息后自动下载附件 (群和个人)
 *  @discussion 默认为YES,SDK会在第一次收到消息是直接下载消息附件,上层开发可以根据自己的需要进行设置
 */
@property (nonatomic,assign)    BOOL    fetchAttachmentAutomaticallyAfterReceiving;


/**
 *  是否在收到聊天室消息后自动下载附件
 *  @discussion 默认为NO
 */
@property (nonatomic,assign)    BOOL    fetchAttachmentAutomaticallyAfterReceivingInChatroom;


/**
 *  是否使用 NSFileProtectionNone 作为云信文件的 NSProtectionKey
 *  @discussion 默认为 NO，只有在上层 APP 开启了 Data Protection 时才起效
 */
@property (nonatomic,assign)    BOOL    fileProtectionNone;

/**
 *  是否需要将被撤回的消息计入未读计算考虑
 *  @discussion 默认为 NO。设置成 YES 的情况下，如果被撤回的消息本地还未读，那么当消息发生撤回时，对应会话的未读计数将减 1 以保持最近会话未读数的一致性
 *  默认未读 NO 的原因是客户端常常需要直接再写入一条 tip 消息用于提醒显示，使用 NO 作为默认值直接写入一条已读 tip 消息，避免未读计数发生两次变化，最终导致界面重复刷新
 *  如果客户场景不需要写入 tip 消息，可以设置为 YES，以保持未读计数的一致性。
 */
@property (nonatomic,assign)    BOOL    shouldConsiderRevokedMessageUnreadCount;;

/**
 *  是否需要多端同步未读数
 *  @discusssion 默认为 NO。设置成 YES 的情况下，同个账号多端（PC 和 移动端等）将同步未读计数。
 */
@property (nonatomic,assign)    BOOL    shouldSyncUnreadCount;


/**
 *  针对用户信息开启 https 支持
 *  @discusssion 默认为 YES。在默认情况下，我们认为用户头像，群头像，聊天室类用户头像等信息都是默认托管在云信上，所以 SDK 会针对他们自动开启 https 支持。
 *                          但如果你需要将这些信息都托管在自己的服务器上，需要设置这个接口为 NO，避免 SDK 自动将你的 http url 自动转换为 https url。
 */
@property (nonatomic,assign)    BOOL    enabledHttpsForInfo;


/**
 *  针对消息内容开启 https 支持
 *  @discusssion 默认为 YES。在默认情况下，我们认为消息，包括图片，视频，音频信息都是默认托管在云信上，所以 SDK 会针对他们自动开启 https 支持。
 *                         但如果你需要将这些信息都托管在自己的服务器上，需要设置这个接口为 NO，避免 SDK 自动将你的 http url 自动转换为 https url。 (强烈不建议)
 *                         需要注意的是即时设置了这个属性，通过 iOS SDK 发出去的消息 URL 仍是 https 的，设置这个值只影响接收到的消息 URL 格式转换
 */
@property (nonatomic,assign)    BOOL    enabledHttpsForMessage;


/**
 *  自动登录重试次数
 *  @discusssion 默认为 0。即默认情况下，自动登录将无限重试。设置成大于 0 的值后，在没有登录成功前，自动登录将重试最多 maxAutoLoginRetryTimes 次，如果失败，则抛出错误 (NIMLocalErrorCodeAutoLoginRetryLimit)。
 */
@property (nonatomic,assign)    NSInteger   maxAutoLoginRetryTimes;

/**
 *  配置项委托
 */
@property (nullable,nonatomic,weak)    id<NIMSDKConfigDelegate>    delegate;

/**
 *  设置 SDK 根目录
 *
 *  @param sdkDir SDK 根目录
 *  @discussion 设置该值后 SDK 产生的数据(包括聊天记录，但不包括临时文件)都将放置在这个目录下，如果不设置，所有数据将放置于 $Document/NIMSDK目录下
 *              该配置项必须在 NIMSDK 任一一个 sharedSDK 方法调用之前调用，否则配置无法生效
 */
- (void)setupSDKDir:(NSString *)sdkDir;
@end


NS_ASSUME_NONNULL_END
