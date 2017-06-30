//
//  XYTransitionNavigationDelegate.m
//  UniversalApp
//
//  Created by 徐阳 on 2017/6/30.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "XYTransitionNavigationDelegate.h"
#import "XYTransitionProtocol.h"

@interface XYTransitionNavigationDelegate()
@property (nonatomic,weak) UINavigationController * navigationController;
@property (nonatomic,strong) UIPercentDrivenInteractiveTransition *interactivePopTransition;
@property (nonatomic,strong) UIScreenEdgePanGestureRecognizer *popRecognizer;

@end

@implementation XYTransitionNavigationDelegate

-(instancetype)initWithNavigationController:(UINavigationController *)navigation
{
    self = [super init];
    if (self) {
        self.navigationController = navigation;
        self.navigationController.delegate = self;
        
        _popRecognizer = [[UIScreenEdgePanGestureRecognizer alloc] initWithTarget:self action:@selector(handlePopRecognizer:)];
        _popRecognizer.edges = UIRectEdgeLeft;
        [self.navigationController.view addGestureRecognizer:_popRecognizer];
    }
    return self;
}
#pragma mark -UIViewControllerAnimatedTransitioning
//navigation切换是会走这个代理
-(id<UIViewControllerAnimatedTransitioning>)navigationController:(UINavigationController *)navigationController animationControllerForOperation:(UINavigationControllerOperation)operation fromViewController:(UIViewController *)fromVC toViewController:(UIViewController *)toVC
{
    if (_popRecognizer) {
        [_popRecognizer setEnabled:YES];
    }
    if ([fromVC conformsToProtocol:@protocol(XYTransitionProtocol)] && [toVC conformsToProtocol:@protocol(XYTransitionProtocol)]) {
        
        BOOL pinterestNedd = [self isNeedTransition:fromVC:toVC];
        XYTransition *transion = [XYTransition new];
        if (operation == UINavigationControllerOperationPush && pinterestNedd) {
            transion.isPush = YES;
        }
        else if(operation == UINavigationControllerOperationPop && pinterestNedd)
        {
            transion.isPush = NO;
        }
        else{
            if (_popRecognizer) {
                [_popRecognizer setEnabled:NO];
            }
            return nil;
        }
        return transion;
    }
    if (_popRecognizer) {
        [_popRecognizer setEnabled:NO];
    }
    return nil;
}

//判断fromVC和toVC是否需要实现pinterest效果
-(BOOL)isNeedTransition:(UIViewController<XYTransitionProtocol> *)fromVC :(UIViewController<XYTransitionProtocol> *)toVC
{
    BOOL a = NO;
    BOOL b = NO;
    if ([fromVC respondsToSelector:@selector(isNeedTransition)] && [fromVC isNeedTransition]) {
        a = YES;
    }
    if ([toVC respondsToSelector:@selector(isNeedTransition)] && [toVC isNeedTransition]) {
        b = YES;
    }
    return (a && b) ;

}

#pragma mark -- NavitionContollerDelegate
- (id<UIViewControllerInteractiveTransitioning>)navigationController:(UINavigationController *)navigationController
                         interactionControllerForAnimationController:(id<UIViewControllerAnimatedTransitioning>)animationController
{
    if (!self.interactivePopTransition) { return nil; }
    return self.interactivePopTransition;
}


#pragma mark UIGestureRecognizer handlers

- (void)handlePopRecognizer:(UIScreenEdgePanGestureRecognizer*)recognizer
{
    CGFloat progress = [recognizer translationInView:self.navigationController.view].x / (self.navigationController.view.bounds.size.width);
    progress = MIN(1.0, MAX(0.0, progress));
    
    if (recognizer.state == UIGestureRecognizerStateBegan) {
        self.interactivePopTransition = [[UIPercentDrivenInteractiveTransition alloc] init];
        [self.navigationController popViewControllerAnimated:YES];
    }
    else if (recognizer.state == UIGestureRecognizerStateChanged) {
        [self.interactivePopTransition updateInteractiveTransition:progress];
    }
    else if (recognizer.state == UIGestureRecognizerStateEnded || recognizer.state == UIGestureRecognizerStateCancelled) {
        CGPoint velocity = [recognizer velocityInView:recognizer.view];
        
        if (progress > 0.5 || velocity.x >1000) {
            [self.interactivePopTransition finishInteractiveTransition];
        }
        else {
            [self.interactivePopTransition cancelInteractiveTransition];
        }
        self.interactivePopTransition = nil;
    }
}

@end
