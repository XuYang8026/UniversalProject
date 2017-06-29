//
//  NIMAudioObject.h
//  NIMLib
//
//  Created by Netease.
//  Copyright (c) 2015年 Netease. All rights reserved.
//

#import "NIMMessageObjectProtocol.h"
NS_ASSUME_NONNULL_BEGIN

/**
 *  语音实例对象
 */
@interface NIMAudioObject : NSObject<NIMMessageObject>

/**
 *  语音对象初始化方法
 *
 *  @param sourcePath 语音路径
 *
 *  @return 语音实例对象
 */
- (instancetype)initWithSourcePath:(NSString *)sourcePath;

/**
 *  语音对象初始化方法
 *
 *  @param data 语音数据
 *  @param extension 语音数据文件后缀名
 *
 *  @return 语音实例对象
 */
- (instancetype)initWithData:(NSData *)data
                   extension:(NSString *)extension;

/**
 *  语音的本地路径
 */
@property (nullable, nonatomic, copy, readonly) NSString *path;

/**
 *  语音的远程路径
 */
@property (nullable, nonatomic, copy, readonly) NSString *url;

/**
 *  语音时长，毫秒为单位
 *  @discussion SDK会根据传入文件信息自动解析出duration,但上层也可以自己设置这个值
 */
@property (nonatomic, assign)  NSInteger duration;


@end

NS_ASSUME_NONNULL_END
