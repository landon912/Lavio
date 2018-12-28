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
		struct Vector4
		{
			static_assert(std::is_arithmetic<T>::value, "Invalid Template Type: T must be a arithmetic data type");

			T x, y, z, w;

			const static Vector4<float> Right;
			const static Vector4<float> Forward;
			const static Vector4<float> Depth;
			const static Vector4<float> W;

			Vector4<T>();
			Vector4<T>(const T x, const T y, const T z, const T w);

		private:
			Vector4<T>& Add(const Vector4<T> &other);
			Vector4<T>& Subtract(const Vector4<T> &other);
			Vector4<T>& Multiply(const Vector4<T> &other);
			Vector4<T>& Divide(const Vector4<T> &other);

		public:
			template <typename T>
			friend Vector4<T> operator+(Vector4<T> left, const Vector4<T> &right);
			template <typename T>
			friend Vector4<T> operator-(Vector4<T> left, const Vector4<T> &right);
			template <typename T>
			friend Vector4<T> operator*(Vector4<T> left, const Vector4<T> &right);
			template <typename T>
			friend Vector4<T> operator/(Vector4<T> left, const Vector4<T> &right);

			template <typename T>
			friend Vector4<T>& operator+=(Vector4<T> &left, const Vector4<T> &right);
			template <typename T>
			friend Vector4<T>& operator-=(Vector4<T> &left, const Vector4<T> &right);
			template <typename T>
			friend Vector4<T>& operator*=(Vector4<T> &left, const Vector4<T> &right);
			template <typename T>
			friend Vector4<T>& operator/=(Vector4<T> &left, const Vector4<T> &right);

			template <typename T>
			friend bool operator==(const Vector4<T> &left, const Vector4<T> &right);
			template <typename T>
			friend bool operator!=(const Vector4<T> &left, const Vector4<T> &right);

			template <typename T>
			friend std::ostream& operator<<(std::ostream &stream, const Vector4<T> &vector);
		};

		const Vector4<float> Vector4<float>::Right = Vector4<float>(1, 0, 0, 0);
		const Vector4<float> Vector4<float>::Forward = Vector4<float>(0, 1, 0, 0);
		const Vector4<float> Vector4<float>::Depth = Vector4<float>(0, 0, 1, 0);
		const Vector4<float> Vector4<float>::W = Vector4<float>(0, 0, 1, 0);
	}
}
