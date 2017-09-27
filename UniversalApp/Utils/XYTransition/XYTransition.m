//
//  XYTransition.m
//  UniversalApp
//
//  Created by 徐阳 on 2017/6/30.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "XYTransition.h"
#import "XYTransitionProtocol.h"

@interface XYTransition()

@property (nonatomic, assign) CGFloat animationScale;//缩放比例

@end

@implementation XYTransition

-(instancetype)init{
    self = [super init];
    if (self) {
        self.animationDuration = 0.3;
    }
    return self;
}

- (NSTimeInterval)transitionDuration:(id<UIViewControllerContextTransitioning>)transitionContext
{
    return self.animationDuration;
}

- (void)animateTransition:(id<UIViewControllerContextTransitioning>)transitionContext
{
    if (_isPush) {
        [self pushAnimateTransition:transitionContext];
    }else{
        [self popAnimateTransition:transitionContext];
    }
}

#pragma mark ————— push —————
- (void)pushAnimateTransition:(id<UIViewControllerContextTransitioning>)transitionContext
{
    //获取跳转的Controller和目标Controller
    UIViewController<XYTransitionProtocol> * fromVC = (UIViewController <XYTransitionProtocol> * )[transitionContext viewControllerForKey:UITransitionContextFromViewControllerKey];
    UIViewController<XYTransitionProtocol> * toVC = (UIViewController <XYTransitionProtocol> * )[transitionContext viewControllerForKey:UITransitionContextToViewControllerKey];
    //from和to的两个视图
    __block UIView * fromView = fromVC.view;
    __block UIView * toView = toVC.view;
    
    //container容器加入要显示的视图 不加入fromVC 返回的时候就无法返回
    UIView * containerView = [transitionContext containerView];
    [containerView addSubview:fromView];
    [containerView addSubview:toView];
    
    //转场动画的目标View
    UIView *fromCellView = [fromVC targetTransitionView];
    UIView *toCellView = [toVC targetTransitionView];
    
    //获取cell相对左上角坐标 计算相对坐标
    CGPoint nowViewPoint = [fromCellView convertPoint:CGPointZero toView:nil];
    
    //获取当前view相对窗口坐标
    CGPoint toViewPoint = [toCellView convertPoint:CGPointZero toView:nil];
    
    toView.hidden = YES;
    
    
    //复制一个Cell用于显示动画效果
    __block UIImageView * snapShot =[[UIImageView alloc] initWithImage:[fromCellView snapshotImage]];
    snapShot.backgroundColor = [UIColor clearColor];
    [containerView addSubview:snapShot];
    
    [snapShot setOrigin:nowViewPoint];
    //计算缩放比例
    _animationScale = MAX([toVC targetTransitionView].width, snapShot.width) / MIN([toVC targetTransitionView].width, snapShot.width);
    CGRect originFrame = fromView.frame;
    [UIView animateWithDuration:self.animationDuration animations:^{
        //设置缩放变换 x,y分别放大多少倍
        snapShot.transform =  CGAffineTransformMakeScale(_animationScale,_animationScale);
        [snapShot setOrigin:toViewPoint];
        
        fromView.alpha = 0;
        fromView.transform = snapShot.transform;
        fromView.frame = CGRectMake(-(nowViewPoint.x)*_animationScale,
                                    -(nowViewPoint.y)*_animationScale + toViewPoint.y,
                                    fromVC.view.frame.size.width,
                                    fromVC.view.frame.size.height);
        kAppDelegate.mainTabBar.tabBar.alpha = 0;
    } completion:^(BOOL finished) {
        if (finished) {
            //没有这句过滤动画就不会结束
            [snapShot removeFromSuperview];
            toView.hidden = NO;
            fromView.alpha = 1;
            fromVC.view.transform = CGAffineTransformIdentity;
            fromVC.view.frame = originFrame;
            [transitionContext completeTransition:!transitionContext.transitionWasCancelled];
        }
    }];
    
}

