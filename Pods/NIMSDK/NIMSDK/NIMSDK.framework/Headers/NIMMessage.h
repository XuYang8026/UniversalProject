//
//  NIMMessage.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMGlobalDefs.h"
#import "NIMSession.h"
#import "NIMLoginClient.h"
#import "NIMImageObject.h"
#import "NIMLocationObject.h"
#import "NIMAudioObject.h"
#import "NIMCustomObject.h"
#import "NIMVideoObject.h"
#import "NIMFileObject.h"
#import "NIMNotificationObject.h"
#import "NIMTipObject.h"
#import "NIMMessageSetting.h"
#import "NIMMessageReceipt.h"
#import "NIMAntiSpamOption.h"
#import "NIMMessageApnsMemberOption.h"

NS_ASSUME_NONNULL_BEGIN

@class NIMMessageChatroomExtension;

/**
 *  消息送达状态枚举
 */
typedef NS_ENUM(NSInteger, NIMMessageDeliveryState){
    /**
     *  消息发送失败
     */
    NIMMessageDeliveryStateFailed,
    /**
     *  消息发送中
     */
    NIMMessageDeliveryStateDelivering,
    /**
     *  消息发送成功
     */
    NIMMessageDeliveryStateDeliveried
};

/**
 *  消息附件下载状态
 */
typedef NS_ENUM(NSInteger, NIMMessageAttachmentDownloadState){
    /**
     *  附件需要进行下载 (有附件但并没有下载过)
     */
    NIMMessageAttachmentDownloadStateNeedDownload,
    /**
     *  附件收取失败 (尝试下载过一次并失败)
     */
    NIMMessageAttachmentDownloadStateFailed,
    /**
     *  附件下载中
     */
    NIMMessageAttachmentDownloadStateDownloading,
    /**
     *  附件下载成功/无附件
     */
    NIMMessageAttachmentDownloadStateDownloaded
};




/**
 *  消息体协议
 */
@protocol NIMMessageObject;
/**
 *  消息结构
 */
@interface NIMMessage : NSObject

/**
 *  消息类型
 */
@property (nonatomic,assign,readonly)       NIMMessageType messageType;

/**
 *  消息来源
 */
@property (nullable,nonatomic,copy)                  NSString *from;

/**
 *  消息所属会话
 */
@property (nullable,nonatomic,copy,readonly)       NIMSession *session;

/**
 *  消息ID,唯一标识
 */
@property (nonatomic,copy,readonly)         NSString *messageId;

/**
 *  消息文本
 *  @discussion 聊天室消息中除 NIMMessageTypeText 和 NIMMessageTypeTip 外，其他消息 text 字段都为 nil
 */
@property (nullable,nonatomic,copy)                  NSString *text;

/**
 *  消息附件内容
 */
@property (nullable,nonatomic,strong)                id<NIMMessageObject> messageObject;


/**
 *  消息设置
 *  @discussion 可以通过这个字段制定当前消息的各种设置,如是否需要计入未读，是否需要多端同步等
 */
@property (nullable,nonatomic,strong)                NIMMessageSetting *setting;

/**
 *  消息反垃圾配置
 *  @discussion 目前仅支持易盾，只有接入了易盾才可以设置这个配置
 */
@property (nullable,nonatomic,strong)                NIMAntiSpamOption *antiSpamOption;


/**
 *  消息推送文案,长度限制200字节
 */
@property (nullable,nonatomic,copy)                  NSString *apnsContent;

/**
 *  消息推送Payload
 *  @discussion 可以通过这个字段定义消息推送Payload,支持字段参考苹果技术文档,长度限制 2K
 */
@property (nullable,nonatomic,copy)                NSDictionary *apnsPayload;

/**
 *  指定成员推送选项
 *  @discussion 通过这个选项进行一些更复杂的推送设定，目前只能在群会话中使用
 */
@property (nullable,nonatomic,strong)                NIMMessageApnsMemberOption *apnsMemberOption;


/**
 *  服务器扩展
 *  @discussion 客户端可以设置这个字段,这个字段将在本地存储且发送至对端,上层需要保证 NSDictionary 可以转换为 JSON，长度限制 4K
 */
@property (nullable,nonatomic,copy)                NSDictionary    *remoteExt;

/**
 *  客户端本地扩展
 *  @discussion 客户端可以设置这个字段，这个字段只在本地存储,不会发送至对端,上层需要保证 NSDictionary 可以转换为 JSON
 */
@property (nullable,nonatomic,copy)                NSDictionary    *localExt;

/**
 *  消息拓展字段
 *  @discussion 服务器下发的消息拓展字段，并不在本地做持久化，目前只有聊天室中的消息才有该字段(NIMMessageChatroomExtension)
 */
@property (nullable,nonatomic,strong)                id messageExt;

/**
 *  消息发送时间
 *  @discussion 本地存储消息可以通过修改时间戳来调整其在会话列表中的位置，发完服务器的消息时间戳将被服务器自动修正
 */
@property (nonatomic,assign)                NSTimeInterval timestamp;

/**
 *  消息投递状态 仅针对发送的消息
 */
@property (nonatomic,assign,readonly)       NIMMessageDeliveryState deliveryState;


/**
 *  消息附件下载状态 仅针对收到的消息
 */
@property (nonatomic,assign,readonly)       NIMMessageAttachmentDownloadState attachmentDownloadState;


/**
 *  是否是收到的消息
 *  @discussion 由于有漫游消息的概念,所以自己发出的消息漫游下来后仍旧是"收到的消息",这个字段用于消息出错是时判断需要重发还是重收
 */
@property (nonatomic,assign,readonly)       BOOL isReceivedMsg;

/**
 *  是否是往外发的消息
 *  @discussion 由于能对自己发消息，所以并不是所有来源是自己的消息都是往外发的消息，这个字段用于判断头像排版位置（是左还是右）。
 */
@property (nonatomic,assign,readonly)       BOOL isOutgoingMsg;

/**
 *  消息是否被播放过
 *  @discussion 修改这个属性,后台会自动更新db中对应的数据
 */
@property (nonatomic,assign)                BOOL isPlayed;


/**
 *  消息是否标记为已删除
 *  @discussion 已删除的消息在获取本地消息列表时会被过滤掉，只有根据messageId获取消息的接口可能会返回已删除消息。
 */
@property (nonatomic,assign,readonly)       BOOL isDeleted;


/**
 *  对端是否已读
 *  @discussion 只有当当前消息为 P2P 消息且 isOutgoingMsg 为 YES 时这个字段才有效，需要对端调用过发送已读回执的接口
 */
@property (nonatomic,assign,readonly)       BOOL isRemoteRead;

/**
 *  消息发送者名字
 *  @discussion 当发送者是自己时,这个值可能为空,这个值表示的是发送者当前的昵称,而不是发送消息时的昵称。聊天室消息里，此字段无效。
 */
@property (nullable,nonatomic,copy,readonly)         NSString *senderName;


/**
 *  发送者客户端类型
 */
@property (nonatomic,assign,readonly)   NIMLoginClientType senderClientType;
@end

NS_ASSUME_NONNULL_END
