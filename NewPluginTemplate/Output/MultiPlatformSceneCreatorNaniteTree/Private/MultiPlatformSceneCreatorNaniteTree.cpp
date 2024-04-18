// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiPlatformSceneCreatorNaniteTree.h"
#include "MultiPlatformSceneCreatorNaniteTreeStyle.h"
#include "MultiPlatformSceneCreatorNaniteTreeCommands.h"
#include "SMultiPlatformSceneCreatorNaniteTreePanel.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"

static const FName MultiPlatformSceneCreatorNaniteTreeTabName("MultiPlatformSceneCreatorNaniteTree");

#define LOCTEXT_NAMESPACE "FMultiPlatformSceneCreatorNaniteTreeModule"

void FMultiPlatformSceneCreatorNaniteTreeModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FMultiPlatformSceneCreatorNaniteTreeStyle::Initialize();
	FMultiPlatformSceneCreatorNaniteTreeStyle::ReloadTextures();

	FMultiPlatformSceneCreatorNaniteTreeCommands::Register();

	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FMultiPlatformSceneCreatorNaniteTreeCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FMultiPlatformSceneCreatorNaniteTreeModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMultiPlatformSceneCreatorNaniteTreeModule::RegisterMenus));

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(MultiPlatformSceneCreatorNaniteTreeTabName, FOnSpawnTab::CreateRaw(this, &FMultiPlatformSceneCreatorNaniteTreeModule::OnSpawnPluginTab))
	                        .SetDisplayName(LOCTEXT("FMultiPlatformSceneCreatorNaniteTreeTabTitle", "MultiPlatformSceneCreatorNaniteTree"))
	                        .SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FMultiPlatformSceneCreatorNaniteTreeModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FMultiPlatformSceneCreatorNaniteTreeStyle::Shutdown();

	FMultiPlatformSceneCreatorNaniteTreeCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(MultiPlatformSceneCreatorNaniteTreeTabName);
}

TSharedRef<SDockTab> FMultiPlatformSceneCreatorNaniteTreeModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	TSharedRef<SDockTab> MajorTab = SNew(SDockTab).TabRole(ETabRole::MajorTab);
	MajorTab->SetContent(SNew(SMultiPlatformSceneCreatorNaniteTreePanel));
	return MajorTab;
}

void FMultiPlatformSceneCreatorNaniteTreeModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(MultiPlatformSceneCreatorNaniteTreeTabName);
}

void FMultiPlatformSceneCreatorNaniteTreeModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList("MultiPlatformSceneCreatorNaniteTree", FMultiPlatformSceneCreatorNaniteTreeCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FMultiPlatformSceneCreatorNaniteTreeCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMultiPlatformSceneCreatorNaniteTreeModule, MultiPlatformSceneCreatorNaniteTree)
