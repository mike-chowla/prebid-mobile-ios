/*   Copyright 2017 APPNEXUS INC
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import "PBBidManager.h"
#import "PBLogging.h"
#import <UIKit/UIKit.h>

@class PBAdUnit;

@interface PrebidMobile : NSObject

/**
 * DEPRECATED: This method allows the developer to register the ad units created for Prebid Mobile
 * @param adUnits : Array of AdUnits that can be registered
 * @param accountId : Prebid server accountId
 */
+ (void)registerAdUnits:(nonnull NSArray<PBAdUnit *> *)adUnits withAccountId:(nonnull NSString *)accountId __deprecated;

/**
 * This method allows the developer to register the ad units created for Prebid Mobile
 * @param adUnits : Array of AdUnits that can be registered
 * @param accountId : Prebid server accountId
 * @param adServer : Primary ad server - needed to determine optimal bid caching
 */
+ (void)registerAdUnits:(nonnull NSArray<PBAdUnit *> *)adUnits
          withAccountId:(nonnull NSString *)accountId
     andPrimaryAdServer:(PBPrimaryAdServerType)adServer;

+ (void)setBidKeywordsOnAdObject:(nonnull id)adObject withAdUnitId:(nonnull NSString *)adUnitId;

+ (void)setBidKeywordsOnAdObject:(nonnull id)adObject
                    withAdUnitId:(nonnull NSString *)adUnitIdentifier
                     withTimeout:(int)timeoutInMilliseconds
               completionHandler:(nullable void (^)(void))handler;


@end
