// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MultiPlatformSceneCreatorUpdateConvexStyle.h"

class FMultiPlatformSceneCreatorUpdateConvexCommands : public TCommands<FMultiPlatformSceneCreatorUpdateConvexCommands>
{
public:

	FMultiPlatformSceneCreatorUpdateConvexCommands()
		: TCommands<FMultiPlatformSceneCreatorUpdateConvexCommands>(TEXT("MultiPlatformSceneCreatorUpdateConvex"), NSLOCTEXT("Contexts", "MultiPlatformSceneCreatorUpdateConvex", "MultiPlatformSceneCreatorUpdateConvex Plugin"), NAME_None, FMultiPlatformSceneCreatorUpdateConvexStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};