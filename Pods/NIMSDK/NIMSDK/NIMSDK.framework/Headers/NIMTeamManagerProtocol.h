//
//  NIMTeamManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NIMTeamDefs.h"
#import "NIMTeam.h"
#import "NIMTeamMember.h"
#import "NIMCreateTeamOption.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  通用的群组操作block
 *
 *  @param error 错误,如果成功则error为nil
 */
typedef void(^NIMTeamHandler)(NSError * __nullable error);

/**
 *  创建群组block
 *
 *  @param error   错误,如果成功则error为nil
 *  @param teamId 群组ID
 */
typedef void(^NIMTeamCreateHandler)(NSError * __nullable error,NSString * __nullable teamId);

/**
 *  群成员block
 *
 *  @param error   错误,如果成功则error为nil
 *  @param members 群成员列表,内部为NIMTeamMember
 */
typedef void(^NIMTeamMemberHandler)(NSError * __nullable error,NSArray<NIMTeamMember *> * __nullable members);

/**
 *  拉取群信息Block
 *
 *  @param error 错误,如果成功则error为nil
 *  @param team  群信息
 */
typedef void(^NIMTeamFetchInfoHandler)(NSError * __nullable error,NIMTeam * __nullable team);

/**
 *  群申请block
 *
 *  @param error       错误,如果成功则error为nil
 *  @param applyStatus 群申请状态
 */
typedef void(^NIMTeamApplyHandler)(NSError * __nullable error,NIMTeamApplyStatus applyStatus);


/**
 *  群组委托
 */
@protocol NIMTeamManagerDelegate <NSObject>

@optional
/**
 *  群组增加回调
 *
 *  @param team 添加的群组
 */
- (void)onTeamAdded:(NIMTeam *)team;

/**
 *  群组更新回调
 *
 *  @param team 更新的群组
 */
- (void)onTeamUpdated:(NIMTeam *)team;

/**
 *  群组移除回调
 *
 *  @param team 被移除的群组
 */
- (void)onTeamRemoved:(NIMTeam *)team;

/**
 *  群组成员变动回调,包括数量增减以及成员属性变动
 *
 *  @param team 变动的群组
 */
- (void)onTeamMemberChanged:(NIMTeam *)team;

@end


/**
 *  群组协议
 */
@protocol NIMTeamManager <NSObject>
/**
 *  获取所有群组
 *
 *  @return 返回所有群组
 */
- (nullable NSArray<NIMTeam *> *)allMyTeams;

/**
 *  根据群组ID获取具体的群组信息
 *
 *  @param teamId 群组ID
 *
 *  @return 群组信息
 */
- (nullable NIMTeam *)teamById:(NSString *)teamId;


/**
 *  根据群组ID判断是否是我所在的群
 *
 *  @param teamId 群组ID
 *
 *  @return 是否在此群组
 */
- (BOOL)isMyTeam:(NSString *)teamId;

/**
 *  创建群组
 *
 *  @param option     创建群选项
 *  @param users      用户ID列表
 *  @param completion 完成后的回调
 */
- (void)createTeam:(NIMCreateTeamOption *)option
              users:(NSArray<NSString *> *)users
         completion:(nullable NIMTeamCreateHandler)completion;

/**
 *  解散群组
 *
 *  @param teamId      群组ID
 *  @param completion  完成后的回调
 */
- (void)dismissTeam:(NSString *)teamId
         completion:(nullable NIMTeamHandler)completion;

/**
 *  退出群组
 *
 *  @param teamId     群组ID
 *  @param completion 完成后的回调
 */
- (void)quitTeam:(NSString *)teamId
      completion:(nullable NIMTeamHandler)completion;

/**
 *  邀请用户入群
 *
 *  @param users       用户ID列表
 *  @param teamId      群组ID
 *  @param postscript  邀请附言
 *  @param completion  完成后的回调
 */
- (void)addUsers:(NSArray<NSString *>  *)users
          toTeam:(NSString *)teamId
      postscript:(NSString *)postscript
      completion:(nullable NIMTeamMemberHandler)completion;

