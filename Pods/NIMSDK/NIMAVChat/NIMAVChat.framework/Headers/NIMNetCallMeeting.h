//
//  NIMNetCallMeeting.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMAVChatDefs.h"

@class NIMNetCallOption;

NS_ASSUME_NONNULL_BEGIN

/**
 *  多人音视频会议
 */
@interface NIMNetCallMeeting : NSObject

/**
 *  会议名称
 *
 *  @discussion 相同的会议名称, 只在会议使用完以后才可以重复使用, 开发者需要保证不会出现重复预订某会议名称而不使用的情况
 */
@property (nonatomic,copy)    NSString          *name;


/**
 *  会议对应的当前通话 call id
 */
@property (nonatomic, readonly) UInt64          callID;

/**
 *  扩展信息
 *  @discussion 用于在会议的创建和加入之间传递额外信息, 仅在创建会议时设置有效
 */
@property (nullable,nonatomic,copy)      NSString        *ext;

/**
 *  加入会议的音视频类型
 */
@property (nonatomic,assign)    NIMNetCallMediaType   type;


/**
 *  以发言者的角色加入, 非发言者 (观众)不发送音视频数据
 */
@property (nonatomic, assign)   BOOL             actor;

/**
 *  网络通话可选配置
 */
@property (nullable, nonatomic, strong) NIMNetCallOption *option;

@end

NS_ASSUME_NONNULL_END
