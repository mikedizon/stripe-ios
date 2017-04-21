//
//  STPAnalyticsClient.h
//  Stripe
//
//  Created by Ben Guo on 4/22/16.
//  Copyright © 2016 Stripe, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class STPPaymentConfiguration, STPToken;
@protocol STPFormEncodable;

@interface STPAnalyticsClient : NSObject

+ (instancetype)sharedClient;

+ (void)initializeIfNeeded;

+ (void)disableAnalytics;

+ (NSString *)muid;

+ (NSString *)tokenTypeFromParameters:(NSDictionary *)parameters;

- (void)logTokenCreationAttemptWithConfiguration:(STPPaymentConfiguration *)configuration
                                       tokenType:(NSString *)tokenType;

- (void)logSourceCreationAttemptWithConfiguration:(STPPaymentConfiguration *)configuration
                                       sourceType:(NSString *)sourceType;

- (void)logRUMWithToken:(STPToken *)token
          configuration:(STPPaymentConfiguration *)config
               response:(NSHTTPURLResponse *)response
                  start:(NSDate *)startTime
                    end:(NSDate *)endTime;

@end
