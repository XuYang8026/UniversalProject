//
//  MakeFriendsViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "MakeFriendsViewController.h"

@interface MakeFriendsViewController ()

@end

@implementation MakeFriendsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.isShowLiftBack = NO;
    
    UILabel * lbl = [UILabel new];
    lbl.font = SYSTEMFONT(30);
    lbl.text = @"社交页控制器";
    lbl.textAlignment = NSTextAlignmentCenter;
    lbl.textColor = KBlackColor;
    lbl.frame = self.view.bounds;
    [self.view addSubview:lbl];
    
    [self addNavigationItemWithTitles:@[@"登录"] isLeft:NO target:self action:@selector(naviBtnClick:) tags:@[@1000]];
}
-(void)naviBtnClick:(UIButton *)btn{
    [MBProgressHUD showTopTipMessage:STRING_BUILDER(@"点击了%@按钮", btn.titleLabel.text)];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
