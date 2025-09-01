#include "Object.h"






SDK::UObject* Object::GetObjectOfClass(const SDK::TSubclassOf<SDK::UObject>& classToSearch)
{
	int32_t objectsNum = SDK::UObject::GObjects->Num();
	for (int i = 0; i < objectsNum; i++)
	{
		SDK::UObject* objectReference = SDK::UObject::GObjects->GetByIndex(i);

		if (objectReference == nullptr || objectReference->IsDefaultObject())
			continue;

		if (objectReference->IsA(classToSearch))
			return objectReference;
	}

	return nullptr;
}

SDK::UObject* Object::GetDefaultObjectOfClass(const SDK::TSubclassOf<SDK::UObject>& classToSearch)
{
	int32_t objectsNum = SDK::UObject::GObjects->Num();
	for (int i = 0; i < objectsNum; i++)
	{
		SDK::UObject* objectReference = SDK::UObject::GObjects->GetByIndex(i);

		if (objectReference == nullptr || objectReference->IsDefaultObject() == false)
			continue;

		if (objectReference->IsA(classToSearch))
			return objectReference;
	}

	return nullptr;
}


std::vector<SDK::UObject*> Object::GetAllObjectsOfClass(const SDK::TSubclassOf<SDK::UObject>& classToSearch)
{
	std::vector<SDK::UObject*> outputArray;

	int32_t objectsNum = SDK::UObject::GObjects->Num();
	for (int i = 0; i < objectsNum; i++)
	{
		SDK::UObject* objectReference = SDK::UObject::GObjects->GetByIndex(i);

		if (objectReference == nullptr || objectReference->IsDefaultObject())
			continue;

		if (objectReference->IsA(classToSearch))
			outputArray.push_back(objectReference);
	}

	return outputArray;
}
