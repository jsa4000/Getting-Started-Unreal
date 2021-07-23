// Fill out your copyright notice in the Description page of Project Settings.


#include "RollaBallGameModeBase.h"

#include "Kismet/GameplayStatics.h"
#include "RollaBallGame/Items/ARollaBallItemBase.h"


void ARollaBallGameModeBase::BeginPlay()
{
	// Set the total number of ARollaBallItemBase instances added into the level
	TArray<AActor*> Items;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),ARollaBallItemBase::StaticClass(), Items);
	ItemsInLevel = Items.Num();

	if (GameWidgetClass)
	{
		GameWidget = Cast<URollaBallWidget>(CreateWidget(GetWorld(), GameWidgetClass));
			
		if (GameWidget)
		{
			GameWidget->AddToViewport();
			UpdateItemText();
		}
	}
}

void ARollaBallGameModeBase::UpdateItemText()
{
	if (GameWidget)
	{
		//GEngine->AddOnScreenDebugMessage(-1,15.0f,FColor::Orange,
		//	FString::Printf(TEXT("UpdateItemText: %d / %d"),ItemsCollected,ItemsInLevel));

		// Set the the Widget Text Component
		GameWidget->SetItemsText(ItemsCollected, ItemsInLevel);
	}
 }


void ARollaBallGameModeBase::ItemCollected()
{
	// Increase the Items Collected Counter
	ItemsCollected++;
	// Force to Update the Widget
	UpdateItemText();
}
