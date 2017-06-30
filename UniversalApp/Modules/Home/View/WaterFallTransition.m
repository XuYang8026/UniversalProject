//
//  WaterFallTransition.m
//  UniversalApp
//
//  Created by 徐阳 on 2017/6/29.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "WaterFallTransition.h"

#define animationScale (KScreenWidth/(KScreenWidth/2)-5.0)

@implementation WaterFallTransition

-(NSTimeInterval)transitionDuration:(id<UIViewControllerContextTransitioning>)transitionContext{
    return self.animationDuration==0?YES:2;
}
-(void)animateTransition:(id<UIViewControllerContextTransitioning>)transitionContext{
    
}
@end
