// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomItemGameMode.h"
#include "L20260407/Widget/W_Main.h"

void ARandomItemGameMode::BeginPlay()
{
	Super::BeginPlay();

    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        MainWidget = CreateWidget<UW_Main>(PlayerController, MainWidgetClass);
        if (MainWidget)
        {
            MainWidget->AddToViewport();
        }
    }
}
