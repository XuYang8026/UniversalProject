//
//  NIMVideoObject.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015年 Netease. All rights reserved.
//

#import "NIMMessageObjectProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  视频实例对象
 */
@interface NIMVideoObject : NSObject<NIMMessageObject>

/**
 *  视频实例对象的初始化方法
 *
 *  @param sourcePath 视频的文件路径
 *
 *  @return 视频实例对象
 */
- (instancetype)initWithSourcePath:(NSString *)sourcePath;


/**
 *  视频实例对象的初始化方法
 *
 *  @param data 视频数据
 *  @param extension 视频文件后缀
 *
 *  @return 视频实例对象
 */
- (instancetype)initWithData:(NSData *)data
                   extension:(NSString *)extension;

/**
 *  视频展示名
 */
@property (nullable, nonatomic, copy) NSString *displayName;
/**
 *  视频MD5
 */
@property (nullable, nonatomic, copy, readonly) NSString *md5;



/**
 *  视频的本地路径
 *  @discussion 目前 SDK 并不提供视频下载功能,但是建议 APP 使用这个 path 作为视频的下载地址,以便后期 SDK 提供缓存清理等功能
 */
@property (nullable, nonatomic, copy, readonly) NSString *path;

/**
 *  视频的远程路径
 */
@property (nullable, nonatomic, copy, readonly) NSString *url;

/**
 *  视频封面的远程路径
 *  @discussion 只有是上传到云信服务器上的视频才支持封面地址，否则地址无效
 */
@property (nullable, nonatomic, copy, readonly) NSString *coverUrl;

/**
 *  视频封面的本地路径
 */
@property (nullable, nonatomic, copy, readonly) NSString *coverPath;

/**
 *  封面尺寸
 */
@property (nonatomic, assign, readonly) CGSize coverSize;

/**
 *  视频时长，毫秒为单位
 *  @discussion SDK会根据传入文件信息自动解析出duration,但上层也可以自己设置这个值
 */
@property (nonatomic, assign) NSInteger duration;

/**
 *  文件大小
 */
@property (nonatomic, assign, readonly) long long fileLength;



@end

NS_ASSUME_NONNULL_END
