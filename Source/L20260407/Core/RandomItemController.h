// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RandomItemController.generated.h"

/**
 * 
 */

class UW_Main;

UCLASS()
class L20260407_API ARandomItemController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Widget")
	TSubclassOf<UW_Main> MainWidgetClass;

	UPROPERTY()
	UW_Main* MainWidget;
};
