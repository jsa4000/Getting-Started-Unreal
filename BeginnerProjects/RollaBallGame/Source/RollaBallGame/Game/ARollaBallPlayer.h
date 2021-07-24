// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Pawn.h"
#include "ARollaBallPlayer.generated.h"

// References to Class Names instead using includes (.h files)
// (Following Class Names are included during their declaration)
// class UCameraComponent;
// class USpringArmComponent; 

UCLASS()
class ROLLABALLGAME_API ARollaBallPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARollaBallPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// COMPONENTS //
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Player")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
	TObjectPtr<class USpringArmComponent> SpringArm;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
	TObjectPtr<class UCameraComponent> Camera;

	// VARIABLES //
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Roll a Ball", meta = (ClampMin=0.0,ClampMax=99999.0))
	float MoveForce;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Roll a Ball", meta = (ClampMin=0.0,ClampMax=99999.0))
    float JumpImpulse;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Roll a Ball", meta = (ClampMin=0,ClampMax=10))
	int32 MaxJumpCount;
	
public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	// FUNCTIONS //
	void MoveRight(const float Value);
	void MoveForward(const float Value);
	void Jump();

	// Binding to OnComponentHit from Mesh
	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit );
	
	int32 JumpCount;

};
