//
//  NIMDocTranscodingInfo.h
//  NIMLib
//
//  Created by Netease on 16/12/9.
//  Copyright © 2016年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  转码源文件格式
 */
typedef NS_ENUM(NSInteger, NIMDocTranscodingFileType){
    /**
     *  ppt
     */
    NIMDocTranscodingFileTypePPT   = 1,
    /**
     *  pptx
     */
    NIMDocTranscodingFileTypePPTX  = 2,
    /**
     *  pdf
     */
    NIMDocTranscodingFileTypePDF   = 3,
};

/**
 *  转码目标图像文件类型
 */
typedef NS_ENUM(NSInteger, NIMDocTranscodingImageType){
    /**
     *  未知图像文件类型
     */
    NIMDocTranscodingImageTypeUnknown  = 0,
    /**
     *  转码为 jpg 图片
     */
    NIMDocTranscodingImageTypeJPG      = 10,
    /**
     *  转码为 png 图片
     */
    NIMDocTranscodingImageTypePNG      = 11,
};

/**
 *  转码图像清晰度
 */
typedef NS_ENUM(NSInteger, NIMDocTranscodingQuality){
    /**
     *  高清转码质量
     */
    NIMDocTranscodingQualityHigh    = 1,
    /**
     *  中等转码质量
     */
    NIMDocTranscodingQualityMedium  = 2,
    /**
     *  低清转码质量
     */
    NIMDocTranscodingQualityLow     = 3,
};


/**
 *  转码过程状态
 */
typedef NS_ENUM(NSInteger, NIMDocTranscodingState){
    /**
     *  未知转码状态
     */
    NIMDocTranscodingStateUnknown     = 0,
    /**
     *  转码准备中
     */
    NIMDocTranscodingStatePreparing   = 1,
    /**
     *  转码进行中
     */
    NIMDocTranscodingStateOngoing     = 2,
    /**
     *  转码超时
     */
    NIMDocTranscodingStateTimeout     = 3,
    /**
     *  转码完成
     */
    NIMDocTranscodingStateCompleted   = 4,
    /**
     *  转码失败
     */
    NIMDocTranscodingStateFailed      = 5,
};


/**
 转码文档信息
 */
@interface NIMDocTranscodingInfo : NSObject

/**
 转码文档标识 id
 */
@property (nonatomic,copy,readonly)   NSString *docId;

/**
 转码文档名称
 */
@property (nonatomic,copy,readonly)   NSString *docName;

/**
 转码源文档的文件类型
 */
@property (nonatomic,assign,readonly) NIMDocTranscodingFileType sourceType;

/**
 转码源文档大小
 */
@property (nonatomic,assign,readonly) UInt64 sourceSize;

/**
 转码目标图片的文件类型
 */
@property (nonatomic,assign,readonly) NIMDocTranscodingImageType targetType;

/**
 转码过程状态
 */
@property (nonatomic,assign,readonly) NIMDocTranscodingState state;

/**
 转码源文档文件的下载地址
 */
@property (nonatomic,copy,readonly)   NSString *sourceFileUrl;

/**
 转码文档总页数
 */
@property (nonatomic,assign,readonly) NSUInteger numberOfPages;

/**
 发起文档转码时的附带信息
 */
@property (nullable,nonatomic,copy,readonly)   NSString *ext;

/**
 文档转码内部状态码, 0 表示成功, 可用于在转码失败时定位具体失败原因。已知的一些失败原因 2: 找不到文件; 3: 文件类型错误; 4: 转码请求出现异常; 5: 转码服务器连接错误 6: 转码服务器内部错误; 7: 文档转码图片出错; 8: 图片质量处理错误; 9: 页数超限; 10: nos回调错误; 11: 文档解析错误（如加密的PDF无法解析; 100: 未知错误
 */
@property (nonatomic,assign,readonly) NSInteger transcodingFlag;

/**
 获取某清晰度的转码后文件总字节大小

 @param quality 转码质量
 @return 转码后该质量的图片文件总字节大小
 */
- (UInt64)transcodedTotalSize:(NIMDocTranscodingQuality)quality;

/**
 获取某清晰度转码后图片的长宽信息
 
 @param quality 转码质量
 @return 转码后图片的长宽信息
 */
- (CGSize)transcodedImagesSize:(NIMDocTranscodingQuality)quality;

/**
 获取转码后某清晰度的文件页码对应的下载 url

 @param pageNumber 文件页码
 @param quality 图片质量
 @return 图片下载 url
 */
- (nullable NSString *)transcodedUrl:(NSUInteger)pageNumber
                           ofQuality:(NIMDocTranscodingQuality)quality;

@end

NS_ASSUME_NONNULL_END
