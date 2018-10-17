//
//  Jsonable.h
//  MOSDK
//
//  Created by jack on 2017/4/12.
//  Copyright © 2017年 Morlia. All rights reserved.
//

#ifndef Jsonable_h
#define Jsonable_h

@protocol Jsonable <NSObject>
@required

- (NSDictionary*) toJSON : (NSDictionary*)parent
                    json : (NSDictionary*)json;

- (NSString*) toJSONString;

@end  // Jsonable

#endif /* Jsonable_h */
