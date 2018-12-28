// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "Vector4.h"

namespace Lavio
{
	namespace Math
	{
		template <typename T>
		Vector4<T>::Vector4()
		{
			x = static_cast<T>(0);
			y = static_cast<T>(0);
			z = static_cast<T>(0);
			w = static_cast<T>(0);
		}

		template <typename T>
		Vector4<T>::Vector4(const T x, const T y, const T z, const T w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		template <typename T>
		Vector4<T>& Vector4<T>::Add(const Vector4<T> &other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		template <typename T>
		Vector4<T>& Vector4<T>::Subtract(const Vector4<T> &other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}

		template <typename T>
		Vector4<T>& Vector4<T>::Multiply(const Vector4<T> &other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;

			return *this;
		}

		template <typename T>
		Vector4<T>& Vector4<T>::Divide(const Vector4<T> &other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;

			return *this;
		}

		template <typename T>
		Vector4<T> operator+(Vector4<T> left, const Vector4<T> &right)
		{
			left.Add(right);
			return left;
		}

		template <typename T>
		Vector4<T> operator-(Vector4<T> left, const Vector4<T> &right)
		{
			left.Subtract(right);
			return left;
		}

		template <typename T>
		Vector4<T> operator*(Vector4<T> left, const Vector4<T> &right)
		{
			left.Multiply(right);
			return left;
		}

		template <typename T>
		Vector4<T> operator/(Vector4<T> left, const Vector4<T> &right)
		{
			left.Divide(right);
			return left;
		}

		template <typename T>
		Vector4<T>& operator+=(Vector4<T> &left, const Vector4<T> &right)
		{
			Vector4<T> returnVector(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
			left = returnVector;
			return left;
		}

		template <typename T>
		Vector4<T>& operator-=(Vector4<T> &left, const Vector4<T> &right)
		{
			Vector4<T> returnVector(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
			left = returnVector;
			return left;
		}

		template <typename T>
		Vector4<T>& operator*=(Vector4<T> &left, const Vector4<T> &right)
		{
			Vector4<T> returnVector(left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w);
			left = returnVector;
			return left;
		}

		template <typename T>
		Vector4<T>& operator/=(Vector4<T> &left, const Vector4<T> &right)
		{
			Vector4<T> returnVector(left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.w);
			left = returnVector;
			return left;
		}

		template <typename T>
		bool operator==(const Vector4<T> &left, const Vector4<T> &right)
		{
			return (left.x == right.x) && (left.y == right.y) && (left.z == right.z) && (left.w == right.w);
		}

		template <typename T>
		bool operator!=(const Vector4<T> &left, const Vector4<T> &right)
		{
			return !(left == right);
		}

		template <typename T>
		std::ostream& operator<<(std::ostream &stream, const Vector4<T> &vector)
		{
			stream << "Vector4: (" << vector.x << "," << vector.y << "," << vector.z << "," << vector.w << ")";
			return stream;
		}
	}
}
