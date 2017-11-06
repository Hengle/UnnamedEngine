#pragma once

#include "Engine/Base/Types/System.h"

class RenderSystem : public System<RenderSystem> {
public:
	virtual void Update(float dt, Ptr<EntityAdmin> entityAdmin) override;
	virtual void StaticInitDependencies() override;
};

