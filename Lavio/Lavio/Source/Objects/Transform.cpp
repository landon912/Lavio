// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "Transform.h"

namespace Lavio
{
	Transform::Transform()
		: Component()
	{
		SetTransform(0,0,0,0,0,0,1,1,1, true);
	}

	Transform::~Transform()
	{
		//multiple children will try to delete their parents
		if(parent == nullptr)
		{
			delete parent;
			parent = nullptr;
		}
	}

	//copy constructors
	Transform::Transform(const Transform &other) : Component(), mPosition(other.mPosition), mRotation(other.mRotation), mScale(other.mScale), 
			mLocalPosition(other.mLocalPosition), mLocalRotation(other.mLocalRotation), mLocalScale(other.mLocalScale), mTransformationMatrix(other.mTransformationMatrix)
	{
		//should have same parent pointer
		parent = other.parent;
	}

	Transform & Transform::operator=(const Transform &other)
	{
		Transform copy = other;

		std::swap(mPosition, copy.mPosition);
		std::swap(mRotation, copy.mRotation);
		std::swap(mScale, copy.mScale);
		std::swap(mLocalPosition, copy.mLocalPosition);
		std::swap(mLocalRotation, copy.mLocalRotation);
		std::swap(mLocalScale, copy.mLocalScale);

		std::swap(parent, copy.parent);
		std::swap(mTransformationMatrix, copy.mTransformationMatrix);

		return *this;
	}

	void Transform::WalkTransformationStack()
	{
		mPosition = mLocalPosition;
		mRotation = mLocalRotation;
		mScale = mLocalScale;

		if (parent != nullptr)
		{
			mPosition += parent->GetPosition(false);
			mRotation += parent->GetRotation(false);
			mScale *= parent->GetScale(false);
		}

		mTransformationMatrix = Matrix4x4<float>(1.0f) * Matrix4x4<float>::Translate(mPosition) * Matrix4x4<float>::Rotate(mRotation.z, Vector3<float>::Depth)
			* Matrix4x4<float>::Rotate(mRotation.y, Vector3<float>::Forward) * Matrix4x4<float>::Rotate(mRotation.x, Vector3<float>::Right)
			* Matrix4x4<float>::Scale(mScale);
	}

	void Transform::SetTransformParent(Transform *parent)
	{
		this->parent = parent;
		this->parent->AddTransformChild(this);
	}

	void Transform::AddTransformChild(Transform *child)
	{
		children.push_back(child);
		child->WalkTransformationStack();
	}

	void Transform::RemoveTransformChild(int index)
	{
		children.erase(children.begin() + index);
		children.at(index)->WalkTransformationStack();
	}

	const Vector3<float>& Transform::GetPosition(bool local) const
	{
		return local == true ? mLocalPosition : mPosition;
	}

	const Vector3<float>& Transform::GetRotation(bool local) const
	{
		return local == true ? mLocalRotation : mRotation;
	}

	const Vector3<float>& Transform::GetScale(bool local) const
	{
		return local == true ? mLocalScale : mScale;
	}

	void Transform::SetPosition(const Vector3<float>& position, bool local)
	{
		if (local)
		{
			this->mLocalPosition = position;
		}
		else
		{
			//Log::DebugLog("Transform Error -> Setting global position is not avaliable");
		}
		WalkTransformationStack();
		for (Transform *child : children)
		{
			child->WalkTransformationStack();
		}
	}

	void Transform::SetRotation(const Vector3<float>& rotation, bool local)
	{
		if (local)
		{
			this->mLocalRotation = rotation;
		}
		else
		{
			//Log::DebugLog("Transform Error -> Setting global rotation is not avaliable");
		}
		WalkTransformationStack();
		for (Transform *child : children)
		{
			child->WalkTransformationStack();
		}
	}

	void Transform::SetScale(const Vector3<float>& scale, bool local)
	{
		if (local)
		{
			this->mLocalScale = scale;
		}
		else
		{
			//Log::DebugLog("Transform Error -> Setting global scale is not avaliable");
		}
		WalkTransformationStack();
		for (Transform *child : children)
		{
			child->WalkTransformationStack();
		}
	}

	void Transform::SetTransform(Vector3<float>& position, Vector3<float>& rotation, Vector3<float>& scale, bool local)
	{
		if (local)
		{
			this->mLocalPosition = position;
			this->mLocalRotation = rotation;
			this->mLocalScale = scale;
		}
		WalkTransformationStack();
		for (Transform *child : children)
		{
			child->WalkTransformationStack();
		}
	}

	void Transform::SetTransform(float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz, bool local)
	{
		if (local)
		{
			mLocalPosition.x = px; mLocalPosition.y = py; mLocalPosition.z = pz;
			mLocalRotation.x = rx; mLocalRotation.y = ry; mLocalRotation.z = rz;
			mLocalScale.x = sx; mLocalScale.y = sy; mLocalScale.z = sz;
		}
		WalkTransformationStack();
		for (Transform *child : children)
		{
			child->WalkTransformationStack();
		}
	}
}
