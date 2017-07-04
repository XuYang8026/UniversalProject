//
//  WaterFallListViewController.m
//  MiAiApp
//
//  Created by 徐阳 on 2017/6/22.
//  Copyright © 2017年 徐阳. All rights reserved.
//

#import "WaterFallListViewController.h"
#import "WaterFallCollectionViewCell.h"
#import "WaterFlowLayout.h"
#import "SecondViewController.h"
#import "UICollectionView+IndexPath.h"
#import "XYTransitionProtocol.h"
#import "HomeViewController.h"
#import "WaterFallListLogic.h"

#define itemWidthHeight ((kScreenWidth-10)/2)

@interface WaterFallListViewController ()<UICollectionViewDelegate,UICollectionViewDataSource,WaterFlowLayoutDelegate,XYTransitionProtocol,WaterFallListDelegate>


@property(nonatomic,strong) WaterFallListLogic *logic;//逻辑层
@end

@implementation WaterFallListViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.isShowLiftBack = NO;//每个根视图需要设置该属性为NO，否则会出现导航栏异常
    
    //初始化逻辑类
    _logic = [WaterFallListLogic new];
    _logic.delegagte = self;
    
    [self setupUI];
    //开始第一次数据拉取
    [self.collectionView.mj_header beginRefreshing];
}
#pragma mark ————— 初始化页面 —————
-(void)setupUI{
    //添加导航栏按钮
    [self addNavigationItemWithTitles
     :@[@"粒子动画"] isLeft:NO target:self action:@selector(naviBtnClick:) tags:@[@1000]];
    
    //设置瀑布流布局
    WaterFlowLayout *layout = [WaterFlowLayout new];
    layout.columnCount = 2;
    layout.sectionInset = UIEdgeInsetsZero;
    layout.rowMargin = 10;
    layout.columnMargin = 10;
    layout.delegate = self;
    
    [self.collectionView setCollectionViewLayout:layout];
    self.collectionView.backgroundColor = KGrayColor;
    [self.collectionView registerClass:[WaterFallCollectionViewCell class] forCellWithReuseIdentifier:NSStringFromClass([WaterFallCollectionViewCell class])];
    self.collectionView.delegate = self;
    self.collectionView.dataSource = self;
    [self.view addSubview:self.collectionView];
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

#pragma mark ————— 数据拉取完成 渲染页面 —————
-(void)requestDataCompleted{
    [self.collectionView.mj_footer endRefreshing];
    [self.collectionView.mj_header endRefreshing];
    
    [UIView performWithoutAnimation:^{
        [self.collectionView reloadData];
    }];

}

#pragma mark ————— collection代理方法 —————
-(NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView{
    return 1;
}

-(NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section{
    return _logic.dataArray.count;
}


-(UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath{
    WaterFallCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:NSStringFromClass([WaterFallCollectionViewCell class]) forIndexPath:indexPath];
    cell.imageName = _logic.dataArray[indexPath.row];

    return cell;
}

#pragma mark ————— layout 代理 —————
-(CGFloat)waterFlowLayout:(WaterFlowLayout *)WaterFlowLayout heightForWidth:(CGFloat)width andIndexPath:(NSIndexPath *)indexPath{
    UIImage *img = IMAGE_NAMED(_logic.dataArray[indexPath.row]);
    
    return img.size.height * itemWidthHeight / img.size.width;
}

//*******重写的时候需要走一句话
-(void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
    //标记cell
    [self.collectionView setCurrentIndexPath:indexPath];
    SecondViewController *secondVC = [SecondViewController new];
    secondVC.photoImg = IMAGE_NAMED(_logic.dataArray[indexPath.row]);
    [self.navigationController pushViewController:secondVC animated:YES];
    //    CellParticularController * con = [CellParticularController new];
    //    [self.navigationController pushViewController:con animated:YES];
}
#pragma mark ————— 转场动画起始View —————
-(UIView *)targetTransitionView{
    NSIndexPath * indexPath = [self.collectionView currentIndexPath];
    UIView* fromCellView =[self.collectionView cellForItemAtIndexPath:indexPath];
    return fromCellView;
}

-(BOOL)isNeedTransition{
    return YES;
}


-(void)naviBtnClick:(UIButton *)btn{
    [self.navigationController pushViewController:[HomeViewController new] animated:YES];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
