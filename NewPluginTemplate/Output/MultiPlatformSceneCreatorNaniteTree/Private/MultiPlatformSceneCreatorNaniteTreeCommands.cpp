// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiPlatformSceneCreatorNaniteTreeCommands.h"

#define LOCTEXT_NAMESPACE "FMultiPlatformSceneCreatorNaniteTreeModule"

void FMultiPlatformSceneCreatorNaniteTreeCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "MultiPlatformSceneCreatorNaniteTree", "Bring up MultiPlatformSceneCreatorNaniteTree window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
