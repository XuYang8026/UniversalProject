//
//  MakeFriendsViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/5/18.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "MakeFriendsViewController.h"
#import "CellModel.h"
#import "TableViewCell.h"
#import "MakeFriendsLogic.h"

@interface MakeFriendsViewController ()<UITableViewDelegate,UITableViewDataSource,MakeFriendsDelegate>

@property (nonatomic,strong) NSMutableArray * dataArray;
@property (nonatomic,strong) MakeFriendsLogic * logic;
@end

@implementation MakeFriendsViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    _dataArray = @[].mutableCopy;
    _logic = [MakeFriendsLogic new];
    _logic.delegagte = self;
    [self initUI];
    [self.tableView.mj_header beginRefreshing];
}
#pragma mark -  初始化UI
-(void)initUI{
    self.tableView.frame = CGRectMake(0, 0, KScreenWidth, KScreenHeight - kTopHeight - kTabBarHeight);
    [self.view addSubview:self.tableView];
    [self.tableView registerClass:[TableViewCell class] forCellReuseIdentifier:NSStringFromClass([TableViewCell class])];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    
}

#pragma mark -  tableView delegate
-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return _logic.dataArray.count;
}
-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return 45.0f;
}
-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    TableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass([TableViewCell class]) forIndexPath:indexPath];
    cell.model = _logic.dataArray[indexPath.row];
    return cell;
}

#pragma mark ————— 下拉刷新 —————
-(void)headerRereshing{
    [_logic.dataArray removeAllObjects];
    [_logic loadData];
}

#pragma mark ————— 上拉刷新 —————
-(void)footerRereshing{
    [_logic loadData];
}


#pragma mark -  logic delegate
-(void)requestDataCompleted{
    [self.tableView.mj_header endRefreshing];
    [self.tableView.mj_footer endRefreshing];
    [self.tableView reloadData];
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
