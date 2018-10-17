//
//  ViewController.h
//  MOSDKDemo
//
//  Created by Jack on 16/3/18.
//  Copyright © 2016年 Morlia. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MOSDK/MOSDK.h>


/**
 * 魔亚平台接入
 *
 * MODelegate       登录回调接口
 * MOTradeDelegate  支付回调接口
 */

@interface ViewController
    : UIViewController<MODelegate, MOTradeDelegate>


@end  // ViewController
