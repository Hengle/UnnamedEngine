#pragma once
#include "Engine/Base/Common/Common.h"
#include "Engine/Base/Types/ComponentBase.h"

class Serializer;

typedef uint64_t ComponentFlag;
static ComponentFlag sComponentGroup = 0;

template <typename Derived>
class Component : public ComponentBase {
public:
	Component() {}

	static ComponentFlag GetGroup()
	{
		static const int group = sComponentGroup++;
		return(group);
	}

	std::string GetName()
	{
		return(sName);
	}

	virtual Serializer& Serialize(Serializer& s) { return(s); }

protected:
	static std::string sName;
	static bool sSerializable;
};
