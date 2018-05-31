// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "Engine.h"
#include "TankMovementComponent.generated.h"


class UTankTrack;

/**
 * 
 */

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
	
public:

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendToMove(float ThrowF);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendToMoveBack(float ThrowB);
	
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnRight(float TurnR);

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnLeft(float TurnL);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankTrack * LeftTrackToSet, UTankTrack * UTankTrackToSet);
	
	
private:

	UTankTrack * LeftTrack = nullptr;
	UTankTrack * RightTrack = nullptr;
	
};
