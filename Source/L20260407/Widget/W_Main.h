// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "W_Main.generated.h"

/**
 * 
 */

class UWrapBox;
class UTextBlock;
class UButton;
class UW_ItemButton;

UCLASS()
class L20260407_API UW_Main : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

protected:
	void RefreshItems();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* DT_Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FName> RowNames;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RandomCnt;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UWrapBox* WrapBox;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TXT_SelectLog;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* BTN_Refresh;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UW_ItemButton> ItemButtonClass;

	UFUNCTION()
	void OnRefreshButtonClicked();

	void ShuffleRowNames();
	void AddRandomItem();

	void UpdateSelectLog(FName RowName);
	void UpdateButtonEnabled();

	UFUNCTION()
	void OnClickedItem(FName RowName);
};
