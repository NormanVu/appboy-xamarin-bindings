#if !TARGET_OS_TV
#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/*
 * Appboy Public API: ABKPushUtils
 */
@interface ABKPushUtils : NSObject

/*!
 * @param response The UNNotificationResponse passed to userNotificationCenter:didReceiveNotificationResponse:withCompletionHandler:.
 *
 * @return YES if the user notification was sent from Appboy's servers.
 */
+ (BOOL)isAppboyUserNotification:(UNNotificationResponse *)response NS_AVAILABLE_IOS(10.0);

/*!
 * @param userInfo The userInfo dictionary passed to application:didReceiveRemoteNotification:fetch​Completion​Handler:
 *                 or application:didReceiveRemoteNotification:.
 *
 * @return YES if the push notification was sent from Appboy's servers.
 */
+ (BOOL)isAppboyRemoteNotification:(NSDictionary *)userInfo;

/*!
 * @param userInfo The userInfo dictionary passed to application:didReceiveRemoteNotification:fetchCompletionHandler:
 *                 or application:didReceiveRemoteNotification:.
 *
 * @return YES if the push notification was sent by Appboy for an internal feature.
 *
 * @discussion Appboy uses content-available silent notifications for internal features. You can use this method to ensure
 *             your app doesn't take any undesired or unnecessary actions upon receiving Appboy's internal content-available notifications
 *             (e.g., pinging your server for content).
 */
+ (BOOL)isAppboyInternalRemoteNotification:(NSDictionary *)userInfo;

/*!
 * @param response The UNNotificationResponse passed to userNotificationCenter:didReceiveNotificationResponse:withCompletionHandler:.
 *
 * @return YES if the user notification was sent by Appboy for uninstall tracking.
 *
 * @discussion Uninstall tracking notifications are content-available silent notifications. You can use this method to ensure 
 *             your app doesn't take any undesired or unnecessary actions upon receiving Appboy's uninstall tracking notifications
 *             (e.g., pinging your server for content).
 */
+ (BOOL)isUninstallTrackingUserNotification:(UNNotificationResponse *)response NS_AVAILABLE_IOS(10.0);

/*!
 * @param userInfo The userInfo dictionary passed to application:didReceiveRemoteNotification:fetchCompletionHandler:
 *                 or application:didReceiveRemoteNotification:.
 *
 * @return YES if the push notification was sent by Appboy for uninstall tracking.
 *
 * @discussion Uninstall tracking notifications are content-available silent notifications. You can use this method to ensure
 *             your app doesn't take any undesired or unnecessary actions upon receiving Appboy's uninstall tracking notifications
 *             (e.g., pinging your server for content).
 */
+ (BOOL)isUninstallTrackingRemoteNotification:(NSDictionary *)userInfo;

/*!
 * @param response The UNNotificationResponse passed to userNotificationCenter:didReceiveNotificationResponse:withCompletionHandler:.
 *
 * @return YES if the user notification was sent by Appboy for syncing geofences.
 *
 * @discussion Geofence sync notifications are content-available silent notifications. You can use this method to ensure
 *             your app doesn't take any undesired or unnecessary actions upon receiving Appboy's geofence sync notifications
 *             (e.g., pinging your server for content).
 */
+ (BOOL)isGeofencesSyncUserNotification:(UNNotificationResponse *)response NS_AVAILABLE_IOS(10.0);

/*!
 * @param userInfo The userInfo dictionary passed to application:didReceiveRemoteNotification:fetchCompletionHandler:
 *                 or application:didReceiveRemoteNotification:.
 *
 * @return YES if the push notification was sent by Appboy for syncing geofences.
 *
 * @discussion Geofence sync notifications are content-available silent notifications. You can use this method to ensure
 *             your app doesn't take any undesired or unnecessary actions upon receiving Appboy's geofence sync notifications
 *             (e.g., pinging your server for content).
 */
+ (BOOL)isGeofencesSyncRemoteNotification:(NSDictionary *)userInfo;

/*!
 * @param userInfo The userInfo dictionary passed to application:didReceiveRemoteNotification:fetchCompletionHandler:
 *                 or application:didReceiveRemoteNotification:.
 *
 * @return YES if the push notification was sent by Appboy for push stories.
 *
 * @discussion Push story notifications are content-available silent notifications. You can use this method to ensure
 *             your app doesn't take any undesired or unnecessary actions upon receiving Appboy's push story notifications
 *             (e.g., pinging your server for content).
 */
+ (BOOL)isPushStoryRemoteNotification:(NSDictionary *)userInfo;

/*!
 * @param userInfo The userInfo dictionary payload.
 *
 * @return YES if the notification contains an a flag that inticates the device should fetch test triggers from the server.
 *
 */
+ (BOOL)shouldFetchTestTriggersFlagContainedInPayload:(NSDictionary *)userInfo __deprecated;

+ (NSSet<UNNotificationCategory *> *)getAppboyUNNotificationCategorySet NS_AVAILABLE_IOS(10.0);

+ (NSSet<UIUserNotificationCategory *> *)getAppboyUIUserNotificationCategorySet __deprecated;

@end
NS_ASSUME_NONNULL_END
#endif
