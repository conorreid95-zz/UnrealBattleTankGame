// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {

	

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendToMove(float ThrowF) {

	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(ThrowF);
	RightTrack->SetThrottle(ThrowF);
}

void UTankMovementComponent::IntendToMoveBack(float ThrowB) {

	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(-ThrowB);
	RightTrack->SetThrottle(-ThrowB);
}


void UTankMovementComponent::IntendTurnRight(float TurnR) {

	if (!LeftTrack || !RightTrack) { return; }
	UE_LOG(LogTemp, Warning, TEXT("Turn right called"));
	LeftTrack->SetThrottle(TurnR);
	RightTrack->SetThrottle(-TurnR);
}

void UTankMovementComponent::IntendTurnLeft(float TurnL) {

	if (!LeftTrack || !RightTrack) { return; }
	UE_LOG(LogTemp, Warning, TEXT("Turn right called"));
	LeftTrack->SetThrottle(-TurnL);
	RightTrack->SetThrottle(TurnL);
}