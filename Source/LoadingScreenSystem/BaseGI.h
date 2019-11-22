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
	/*����� ��������*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LoadingScreen")
		bool bAutoCompleteWhenLoadingCompletes = false;							/** ���� ��� ������, ����������� ����� ��������, ��� ������ ��� ������, ������ � �������� �� �����������. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LoadingScreen")
		bool bMoviesAreSkippable = true;										/** ���� ��� ������, ������ ����� ����������, ����� �� ����� �������� ��� �������� ����������. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "LoadingScreen")
		FString MovieName = "Logo";
	
};
