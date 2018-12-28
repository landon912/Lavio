// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#include "World.h"
#include "Platform/Factories/InputFactory.h"

namespace Lavio
{
	World *World::worldInstance = nullptr;

	World::World(Graphics::IWindow *window, API::APIManager *api)
	{
		Log::DebugLog("Created World");
		Window = window;
		this->APIManager = api;
		LoadInput();
	}

	void World::LoadInput()
	{
		Input = API::InputFactory::CreateInput(APIManager->GetCurrentAPI());
		Window->AssignedInputModule = Input;
		Input->SetContextCallbacks(Window->GetWindow());
	}

	World::~World()
	{
		delete Window;
		delete Input;
		delete APIManager;
		delete FontManager;
	}
}
