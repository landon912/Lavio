// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include <cmath>
#include "Matrix4x4.h"

namespace Lavio
{
	namespace Math
	{
		template <typename T>
		Matrix4x4<T>::Matrix4x4()
		{
			for (int i = 0; i < 16; i++)
			{
				elements[i] = static_cast<T>(0);
			}
		}

		template <typename T>
		Matrix4x4<T>::Matrix4x4(T diagonal)
		{
			for (int i = 0; i < 16; i++)
			{
				elements[i] = static_cast<T>(0);
			}

			elements[0 + 0 * 4] = diagonal;
			elements[1 + 1 * 4] = diagonal;
			elements[2 + 2 * 4] = diagonal;
			elements[3 + 3 * 4] = diagonal;
		}

		template <typename T>
		Matrix4x4<T>& Matrix4x4<T>::MultiplyRef(const Matrix4x4<T> &other)
		{
			float data[16];
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					T sum = static_cast<T>(0);
					for (int e = 0; e < 4; e++)
					{
						sum += elements[x + e * 4] * other.elements[e + y * 4];
					}
					data[x + y * 4] = sum;
				}
			}

			memcpy(elements, data, 16 * sizeof(float));

			return *this;
		}

		template <typename T>
		Matrix4x4<T> Matrix4x4<T>::Multiply(const Matrix4x4<T> &other) const
		{
			float data[16];
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					T sum = static_cast<T>(0);
					for (int e = 0; e < 4; e++)
					{
						sum += elements[x + e * 4] * other.elements[e + y * 4];
					}
					data[x + y * 4] = sum;
				}
			}

			Matrix4x4<T> result {};

			memcpy(result.elements, data, 16 * sizeof(float));

			return result;
		}

		template <typename T>
		Vector3<T> Matrix4x4<T>::Multiply(const Vector3<T> &other) const
		{
			return Vector3<T>
				(
					 columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x,
					 columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y,
					 columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z
				);
		}

		template <typename T>
		Vector4<T> Matrix4x4<T>::Multiply(const Vector4<T> &other) const
		{
			return Vector4<T>
				(
					 columns[0].x * other.x + columns[1].x * other.y + columns[2].x * other.z + columns[3].x * other.w,
					 columns[0].y * other.x + columns[1].y * other.y + columns[2].y * other.z + columns[3].y * other.w,
					 columns[0].z * other.x + columns[1].z * other.y + columns[2].z * other.z + columns[3].z * other.w,
					 columns[0].w * other.x + columns[1].w * other.y + columns[2].w * other.z + columns[3].w * other.w
				);
		}

		template <typename T>
		Matrix4x4<T> Matrix4x4<T>::Orthographic(Rect<T> rect, T nearClipping, T farClipping)
		{
			Matrix4x4<T> result(static_cast<T>(1));

			result.elements[0 + 0 * 4] = static_cast<T>(2) / (rect.right - rect.left);
			result.elements[1 + 1 * 4] = static_cast<T>(2) / (rect.top - rect.bottom);
			result.elements[2 + 2 * 4] = static_cast<T>(2) / (nearClipping - farClipping);

			result.elements[0 + 3 * 4] = (rect.left + rect.right) / (rect.left - rect.right);
			result.elements[1 + 3 * 4] = (rect.bottom + rect.top) / (rect.bottom - rect.top);
			result.elements[2 + 3 * 4] = (farClipping + nearClipping) / (farClipping - nearClipping);

			return result;
		}

		template <typename T>
		Matrix4x4<T> Matrix4x4<T>::Perspective(T fieldOfView, T aspectRatio, T nearClipping, T farClipping)
		{
			Matrix4x4<T> result(static_cast<T>(1));

			T q = static_cast<T>(1) / static_cast<T>(tan(ToRadians(static_cast<T>(0.5) * fieldOfView)));
			T a = q / aspectRatio;

			T b = (nearClipping + farClipping) / (nearClipping - farClipping);
			T c = (static_cast<T>(2) * nearClipping * farClipping) / (nearClipping - farClipping);

			result.elements[0 + 0 * 4] = a;
			result.elements[1 + 1 * 4] = q;
			result.elements[2 + 2 * 4] = b;
			result.elements[3 + 2 * 4] = static_cast<T>(-1);
			result.elements[2 + 3 * 4] = c;

			return result;
		}

		template <typename T>
		Matrix4x4<T> Matrix4x4<T>::Translate(const Vector3<T> &translation)
		{
			Matrix4x4<T> result(static_cast<T>(1));

			result.elements[0 + 3 * 4] = translation.x;
			result.elements[1 + 3 * 4] = translation.y;
			result.elements[2 + 3 * 4] = translation.z;

			return result;
		}

		template <typename T>
		Matrix4x4<T> Matrix4x4<T>::Rotate(T angle, const Vector3<T> &axis)
		{
			Matrix4x4<T> result(static_cast<T>(1));

			T r = ToRadians(angle);
			T c = cos(r);
			T s = sin(r);
			T omc = static_cast<T>(1) - c;

			T x = axis.x;
			T y = axis.y;
			T z = axis.z;

			result.elements[0 + 0 * 4] = x * omc + c;
			result.elements[0 + 1 * 4] = y * x * omc + z * s;
			result.elements[0 + 2 * 4] = x * z * omc - y * s;

			result.elements[1 + 0 * 4] = x * y * omc - z * s;
			result.elements[1 + 1 * 4] = y * omc + c;
			result.elements[1 + 2 * 4] = y * z * omc + x * s;

			result.elements[2 + 0 * 4] = x * z * omc + y * s;
			result.elements[2 + 1 * 4] = y * z * omc - x * s;
			result.elements[2 + 2 * 4] = z * omc + c;

			return result;
		}

		template <typename T>
		Matrix4x4<T> Matrix4x4<T>::Scale(const Vector3<T> &scale)
		{
			Matrix4x4<T> result(static_cast<T>(1));

			result.elements[0 + 0 * 4] = scale.x;
			result.elements[1 + 1 * 4] = scale.y;
			result.elements[2 + 2 * 4] = scale.z;

			return result;
		}

		template <typename T>
		Matrix4x4<T>& Matrix4x4<T>::Invert()
		{
			double temp[16];

			temp[0] = elements[5] * elements[10] * elements[15] -
				elements[5] * elements[11] * elements[14] -
				elements[9] * elements[6] * elements[15] +
				elements[9] * elements[7] * elements[14] +
				elements[13] * elements[6] * elements[11] -
				elements[13] * elements[7] * elements[10];

			temp[4] = -elements[4] * elements[10] * elements[15] +
				elements[4] * elements[11] * elements[14] +
				elements[8] * elements[6] * elements[15] -
				elements[8] * elements[7] * elements[14] -
				elements[12] * elements[6] * elements[11] +
				elements[12] * elements[7] * elements[10];

			temp[8] = elements[4] * elements[9] * elements[15] -
				elements[4] * elements[11] * elements[13] -
				elements[8] * elements[5] * elements[15] +
				elements[8] * elements[7] * elements[13] +
				elements[12] * elements[5] * elements[11] -
				elements[12] * elements[7] * elements[9];

			temp[12] = -elements[4] * elements[9] * elements[14] +
				elements[4] * elements[10] * elements[13] +
				elements[8] * elements[5] * elements[14] -
				elements[8] * elements[6] * elements[13] -
				elements[12] * elements[5] * elements[10] +
				elements[12] * elements[6] * elements[9];

			temp[1] = -elements[1] * elements[10] * elements[15] +
				elements[1] * elements[11] * elements[14] +
				elements[9] * elements[2] * elements[15] -
				elements[9] * elements[3] * elements[14] -
				elements[13] * elements[2] * elements[11] +
				elements[13] * elements[3] * elements[10];

			temp[5] = elements[0] * elements[10] * elements[15] -
				elements[0] * elements[11] * elements[14] -
				elements[8] * elements[2] * elements[15] +
				elements[8] * elements[3] * elements[14] +
				elements[12] * elements[2] * elements[11] -
				elements[12] * elements[3] * elements[10];

			temp[9] = -elements[0] * elements[9] * elements[15] +
				elements[0] * elements[11] * elements[13] +
				elements[8] * elements[1] * elements[15] -
				elements[8] * elements[3] * elements[13] -
				elements[12] * elements[1] * elements[11] +
				elements[12] * elements[3] * elements[9];

			temp[13] = elements[0] * elements[9] * elements[14] -
				elements[0] * elements[10] * elements[13] -
				elements[8] * elements[1] * elements[14] +
				elements[8] * elements[2] * elements[13] +
				elements[12] * elements[1] * elements[10] -
				elements[12] * elements[2] * elements[9];

			temp[2] = elements[1] * elements[6] * elements[15] -
				elements[1] * elements[7] * elements[14] -
				elements[5] * elements[2] * elements[15] +
				elements[5] * elements[3] * elements[14] +
				elements[13] * elements[2] * elements[7] -
				elements[13] * elements[3] * elements[6];

			temp[6] = -elements[0] * elements[6] * elements[15] +
				elements[0] * elements[7] * elements[14] +
				elements[4] * elements[2] * elements[15] -
				elements[4] * elements[3] * elements[14] -
				elements[12] * elements[2] * elements[7] +
				elements[12] * elements[3] * elements[6];

			temp[10] = elements[0] * elements[5] * elements[15] -
				elements[0] * elements[7] * elements[13] -
				elements[4] * elements[1] * elements[15] +
				elements[4] * elements[3] * elements[13] +
				elements[12] * elements[1] * elements[7] -
				elements[12] * elements[3] * elements[5];

			temp[14] = -elements[0] * elements[5] * elements[14] +
				elements[0] * elements[6] * elements[13] +
				elements[4] * elements[1] * elements[14] -
				elements[4] * elements[2] * elements[13] -
				elements[12] * elements[1] * elements[6] +
				elements[12] * elements[2] * elements[5];

			temp[3] = -elements[1] * elements[6] * elements[11] +
				elements[1] * elements[7] * elements[10] +
				elements[5] * elements[2] * elements[11] -
				elements[5] * elements[3] * elements[10] -
				elements[9] * elements[2] * elements[7] +
				elements[9] * elements[3] * elements[6];

			temp[7] = elements[0] * elements[6] * elements[11] -
				elements[0] * elements[7] * elements[10] -
				elements[4] * elements[2] * elements[11] +
				elements[4] * elements[3] * elements[10] +
				elements[8] * elements[2] * elements[7] -
				elements[8] * elements[3] * elements[6];

			temp[11] = -elements[0] * elements[5] * elements[11] +
				elements[0] * elements[7] * elements[9] +
				elements[4] * elements[1] * elements[11] -
				elements[4] * elements[3] * elements[9] -
				elements[8] * elements[1] * elements[7] +
				elements[8] * elements[3] * elements[5];

			temp[15] = elements[0] * elements[5] * elements[10] -
				elements[0] * elements[6] * elements[9] -
				elements[4] * elements[1] * elements[10] +
				elements[4] * elements[2] * elements[9] +
				elements[8] * elements[1] * elements[6] -
				elements[8] * elements[2] * elements[5];

			double determinant = elements[0] * temp[0] + elements[1] * temp[4] + elements[2] * temp[8] + elements[3] * temp[12];
			determinant = 1.0 / determinant;

			for (int i = 0; i < 16; i++)
				elements[i] = temp[i] * determinant;

			return *this;
		}

		//this is based of the Gauss-Jordan elimination method
		template <typename T>
		Matrix4x4<T> Matrix4x4<T>::Inverse(const Matrix4x4<T> &matrix)
		{
		}

		template <typename T>
		Matrix4x4<T> operator*(const Matrix4x4<T> left, const Matrix4x4<T> &right)
		{
			return left.Multiply(right);
		}

		template <typename T>
		Vector3<T> operator*(const Matrix4x4<T> &left, const Vector3<T> &right)
		{
			return left.Multiply(right);
		}

		template <typename T>
		Vector4<T> operator*(const Matrix4x4<T> &left, const Vector4<T> &right)
		{
			return left.Multiply(right);
		}

		template <typename T>
		Matrix4x4<T>& operator*=(Matrix4x4<T> &left, const Matrix4x4<T> &right)
		{
			return left.MultiplyRef(right);
		}
	}
}
