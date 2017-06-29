//
//  NIMDocTranscodingManagerProtocol.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2016 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NIMDocTranscodingInfo;

NS_ASSUME_NONNULL_BEGIN


/**
 查询文档转码信息结果 block

 @param error 执行结果，如果成功则为 nil
 @param info 查询到的文档转码信息
 */
typedef void(^NIMDocTranscodingInquireCompleteBlock)(NSError * __nullable error, NIMDocTranscodingInfo * __nullable info);


/**
 拉取文档转码信息列表结果 block

 @param error 执行结果，如果成功则为 nil
 @param infos 拉取到的所有文档转码信息
 */
typedef void(^NIMDocTranscodingFetchCompleteBlock)(NSError * __nullable error, NSArray<NIMDocTranscodingInfo *> * __nullable infos);

/**
 *  删除转码文档结果 block
 *
 @param error 执行结果，如果成功则为 nil
 */
typedef void(^NIMDocTranscodingDeleteCompleteBlock)(NSError * __nullable error);

/**
 *  文档转码管理器
 */
@protocol NIMDocTranscodingManager <NSObject>

/**
 查询文档转码信息

 @param docId 转码文档标识 id
 @param completion 查询结果 block
 */
- (void)inquireDocInfo:(NSString *)docId
            completion:(nullable NIMDocTranscodingInquireCompleteBlock)completion;

/**
 拉取文档转码信息列表

 @param lastDocId 最后一个文档的锚点，不包括此文档。填 nil 会从最新提交的转码文档开始往前查询。
 @param limit 拉取文档的最大个数，每次拉取的个数不能超过 30
 @param completion 拉取结果 block
 */
- (void)fetchMyDocsInfo:(nullable NSString *)lastDocId
                  limit:(NSUInteger)limit
             completion:(nullable NIMDocTranscodingFetchCompleteBlock)completion;

/**
 删除转码文档

 @param docId 转码文档标识 id
 @param completion 删除转码文档结果 block
 */
- (void)deleteDoc:(NSString *)docId
       completion:(nullable NIMDocTranscodingDeleteCompleteBlock)completion;

@end


NS_ASSUME_NONNULL_END
