//
//  MOUser.h
//  MOSDK
//
//  Created by Jack on 16/3/18.
//  Copyright © 2016年 Morlia. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger,MOAccountLevel)
{
    MOAccountLevelNone = 0,
    MOAccountLevelOne = 1 << 0,//游客账号
    MOAccountLevelTwo = 1 << 1,//gamecenter 账号或者 游客账号绑定了gamecenter 账号
    MOAccountLevelThree = 1 << 2 //普通账号，gamecenter账号绑定普通账号，游客账号同时绑定了gamecenter和普通账号
};

@interface MOUser
    : NSObject
// 绑定的账号
@property(nonatomic, copy) NSString *bindedAccount;

//绑定的第三方账号
@property(nonatomic, copy) NSString *thirdAccountType;

- (MOAccountLevel)getUserAccountLevel;

/**
 * @brief 初始化方法。
 *
 * @param aID 用户ID
 * @param aName 用户名
 * @param aToken 用户登录符号
*
 * @return 已初始化好的 MOUser 实例对象
 */
- (id) initWithDetail : (NSNumber*)aID name : (NSString*)aName token : (NSString*)aToken;


/**
 * @brief 初始化方法。
 *
 * @param aID      用户ID
 * @param aName     用户名
 * @param aToken    用户登录符号
 * @param aDevice   设备标识
 * @param aIsGuest  是否为游客账号
 * @param aFacebook Facebook 用户 ID
 * @param aGoogle   Google 用户 ID
 *
 * @return 已初始化好的 MOUser 实例对象
 */
- (id) initWithDetail : (NSNumber*)aID
                 name : (NSString*)aName
                token : (NSString*)aToken
               device : (NSString*)aDevice
              isGuest : (BOOL)aIsGuest
             facebook : (NSString*)aFacebook
               google : (NSString*)aGoogle
            modifiers : (int)aModifiers;

/**
 * @brief 获取用户 ID。
 *
 * @return 用户 ID 字符串
 */
- (NSNumber*) getID;

/**
 * @brief 获取用户名。
 *
 * @return 用户名字符串
 */
- (NSString*) getName;


- (BOOL) isThirdAccount;

- (BOOL) isThirdAccountBounded;

/**
 * @brief 获取用户登录符号。
 *
 * @return 用户登录符号字符串
 */
- (NSString*) getToken;

/**
 * @brief 获取设备标识
 *
 * @return 设备标识
 */
- (NSString*) getDevice;

/**
 * @brief 是否为游客账号。
 *
 * @return YES 游客账号，NO 魔亚账号或第三方账号
 */
- (BOOL) isGuestAccount;

//是否是gamecenter 账号登陆
- (BOOL) isGcAccount;

//是否是Google 账号
- (BOOL) isGoogleAccount;

/**
 * @brief 是否为快速账号（Google/Facebook/...）。
 *
 * @return YES 快速账号，NO 魔亚账号或游客账号
 */
- (BOOL) isQuickAccount;

/**
 * @brief 获取本地化处理过的用户名（\@"游客 [123]"/\@"Guest [123]"）。
 *
 * @return 本地化用户名字符串
 */
- (NSString*) getDisplayName;

/**
 * @brief 是否是Facebook 账号。
 *
 * @return YES ，NO
 */
- (BOOL) isMIsFacebookAccount;

/**
 * @brief 获取 Facebook 账号用户ID。
 *
 * @return Facebook 账号用户ID（15位数字）
 */
- (NSString*) getFacebookID;



/**
 * @brief 获取 Google 账号用户ID。
 *
 * @return Facebook 账号用户ID（21位数字）
 */
- (NSString*) getGoogleID;

/**
 * @brief 设置修饰信息
 *
 * @param aModifiers 修饰信息
 */
- (void) setModifiers : (int)aModifiers;

/**
 * @brief 获取修饰信息
 *
 * @return 修饰信息
 */
- (int) getModifiers;

@end  // MOUser
