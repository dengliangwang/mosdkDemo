//
//  MOError.h
//  MOSDK
//
//  Created by Jack on 16/3/18.
//  Copyright © 2016年 Morlia. All rights reserved.
//

#import <Foundation/Foundation.h>


#define MOERROR_OK                  0

/**
 * @brief 网络错误
 */
#define MOERROR_NETWORK_ERROR       100100
/**
 * @brief 数据错误
 */
#define MOERROR_DATA_ERROR          100101
/**
 * @brief 内部错误
 */
#define MOERROR_INTERNAL_ERROR      100102
/**
 * @brief 参数错误
 */
#define MOERROR_ARGS_ERROR          100103
/**
 * @brief 未安装最新客户端
 */
#define MOERROR_CLIENT_ERROR        100104
/**
 * @brief 界面响应错误
 */
#define MOERROR_UI_RESP_ERROR       100105


/**
 * @brief 服务器返回错误
 */
#define MOERROR_SERVER_RET_ERROR    500200


@interface MOError
    : NSObject

/**
 * @brief 错误码.
 */
@property (assign, nonatomic) NSInteger mCode;

/**
 * @brief 错误信息.
 */
@property (copy, nonatomic) NSString* mMessage;

/**
 * @brief 初始化方法.
 *
 * @param aCode 错误码
 * @param aMessage 错误信息
 *
 * @return 完成初始化的MDKError实例对象
 */
- (id) initWithErrorCode : (NSInteger)aCode message : (NSString*)aMessage;

/**
 * 错误码是40200,错误信息是:无法连接到服务器.
 *
 * @brief 初始化方法.
 *
 * @return 完成初始化的MDKError实例对象.
 */
- (id) initWithNetworkError;

/*
 Error Code
 
 100***         程序相关
 200***         用户相关
 300***         支付相关
 400***         插件相关
 500***         服务器相关


 200100         还未登录
 200101         重复登录
 200102         授权失败，如token自动登录
 200103         用户取消授权
 200104         token 无效
 200105         token 过期
 
 300100         无可购买商品
 300101         请求商品错误
 300102         设备没有开启IAP
 300103         正在购买中
 300104         创建定单失败
 300105         完成定单失败

 300201         SKErrorUnknown 苹果交易未知错误
 300202         SKErrorClientInvalid 苹果交易客户端没有权限
 300203         SKErrorPaymentCancelled 苹果交易用户取消订单请求
 300204         SKErrorPaymentInvalid 苹果交易订单参数有误
 300205         SKErrorPaymentNotAllowed 苹果交易用户账号不被允许交易
 300206         SKErrorStoreProductNotAvailable 苹果交易请求的商品不可用
 300207         SKErrorCloudServicePermissionDenied 用户禁止检索云服务信息
 300208         SKErrorCloudServiceNetworkConnectionFailed 设备无法连接到云服务网络

 300301         谷歌交易取消
 300302         谷歌交易错误

 
 500101         连接苹果服务器错误
 500102         连接谷歌服务器错误

 */

@end  // MOError
