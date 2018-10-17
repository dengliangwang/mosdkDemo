//
//  MOUser.h
//  MOSDK
//
//  Created by Jack on 16/10/18.
//  Copyright © 2016年 Morlia. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface MOGameUser
    : NSObject


/**
 * @brief 初始化方法。
 *
 * @param aUserId      用户ID
 * @param aServerId    服务器ID
 * @param aLocale      语言
 *
 * @return 已初始化好的 MOGameUser 实例对象
 */
- (id) initWithDetail : (NSString*)aUserId
             serverId : (NSString*)aServerId
              tlocale : (NSString*)aLocale
              extra   : (NSString*)aExtra;

- (NSString*) getUserId;
- (NSString*) getServerId;
- (NSString*) getLocale;
- (NSString*) getExtra;

@property(copy, nonatomic) NSString*    mUserId;
@property(copy, nonatomic) NSString*    mServerId;
@property(copy, nonatomic) NSString*    mLocale;
@property(copy, nonatomic) NSString*    mExtra;

@end  // MOUser
