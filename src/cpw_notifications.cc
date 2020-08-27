/*
 * cpw_notifications.cc
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


#include "cpw_notifications.h"


CPWNotifications::CPWNotifications()
{
	AllocateMemory_();
}

CPWNotifications::CPWNotifications(char id_application[], char title_notification[], char body_notification[], char icon_notification[])
{
	AllocateMemory_();
	ReceiveData_(id_application, title_notification, body_notification, icon_notification);
}

CPWNotifications::~CPWNotifications()
{
	std::free(id_application_);
	std::free(title_notification_);
	std::free(body_notification_);
	std::free(icon_notification_);
}

char* CPWNotifications::get_id_application()
{
	return id_application_;
}

char* CPWNotifications::get_title_notification()
{
	return title_notification_;
}

char* CPWNotifications::get_body_notification()
{
	return body_notification_;
}

char* CPWNotifications::get_icon_notification()
{
	return icon_notification_;
}

void CPWNotifications::AllocateMemory_()
{
	id_application_ = (char*)std::malloc(1);
	title_notification_ = (char*)std::malloc(1);
	body_notification_ = (char*)std::malloc(1);
	icon_notification_ = (char*)std::malloc(1);
}

void CPWNotifications::ReceiveData_(char id_application[], char title_notification[], char body_notification[], char icon_notification[])
{
	id_application_ = (char*)std::realloc(id_application_, strlen(id_application) + 1);
	title_notification_ = (char*)std::realloc(title_notification_, strlen(title_notification) + 1);
	body_notification_ = (char*)std::realloc(body_notification_, strlen(body_notification) + 1);
	icon_notification_ = (char*)std::realloc(icon_notification_, strlen(icon_notification) + 1);
	
	strcpy(id_application_, id_application);
	strcpy(title_notification_, title_notification);
	strcpy(body_notification_, body_notification);
	strcpy(icon_notification_, icon_notification);
}

void CPWNotifications::AddThemedIcon_()
{
	ObjectThemedIcon_ = Gio::ThemedIcon::create(icon_notification_);
	ObjectNotification_->set_icon(ObjectThemedIcon_);
}

bool CPWNotifications::PrepareNotification_()
{
	if(id_application_ == "" || title_notification_ == "" || body_notification_ == "") 
		return	false;
	else
	{
		ObjectApplication_ = Gio::Application::create(id_application_, Gio::APPLICATION_FLAGS_NONE);
		ObjectApplication_->register_application();
		
		ObjectNotification_ = Gio::Notification::create(title_notification_);
		ObjectNotification_->set_body(body_notification_);
		return true;
	}
}

void CPWNotifications::ShowNotification_()
{
	ObjectApplication_->send_notification(ObjectNotification_);
}