/**
 *  从群组内移除成员
 *
 *  @param users       需要移除的用户ID列表
 *  @param teamId      群组ID
 *  @param completion  完成后的回调
 */
- (void)kickUsers:(NSArray<NSString *> *)users
         fromTeam:(NSString *)teamId
       completion:(nullable NIMTeamHandler)completion;

/**
 *  更新群组名称
 *
 *  @param teamName   群组名称
 *  @param teamId     群组ID
 *  @param completion 完成后的回调
 */
- (void)updateTeamName:(NSString *)teamName
                teamId:(NSString *)teamId
            completion:(nullable NIMTeamHandler)completion;


/**
 *  更新群组头像
 *
 *  @param teamAvatarUrl 群组头像Url
 *  @param teamId        群组ID
 *  @param completion    完成后的回调
 */
- (void)updateTeamAvatar:(NSString *)teamAvatarUrl
                  teamId:(NSString *)teamId
              completion:(nullable NIMTeamHandler)completion;


/**
 *  更新群组验证方式
 *
 *  @param joinMode   验证方式
 *  @param teamId     群组ID
 *  @param completion 完成后的回调
 */
- (void)updateTeamJoinMode:(NIMTeamJoinMode)joinMode
                    teamId:(NSString *)teamId
                completion:(nullable NIMTeamHandler)completion;


/**
 *  更新群组邀请他人方式
 *
 *  @param inviteMode  邀请方式
 *  @param teamId      群组ID
 *  @param completion  完成后的回调
 */
- (void)updateTeamInviteMode:(NIMTeamInviteMode)inviteMode
                      teamId:(NSString *)teamId
                  completion:(nullable NIMTeamHandler)completion;

/**
 *  更新群组被邀请人验证方式
 *
 *  @param beInviteMode 邀请方式
 *  @param teamId       群组ID
 *  @param completion   完成后的回调
 */
- (void)updateTeamBeInviteMode:(NIMTeamBeInviteMode)beInviteMode
                        teamId:(NSString *)teamId
                    completion:(nullable NIMTeamHandler)completion;


/**
 *  更改群组更新信息的权限
 *
 *  @param updateInfoMode 修改谁有权限更新群组信息
 *  @param teamId         群组ID
 *  @param completion     完成后的回调
 */
- (void)updateTeamUpdateInfoMode:(NIMTeamUpdateInfoMode)updateInfoMode
                          teamId:(NSString *)teamId
                      completion:(nullable NIMTeamHandler)completion;


/**
 *  更改群组更新自定义字段的权限
 *
 *  @param clientCustomMode 修改谁有权限更新群组自定义字段
 *  @param teamId           群组ID
 *  @param completion       完成后的回调
 */
- (void)updateTeamUpdateClientCustomMode:(NIMTeamUpdateClientCustomMode)clientCustomMode
                                  teamId:(NSString *)teamId
                              completion:(nullable NIMTeamHandler)completion;



/**
 *  更新群介绍
 *
 *  @param intro       群介绍
 *  @param teamId      群组ID
 *  @param completion  完成后的回调
 */
- (void)updateTeamIntro:(NSString *)intro
                 teamId:(NSString *)teamId
             completion:(nullable NIMTeamHandler)completion;


/**
 *  更新群公告
 *
 *  @param announcement 群公告
 *  @param teamId       群组ID
 *  @param completion   完成后的回调
 */
- (void)updateTeamAnnouncement:(NSString *)announcement
                        teamId:(NSString *)teamId
                    completion:(nullable NIMTeamHandler)completion;

/**
 *  更新群自定义信息
 *
 *  @param info         群自定义信息
 *  @param teamId       群组ID
 *  @param completion   完成后的回调
 */
- (void)updateTeamCustomInfo:(NSString *)info
                      teamId:(NSString *)teamId
                  completion:(nullable NIMTeamHandler)completion;


