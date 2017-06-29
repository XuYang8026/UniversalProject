//
//  NIMChatroomQueueRequest.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

/**
 *  聊天室通用队列更新请求
 */
@interface NIMChatroomQueueUpdateRequest : NSObject

/**
 *  聊天室ID
 */
@property (nonatomic,copy) NSString *roomId;

/**
 *  更新元素的Key值，如果key在队列中存在则更新，不存在则放到队列尾部 ，长度限制为32字节
 */
@property (nonatomic,copy) NSString *key;

/**
 *  更新元素的Value值，长度限制为4096字节
 */
@property (nonatomic,copy) NSString *value;

@end




/**
 *  聊天室通用队列取出请求
 */
@interface NIMChatroomQueueRemoveRequest : NSObject

/**
 *  聊天室ID
 */
@property (nonatomic,copy) NSString *roomId;

/**
 *  拉去元素的Key值，如果要拉取第一个元素，则传空
 */
@property (nullable,nonatomic,copy) NSString *key;


@end




NS_ASSUME_NONNULL_END