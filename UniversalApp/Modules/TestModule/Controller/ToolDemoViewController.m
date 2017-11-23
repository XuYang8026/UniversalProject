//
//  ToolDemoViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/8/17.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "ToolDemoViewController.h"
#import "MineTableViewCell.h"
#import "RootWebViewController.h"
#import "EmitterViewController.h"
#import "TagsViewController.h"
#import "IAPManager.h"
#import "XZPickView.h"
#import "ScrollBannerVC.h"
#import "NativeCallJSVC.h"

@interface ToolDemoViewController ()<UITableViewDelegate,UITableViewDataSource,IApRequestResultsDelegate,XZPickViewDelegate,XZPickViewDataSource>
@property (nonatomic,strong) NSMutableArray * dataArray;
@property (nonatomic,strong) XZPickView *emitterPickView;
@property (nonatomic,copy) NSArray * emitterArray;
@end

@implementation ToolDemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"Demo";
    self.emitterArray = @[@"彩带",@"下雪",@"下雨",@"烟花"];
    
    NSDictionary *tags = @{@"titleText":@"01 - 标签选择",@"clickSelector":@"tagsView"};
    NSDictionary *webView = @{@"titleText":@"02 - 网页 带进度条",@"clickSelector":@"openWebView"};
    NSDictionary *emitterView = @{@"titleText":@"03 - 粒子效果 & PickView选择器",@"clickSelector":@"emitter"};
    NSDictionary *IAPPay = @{@"titleText":@"04 - IAP内购",@"clickSelector":@"IAP"};
    NSDictionary *tabarBadge = @{@"titleText":@"05 - tabbr badges",@"clickSelector":@"tabarBadge"};
    NSDictionary *share = @{@"titleText":@"06 - 第三方分享",@"clickSelector":@"share"};
    NSDictionary *alert = @{@"titleText":@"07 - AlertView封装（兼容iOS 7+）",@"clickSelector":@"alertView"};
    NSDictionary *action = @{@"titleText":@"08 - ActionSheet封装（兼容iOS 7+）",@"clickSelector":@"actionSheet"};
    NSDictionary *status = @{@"titleText":@"09 - 改变状态栏样式",@"clickSelector":@"changeStatusStyle"};
    NSDictionary *NavColor = @{@"titleText":@"10 - 改变导航栏颜色",@"clickSelector":@"changeNavBarColor"};
    NSDictionary *JSCore = @{@"titleText":@"11 - JS与Native交互",@"clickSelector":@"JSCallNative"};
    NSDictionary *scrollBanner = @{@"titleText":@"12 - 轮播图",@"clickSelector":@"scrollBanner"};
    
    self.dataArray =@[tags,webView,emitterView,IAPPay,tabarBadge,share,alert,action,status,NavColor,JSCore,scrollBanner].mutableCopy;
    
    [self initUI];
    
}


#pragma mark -  初始化页面
-(void)initUI{
    self.tableView.mj_header.hidden = YES;
//    self.tableView.mj_footer.hidden = YES;
    [self.tableView registerClass:[MineTableViewCell class] forCellReuseIdentifier:@"MineTableViewCell"];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    [self.view addSubview:self.tableView];

    [self.tableView reloadData];
}

-(void)footerRereshing{
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        for (int i =0; i<10; i++) {
            NSDictionary *d = @{@"titleText":@"测试滚动",@"clickSelector":@""};
            [self.dataArray addObject:d];
        }
        [self.tableView.mj_footer endRefreshing];
        [self.tableView reloadData];
    });
    
}

#pragma mark ————— tableview 代理 —————
-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return _dataArray.count;
}

-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return 50.0f;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    MineTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"MineTableViewCell" forIndexPath:indexPath];
    cell.cellData = _dataArray[indexPath.row];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    NSString *title = _dataArray[indexPath.row][@"titleText"];
//    NSString *selector = _dataArray[indexPath.row][@"clickSelector"];
    [MBProgressHUD showTopTipMessage:title isWindow:YES];
    NSString *selectorStr = _dataArray[indexPath.row][@"clickSelector"];
    if (selectorStr && selectorStr.length>0) {
        SEL selector = NSSelectorFromString(_dataArray[indexPath.row][@"clickSelector"]);
        if (selector) {
            [self performSelector:selector withObject:nil];
        }
    }
    
}

#pragma mark -  XZPickView 代理
//列数
-(NSInteger)numberOfComponentsInPickerView:(XZPickView *)pickerView{
    return 1;
}

