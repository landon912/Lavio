// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "Vector3.h"

namespace Lavio
{
	namespace Math
	{
		template <typename T>
		Vector3<T>::Vector3()
		{
			x = static_cast<T>(0);
			y = static_cast<T>(0);
			z = static_cast<T>(0);
		}

		template <typename T>
		Vector3<T>::Vector3(const T x, const T y, const T z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		template <typename T>
		Vector3<T>& Vector3<T>::Add(const Vector3<T> &other)
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		template <typename T>
		Vector3<T>& Vector3<T>::Subtract(const Vector3<T> &other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		template <typename T>
		Vector3<T>& Vector3<T>::Multiply(const Vector3<T> &other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

		template <typename T>
		Vector3<T>& Vector3<T>::Divide(const Vector3<T> &other)
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;

			return *this;
		}

		template <typename T>
		Vector3<T> operator+(Vector3<T> left, const Vector3<T> &right)
		{
			left.Add(right);
			return left;
		}

		template <typename T>
		Vector3<T> operator-(Vector3<T> left, const Vector3<T> &right)
		{
			left.Subtract(right);
			return left;
		}

		template <typename T>
		Vector3<T> operator*(Vector3<T> left, const Vector3<T> &right)
		{
			left.Multiply(right);
			return left;
		}

		template <typename T>
		Vector3<T> operator/(Vector3<T> left, const Vector3<T> &right)
		{
			left.Divide(right);
			return left;
		}

		template <typename T>
		Vector3<T>& operator+=(Vector3<T> &left, const Vector3<T> &right)
		{
			//Vector3<T> returnVector(left.x + right.x, left.y + right.y, left.z + right.z);
			left.x = left.x + right.x;
			left.y = left.y + right.y;
			left.z = left.z + right.z;
			return left;
		}

		template <typename T>
		Vector3<T>& operator-=(Vector3<T> &left, const Vector3<T> &right)
		{
			Vector3<T> returnVector(left.x - right.x, left.y - right.y, left.z - right.z);
			left = returnVector;
			return left;
		}

		template <typename T>
		Vector3<T>& operator*=(Vector3<T> &left, const Vector3<T> &right)
		{
			Vector3<T> returnVector(left.x * right.x, left.y * right.y, left.z * right.z);
			left = returnVector;
			return left;
		}

		template <typename T>
		Vector3<T>& operator/=(Vector3<T> &left, const Vector3<T> &right)
		{
			Vector3<T> returnVector(left.x / right.x, left.y / right.y, left.z / right.z);
			left = returnVector;
			return left;
		}

		template <typename T>
		bool operator==(const Vector3<T> &left, const Vector3<T> &right)
		{
			return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
		}

		template <typename T>
		bool operator!=(const Vector3<T> &left, const Vector3<T> &right)
		{
			return !(left == right);
		}

		template <typename T>
		std::ostream& operator<<(std::ostream &stream, const Vector3<T> &vector)
		{
			stream << "Vector3: (" << vector.x << "," << vector.y << "," << vector.z << ")";
			return stream;
		}
	}
}
