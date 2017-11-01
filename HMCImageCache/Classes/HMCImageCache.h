//
//  ZLMImageCache.h
//  HMCImageCache
//
//  Created by chuonghuynh on 8/2/17.
//  Copyright © 2017 Chương M. Huỳnh. All rights reserved.
//

@import ImageIO;
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define MAXIMUM_MEMORY_RATIO 0.8
#define MINIMUM_MEMORY_RATIO 0.05
#define EXPIRATION_DAYS 30                  // Clear file on disk after 30 days

/**
 HMCImageCache utility - support caching equally between disk and memory
 */
@interface HMCImageCache : NSObject

/**
 Singleton instance

 @return HMCImageCache instance
 */
+ (id)sharedInstance;

- (instancetype)init NS_UNAVAILABLE;

/**
 Store image to disk

 @param image - image to store
 @param key - key to store
 */
- (void)storeImage:(UIImage *)image
           withKey:(NSString *)key;

/**
 Get image from cache with key

 @param key - key of image
 @param storeToMem - want store to memory
 @return storedImage in cache
 */
- (UIImage *)imageFromKey:(NSString *)key
               storeToMem:(BOOL)storeToMem;

/**
 Get image from cache with key and target size

 @param key key of image
 @param size size of image
 @return stored image in cache with size
 */
- (UIImage *)imageFromKey:(NSString *)key
                 withSize:(CGSize)size;

/**
 Download, cache and set image to UIImageView

 @param url url to download image
 @param imageView imageView to load to
 */
- (void)setImageFromURL:(NSURL *) url
            toImageView:(UIImageView *)imageView;

/**
 Get image from url with target size

 @param url url to download image
 @param size size of target image
 @param completionCallback callback to get target image
 @param queue queue to callback
 */
- (void)imageFromURL:(NSURL *)url
      withTargetSize:(CGSize)size
          completion:(void(^)(UIImage *image))completionCallback
       callbackQueue:(dispatch_queue_t)queue;

/**
 Remove image with key from cache

 @param key - key of image
 */
- (void)removeImageForKey:(NSString *)key;

/**
 Remove all cache
 */
- (void)removeAllCache;

@end
