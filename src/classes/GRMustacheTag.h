// The MIT License
//
// Copyright (c) 2012 Gwendal Roué
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "GRMustacheAvailabilityMacros.h"

@class GRMustacheTemplateRepository;

/**
 * The types of Mustache tags
 *
 * @since v6.0
 */
typedef enum {
    /**
     * The type for variable tags such as {{ name }}
     *
     * @since v6.0
     */
    GRMustacheTagTypeVariable = 1 << 1 AVAILABLE_GRMUSTACHE_VERSION_6_0_AND_LATER,
    
    /**
     * The type for section tags such as {{# name }}...{{/}}
     *
     * @since v6.0
     */
    GRMustacheTagTypeSection = 1 << 2 AVAILABLE_GRMUSTACHE_VERSION_6_0_AND_LATER,
    
    /**
     * The type for overridable section tags such as {{$ name }}...{{/}}
     *
     * @since v6.0
     */
    GRMustacheTagTypeOverridableSection = 1 << 3 AVAILABLE_GRMUSTACHE_VERSION_6_0_AND_LATER,
    
    /**
     * The type for inverted section tags such as {{^ name }}...{{/}}
     *
     * @since v6.0
     */
    GRMustacheTagTypeInvertedSection = 1 << 4 AVAILABLE_GRMUSTACHE_VERSION_6_0_AND_LATER,
} GRMustacheTagType AVAILABLE_GRMUSTACHE_VERSION_6_0_AND_LATER;


/**
 * GRMustacheTag instances represent Mustache tags that render values, such as
 * a variable tag {{ name }}, or a section tag {{# name }}...{{/}).
 */
@interface GRMustacheTag: NSObject {
    id _expression;
    GRMustacheTemplateRepository *_templateRepository;
}

/**
 * The type of the tag
 */
@property (nonatomic, readonly) GRMustacheTagType type AVAILABLE_GRMUSTACHE_VERSION_6_0_AND_LATER;

/**
 * The template repository that did provide the template string from which the
 * receiver has been extracted.
 *
 * @see GRMustacheTemplateRepository
 */
@property (nonatomic, readonly) GRMustacheTemplateRepository *templateRepository AVAILABLE_GRMUSTACHE_VERSION_6_0_AND_LATER;

/**
 * The literal and unprocessed inner content of the tag, the `...` in
 * `{{# name }}...{{/}}`.
 *
 * Is is nil for variable tags such as `{{ name }}`.
 */
@property (nonatomic, readonly) NSString *innerTemplateString AVAILABLE_GRMUSTACHE_VERSION_6_0_AND_LATER;

/**
 * Returns the rendering of the inner content of the receiver, given a rendering
 * context.
 *
 * Is is empty for variable tags such as `{{ name }}`.
 *
 * @param context   A rendering context.
 * @param HTMLSafe  Upon return contains YES if the result is HTML-safe.
 * @param error     If there is an error rendering the tag, upon return contains
 *                  an NSError object that describes the problem.
 *
 * @return The rendering of the tag.
 */
- (NSString *)renderContentWithContext:(GRMustacheContext *)context HTMLSafe:(BOOL *)HTMLSafe error:(NSError **)error AVAILABLE_GRMUSTACHE_VERSION_6_0_AND_LATER;

@end