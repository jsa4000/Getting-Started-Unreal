// Fill out your copyright notice in the Description page of Project Settings.


#include "ARollaBallItemBase.h"
#include "RollaBallGame/Game/ARollaBallPlayer.h"

// Sets default values
ARollaBallItemBase::ARollaBallItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create Components
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	// Setup the Root Component and Attach Child Components.
	RootComponent = Mesh;

	// Enable Overlapped Body Physics Events
	Mesh->SetGenerateOverlapEvents(true);
	Mesh->SetCollisionProfileName(TEXT("OverlapAll"));
}

// Called when the game starts or when spawned
void ARollaBallItemBase::BeginPlay()
{
	Super::BeginPlay();

	// Dynamic Events must be put in PostInitializeComponents() or BeginPlay()
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ARollaBallItemBase::OnComponentBeginOverlap);
	
}

void ARollaBallItemBase::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ARollaBallPlayer>(OtherActor))
	{
		GEngine->AddOnScreenDebugMessage(-1,15.0f,FColor::Orange,"Item Collected");
		Collect();
	}
}

void ARollaBallItemBase::Collect_Implementation()
{
	
}


