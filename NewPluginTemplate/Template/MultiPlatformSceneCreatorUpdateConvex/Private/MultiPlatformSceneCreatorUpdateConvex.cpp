// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiPlatformSceneCreatorUpdateConvex.h"
#include "MultiPlatformSceneCreatorUpdateConvexStyle.h"
#include "MultiPlatformSceneCreatorUpdateConvexCommands.h"
#include "SMultiPlatformSceneCreatorUpdateConvexPanel.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"

static const FName MultiPlatformSceneCreatorUpdateConvexTabName("MultiPlatformSceneCreatorUpdateConvex");

#define LOCTEXT_NAMESPACE "FMultiPlatformSceneCreatorUpdateConvexModule"

void FMultiPlatformSceneCreatorUpdateConvexModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FMultiPlatformSceneCreatorUpdateConvexStyle::Initialize();
	FMultiPlatformSceneCreatorUpdateConvexStyle::ReloadTextures();

	FMultiPlatformSceneCreatorUpdateConvexCommands::Register();

	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FMultiPlatformSceneCreatorUpdateConvexCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FMultiPlatformSceneCreatorUpdateConvexModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMultiPlatformSceneCreatorUpdateConvexModule::RegisterMenus));

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(MultiPlatformSceneCreatorUpdateConvexTabName, FOnSpawnTab::CreateRaw(this, &FMultiPlatformSceneCreatorUpdateConvexModule::OnSpawnPluginTab))
	                        .SetDisplayName(LOCTEXT("FMultiPlatformSceneCreatorUpdateConvexTabTitle", "MultiPlatformSceneCreatorUpdateConvex"))
	                        .SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FMultiPlatformSceneCreatorUpdateConvexModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FMultiPlatformSceneCreatorUpdateConvexStyle::Shutdown();

	FMultiPlatformSceneCreatorUpdateConvexCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(MultiPlatformSceneCreatorUpdateConvexTabName);
}

TSharedRef<SDockTab> FMultiPlatformSceneCreatorUpdateConvexModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	TSharedRef<SDockTab> MajorTab = SNew(SDockTab).TabRole(ETabRole::MajorTab);
	MajorTab->SetContent(SNew(SMultiPlatformSceneCreatorUpdateConvexPanel));
	return MajorTab;
}

void FMultiPlatformSceneCreatorUpdateConvexModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(MultiPlatformSceneCreatorUpdateConvexTabName);
}

void FMultiPlatformSceneCreatorUpdateConvexModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList("MultiPlatformSceneCreatorUpdateConvex", FMultiPlatformSceneCreatorUpdateConvexCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FMultiPlatformSceneCreatorUpdateConvexCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMultiPlatformSceneCreatorUpdateConvexModule, MultiPlatformSceneCreatorUpdateConvex)
