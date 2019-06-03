#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JYCWindow.h"


typedef enum
{
    DLActivityModelTwo,
    DLActivityModelThree
}DLActivityModel;

typedef enum{
    DLMorliaActivityTypeFacebookLike,//facebook 点赞
    DLMorliaActivityTypeFacebookShare,//facebook 分享
    DLMorliaActivityTypeFacebookInvite,//facebook 邀请
    DLMorliaActivityTypeCommentary, //评分活动
    DLMorliaActivityTypeOther//未知
} DLMorliaActivityType;




@class MOError;
@class MOUser;
@class MOGameUser;
@protocol MOInitDelegate;
@protocol MODelegate;
@protocol MOTradeDelegate;
@protocol MOActivityDelegate;
@protocol MOGameControlDelegate;
@class MOProduct;
@protocol MOAccountManagerDelegate;

/**
 * 魔亚主要功能接口，包括：应用注册、用户登录、在线定单等。
 *
 * @brief 魔亚接口
 */
@interface MO
    : NSObject <MOFloatWindowDelegate>

/**
 * @brief 获取 MO 单例对象。
 *
 * @return MO 单例。
 */
+ (MO*) instance;


+ (void) wdl_uploadUserInforWithSeversName:(NSString*)serversName
                              roleName:(NSString*)roleName;

/**
 * @brief 获取 MOSDK 版本号
 *
 * @return MOSDK 版本号。
 */
+ (NSString*) getSDKVersion;

/**
 * @brief 判断用户是否安装了 MO 客户端。
 *
 * @return YES 代表用户安装了魔亚客户端，NO 则反之。
 */
+ (BOOL) isMOInstalled;


/**
 * @brief 设置 SDK 的语言环境
 *
 * 例：设置简体中文
 * [MO setSDKLanguage : \@"zh-Hans"];
 *
 * @param aLang 语言编码（例：英语[\@"en"]、简体中文[\@"zh-Hans"]、繁体中文[\@"zh-Hant"]）。
 */
+ (void) setSDKLanguage : (NSString*)aLang;

/**
 * @brief 获取 SDK 的语言环境
 *
 * @return 语言编码（例：简体中文[\@"zh-Hans"]）。
 */
+ (NSString*) getSDKLanguage;

// SDK 设置的语言
+ (NSString*) getSDKSetUpLanguage;

/**
 * @brief 获取 SDK 的支持的语言列表
 *
 * @return SDK 支持的语言编码数组。
 */
+ (NSArray*) getSDKLanguages;

- (void)setShouldSendSyncrequest:(BOOL)shouldSendSyncrequest;
/**
 * 您需要在使用其他 SDK 任意接口前，首先调用此接口来完成相关信息配置。
 * 如果参数第一次配置好之后，视图尝试再次配置是无效的；
 * 如果第一次配置失败，可重新配置。
 *
 * @brief SDK接入配置接口，必接。
 */
+ (void) init : (id<MOInitDelegate>)delegate domainName:(NSString*)aDomainName portNumber:(NSInteger)aPortNumber;

/**
 * 在 AppDelegate 中实现 `application:didFinishLaunchingWithOptions:` 协议，并调用此特定接口。
 *
 * @brief           SDK 配置的特定接口，调用时机是app进入前台时；必接
 *
 * @param aApp      iOS 应用对象实例，来源 AppDelegate。
 * @param aOptions  启动应用时，传递的启动参数，来源 AppDelegate。
 */
- (BOOL) appDidFinishLaunching : (UIApplication*)aApp
                       options : (NSDictionary*)aOptions;

/**
 * 在 AppDelegate 中实现 `applicationDidBecomeActive:` 协议，并调用此特定接口。
 *
 * @brief SDK 配置的特定接口，调用时机是app进入前台时；必接
 */
- (void) appBecomeActive;

/**
 * 在 AppDelegate 中实现 `applicationDidEnterBackground:` 协议,并调用此特定接口。
 *
 * @brief SDK 配置的特定接口，调用时机是app进入后台时；必接
 */
- (void) appEnterBackground;


/**
 * 使用此接口时,应该首先在AppDelegate中实现`application:openURL:sourceApplication:annotation:`协议.
 * 在其实现中调用此接口来处理魔亚客户端授权跳回或者支付宝快捷支付端等跳转到app的事件。
 *
 * @brief 处理外部程序跳转到app的url;必接.
 *
 * @param aApp          iOS 应用对象实例，来源 AppDelegate。
 * @param aURL          打开的 URL 资源地址。
 * @param aSource       发出请求的原应用 ID。
 *
 */
