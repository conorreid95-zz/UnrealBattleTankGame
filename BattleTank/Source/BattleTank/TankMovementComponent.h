
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

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendToMove(float ThrowF);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendToMoveBack(float ThrowB);
	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurnRight(float TurnR);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurnLeft(float TurnL);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankTrack * LeftTrackToSet, UTankTrack * UTankTrackToSet);
	
	virtual void RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed) override;
	
private:

	UTankTrack * LeftTrack = nullptr;
	UTankTrack * RightTrack = nullptr;
	
};
