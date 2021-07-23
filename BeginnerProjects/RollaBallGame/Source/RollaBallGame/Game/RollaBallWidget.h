// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RollaBallWidget.generated.h"

/**
 * 
 */
UCLASS()
class ROLLABALLGAME_API URollaBallWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent)
	void SetItemsText(int32 ItemsCollected, int32 ItemsInLevel);
	
};
