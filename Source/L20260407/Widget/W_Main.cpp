// Fill out your copyright notice in the Description page of Project Settings.


#include "W_Main.h"
#include "Components/WrapBox.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Algo/RandomShuffle.h"
#include "W_ItemButton.h"
#include "L20260407/Data/S_Item.h"

void UW_Main::NativeConstruct()
{
	Super::NativeConstruct();

	RandomCnt = 3;

	if (BTN_Refresh)
	{
		BTN_Refresh->OnClicked.AddDynamic(this, &UW_Main::OnRefreshButtonClicked);
	}

	if (DT_Item)
	{
		RowNames = DT_Item->GetRowNames();
	}

	RefreshItems();
}

void UW_Main::RefreshItems()
{
	WrapBox->ClearChildren();

	ShuffleRowNames();
	AddRandomItem();

	TXT_SelectLog->SetVisibility(ESlateVisibility::Hidden);
}

void UW_Main::OnRefreshButtonClicked()
{
	RefreshItems();
}

void UW_Main::ShuffleRowNames()
{
	Algo::RandomShuffle(RowNames);
}

void UW_Main::AddRandomItem()
{
	if (!ItemButtonClass)
	{
		return;
	}

	for (int32 i = 0; i < RandomCnt; ++i)
	{
		UW_ItemButton* ItemButton = CreateWidget<UW_ItemButton>(GetOwningPlayer(), ItemButtonClass);
		if (ItemButton)
		{
			ItemButton->UpdateItemWidget(RowNames[i]);
			ItemButton->OnClickedItem.AddDynamic(this, &UW_Main::OnClickedItem);
			WrapBox->AddChild(ItemButton);
		}
	}
}

void UW_Main::UpdateSelectLog(FName RowName)
{
	FS_Item* ItemData = DT_Item->FindRow<FS_Item>(RowName, TEXT("UpdateSelectLog"));
	if (ItemData)
	{
		FText FormatText = FText::Format(
			NSLOCTEXT("W_Main", "SelectLog", "[{0}을(를) 선택하셨습니다!]"),
			ItemData->Name
		);
		TXT_SelectLog->SetText(FormatText);
		TXT_SelectLog->SetVisibility(ESlateVisibility::Visible);
	}
}

void UW_Main::UpdateButtonEnabled()
{
	TArray<UWidget*> Children = WrapBox->GetAllChildren();

	for (UWidget* Child : Children)
	{
		UW_ItemButton* ItemButton = Cast<UW_ItemButton>(Child);
		if (IsValid(ItemButton))
		{
			if (ItemButton->GetIsClicked())
			{
				ItemButton->SetButtonDisabled();
			}
		}		
	}
}

void UW_Main::OnClickedItem(FName RowName)
{
	UpdateSelectLog(RowName);
	UpdateButtonEnabled();
}