//
//  UIButton+HMCImageCacheExtension.h
//  HMCImageCache
//
//  Created by Huỳnh Minh Chương on 11/4/17.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface UIButton(HMCImageCache)

/**
 Download, cache and set image to UIButton
 
 @param url url to download image
 @param state state of control
 */
- (void)HMCSetImageFromURL:(NSURL *) url
                  forState:(UIControlState)state;

/**
 Get key of cached image

 @return cached image key
 */
- (NSString *)getCachedImageKey;

@end
