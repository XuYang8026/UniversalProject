//
//  NIMAntiSpamOption.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * 反垃圾选项
 * @discussion 这个选项用于配置易盾反垃圾，设置 enabled 为 YES (默认为 NO) 后该消息进投递到易盾系统进行反垃圾检测 （需要开启易盾服务）
 */
@interface NIMAntiSpamOption : NSObject

/**
 * 是否开启
 */
@property (nonatomic,assign)            BOOL    enabled;


/**
 * 需要反垃圾的内容
 */
@property (nullable,nonatomic,copy)     NSString    *content;
@end

NS_ASSUME_NONNULL_END
