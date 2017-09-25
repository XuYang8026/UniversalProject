//
//  RootWebViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "RootWebViewController.h"
#import <YYKit.h>

@interface RootWebViewController ()<WKNavigationDelegate>

@property (nonatomic,assign) double lastProgress;//上次进度条位置
@end

@implementation RootWebViewController


- (void)viewDidLoad {
    [super viewDidLoad];
}

-(void)updateNavigationItems{
    if (_isShowCloseBtn) {
        if (self.webView.canGoBack) {
            self.navigationController.interactivePopGestureRecognizer.enabled = NO;
            [self addNavigationItemWithImageNames:@[@"back_icon",@"close_icon"] isLeft:YES target:self action:@selector(leftBtnClick:) tags:@[@2000,@2001]];
            
        }else{
            self.navigationController.interactivePopGestureRecognizer.enabled = YES;
            
            //iOS8系统下发现的问题：在导航栏侧滑过程中，执行添加导航栏按钮操作，会出现按钮重复，导致导航栏一系列错乱问题
            //解决方案待尝试：每个vc显示时，遍历 self.navigationController.navigationBar.subviews 根据tag去重
            //现在先把iOS 9以下的不使用动态添加按钮 其实微信也是这样做的，即便返回到webview的第一页也保留了关闭按钮
            
            if (kiOS9Later) {
                //            [self addNavigationItemWithTitles:@[@"返回"] isLeft:YES target:self action:@selector(leftBtnClick:) tags:@[@2001]];
                [self addNavigationItemWithImageNames:@[@"back_icon"] isLeft:YES target:self action:@selector(leftBtnClick:) tags:@[@2001]];
            }
        }
    }
}

-(void)leftBtnClick:(UIButton *)btn{
    switch (btn.tag) {
        case 2000:
            [super backBtnClicked];
            
            break;
        case 2001:
        {
            if (self.presentingViewController) {
                [self dismissViewControllerAnimated:YES completion:nil];
            }else{
                [self.navigationController popViewControllerAnimated:YES];
            }
        }
            
            break;
        default:
            break;
    }
}

-(void)dealloc{
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end

