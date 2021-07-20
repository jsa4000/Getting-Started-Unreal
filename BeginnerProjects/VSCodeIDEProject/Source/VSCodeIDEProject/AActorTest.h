// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AActorTest.generated.h"

UCLASS()
class VSCODEIDEPROJECT_API AAActorTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAActorTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** the desired intensity for the light */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Switch Variables")
	float DesiredIntensity = 3000.0f;

	/** the desired intensity for the light */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Switch Variables")
	float DesiredRadius = 250.0f;

	/** point light component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Switch Components")
	class UPointLightComponent* PointLight;

	/** sphere component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Switch Components")
	class USphereComponent* Sphere;

};
