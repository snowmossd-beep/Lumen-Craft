#import <Foundation/Foundation.h>

@interface GyroInput : NSObject

+ (void)updateOrientation;
+ (void)updateSensitivity:(int)sensitivity invertXAxis:(BOOL)invertX invertYAxis:(BOOL)invertY smoothing:(BOOL)smoothing;
+ (void)tick;

@end
