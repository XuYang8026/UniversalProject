//
//  XYTransitionNavigationDelegate.h
//  UniversalApp
//
//  Created by 徐阳 on 2017/6/30.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "XYTransition.h"

@interface XYTransitionNavigationDelegate : NSObject<UINavigationControllerDelegate>

/**
 *  初始化新的Navigation的代理
 *
 *  @param navigation 改变navigation的代理为当前类
 *
 *  @return NavigationControllerDelegate
 */
-(instancetype)initWithNavigationController:(UINavigationController*)navigation;

@end
