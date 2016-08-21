// Fill out your copyright notice in the Description page of Project Settings.

#include "MamaLava.h"
#include "CPP_Brick.h"

// Sets default values
ACPP_Brick::ACPP_Brick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Brick::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACPP_Brick::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

FVector ACPP_Brick::GetDimension() {
	return Dimension;
}

FTransform ACPP_Brick::GetRightAP() {
	return RightAP;
}
