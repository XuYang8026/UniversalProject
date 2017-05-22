//
//  AppManager.h
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/21.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 应用层的网络请求
 */
@interface AppManager : NSObject

#pragma mark - ——————— APP启动接口 ————————
+(void)appStart:(HttpRequestCallBack)callBack;

#pragma mark - 实时监测网络状态
+ (void)monitorNetworkStatus;

@end
