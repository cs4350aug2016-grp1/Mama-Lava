// Fill out your copyright notice in the Description page of Project Settings.

#include "MamaLava.h"
#include <math.h>
#include <stdlib.h> 
#include <time.h>  
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
	//srand(time(NULL));

	ACPP_Brick* wall = WallTypes[0];
	ACPP_Platform* platform = PlatformTypes[0];
	int wallWidth = wall->GetDimension().Z;
	int numWalls = PI / atan(wallWidth / 2.0 / Radius);
	double angle = 180.0 - (numWalls - 2)*180.0 / numWalls;
	FVector* translation = new FVector(0, -Radius, TowerHeight);
	FRotator* rotation = new FRotator(0, angle, 0);
	for (int i = 0; i < numWalls; i++) {
		ACPP_Brick* curr_wall = dynamic_cast<ACPP_Brick*>(
			GetWorld()->SpawnActor(wall->GetClass(),
				const_cast<const FVector*>(translation),
				const_cast<const FRotator*>(rotation)));
		if (static_cast<double>(rand()) / RAND_MAX > 0.8) {
			ACPP_Platform* curr_platform = dynamic_cast<ACPP_Platform*>(
				GetWorld()->SpawnActor(platform->GetClass(),
					const_cast<const FVector*>(translation),
					const_cast<const FRotator*>(rotation)));
		}
		translation = new FVector(curr_wall->GetRightAP().GetTranslation());
		rotation->Add(0, angle, 0);
	}
	TowerHeight += wall->GetDimension().Z;
}

