//
//  ViewController.m
//  MOSDKDemo
//
//  Created by Jack on 16/3/18.
//  Copyright © 2016年 Morlia. All rights reserved.
//

#import "ViewController.h"
#import <StoreKit/StoreKit.h>
#import "AppDelegate.h"


@interface ViewController ()<HYInitDelegate,HYLoginDelegate,HYTradeDelegate>

@property (weak, nonatomic) IBOutlet UIButton*  mLogin;
@property (weak, nonatomic) IBOutlet UIButton*  mLogout;
@property (weak, nonatomic) IBOutlet UIButton*  mRequest;
@property (weak, nonatomic) IBOutlet UIButton*  mPurchase;
@property (weak, nonatomic) IBOutlet UIButton*  mFacebook;
@property (weak, nonatomic) IBOutlet UILabel*   mUsername;
@property (weak, nonatomic) IBOutlet UIButton *mUserCenterBtn;
@property (strong, nonatomic) UIColor*          mColor1;
@property (strong, nonatomic) UIColor*          mColor2;

@property (copy, nonatomic) NSArray*            mProducts;

@property (weak, nonatomic) IBOutlet UIButton *FAQBTN;
@property (weak, nonatomic) IBOutlet UIButton *csvBtn;
- (IBAction)openCafe:(UIButton *)sender;

@end  // ViewController ()

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.mColor1 = [UIColor colorWithRed : 1.0f green : 0.675f blue : 0.11f alpha:1.0f];
    self.mColor2 = [UIColor colorWithRed : 0.625f green : 0.625f blue : 0.625f alpha:1.0f];
    
    /**
     * 魔亚平台接入
     *
     * setTradeDelegate
     * 设置支付回调 MOTradeDelegate，可多次设置，可设置不同的实例；
     */
    [[HY sharedInstance] setTradeDelegate:self];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    /**
     * 魔亚平台接入
     *
     * 第一步：初始化；
     */
    NSString *host = @"platformshios.kljunes.com";//SDK域名，运营处获取，此为示例域名
    NSInteger port = 443;//SDK请求端口，如无特殊需求，默认传入443
    [[HY sharedInstance] MOInitWithDelegate:self domainName:host portNumber:port];
    NSLog(@"[[HY sharedInstance] getSDKSetUpLanguage] = %@",[[HY sharedInstance] getSDKSetUpLanguage]);
}
- (IBAction) on : (id)aSender
{
    if (aSender == self.mLogin)
    {
        /**
         * 魔亚平台接入
         *
         * 第二步：魔亚平台登录入口；
         *
         * 登录成功会回调 self.loginSuccess
         * 登录失败会回调 self.loginFailed
         * 用户关闭登录会回调 self.loginCancelled
         */
       
    }
    else if (aSender == self.mLogout)
    {
        /**
         * 魔亚平台接入
         *
         * 用户主动注销当前登录
         * 注销成功会回调 self.logoutDidFinish
         */
        
    }
    else if (aSender == self.mRequest)
    {
        /**
         * 魔亚平台接入
         *
         * 第三步：请求产品信息列表，并显示在相应的用户界面；
         *
         * requestProducts
         * 发送产品信息查询
         * 查询成功会回调 self.requestProductsSuccess
         * 查询失败会回调 self.requestProductsFailed
         */
        [[HY sharedInstance] requestProducts];
    }
    else if (aSender == self.mPurchase)
    {
        if (nil == self.mProducts)
            return;
        
        /**
         * 魔亚平台接入
         *
         * 第四步：购买产品，并发放相应产品内容；
         *
         * buyProduct
         * 发送产品信息查询
         * 购买成功会回调 self.buyProductDidFinish
         * 购买失败会回调 self.buyProductFailed
         */
        NSMutableDictionary* aParams = [[NSMutableDictionary alloc] init];
        [aParams setValue : @"1000001" forKey : @"server"];
        [aParams setValue : @"lalala" forKey : @"role"];
        [aParams setValue : @"0" forKey : @"number"];
        [aParams setValue : @"xxx" forKey : @"extra1"];
        [aParams setValue : @"yyy" forKey : @"extra2"];
        [[HY sharedInstance] buyWithProduct:self.mProducts[0] params:aParams];
        
    }
    else if (aSender == self.mFacebook)
    {
        /**
         * 魔亚平台接入
         *
         * 调用 Facebook 分享界面；
         */
        
        [[HY sharedInstance] showSnsViewWithViewController:self];
        
       
    }
    else if (aSender == self.FAQBTN)
    {
        [[HY sharedInstance] showFAQs:self];
    }
    else if (aSender == self.csvBtn)
    {
        [[HY sharedInstance] showConversation:self];
       
    }
    else if (aSender == self.mUserCenterBtn){
        [[HY sharedInstance] showAccountManagerCenterWithViewController:self];
    }
}
    
