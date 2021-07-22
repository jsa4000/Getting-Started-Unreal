// Fill out your copyright notice in the Description page of Project Settings.


#include "ARollaBallPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AARollaBallPlayer::AARollaBallPlayer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Create Components
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	// Setup the Root Component and Attach Child Components.
	Camera->SetupAttachment(SpringArm);
	SpringArm->SetupAttachment(Mesh);
	RootComponent = Mesh;

	// Enable Physics since player uses forces for the movements
	Mesh->SetSimulatePhysics(true);
	// Enable Simulation Generates Hit Events
	Mesh->SetNotifyRigidBodyCollision(true);

	// Disable Parent rotation inheritance
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritYaw = false;
	
	// Initialize default variables. It is recommended does not modify the header file as much as possible.
	MoveForce = 500.0f;
	JumpImpulse = 500.0f;
	MaxJumpCount = 1;
	JumpCount = 0;
}

// Called when the game starts or when spawned
void AARollaBallPlayer::BeginPlay()
{
	Super::BeginPlay();

	// Dynamic Events must be put in PostInitializeComponents() or BeginPlay()
	Mesh->OnComponentHit.AddDynamic(this, &AARollaBallPlayer::OnComponentHit);

	// Account for Mass in forces applied to the mesh
	MoveForce *= Mesh->GetMass();
	JumpImpulse *= Mesh->GetMass();
}

void AARollaBallPlayer::MoveRight(const float Value)
{
	// Get the right vector (local)	of the Camera and applied to the Force and Input Value
	const FVector Right = Camera->GetRightVector() * MoveForce * Value;
	Mesh->AddForce(Right);
}

void AARollaBallPlayer::MoveForward(const float Value)
{
	// Get the forward vector (local) of the Camera and applied to the Force and Input Value
	const FVector Forward = Camera->GetForwardVector() * MoveForce * Value;
	Mesh->AddForce(Forward);
}

void AARollaBallPlayer::Jump()
{
	// Compare current jump count with the maximum
	if (JumpCount >= MaxJumpCount) return;
	// Use the UP vector (Z Axis) and multiply by the Jump Impulse
	Mesh->AddImpulse(FVector::UpVector * JumpImpulse);
	// Increase the Jump Count 
	JumpCount ++;
}

void AARollaBallPlayer::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//UE_LOG(LogTemp, Warning, TEXT("AARollaBallPlayer::OnComponentHit has been called"));
	//GEngine->AddOnScreenDebugMessage(-1,15.0f,FColor::Orange,
	//	FString::Printf(TEXT("Z Normal: %f"),Hit.Normal.Z));
	
	// Check if the Z direction (collision) is positive. (Normal to the surface)
	if (Hit.Normal.Z > 0)
	{
		// Initialize the Jump Count to zero
		JumpCount = 0;
	}
}

// Called to bind functionality to input
void AARollaBallPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Custom Input Axis Bindings
	InputComponent->BindAxis("MoveForward", this, &AARollaBallPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AARollaBallPlayer::MoveRight);

	// Custom Input Action Bindings
	InputComponent->BindAction("Jump", IE_Pressed, this, &AARollaBallPlayer::Jump);
}
