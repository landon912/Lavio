// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "Layer.h"

namespace Lavio
{
	namespace Graphics
	{
		Layer::Layer(IRenderer2D *renderer, IShader *shader, Matrix4x4<float> projecitonMatrix)
			: mRenderer(renderer), mShader(shader), mProjectionMatrix(projecitonMatrix)
		{
			mShader->Enable();
			mShader->SetUniform("pr_matrix", mProjectionMatrix);
			mShader->Disable();
		}

		Layer::~Layer()
		{
			delete mShader;
			delete mRenderer;
			
			//components(Such as Graphics) are deleted at the destruction of the GameObjects

			/*for(int i = 0; i < mRenderables.size(); i++)
			{
				delete mRenderables[i];
			}*/
		}

		void Layer::Add(Graphic *renderable)
		{
			mRenderables.push_back(renderable);
			mRenderableSize++;
		}

		void Layer::Render()
		{
			if (mTooLarge == false)
			{
				mShader->Enable();
				mRenderer->Begin();

				for (unsigned int i = 0; i < mRenderableSize; i++)
				{
					if (mRenderer->Submit(*mRenderables[i]) == false)
					{
						mTooLarge = true;
						break;
					}
				}

				mRenderer->End();
				mRenderer->Flush();
				mShader->Disable();
			}
		}

		void Layer::ClearRenderables()
		{
			mTooLarge = false;
			mRenderableSize = 0;
			mRenderables.clear();
		}
	}
}
