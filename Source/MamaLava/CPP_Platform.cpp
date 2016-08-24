// Fill out your copyright notice in the Description page of Project Settings.

#include "MamaLava.h"
#include "CPP_Platform.h"


// Sets default values
ACPP_Platform::ACPP_Platform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Platform::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACPP_Platform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Generate a number of continuous platform
ACPP_Platform* ACPP_Platform::Generate(ACPP_TowerGenerator* Tower, int StartAngle, int EndAngle) {
	ACPP_Platform* Platform = dynamic_cast<ACPP_Platform*> (Tower->GetWorld()->SpawnActor(ACPP_Platform::StaticClass()));

	ACPP_Platform_Unit* PlatformType = Tower->PlatformTypes[0];
	FRotator Rotator(0, StartAngle, 0);
	FRotationMatrix RotationMatrix = FRotationMatrix(Rotator);
	FVector Translation = RotationMatrix.TransformPosition(Tower->CenterToWallVector);
	Platform->StartingPoint = Translation;
	Platform->StartingAngle = Tower->Angle;

	for (int i = 0; i < 3 && Rotator.Euler().Z < EndAngle; i++) {
		Tower->GetWorld()->SpawnActor(PlatformType->GetClass(), &Translation, &Rotator);
		Rotator.Add(0, Tower->Angle, 0);
		RotationMatrix = FRotationMatrix(Rotator);
		Translation = RotationMatrix.TransformPosition(Tower->CenterToWallVector);
	}

	Platform->EndingPoint = Translation;
	Platform->EndingAngle = Rotator.Euler().Z - Tower->Angle;

	return Platform;
}