//行数
-(NSInteger)pickerView:(XZPickView *)pickerView numberOfRowsInComponent:(NSInteger)component{
    return self.emitterArray.count;
}

//标题
-(NSString *)pickerView:(XZPickView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component{
    return self.emitterArray[row];
}
//确认按钮点击
-(void)pickView:(XZPickView *)pickerView confirmButtonClick:(UIButton *)button{
    NSInteger left = [pickerView selectedRowInComponent:0];
    EmitterViewController *emitterVC = [[EmitterViewController alloc] init];
    emitterVC.animation_type = left;
    [self.navigationController pushViewController:emitterVC animated:YES];

}

//滑动选中
-(void)pickerView:(XZPickView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component{
    
}




#pragma mark -  标签选择
-(void)tagsView{
    TagsViewController *tagsView = [TagsViewController new];
    RootNavigationController *Navi =[[RootNavigationController alloc] initWithRootViewController:tagsView];
    [self presentViewController:Navi animated:YES completion:nil];
//    [self.navigationController pushViewController:tagsView animated:YES];
}

#pragma mark -  网页测试
-(void)openWebView{
    RootNavigationController *loginNavi =[[RootNavigationController alloc] initWithRootViewController:[[RootWebViewController alloc] initWithUrl:@"http://www.hao123.com"]];
    [self presentViewController:loginNavi animated:YES completion:nil];
    
    //push
//    RootWebViewController *webView = [[RootWebViewController alloc] initWithUrl:@"http://hao123.com"];
//    [webView addNavigationItemWithTitles:@[@"测试"] isLeft:NO target:self action:@selector(naviBtnClick:) tags:@[@1003]];
//    [self.navigationController pushViewController:webView animated:YES];
}

#pragma mark -  粒子效果 + 选择器
-(void)emitter{
    [self.emitterPickView reloadData];
    //[self.userNumPickView selectRow:0 inComponent:0 animated:NO];
    [kAppWindow addSubview:self.emitterPickView];
    [self.emitterPickView show];
}

#pragma mark -  alertview
-(void)alertView{
    [self AlertWithTitle:@"测试标题" message:@"测试内容" andOthers:@[@"取消",@"确定"] animated:YES action:^(NSInteger index) {
        DLog(@"点击了 %ld",index);
    }];
}

#pragma mark -  ActionSheet
-(void)actionSheet{
    [self ActionSheetWithTitle:@"测试" message:@"测试内容" destructive:nil destructiveAction:nil andOthers:@[@"1",@"2",@"3",@"4"] animated:YES action:^(NSInteger index) {
        DLog(@"点了 %ld",index);
    }];
}

#pragma mark ————— 粒子效果 —————
-(void)addrainBtn:(NSInteger) type top:(float)top{
    NSMutableAttributedString *text = [NSMutableAttributedString new];
    NSString *str;
    {
        switch (type) {
            case 1://下雪
                str = @"下雪";
                break;
            case 2://下雨
                str = @"下雨";
                break;
            case 3://烟花
                str = @"烟花";
                break;
                
            default:
                break;
        }
        
        NSMutableAttributedString *one = [[NSMutableAttributedString alloc] initWithString:str];
        one.font = [UIFont boldSystemFontOfSize:30];
        one.color = [UIColor whiteColor];
        
        YYTextShadow *shadow = [YYTextShadow new];
        shadow.color = [UIColor colorWithWhite:0.000 alpha:0.490];
        shadow.offset = CGSizeMake(0, 1);
        shadow.radius = 5;
        one.textShadow = shadow;
        
        YYTextShadow *shadow0 = [YYTextShadow new];
        shadow0.color = [UIColor colorWithWhite:0.000 alpha:0.20];
        shadow0.offset = CGSizeMake(0, -1);
        shadow0.radius = 1.5;
        YYTextShadow *shadow1 = [YYTextShadow new];
        shadow1.color = [UIColor colorWithWhite:1 alpha:0.99];
        shadow1.offset = CGSizeMake(0, 1);
        shadow1.radius = 1.5;
        shadow0.subShadow = shadow1;
        
        YYTextShadow *innerShadow0 = [YYTextShadow new];
        innerShadow0.color = [UIColor colorWithRed:0.851 green:0.311 blue:0.000 alpha:0.780];
        innerShadow0.offset = CGSizeMake(0, 1);
        innerShadow0.radius = 1;
        
        YYTextHighlight *highlight = [YYTextHighlight new];
        [highlight setColor:[UIColor colorWithRed:1.000 green:0.795 blue:0.014 alpha:1.000]];
        [highlight setShadow:shadow0];
        [highlight setInnerShadow:innerShadow0];
        [one setTextHighlight:highlight range:one.rangeOfAll];
        
        [text appendAttributedString:one];
    }
    
    YYLabel *snowBtn = [[YYLabel alloc] initWithFrame:CGRectMake(0, top, 200, 30)];
    snowBtn.attributedText = text;
    snowBtn.textAlignment = NSTextAlignmentCenter;
    snowBtn.textVerticalAlignment = YYTextVerticalAlignmentCenter;
    snowBtn.centerX = KScreenWidth/2;
    
    
    snowBtn.textTapAction = ^(UIView * _Nonnull containerView, NSAttributedString * _Nonnull text, NSRange range, CGRect rect) {
        //        [MBProgressHUD showTopTipMessage:NSStringFormat(@"%@马上开始",str) isWindow:YES];
        
            };
    
    [self.view addSubview:snowBtn];
    
}


#pragma mark -  tabarBadge
-(void)tabarBadge{
    [kAppDelegate.mainTabBar setRedDotWithIndex:3 isShow:YES];
    [self.navigationController popToRootViewControllerAnimated:YES];
}

#pragma mark -  IAPTest
-(void)IAP{
    [IAPManager sharedIAPManager].delegate = self;
    [[IAPManager sharedIAPManager] requestProductWithId:@"test_1"];
}
#pragma mark IApRequestResultsDelegate
- (void)filedWithErrorCode:(NSInteger)errorCode andError:(NSString *)error {
    NSString *errorStr = @"支付失败";
    switch (errorCode) {
        case IAP_FILEDCOED_APPLECODE:
            NSLog(@"用户禁止应用内付费购买:%@",error);
            errorStr = NSStringFormat(@"用户禁止应用内付费购买%@",error);
            break;
            
        case IAP_FILEDCOED_NORIGHT:
            errorStr = @"用户禁止应用内付费购买";
            NSLog(@"用户禁止应用内付费购买");
            break;
            
        case IAP_FILEDCOED_EMPTYGOODS:
            errorStr = @"商品为空";
            NSLog(@"商品为空");
            break;
            
        case IAP_FILEDCOED_CANNOTGETINFORMATION:
            errorStr = @"无法获取产品信息，请重试";
            NSLog(@"无法获取产品信息，请重试");
            break;
            
        case IAP_FILEDCOED_BUYFILED:
            errorStr = @"购买失败，请重试";
            NSLog(@"购买失败，请重试");
            break;
            
        case IAP_FILEDCOED_USERCANCEL:
            errorStr = @"用户取消交易";
            NSLog(@"用户取消交易");
            break;
            
        default:
            break;
    }
    
    [MBProgressHUD showErrorMessage:errorStr];
}

#pragma mark -  share
-(void)share{
    [[ShareManager sharedShareManager] showShareView];
}

#pragma mark -  修改状态栏样式
-(void)changeStatusStyle{
    self.StatusBarStyle = !self.StatusBarStyle;
}

#pragma mark -  修改导航栏颜色
-(void)changeNavBarColor{
    UIColor * color = [UIColor colorWithRed:0/255.0 green:175/255.0 blue:240/255.0 alpha:1];
//    [self.navigationController.navigationBar lt_setBackgroundColor:color];
}

#pragma mark -  JSCallNative
-(void)JSCallNative{
    NSString * fileUrl = [[NSBundle mainBundle]pathForResource:@"JSToOC" ofType:@"html"];
    NSURL * file = [NSURL fileURLWithPath:fileUrl];
    
    NativeCallJSVC *webVC = [[NativeCallJSVC alloc] initWithUrl:file.absoluteString];
    webVC.isHidenNaviBar = YES;
    RootNavigationController *loginNavi =[[RootNavigationController alloc] initWithRootViewController:webVC];
    
    [self presentViewController:loginNavi animated:YES completion:nil];
}

#pragma mark -  scrollBanner
-(void)scrollBanner{
    ScrollBannerVC *b = [ScrollBannerVC new];
    [self.navigationController pushViewController:b animated:YES];
}

-(void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    self.tableView.delegate = self;
}

-(void)viewWillDisappear:(BOOL)animated{
    [super viewWillDisappear:animated];
    self.tableView.delegate = nil;
}

-(XZPickView *)emitterPickView{
    if(!_emitterPickView){
        _emitterPickView = [[XZPickView alloc]initWithFrame:kScreen_Bounds title:@"请选择"];
        _emitterPickView.delegate = self;
        _emitterPickView.dataSource = self;
    }
    return _emitterPickView;
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
