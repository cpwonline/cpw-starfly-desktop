/*
 * cpw_notifications.h
 * 
 * Copyright 2020 CPW Online <josefelixrc@outlook.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * For more information see the LICENCE file.
 * 
 */

 
#ifndef CPW_NOTIFICATIONS_H
#define CPW_NOTIFICATIONS_H

#include <cstdlib>
#include <string>
#include <giomm-2.4/giomm.h>
#include "Config.h"

class CPWNotifications
{
	public:
		CPWNotifications();
		CPWNotifications(char id_application[], char title_notification[], char body_notification[], char icon_notification[]);
		~CPWNotifications();
		char* get_id_application();
		char* get_title_notification();
		char* get_body_notification();
		char* get_icon_notification();
		void ReceiveData_(char id_application[], char title_notification[], char body_notification[], char icon_notification[]);
		void ShowNotification_();
		void AddThemedIcon_();
		bool PrepareNotification_();
		void AllocateMemory_();
			
	private:
		char* id_application_, * title_notification_;
		char* body_notification_, * icon_notification_;
		Glib::RefPtr<Gio::Application> ObjectApplication_;
		Glib::RefPtr<Gio::Notification> ObjectNotification_;
		Glib::RefPtr<Gio::ThemedIcon> ObjectThemedIcon_;
};

#endif /* CPW_NOTIFICATIONS_H */ 
