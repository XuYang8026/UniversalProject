//
//  XYTransitionProtocol.h
//  UniversalApp
//
//  Created by 徐阳 on 2017/6/30.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol XYTransitionProtocol <NSObject>
@optional

/**
 转场动画的目标View 每个需要转场动画的VC实现该方法

 @return view
 */
-(UIView *)targetTransitionView;

///**
// 转场动画 目标View
//
// @return view
// */
//-(UIView *)transitionToView;

/**
 *  是否是需要实现 转场效果
 *
 *  @return 是否
 */
-(BOOL)isNeedTransition;

@end
