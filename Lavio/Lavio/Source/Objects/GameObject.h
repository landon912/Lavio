// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "Transform.h"


namespace Lavio
{
	using namespace Math;

	class GameObject
	{
	private:
		std::vector<Component*> mComponents;
		void InternalAddComponent(Component *componentToManage);
		void DestroyAllComponents();
		void DestroyChildren() const;
		//friend Transform::Transform(const Transform &other);
	public:
		GameObject(std::string *name, Vector3<float> position, Vector3<float> rotation);
		explicit GameObject(std::string *name);
		~GameObject();

		std::string *name;
	private:
		Transform *mTransform;
	public:
		Transform& GetTransform() const
		{
			return *mTransform;
		}

	public:
		template <typename T>
		T* GetComponent(bool searchChildren = false) const;
		template <typename T1>
		T1* AddComponent(T1 *componentToManage);
		template <typename T2>
		void RemoveComponent();

	public:
		GameObject(const GameObject &other);
		GameObject& operator=(const GameObject& other);
	};
}

#include "GameObject.inl"