#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SMultiPlatformSceneCreatorUpdateConvexPanel : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMultiPlatformSceneCreatorUpdateConvexPanel)
	{
	}
	
	SLATE_END_ARGS()

	virtual ~SMultiPlatformSceneCreatorUpdateConvexPanel();
	void Construct(const FArguments& InArgs);
	void CreateSettingsView();
	
private:
	TSharedPtr<class IDetailsView> SettingsView;

	static void OnUpdateButtonPressed();
};
