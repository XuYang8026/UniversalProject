//
//  AppDelegate+AppService.h
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/19.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "AppDelegate.h"

#define ReplaceRootViewController(vc) [[AppDelegate shareAppDelegate] replaceRootViewController:vc]

/**
 包含第三方 和 应用内业务的实现，减轻入口代码压力
 */
@interface AppDelegate (AppService)

//初始化window
-(void)initWindow;
//UMeng初始化
-(void)initUMeng;

//初始化用户系统
-(void)initUserManager;

//替换当前根视图
- (void)replaceRootViewController:(UIViewController*)rootViewController;

+ (AppDelegate *)shareAppDelegate;

/**
 当前顶层控制器
 */
-(UIViewController*) getCurrentVC;

-(UIViewController*) getCurrentUIVC;
@end
