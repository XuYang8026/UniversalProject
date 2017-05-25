//
//  HomeViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "HomeViewController.h"
#import "RootWebViewController.h"

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
     :@[@"pre登录",@"push登录"] isLeft:YES target:self action:@selector(naviBtnClick:) tags:@[@1000,@1001]];
    [self addNavigationItemWithTitles:@[@"pre网页",@"push网页"] isLeft:NO target:self action:@selector(naviBtnClick:) tags:@[@1002,@1003]];
    
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
        {
            [kAppDelegate.mainTabBar.selectedViewController.tabBarItem setBadgeValue:@"10"];
            RootNavigationController *loginNavi =[[RootNavigationController alloc] initWithRootViewController:[[RootWebViewController alloc] initWithUrl:@"http://www.hao123.com"]];
            
            //    RootNavigationController *loginNavi =[[RootNavigationController alloc] initWithRootViewController:[LoginViewController new]];
            [kRootViewController presentViewController:loginNavi animated:YES completion:nil];
        }
            break;
        case 1003:{
            RootWebViewController *webView = [[RootWebViewController alloc] initWithUrl:@"http://baidu.com"];
            [self.navigationController pushViewController:webView animated:YES];
        }
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
