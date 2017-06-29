//
//  NIMCustomObject.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015年 Netease. All rights reserved.
//

#import "NIMMessageObjectProtocol.h"

NS_ASSUME_NONNULL_BEGIN
/*
 除了 SDK 预定义的几种消息类型，上层APP开发者如果想要实现更多的消息类型，不可避免需要使用自定义消息这种类型
 由于 SDK 并不能预测上层 APP 的应用场景，所以 NIMCustomObject 采取消息透传的方式以提供给上层开发者最大的自由度
 即 SDK 只负责发送和收取由 NIMCustomObject 中 id<NIMCustomAttachment> attachment 序列化和反序列化后的字节流
 在发送端,SDK 获取 encodeAttachment 后得到的字节流发送至对面端
 在接收端,SDK 读取字节流，并通过上层 APP 设置的反序列化对象进行解析 (registerCustomDecoder:)

文件上传:
 为了方便 APP 在自定义消息类型中进行文件的上传，SDK 也提供了三个接口文件上传
 即只要 APP 实现上传相关的接口，资源的上传就可以由 SDK 自动完成
 如需要上传资源需要实现的接口有：
 1. - (BOOL)attachmentNeedsUpload  是否有文件需要上传,在有文件且文件没有上传成功时返回YES
 2. - (NSString *)attachmentPathForUploading  返回需要上传的文件路径
 3. - (void)updateAttachmentURL:(NSString *)urlString 上传成功后SDK会调用这个接口,APP 需要实现这个接口来保存上传后的URL
 具体可以参考 DEMO 中阅后即焚的实现
 
 */



/**
 *  自定义消息对象附件协议
 */
@protocol NIMCustomAttachment <NSObject>
@required

/**
 *  序列化attachment
 *
 *  @return 序列化后的结果，将用于透传
 */
- (NSString *)encodeAttachment;

@optional
#pragma mark - 上传相关接口
/**
 *  是否需要上传附件
 *
 *  @return 是否需要上传附件
 */
- (BOOL)attachmentNeedsUpload;

/**
 *  需要上传的附件路径
 *
 *  @return 路径
 */
- (NSString *)attachmentPathForUploading;

/**
 *  更新附件URL
 *
 *  @param urlString 附件url
 */
- (void)updateAttachmentURL:(NSString *)urlString;

#pragma mark - 下载相关接口
/**
 *  是否需要下载附件
 *
 *  @return 是否需要上传附件
 */
- (BOOL)attachmentNeedsDownload;

/**
 *  需要下载的附件url
 *
 *  @return 附件url
 *  @discussion 如果当前字段是云信的 http url 地址，那么需要调用 id<NIMResourceManager> 中 convertHttpToHttps: 方法将这个地址转换为 https
 */
- (NSString *)attachmentURLStringForDownloading;

/**
 *  需要下载的附件本地路径
 *
 *  @return 附件本地路径
 *  @discussion 上层需要保证路径的
 */
- (NSString *)attachmentPathForDownloading;

@end



/**
 *  自定义消息对象附件序列化协议
 */
@protocol NIMCustomAttachmentCoding<NSObject>
@required

/**
 *  反序列化
 *
 *  @param content 透传的自定义消息
 *
 *  @return 自定义消息附件
 */
- (nullable id<NIMCustomAttachment>)decodeAttachment:(nullable NSString *)content;
@end


/**
 *  用户自定义消息对象
 */
@interface NIMCustomObject : NSObject<NIMMessageObject>

/**
 *  用户自定义附件
 *  @discussion SDK负责将attachment通过encodeAttachment接口序列化后的结果进行透传
 */
@property(nullable, nonatomic, strong) id<NIMCustomAttachment>  attachment;


/**
 *  注册自定义消息解析器
 *
 *  @param decoder 自定义消息解析器
 *  @disucssion 如果用户使用自定义消息类型,就需要注册自定义消息解析器，负责将透传过来的自定义消息反序列化成上层应用可识别的对象
 */
+ (void)registerCustomDecoder:(id<NIMCustomAttachmentCoding>)decoder;

@end


NS_ASSUME_NONNULL_END
