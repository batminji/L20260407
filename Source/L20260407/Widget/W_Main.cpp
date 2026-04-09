// Fill out your copyright notice in the Description page of Project Settings.


#include "W_Main.h"
#include "Components/WrapBox.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UW_Main::NativeConstruct()
{
	RandomCnt = 3;

	if (BTN_Refresh)
	{
		BTN_Refresh->OnClicked.AddDynamic(this, &UW_Main::OnRefreshButtonClicked);
	}
}

void UW_Main::OnRefreshButtonClicked()
{

}