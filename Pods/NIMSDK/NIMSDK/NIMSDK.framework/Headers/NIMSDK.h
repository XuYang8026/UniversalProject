//
//  NIMSDK.h
//  NIMSDK
//
//  Created by chris on 2017/2/7.
//  Copyright © 2017年 Netease. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  全局枚举和结构体定义
 */
#import "NIMGlobalDefs.h"

/**
 *  配置项
 */
#import "NIMSDKConfig.h"

/**
 *  会话相关定义
 */
#import "NIMSession.h"
#import "NIMRecentSession.h"
#import "NIMMessageSearchOption.h"

/**
 *  用户定义
 */
#import "NIMUser.h"

/**
 *  群相关定义
 */
#import "NIMTeamDefs.h"
#import "NIMTeam.h"
#import "NIMTeamMember.h"
#import "NIMCreateTeamOption.h"
/**
 *  聊天室相关定义
 */
#import "NIMChatroom.h"
#import "NIMChatroomEnterRequest.h"
#import "NIMMessageChatroomExtension.h"
#import "NIMChatroomMember.h"
#import "NIMChatroomMemberRequest.h"
#import "NIMChatroomUpdateRequest.h"
#import "NIMChatroomQueueRequest.h"

/**
 *  消息定义
 */
#import "NIMMessage.h"
#import "NIMSystemNotification.h"
#import "NIMRevokeMessageNotification.h"

/**
 *  推送定义
 */
#import "NIMPushNotificationSetting.h"

/**
 *  登录定义
 */
#import "NIMLoginClient.h"

/**
 *  文档转码信息
 */
#import "NIMDocTranscodingInfo.h"

/**
 *  事件订阅
 */
#import "NIMSubscribeEvent.h"
#import "NIMSubscribeRequest.h"
#import "NIMSubscribeOnlineInfo.h"
#import "NIMSubscribeResult.h"

/**
 *  各个对外接口协议定义
 */
#import "NIMLoginManagerProtocol.h"
#import "NIMChatManagerProtocol.h"
#import "NIMConversationManagerProtocol.h"
#import "NIMMediaManagerProtocol.h"
#import "NIMUserManagerProtocol.h"
#import "NIMTeamManagerProtocol.h"
#import "NIMSystemNotificationManagerProtocol.h"
#import "NIMApnsManagerProtocol.h"
#import "NIMResourceManagerProtocol.h"
#import "NIMChatroomManagerProtocol.h"
#import "NIMDocTranscodingManagerProtocol.h"
#import "NIMEventSubscribeManagerProtocol.h"

/**
 *  SDK业务类
 */
#import "NIMSDKHeader.h"
