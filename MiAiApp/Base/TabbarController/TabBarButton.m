//
//  TabBarButton.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#define TabBarButtonImageRatio 0.6
#import "TabBarButton.h"

@implementation TabBarButton

-(id)initWithFrame:(CGRect)frame{
    self = [super initWithFrame:frame];
    if (self)
    {
        //图片居中
        self.imageView.contentMode = UIViewContentModeCenter;
        //文字居中
        self.titleLabel.textAlignment = NSTextAlignmentCenter;
        //字体居中
        self.titleLabel.font = [UIFont systemFontOfSize:11];
        //文字颜色
        [self setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [self setTitleColor:CNavBgColor forState:UIControlStateSelected];
        
        //添加一个提醒数字按钮
        UIButton *badgeButton = [[UIButton alloc]init];
        [self addSubview:badgeButton];
    }
    return  self;
}


-(void)setHighlighted:(BOOL)highlighted{
    
}
-(CGRect)imageRectForContentRect:(CGRect)contentRect
{
    CGFloat imageW = contentRect.size.width;
    CGFloat imageH = contentRect.size.height * TabBarButtonImageRatio;
    return CGRectMake(0, 0, imageW, imageH);
}

-(CGRect)titleRectForContentRect:(CGRect)contentRect{
    
    CGFloat  titleY = contentRect.size.height * TabBarButtonImageRatio;
    CGFloat titleW = contentRect.size.width;
    CGFloat titleH = contentRect.size.height -titleY ;
    return  CGRectMake(0, titleY, titleW, titleH);
}

-(void)setItem:(UITabBarItem *)item{
    _item = item;
    [self setTitle:item.title forState:UIControlStateNormal];
    [self setImage:item.image forState:UIControlStateNormal];
    [self setImage:item.selectedImage forState:UIControlStateSelected];
}



@end
