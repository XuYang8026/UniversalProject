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

#define itemWidthHeight ((kScreenWidth-10)/2)

@interface WaterFallListViewController ()<UICollectionViewDelegate,UICollectionViewDataSource,WaterFlowLayoutDelegate,XYTransitionProtocol>

PropertyNSMutableArray(dataArray);//数据源
@end

@implementation WaterFallListViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    _dataArray = @[].mutableCopy;
    [self setupUI];
    
    [self.collectionView.mj_header beginRefreshing];
}
#pragma mark ————— 初始化页面 —————
-(void)setupUI{
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
#pragma mark ————— 拉取数据 —————
-(void)loadData{
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{

        for (int i = 0; i < 14; i++) {
            
            NSString *imageName = NSStringFormat(@"%d.jpg", i);
            
            [_dataArray addObject:imageName];
        }
        [self.collectionView.mj_footer endRefreshing];
        [self.collectionView.mj_header endRefreshing];

        [UIView performWithoutAnimation:^{
            [self.collectionView reloadData];
        }];
    });
}

#pragma mark ————— 下拉刷新 —————
-(void)headerRereshing{
    [_dataArray removeAllObjects];
    [self loadData];
}

#pragma mark ————— 上拉刷新 —————
-(void)footerRereshing{
    [self loadData];
}

#pragma mark ————— collection代理方法 —————
-(NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView{
    return 1;
}

-(NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section{
    return _dataArray.count;
}


-(UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath{
    WaterFallCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:NSStringFromClass([WaterFallCollectionViewCell class]) forIndexPath:indexPath];
    cell.imageName = _dataArray[indexPath.row];

    return cell;
}

#pragma mark ————— layout 代理 —————
-(CGFloat)waterFlowLayout:(WaterFlowLayout *)WaterFlowLayout heightForWidth:(CGFloat)width andIndexPath:(NSIndexPath *)indexPath{
    UIImage *img = IMAGE_NAMED(_dataArray[indexPath.row]);
    
    return img.size.height * itemWidthHeight / img.size.width;
}

//*******重写的时候需要走一句话
-(void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
    //pinterest需要的效果
    [self.collectionView setCurrentIndexPath:indexPath];
    SecondViewController *secondVC = [SecondViewController new];
    secondVC.photoImg = IMAGE_NAMED(_dataArray[indexPath.row]);
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

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
