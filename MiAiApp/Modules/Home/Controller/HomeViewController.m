//
//  HomeViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "HomeViewController.h"

@interface HomeViewController ()

@end

@implementation HomeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.isShowLiftBack = NO;
    
    UILabel * lbl = [UILabel new];
    lbl.font = SYSTEMFONT(30);
    lbl.text = @"首页控制器";
    lbl.textAlignment = NSTextAlignmentCenter;
    lbl.textColor = KBlackColor;
    lbl.frame = self.view.bounds;
    [self.view addSubview:lbl];
    
    [self addNavigationItemWithTitles
     :@[@"present",@"push"] isLeft:YES target:self action:@selector(naviBtnClick:) tags:@[@1000,@1001]];
    [self addNavigationItemWithTitles:@[@"小Loading",@"大Loading"] isLeft:NO target:self action:@selector(naviBtnClick:) tags:@[@1003,@1002]];
    
}

-(void)naviBtnClick:(UIButton *)btn{
    switch (btn.tag) {
        case 1000:
            [self goLogin];
            break;
        case 1001:
        {
            [self goLoginWithPush];
        }
            break;
        case 1002:
            [MBProgressHUD showActivityMessageInView:nil];
            break;
        case 1003:
            [MBProgressHUD hideHUD];
//            [MBProgressHUD showActivityMessageInWindow:@"网络请求失败网络请求失败网络请求失败" timer:3];
            break;
        default:
            break;
    }
    
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



@end
