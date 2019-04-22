#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger,MO_Http_Method)
{

    MO_Http_Method_Error,
    MO_Http_Method_Get,
    MO_Http_Method_Post,
    MO_Http_Method_OPTIONS,
    MO_Http_Method_HEAD,
    MO_Http_Method_PUT,
    MO_Http_Method_DELETE,
    MO_Http_Method_TRACE,
    MO_Http_Method_CONNECT
};

//判断是是否是 //iPhoneX / iPhoneXS
#define isIphoneX_XS (CGSizeEqualToSize(CGSizeMake(375.f, 812.f), [UIScreen mainScreen].bounds.size) || CGSizeEqualToSize(CGSizeMake(812.f, 375.f), [UIScreen mainScreen].bounds.size))
// iPhoneXR / iPhoneXSMax
#define isIphoneXR_XSMax (CGSizeEqualToSize(CGSizeMake(414.f, 896.f), [UIScreen mainScreen].bounds.size) || CGSizeEqualToSize(CGSizeMake(896.f, 414.f), [UIScreen mainScreen].bounds.size))

//异性全面屏(是否具有齐刘海)
#define   isFullScreen    (isIphoneX_XS || isIphoneXR_XSMax)

// Status bar height.
#define  StatusBarHeight     (isFullScreen ? 44.f : 20.f)


@interface MOUtil
: NSObject


/**
 * 将 常规字符串 转换为 URL 格式的字符串。
 *
 * @brief 辅助函数。
 *
 * @param aStr 常规字符串。
 *
 * @return URL 格式的字符串。
 */
+ (NSString*) wdl_encodeURL : (NSString*)aStr;

/**
 * 将 URL 格式的字符串 转换为 常规字符串。
 *
 * @brief 辅助函数。
 *
 * @param aStr URL 格式的字符串。
 *
 * @return 常规字符串。
 */
+ (NSString*) wdl_decodeURL : (NSString*)aStr;


/**
 * 跳转到指定的 URL 地址。
 *
 * @brief 辅助函数。
 *
 * @param aURL URL 地址。
 *
 * @return YES 成功跳转，NO 跳转失败。
 */
+ (BOOL) wdl_openURL : (NSString*)aURL;

+ (UIViewController *)ViewControllerWithStoryBoardId:(NSString*)StoryBoardId;

/**
 发起异步网络请求

 @param RequestMethod 请求方法（GET/POST/HEADER...）。
 @param isHttps 是否是HTTPS请求
 @param host 服务器地址，域名或IP地址
 @param port 端口号 默认80
 @param urlString 服务器统一地址
 @param cmd 访问请求串 即 ？后面的请求数据
 @param data http body 数据
 @param completionHandler 回调block
 */
+ (void)wdl_sendAsynchronousHttpRequestWithRequestMethod:(MO_Http_Method)RequestMethod
                                             isHttps:(BOOL)isHttps
                                                host:(NSString*)host
                                                port:(int)port
                                           urlString:(NSString*)urlString
                                                 cmd:(NSString*)cmd
                                                data:(NSString*)data
                                   completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;

+ (void)wdl_sendAsynchronousHttpRequestWithHeaderEnanble:(BOOL)HeaderEnanble
                                       RequestMethod:(MO_Http_Method)RequestMethod
                                             isHttps:(BOOL)isHttps
                                                host:(NSString*)host
                                                port:(int)port
                                           urlString:(NSString*)urlString
                                                 cmd:(NSString*)cmd
                                                data:(NSString*)data
                                   completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;

+ (void) wdl_sendHttpRequestWithHttpMethod : (MO_Http_Method)httpMethod
                                   url : (NSURL*)url
                                  data : (NSString*)data
                      completionHandler:(nullable void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;

+ (void) wdl_sendHttpRequestWithHeaderEnable:(BOOL)HeaderEnable
                             HttpMethod : (MO_Http_Method)httpMethod
                                    url : (NSURL*)url
                                   data : (NSString*)data
                       completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/**
 * 获得字符串的 UTF8 字节序列的 MD5。
 *
 * @brief 辅助函数。
 *
 * @param aText 常规字符串。
 *
 * @return 小写格式的 MD5 字符串。
 */
+ (NSString *) wdl_digest : (NSString*_Nullable)aText;

+ (void) setOrientation : (UIInterfaceOrientation)aOrientation;


+ (NSDictionary*) wdl_fromJSONString : (NSString*)str;
+ (NSString*) wdl_toJSONString : (NSDictionary*)dic;

+ (NSString*) wdl_queryString : (NSDictionary*)params;
+ (NSString*) wdl_getSignSource : (NSDictionary*)params
                     secret : (NSString*)secret;
+ (NSString*) wdl_md5Sign : (NSDictionary*)params
               secret : (NSString*)secret;

+ (void) wdl_get : (NSURL*)url
          params : (NSDictionary*)params
          secret : (NSString*)secret
            data : (NSString*)data
completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;

+ (void)wdl_post : (NSURL*)url
          params : (NSDictionary*)params
          secret : (NSString*)secret
            data : (NSString*)data
completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;

+ (NSString*) wdl_getDeviceId;
+ (NSString*) wdl_getDeviceModel;
+ (NSString*) wdl_getPreferredLanguage;

+ (void) wdl_saveKeyData : (NSString*)service
                data : (id)data;
+ (id) wdl_loadKeyData : (NSString*)service;
+ (void) wdl_removeKeyData : (NSString*)service;

+ (NSString*) wdl_getIDFV;

+ (NSString*)getIDFA;

+ (NSString*)getStringFromUserDefaultsWithKey:(NSString*)key;
+ (BOOL)setStringDataToUserDefaultsWithValue:(NSString*)value key:(NSString*)key;


//+ (NSString*) getReceiptSignature;
+ (BOOL) wdl_validReceipt : (NSData*)receipt;

+ (NSDictionary*) wdl_parseURLParams : (NSString*)query
                        encoding : (NSStringEncoding)encoding;


+ (void)wdl_Model1RewardWithMorliaAppID:(NSString*)morliaAppID
                         activityId:(NSString*)activityId
                             userId:(NSNumber*)userid
                           gameRole:(NSString*)gameRole
                         gameServer:(NSString*)gameServer
                  completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;

+ (void)Model2RewardWithMorliaAppID:(NSString*)morliaAppID
                         activityId:(NSString*)activityId
                             userId:(NSNumber*)userid
                           gameRole:(NSString*)gameRole
                         gameServer:(NSString*)gameServer
                  completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;

@end  // MOUtil
