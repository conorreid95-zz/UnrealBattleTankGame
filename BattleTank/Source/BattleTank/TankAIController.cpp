// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	tank = Cast<ATank>(GetPawn());
	playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (playerTank) {


		MoveToActor(playerTank, 200.0f, true, true, true, 0, true);
		tank->AimAt(playerTank->GetActorLocation());
		tank->Fire();
	}
}