/**
 *  更新群信息
 *
 *  @param values      需要更新的群信息键值对
 *  @param teamId      群组ID
 *  @param completion  完成后的回调
 *  @discussion   这个接口可以一次性修改群的多个属性,如名称,公告等,传入的数据键值对是 {@(NIMTeamUpdateTag) : NSString},无效数据将被过滤
 */
- (void)updateTeamInfos:(NSDictionary<NSNumber *,NSString *> *)values
                 teamId:(NSString *)teamId
             completion:(nullable NIMTeamHandler)completion;



/**
 *  群申请
 *
 *  @param teamId     群组ID
 *  @param message    申请消息
 *  @param completion 完成后的回调
 */
- (void)applyToTeam:(NSString *)teamId
            message:(NSString *)message
         completion:(nullable NIMTeamApplyHandler)completion;


/**
 *  通过群申请
 *
 *  @param teamId       群组ID
 *  @param userId       申请的用户ID
 *  @param completion   完成后的回调
 */
- (void)passApplyToTeam:(NSString *)teamId
                 userId:(NSString *)userId
             completion:(nullable NIMTeamApplyHandler)completion;

/**
 *  拒绝群申请
 *
 *  @param teamId       群组ID
 *  @param userId       申请的用户ID
 *  @param rejectReason 拒绝理由
 *  @param completion   完成后的回调
 */
- (void)rejectApplyToTeam:(NSString *)teamId
                   userId:(NSString *)userId
             rejectReason:(NSString*)rejectReason
               completion:(nullable NIMTeamHandler)completion;


/**
 *  更新成员群昵称
 *
 *  @param userId       群成员ID
 *  @param newNick      新的群成员昵称
 *  @param teamId       群组ID
 *  @param completion   完成后的回调
 */
- (void)updateUserNick:(NSString *)userId
               newNick:(NSString *)newNick
                inTeam:(NSString *)teamId
            completion:(nullable NIMTeamHandler)completion;


/**
 *  更新成员群自定义属性
 *
 *  @param newInfo      新的自定义属性
 *  @param teamId       群组ID
 *  @param completion   完成后的回调
 *  @discussion
 */
- (void)updateMyCustomInfo:(NSString *)newInfo
                    inTeam:(NSString *)teamId
                completion:(nullable NIMTeamHandler)completion;

/**
 *  添加管理员
 *
 *  @param teamId      群组ID
 *  @param users       需要添加为管理员的用户ID列表
 *  @param completion  完成后的回调
 */
- (void)addManagersToTeam:(NSString *)teamId
                    users:(NSArray<NSString *>  *)users
               completion:(nullable NIMTeamHandler)completion;

/**
 *  移除管理员
 *
 *  @param teamId     群组ID
 *  @param users      需要移除管理员的用户ID列表
 *  @param completion 完成后的回调
 */
- (void)removeManagersFromTeam:(NSString *)teamId
                         users:(NSArray<NSString *>  *)users
                    completion:(nullable NIMTeamHandler)completion;


/**
 *  移交群主
 *
 *  @param teamId     群组ID
 *  @param newOwnerId 新群主ID
 *  @param isLeave    是否同时离开群组
 *  @param completion 完成后的回调
 */
- (void)transferManagerWithTeam:(NSString *)teamId
                     newOwnerId:(NSString *)newOwnerId
                        isLeave:(BOOL)isLeave
                     completion:(nullable NIMTeamHandler)completion;


/**
 *  接受入群邀请
 *
 *  @param teamId     群组ID
 *  @param invitorId  邀请者ID
 *  @param completion 完成后的回调
 */
- (void)acceptInviteWithTeam:(NSString*)teamId
                   invitorId:(NSString*)invitorId
                  completion:(nullable NIMTeamHandler)completion;


/**
 *  拒绝入群邀请
 *
 *  @param teamId       群组ID
 *  @param invitorId    邀请者ID
 *  @param rejectReason 拒绝原因
 *  @param completion   完成后的回调
 */
- (void)rejectInviteWithTeam:(NSString*)teamId
                   invitorId:(NSString*)invitorId
                rejectReason:(NSString*)rejectReason
                  completion:(nullable NIMTeamHandler)completion;


