// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivalCharacter.h"

// Sets default values
ASurvivalCharacter::ASurvivalCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASurvivalCharacter::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ASurvivalCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASurvivalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind Player Movement Axis Controls
	PlayerInputComponent->BindAxis("MoveForward", this, &ASurvivalCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASurvivalCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ASurvivalCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &ASurvivalCharacter::LookRight);
	// Bind Player Movement Action Controls
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
}

void ASurvivalCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void ASurvivalCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void ASurvivalCharacter::LookUp(float AxisValue)
{
	AddControllerPitchInput(MouseSensitivity * AxisValue);
}

void ASurvivalCharacter::LookRight(float AxisValue)
{
	AddControllerYawInput(MouseSensitivity * AxisValue);
}

