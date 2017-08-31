//
//  RootWebViewController.h
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "RootViewController.h"
#import <WebKit/WebKit.h>
/**
 WebView 基类
 */
@interface RootWebViewController : RootViewController

/**
 webView
 */
@property(nonatomic, strong) WKWebView *wkwebView;

/**
 JS 注册
 */
@property(nonatomic,strong) WKUserContentController * userContentController;
/**
 *  origin url
 */
@property (nonatomic)NSString* url;

/**
 *  embed webView
 */
//@property (nonatomic)UIWebView* webView;

/**
 *  tint color of progress view
 */
@property (nonatomic)UIColor* progressViewColor;

/**
 *  get instance with url
 *
 *  @param url url
 *
 *  @return instance
 */
-(instancetype)initWithUrl:(NSString *)url;


-(void)reloadWebView;


@end
