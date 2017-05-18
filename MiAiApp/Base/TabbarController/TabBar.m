//
//  TabBar.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "TabBar.h"

@implementation TabBar

-(void)addTabBarButtonWithItem:(UITabBarItem *)item{
    //1.创建按钮
    TabBarButton *button = [[TabBarButton alloc]init];
    [self addSubview:button];
    /*
     [button setTitle:itme.title forState:UIControlStateNormal];
     [button setImage:itme.image forState:UIControlStateNormal];
     [button setImage:itme.selectedImage forState:UIControlStateSelected];
     [button setBackgroundImage:[UIImage imageWithName:@"tabbar_slider"] forState:UIControlStateSelected];
     */
    //设置数据把buttonitem模型传给button
    button.item = item;
    
    //监听点击button
    [button addTarget:self  action:@selector(buttonClick:) forControlEvents:UIControlEventTouchDown];
    
    //默认选中
    if (self.subviews.count == 1) {
        [self buttonClick:button];
    }
    
    
}

/**
 * button监听事件
 *
 */
-(void)buttonClick:(TabBarButton*)button{
    
    if ([self.delegate respondsToSelector:@selector(tabBar:didselectedButtonFrom:to:)]
        )
    {
        [self.delegate tabBar:self didselectedButtonFrom:(int)self.selectedButton.tag to:(int)button.tag];
    }
    self.selectedButton.selected = NO;
    button.selected = YES;
    self.selectedButton = button;
    
}

-(void)layoutSubviews{
    [super layoutSubviews];
    
    CGFloat buttonW = self.frame.size.width/ self.subviews.count ;
    CGFloat buttonH = self.frame.size.height;
    CGFloat buttonY = 0 ;
    
    for ( int index = 0; index < self.subviews.count; index++) {
        //1.取出按钮
        TabBarButton *button = self.subviews[index];
        
        //2. 设置按钮的frame
        
        CGFloat buttonX = index * buttonW;
        
        button.frame = CGRectMake(buttonX, buttonY, buttonW, buttonH) ;
        
        //绑定tag;
        button.tag = index;
    }
}


@end
