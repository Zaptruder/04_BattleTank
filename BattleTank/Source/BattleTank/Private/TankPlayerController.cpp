// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "../Public/TankPlayerController.h"

// Method to get the pawn that's spawned for the player.
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

// Called when the game starts or when spawned
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//TODO remove logging information
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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	else {
		//Get world location of line trace through crosshair.
		//If it hits the landscape
			//rotate the player tank turret at fixed rate towards world location.
			//rotate the player tank barrel at fixed rate towards world location.
	}
}