/**
 *  修改群通知状态
 *
 *  @param notify       是否通知
 *  @param teamId       群组ID
 *  @param completion   完成后的回调
 */
- (void)updateNotifyState:(BOOL)notify
                   inTeam:(NSString *)teamId
               completion:(nullable NIMTeamHandler)completion;

/**
 *  是否需要消息通知
 *
 *  @param teamId 群Id
 *
 *  @return 是否需要消息通知
 */
- (BOOL)notifyForNewMsg:(NSString *)teamId;


/**
 *  群成员禁言
 *
 *  @param mute        是否禁言
 *  @param userId      用户ID
 *  @param teamId      群组ID
 *  @param completion  经验操作完成后的回调
 *  @discussion   操作成功后，云信服务器会下发禁言的群通知消息
 */
- (void)updateMuteState:(BOOL)mute
                 userId:(NSString *)userId
                 inTeam:(NSString *)teamId
             completion:(nullable NIMTeamHandler)completion;


/**
 *  获取群组成员
 *
 *  @param teamId     群组ID
 *  @param completion 完成后的回调
 *  @discussion   绝大多数情况这个请求都是从本地读取缓存并同步返回，但是由于群成员信息量较大， SDK 采取的是登录后延迟拉取的策略
 *                考虑到用户网络等问题, SDK 有可能没有及时缓存群成员信息,那么这个请求将是个带网络请求的异步操作(增量请求)。
 *                同时这个接口会去请求本地没有缓存的群用户的资料信息，但不会触发 - (void)onUserInfoChanged: 回调。
 */
- (void)fetchTeamMembers:(NSString *)teamId
              completion:(nullable NIMTeamMemberHandler)completion;



/**
 *  获取群内被禁言的成员列表
 *
 *  @param teamId     群组ID
 *  @param completion 完成后的回调
 *  @discussion   绝大多数情况这个请求都是从本地读取缓存并同步返回，但是由于群成员信息量较大， SDK 采取的是登录后延迟拉取的策略
 *                考虑到用户网络等问题, SDK 有可能没有及时缓存群成员信息,那么这个请求将是个带网络请求的异步操作(增量请求)。
 *                同时这个接口会去请求本地没有缓存的群用户的资料信息，但不会触发 - (void)onUserInfoChanged: 回调。
 */
- (void)fetchTeamMutedMembers:(NSString *)teamId
                   completion:(nullable NIMTeamMemberHandler)completion;


/**
 *  通过网络请求获取群组成员
 *
 *  @param teamId      群组ID
 *  @param completion  完成后的回调
 *  @discussion   通过网络请求获取群成员列表,不同于fetchTeamMembers:completion这个接口是个必然带网络请求的异步操作(增量请求)
 *                同时这个接口会去请求本地没有缓存的群用户的资料信息，但不会触发 - (void)onUserInfoChanged: 回调。
 */
- (void)fetchTeamMembersFromServer:(NSString *)teamId
                        completion:(nullable NIMTeamMemberHandler)completion;


/**
 *  获取群信息
 *
 *  @param teamId      群组ID
 *  @param completion  完成后的回调
 */
- (void)fetchTeamInfo:(NSString *)teamId
           completion:(nullable NIMTeamFetchInfoHandler)completion;


/**
 *  获取单个群成员信息
 *
 *  @param userId 用户ID
 *  @param teamId 群组ID
 *  @return       返回成员信息
 *  @discussion   返回本地缓存的群成员信息，如果本地没有相应数据则返回 nil。
 */
- (nullable NIMTeamMember *)teamMember:(NSString *)userId
                                inTeam:(NSString *)teamId;


/**
 *  添加群组委托
 *
 *  @param delegate 群组委托
 */
- (void)addDelegate:(id<NIMTeamManagerDelegate>)delegate;

/**
 *  移除群组委托
 *
 *  @param delegate 群组委托
 */
- (void)removeDelegate:(id<NIMTeamManagerDelegate>)delegate;
@end

NS_ASSUME_NONNULL_END
