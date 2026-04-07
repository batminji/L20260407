// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "L20260407/Data/S_Item.h"
#include "W_ItemButton.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClickedItemSignature, FName, RowName);

UCLASS()
class L20260407_API UW_ItemButton : public UUserWidget
{
	GENERATED_BODY()
	
public:
    virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* DT_Item;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName RowName;

	UPROPERTY(BlueprintAssignable)
	FOnClickedItemSignature OnClickedItem;

	UFUNCTION(BlueprintCallable)
	void UpdateItemWidget(FName InRowName);

    UFUNCTION()
    void OnItemButtonClicked();

    UPROPERTY(meta = (BindWidget))
    class UButton* BTN_Item;

    UPROPERTY(meta = (BindWidget))
    class UImage* IMG_Icon;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* TXT_ItemName;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* TXT_Tier;

    UPROPERTY(meta = (BindWidget))
    class UBorder* Tier_BG;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* TXT_Desc;
};
