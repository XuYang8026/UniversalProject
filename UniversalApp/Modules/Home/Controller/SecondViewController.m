//
//  SecondViewController.m
//  UniversalApp
//
//  Created by 徐阳 on 2017/6/29.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "SecondViewController.h"
#import "XYTransitionProtocol.h"

@interface SecondViewController ()<XYTransitionProtocol>
{
    UIImageView * _imgView;
}

@end

@implementation SecondViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self addNavigationItemWithTitles
     :@[@"push"] isLeft:NO target:self action:@selector(naviBtnClick:) tags:@[@1000]];
    
    _imgView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 64, kScreenWidth, kScreenWidth/_photoImg.size.width*_photoImg.size.height)];
    [self.view addSubview:_imgView];
    [_imgView setImage:_photoImg];
    
}
-(void)setPhotoImg:(UIImage *)photoImg{
    _photoImg = photoImg;
}

#pragma mark ————— 转场动画目标View —————
-(UIView *)targetTransitionView{
    return _imgView;
}

-(BOOL)isNeedTransition{
    return YES;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
