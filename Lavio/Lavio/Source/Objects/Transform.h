// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../Math/Math.h"
#include "Component.h"

#include <vector>

namespace Lavio
{
	using namespace Math;

	class Transform : public Component
	{
	private:
		Vector3<float> mPosition;
		Vector3<float> mRotation;
		Vector3<float> mScale;
					   
		Vector3<float> mLocalPosition;
		Vector3<float> mLocalRotation;
		Vector3<float> mLocalScale;

		Matrix4x4<float> mTransformationMatrix;
		void WalkTransformationStack();
	public:
		Transform *parent = nullptr;
		std::vector<Transform*> children;
	public:
		Transform();
		~Transform();

		void SetTransformParent(Transform *parent);
		void AddTransformChild(Transform *child);
		void RemoveTransformChild(int index);

		const Vector3<float>& GetPosition(bool local) const;
		const Vector3<float>& GetRotation(bool local) const;
		const Vector3<float>& GetScale(bool local) const;

		Matrix4x4<float>& GetTransformationMatrix()
		{
			return mTransformationMatrix;
		}

		void SetPosition(const Vector3<float>& position, bool local = true);
		void SetRotation(const Vector3<float>& rotation, bool local = true);
		void SetScale(const Vector3<float>& scale, bool local = true);

		void SetTransform(Vector3<float>& position, Vector3<float>& rotation, Vector3<float>& scale, bool local);
		void SetTransform(float px, float py, float pz, float rx, float ry, float rz, float sx, float sy, float sz, bool local);

	public:
		//copy constructors
		Transform(const Transform &other);
		Transform& operator=(const Transform &other);
	};
}