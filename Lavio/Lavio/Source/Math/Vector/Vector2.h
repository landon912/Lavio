// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include <iostream>

namespace Lavio
{
	namespace Math
	{
		template <typename T>
		struct Vector2
		{
			static_assert(std::is_arithmetic<T>::value, "Invalid Template Type: T must be a arithmetic data type");

			T x, y;

			static const Vector2<float> Right;
			static const Vector2<float> Forward;

			Vector2<T>();
			Vector2<T>(const T x, const T y);

		private:
			Vector2<T>& Add(const Vector2<T> &other);
			Vector2<T>& Subtract(const Vector2<T> &other);
			Vector2<T>& Multiply(const Vector2<T> &other);
			Vector2<T>& Divide(const Vector2<T> &other);

		public:
			template <typename T>
			friend Vector2<T> operator+(Vector2<T> left, const Vector2<T> &right);
			template <typename T>
			friend Vector2<T> operator-(Vector2<T> left, const Vector2<T> &right);
			template <typename T>
			friend Vector2<T> operator*(Vector2<T> left, const Vector2<T> &right);
			template <typename T>
			friend Vector2<T> operator/(Vector2<T> left, const Vector2<T> &right);

			template <typename T>
			friend Vector2<T>& operator+=(Vector2<T> &left, const Vector2<T> &right);
			template <typename T>
			friend Vector2<T>& operator-=(Vector2<T> &left, const Vector2<T> &right);
			template <typename T>
			friend Vector2<T>& operator*=(Vector2<T> &left, const Vector2<T> &right);
			template <typename T>
			friend Vector2<T>& operator/=(Vector2<T> &left, const Vector2<T> &right);

			template <typename T>
			friend bool operator==(const Vector2<T> &left, const Vector2<T> &right);
			template <typename T>
			friend bool operator!=(const Vector2<T> &left, const Vector2<T> &right);

			template <typename T>
			friend std::ostream& operator<<(std::ostream &stream, const Vector2<T> &vector);
		};

		const Vector2<float> Vector2<float>::Right = Vector2<float>(1, 0);
		const Vector2<float> Vector2<float>::Forward = Vector2<float>(0, 1);
	}
}
