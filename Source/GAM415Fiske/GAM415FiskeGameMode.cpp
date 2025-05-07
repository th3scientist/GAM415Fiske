// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAM415FiskeGameMode.h"
#include "GAM415FiskeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGAM415FiskeGameMode::AGAM415FiskeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
