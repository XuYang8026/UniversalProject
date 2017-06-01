//
//  MsgViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "MsgViewController.h"

@interface MsgViewController ()

@end

@implementation MsgViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UIButton *_btn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    _btn.frame = CGRectMake(40, 100,150, 50);
    _btn.center = self.view.center;
    [_btn setBackgroundColor:[UIColor redColor]];
    [_btn setTitle:@"测试AlertView" forState:UIControlStateNormal];
    [_btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    _btn.showsTouchWhenHighlighted = YES;
    _btn.tag = 3000;
    [_btn addTarget:self action:@selector(btnClick:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_btn];
    
    UIButton *_btn2 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    
    _btn2.frame = CGRectMake(40, 100,150, 50);
    _btn2.center = self.view.center;
    _btn2.top = _btn.bottom + 20;
    [_btn2 setBackgroundColor:[UIColor redColor]];
    [_btn2 setTitle:@"测试ActionSheet" forState:UIControlStateNormal];
    [_btn2 setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    _btn2.showsTouchWhenHighlighted = YES;
    _btn2.tag = 3001;

    [_btn2 addTarget:self action:@selector(btnClick:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:_btn2];
}
-(void)btnClick:(UIButton *)btn{
    if (btn.tag == 3000) {
        [self AlertWithTitle:@"测试标题" message:@"测试内容" andOthers:@[@"取消",@"确定"] animated:YES action:^(NSInteger index) {
            DLog(@"点击了 %ld",index);
        }];
    }else{
        [self ActionSheetWithTitle:@"测试" message:@"测试内容" destructive:nil destructiveAction:nil andOthers:@[@"1",@"2",@"3",@"4"] animated:YES action:^(NSInteger index) {
            DLog(@"点了 %ld",index);
        }];
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
