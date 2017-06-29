//
//  NIMNetCallAudioFileMixTask.h
//  NIM
//
//  Created by Netease on 16/12/5.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 语音文件混音任务
 */
@interface NIMNetCallAudioFileMixTask : NSObject

/**
 初始化任务

 @param url 语音文件 URL。只能播放系统原生支持语音播放的音频文件类型，如 aac、mp3、mp4 和 wav 等
 @return 任务实例
 */
- (instancetype)initWithFileURL:(NSURL *)url;

/**
 语音文件 URL
 */
@property (nonatomic, readonly) NSURL *fileURL;

/**
 循环播放次数，负数表示无限循环，非负数表示总共播放 numberOfLoops + 1 次，可以实时更新，更新后重新计数
 */
@property (nonatomic, assign) NSInteger numberOfLoops;

/**
 发送的语音音量, 接受输入值为 0.0 到 1.0，可以实时更新
 */
@property (nonatomic, assign) float sendVolume;

/**
 播放的语音音量, 接受输入值为 0.0 到 1.0，可以实时更新
 */
@property (nonatomic, assign) float playbackVolume;

@end

NS_ASSUME_NONNULL_END

