//
//  NIMChatroomUpdateRequest.h
//  NIMLib
//
//  Created by Netease.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  聊天室信息修改字段
 */
typedef NS_ENUM(NSInteger, NIMChatroomUpdateTag){
    /**
     *  聊天室名称
     */
    NIMChatroomUpdateTagName         = 3,
    /**
     *  聊天室公告
     */
    NIMChatroomUpdateTagAnnouncement = 4,
    /**
     *  聊天室直播拉流地址
     */
    NIMChatroomUpdateTagBroadcastUrl = 5,
    /**
     *  聊天室扩展字段
     */
    NIMChatroomUpdateTagExt          = 12,
    
};


/**
 *  聊天室信息更新请求
 */
@interface NIMChatroomUpdateRequest : NSObject

/**
 *  聊天室ID
 */
@property (nonatomic,copy)   NSString *roomId;

/**
 *  修改信息字段,修改传入的数据键值对是 {@(NIMChatroomUpdateTag) : NSString},无效数据将被过滤
 */
@property (nonatomic,copy)   NSDictionary *updateInfo;

/**
 *  是否需要通知
 */
@property (nonatomic,assign) BOOL needNotify;

/**
 *  放到事件通知里的扩展字段
 */
@property (nullable,nonatomic,copy)   NSString *notifyExt;

@end

NS_ASSUME_NONNULL_END
