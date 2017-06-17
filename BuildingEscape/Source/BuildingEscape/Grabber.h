// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	//how far ahead of the player can we reach in cm
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	FVector GetPlayerViewPointLocation(); //returns player location
	FRotator GetPlayerViewPointRotation(); //returns player rotation
	FVector GetTraceEnd(); //returns trace end
		
	void Grab(); //ray-cast and grab whats in reach
	void Release(); //called when grab key is released
	void FindPhysicsHandleComponent(); //find attached physics handle component
	void SetupInputComponent(); //setup input component
	const FHitResult GetFirstPhysicsBodyInReach(); //return hit for first physics body reach
};