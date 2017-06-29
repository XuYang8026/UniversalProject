//
//  NIMMessageSearchOption.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMGlobalDefs.h"

NS_ASSUME_NONNULL_BEGIN

@class NIMMessage;


/**
 *  搜索顺序
 */
typedef NS_ENUM(NSInteger,NIMMessageSearchOrder) {
    /**
     *  从新消息往旧消息查询
     */
    NIMMessageSearchOrderDesc       =   0,
    
    /**
     *  从旧消息往新消息查询
     */
    NIMMessageSearchOrderAsc        =   1,
};


/**
 *  本地搜索选项
 *  @discussion 搜索条件: 时间在(startTime,endTime) 内(不包含)，类型为 messageType （或全类型） ，且匹配 searchContent 或 fromIds 的一定数量 (limit) 消息
 */
@interface NIMMessageSearchOption : NSObject

/**
 *  起始时间,默认为0
 */
@property (nonatomic,assign)    NSTimeInterval startTime;


/**
 *  结束时间,默认为0
 *  @discussion 搜索的结束时间,0 表示最大时间戳
 */
@property (nonatomic,assign)    NSTimeInterval endTime;

/**
 *  检索条数
 *  @discussion 默认100条,设置为0表示无条数限制
 */
@property (nonatomic,assign)    NSUInteger limit;

/**
 *  检索顺序
 */
@property (nonatomic,assign)    NIMMessageSearchOrder order;

/**
 *  查询的消息类型
 *  @discusssion 默认为 NIMMessageTypeText
 */
@property (nonatomic,assign)    NIMMessageType messageType;

/**
 *  全部消息类型
 *  @discussion 默认为 NO，当设置为 YES 时，忽略 messageType 和 searchContent，同时返回所有的消息类型消息
 */
@property (nonatomic,assign)    BOOL allMessageTypes;

/**
 *  检索文本
 *  @discussion 只有在 messageType 为 NIMMessageTypeText 时才有效
 */
@property (nullable,nonatomic,copy)      NSString *searchContent;

/**
 *  消息发出者帐号列表
 */
@property (nullable,nonatomic,copy)      NSArray<NSString *> *fromIds;

@end


/**
 *  检索服务器历史消息选项
 */
@interface NIMHistoryMessageSearchOption : NSObject

/**
 *  检索消息起始时间
 *  @discussion 需要检索的起始时间,没有则传入0。
 */
@property (nonatomic,assign)      NSTimeInterval  startTime;

/**
 *  检索条数
 *  @discussion 最大限制100条
 */
@property (nonatomic,assign)      NSUInteger       limit;


/**
 *  检索消息终止时间,此参数对聊天室会话无效。
 *  @discussion 当前最早的时间,没有则传入0。
 */
@property (nonatomic,assign)      NSTimeInterval  endTime;


/**
 *  检索消息的当前参考消息,返回的消息结果集里不会包含这条消息,此参数对聊天室会话无效。
 *  @discussion 传入最早时间,没有则传入nil。
 */
@property (nullable,nonatomic,strong)      NIMMessage      *currentMessage;


/**
 *  检索顺序。
 */
@property (nonatomic,assign)      NIMMessageSearchOrder             order;

/**
 *  是否需要同步到DB，此参数对聊天室会话无效。
 */
@property (nonatomic,assign)      BOOL            sync;


@end

NS_ASSUME_NONNULL_END