- (BOOL) appOpenURL : (UIApplication*)aApp
                         url : (NSURL*)aURL
                   sourceApp : (NSString*)aSource
                  annotation : (id)aAnnotation;

#if __IPHONE_OS_VERSION_MAX_ALLOWED > __IPHONE_9_0

- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
            options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;
#endif

//自动登录
- (void) automaticLoginWithDelegate : (id<MODelegate>)aDelegate ViewController:(UIViewController*)vc;

//账户管理
- (void) showAccountManagerCenter: (UIViewController*)aVC;
/**
 * SDK 唯一的登录接口。
 * 只有在登录后，才能调用 SDK 其他功能接口。
 * 登录成功或失败后的回调见协议：｀MODelegate`。
 *
 * @brief 登录接口。
 *
 * @param aDelegate 实现 'MODelegate' 协议的 delegate 对象.
 * @param aVC       负责弹出登录视图的视图控制器。（确保在SDK使用期间该对象不会被释放）
 */
- (void) loginWithDelegate : (id<MODelegate>)aDelegate vc : (UIViewController*)aVC;

- (void) viewDidAppearWithMainViewController: (UIViewController*)mainViewController delegate:(id<MOInitDelegate>)delegate;

/**
 * 注销当前登录状态。
 *
 * @brief 注销
 */
- (void) logout;

/**
 * 获取当前登录用户的用户信息。
 *
 * @brief   获取用户信息
 *
 * @return  返回用户信息 MOUser 对象。
 */
- (MOUser*) getUser;

//morlia 活动回调的代理
- (void) setActivityDelegate:(id<MOActivityDelegate>)delegate;

- (void) setGameControlDelegate: (id<MOGameControlDelegate>)delegate;

/**
 * 设置支付回调 'MOTradeDelegate' 协议。
 *
 * @brief   设置支付回调接口。
 *
 * @param   aDelegate 支付回调接口。
 */
- (void) setTradeDelegate : (id<MOTradeDelegate>)aDelegate;

/**
 * 接口为异步请求操作，回调方法见'MOTradeDelegate'协议。
 *
 * @brief   请求支付通道的商品列表。
 */
- (void) requestProducts;

/**
 * 当前苹果用户是否可以提交支付。
 *
 * @brief   支付开启状态
 *
 * @return YES 表示可以支付，NO 表示用户关闭了支付通道。
 */
- (BOOL) canProcessPayments;

/**
 * 正在处理支付流程。
 *
 * @brief   支付状态
 *
 * @return YES 表示正在支付，NO 表示没有在处理支付流程。
 */
- (BOOL) isProcessPayments;

/**
 * 接口为异步请求操作，回调方法见'MDKTradeDelegate'协议。
 *
 * aParams附加参数说明：
 * @{
 *      @"server" : @"201",     // 服务器名称
 *        @"role" : @"ABC",     // 角色名称
 *      @"extra1" : @"xxx",     // 附加参数1
 *      @"extra2" : @"yyy"      // 附加参数2
 * }
 *
 * @brief   购买苹果商品，并传入外部交易号。
 *
 * @param   aProduct    要购买的商品；
 * @param   aParams     附加参数。
 */
- (void) buyProduct : (MOProduct*)aProduct params : (NSDictionary*)aParams;


/**
 *
 * @{
 *      @"server" : @"201",     // 服务器名称
 *        @"role" : @"ABC",     // 角色名称
 *       @"extra" : @"xxx",     // 附加参数
 * }
 */
- (void) submitPlayerInfo : (NSDictionary*)dir;

/**
 * @brief   显示facebook面板
 *
 */
- (void) showSnsView : (UIViewController*)vc;

- (void) showActivityViewWithViewController:(UIViewController*)vc activityType:(DLActivityModel)activityType;

/**
 显示常见问题

 @param ViewController 发起调用的视图控制器
 */
- (void) showFAQs:(UIViewController*)ViewController;

/**
 发起会话

 @param ViewController 发起调用的视图控制器
 */
- (void) showConversation:(UIViewController*)ViewController;

