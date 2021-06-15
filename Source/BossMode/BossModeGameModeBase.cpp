// Copyright Epic Games, Inc. All Rights Reserved.


#include "BossModeGameModeBase.h"
#include "BMHUD.h"

ABossModeGameModeBase::ABossModeGameModeBase() : Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/FP2Character"));

	DefaultPawnClass = PlayerPawnClassFinder.Class;
	HUDClass = ABMHUD::StaticClass();
}