//
//  AppDelegate.m
//  MOSDKDemo
//
//  Created by Jack on 16/3/18.
//  Copyright © 2016年 Morlia. All rights reserved.
//

#import "AppDelegate.h"
#import <hysdk/hysdk-Swift.h>


@interface AppDelegate ()

@end  // AppDelegate ()


@implementation AppDelegate

- (BOOL) application : (UIApplication*)aApp didFinishLaunchingWithOptions : (NSDictionary*)aOptions
{
    
    
    /**
     * 魔亚平台接入
     *
     * 同步应用状态。
     */
    //[[MO instance] appDidFinishLaunching : aApp options : aOptions];
    [[HY sharedInstance] application:aApp didFinishLaunchingWithOptions:aOptions];
    
    return YES;
}

- (void) applicationWillResignActive:(UIApplication *)aApp
{
}

- (void) applicationDidEnterBackground : (UIApplication*)aApp
{
    /**
     * 魔亚平台接入
     *
     * 同步应用状态。
     */
    [[HY sharedInstance] applicationDidEnterBackground:aApp];
    
}

- (void) applicationWillEnterForeground : (UIApplication*)aApp
{
}

- (void) applicationDidBecomeActive:(UIApplication *)aApp
{
    /**
     * 魔亚平台接入
     *
     * 同步应用状态。
     */
    [[HY sharedInstance] applicationDidBecomeActive:aApp];

}

- (void) applicationWillTerminate : (UIApplication*)aApp
{
}

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options{
   return [[HY sharedInstance] application:app open:url options:options];
}



@end  // AppDelegate