/**
 储值活动
 
 @param viewController 发起调用的视图控制器
 */
- (void) showStoredValue:(UIViewController*)viewController;

/**
 显示悬浮窗
 
 @param viewController 发起调用的视图控制器
 */
- (void) showFloatWindowWithViewController:(UIViewController*)viewController;

//统计事件
- (void)selectGameServerEvent;//选择游戏服务器
- (void)createRloeEvent;//创建角色
- (void)throughTheNoviceTutorialEvent;//通过新手教程
/**
 自定义统计事件
@param eventName 事件名称,建议使用小写字母
 */
- (void) customEventWithEventName:(NSString*)eventName;// 自定义事件
@end  // MO

/**
 * 'MOInitDelegate' 协议，声明了初始化成功和失败的回调接口。
 *
 * @brief 魔亚平台初始化回调接口
 */
@protocol MOInitDelegate <NSObject>
@required

- (void) initSuccess : (MO*)mo;
- (void) initFailure : (MOError*)error;

@end  // MOInitDelegate


/**
 * 'MODelegate' 协议，声明了登陆成功和失败的回调接口，所有协议方法都是可选的。
 *
 * @brief 魔亚登录回调接口
 */
@protocol MODelegate <NSObject>
@optional

/**
 * @brief 用户取消登陆后的回调.
 *
 */
- (void) loginCancelled;

/**
 * 开发者必须在登录成功的回调方法里,传入'MDKTrade'单例的delegate对象,并且此delegate是已经实现了'MDKTradeDelegate'协议.
 这样要求是因为,如果IAP时程序异常退出,并且支付成功,程序重启登录后能立即捕获到IAP恢复订单的通知,可有效避免异常调单.
 *
 * @brief 登陆成功后的回调.
 *
 * @param aUser     包含用户信息的 MOUser 对象。
 */
- (void) loginSuccess : (MOUser*)aUser;

/**
 * @brief 登陆失败后的回调.
 *
 * @param aError 包含错误信息的 MOError对象.
 */
- (void) loginFailed : (MOError*)aError;

/**
 * 注销回调的情况：
 * 用户主动调用注销；
 * CP 主动调用注销；
 * 用户账号重复登录。
 *
 * @brief SDK 完成注销的回调。
 */
- (void) logoutDidFinish;

@end  // MODelegate

// 正式服务器和测试服务器切换j控制策略
@protocol MOGameControlDelegate <NSObject>
//切换到测试服回调
- (void) shouldGoToTestServer:(MOUser*)user;
//切换到正式服回调
- (void) shouldGoToOfficialServer:(MOUser*)user;
@end


/**
 * 'MOTradeDelegate'协议，声明了一组苹果交易的回调接口，必须实现协议中的所有方法。
 *
 * @brief 魔亚支付回调接口
 */
@protocol MOTradeDelegate <NSObject>
@required
/**
 * @brief   请求商品成功的回调
 *
 * @param   aProducts 请求到的商品数组，数组元素为 MOProduct 对象。
 */
- (void) requestProductsSuccess : (NSArray<MOProduct*>*)aProducts;

/**
 * @brief   请求商品失败的回调
 *
 * @param   aError 描述错误信息的 MOError 对象。
 */
- (void) requestProductsFailed : (MOError*)aError;

/**
 * 此时账单已提交至魔亚服务器。
 *
 * @brief   完成购买商品的回调
 *
 * @param   args 相关参数。
 *
 * @{
 *        @"order" : @"123456"                      // 定单编号
 *      @"product" : @"com.morlia.pay.product1",    // 商品标识
 * }
 */
- (void) buyProductDidFinish : (NSDictionary*)args;

/**
 * @brief   购买商品失败的回调
 *
 * @param   aError 描述错误信息的 MOError 对象。
 */
- (void) buyProductFailed : (MOError*)aError;


@end  // MOTradeDelegate




@protocol MOActivityDelegate <NSObject>

@optional

- (void) activityCallBack:(DLMorliaActivityType)MorliaActivityType activityStatus:(BOOL)status infor:(NSDictionary*)infor;


@end

@protocol MOAccountManagerDelegate <NSObject>

@optional
- (void) userDidSwitchToAccount:(MOUser*)account fromAccuont:(MOUser*)fromAccuont;
- (void) userDidBindToAccount:(MOUser*)account;

@end


