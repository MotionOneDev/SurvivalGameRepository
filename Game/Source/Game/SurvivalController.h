// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SurvivalController.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API ASurvivalController : public APlayerController
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> PauseMenuClass;

	UUserWidget* PauseMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> PlayerHUDClass;

	UUserWidget* PlayerHUD;

	// Override BeginPlay()
	virtual void BeginPlay() override;

	// Player Variables

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 PlayerLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Experience;

	UPROPERTY(EditAnywhere)
	float PlayerCurrency;

	void CalculateLevel();

	void AddExperience();
	
	
	// Menu functions
	void OpenPauseMenu();

	UFUNCTION(BlueprintCallable)
	void ClosePauseMenu();
	
	bool bPauseMenuOpen = false;

	//Camera Options Settings
	float CameraFOV = 90.f;
};
