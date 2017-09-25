//
//  XLJSHandler.m
//  MiAiApp
//
//  Created by 谭启龙 on 2017/9/14.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "XLJSHandler.h"


@interface XLJSHandler ()


@end

@implementation XLJSHandler

-(instancetype)initWithViewController:(UIViewController *)webVC configuration:(WKWebViewConfiguration *)configuration {
    self = [super init];
    if (self) {
        _webVC = webVC;
        _configuration = configuration;
        //js handler
        //注册JS 事件
//        [configuration.userContentController addScriptMessageHandler:self name:@"showImages"];
//        [configuration.userContentController addScriptMessageHandler:self name:@"backPage"];
//        [configuration.userContentController addScriptMessageHandler:self name:@"showVideo"];
//        [configuration.userContentController addScriptMessageHandler:self name:@"issueMoment"];
//        [configuration.userContentController addScriptMessageHandler:self name:@"JSShare"];
        
    }
    return self;
}

#pragma mark -  JS 调用 Native  代理
- (void)userContentController:(WKUserContentController *)userContentController didReceiveScriptMessage:(WKScriptMessage *)message{
    if ([message.name isEqualToString:@"showImages"]) {
        //根据key取JS事件传递的值
        
    }else if ([message.name isEqualToString:@"JSShare"]) {
        //分享
        NSDictionary * dic = message.body;
        NSString *shareTitle = dic[@"shareTitleWebkit"];
        NSString *shareInfoWebkit = dic[@"shareInfoWebkit"];
        NSString *shareUrlWebkit = dic[@"shareUrlWebkit"];
        
//        [[ShareManager sharedShareManager] showShareViewWithTitle:shareTitle shareContent:shareInfoWebkit shareUrl:shareUrlWebkit];
    }
}

#pragma mark -  记得要移除
-(void)cancelHandler {
//    [_configuration.userContentController removeScriptMessageHandlerForName:@"showImages"];
//    [_configuration.userContentController removeScriptMessageHandlerForName:@"backPage"];
//    [_configuration.userContentController removeScriptMessageHandlerForName:@"showVideo"];
//    [_configuration.userContentController removeScriptMessageHandlerForName:@"issueMoment"];
//    [_configuration.userContentController removeScriptMessageHandlerForName:@"JSShare"];
}

-(void)dealloc {
    
}

@end
