//
//  NativeCallJSVC.m
//  UniversalApp
//
//  Created by 徐阳 on 2017/10/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "NativeCallJSVC.h"

@interface NativeCallJSVC ()

@end

@implementation NativeCallJSVC

- (void)viewDidLoad {
    [super viewDidLoad];
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    [btn setTitle:@"调用JS函数" forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [btn setBackgroundColor:[UIColor redColor]];
    btn.frame = CGRectMake(0, 0, 100, 100);
    btn.center =self.view.center;
    ViewRadius(btn, 50);
    [btn addTarget:self action:@selector(callJS) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn];
}
-(void)callJS{
    [self.webView evaluateJavaScript:@"testCallJs()" completionHandler:^(id _Nullable obj, NSError * _Nullable error) {
        if (error) {
            [MBProgressHUD showErrorMessage:@"调用失败"];
        }else if([obj isKindOfClass:[NSString class]]){
            [self AlertWithTitle:nil message:obj andOthers:@[@"ok"] animated:YES action:^(NSInteger index) {
                
            }];
        }else{
            [self AlertWithTitle:nil message:@"成功" andOthers:@[@"ok"] animated:YES action:^(NSInteger index) {
                
            }];
        }
        
    }];
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
