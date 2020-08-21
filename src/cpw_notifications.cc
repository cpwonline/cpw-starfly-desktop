/*
 * cpw_notifications.cc
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


#include "cpw_notifications.h"


CPWNotifications::CPWNotifications(char* id_application, char* title_notification, char* body_notification, char* icon_notification) :
	id_application_(id_application),
	title_notification_(title_notification),
	body_notification_(body_notification),
	icon_notification_(icon_notification)
{
	ObjectApplication_ = Gio::Application::create(id_application_, Gio::APPLICATION_FLAGS_NONE);
	ObjectApplication_->register_application();
	
	ObjectNotification_ = Gio::Notification::create(title_notification_);
	ObjectNotification_->set_body(body_notification_);
}

void CPWNotifications::ShowNotification_()
{
	ObjectApplication_->send_notification(ObjectNotification_);
}

void CPWNotifications::AddThemedIcon_()
{
	ObjectThemedIcon_ = Gio::ThemedIcon::create(icon_notification_);
	ObjectNotification_->set_icon(ObjectThemedIcon_);
}

void CPWNotifications::AddIconSrc_()
{
	ObjectIcon_ = Gio::Icon::create(icon_notification_);
	ObjectNotification_->set_icon(ObjectIcon_);
}