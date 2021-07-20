// Fill out your copyright notice in the Description page of Project Settings.


#include "AActorTest.h"

#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AAActorTest::AAActorTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");

	PointLight->Intensity = DesiredIntensity;
	Sphere->InitSphereRadius(DesiredRadius);

	RootComponent = PointLight;
	Sphere->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AAActorTest::BeginPlay()
{
	Super::BeginPlay();
	
}


