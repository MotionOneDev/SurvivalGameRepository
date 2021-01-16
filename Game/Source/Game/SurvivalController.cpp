// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivalController.h"
#include "SurvivalCharacter.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/UserWidget.h"

void ASurvivalController::BeginPlay()
{
	Super::BeginPlay();

	PlayerLevel = 1;
	Experience = 0;

	PlayerHUD = CreateWidget<UUserWidget>(this, PlayerHUDClass);

	if (PlayerHUD)
	{
		PlayerHUD->AddToViewport();
	}
}

void ASurvivalController::OpenPauseMenu()
{
	if (PauseMenuClass) //if PauseMenuClass is occupying a UUserWidget do..
	{
		PauseMenu = CreateWidget<UUserWidget>(this, PauseMenuClass);

		if (PauseMenu && bPauseMenuOpen == false)
		{
			PauseMenu->AddToViewport();
			PlayerHUD->RemoveFromParent();
			bPauseMenuOpen = true;
			SetIgnoreLookInput(true);
			SetIgnoreMoveInput(true);
			bShowMouseCursor = true;
		}
	}
}

void ASurvivalController::ClosePauseMenu()
{
	if (PauseMenuClass)
	{
		if (PauseMenu && bPauseMenuOpen == true)
		{
			PauseMenu->RemoveFromParent();
			PlayerHUD->AddToViewport();
			bPauseMenuOpen = false;
			SetIgnoreLookInput(false);
			SetIgnoreMoveInput(false);
			SetInputMode(FInputModeGameOnly());
			bShowMouseCursor = false;
		}
	}
}

void ASurvivalController::CalculateLevel()
{
}

void ASurvivalController::AddExperience()
{
	Experience += 50.f;

	if (Experience >= pow(PlayerLevel * 4, 4))
	{
		PlayerLevel++;
	}
}

