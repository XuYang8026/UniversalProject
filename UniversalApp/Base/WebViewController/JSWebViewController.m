//
//  JSWebViewController.m
//  UniversalApp
//
//  Created by 徐阳 on 2017/8/31.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "JSWebViewController.h"
#import <WebKit/WebKit.h>

@interface JSWebViewController ()<WKScriptMessageHandler>

@end

@implementation JSWebViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    YYLabel *skipBtn = [[YYLabel alloc] initWithFrame:CGRectMake(0, 400, 150, 60)];
    skipBtn.text = @"调用JS";
    skipBtn.font = SYSTEMFONT(20);
    skipBtn.textColor = KBlueColor;
    skipBtn.backgroundColor = KClearColor;
    skipBtn.textAlignment = NSTextAlignmentCenter;
    skipBtn.textVerticalAlignment = YYTextVerticalAlignmentCenter;
    skipBtn.centerX = KScreenWidth/2;
    
    kWeakSelf(self);
    skipBtn.textTapAction = ^(UIView * _Nonnull containerView, NSAttributedString * _Nonnull text, NSRange range, CGRect rect) {
        [weakself callJS];
    };
    
    [self.view addSubview:skipBtn];
}
#pragma mark -  注册JS函数
-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    
    [self.userContentController addScriptMessageHandler:self name:@"showMobile"];
    [self.userContentController addScriptMessageHandler:self name:@"showName"];
    [self.userContentController addScriptMessageHandler:self name:@"showSendMsg"];
}
#pragma mark -  移除注册的JS函数
-(void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
    [self.userContentController removeScriptMessageHandlerForName:@"showMobile"];
    [self.userContentController removeScriptMessageHandlerForName:@"showName"];
    [self.userContentController removeScriptMessageHandlerForName:@"showSendMsg"];
}
#pragma mark -  调用JS
-(void)callJS{
    NSString *jsStr = @"showAlert('666')";
    [self.wkwebView evaluateJavaScript:jsStr completionHandler:^(id _Nullable result, NSError * _Nullable error) {
        NSLog(@"%@----%@",result, error);
    }];

}

#pragma mark -  JS 调用 Native  代理
- (void)userContentController:(WKUserContentController *)userContentController didReceiveScriptMessage:(WKScriptMessage *)message{
    NSLog(@"%@",message.body);

    if ([message.name isEqualToString:@"showMobile"]) {
        [self AlertWithTitle:@"showMobile弹窗" message:nil andOthers:@[@"好"] animated:YES action:nil];
    }

    if ([message.name isEqualToString:@"showName"]) {
        NSString *info = [NSString stringWithFormat:@"你好 %@, 很高兴见到你",message.body];
        [self AlertWithTitle:info message:nil andOthers:@[@"好"] animated:YES action:nil];
    }

    if ([message.name isEqualToString:@"showSendMsg"]) {
        NSArray *array = message.body;
        NSString *info = [NSString stringWithFormat:@"这是我的手机号: %@, %@ !!",array.firstObject,array.lastObject];
        [self AlertWithTitle:info message:nil andOthers:@[@"好"] animated:YES action:nil];
    }
}

-(void)dealloc{
    NSLog(@"销毁");
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
