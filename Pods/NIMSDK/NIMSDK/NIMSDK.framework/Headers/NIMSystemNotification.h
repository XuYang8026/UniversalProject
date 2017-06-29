//
//  NIMSystemNotification.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMSession.h"
#import "NIMUser.h"
#import "NIMCustomSystemNotificationSetting.h"
#import "NIMAntiSpamOption.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  系统通知类型
 */
typedef NS_ENUM(NSInteger, NIMSystemNotificationType){
    /**
     *  申请入群
     */
    NIMSystemNotificationTypeTeamApply              = 0,
    /**
     *  拒绝入群
     */
    NIMSystemNotificationTypeTeamApplyReject        = 1,
    /**
     *  邀请入群
     */
    NIMSystemNotificationTypeTeamInvite             = 2,
    /**
     *  拒绝入群邀请
     */
    NIMSystemNotificationTypeTeamIviteReject        = 3,
    
    /**
     *  添加好友
     */
    NIMSystemNotificationTypeFriendAdd              = 5,
    
};

#pragma mark - 系统通知
/**
 *  系统通知
 */
@interface NIMSystemNotification : NSObject
/**
 *  通知类型
 */
@property (nonatomic,assign,readonly)       NIMSystemNotificationType type;

/**
 *  时间戳
 */
@property (nonatomic,assign,readonly)       NSTimeInterval timestamp;

/**
 *  操作者
 */
@property (nullable,nonatomic,copy,readonly)         NSString *sourceID;

/**
 *  目标ID,群ID或者是用户ID
 */
@property (nullable,nonatomic,copy,readonly)         NSString *targetID;

/**
 *  附言
 */
@property (nullable,nonatomic,copy,readonly)         NSString *postscript;

/**
 *  是否已读
 *  @discussion 修改这个属性并不会修改db中的数据
 */
@property (nonatomic,assign)                BOOL read;

/**
 *  消息处理状态
 *  @discussion 修改这个属性,后台会自动更新db中对应的数据,SDK调用者可以使用这个值来持久化他们对消息的处理结果,默认为0
 */
@property (nonatomic,assign)                NSInteger handleStatus;


/**
 *  系统通知下发的自定义扩展信息
 */
@property (nullable,nonatomic,readonly)   NSString *notifyExt;

/**
 *  附件
 *  @discussion 额外信息,只有 好友添加
 *              好友添加的 attachment 为 NIMUserAddAttachment
 */
@property (nullable,nonatomic,strong,readonly)       id attachment;

@end


/**
 *  添加好友附件
 */
@interface NIMUserAddAttachment : NSObject

/**
 *  好友操作类型
 */
@property (nonatomic,assign,readonly)   NIMUserOperation    operationType;

@end


/**
 *  系统通知过滤器
 */
@interface NIMSystemNotificationFilter : NSObject
/**
 *  类型列表
 */
@property (nonatomic,copy)    NSArray<NSNumber *>     *notificationTypes;
@end


#pragma mark - 自定义系统通知
/**
 *  自定义系统消息
 */
@interface NIMCustomSystemNotification : NSObject

/**
 *  时间戳
 */
@property (nonatomic,assign,readonly)       NSTimeInterval timestamp;

/**
 *  通知发起者id
 */
@property (nullable,nonatomic,copy,readonly)         NSString *sender;

/**
 *  通知接受者id
 */
@property (nullable,nonatomic,copy,readonly)         NSString *receiver;


/**
 *  通知接受者类型
 */
@property (nonatomic,assign,readonly)       NIMSessionType  receiverType;

/**
 *  透传的消息体内容
 */
@property (nullable,nonatomic,copy,readonly)         NSString    *content;

/**
 *  是否只发送给在线用户
 *  @discussion 默认为YES 如果这个值为NO,通知接受者如果在通知投递时不在线,那么他会在下次登录时收到这个通知。如果消息接受者是群,则只允许投递到当前在线的用户
 */
@property (nonatomic,assign)                BOOL sendToOnlineUsersOnly;

/**
 *  apns推送文案
 *  @discussion 默认为nil,用户可以设置当前通知的推送文案
 */
@property (nullable,nonatomic,copy)                  NSString *apnsContent;


/**
 *  apns推送Payload
 *  @discussion 可以通过这个字段定义自定义通知的推送Payload,支持字段参考苹果技术文档,最多支持2K
 */
@property (nullable,nonatomic,copy)                  NSDictionary *apnsPayload;

/**
 *  自定义系统通知设置
 *  @discussion 可以通过这个字段制定当前通知的各种设置,如是否需要计入推送未读，是否需要带推送前缀等等
 */
@property (nullable,nonatomic,strong)                NIMCustomSystemNotificationSetting *setting;


/**
 *  反垃圾选项
 */
@property (nullable,nonatomic,strong)                NIMAntiSpamOption *antiSpamOption;


- (instancetype)initWithContent:(NSString *)content;

@end

NS_ASSUME_NONNULL_END
