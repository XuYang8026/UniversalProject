//
//  UITabBar+CustomBadge.h
//  gamecenter
//
//  Created by ZhuGuangwen on 15/9/21.
//  Copyright © 2015年 wepie. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, CustomBadgeType){
    kCustomBadgeStyleRedDot,
    kCustomBadgeStyleNumber,
    kCustomBadgeStyleNone
};

@interface UITabBar (CustomBadge)

/**
 *设置tab上icon的宽度，用于调整badge的位置
 */
- (void)setTabIconWidth:(CGFloat)width;

/**
 *设置badge的top
 */
- (void)setBadgeTop:(CGFloat)top;

/**
 *设置badge样、数字
 */
- (void)setBadgeStyle:(CustomBadgeType)type value:(NSInteger)badgeValue atIndex:(NSInteger)index;

@end
