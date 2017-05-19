//
//  LoginViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "LoginViewController.h"

@interface LoginViewController ()

@end

@implementation LoginViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UILabel * lbl = [UILabel new];
    lbl.font = SYSTEMFONT(30);
    lbl.text = @"登录页";
    lbl.textAlignment = NSTextAlignmentCenter;
    lbl.textColor = KBlackColor;
    lbl.frame = self.view.bounds;
    [self.view addSubview:lbl];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
