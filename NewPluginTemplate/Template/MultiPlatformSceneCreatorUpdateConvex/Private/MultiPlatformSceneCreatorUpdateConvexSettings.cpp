#include "MultiPlatformSceneCreatorUpdateConvexSettings.h"


UMultiPlatformSceneCreatorUpdateConvexSettings* UMultiPlatformSceneCreatorUpdateConvexSettings::Get()
{
	static UMultiPlatformSceneCreatorUpdateConvexSettings* DefaultObject;

	if (!DefaultObject)
	{
		DefaultObject = DuplicateObject(GetMutableDefault<UMultiPlatformSceneCreatorUpdateConvexSettings>(), nullptr);
		DefaultObject->AddToRoot();
	}

	return DefaultObject;
}
