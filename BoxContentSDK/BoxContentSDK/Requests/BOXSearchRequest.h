//
//  BOXSearchRequest.h
//  BoxContentSDK
//

#import <BoxContentSDK/BOXRequest.h>

@interface BOXSearchRequest : BOXRequest

@property (nonatomic, readonly, strong) NSString *query;
@property (nonatomic, readonly, assign) NSUInteger limit;
@property (nonatomic, readonly, assign) NSUInteger offset;

@property (nonatomic, readwrite, strong) NSArray *fileExtensions;
@property (nonatomic, readwrite, strong) NSDate *createdAtFromDate;
@property (nonatomic, readwrite, strong) NSDate *createdAtToDate;
@property (nonatomic, readwrite, strong) NSDate *updatedAtFromDate;
@property (nonatomic, readwrite, strong) NSDate *updatedAtToDate;
@property (nonatomic, readwrite, assign) NSUInteger sizeLowerBound;
@property (nonatomic, readwrite, assign) NSUInteger sizeUpperBound;
@property (nonatomic, readwrite, strong) NSArray *ownerUserIDs;
@property (nonatomic, readwrite, strong) NSArray *ancestorFolderIDs;
@property (nonatomic, readwrite, strong) NSArray *contentTypes;
@property (nonatomic, readwrite, strong) NSString *type;

/*
 By default BOXSearchRequest will only fetch a predefined set of fields. Use |requestAllItemFields| to
 request all fields.
 */
@property (nonatomic, readwrite, assign) BOOL requestAllItemFields;

- (instancetype)initWithSearchQuery:(NSString *)query inRange:(NSRange)range;

- (instancetype)initWithTemplateKey:(NSString *)templateKey scope:(NSString *)scope filters:(NSArray *)filters inRange:(NSRange)range;

//Perform API request only if completionBlock is not nil
- (void)performRequestWithCompletion:(BOXItemArrayCompletionBlock)completionBlock;

//Perform API and cache requests, with each request occurring only if it is not nil
- (void)performRequestWithCached:(BOXItemArrayCompletionBlock)cacheBlock
                       refreshed:(BOXItemArrayCompletionBlock)refreshBlock;

@end
