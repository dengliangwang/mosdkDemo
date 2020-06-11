//
//  DLCafe.h
//  HYSDK
//
//  Created by dengliang.wang on 2020/6/9.
//  Copyright © 2020 morlia. All rights reserved.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface DLCafe : NSObject

- (void)cafeSdkInit:(NSString*)cafeId clientId:(NSString*)clientId clientSecert:(NSString*)clientSecert;
- (void)cafeSdkSetParentViewController:(UIViewController*) parentViewController;
- (void)cafeSdkPresentMainViewController;

- (void)cafeSdkDismissMainViewController;

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

@end

NS_ASSUME_NONNULL_END
