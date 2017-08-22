//
//  TagsViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/8/17.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "TagsViewController.h"
#import "FFTagsView.h"


@interface TagsViewController ()

@end

@implementation TagsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self createTagsView];
}

#pragma mark -  标签View
-(void)createTagsView{
    self.view.backgroundColor = KGrayColor;
    FFTagsViewConfig *config = [[FFTagsViewConfig alloc] init];
    config.itemHeight = 35;
    config.itemHerMargin = 14;
    config.itemVerMargin = 10;
    config.hasBorder = YES;
    config.topBottomSpace = 15.0;
    config.itemContentEdgs = 13;
    config.isCanSelected = YES;
    config.isCanCancelSelected = YES;
    config.singleSelectedTitle = @"啥风格风格";
    config.isMulti = YES;
    config.normalBgImage = [UIImage imageWithColor:KWhiteColor];
    config.selectedBgImage = [UIImage imageWithColor:[UIColor redColor]];
    config.fontSize = 14;
    config.selectedTitleColor = KWhiteColor;
    config.selectedDefaultTags =  @[@"功夫",@"是否",@"很感动的"] ;
    
    CGFloat w = [UIScreen mainScreen].bounds.size.width-50;
    NSArray *tags = @[@"反倒是",@"更多",@"鼓捣鼓捣发",@"国防生的",@"韩国",@"还让",@"金凤",@"人的风格",@"个梵蒂冈和",@"第三方",@"是否",@"热",@"啥风格风格",@"功夫",@"发送给是否",@"方法",@"好的",@"爱国的风格",@"符合的",@"很感动的",@"就好几个大地飞歌"];
    FFTagsView *tagView = [[FFTagsView alloc] initWithFrame:CGRectMake(25, 100, w, 0) tagsArray:tags config:config];
    tagView.backgroundColor = [UIColor whiteColor];
    
    tagView.tagBtnClickedBlock = ^(FFTagsView *aTagsView, UIButton *sender, NSInteger index){
        NSLog(@"--- index = %ld",index);
        //NSLog(@"---- titles = %@",aTagsView.multiSelectedTags);
    };
    
    [self.view addSubview:tagView];
    
    
    CGFloat viewHeight = [tagView heighttagsArray:tags config:config];
    NSLog(@"------h = %.2f---",viewHeight);
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
