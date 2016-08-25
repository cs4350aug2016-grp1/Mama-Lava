// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFramework/Actor.h"
#include "CPP_Brick.generated.h"

using namespace std;

UCLASS()
class MAMALAVA_API ACPP_Brick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Brick();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	FVector GetDimension();

protected:
	UPROPERTY(BlueprintReadWrite)
	FVector Dimension;
};
