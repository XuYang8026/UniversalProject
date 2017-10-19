//
//  HomeViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "HomeViewController.h"
#import "RootWebViewController.h"
#import "EmitterViewController.h"
#import "LoginViewController.h"

@interface HomeViewController ()

@end

@implementation HomeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"粒子";
    
//    self.isShowLiftBack = NO;

    [self addNavigationItemWithTitles
     :@[@"pre登录"] isLeft:NO target:self action:@selector(naviBtnClick:) tags:@[@1000]];
    [self addNavigationItemWithTitles:@[@"pre网页"] isLeft:NO target:self action:@selector(naviBtnClick:) tags:@[@1002,@1003]];
    
    [self addrainBtn:1 top:200];
    [self addrainBtn:2 top:300];
    [self addrainBtn:3 top:400];

}

-(void)naviBtnClick:(UIButton *)btn{
    switch (btn.tag) {
        case 1000:{
            RootNavigationController *loginNavi =[[RootNavigationController alloc] initWithRootViewController:[LoginViewController new]];
            [self presentViewController:loginNavi animated:YES completion:nil];
        }
            break;
        case 1002:
        {
            [kAppDelegate.mainTabBar setRedDotWithIndex:3 isShow:YES];
            RootNavigationController *loginNavi =[[RootNavigationController alloc] initWithRootViewController:[[RootWebViewController alloc] initWithUrl:@"http://www.hao123.com"]];
            
            //    RootNavigationController *loginNavi =[[RootNavigationController alloc] initWithRootViewController:[LoginViewController new]];
            [kRootViewController presentViewController:loginNavi animated:YES completion:nil];
        }
            break;
        default:
            break;
    }
    
}
#pragma mark ————— 下雨 —————
-(void)addrainBtn:(NSInteger) type top:(float)top{
    NSMutableAttributedString *text = [NSMutableAttributedString new];
    NSString *str;
    {
        switch (type) {
            case 1://下雪
                str = @"下雪";
                break;
            case 2://下雨
                str = @"下雨";
                break;
            case 3://烟花
                str = @"烟花";
                break;
                
            default:
                break;
        }

        NSMutableAttributedString *one = [[NSMutableAttributedString alloc] initWithString:str];
        one.font = [UIFont boldSystemFontOfSize:30];
        one.color = [UIColor whiteColor];
        
        YYTextShadow *shadow = [YYTextShadow new];
        shadow.color = [UIColor colorWithWhite:0.000 alpha:0.490];
        shadow.offset = CGSizeMake(0, 1);
        shadow.radius = 5;
        one.textShadow = shadow;
        
        YYTextShadow *shadow0 = [YYTextShadow new];
        shadow0.color = [UIColor colorWithWhite:0.000 alpha:0.20];
        shadow0.offset = CGSizeMake(0, -1);
        shadow0.radius = 1.5;
        YYTextShadow *shadow1 = [YYTextShadow new];
        shadow1.color = [UIColor colorWithWhite:1 alpha:0.99];
        shadow1.offset = CGSizeMake(0, 1);
        shadow1.radius = 1.5;
        shadow0.subShadow = shadow1;
        
        YYTextShadow *innerShadow0 = [YYTextShadow new];
        innerShadow0.color = [UIColor colorWithRed:0.851 green:0.311 blue:0.000 alpha:0.780];
        innerShadow0.offset = CGSizeMake(0, 1);
        innerShadow0.radius = 1;
        
        YYTextHighlight *highlight = [YYTextHighlight new];
        [highlight setColor:[UIColor colorWithRed:1.000 green:0.795 blue:0.014 alpha:1.000]];
        [highlight setShadow:shadow0];
        [highlight setInnerShadow:innerShadow0];
        [one setTextHighlight:highlight range:one.rangeOfAll];
        
        [text appendAttributedString:one];
    }
    
    YYLabel *snowBtn = [[YYLabel alloc] initWithFrame:CGRectMake(0, top, 200, 30)];
    snowBtn.attributedText = text;
    snowBtn.textAlignment = NSTextAlignmentCenter;
    snowBtn.textVerticalAlignment = YYTextVerticalAlignmentCenter;
    snowBtn.centerX = KScreenWidth/2;
    
    
    kWeakSelf(self);
    snowBtn.textTapAction = ^(UIView * _Nonnull containerView, NSAttributedString * _Nonnull text, NSRange range, CGRect rect) {
//        [MBProgressHUD showTopTipMessage:NSStringFormat(@"%@马上开始",str) isWindow:YES];
        
        EmitterViewController *emitterVC = [[EmitterViewController alloc] init];
        emitterVC.animation_type = type;
        [weakself.navigationController pushViewController:emitterVC animated:YES];
    };
    
    [self.view addSubview:snowBtn];

}

#pragma mark -  屏幕旋转
//在需要旋转的页面重写以下三个方法 默认不可旋转

-(UIInterfaceOrientationMask)supportedInterfaceOrientations
{
    //当前支持的旋转类型
    return UIInterfaceOrientationMaskAllButUpsideDown;
}

- (BOOL)shouldAutorotate
{
    // 是否支持旋转
    return YES;
}

-(UIInterfaceOrientation)preferredInterfaceOrientationForPresentation
{
    // 默认进去类型
    return   UIInterfaceOrientationPortrait;
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



@end