// MODelegate
- (void) loginCancelled
{
    /**
     * 魔亚平台接入
     *
     * 用户关闭了登录视图，
     * CP方可在此退出游戏，
     * 或做其他逻辑处理。
     */

    NSLog(@"MOSDK Demo: loginCancelled");
}

- (void) exitApplication
{
    AppDelegate* aDele = [UIApplication sharedApplication].delegate;
    UIWindow* aWnd = aDele.window;
    
    [UIView animateWithDuration : 0.5f animations : ^
    {
        aWnd.alpha = 0.0f;
    }
    completion : ^(BOOL finished)
    {
        exit(0);
    }];
}

- (void)loginSuccess:(DLUser *)aUser{
    /**
     * 魔亚平台接入
     *
     * 用户登录成功，
     * 做相应逻辑处理。
     */
    
    /**
     *
     *
     */
    
    
    NSMutableDictionary* info = [[NSMutableDictionary alloc] init];
    [info setObject:@"2" forKey:@"server"];
    [info setObject:@"100" forKey:@"role"];
    [info setObject:@"Game Extra Info" forKey:@"extra"];
    
    [[HY sharedInstance] submitWithPlayerInfo:info];
    
    
    NSLog(@"MOSDK Demo: loginSuccess %@", [aUser getDisplayName]);
    
    UIColor* aCr1 = self.mColor1;
    UIColor* aCr2 = self.mColor2;
    
    [self.mLogin setEnabled : NO];
    [self.mLogin setBackgroundColor : aCr2];
    [self.mLogout setEnabled : YES];
    [self.mLogout setBackgroundColor: aCr1];
    [self.mRequest setEnabled : YES];
    [self.mRequest setBackgroundColor: aCr1];
    [self.mFacebook setEnabled : YES];
    [self.mFacebook setBackgroundColor: aCr1];
    [self.mUserCenterBtn setEnabled:YES];
    [self.mUserCenterBtn setBackgroundColor:aCr1];
    
    //MOUser* aUser = [[MO instance] getUser];
    [self.mUsername setText: [NSString stringWithFormat: @"%@", [aUser getDisplayName]]];
    
   
}

- (void)loginFailed:(NSError *)aError{
    //NSLog(@"MOSDK Demo: loginFailed %d:%@", (int)aError.mCode, aError.mMessage);
}
- (void)requestProductsSuccess:(NSArray<DLProduct *> *)aProduct{
    self.mProducts = aProduct;
        

        if (nil == self.mProducts
            || 0 == self.mProducts.count)
            //
            return;

        UIColor* aCr1 = self.mColor1;

        [self.mPurchase setEnabled : YES];
        [self.mPurchase setBackgroundColor : aCr1];
}

- (void)requestProductsFailed:(NSError *)aError{
    //NSLog(@"MOSDK Demo: requestProductsFailed %d:%@", (int)aError.mCode, aError.mMessage);

    UIColor* aCr2 = self.mColor2;
    
    [self.mPurchase setEnabled : NO];
    [self.mPurchase setBackgroundColor : aCr2];
}


- (void)buyProductSuccess:(NSDictionary<NSString *,id> *)aParam{
    NSLog(@"MOSDK Demo: buyProductDidFinish - %@", aParam);
}
- (void)buyProductFailed:(NSError *)aError
{
    // NSLog(@"MOSDK Demo: buyProductFailed %d:%@", (int)aError.mCode, aError.mMessage);
}

/**
 * 魔亚平台初始化成功
 */
- (void)initSuccess:(HY *)platform {
     [[HY sharedInstance] automaticLoginWithDelegate:self ViewController:self];
}

/**
* 魔亚平台初始化失败
*/
- (void)initFailure:(NSError *)error{
    NSLog(@"Demo error: %@", error);
}
- (IBAction)openCafe:(UIButton *)sender {
    [[HY sharedInstance] openCafeHome:self];
}
@end  // ViewController
