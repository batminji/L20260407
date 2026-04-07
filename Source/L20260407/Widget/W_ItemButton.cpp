// Fill out your copyright notice in the Description page of Project Settings.


#include "W_ItemButton.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"

void UW_ItemButton::NativeConstruct()
{
	Super::NativeConstruct();

	if (BTN_Item)
	{
		BTN_Item->OnClicked.AddDynamic(this, &UW_ItemButton::OnItemButtonClicked);
	}
}

void UW_ItemButton::UpdateItemWidget(FName InRowName)
{
	RowName = InRowName;

    if (!DT_Item) return;

    FS_Item* ItemData = DT_Item->FindRow<FS_Item>(RowName, TEXT("FindRow"));

    if (ItemData)
    {
        if (TXT_ItemName)
        {
            TXT_ItemName->SetText(ItemData->Name);
        }
        if (TXT_Desc)
        {
            TXT_Desc->SetText(ItemData->Desc);
        }

        if (TXT_Tier)
        {
            FText TierText = UEnum::GetDisplayValueAsText(ItemData->Tier);
            TXT_Tier->SetText(TierText);
        }

        if (IMG_Icon)
        {
            IMG_Icon->SetBrushFromTexture(ItemData->Image);
        }

        if (Tier_BG)
        {
            Tier_BG->SetContentColorAndOpacity(FLinearColor(ItemData->TierBGColor));
        }
    }
}

void UW_ItemButton::OnItemButtonClicked()
{
    if (OnClickedItem.IsBound())
    {
        OnClickedItem.Broadcast(RowName);
    }
}
