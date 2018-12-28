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
		struct Vector3
		{
			static_assert(std::is_arithmetic<T>::value, "Invalid Template Type: T must be a arithmetic data type");

			T x, y, z;

			Vector3<T>();
			Vector3<T>(const T x, const T y, const T z);

			const static Vector3<float> Right;
			const static Vector3<float> Forward;
			const static Vector3<float> Depth;
		private:
			Vector3<T>& Add(const Vector3<T> &other);
			Vector3<T>& Subtract(const Vector3<T> &other);
			Vector3<T>& Multiply(const Vector3<T> &other);
			Vector3<T>& Divide(const Vector3<T> &other);

		public:
			template <typename T>
			friend Vector3<T> operator+(Vector3<T> left, const Vector3<T> &right);
			template <typename T>
			friend Vector3<T> operator-(Vector3<T> left, const Vector3<T> &right);
			template <typename T>
			friend Vector3<T> operator*(Vector3<T> left, const Vector3<T> &right);
			template <typename T>
			friend Vector3<T> operator/(Vector3<T> left, const Vector3<T> &right);

			template <typename T>
			friend Vector3<T>& operator+=(Vector3<T> &left, const Vector3<T> &right);
			template <typename T>
			friend Vector3<T>& operator-=(Vector3<T> &left, const Vector3<T> &right);
			template <typename T>
			friend Vector3<T>& operator*=(Vector3<T> &left, const Vector3<T> &right);
			template <typename T>
			friend Vector3<T>& operator/=(Vector3<T> &left, const Vector3<T> &right);

			template <typename T>
			friend bool operator==(const Vector3<T> &left, const Vector3<T> &right);
			template <typename T>
			friend bool operator!=(const Vector3<T> &left, const Vector3<T> &right);

			template <typename T>
			friend std::ostream& operator<<(std::ostream &stream, const Vector3<T> &vector);
		};

		const Vector3<float> Vector3<float>::Right = Vector3<float>(1, 0, 0);
		const Vector3<float> Vector3<float>::Forward = Vector3<float>(0, 1, 0);
		const Vector3<float> Vector3<float>::Depth = Vector3<float>(0, 0, 1);
	}
}
