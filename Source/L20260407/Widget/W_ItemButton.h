// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "L20260407/Data/S_Item.h"
#include "W_ItemButton.generated.h"

class UButton;
class UImage;
class UTextBlock;
class UBorder;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClickedItem, FName, RowName);

UCLASS()
class L20260407_API UW_ItemButton : public UUserWidget
{
	GENERATED_BODY()
	
public:
    virtual void NativeConstruct() override;

    UPROPERTY(BlueprintAssignable)
    FOnClickedItem OnClickedItem;

    UFUNCTION(BlueprintCallable)
    void UpdateItemWidget(FName InRowName);

    UFUNCTION(BlueprintCallable)
    void SetButtonDisabled();

    UFUNCTION(BlueprintImplementable, Category = "Button")
    void SetButtonClicked();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* DT_Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName RowName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsClicked;

    UFUNCTION()
    void OnItemButtonClicked();

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UButton* BTN_Item;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UImage* IMG_Icon;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UTextBlock* TXT_ItemName;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UTextBlock* TXT_Tier;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UBorder* Tier_BG;

    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    UTextBlock* TXT_Desc;
};
