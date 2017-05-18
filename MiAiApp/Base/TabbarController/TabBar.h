//
//  TabBar.h
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TabBarButton.h"

@class TabBar;

//给每个按钮定义协议 与 方法
@protocol tabbarDelegate <NSObject>

@optional
-(void)tabBar:(TabBar * )tabBar didselectedButtonFrom:(int)from to:(int)to;

@end

@interface TabBar : UIView
@property (weak ,nonatomic)TabBarButton *selectedButton;
/**
 *  给自定义的tabbar添加按钮
 */
-(void)addTabBarButtonWithItem:(UITabBarItem *)itme;
@property(nonatomic , weak) id <tabbarDelegate> delegate;


@end
