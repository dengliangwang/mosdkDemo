#import <Foundation/Foundation.h>

@interface PTItem : NSObject <NSCoding>

@property (nonatomic, retain) NSString *identifier;

// Production Parameters
@property (nonatomic, retain) NSString *item_name;
@property (nonatomic, retain) NSNumber *item_num;
@property (nonatomic, retain) NSNumber *item_price;
@property (nonatomic, retain) NSString *item_price_currency;

// Other Paramters
@property (nonatomic, retain) NSString *achievement;
@property (nonatomic, retain) NSString *content_type;
@property (nonatomic, retain) NSString *level_value;
@property (nonatomic, retain) NSString *max_rating_value;
@property (nonatomic, retain) NSString *payment_info;
@property (nonatomic, retain) NSString *rating_value;
@property (nonatomic, retain) NSString *registration_method;
@property (nonatomic, retain) NSString *search_string;
@property (nonatomic, retain) NSString *virtual_currency;
@property (nonatomic, retain) NSString *virtual_currency_price;

- (PTItem *) initWithAttributes:(NSDictionary *)attributes;
- (NSDictionary *) toNSDictionary;

@end