// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once

#include "../Source/Math/Math.h"
#include "../Source/Graphics/IShader.h"
#include "../OpenGLContext_Exports.h"

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			using namespace Math;

			class GLShader: public Lavio::Graphics::IShader
			{
			private:
				unsigned int Load() override;
				int GetUniformLocation(const char *name) override;
			public:
				GL_API GLShader(const char *vertPath, const char *fragPath);
				GL_API ~GLShader();

				//TODO: Template?
				void GL_API SetUniform(const char *name, float value) override;
				void GL_API SetUniform(const char *name, int value) override;
				void GL_API SetUniform(const char *name, const Vector2<float> &value) override;
				void GL_API SetUniform(const char *name, const Vector3<float> &value) override;
				void GL_API SetUniform(const char *name, const Vector4<float> &value) override;
				void GL_API SetUniform(const char *name, const Matrix4x4<float> &matrix) override;
				void GL_API SetUniform(const char *name, float *values, int count) override;
				void GL_API SetUniform(const char *name, int *values, int count) override;

				void GL_API Enable() const override;
				void GL_API Disable() const override;

			private:
				GL_API GLShader(const GLShader& other) = delete;
				GL_API GLShader operator=(const GLShader& other) = delete;
			};
		}
	}
}
