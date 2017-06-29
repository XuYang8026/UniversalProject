//
//  NIMMessageApnsMemberOption.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 *  推送人员选项
 */
@interface NIMMessageApnsMemberOption : NSObject

/**
 *  需要特殊推送的用户列表
 *  @discussion 设置为 nil 时表示推送给当前会话内的所有用户
 */
@property (nullable,nonatomic,copy)     NSArray<NSString *> *userIds;

/**
 *  是否强制推送
 *  @discussion 默认为 YES. 设置为 YES 表示即使推送列表中的用户屏蔽了当前会话(如静音)，仍能够推送当前这条推送内容给相应用户
 */
@property (nonatomic,assign)            BOOL    forcePush;

/**
 *  推送文案
 *  @discussion 推送给制定用户的特定推送文案，如果设置为 nil 则使用消息本身的推送文案
 *
 */
@property (nullable,nonatomic,copy)     NSString    *apnsContent;
@end

NS_ASSUME_NONNULL_END