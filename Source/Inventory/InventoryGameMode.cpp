#include "InventoryGameMode.h"
#include "InventoryCharacter.h"
#include "UObject/ConstructorHelpers.h"

AInventoryGameMode::AInventoryGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
