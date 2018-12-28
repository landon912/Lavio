// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "GameObject.h"
#include <algorithm>

namespace Lavio
{
	GameObject::GameObject(std::string *name, Vector3<float> position, Vector3<float> rotation)
	{
		mTransform = new Transform();
		InternalAddComponent(mTransform);

		this->name = name;
		this->mTransform->SetPosition(position);
		this->mTransform->SetRotation(rotation);
	}

	GameObject::GameObject(std::string *name)
	{
		mTransform = new Transform();
		InternalAddComponent(mTransform);

		this->name = name;
		this->mTransform->SetPosition(Vector3<float>(0, 0, 0));
		this->mTransform->SetRotation(Vector3<float>(0, 0, 0));
	}

	//copy constructor
	GameObject::GameObject(const GameObject &other)
	{
		//mComponents.resize(otherSize);

		mTransform = new Transform(*other.mTransform);
		InternalAddComponent(mTransform);

		//start at 1 to ignore Transform
		for(int i = 1; i < other.mComponents.size(); i++)
		{
			mComponents[i] = new Component(*this);
			*mComponents[i] = *other.mComponents[i];
		}

		for(int i = 0; i < other.GetTransform().children.size(); i++)
		{
			GameObject* child = new GameObject(other.GetTransform().children[i]->GetParentGameObject());
			child->GetTransform().SetTransformParent(mTransform);
			//mTransform->AddTransformChild(&child->GetTransform());
		}

		name = new std::string(*other.name);
	}

	GameObject& GameObject::operator=(const GameObject &other)
	{
		GameObject gameObject = GameObject(other);

		for (int i = 0; i < mComponents.size(); i++)
		{
			std::swap(*mComponents[i], *gameObject.mComponents[i]);
		}
		std::swap(*name, *gameObject.name);
		std::swap(*mTransform, *gameObject.mTransform);

		return *this;
	}

	GameObject::~GameObject()
	{
		delete name;
		DestroyChildren();
		DestroyAllComponents();
	}

	void GameObject::DestroyAllComponents()
	{
		for (int i = 0; i < mComponents.size(); i++)
		{
			delete mComponents[i];
		}
	}

	void GameObject::DestroyChildren() const
	{
		for(int i = 0; i < mTransform->children.size(); i++)
		{
			delete &mTransform->children[i]->GetParentGameObject();
		}
	}


	void GameObject::InternalAddComponent(Component *componentToManage)
	{
		AddComponent(componentToManage);
	}
}
