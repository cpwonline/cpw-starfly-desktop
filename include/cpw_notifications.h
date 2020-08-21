/*
 * cpw_notifications.h
 * 
 * Copyright 2020 CPW Online <josefelixrc@outlook.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#ifndef CPW_NOTIFICATIONS_H
#define CPW_NOTIFICATIONS_H

#include <string>
#include <giomm-2.4/giomm.h>
#include "Config.h"

class CPWNotifications
{
	public:
		CPWNotifications();
		CPWNotifications(char* id_application, char* title_notification, char* body_notification, char* icon_notification);
		void ReceiveData_(char* id_application, char* title_notification, char* body_notification, char* icon_notification);
		void ShowNotification_();
			
	private:
		char* id_application_, * title_notification_;
		char* body_notification_, * icon_notification_;
		Glib::RefPtr<Gio::Application> ObjectApplication_;
		Glib::RefPtr<Gio::Notification> ObjectNotification_;
		Glib::RefPtr<Gio::ThemedIcon> ObjectIcon_;
};

#endif /* CPW_NOTIFICATIONS_H */ 
