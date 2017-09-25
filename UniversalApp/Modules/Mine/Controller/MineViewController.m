//
//  MineViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "MineViewController.h"
#import "MineTableViewCell.h"
#import "MineHeaderView.h"
#import "ProfileViewController.h"
#import "SettingViewController.h"
#import "XYTransitionProtocol.h"

#define KHeaderHeight ((260 * Iphone6ScaleWidth) + kStatusBarHeight)

@interface MineViewController ()<UITableViewDelegate,UITableViewDataSource,headerViewDelegate,XYTransitionProtocol>
{
    UILabel * lbl;
    NSArray *_dataSource;
    MineHeaderView *_headerView;//头部view
    UIView *_NavView;//导航栏
}
@end

@implementation MineViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.isHidenNaviBar = YES;
    self.StatusBarStyle = UIStatusBarStyleLightContent;
    self.isShowLiftBack = NO;//每个根视图需要设置该属性为NO，否则会出现导航栏异常
    
    [self createUI];
    
}

-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    [self getRequset];
}
-(void)viewDidAppear:(BOOL)animated{
    [super viewDidAppear:animated];
    //    self.navigationController.delegate = self.navigationController;
}
-(void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
    //    [self ysl_removeTransitionDelegate];
}

#pragma mark ————— 拉取数据 —————
-(void)getRequset{
    _headerView.userInfo = curUser;
}

#pragma mark ————— 头像被点击 —————
-(void)headerViewClick{
    //    [self ysl_addTransitionDelegate:self];
    ProfileViewController *profileVC = [ProfileViewController new];
    profileVC.headerImage = _headerView.headImgView.image;
    [self.navigationController pushViewController:profileVC animated:YES];
}

#pragma mark ————— 昵称被点击 —————
-(void)nickNameViewClick{
    [self.navigationController pushViewController:[RootViewController new] animated:YES];
}

#pragma mark -- YSLTransitionAnimatorDataSource
//-(UIImageView *)pushTransitionImageView{
//    return _headerView.headImgView;
//}
//
//- (UIImageView *)popTransitionImageView
//{
//    return nil;
//}
-(UIView *)targetTransitionView{
    return _headerView.headImgView;
}
-(BOOL)isNeedTransition{
    return YES;
}


#pragma mark ————— 创建页面 —————
-(void)createUI{
    self.tableView.height = KScreenHeight - kTabBarHeight;
    self.tableView.mj_header.hidden = YES;
    self.tableView.mj_footer.hidden = YES;
    [self.tableView registerClass:[MineTableViewCell class] forCellReuseIdentifier:@"MineTableViewCell"];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    
    _headerView = [[MineHeaderView alloc] initWithFrame:CGRectMake(0, -KHeaderHeight, KScreenWidth, KHeaderHeight)];
    _headerView.delegate = self;
    self.tableView.contentInset = UIEdgeInsetsMake(_headerView.height, 0, 0, 0);
    [self.tableView addSubview:_headerView];
    
    
    [self.view addSubview:self.tableView];
    
    [self createNav];
    
    NSDictionary *myWallet = @{@"titleText":@"我的钱包",@"clickSelector":@"",@"title_icon":@"qianb",@"detailText":@"10.00",@"arrow_icon":@"arrow_icon"};
    NSDictionary *myMission = @{@"titleText":@"我的任务",@"clickSelector":@"",@"title_icon":@"renw",@"arrow_icon":@"arrow_icon"};
    NSDictionary *myFriends = @{@"titleText":@"我的好友",@"clickSelector":@"",@"title_icon":@"haoy",@"arrow_icon":@"arrow_icon"};
    NSDictionary *myLevel = @{@"titleText":@"我的等级",@"clickSelector":@"",@"title_icon":@"dengji",@"detailText":@"LV10",@"arrow_icon":@"arrow_icon"};
    
    _dataSource = @[myWallet,myMission,myFriends,myLevel];
    [self.tableView reloadData];
}
#pragma mark ————— 创建自定义导航栏 —————
-(void)createNav{
    _NavView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, KScreenWidth, kTopHeight)];
    _NavView.backgroundColor = KClearColor;
    
    UILabel * titlelbl = [[UILabel alloc] initWithFrame:CGRectMake(0, kStatusBarHeight, KScreenWidth/2, kNavBarHeight )];
    titlelbl.centerX = _NavView.width/2;
    titlelbl.textAlignment = NSTextAlignmentCenter;
    titlelbl.font= SYSTEMFONT(17);
    titlelbl.textColor = KWhiteColor;
    titlelbl.text = self.title;
    [_NavView addSubview:titlelbl];
    
    UIButton * btn = [UIButton buttonWithType:UIButtonTypeSystem];
    [btn setTitle:@"设置" forState:UIControlStateNormal];
    btn.titleLabel.font = SYSTEMFONT(16);
    [btn setTitleColor:KWhiteColor forState:UIControlStateNormal];
    [btn sizeToFit];
    btn.frame = CGRectMake(_NavView.width - btn.width - 15, kStatusBarHeight, btn.width, 40);
    [btn setTitleColor:KWhiteColor forState:UIControlStateNormal];
    [btn addTarget:self action:@selector(changeUser) forControlEvents:UIControlEventTouchUpInside];
    
    [_NavView addSubview:btn];
    
    [self.view addSubview:_NavView];
}

#pragma mark ————— tableview 代理 —————
-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return _dataSource.count;
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return 50.0f;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    MineTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"MineTableViewCell" forIndexPath:indexPath];
    cell.cellData = _dataSource[indexPath.row];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    switch (indexPath.row) {
        case 0:
            NSLog(@"点击了 我的钱包");
            break;
        case 1:
            NSLog(@"点击了 我的任务");
            break;
        case 2:
            NSLog(@"点击了 我的好友");
            break;
        case 3:
            NSLog(@"点击了 我的等级");
            break;
        default:
            break;
    }
}

#pragma mark ————— scrollView 代理 —————
- (void)scrollViewDidScroll:(UIScrollView *)scrollView{
    CGFloat offset = scrollView.contentOffset.y ;
    CGFloat totalOffsetY = scrollView.contentInset.top + offset;
    
    NSLog(@"offset    %.f   totalOffsetY %.f",offset,totalOffsetY);
    //    if (totalOffsetY < 0) {
    _headerView.frame = CGRectMake(0, offset, self.view.width, KHeaderHeight- totalOffsetY);
    //    }
    
}

#pragma mark ————— 切换账号 —————
-(void)changeUser{
    SettingViewController *settingVC = [SettingViewController new];
    [self.navigationController pushViewController:settingVC animated:YES];
    
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
