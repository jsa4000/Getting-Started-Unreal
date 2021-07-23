// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "RollaBallWidget.h"
#include "GameFramework/GameModeBase.h"
#include "RollaBallGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ROLLABALLGAME_API ARollaBallGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	void ItemCollected();
	
protected:

	int32 ItemsCollected = 0;
	int32 ItemsInLevel = 0;

	UPROPERTY(EditAnywhere, Category="Widgets")
	TSubclassOf<class UUserWidget> GameWidgetClass;

	UPROPERTY()
	TObjectPtr<URollaBallWidget> GameWidget;
	
	virtual void BeginPlay() override;

	void UpdateItemText();

};
