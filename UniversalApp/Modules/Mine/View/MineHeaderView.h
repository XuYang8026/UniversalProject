//
//  MineHeaderView.h
//  MiAiApp
//
//  Created by 徐阳 on 2017/6/13.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 我的页面 头部 view
 */
@protocol headerViewDelegate <NSObject>

-(void)headerViewClick;
-(void)nickNameViewClick;

@end

@interface MineHeaderView : UIView

@property(nonatomic, strong) YYAnimatedImageView *headImgView; //头像
@property(nonatomic, strong) UserInfo *userInfo;//用户信息
@property(nonatomic, assign) id<headerViewDelegate> delegate;

@end
