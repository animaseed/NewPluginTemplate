// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiPlatformSceneCreatorUpdateConvexStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Framework/Application/SlateApplication.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FMultiPlatformSceneCreatorUpdateConvexStyle::StyleInstance = nullptr;

void FMultiPlatformSceneCreatorUpdateConvexStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FMultiPlatformSceneCreatorUpdateConvexStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FMultiPlatformSceneCreatorUpdateConvexStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MultiPlatformSceneCreatorUpdateConvexStyle"));
	return StyleSetName;
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FMultiPlatformSceneCreatorUpdateConvexStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("MultiPlatformSceneCreatorUpdateConvexStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("MultiPlatformSceneCreatorUpdateConvex")->GetBaseDir() / TEXT("Resources"));

	Style->Set("MultiPlatformSceneCreatorUpdateConvex.OpenPluginWindow", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));

	return Style;
}

void FMultiPlatformSceneCreatorUpdateConvexStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FMultiPlatformSceneCreatorUpdateConvexStyle::Get()
{
	return *StyleInstance;
}
