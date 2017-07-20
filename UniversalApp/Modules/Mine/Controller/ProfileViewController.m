//
//  ProfileViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/6/14.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "ProfileViewController.h"
#import "XYTransitionProtocol.h"
#import "WaterFallListViewController.h"

@interface ProfileViewController ()<XYTransitionProtocol>

@property (nonatomic, strong) UIImageView *headerImageView;
@property (nonatomic, strong) UIView *detailsView;

@end

@implementation ProfileViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.title = @"个人信息";
    _headerImageView = [UIImageView new];
    _headerImageView.frame = CGRectMake(0, 64, self.view.width , KScreenWidth/_headerImage.size.width * _headerImage.size.height);
    [self.view addSubview:_headerImageView];
    [_headerImageView setImage:_headerImage];
}

-(void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    [self createDetails];
}
#pragma mark -  信息详情
-(void)createDetails{
    if (_detailsView) {
        return;
    }
    _detailsView = [[UIView alloc] initWithFrame:CGRectMake(0, _headerImageView.bottom, KScreenWidth, 1000)];
    [self.view addSubview:_detailsView];
    UILabel *lbl = [[UILabel alloc] initWithFrame:CGRectMake(15, 20, KScreenWidth-30, 230)];
    lbl.numberOfLines = 0;
    lbl.text = @"个人信息\n\n\n昵称：萌萌哒小萌新\n\n性别：女\n\n个人爱好：琴棋书画我样样不会，只会打王者荣耀😜";
//    [lbl sizeToFit];
    lbl.font = SYSTEMFONT(20);
    lbl.textColor = KBlackColor;
    [_detailsView addSubview:lbl];
    
    _detailsView.alpha = 0;
    _detailsView.transform = CGAffineTransformMakeTranslation(0, 50);
    [UIView animateWithDuration:0.5 delay:0 options:UIViewAnimationOptionAllowUserInteraction|UIViewAnimationOptionCurveEaseInOut animations:^{
        _detailsView.alpha = 1;
        _detailsView.transform = CGAffineTransformIdentity;
    } completion:^(BOOL finished) {
        
    }];
}

-(UIView *)targetTransitionView{
    return self.headerImageView;
}
-(BOOL)isNeedTransition{
    return _isTransition;
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
