// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "E_Tier.h"
#include "Engine/Texture2D.h"
#include "S_Item.generated.h"
/**
 * 
 */

USTRUCT(BlueprintType)
struct FS_Item : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Desc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    E_Tier Tier;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FColor TierBGColor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TObjectPtr<UTexture2D> Image;
};
