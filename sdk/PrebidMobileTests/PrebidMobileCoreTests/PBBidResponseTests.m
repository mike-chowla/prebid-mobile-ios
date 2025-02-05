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

#import "PBBidResponse.h"
#import <XCTest/XCTest.h>

@interface PBBidResponseTests : XCTestCase

@end

@implementation PBBidResponseTests

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)testBidResponseObject {
    NSDictionary *testAdServerTargeting = @{@"hb_pb":@"3.14", @"hb_cache_id":@"0000-0000-000-0000"};
    PBBidResponse *response = [PBBidResponse bidResponseWithAdUnitId:@"testAdUnitID" adServerTargeting:testAdServerTargeting];
    XCTAssertNotNil(response);
}

- (void)testBidResponseExpired {
    NSDictionary *testAdServerTargeting = @{@"hb_pb":@"3.14", @"hb_cache_id":@"0000-0000-000-0000"};
    PBBidResponse *response = [PBBidResponse bidResponseWithAdUnitId:@"testAdUnitID" adServerTargeting:testAdServerTargeting];
    XCTAssertFalse([response isExpired]);
    response.timeToExpireAfter = 1;
    [[NSRunLoop mainRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:2]];
    XCTAssertTrue([response isExpired]);
}

@end
