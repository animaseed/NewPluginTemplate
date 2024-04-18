#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SMultiPlatformSceneCreatorNaniteTreePanel : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMultiPlatformSceneCreatorNaniteTreePanel)
	{
	}
	
	SLATE_END_ARGS()

	virtual ~SMultiPlatformSceneCreatorNaniteTreePanel();
	void Construct(const FArguments& InArgs);
	void CreateSettingsView();
	
private:
	TSharedPtr<class IDetailsView> SettingsView;

	static void OnUpdateButtonPressed();
};
