//
//  BaseRequestAPI.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/6/28.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "BaseRequestAPI.h"
#import "HeaderModel.h"
#import "AESCipher.h"

@implementation BaseRequestAPI

-(instancetype)init{
    self = [super init];
    if (self) {
        self.isOpenAES = YES;
    }
    return self;
}

#pragma mark ————— 自定义数据 —————

- (NSString *)message {
    if (self.error) {
        return self.error.localizedDescription;
    }
    NSString *message = [NSString stringWithFormat:@"%@",self.result[@"codemsg"]];
    return message;
}
- (NSString *)code {
    NSString *code = [NSString stringWithFormat:@"%@",self.result[@"code"]];
    return code;
}
- (BOOL)isSuccess {
    
    NSString *code = [self code];
    
    BOOL isSuccess = NO;
    
    if ([code isEqualToString:@"0"]) {
        isSuccess = YES;
    } else if ([code isEqualToString:@"1023"]) {
        //账号被顶掉
        [[kAppDelegate getCurrentUIVC] AlertWithTitle:nil message:self.message andOthers:@[@"确定"] animated:YES action:nil];
        KPostNotification(KNotificationOnKick, nil);
    }else if([code isEqualToString:@"1039"]){
        //token过期
        [[kAppDelegate getCurrentUIVC] AlertWithTitle:nil message:self.message andOthers:@[@"确定"] animated:YES action:nil];
        KPostNotification(KNotificationOnKick, nil);
    }
    
    return  isSuccess;
    
}

#pragma mark ————— 定义返回数据格式，若是加密要用HTTP接受 —————
-(YTKResponseSerializerType)responseSerializerType {
    if (self.isOpenAES) {
        return YTKResponseSerializerTypeHTTP;
    }
    return YTKResponseSerializerTypeJSON;
}
#pragma mark ————— 默认请求方式 POST —————
-(YTKRequestMethod)requestMethod{
    return YTKRequestMethodPOST;
}
//#pragma mark ————— 默认请求体是自身转json —————
//-(id)requestArgument{
//    return [self modelToJSONObject];
//}
#pragma mark ————— 请求失败过滤器 —————
-(void)requestFailedFilter{
    //失败处理器
}
#pragma mark ————— 请求成功过滤器 —————
-(void)requestCompleteFilter{
    //解密
    if (self.isOpenAES) {
        self.result = aesDecryptWithData(self.responseData);
    }else{
        self.result = self.responseJSONObject;
    }
//    NSLog(@"请求处理器%@",self.result);
}

#pragma mark ————— 非加密时也要传输的头部内容 也可能不需要，暂时保留 —————
-(NSDictionary<NSString *,NSString *> *)requestHeaderFieldValueDictionary{
    //加密header部分
    NSString *contentStr = [[HeaderModel new] modelToJSONString];
    NSString *AESStr = aesEncrypt(contentStr);
    return @{@"header-encrypt-code":AESStr};
    
}

#pragma mark ————— 如果是加密方式传输，自定义request —————
-(NSURLRequest *)buildCustomUrlRequest{
    
    if (!_isOpenAES) {
        return nil;
    }
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:[NSString stringWithFormat:@"%@%@",URL_main,self.requestUrl]]];
    
    //加密header部分
    NSString *headerContentStr = [[HeaderModel new] modelToJSONString];
    NSString *headerAESStr = aesEncrypt(headerContentStr);
    [request setValue:headerAESStr forHTTPHeaderField:@"header-encrypt-code"];
    
    NSString *contentStr = [self.requestArgument jsonStringEncoded];
    NSString *AESStr = aesEncrypt(contentStr);
    
    [request setHTTPMethod:@"POST"];
    
    [request setValue:@"text/encode" forHTTPHeaderField:@"Content-Type"];
    
    
    NSData *bodyData = [AESStr dataUsingEncoding:NSUTF8StringEncoding];
    
    [request setHTTPBody:bodyData];
    return request;
    
}
@end
