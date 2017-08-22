//
//  SettingViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/6/16.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "SettingViewController.h"
#import "BaseTableViewCell.h"
#import "HSBaseCellModel.h"

@interface SettingViewController ()<UITableViewDelegate,UITableViewDataSource>

@property (nonatomic,copy) NSArray * dataArray;//数据源

@end

@implementation SettingViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"设置";
    [self setupUI];
    [self getData];
}
#pragma mark ————— 初始化页面 —————
-(void)setupUI{
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    self.tableView.mj_header.hidden = YES;
    self.tableView.mj_footer.hidden = YES;
    [self.tableView registerClass:[BaseTableViewCell class] forCellReuseIdentifier:@"BaseTableViewCell"];
    [self.view addSubview:self.tableView];
    
    
    
    UIView *footView = [[UIView alloc]initWithFrame:CGRectMake(0, 0, KScreenWidth, 69)];
    
    UIButton *logoutBtn = [UIButton buttonWithType:UIButtonTypeSystem];
    logoutBtn.frame = CGRectMake(0, 20, footView.width, 49);
    logoutBtn.titleLabel.font = SYSTEMFONT(16);
    [logoutBtn setTitle:@"退出登录" forState:UIControlStateNormal];
    [logoutBtn setTitleColor:KBlackColor forState:UIControlStateNormal];
    logoutBtn.backgroundColor = KWhiteColor;
    [logoutBtn addTarget:self action:@selector(logoutAction:) forControlEvents:UIControlEventTouchUpInside];
    
    [footView addSubview:logoutBtn];
    
    self.tableView.tableFooterView = footView;
}

#pragma mark ————— 数据源 —————
-(void)getData{
    HSBaseCellModel *pushCofigModel = [HSBaseCellModel new];
    pushCofigModel.title = @"推送消息设置";
    pushCofigModel.identifier = 9000;
    pushCofigModel.selectionStyle = UITableViewCellSelectionStyleNone;
    pushCofigModel.isShowArrow = YES;

    
    HSBaseCellModel *soundsCofigModel = [HSBaseCellModel new];
    soundsCofigModel.title = @"声音";
    soundsCofigModel.identifier = 9001;
    soundsCofigModel.selectionStyle = UITableViewCellSelectionStyleNone;
    soundsCofigModel.detailText = @"关";
    soundsCofigModel.isShowArrow = NO;
    
    HSBaseCellModel *cleanCofigModel = [HSBaseCellModel new];
    cleanCofigModel.title = @"清除缓存";
    cleanCofigModel.identifier = 9002;
    cleanCofigModel.selectionStyle = UITableViewCellSelectionStyleNone;
    cleanCofigModel.detailText = NSStringFormat(@"%.2fM",[self filePath]);
    cleanCofigModel.isShowArrow = NO;
    
    HSBaseCellModel *aboutCofigModel = [HSBaseCellModel new];
    aboutCofigModel.title = @"关于我们";
    aboutCofigModel.identifier = 9003;
    aboutCofigModel.selectionStyle = UITableViewCellSelectionStyleNone;
    aboutCofigModel.isShowArrow = YES;
    
    NSArray *one = @[pushCofigModel];
    NSArray *two = @[soundsCofigModel,cleanCofigModel,aboutCofigModel];
    _dataArray = @[one,two];
    [self.tableView reloadData];
    
}

#pragma mark ————— tableView 代理 —————
-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return _dataArray.count;
}
-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return [_dataArray[section] count];
}
-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return 49.0f;
}
- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section
{
    //如果是最后一个section
    if(section == self.dataArray.count - 1){
        return 0;
    }
    return 10;
}

- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section
{
    
    //如果是最后一个section
    if(section == self.dataArray.count - 1){
        return nil;
    }
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 10)];
    [view setBackgroundColor:CViewBgColor];
    return view;
}
-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    BaseTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"BaseTableViewCell" forIndexPath:indexPath];
    HSBaseCellModel *model = _dataArray[indexPath.section][indexPath.row];
    cell.selectionStyle = model.selectionStyle;
    cell.textLabel.text = model.title;
    cell.customDetailText = model.detailText;
    cell.accessoryType = model.isShowArrow ? UITableViewCellAccessoryDisclosureIndicator : UITableViewCellAccessoryNone;
    return cell;
}
-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    HSBaseCellModel *model = _dataArray[indexPath.section][indexPath.row];
    NSLog(@"点击了 %@",model.title);
//    switch (indexPath.row) {
//        case 9000:
//        {
//            NSLog(@"点击了 %@",model.title);
//        }
//            break;
//            
//        default:
//            break;
//    }
}
-(void)viewDidLayoutSubviews
{
    if ([self.tableView respondsToSelector:@selector(setSeparatorInset:)]) {
        [self.tableView setSeparatorInset:UIEdgeInsetsMake(0,0,0,0)];
    }
    
    if ([self.tableView respondsToSelector:@selector(setLayoutMargins:)]) {
        [self.tableView setLayoutMargins:UIEdgeInsetsMake(0,0,0,0)];
    }
}

-(void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([cell respondsToSelector:@selector(setSeparatorInset:)]) {
        [cell setSeparatorInset:UIEdgeInsetsZero];
    }
    
    if ([cell respondsToSelector:@selector(setLayoutMargins:)]) {
        [cell setLayoutMargins:UIEdgeInsetsZero];
    }
}
#pragma mark ————— 退出登录 —————
-(void)logoutAction:(UIButton *)btn{
    [self AlertWithTitle:nil message:@"确定要退出吗？" andOthers:@[@"取消",@"确定"] animated:YES action:^(NSInteger index) {
        NSLog(@"%ld",index);
        if (index == 1) {
            [userManager logout:nil];
        }
    }];
}
#pragma mark ————— 计算缓存大小 —————
// 显示缓存大小
-(float)filePath{
    NSString * cachPath = [ NSSearchPathForDirectoriesInDomains ( NSCachesDirectory , NSUserDomainMask , YES ) firstObject ];
    return [ self folderSizeAtPath :cachPath];
}

-(long long)fileSizeAtPath:(NSString *)path{
    NSFileManager *fileManager=[NSFileManager defaultManager];
    if([fileManager fileExistsAtPath:path]){
        long long size=[fileManager attributesOfItemAtPath:path error:nil].fileSize;
        return size;
    }
    return 0;
}
-(float)folderSizeAtPath:(NSString *)path{
    NSFileManager *fileManager=[NSFileManager defaultManager];
    NSString *cachePath=[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject];
    cachePath=[cachePath stringByAppendingPathComponent:path];
    long long folderSize=0;
    if ([fileManager fileExistsAtPath:cachePath])
    {
        NSArray *childerFiles=[fileManager subpathsAtPath:cachePath];
        for (NSString *fileName in childerFiles)
        {
            NSString *fileAbsolutePath=[cachePath stringByAppendingPathComponent:fileName];
            long long size=[self fileSizeAtPath:fileAbsolutePath];
            folderSize += size;
            NSLog(@"fileAbsolutePath=%@",fileAbsolutePath);
            
        }
        return folderSize/1024.0/1024.0;
    }
    return 0;
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
