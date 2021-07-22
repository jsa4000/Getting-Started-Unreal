// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ARollaBallItemBase.generated.h"

UCLASS()
class ROLLABALLGAME_API ARollaBallItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARollaBallItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// COMPONENTS //
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Player")
	UStaticMeshComponent* Mesh;

	UFUNCTION(BlueprintNativeEvent)
	void Collect();

private:

	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

};
