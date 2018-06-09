// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrell.h"
#include "TankTurret.h"
#include "Projectile.h"





// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::Initialise(UTankBarrell * BarrellToSet, UTankTurret * TurretToSet) {

	Barrell = BarrellToSet;
	Turret = TurretToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UE_LOG(LogTemp, Warning, TEXT("Tick called"));
	// ...
}

void UTankAimingComponent::AimAt(FVector WorldSpaceAim)
{
	if (!ensure(Barrell)) { return; }

	auto BarrellLocation = Barrell->GetComponentLocation();

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrell->GetSocketLocation(FName("Projectile"));


	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, WorldSpaceAim, LaunchSpeed, false, 0.0, 0.0, ESuggestProjVelocityTraceOption::DoNotTrace)) {

		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("%s Aiming at: %s from %s"), *GetOwner()->GetName(), *WorldSpaceAim.ToString(), *BarrellLocation.ToString());
		//UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s"), *GetOwner()->GetName(), *AimDirection.ToString());
		MoveBarrellTowards(AimDirection);
		//firingState = EFiringState::Aiming;
	}
	else {
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: No aim solution found"), Time);
	}
}

void UTankAimingComponent::MoveBarrellTowards(FVector AimDirection)
{
	if (!ensure(Barrell || !Turret)) { return; }

	auto BarrellRotator = Barrell->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrellRotator;

	Barrell->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}

void UTankAimingComponent::Fire()
{

	bool isReloaded = ((FPlatformTime::Seconds() - LastFireTime) > ReloadTime);

	if (ensure(Barrell && isReloaded && ProjectileBluePrint)) {

		LastFireTime = FPlatformTime::Seconds();
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBluePrint, Barrell->GetSocketLocation(FName("Projectile")), Barrell->GetSocketRotation(FName("Projectile")));

		Projectile->LaunchProjectile(LaunchSpeed);
	}
}

