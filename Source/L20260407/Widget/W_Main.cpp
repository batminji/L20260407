// Fill out your copyright notice in the Description page of Project Settings.


#include "W_Main.h"
#include "Components/WrapBox.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Algo/RandomShuffle.h"
#include "W_ItemButton.h"

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

void UW_Main::OnClickedItem(FName RowName)
{

}