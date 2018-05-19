// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed) {

	//UE_LOG(LogTemp, Warning, TEXT("Rotate called for %f per second"), RelativeSpeed);

	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);

	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	//RawNewElevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(0.0, RawNewRotation, 0.0));
}

