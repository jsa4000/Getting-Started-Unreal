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
}

void ARollaBallGameModeBase::UpdateItemText()
{
}


void ARollaBallGameModeBase::ItemCollected()
{
	// Increase the Items Collected Counter
	ItemsCollected++;
}
