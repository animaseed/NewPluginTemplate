#include "MultiPlatformSceneCreatorNaniteTreeSettings.h"


UMultiPlatformSceneCreatorNaniteTreeSettings* UMultiPlatformSceneCreatorNaniteTreeSettings::Get()
{
	static UMultiPlatformSceneCreatorNaniteTreeSettings* DefaultObject;

	if (!DefaultObject)
	{
		DefaultObject = DuplicateObject(GetMutableDefault<UMultiPlatformSceneCreatorNaniteTreeSettings>(), nullptr);
		DefaultObject->AddToRoot();
	}

	return DefaultObject;
}
