// Fill out your copyright notice in the Description page of Project Settings.

#include "MamaLava.h"
#include "CPP_Platform_Unit.h"


// Sets default values
ACPP_Platform_Unit::ACPP_Platform_Unit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_Platform_Unit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Platform_Unit::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

