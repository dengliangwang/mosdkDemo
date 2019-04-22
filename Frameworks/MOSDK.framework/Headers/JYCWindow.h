//
//  JYCWindow.h
//  HOUNOLVJU
//
//  Created by 蒋永昌 on 9/24/16.
//  Copyright © 2016 蒋永昌. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    floatWindowActionUserCenter,
    floatWindowActionFacebook,
    floatWindowActionCommentaryActivities,
    floatWindowActionAnnouncement,
    floatWindowActionCustomerService,
    floatWindowActionStoredValue,
    floatWindowActionUnkown
} floatWindowAction;


typedef void(^CallTheService)(floatWindowAction action);

typedef NS_ENUM(NSInteger,MOViewControllerLifeCycle) {
    MOViewControllerLifeCycleWillAppear,
    MOViewControllerLifeCycleWillDisappear
};

typedef void(^ViewControllerLifeCycle)(floatWindowAction action,MOViewControllerLifeCycle lifeCycle);

typedef NS_ENUM(NSUInteger, ExpansionDirection) {
    DirectionLeft = 0,
    DirectionRight,
    DirectionUp,
    DirectionDown
};



@protocol MOFloatWindowDelegate <NSObject>

@optional
- (void) FloatWindowWillShow;
- (void) FloatWindowDidShow;
- (void) FloatWindowWillShowItemContent:(floatWindowAction) action;
- (void) FloatWindowDidDisappearItemContent:(floatWindowAction) action;

@end

@class JYCWindow;

@protocol JYCWindowDelegate <NSObject>

@optional
- (void)bubbleMenuButtonWillExpand:(JYCWindow *)expandableView;
- (void)bubbleMenuButtonDidExpand:(JYCWindow *)expandableView;
- (void)bubbleMenuButtonWillCollapse:(JYCWindow *)expandableView;
- (void)bubbleMenuButtonDidCollapse:(JYCWindow *)expandableView;

@end

static NSString * const mosdk_floatwindow_expand_lock_status = @"mosdk_floatwindow_expand_lock_status";

@interface JYCWindow : UIWindow

@property (nonatomic, readonly) BOOL isCollapsed;

@property (nonatomic, weak) id <JYCWindowDelegate> delegate;

@property(nonatomic, weak) id<MOFloatWindowDelegate> moDelegate;

// The duration of the expand/collapse animation
@property (nonatomic) float animationDuration;

// The direction in which the menu expands
@property (nonatomic) enum ExpansionDirection direction;

// The spacing between menu buttons when expanded
@property (nonatomic) float buttonSpacing;

// Indicates whether the home button will animate it's touch highlighting, this is enabled by default
@property (nonatomic) BOOL animatedHighlighting;

// Indicates whether menu should collapse after a button selection, this is enabled by default
@property (nonatomic) BOOL collapseAfterSelection;

// The default alpha of the homeButtonView when not tapped
@property (nonatomic) float standbyAlpha;

// The highlighted alpha of the homeButtonView when tapped
@property (nonatomic) float highlightAlpha;


//重要：所有图片都要是圆形的，程序里并没有自动处理成圆形

//  warning: frame的长宽必须相等
- (instancetype)initWithFrame:(CGRect)frame mainImageName:(NSString*)name bgcolor:(UIColor *)bgcolor;

// 长按雷达辐射效果
- (instancetype)initWithFrame:(CGRect)frame mainImageName:(NSString*)name bgcolor:(UIColor *)bgcolor animationColor:animationColor;

// 显示（默认）
- (void)showWindow;

// 隐藏
- (void)dissmissWindow;

- (void) makeMainWindowMakeKeyWindow;

@property (nonatomic,copy)CallTheService callService;
@end
