#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MultiPlatformSceneCreatorUpdateConvexSettings.generated.h"

UCLASS(Config=Game)
class UMultiPlatformSceneCreatorUpdateConvexSettings : public UObject
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
	static UMultiPlatformSceneCreatorUpdateConvexSettings* Get();
};
