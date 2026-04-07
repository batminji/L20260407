// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "E_Tier.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class E_Tier : uint8
{
    Epic        UMETA(DisplayName = "Epic"),
    Rare        UMETA(DisplayName = "Rare"),
    Normal      UMETA(DisplayName = "Normal"),
    Legendary   UMETA(DisplayName = "Legendary")
};
