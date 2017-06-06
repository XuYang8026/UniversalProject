//
//  MineViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "MineViewController.h"

@interface MineViewController ()
{
    UILabel * lbl;
}
@end

@implementation MineViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    lbl = [UILabel new];
    lbl.font = SYSTEMFONT(30);
    lbl.text = @"用户昵称";
    lbl.textAlignment = NSTextAlignmentCenter;
    lbl.textColor = KBlackColor;
    lbl.frame = self.view.bounds;
    [self.view addSubview:lbl];
    
    kWeakSelf(self)
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc]initWithActionBlock:^(id  _Nonnull sender) {
        [userManager logout:nil];
        //        weakself.StatusBarStyle = weakself.StatusBarStyle == 1 ? UIStatusBarStyleDefault : UIStatusBarStyleLightContent;
    }];
    [self.view addGestureRecognizer:tap];


}
-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    if (userManager.isLogined) {
        lbl.text = curUser.nickname;
    }else{
        lbl.text = @"未登录";
    }
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
