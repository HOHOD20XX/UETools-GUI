#pragma once
#include "SDK\Engine_classes.hpp"

#include <vector>






class Object
{
public:
	static SDK::UObject* GetObjectOfClass(const SDK::TSubclassOf<SDK::UObject>& classToSearch);
	static SDK::UObject* GetDefaultObjectOfClass(const SDK::TSubclassOf<SDK::UObject>& classToSearch);

	static std::vector<SDK::UObject*> GetAllObjectsOfClass(const SDK::TSubclassOf<SDK::UObject>& classToSearch);
};

