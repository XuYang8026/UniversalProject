//
//  WaterFallListLogic.m
//  UniversalApp
//
//  Created by 徐阳 on 2017/7/3.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "WaterFallListLogic.h"
#import "GetWaterFallListAPI.h"

@interface WaterFallListLogic()

@end

@implementation WaterFallListLogic

-(instancetype)init{
    self = [super init];
    if (self) {
        _dataArray = @[].mutableCopy;
    }
    return self;
}

#pragma mark ————— 拉取数据 —————
-(void)loadData{
    //发起请求
    GetWaterFallListAPI *req = [GetWaterFallListAPI new];
    [req startWithCompletionBlockWithSuccess:^(__kindof YTKBaseRequest * _Nonnull request) {
        NSLog(@"请求成功");
    } failure:^(__kindof YTKBaseRequest * _Nonnull request) {
        NSLog(@"请求失败 %@",req.message);
        //模拟成功
        for (int i = 0; i < 14; i++) {
            
            NSString *imageName = NSStringFormat(@"%d.jpg", i);
            
            [_dataArray addObject:imageName];
        }
        if (self.delegagte && [self.delegagte respondsToSelector:@selector(requestDataCompleted)]) {
            [self.delegagte requestDataCompleted];
        }
    }];
}


@end
