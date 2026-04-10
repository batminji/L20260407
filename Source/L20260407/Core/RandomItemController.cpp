// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomItemController.h"
#include "L20260407/Widget/W_Main.h"


void ARandomItemController::BeginPlay()
{
	Super::BeginPlay();

	if (MainWidgetClass && IsLocalPlayerController())
	{
		MainWidget = CreateWidget<UW_Main>(this, MainWidgetClass);

		if (MainWidget)
		{
			MainWidget->AddToViewport();
		}
	}
	
}
