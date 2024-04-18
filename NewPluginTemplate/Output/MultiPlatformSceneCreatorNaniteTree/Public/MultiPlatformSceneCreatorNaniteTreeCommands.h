// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MultiPlatformSceneCreatorNaniteTreeStyle.h"

class FMultiPlatformSceneCreatorNaniteTreeCommands : public TCommands<FMultiPlatformSceneCreatorNaniteTreeCommands>
{
public:

	FMultiPlatformSceneCreatorNaniteTreeCommands()
		: TCommands<FMultiPlatformSceneCreatorNaniteTreeCommands>(TEXT("MultiPlatformSceneCreatorNaniteTree"), NSLOCTEXT("Contexts", "MultiPlatformSceneCreatorNaniteTree", "MultiPlatformSceneCreatorNaniteTree Plugin"), NAME_None, FMultiPlatformSceneCreatorNaniteTreeStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};