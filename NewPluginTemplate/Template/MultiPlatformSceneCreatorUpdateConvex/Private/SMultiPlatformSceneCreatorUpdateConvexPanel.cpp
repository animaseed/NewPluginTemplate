#include "SMultiPlatformSceneCreatorUpdateConvexPanel.h"

#include "MultiPlatformSceneCreatorUpdateConvexSettings.h"

#define LOCTEXT_NAMESPACE "SMultiPlatformSceneCreatorUpdateConvexPanel"

DEFINE_LOG_CATEGORY_STATIC(LogSMultiPlatformSceneCreatorUpdateConvexPanel, Log, All);

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

SMultiPlatformSceneCreatorUpdateConvexPanel::~SMultiPlatformSceneCreatorUpdateConvexPanel()
{
}

void SMultiPlatformSceneCreatorUpdateConvexPanel::Construct(const FArguments& InArgs)
{
	CreateSettingsView();

	TSharedRef<SBorder> MainContent = SNew(SBorder)
	.BorderImage(FAppStyle::Get().GetBrush("Brushes.Panel"))
	.Padding(0.0f)
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.VAlign(VAlign_Fill)
		[
			SettingsView->AsShared()
		]
		+ SVerticalBox::Slot()
		  .Padding(10, 5)
		  .AutoHeight()
		[
			SNew(SButton)
			.Text(LOCTEXT("Update", "Update"))
			.HAlign(HAlign_Center)
			.OnPressed_Static(OnUpdateButtonPressed)
		]
	];

	ChildSlot
	[
		MainContent
	];
}

void SMultiPlatformSceneCreatorUpdateConvexPanel::CreateSettingsView()
{
	FPropertyEditorModule& EditModule = FModuleManager::Get().GetModuleChecked<FPropertyEditorModule>("PropertyEditor");

	FDetailsViewArgs DetailsViewArgs;
	DetailsViewArgs.bUpdatesFromSelection = true;
	DetailsViewArgs.bLockable = true;
	DetailsViewArgs.bCustomNameAreaLocation = false;
	DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::ENameAreaSettings::HideNameArea;
	DetailsViewArgs.bCustomFilterAreaLocation = true;
	DetailsViewArgs.DefaultsOnlyVisibility = EEditDefaultsOnlyNodeVisibility::Hide;

	SettingsView = EditModule.CreateDetailView(DetailsViewArgs);

	UMultiPlatformSceneCreatorUpdateConvexSettings* Settings = UMultiPlatformSceneCreatorUpdateConvexSettings::Get();
	SettingsView->SetObject(Settings);
}

void SMultiPlatformSceneCreatorUpdateConvexPanel::OnUpdateButtonPressed()
{
	UMultiPlatformSceneCreatorUpdateConvexSettings* Settings = UMultiPlatformSceneCreatorUpdateConvexSettings::Get();
	TSoftObjectPtr<UStaticMesh> StaticMesh = Settings->StaticMesh;
	const FFilePath& ConvexFbxFilePath = Settings->ConvexFbxFilePath;
	TSoftObjectPtr<UStaticMesh> ConvexStaticMesh = Settings->ConvexStaticMesh;
}


END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE
