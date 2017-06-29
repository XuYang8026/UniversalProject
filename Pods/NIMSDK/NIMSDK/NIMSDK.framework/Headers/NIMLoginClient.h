//
//  NIMLoginClient.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  客户端类型
 */
typedef NS_ENUM(NSInteger, NIMLoginClientType) {
    
    /**
     *  未知类型
     */
    NIMLoginClientTypeUnknown    = 0,
    /**
     *  Android
     */
    NIMLoginClientTypeAOS         = 1,
    /**
     *  iOS
     */
    NIMLoginClientTypeiOS         = 2,
    /**
     *  PC
     */
    NIMLoginClientTypePC          = 4,
    /**
     *  WP
     */
    NIMLoginClientTypeWP          = 8,
    /**
     *  WEB
     */
    NIMLoginClientTypeWeb         = 16,
    /**
     *  REST API
     */
    NIMLoginClientTypeRestful     = 32,
};


/**
 *  登录客户端描述
 */
@interface NIMLoginClient : NSObject
/**
 *  类型
 */
@property (nonatomic,assign,readonly)   NIMLoginClientType      type;
/**
 *  操作系统
 */
@property (nullable,nonatomic,copy,readonly)     NSString                *os;
/**
 *  登录时间
 */
@property (nonatomic,assign,readonly)   NSTimeInterval          timestamp;
@end




/**
 *  自动登录参数
 */
@interface NIMAutoLoginData : NSObject
/**
 *  账号
 */
@property (nonatomic,copy)      NSString    *account;

/**
 *  令牌(在后台绑定的登录token)
 */
@property (nonatomic,copy)      NSString    *token;

/**
 *  强制模式
 *  @discussion 默认为 NO.
 *  在云信中，我们推荐用户在在首次登录时使用手动登录接口，而后的登录采用非强制的自动登录模式，这种方式可以有效的规避非法异地登录带来的损害。(设备失窃或账号失窃)
 *  非强制模式下的自动登录，服务器将检查当前登录设备是否为上一次登录设备，如果不是，服务器将拒绝这次自动登录。(返回 error code 为 417 的错误)
 *  而强制模式下的自动登录，服务器将不检查当前登录设备是否为上一次登录设备，安全性较低。但相对的更加方便，适合 IM 仅作为辅助模块的 App
 */
@property (nonatomic,assign)    BOOL        forcedMode;

@end

NS_ASSUME_NONNULL_END

