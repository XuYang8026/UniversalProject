//
//  ShopWaterLayout.h
//  集合视图之瀑布流
//
//  Created by ma c on 15/11/21.
//  Copyright (c) 2015年 夏远全. All rights reserved.
//

#import <UIKit/UIKit.h>

/*
为了体现封装性的特点,我们可以把一些数据设置为公共的，既可以提高扩展性和通用性，
也便于外界按照自己的需求做必要的调整。
*/

@protocol WaterFlowLayoutDelegate;


@class WaterFlowLayout;
@interface WaterFlowLayout : UICollectionViewLayout
@property (assign,nonatomic)CGFloat columnMargin;//每一列item之间的间距
@property (assign,nonatomic)CGFloat rowMargin;   //每一行item之间的间距
@property (assign,nonatomic)UIEdgeInsets sectionInset;//设置于collectionView边缘的间距
@property (assign,nonatomic)NSInteger columnCount;//设置每一行排列的个数


@property (weak,nonatomic)id<WaterFlowLayoutDelegate> delegate; //设置代理
@end


@protocol WaterFlowLayoutDelegate
-(CGFloat)waterFlowLayout:(WaterFlowLayout *) WaterFlowLayout heightForWidth:(CGFloat)width andIndexPath:(NSIndexPath *)indexPath;
@end