#pragma mark ————— pop —————
- (void)popAnimateTransition:(id<UIViewControllerContextTransitioning>)transitionContext
{
    //获取跳转VC和目标VC
    UIViewController <XYTransitionProtocol> * fromVC = (UIViewController<XYTransitionProtocol>*)[transitionContext viewControllerForKey:UITransitionContextFromViewControllerKey];
    UIViewController <XYTransitionProtocol> * toVC = (UIViewController<XYTransitionProtocol>*)[transitionContext viewControllerForKey:UITransitionContextToViewControllerKey];
    
    //添加要跳转的视图并且先隐藏掉
    UIView * containerView = [transitionContext containerView];
    __block UIView * toView = toVC.view;
    [containerView addSubview:toView];
    toView.hidden = YES;
    
    //来源View
    UIView *fromCellView = [fromVC targetTransitionView];
    
    //转场动画的目标View
    UIView *toCellView = [toVC targetTransitionView];
    
    //获取相对窗口的坐标
    CGPoint leftUperPoint = [toCellView convertPoint:CGPointZero toView:nil];
    
    //获取当前view相对窗口坐标
    CGPoint nowViewPoint = [fromCellView convertPoint:CGPointZero toView:nil];
    
    //计算cell偏移量 为了更好的现实动画
//    CGFloat offsetY = fromVC.navigationController.navigationBarHidden ? 0.0 : 64;
    //复制一份截图用于动画过程
    __block UIImageView * snapShot =[[UIImageView alloc] initWithImage:[toCellView snapshotImage]];
    
    //计算缩放比例
    _animationScale = MAX(fromCellView.width, snapShot.width) / MIN(fromCellView.width, snapShot.width);
    
    [containerView addSubview:snapShot];
    snapShot.backgroundColor = [UIColor clearColor];
    //将目标View先放大到跟当前view一样大，然后在动画中缩小，实现动画pop效果
    snapShot.transform = CGAffineTransformMakeScale(_animationScale, _animationScale);
    [snapShot setOrigin:CGPointMake(0, nowViewPoint.y)];
    //用于动画设置淡出缩小效果
    CGRect originFrame = toView.frame;
    toView.hidden = NO;
    toView.alpha = 0;
    toView.transform = snapShot.transform;
    
    toView.frame = CGRectMake(-(leftUperPoint.x * _animationScale), -((leftUperPoint.y - nowViewPoint.y) * _animationScale + nowViewPoint.y),
                              toView.frame.size.width, toView.frame.size.height);
    
    
    toCellView.hidden = YES;
    //添加一个百色淡出效果
    __block UIView *whiteViewContainer = [[UIView alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    whiteViewContainer.backgroundColor = [UIColor whiteColor];
    
    [containerView addSubview:whiteViewContainer];
    [containerView insertSubview:whiteViewContainer belowSubview:toView];
    kAppDelegate.mainTabBar.tabBar.alpha = 0;
    [UIView animateWithDuration:self.animationDuration animations:^{
        snapShot.transform = CGAffineTransformIdentity; //恢复原来大小
        [snapShot setOrigin:leftUperPoint]; //设置相对位置
        toView.transform = CGAffineTransformIdentity;
        toView.alpha = 1.0;
        [toView setFrame:originFrame];
        kAppDelegate.mainTabBar.tabBar.alpha = 1;
    } completion:^(BOOL finished) {
        //        if (finished) {
        if (transitionContext.transitionWasCancelled) {
            NSLog(@"动画取消");
            kAppDelegate.mainTabBar.tabBar.alpha = 0;
        }else{
            NSLog(@"动画完成");
        }
        
        [snapShot removeFromSuperview];
        [whiteViewContainer removeFromSuperview];
        toCellView.hidden = NO;
        toView.transform = CGAffineTransformIdentity;
        toView.frame = originFrame;
        [transitionContext completeTransition:!transitionContext.transitionWasCancelled];
        
        //        }
    }];
}
@end
