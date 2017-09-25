//
//  XLJSHandler.h
//  MiAiApp
//
//  Created by 谭启龙 on 2017/9/14.
//  Copyright © 2017年 徐阳. All rights reserved.
//  处理各种js交互

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

@interface XLJSHandler : NSObject<WKScriptMessageHandler>
@property (nonatomic,weak,readonly) UIViewController * webVC;
@property (nonatomic,strong,readonly) WKWebViewConfiguration * configuration;

-(instancetype)initWithViewController:(UIViewController *)webVC configuration:(WKWebViewConfiguration *)configuration;

-(void)cancelHandler;

@end
