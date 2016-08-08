// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "../Public/TankAIController.h"



ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	//protecting pointer
	if (PlayerTank == nullptr) { return nullptr; }
	else { return PlayerTank; }
}

// Called when the game starts or when spawned
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AI Tank Begin Play"));

	auto AIControlledTank = GetControlledTank();

	if (!AIControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI controller not in possession of tank."))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s has been possessed by AI controller."), *AIControlledTank->GetName());
	}

	if (!GetPlayerTank()) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller cannot find Player Tank."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found player tank: %s."), *GetPlayerTank()->GetName());
	}
}
