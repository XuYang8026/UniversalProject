//
//  NIMChatroom.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  聊天室
 */
@interface NIMChatroom : NSObject

/**
 *  聊天室Id
 */
@property (nullable,nonatomic,copy)     NSString    *roomId;

/**
 *  聊天室名
 */
@property (nullable,nonatomic,copy)     NSString    *name;

/**
 *  公告
 */
@property (nullable,nonatomic,copy)     NSString    *announcement;


/**
 *  创建者
 */
@property (nullable,nonatomic,copy)     NSString    *creator;


/**
 *  第三方扩展字段，长度限制4K
 */
@property (nullable,nonatomic,copy)     NSString *ext;

/**
 *  当前在线用户数量
 */
@property (nonatomic,assign)   NSInteger onlineUserCount;

/**
 *  直播拉流地址
 */
@property (nullable,nonatomic,copy)   NSString *broadcastUrl;

/**
 *  聊天室是否正在全员禁言标记，禁言后只有管理员可以发言
 */
- (BOOL)inAllMuteMode;

@end


NS_ASSUME_NONNULL_END


