/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Tencent is pleased to support the open source community by making libpag available.
//
//  Copyright (C) 2021 THL A29 Limited, a Tencent company. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file
//  except in compliance with the License. You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  unless required by applicable law or agreed to in writing, software distributed under the
//  license is distributed on an "as is" basis, without warranties or conditions of any kind,
//  either express or implied. see the license for the specific language governing permissions
//  and limitations under the license.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#import <Foundation/Foundation.h>
#import "PAGLayer.h"
#import "PAGScaleMode.h"

@class PAGImage;
@class PAGVideoRange;

__attribute__((visibility("default")))
@interface PAGImageLayer : PAGLayer
/**
 * Make a PAGImageLayer with size and duration(in microseconds).
 */
+ (instancetype)Make:(CGSize)size duration:(int64_t)duration;

/**
 * Returns the time ranges of the source video for replacement.
 */
- (NSArray<PAGVideoRange*>*)getVideoRanges;

/**
 * Replace the original image content with the specified PAGImage object. Passing in null for the
 * image parameter resets the layer to its default image content. This method walks through the
 * whole layer tree, and replaces every PAGImageLayer which has the same content to this layer.
 * @param image The PAGImage object to replace with.
 */
- (void)replaceImage:(PAGImage*)image;

/**
 * Returns the content duration in microseconds, which indicates the minimal length required for
 * replacement.
 */
- (int64_t)contentDuration;

@end
