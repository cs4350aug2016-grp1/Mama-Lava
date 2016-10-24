// Fill out your copyright notice in the Description page of Project Settings.

#include "MamaLava.h"
#include "BPFI_IO.h"

bool UBPFI_IO::FileSaveString(FString SaveTextB, FString FileNameB)
{
	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameDir() + FileNameB));
}

bool UBPFI_IO::FileLoadString(FString FileNameA, FString& SaveTextA)
{
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA));
}


