//
//  BaseRequestAPI.h
//  MiAiApp
//
//  Created by 徐阳 on 2017/6/28.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import <YTKNetwork/YTKNetwork.h>
/**
 接口请求基类，所有请求必须继承此类
 这里采用的是YTKNetwork网络库，中大型APP专用，可满足所有网络需求
 学习地址：https://github.com/yuantiku/YTKNetwork
 */
@interface BaseRequestAPI : YTKBaseRequest

@property(nonatomic,assign)BOOL isOpenAES;//是否开启加密 默认开启


//自定义属性值
@property(nonatomic,assign)BOOL isSuccess;//是否成功
@property (nonatomic,copy) NSString * message;//服务器返回的信息
@property (nonatomic,copy) NSDictionary * result;//服务器返回的数据 已解密

@end
