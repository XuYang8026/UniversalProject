//
//  NIMSubscribeResult.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2017 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * 查询订阅关系的结果
 * @discussion 由查询订阅关系接口返回，表示和本账号订阅的关系详情
 */
@interface NIMSubscribeResult : NSObject

/**
 *  事件类型
 */
@property (nonatomic, assign, readonly) NSInteger type;

/**
 *  订阅有效期
 */
@property (nonatomic, assign, readonly) NSTimeInterval expiry;


/**
 *  订阅时间
 */
@property (nonatomic, assign, readonly) NSTimeInterval timestamp;


/**
 *  订阅发布事件者的 Id
 */
@property (nonatomic, copy, readonly) NSString *publisher;


@end
