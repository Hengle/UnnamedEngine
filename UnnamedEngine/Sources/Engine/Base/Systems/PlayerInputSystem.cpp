#include "PlayerInputSystem.h"

#include "Engine/Base/Managers/EntityAdmin.h"
#include "Engine/Base/Client/Context.h"
#include "Engine/Base/Client/ClientInputManager.h"
#include "Engine/Base/Components/SingletonComponents/InputComponent.h"

PlayerInputSystem::PlayerInputSystem(Ptr<Context> context) :
	mContext(context)
{}

void PlayerInputSystem::Update(float, Ptr<EntityAdmin> e)
{
	Ptr<InputComponent> inputComponent = GetSingletonWriteComponent<InputComponent>(e);
	inputComponent->inputEvents.clear();

	Ptr<ClientInputManager> manager = mContext->GetInputManager();
	while(manager->HasInput())
	{
		InputEvent event = manager->GetInputEvent();
		inputComponent->inputEvents.push_back(event);
	}

	for(const auto& key : KEYMAPPINGS)
	{
		inputComponent->keycodeDown[key.keycode] = manager->KeyIsDown(key.keycode);
	}
	
}

void PlayerInputSystem::StaticInitDependencies()
{
	AddWriteDependency(ComponentGroup<InputComponent>());
}