// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrell.h"




void UTankBarrell::Elevate(float RelativeSpeed) {
	UE_LOG(LogTemp, Warning, TEXT("Elevate called for %f per second"), RelativeSpeed);
}
