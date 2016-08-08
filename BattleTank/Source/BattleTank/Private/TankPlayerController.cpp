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
	// Avoid aiming towards crosshair if tank isn't player controlled.
	if (!GetControlledTank()) { return; }
	//If it hits the landscape
	
	FVector HitLocation; // Out parameter
	if(GetSightRayHitLocation(HitLocation)) // Has 'side-effect', is going to line trace.
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
		//TODO rotate the player tank turret at fixed rate towards world location.
		//TODO rotate the player tank barrel at fixed rate towards world location.
	}
}

// Get world location of line trace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	FHitResult Hit;

	return true;

	//GetWorld()->LineTraceSingleByChannel(
	//	Hit,
	//	PlayerViewPointLocation,
	//	End,
	//	TraceChannel,
	//	Params,
	//	ResponseParam,
	//);

	// find player position vector - location and rotation
	// multiply by reach (large distance) to get end point.
	// Line trace with start and end point
	// If it hits a location, report lcoation.
}
