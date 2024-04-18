// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiPlatformSceneCreatorNaniteTreeStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Framework/Application/SlateApplication.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FMultiPlatformSceneCreatorNaniteTreeStyle::StyleInstance = nullptr;

void FMultiPlatformSceneCreatorNaniteTreeStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FMultiPlatformSceneCreatorNaniteTreeStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FMultiPlatformSceneCreatorNaniteTreeStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MultiPlatformSceneCreatorNaniteTreeStyle"));
	return StyleSetName;
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FMultiPlatformSceneCreatorNaniteTreeStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("MultiPlatformSceneCreatorNaniteTreeStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("MultiPlatformSceneCreatorNaniteTree")->GetBaseDir() / TEXT("Resources"));

	Style->Set("MultiPlatformSceneCreatorNaniteTree.OpenPluginWindow", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));

	return Style;
}

void FMultiPlatformSceneCreatorNaniteTreeStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FMultiPlatformSceneCreatorNaniteTreeStyle::Get()
{
	return *StyleInstance;
}
