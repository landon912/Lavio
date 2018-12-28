// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "Source/Math/Math.h"
#include "Source/World.h"
#include "Source/IO/Utilities/Timer.h"
#include "Source/Graphics/Layers/TileLayer.h"
#include "Source/Platform/Factories/WindowFactory.h"
#include "Source/Platform/Factories/ShaderFactory.h"
#include "Source/Platform/APIManager.h"
#include "Source/Objects/GameObject.h"
#include "Source/Objects/Transform.h"

//TEMP
#include "Source/Graphics/Textures/ImageLoader.h"
#include "Source/Platform/Factories/TextureFactory.h"
#include "Source/Graphics/GUI/Label.h"
#include "Source/Graphics/Layers/FontLayer.h"
#include "Source/Graphics/GUI/FontManager.h"
#include "Source/Platform/Factories/FontFactory.h"

int main()
{
	using namespace Lavio;
	using namespace Graphics;
	using namespace Math;
	using namespace API;

	APIManager *apiManager = new APIManager(RenderAPI::OpenGL);

	IWindow *window = WindowFactory::CreateLavioWindow(apiManager->GetCurrentAPI(), "Lavio", 1080, 640);

	World::CreateInstance(window, apiManager);
	World::GetInstance().LoadFontManager();
	
	
	GameObject* test = new GameObject(new std::string("Test"), Vector3<float>(0, 0, 0), Vector3<float>(0, 0, 0));
	GameObject* testChild = new GameObject(new std::string("Child"), Vector3<float>(0, 0, 0), Vector3<float>(0, 0, 0));
	testChild->GetTransform().SetTransformParent(&test->GetTransform());
	GameObject* test2 = new GameObject(new std::string("Stdupid"), Vector3<float>(0, 0, 0), Vector3<float>(0, 0, 0));
	*test2 = *test;

	IShader *shader = ShaderFactory::CreateShader(apiManager->GetCurrentAPI(), "C:/Users/landon/Documents/lavio/Lavio/Lavio/Source/Platform/OpenGL/Shader/basic.vert", "C:/Users/landon/Documents/lavio/Lavio/Lavio/Source/Platform/OpenGL/Shader/basic.frag");
	TileLayer layer(shader);

	IShader *fontShader = ShaderFactory::CreateShader(apiManager->GetCurrentAPI(), "C:/Users/landon/Documents/lavio/Lavio/Lavio/Source/Platform/OpenGL/Shader/basic.vert", "C:/Users/landon/Documents/lavio/Lavio/Lavio/Source/Platform/OpenGL/Shader/font.frag");
	FontLayer fontLayer(fontShader);

	//should use projection matrix info for layout
	GameObject *GUIOrigin = new GameObject(new std::string("Top Left Origin"), Vector3<float>(-8, 4.5f, 0), Vector3<float>(0, 0, 0));

	GameObject *origin = new GameObject(new std::string("Origin"), Vector3<float>(0, 0, 0), Vector3<float>(0, 0, 0));

	World::GetInstance().FontManager->Add(FontFactory::CreateFont(World::GetInstance().APIManager->GetCurrentAPI(), "Arial", "Arial.ttf", 16));

	std::string *text = new std::string("");
	GUI::Label *stringLabel = new GUI::Label(*text, *World::GetInstance().FontManager->Get("Arial"), Color(0,0,0,255), *fontShader);

	GameObject *labelObject = new GameObject(new std::string("Label Test"), Vector3<float>(0, -0.4f, 0), Vector3<float>(0, 0, 0));
	labelObject->AddComponent(stringLabel);
	labelObject->GetTransform().SetTransformParent(&GUIOrigin->GetTransform());
	fontLayer.Add(stringLabel);

	//ImageData *spiderData = ImageLoader::LoadImageData("SpiderV1.png");
	//ITexture *spiderTexture = TextureFactory::CreateTexture(apiManager->GetCurrentAPI(), spiderData);
	//Sprite *spiderSprite = new Sprite(true, Vector2<float>(5, 5), *spiderTexture, *shader);

	//GameObject *spiderObj = new GameObject(new std::string("Spider Obj"), Vector3<float>(0, 0, 0), Vector3<float>(0, 0, 0));
	//spiderObj->AddComponent(spiderSprite);
	//layer.Add(spiderSprite);

	//ImageData *data = ImageLoader::LoadImageData("Test.png");
	//ITexture *dataTexture = TextureFactory::CreateTexture(apiManager->GetCurrentAPI(), data);
	//Sprite *dataSprite = new Sprite(true, Vector2<float>(5, 5), *dataTexture, *shader);

	//GameObject *dataObj = new GameObject(new std::string("Test Obj"), Vector3<float>(0, 0, 0), Vector3<float>(0, 0, 0));
	//dataObj->AddComponent(dataSprite);
	//layer.Add(dataSprite);

	ImageData *data = ImageLoader::LoadImageData("Test.png");
	ImageData *data2 = ImageLoader::LoadImageData("Test1.png");
	ImageData *data3 = ImageLoader::LoadImageData("Test2.png");

	ITexture **textures = new ITexture*[3];
	textures[0] = TextureFactory::CreateTexture(apiManager->GetCurrentAPI(), data);
	textures[1] = TextureFactory::CreateTexture(apiManager->GetCurrentAPI(), data2);
	textures[2] = TextureFactory::CreateTexture(apiManager->GetCurrentAPI(), data3);

	GameObject *s1 = new GameObject(new std::string("Sprite1"), Vector3<float>(0, 0, 0), Vector3<float>(0, 0, 0));
	layer.Add(s1->AddComponent(new Graphic(true, Vector2<float>(1.5f, 1.5f), *textures[0], *shader)));
	
	GameObject *s2 = new GameObject(new std::string("Sprite2"), Vector3<float>(1.5f, 1.5f, 0), Vector3<float>(0, 0, 0));
	layer.Add(s2->AddComponent(new Graphic(true, Vector2<float>(1.5f, 1.5f), *textures[1], *shader)));
	
	GameObject *s3 = new GameObject(new std::string("Sprite3"), Vector3<float>(3, 3, 0), Vector3<float>(0, 0, 0));
	layer.Add(s3->AddComponent(new Graphic(true, Vector2<float>(1.5f, 1.5f), *textures[2], *shader)));


	/*GameObject** objects = new GameObject*[576];

	int total = 0;
	for (float y = -9; y < 9; y += 1)
	{
		for (float x = -16; x < 16; x += 1)
		{
			GameObject *s = new GameObject(new std::string("Sprite"), Vector3<float>(x, y, 0), Vector3<float>(0, 0, 0));
			s->GetTransform().SetTransformParent(&origin->GetTransform());
			if (rand() % 4)
			{
				layer.Add(s->AddComponent(new Graphic(true, Vector2<float>(1.5f, 1.5f), *textures[rand() % 3], *shader)));
			}
			else
			{
				layer.Add(s->AddComponent(new Graphic(true, Vector2<float>(1.5, 1.5), ColorSet::Red, *shader)));
			}

			objects[total++] = s;
		}
	}*/

	int texIDs[] =
		{
			0,1,2,3,4,5,6,7,8,9
		};

	shader->Enable();
	shader->SetUniform("textures", texIDs, 10);
	shader->Disable();

	fontShader->Enable();
	fontShader->SetUniform("textures", texIDs, 10);
	fontShader->Disable();

	Timer timer;
	float time = 0;
	unsigned int frames = 0;
	while (!window->Closed())
	{
		window->Clear();

		Vector2<double> mousePos = World::GetInstance().Input->GetMousePosition();
		Vector2<float> lightPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		lightPosition.x = lightPosition.x * 32.0f / World::GetInstance().Window->GetWidth() - 16.0f;
		lightPosition.y = 9.0f - lightPosition.y * 18.0f / World::GetInstance().Window->GetHeight();

		//Vector3<float> currentPos = spiderObj->GetTransform().GetPosition(true);
		//spiderObj->GetTransform().SetPosition(Vector3<float>(currentPos.x + sin(time.Elapsed()/1000.0f)/2000.0f, currentPos.y + cos(time.Elapsed()/1000.0f)/2000.0f, currentPos.z));

		shader->Enable();
		shader->SetUniform("light_pos", lightPosition);
		shader->Disable();

		const std::vector<Graphic*>& renderables = layer.GetRenderables();
		for (int i = 0; i < renderables.size(); i++)
		{
			int c = abs(sin(timer.ElapsedSeconds())) * 255;
			renderables[i]->SetColor(Color(c, c, c, 255));
		}

		layer.Render();

		fontLayer.Render();

		window->Update();

		frames++;
		if (timer.Elapsed() - time > 1000)
		{
			time += 1000;
			stringLabel->text = std::to_string(frames) + " FPS";
			frames = 0;
		}
	}

	World::DestroyInstance();
	delete origin;
	delete GUIOrigin;

	for(int i = 0; i < 3; i++)
	{
		delete textures[i];
	}
	delete[] textures;

	//for(int i = 0; i < 576; i++)
	//{
	//	delete objects[i];
	//}
	//delete[] objects;

	delete s1;
	delete s2;
	delete s3;

	return 0;
}
