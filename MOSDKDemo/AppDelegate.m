//
//  AppDelegate.m
//  MOSDKDemo
//
//  Created by Jack on 16/3/18.
//  Copyright © 2016年 Morlia. All rights reserved.
//

#import "AppDelegate.h"



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
    [[MO instance] appDidFinishLaunching : aApp options : aOptions];
    
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
    [[MO instance] appEnterBackground];
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
    [[MO instance] appBecomeActive];
}

- (void) applicationWillTerminate : (UIApplication*)aApp
{
}

- (BOOL) application : (UIApplication*)aApp openURL:(nonnull NSURL*)aURL sourceApplication : (nullable NSString*)aSourceApp annotation : (nonnull id)aAnnotation
{
    /**
     * 魔亚平台接入
     *
     * 应用访问。
     */
    [[MO instance] appOpenURL : aApp
                          url : aURL
                    sourceApp : aSourceApp
                   annotation : aAnnotation];
    return YES;
}


@end  // AppDelegate
