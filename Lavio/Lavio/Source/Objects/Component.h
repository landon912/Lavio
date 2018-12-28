// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../../Debug/Debugging/Log.h"

namespace Lavio
{
	class GameObject;

	class Component
	{
	public:
		explicit Component(const GameObject& parentGameObject) : parentGameObject(&parentGameObject){}
		explicit Component() {}
		virtual ~Component() {}

		const GameObject& GetParentGameObject() const
		{
			return *parentGameObject;
		}
		void SetParentGameObject(const GameObject& parent)
		{
			if (parentGameObject) { Log::DebugLog("You may not change the parent of a Component once it has been added to a GameObject."); return; }
			parentGameObject = &parent;
		}

	private:
		const GameObject* parentGameObject = nullptr;
		//char *name;
		unsigned int ID = 0;
		//const type_info& typeInfo;

	private:
		/*Component(const Component &other) = delete;
		Component & operator=(const Component &other) = delete;*/
	};
}