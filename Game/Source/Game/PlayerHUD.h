// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class GAME_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:

	APlayerHUD();

	virtual void DrawHUD() override;

	virtual void BeginPlay() override;
	
private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> PlayerHUDClass;

	UPROPERTY(EditAnywhere)
	class UUserWidget* PlayerHUD;
};
