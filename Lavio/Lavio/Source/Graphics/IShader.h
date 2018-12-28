// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../Math/Math.h"

namespace Lavio
{
	namespace Graphics
	{
		using namespace Math;

		class IShader
		{
		protected:
			unsigned int mShaderID;
			const char *mVertPath;
			const char *mFragPath;

			virtual unsigned int Load() = 0;
			virtual int GetUniformLocation(const char *name) = 0;
		public:
			IShader(const char *vertPath, const char *fragPath) : mShaderID(0), mVertPath(vertPath), mFragPath(fragPath)
			{
			}

			virtual ~IShader()
			{
			}

			virtual void SetUniform(const char *name, float value) = 0;
			virtual void SetUniform(const char *name, int value) = 0;
			virtual void SetUniform(const char *name, const Vector2<float> &value) = 0;
			virtual void SetUniform(const char *name, const Vector3<float> &value) = 0;
			virtual void SetUniform(const char *name, const Vector4<float> &value) = 0;
			virtual void SetUniform(const char *name, const Matrix4x4<float> &matrix) = 0;
			virtual void SetUniform(const char *name, float *values, int count) = 0;
			virtual void SetUniform(const char *name, int *values, int count) = 0;

			unsigned int GetShaderID() const { return mShaderID; }
			const char* GetShaderVertPath() const { return mVertPath; }
			const char* GetShaderFragPath() const { return mFragPath; }

			virtual void Enable() const = 0;
			virtual void Disable() const = 0;

		public:
			IShader(const IShader &other) = delete;
			IShader& operator=(const IShader& rhs) = delete;
		};
	}
}
