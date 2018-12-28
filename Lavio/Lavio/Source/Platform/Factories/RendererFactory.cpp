// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "RendererFactory.h"
#include "../../OpenGLContext/Renderer/GLSimple2DRenderer.h"
#include "../../OpenGLContext/Renderer/GLBatch2DRenderer.h"
#include "../../../Debug/Debugging/Log.h"
#include "../../../../OpenGLContext/Renderer/GLFontRenderer.h"

namespace Lavio
{
	namespace API
	{
		IRenderer2D* RendererFactory::Create2DRenderer(RenderAPI api, bool batching)
		{
			switch (api)
			{
				case RenderAPI::OpenGL:
					if (batching)
						return dynamic_cast<IRenderer2D*>(new OpenGL::Graphics::GLBatchRenderer2D());
					//return dynamic_cast<IRenderer2D*>(new OpenGL::Graphics::GLSimple2DRenderer());
				default:
					Log::DebugLog("Renderer Factory Error -> No Renderer Module for this API!");
					return nullptr;
			}
		}

		IRenderer2D* RendererFactory::CreateFontRenderer(RenderAPI api)
		{
			switch (api)
			{
			case RenderAPI::OpenGL:
					return dynamic_cast<IRenderer2D*>(new OpenGL::Graphics::GLFontRenderer());
			default:
				Log::DebugLog("Renderer Factory Error -> No Renderer Module for this API!");
				return nullptr;
			}
		}
	}
}
