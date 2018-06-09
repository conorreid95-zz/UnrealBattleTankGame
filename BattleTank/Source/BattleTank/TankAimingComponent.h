// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "TankAimingComponent.generated.h"


UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked

};

//forward declaration
class UTankBarrell; 
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrell * BarrellToSet, UTankTurret * TurretToSet);

	// Sets default values for this component's properties
	UTankAimingComponent();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UTankBarrell * Barrell = nullptr;

	UTankTurret * Turret = nullptr;

	UPROPERTY(EditAnywhere, Category = "Firing")
		float LaunchSpeed = 12000;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation);

	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();

	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState firingState = EFiringState::Locked;


	UPROPERTY(EditAnywhere, Category = "Firing")
		TSubclassOf<AProjectile> ProjectileBluePrint;

	UPROPERTY(EditAnywhere, Category = "Firing")
		double ReloadTime = 3.0;

	double LastFireTime = 0;


private:
	
	void MoveBarrellTowards(FVector AimDirection);


	
	
};