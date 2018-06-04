// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {

	

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	float ForwardProduct = FVector::DotProduct(TankForwardDirection, AIForwardIntention);

	auto RotationProduct = FVector::CrossProduct(AIForwardIntention, TankForwardDirection);

	IntendTurnRight(RotationProduct.Z);
	//UE_LOG(LogTemp, Warning, TEXT("ForwardProduct of %f"), ForwardProduct);
	IntendToMove(ForwardProduct);
	//UE_LOG(LogTemp, Warning, TEXT("RequestDirectMove called with move velocity of %s"), *AIForwardIntention);
}

void UTankMovementComponent::IntendToMove(float ThrowF) {

	if (!ensure(LeftTrack || !RightTrack)) { return; }
	LeftTrack->SetThrottle(ThrowF);
	RightTrack->SetThrottle(ThrowF);
}

void UTankMovementComponent::IntendToMoveBack(float ThrowB) {

	if (!ensure(LeftTrack || !RightTrack)) { return; }
	LeftTrack->SetThrottle(-ThrowB);
	RightTrack->SetThrottle(-ThrowB);
}


void UTankMovementComponent::IntendTurnRight(float TurnR) {

	if (!ensure(LeftTrack || !RightTrack)) { return; }
	//UE_LOG(LogTemp, Warning, TEXT("Turn right called"));
	LeftTrack->SetThrottle(TurnR);
	RightTrack->SetThrottle(-TurnR);
}

void UTankMovementComponent::IntendTurnLeft(float TurnL) {

	if (!ensure(LeftTrack || !RightTrack)) { return; }
	//UE_LOG(LogTemp, Warning, TEXT("Turn left called"));
	LeftTrack->SetThrottle(-TurnL);
	RightTrack->SetThrottle(TurnL);
}