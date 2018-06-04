// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"
#include "Tank.generated.h"

class UTankBarrell;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent * TankAimingComponent = nullptr;

private:	

	ATank();

	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 12000;
	
	UPROPERTY(EditAnywhere, Category = "Firing")
	TSubclassOf<AProjectile> ProjectileBluePrint;

	UTankBarrell * Barrell = nullptr;

	UPROPERTY(EditAnywhere, Category = "Firing")
	double ReloadTime = 3.0;

	double LastFireTime = 0;
};
