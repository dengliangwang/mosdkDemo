//
//  PTSenderDelegate.h
//  partytrack
//
//  Created by Jamie on 12/3/12.
//  Copyright (c) 2012 adways. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PTSenderDelegate <NSObject>

- (void) processResponseWithData:(NSData *)data AndError:(NSError *)error;

@end
