// Copyright Epic Games, Inc. All Rights Reserved.

#include "FactionWarsGameMode.h"
#include "FactionWarsPlayerController.h"
#include "FactionWarsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFactionWarsGameMode::AFactionWarsGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AFactionWarsPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/PlayerOverseer"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}