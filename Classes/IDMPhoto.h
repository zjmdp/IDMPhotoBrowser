//
//  IDMPhoto.h
//  IDMPhotoBrowser
//
//  Created by Michael Waterfall on 17/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDMPhotoProtocol.h"
#import <AFNetworking/AFNetworking.h>

// This class models a photo/image and it's caption
// If you want to handle photos, caching, decompression
// yourself then you can simply ensure your custom data model
// conforms to IDMPhotoProtocol
@interface IDMPhoto : NSObject <IDMPhoto>

// Progress download block, used to update the circularView
typedef void (^IDMProgressUpdateBlock)(CGFloat progress);
typedef void (^OnLoadBlock)(NSURL *url);

// Properties
@property (nonatomic, strong) NSString *caption;
@property (nonatomic, strong) NSURL *photoURL;
@property (nonatomic, strong) IDMProgressUpdateBlock progressUpdateBlock;
@property (nonatomic, strong) OnLoadBlock loadBlock;

// Class
+ (IDMPhoto *)photoWithImage:(UIImage *)image;
+ (IDMPhoto *)photoWithFilePath:(NSString *)path;
+ (IDMPhoto *)photoWithURL:(NSURL *)url;
+ (IDMPhoto *)photoWithURL:(NSURL *)url thumbnail:(UIImage *)thumbnail;

+ (NSArray *)photosWithImages:(NSArray *)imagesArray;
+ (NSArray *)photosWithFilePaths:(NSArray *)pathsArray;
+ (NSArray *)photosWithURLs:(NSArray *)urlsArray;

// Init
- (id)initWithImage:(UIImage *)image;
- (id)initWithFilePath:(NSString *)path;
- (id)initWithURL:(NSURL *)url;
- (id)initWithURL:(NSURL *)url thumbnail:(UIImage *)thumbnail;

//使用外部的image loader
- (void)setCustomImageLoader:(OnLoadBlock)loadBlock;
- (void)updateProgress:(CGFloat)progress;
- (void)loadFinished:(UIImage *)image;
- (void)loadFailed:(NSError *)error;

@end

