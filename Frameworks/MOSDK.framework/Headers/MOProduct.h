#import <Foundation/Foundation.h>
#import "Jsonable.h"


@interface MOProduct
    : NSObject <Jsonable>

+ (MOProduct*) fromJSON : (MOProduct*)a dic : (NSDictionary*)dic;

- (id) initWithDetail : (__int64_t)iid
                 name : (NSString*)name
              channel : (NSString*)channel
               locale : (NSString*)locale
                title : (NSString*)title
                 desc : (NSString*)desc
                price : (NSString*)price
              curCode : (NSString*)curCode
               curSym : (NSString*)curSym
              priceAM : (__int64_t)priceAM;

/**
 * 获取魔亚平台内部商品标识。
 *
 * @brief 辅助函数。
 *
 * @return 内部商品标识。
 */
- (__int64_t) getId;

/**
 * 获取支付通道商品标识。
 *
 * @brief 辅助函数。
 *
 * @return 支付通道商品标识。
 */
- (NSString*) getName;

/**
 * 获取支付通道标识。
 *
 * @return 支付通道标识。要
 */
- (NSString*) getChannel;

- (NSString*) getLocale;
- (NSString*) getTitle;
- (NSString*) getDesc;
- (NSString*) getPrice;
- (NSString*) getCurrencyCode;
- (NSString*) getCurrencySymbol;
- (__int64_t) getPriceAmountMicros;

- (NSDictionary*) toJSON : (NSDictionary*)parent
                    json : (NSDictionary*)json;
- (NSString*) toJSONString;
@end  // MOProduct
