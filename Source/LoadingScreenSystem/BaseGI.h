// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BaseGI.generated.h"

/**
 * 
 */
UCLASS()
class LOADINGSCREENSYSTEM_API UBaseGI : public UGameInstance
{
	GENERATED_BODY()


public:
	/*Экран загрузки*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LoadingScreen")
		bool bAutoCompleteWhenLoadingCompletes = false;							/** если это правда, загрузочный экран исчезнет, как только все фильмы, играли и загрузка не выполняется. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LoadingScreen")
		bool bMoviesAreSkippable = true;										/** если это правда, фильмы можно пропустить, нажав на экран загрузки как загрузка происходит. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LoadingScreen")
		FString MovieName = "Logo";
	
};
