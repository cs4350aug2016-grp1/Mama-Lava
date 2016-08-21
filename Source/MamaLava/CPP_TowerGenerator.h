// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CPP_Brick.h"
#include "CPP_Platform.h"
#include "GameFramework/Actor.h"
#include "CPP_TowerGenerator.generated.h"

UCLASS()
class MAMALAVA_API ACPP_TowerGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_TowerGenerator();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category="PGC")
	void GenerateLayer();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		int Radius;

	UPROPERTY(EditAnyWhere)
		TArray<ACPP_Brick*> WallTypes;
	UPROPERTY(EditAnyWhere)
		TArray<ACPP_Platform*> PlatformTypes;
	UPROPERTY(BlueprintReadWrite)
		int TowerHeight = 0;

	UPROPERTY(EditAnyWhere,BlueprintReadWrite)
		int MinimumHeightAhead;

	
};
