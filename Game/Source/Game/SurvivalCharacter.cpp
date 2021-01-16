// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivalCharacter.h"
#include "SurvivalController.h"
#include "Blueprint/UserWidget.h"

// Sets default values
ASurvivalCharacter::ASurvivalCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ASurvivalController* SurvivalController = Cast<ASurvivalController>(Controller);
	
	//Child actor class definitions
	CharacterMesh = CreateDefaultSubobject<USkeletalMeshComponent>("CharacterMesh");
	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>("Camera");
	CharacterMesh->SetupAttachment(RootComponent);

	// Spring Arm setup
	CameraSpringArm->SetupAttachment(CharacterMesh);
	CameraSpringArm->SetRelativeLocation(FVector(-30.f, 0.f, 150.f));
	CameraSpringArm->bUsePawnControlRotation = true;
	CameraSpringArm->TargetArmLength = 200.f;

	PlayerCamera->SetupAttachment(CameraSpringArm);

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
	// Bind Player Widget Controls
	PlayerInputComponent->BindAction("PauseMenu", IE_Pressed, this, &ASurvivalCharacter::OpenPauseMenu);

	// TEST BINDING
	PlayerInputComponent->BindAction("AddXP", IE_Pressed, this, &ASurvivalCharacter::AddExperience);
}

void ASurvivalCharacter::OpenPauseMenu()
{
	ASurvivalController* SurvivalController = Cast<ASurvivalController>(Controller);

	if (SurvivalController->bPauseMenuOpen == false)
	{
		SurvivalController->OpenPauseMenu();
	}
	else
	{
		SurvivalController->ClosePauseMenu();
	}
}

void ASurvivalCharacter::AddExperience()
{
	ASurvivalController* SurvivalController = Cast<ASurvivalController>(Controller);

	SurvivalController->AddExperience();
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

