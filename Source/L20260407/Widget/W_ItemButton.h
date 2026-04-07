// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Data/S_Item"
#include "W_ItemButton.generated.h"

/**
 * 
 */
UCLASS()
class L20260407_API UW_ItemButton : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintCallable)
	void UpdateItemWidget(FName InRowName);

protected:

};
