// Fill out your copyright notice in the Description page of Project Settings.

#include "MamaLava.h"
#include <math.h>
#include <stdlib.h> 
#include <time.h>  
#include "CPP_Platform.h"
#include "CPP_TowerGenerator.h"


// Sets default values
ACPP_TowerGenerator::ACPP_TowerGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_TowerGenerator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_TowerGenerator::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACPP_TowerGenerator::GenerateLayer() {
	TArray<ACPP_Platform*> NewLayer;

	ACPP_Brick* wall = WallTypes[0];
	int wallWidth = wall->GetDimension().Z;
	int numWalls = PI / atan(wallWidth / 2.0 / Radius);
	double angle = 180.0 - (numWalls - 2)*180.0 / numWalls;
	FVector wallPosition(0, -Radius, TowerHeight);
	FVector centerToWallVector = FVector(0, -Radius, TowerHeight) - GetActorLocation();
	FRotator rotator(0, 0, 0);
	FRotationMatrix rotationMatrix(rotator);
	FVector translation = rotationMatrix.TransformPosition(centerToWallVector);
	
	int numConsecutivePlatforms = 0;
	for (int i = 0; i < numWalls; i++) {
		ACPP_Brick* curr_wall = dynamic_cast<ACPP_Brick*>(
			GetWorld()->SpawnActor(wall->GetClass(),&translation,&rotator));
		if (static_cast<double>(rand()) / RAND_MAX > 0.9 || numConsecutivePlatforms>0) {
			NewLayer.Add(ACPP_Platform::Generate(this, rotator.Euler().Z, centerToWallVector));
			numConsecutivePlatforms++;
			if (numConsecutivePlatforms >= 3) {
				numConsecutivePlatforms = 0;
			}
		}
		rotator.Add(0, angle, 0);
		rotationMatrix = FRotationMatrix(rotator);
		translation = rotationMatrix.TransformPosition(centerToWallVector);
	}
	TowerHeight += wall->GetDimension().Z;
	PreviousLayer = NewLayer;
}
