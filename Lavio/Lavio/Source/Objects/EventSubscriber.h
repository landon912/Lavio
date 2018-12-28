// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "Component.h"

namespace Lavio
{
	class EventSubscriber : public Component
	{
	public:
		EventSubscriber() : Component()
		{
		}

		virtual ~EventSubscriber()
		{
		}

		virtual void Awake() = 0;
		virtual void Update() = 0;
	};
}
