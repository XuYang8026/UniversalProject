//
//  NIMSDKHeaders.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  NIMSDK
 */
@interface NIMSDK : NSObject
/**
 *  获取SDK实例
 *
 *  @return NIMSDK实例
 */
+ (instancetype)sharedSDK;

/**
 *  获取SDK版本号
 *
 *  @return SDK版本号
 */
- (NSString *)sdkVersion;

/**
 *  初始化SDK
 *
 *  @param appKey  申请的appKey
 *  @param cerName 推送证书名
 */
- (void)registerWithAppID:(NSString *)appKey
                  cerName:(nullable NSString *)cerName;

/**
 *  获取AppKey
 *
 *  @return 返回当前注册的AppKey
 */
- (nullable NSString *)appKey;

/**
 *  是否正在使用Demo AppKey
 *
 *  @return 返回是否正在使用Demo AppKey
 */
- (BOOL)isUsingDemoAppKey;

/**
 *  更新APNS Token
 *
 *  @param token APNS Token
 */
- (void)updateApnsToken:(NSData *)token;


/**
 *  获得SDK Log路径
 *
 *  @return SDK当天log路径
 *  @discussion 这个接口会返回当前最新的一个log文件路径,SDK会每天生成一个log文件方便开发者定位和反馈问题
 */
- (NSString *)currentLogFilepath;

/**
 *  开启控制台Log
 */
- (void)enableConsoleLog;


/**
 *  登录管理类 负责登录,注销和相关操作的通知收发
 */
@property (nonatomic,strong,readonly)   id<NIMLoginManager>   loginManager;

/**
 *  聊天管理类,负责消息的收发
 */
@property (nonatomic,strong,readonly)   id<NIMChatManager>     chatManager;

/**
 *  会话管理类,负责消息,最近会话的读写和管理
 */
@property (nonatomic,strong,readonly)   id<NIMConversationManager>  conversationManager;

/**
 *  媒体管理类,负责多媒体相关的接口 (录音等)
 */
@property (nonatomic,strong,readonly)   id<NIMMediaManager>    mediaManager;

/**
 *  群组管理类,负责群组的操作:创建,拉人,踢人,同步等
 */
@property (nonatomic,strong,readonly)   id<NIMTeamManager>    teamManager;

/**
 *  好友管理类
 */
@property (nonatomic,strong,readonly)   id<NIMUserManager>      userManager;

/**
 *  系统通知管理类
 */
@property (nonatomic,strong,readonly)   id<NIMSystemNotificationManager>    systemNotificationManager;

/**
 *  APNS推送管理类
 */
@property (nonatomic,strong,readonly)   id<NIMApnsManager> apnsManager;

/**
 *  资源管理器,负责文件上传和下载
 */
@property (nonatomic,strong,readonly)   id<NIMResourceManager> resourceManager;

/**
 *  聊天室管理类
 */
@property (nonatomic,strong,readonly)   id<NIMChatroomManager> chatroomManager;

/**
 *  文档转码管理类
 */
@property (nonatomic,strong,readonly)   id<NIMDocTranscodingManager> docTranscodingManager;


/**
 *  事件订阅管理类
 */
@property (nonatomic,strong,readonly)   id<NIMEventSubscribeManager> subscribeManager;

@end

NS_ASSUME_NONNULL_END
