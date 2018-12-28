// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../../Debug/Debugging/Log.h"

#include <typeinfo>

namespace Lavio
{
	template <typename T>
	T* GameObject::GetComponent(bool searchChildren) const
	{
		const type_info &typeInfoToFind = typeid(T);
		for (Component *component : mComponents)
		{
			if (component && typeid(*component) == typeInfoToFind)
			{
				return dynamic_cast<T*>(component);
			}
		}

		if (searchChildren)
		{
			for (std::reference_wrapper<Transform> child : mTransform->children)
			{
				return (child.get().gameObject->GetComponent<T>(searchChildren));
			}
		}

		std::string *text = new std::string("Cannot find component of type");
		Log::DebugLog(text, true);

		return nullptr;
	}

	template <typename T1>
	T1* GameObject::AddComponent(T1 *componentToManage)
	{
		for (int i = 0; i < mComponents.size(); i++)
		{
			const Component *component = mComponents[i];
			if (typeid(component) == typeid(componentToManage))
			{
				//std::string *text = new std::string(strcat("Cannot add another component of same type: ", typeid(componentToManage).name()));
				//Log::DebugLog(text, true);
			}
		}

		componentToManage->SetParentGameObject(*this);
		mComponents.push_back(static_cast<Component*>(componentToManage));
		return componentToManage;
	}

	template <typename T2>
	void GameObject::RemoveComponent()
	{
		const type_info &typeInfoToFind = typeid(T2);
		for (int i = 0; i < mComponents.size(); i++)
		{
			const Component *component = mComponents[i];
			if (component && typeid(*component) == typeInfoToFind)
			{
				mComponents.erase(mComponents.begin() + i);
			}
		}
	}
}
