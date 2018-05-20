// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrell.h"
#include "Projectile.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));


}

void ATank::SetBarrellReference(UTankBarrell * BarrellToSet)
{
	TankAimingComponent->SetBarrellReference(BarrellToSet);
	Barrell = BarrellToSet;
}

void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	if (!Barrell) { return; }

	UE_LOG(LogTemp, Warning, TEXT("Tank Fired!"));

	GetWorld()->SpawnActor<AProjectile>(ProjectileBluePrint, Barrell->GetSocketLocation(FName("Projectile")), Barrell->GetSocketRotation(FName("Projectile")));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
	//UE_LOG(LogTemp, Warning, TEXT("%s Aiming at: %s"),*GetName(), *HitLocation.ToString());

}

