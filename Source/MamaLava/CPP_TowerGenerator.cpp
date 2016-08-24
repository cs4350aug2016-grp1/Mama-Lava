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
void ACPP_TowerGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_TowerGenerator::GenerateLayer() {
	ACPP_Brick* Wall = WallTypes[0];
	int WallWidth = Wall->GetDimension().Z;
	NumWalls = PI / atan(WallWidth / 2.0 / Radius);
	Angle = 180.0 - (NumWalls - 2)*180.0 / NumWalls;
	FVector wallPosition(0, -Radius, TowerHeight);
	CenterToWallVector = FVector(0, -Radius, TowerHeight) - GetActorLocation();
	GenerateWalls();
	GeneratePlatforms();
}

void ACPP_TowerGenerator::GenerateWalls() {
	ACPP_Brick* Wall = WallTypes[0];
	FRotator rotator(0, 0, 0);
	FRotationMatrix rotationMatrix(rotator);
	FVector translation = rotationMatrix.TransformPosition(CenterToWallVector);

	for (int i = 0; i <= NumWalls; i++) {
		ACPP_Brick* curr_wall = dynamic_cast<ACPP_Brick*>(
			GetWorld()->SpawnActor(Wall->GetClass(), &translation, &rotator));

		rotator.Add(0, Angle, 0);
		rotationMatrix = FRotationMatrix(rotator);
		translation = rotationMatrix.TransformPosition(CenterToWallVector);
	}
	TowerHeight += Wall->GetDimension().Z;
}

void ACPP_TowerGenerator::GeneratePlatforms() {
	int NumOfNewPlatforms = 0;
	int NumOfExistingPlatforms = PreviousLayer.Num();
	if (PreviousLayer.Num() == 0) {
		PreviousLayer.Add(ACPP_Platform::Generate(this, 0,360));
		NumOfNewPlatforms++;
	}
	else {
		int StartAngle = PreviousLayer[0]->GetEndingAngle();
		for (int i = 0; i < NumOfExistingPlatforms; i++) {
			PreviousLayer.Add(ACPP_Platform::Generate(this, 
				PreviousLayer[i]->GetEndingAngle(),
				StartAngle+360));
			NumOfNewPlatforms++;
		}
	}
	PreviousLayer.RemoveAt(0, NumOfExistingPlatforms);
}