//
//  MakeFriendsLogic.m
//  UniversalApp
//
//  Created by 徐阳 on 2017/7/11.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "MakeFriendsLogic.h"
#import "CellModel.h"

@interface MakeFriendsLogic()
@property (nonatomic,copy) NSArray * contentArray;
@end

@implementation MakeFriendsLogic

-(instancetype)init{
    self = [super init];
    if (self) {
        _dataArray = @[].mutableCopy;
        _contentArray = @[@"测试",@"测试",@"测试",@"测试",@"测试",@"测试",@"测试"];
    }
    return self;
}

#pragma mark ————— 拉取数据 —————
-(void)loadData{
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        //模拟成功
        for (int i = 0; i < 50; i++) {
            
            CellModel *model = [CellModel new];
            model.textString = _contentArray[arc4random()%_contentArray.count];
            
            [_dataArray addObject:model];
        }
        if (self.delegagte && [self.delegagte respondsToSelector:@selector(requestDataCompleted)]) {
            [self.delegagte requestDataCompleted];
        }
        
    });
}


@end
