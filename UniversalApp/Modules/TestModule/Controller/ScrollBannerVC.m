//
//  ScrollBannerVC.m
//  UniversalApp
//
//  Created by 徐阳 on 2017/9/4.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "ScrollBannerVC.h"
#import "SDCycleScrollView.h"

@interface ScrollBannerVC ()<SDCycleScrollViewDelegate>

@end

@implementation ScrollBannerVC

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSArray *imagesURLStrings = @[
                                  @"https://ss2.baidu.com/-vo3dSag_xI4khGko9WTAnF6hhy/super/whfpf%3D425%2C260%2C50/sign=a4b3d7085dee3d6d2293d48b252b5910/0e2442a7d933c89524cd5cd4d51373f0830200ea.jpg",
                                  @"https://ss0.baidu.com/-Po3dSag_xI4khGko9WTAnF6hhy/super/whfpf%3D425%2C260%2C50/sign=a41eb338dd33c895a62bcb3bb72e47c2/5fdf8db1cb134954a2192ccb524e9258d1094a1e.jpg",
                                  @"http://c.hiphotos.baidu.com/image/w%3D400/sign=c2318ff84334970a4773112fa5c8d1c0/b7fd5266d0160924c1fae5ccd60735fae7cd340d.jpg"];
    
    SDCycleScrollView *cycleScrollView3 = [SDCycleScrollView cycleScrollViewWithFrame:CGRectMake(0, 100, KScreenWidth, 180) delegate:self placeholderImage:[UIImage imageNamed:@"placeholder"]];
    cycleScrollView3.currentPageDotImage = [UIImage imageNamed:@"pageControlCurrentDot"];
    cycleScrollView3.pageDotImage = [UIImage imageNamed:@"pageControlDot"];
    cycleScrollView3.imageURLStringsGroup = imagesURLStrings;
    
    [self.view addSubview:cycleScrollView3];
}

#pragma mark -  scrollview回调
- (void)cycleScrollView:(SDCycleScrollView *)cycleScrollView didSelectItemAtIndex:(NSInteger)index{
    NSLog(@"点击了第%ld个",index);
}

-(void)dealloc{
    NSLog(@"释放VC");
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
