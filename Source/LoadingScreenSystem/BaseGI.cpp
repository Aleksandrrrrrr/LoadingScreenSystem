// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGI.h"
#include "MoviePlayer.h"
#include "MoviePlayer/Public/MoviePlayer.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Images/SThrobber.h"
#include "Engine.h"

void UBaseGI::Init()
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UBaseGI::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UBaseGI::EndLoadingScreen);
}

class SMyLoadingScreenTestWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMyLoadingScreenTestWidget) {}
	SLATE_END_ARGS()

		void Construct(const FArguments& InArgs)
	{
		ChildSlot
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
			.VAlign(VAlign_Bottom)
			.HAlign(HAlign_Center)
			[
				SNew(SThrobber)
				.Visibility(this, &SMyLoadingScreenTestWidget::GetLoadIndicatorVisibility)
			]
		+ SVerticalBox::Slot()
			.VAlign(VAlign_Bottom)
			.HAlign(HAlign_Center)
			[
				SNew(STextBlock)
				.Font(FCoreStyle::GetDefaultFontStyle("Regular", 24))
			.Text(NSLOCTEXT("MoviePlayerTestLoadingScreen", "LoadingComplete", "Loading complete! Press any key."))
			.Visibility(this, &SMyLoadingScreenTestWidget::GetMessageIndicatorVisibility)
			]
			];
	}

private:
	EVisibility GetLoadIndicatorVisibility() const
	{
		return GetMoviePlayer()->IsLoadingFinished() ? EVisibility::Collapsed : EVisibility::Visible;
	}

	EVisibility GetMessageIndicatorVisibility() const
	{
		return GetMoviePlayer()->IsLoadingFinished() ? EVisibility::Visible : EVisibility::Collapsed;
	}
};


void UBaseGI::BeginLoadingScreen(const FString& InMapName)
{
	if (!IsRunningDedicatedServer())
	{
		FLoadingScreenAttributes  LoadingScreen;
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = bAutoCompleteWhenLoadingCompletes;
		LoadingScreen.bMoviesAreSkippable = bMoviesAreSkippable;
		LoadingScreen.MoviePaths.Add(MovieName);
		LoadingScreen.WidgetLoadingScreen = SNew(SMyLoadingScreenTestWidget);
		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
		
	}
}

void UBaseGI::EndLoadingScreen(UWorld* InLoadedWorld)
{
	//if (GEngine)
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, MovieName);
}