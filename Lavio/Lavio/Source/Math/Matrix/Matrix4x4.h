// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../Rect.h"
#include "../Vector/Vector3.h"
#include "../Vector/Vector4.h"

namespace Lavio
{
	namespace Math
	{
		template <typename T>
		struct Matrix4x4
		{
			static_assert(std::is_arithmetic<T>::value, "Invalid Template Type: T must be a arithmetic data type");

			union
			{
				T elements[16];

				struct
				{
					Vector4<T> columns[4];
				};
			};

			Matrix4x4<T>();
			Matrix4x4<T>(T diagonal);

			Matrix4x4<T>& MultiplyRef(const Matrix4x4<T> &other);
			Matrix4x4<T> Multiply(const Matrix4x4<T> &other) const;
			Vector3<T> Multiply(const Vector3<T> &other) const;
			Vector4<T> Multiply(const Vector4<T> &other) const;

			static Matrix4x4<T> Orthographic(Rect<T> rect, T nearClipping, T farClipping);
			static Matrix4x4<T> Perspective(T fieldOfView, T aspectRatio, T nearClipping, T farClipping);

			static Matrix4x4<T> Translate(const Vector3<T> &translation);
			static Matrix4x4<T> Rotate(T angle, const Vector3<T> &axis);
			static Matrix4x4<T> Scale(const Vector3<T> &scale);
			
			Matrix4x4<T>& Invert();

			/*static Matrix4x4<T> ToWorldSpace();
			static Matrix4x4<T> ToLocalSpace();*/

			static Matrix4x4<T> Inverse(const Matrix4x4<T> &matrix);

			template <typename T>
			friend Matrix4x4<T> operator*(const Matrix4x4<T> left, const Matrix4x4<T> &right);

			template <typename T>
			friend Vector3<T> operator*(const Matrix4x4<T> &left, const Vector3<T> &right);

			template <typename T>
			friend Vector4<T> operator*(const Matrix4x4<T> &left, const Vector4<T> &right);

			template <typename T>
			friend Matrix4x4<T>& operator*=(Matrix4x4<T> &left, const Matrix4x4<T> &right);
		};
	}
}
