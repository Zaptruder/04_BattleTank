// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"



ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

// Called when the game starts or when spawned
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AI Tank Begin Play"));

	auto AIControlledTank = GetControlledTank();

	if (GetControlledTank() == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("AI controller not in possession of tank."))
	}
	else {
		UE_LOG(
			LogTemp,
			Warning,
			TEXT("%s has been possessed by AI controller."),
			*AIControlledTank->GetName()
		)
	}
}
