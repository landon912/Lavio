// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

//#include "../stdafx.h"
#include "../Source/IO/Utilities/FileUtility.cpp"
#include "../OpenGL.h"
#include "GLShader.h"
#include "../../Debug/Debugging/Log.h"

#include <vector>

namespace Lavio
{
	namespace OpenGL
	{
		namespace Graphics
		{
			GLShader::GLShader(const char *vertPath, const char *fragPath) :
				IShader(vertPath, fragPath)
			{
				mShaderID = GLShader::Load();
			}

			GLShader::~GLShader()
			{
				glDeleteProgram(mShaderID);
			}

			unsigned int GLShader::Load()
			{
				GLuint program = glCreateProgram();
				GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
				GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

				std::string vertSourceString = IO::FileUtility::ReadFile(mVertPath);
				std::string fragSourceString = IO::FileUtility::ReadFile(mFragPath);

				const char *vertSource = vertSourceString.c_str();
				const char *fragmentSource = fragSourceString.c_str();

				//load vertex shader
				glShaderSource(vertex, 1, &vertSource, nullptr);
				glCompileShader(vertex);

				GLint result;
				glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
				if (result == GL_FALSE)
				{
					GLint length;
					glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
					std::vector<char> error(length);
					glGetShaderInfoLog(vertex, length, &length, &error[0]);
					std::string *text = new std::string("Shader Error -> Failed to compile vertex shader! /n");
					text->append(&error[0]);
					Log::DebugLog(text, true);
					glDeleteShader(vertex);
					return 0;
				}

				//load fragment shader
				glShaderSource(fragment, 1, &fragmentSource, nullptr);
				glCompileShader(fragment);


				glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
				if (result == GL_FALSE)
				{
					GLint length;
					glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
					std::vector<char> error(length);
					glGetShaderInfoLog(fragment, length, &length, &error[0]);
					std::string *text = new std::string("Shader Error -> Failed to compile fragment shader! /n");
					text->append(&error[0]);
					Log::DebugLog(text, true);
					glDeleteShader(fragment);
					return 0;
				}

				//attach shaders to program
				glAttachShader(program, vertex);
				glAttachShader(program, fragment);

				glLinkProgram(program);
				glValidateProgram(program);

				//clean up
				glDeleteShader(vertex);
				glDeleteShader(fragment);

				std::string *text = new std::string("Success Loading Shader : ");
				text->append(std::to_string(program));
				Log::DebugLog(text, true);

				return program;
			}

			int GLShader::GetUniformLocation(const char *name)
			{
				return glGetUniformLocation(GLuint(mShaderID), name);
			}

			void GLShader::SetUniform(const char *name, float value)
			{
				glUniform1f(GLint(GetUniformLocation(const_cast<GLchar*>(name))), value);
			}

			void GLShader::SetUniform(const char *name, int value)
			{
				glUniform1i(GLint(GetUniformLocation(const_cast<GLchar*>(name))), value);
			}

			void GLShader::SetUniform(const char *name, const Vector2<float> &value)
			{
				glUniform2f(GLint(GetUniformLocation(const_cast<GLchar*>(name))), value.x, value.y);
			}

			void GLShader::SetUniform(const char *name, const Vector3<float> &value)
			{
				glUniform3f(GLint(GetUniformLocation(const_cast<GLchar*>(name))), value.x, value.y, value.z);
			}

			void GLShader::SetUniform(const char *name, const Vector4<float> &value)
			{
				glUniform4f(GLint(GetUniformLocation(const_cast<GLchar*>(name))), value.x, value.y, value.z, value.w);
			}

			void GLShader::SetUniform(const char *name, const Matrix4x4<float> &matrix)
			{
				glUniformMatrix4fv(GLint(GetUniformLocation(const_cast<GLchar*>(name))), 1, GL_FALSE, matrix.elements);
			}

			void GLShader::SetUniform(const char *name, float *values, int count)
			{
				glUniform1fv(GetUniformLocation(name), count, values);
			}

			void GLShader::SetUniform(const char *name, int *values, int count)
			{
				glUniform1iv(GetUniformLocation(name), count, values);
			}

			void GLShader::Enable() const
			{
				glUseProgram(GLuint(mShaderID));
			}

			void GLShader::Disable() const
			{
				glUseProgram(0);
			}
		}
	}
}
