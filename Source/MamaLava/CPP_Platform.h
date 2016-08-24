// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CPP_Platform_Unit.h"
#include "CPP_TowerGenerator.h"
#include "CPP_Platform.generated.h"

using namespace std;

UCLASS()
class MAMALAVA_API ACPP_Platform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Platform();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Generate a number of continuous platform
	static ACPP_Platform* Generate(ACPP_TowerGenerator* Tower, int Angle, FVector CenterToWallVector);

private:
	FVector StartingPoint;
	FVector EndingPoint;
};
