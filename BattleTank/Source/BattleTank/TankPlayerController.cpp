// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATankPlayerController::ATankPlayerController() {

	PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
	if (AimingComponent) {
		FoundAimingComponent(AimingComponent);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Aiming Found In PlayerController"));
	}
	
}


void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
		ATank* tank = Cast<ATank>(GetPawn());
		if (tank) {
			FString name = tank->GetName();
			//UE_LOG(LogTemp, Warning, TEXT("Controlled tank is: %s"), *name);
			return tank;
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("No controlled tank"));
			return nullptr;
		}
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!ensure(GetControlledTank())) {
		UE_LOG(LogTemp, Warning, TEXT("No tank to aim"));
	}
	else {
		FVector HitLocation; //out param
		if (GetSightRayHitLocation(HitLocation)) {
			
			//ATank* tank = GetControlledTank();
			//tank->AimAt(HitLocation);
			GetControlledTank()->AimAt(HitLocation);
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("No actor hit with raycast"));
		}
	}
}



bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	
	int32 reticleXPosition, reticleYPosition;
	reticleXPosition = (int32)ViewportSizeX * reticleXPercentage;
	reticleYPosition = (int32)ViewportSizeY * reticleYPercentage;

	FVector LookDirection;
	if (GetLookDirection(reticleXPosition, reticleYPosition, LookDirection)) {

		GetLookVectorHitLocation(LookDirection, OutHitLocation);
		return true;
	}
	else {
		return false;
	}
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& RayHitLocation) const {

	FHitResult HitResult = FHitResult();
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility)) {

		RayHitLocation = HitResult.Location;
		
		return true;
	}
	else {

		RayHitLocation = FVector(0.0, 0.0, 0.0);
		return false;
	}
	


}

bool ATankPlayerController::GetLookDirection(int32 screenX, int32 screenY, FVector& LookDirection) const{

	FVector WorldLocation = FVector(0.0, 0.0, 0.0);

	if (DeprojectScreenPositionToWorld(screenX, screenY, WorldLocation, LookDirection)) {
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *LookDirection.ToString());
		return true;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Deproject false"));
		return false;
	}
}



