// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

// Called when the game starts or when spawned
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	auto ControlledTank = GetControlledTank();

	if (GetControlledTank() == nullptr) { 
		UE_LOG(LogTemp, Warning, TEXT("Player controller not in possession of tank."))
	}
	else {
		UE_LOG(
			LogTemp,
			Warning,
			TEXT("%s has been possessed by player controller."),
			*ControlledTank->GetName()
		)
	}
}