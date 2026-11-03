#pragma once
#import <UIKit/UIKit.h>

static inline UIColor *ZLDynamic(UIColor *light, UIColor *dark) {
    return [UIColor colorWithDynamicProvider:^UIColor *(UITraitCollection *traits) {
        return traits.userInterfaceStyle == UIUserInterfaceStyleDark ? dark : light;
    }];
}

static inline UIColor *ZLTeal(void) {
    return [UIColor colorWithRed:0x2D/255.0 green:0x8B/255.0 blue:0x9C/255.0 alpha:1.0];
}

static inline UIColor *ZLTealElement(void) {
    return [UIColor colorWithRed:0x32/255.0 green:0x99/255.0 blue:0xAB/255.0 alpha:1.0];
}

static inline UIColor *ZLBackground(void) {
    return ZLDynamic([UIColor colorWithRed:0xBD/255.0 green:0xD9/255.0 blue:0xDD/255.0 alpha:1.0],
                     [UIColor colorWithRed:0x1B/255.0 green:0x2A/255.0 blue:0x2D/255.0 alpha:1.0]);
}

static inline UIColor *ZLCardColor(void) {
    return ZLDynamic([UIColor colorWithWhite:1.0 alpha:0.75],
                     [UIColor colorWithRed:0x2A/255.0 green:0x3C/255.0 blue:0x40/255.0 alpha:0.9]);
}

static inline UIColor *ZLCardSelectedColor(void) {
    return ZLDynamic([UIColor colorWithRed:0xDE/255.0 green:0xEE/255.0 blue:0xF1/255.0 alpha:0.85],
                     [UIColor colorWithRed:0x3A/255.0 green:0x55/255.0 blue:0x5A/255.0 alpha:0.95]);
}

static inline UIColor *ZLPrimaryText(void) {
    return ZLDynamic([UIColor colorWithWhite:0.055 alpha:1.0], UIColor.whiteColor);
}

static inline UIView *ZLCardBackground(UIColor *color, UIEdgeInsets insets) {
    UIView *container = [[UIView alloc] init];
    container.backgroundColor = UIColor.clearColor;
    UIView *card = [[UIView alloc] init];
    card.backgroundColor = color;
    card.layer.cornerRadius = 10;
    card.layer.masksToBounds = YES;
    card.translatesAutoresizingMaskIntoConstraints = NO;
    [container addSubview:card];
    [NSLayoutConstraint activateConstraints:@[
        [card.topAnchor constraintEqualToAnchor:container.topAnchor constant:insets.top],
        [card.bottomAnchor constraintEqualToAnchor:container.bottomAnchor constant:-insets.bottom],
        [card.leadingAnchor constraintEqualToAnchor:container.leadingAnchor constant:insets.left],
        [card.trailingAnchor constraintEqualToAnchor:container.trailingAnchor constant:-insets.right],
    ]];
    return container;
}

static inline void ZLStyleNavigationBar(UINavigationBar *bar) {
    UINavigationBarAppearance *appearance = [[UINavigationBarAppearance alloc] init];
    [appearance configureWithOpaqueBackground];
    appearance.backgroundColor = ZLTeal();
    appearance.titleTextAttributes = @{NSForegroundColorAttributeName: UIColor.whiteColor};
    appearance.largeTitleTextAttributes = @{NSForegroundColorAttributeName: UIColor.whiteColor};
    bar.standardAppearance = appearance;
    bar.scrollEdgeAppearance = appearance;
    bar.compactAppearance = appearance;
    bar.tintColor = UIColor.whiteColor;
}
