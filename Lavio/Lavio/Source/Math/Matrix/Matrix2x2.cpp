// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include <cmath>
#include "Matrix2x2.h"

namespace Lavio
{
	namespace Math
	{
		template <typename T>
		Matrix2x2<T>::Matrix2x2()
		{
			for (int i = 0; i < 4; i++)
			{
				elements[i] = static_cast<T>(0);
			}
		}

		template <typename T>
		Matrix2x2<T>::Matrix2x2(T diagonal)
		{
			for (int i = 0; i < 4; i++)
			{
				elements[i] = static_cast<T>(0);
			}

			elements[0 + 0 * 2] = diagonal;
			elements[1 + 1 * 2] = diagonal;
		}

		template <typename T>
		Matrix2x2<T>& Matrix2x2<T>::MultiplyRef(const Matrix2x2<T> &other)
		{
			float data[4];
			for (int y = 0; y < 2; y++)
			{
				for (int x = 0; x < 2; x++)
				{
					T sum = static_cast<T>(0);
					for (int e = 0; e < 2; e++)
					{
						sum += elements[x + e * 2] * other.elements[e + y * 2];
					}
					data[x + y * 2] = sum;
				}
			}

			memcpy(elements, data, 4 * sizeof(float));

			return *this;
		}

		template <typename T>
		Matrix2x2<T> Matrix2x2<T>::Multiply(const Matrix2x2<T> &other)
		{
			float data[4];
			for (int y = 0; y < 2; y++)
			{
				for (int x = 0; x < 2; x++)
				{
					T sum = static_cast<T>(0);
					for (int e = 0; e < 2; e++)
					{
						sum += elements[x + e * 2] * other.elements[e + y * 2];
					}
					data[x + y * 2] = sum;
				}
			}

			Matrix2x2<T> result {};

			memcpy(result.elements, data, 4 * sizeof(float));

			return result;
		}

		template <typename T>
		Vector2<T> Matrix2x2<T>::Multiply(const Vector2<T> &other) const
		{
			return Vector2<T>
				(
					 columns[0].x * other.x + columns[1].x * other.y,
					 columns[0].y * other.x + columns[1].y * other.y
				);
		}

		template <typename T>
		Matrix2x2<T> Matrix2x2<T>::Inverse(const Matrix2x2<T> &matrix)
		{
		}
	}
}
