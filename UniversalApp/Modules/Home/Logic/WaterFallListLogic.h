//
//  WaterFallListLogic.h
//  UniversalApp
//
//  Created by 徐阳 on 2017/7/3.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 瀑布流逻辑处理类
 */

@protocol WaterFallListDelegate <NSObject>
@optional
/**
 数据加载完成
 */
-(void)requestDataCompleted;

@end

@interface WaterFallListLogic : NSObject

@property (nonatomic,strong) NSMutableArray * dataArray;//数据源
@property (nonatomic,assign) NSInteger  page;//页码

@property(nonatomic,weak)id<WaterFallListDelegate> delegagte;

/**
 拉取数据
 */
-(void)loadData;

@end
