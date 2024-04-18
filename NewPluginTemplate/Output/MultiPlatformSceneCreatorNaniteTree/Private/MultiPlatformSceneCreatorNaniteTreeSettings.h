#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MultiPlatformSceneCreatorNaniteTreeSettings.generated.h"

UCLASS(Config=Game)
class UMultiPlatformSceneCreatorNaniteTreeSettings : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Category = Settings, EditAnywhere)
	TSoftObjectPtr<UStaticMesh> StaticMesh;

	UPROPERTY(Category = Settings, EditAnywhere)
	FFilePath ConvexFbxFilePath;

	UPROPERTY(Category = Settings, EditAnywhere)
	TSoftObjectPtr<UStaticMesh> ConvexStaticMesh;
	
public:
	static UMultiPlatformSceneCreatorNaniteTreeSettings* Get();
};
