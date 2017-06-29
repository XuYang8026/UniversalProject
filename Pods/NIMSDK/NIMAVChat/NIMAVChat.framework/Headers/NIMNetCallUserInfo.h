//
//  NIMNetCallUserInfo.h
//  NIMLib
//
//  Created by Netease on 16/9/23.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 网络通话用户信息
 */
@interface NIMNetCallUserInfo : NSObject

/**
 用户 id
 */
@property(nonatomic, copy, readonly) NSString *uid;

/**
 音量
 */
@property(nonatomic, assign, readonly) UInt16 volume;

@end
