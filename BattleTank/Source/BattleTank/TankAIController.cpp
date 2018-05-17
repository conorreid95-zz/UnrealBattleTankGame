// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankAIController Begin Play"));
	GetControlledTank();
	
	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	ATank* tank = Cast<ATank>(GetPawn());
	if (tank) {
		FString name = tank->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("AI controlling tank: %s"), *name);
		return tank;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No AI controlled tank"));
		return nullptr;
	}


}

ATank * ATankAIController::GetPlayerTank() const
{
	ATank* playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (playerTank) {
		FString playerTankName = playerTank->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("AI Tank discovered player tank: %s"), *playerTankName);
		
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank didn't discover player tank"));
		return nullptr;
	}
	
	return playerTank;
}
