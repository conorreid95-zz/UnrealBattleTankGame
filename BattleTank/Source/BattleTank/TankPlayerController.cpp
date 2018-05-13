// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"




void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	GetControlledTank();
	
}

ATank* ATankPlayerController::GetControlledTank() const
{
		ATank* tank = Cast<ATank>(GetPawn());
		if (tank) {
			FString name = tank->GetName();
			UE_LOG(LogTemp, Warning, TEXT("Controlled tank is: %s"), *name);
			return tank;
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("No controlled tank"));
			return NULL;
		}
		

}


