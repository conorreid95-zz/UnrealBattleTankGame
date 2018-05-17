// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrell.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrell : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	void Elevate(float RelativeSpeed);
	

private:
	UPROPERTY(EditAnywhere)
		float MaxDegreesPerSecond = 20.0;
	UPROPERTY(EditAnywhere)
		float MaxElevation = 30.0;
	UPROPERTY(EditAnywhere)
		float MinElevation = -5.0;
};
