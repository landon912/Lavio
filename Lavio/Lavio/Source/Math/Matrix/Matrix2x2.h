// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once


#include "../Vector/Vector2.h"

namespace Lavio
{
	namespace Math
	{
		template <typename T>
		struct Matrix2x2
		{
			static_assert(std::is_arithmetic<T>::value, "Invalid Template Type: T must be a arithmetic data type");

			union
			{
				T elements[4];

				struct
				{
					Vector2<T> columns[2];
				};
			};

			Matrix2x2<T>();
			Matrix2x2<T>(T diagonal);

			Matrix2x2<T>& MultiplyRef(const Matrix2x2<T> &other);
			Matrix2x2<T> Multiply(const Matrix2x2<T> &other);
			Vector2<T> Multiply(const Vector2<T> &other) const;

			static Matrix2x2<T> Inverse(const Matrix2x2<T> &matrix);

			template <typename T>
			friend Matrix2x2<T> operator*(const Matrix2x2<T> left, const Matrix2x2<T> &right)
			{
				return left.Multiply(right);
			}

			template <typename T>
			friend Vector2<T> operator*(const Matrix2x2<T> &left, const Vector2<T> &right)
			{
				return left.Multiply(right);
			}

			template <typename T>
			friend Matrix2x2<T>& operator*=(Matrix2x2<T> &left, const Matrix2x2<T> &right)
			{
				return left.MultiplyRef(right);
			}
		};
	}
}
