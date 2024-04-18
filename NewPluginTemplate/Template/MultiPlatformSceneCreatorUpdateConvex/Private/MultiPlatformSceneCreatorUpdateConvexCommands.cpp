// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiPlatformSceneCreatorUpdateConvexCommands.h"

#define LOCTEXT_NAMESPACE "FMultiPlatformSceneCreatorUpdateConvexModule"

void FMultiPlatformSceneCreatorUpdateConvexCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "MultiPlatformSceneCreatorUpdateConvex", "Bring up MultiPlatformSceneCreatorUpdateConvex window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
