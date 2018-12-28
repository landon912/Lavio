// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "Vector2.h"

namespace Lavio
{
	namespace Math
	{
		template <typename T>
		Vector2<T>::Vector2()
		{
			x = static_cast<T>(0);
			y = static_cast<T>(0);
		}

		template <typename T>
		Vector2<T>::Vector2(const T x, const T y)
		{
			this->x = x;
			this->y = y;
		}

		template <typename T>
		Vector2<T>& Vector2<T>::Add(const Vector2<T> &other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}

		template <typename T>
		Vector2<T>& Vector2<T>::Subtract(const Vector2<T> &other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		template <typename T>
		Vector2<T>& Vector2<T>::Multiply(const Vector2<T> &other)
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}

		template <typename T>
		Vector2<T>& Vector2<T>::Divide(const Vector2<T> &other)
		{
			x /= other.x;
			y /= other.y;

			return *this;
		}

		template <typename T>
		Vector2<T> operator+(Vector2<T> left, const Vector2<T> &right)
		{
			//left is copy data, so using reference math works great
			left.Add(right);
			return left;
		}

		template <typename T>
		Vector2<T> operator-(Vector2<T> left, const Vector2<T> &right)
		{
			//left is copy data, so using reference math works great
			left.Subtract(right);
			return left;
		}

		template <typename T>
		Vector2<T> operator*(Vector2<T> left, const Vector2<T> &right)
		{
			//left is copy data, so using reference math works great
			left.Multiply(right);
			return left;
		}

		template <typename T>
		Vector2<T> operator/(Vector2<T> left, const Vector2<T> &right)
		{
			//left is copy data, so using reference math works great
			left.Divide(right);
			return left;
		}

		template <typename T>
		Vector2<T>& operator+=(Vector2<T> &left, const Vector2<T> &right)
		{
			Vector2<T> returnVector(left.x + right.x, left.y + right.y);
			left = returnVector;
			return left;
		}

		template <typename T>
		Vector2<T>& operator-=(Vector2<T> &left, const Vector2<T> &right)
		{
			Vector2<T> returnVector(left.x - right.x, left.y - right.y);
			left = returnVector;
			return left;
		}

		template <typename T>
		Vector2<T>& operator*=(Vector2<T> &left, const Vector2<T> &right)
		{
			Vector2<T> returnVector(left.x * right.x, left.y * right.y);
			left = returnVector;
			return left;
		}

		template <typename T>
		Vector2<T>& operator/=(Vector2<T> &left, const Vector2<T> &right)
		{
			Vector2<T> returnVector(left.x / right.x, left.y / right.y);
			left = returnVector;
			return left;
		}

		template <typename T>
		bool operator==(const Vector2<T> &left, const Vector2<T> &right)
		{
			return (left.x == right.x) && (left.y == right.y);
		}

		template <typename T>
		bool operator!=(const Vector2<T> &left, const Vector2<T> &right)
		{
			return !(left == right);
		}

		template <typename T>
		std::ostream& operator<<(std::ostream &stream, const Vector2<T> &vector)
		{
			stream << "Vector2: (" << vector.x << "," << vector.y << ")";
			return stream;
		}
	}
}
