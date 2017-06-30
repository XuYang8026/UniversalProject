//
//  WaterFallTransition.h
//  UniversalApp
//
//  Created by 徐阳 on 2017/6/29.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WaterFallTransition : NSObject<UIViewControllerAnimatedTransitioning>

PropertyBool(isPush);
PropertyFloat(animationDuration);

@end
