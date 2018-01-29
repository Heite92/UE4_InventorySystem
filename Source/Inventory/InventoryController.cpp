#include "InventoryController.h"
#include "InventoryGameState.h"
#include "InventoryCharacter.h"

AInventoryController::AInventoryController() 
{
	InventorySlotLimit = 50;
	InventoryWeightLimit = 500;
}

int32 AInventoryController::GetInventoryWeight()
{
	int32 Weight = 0;
	for (auto& Item : Inventory)
	{
		Weight += Item.Weight;
	}

	return Weight;
}

bool AInventoryController::AddItemToInventoryByID(FName ID)
{
	AInventoryGameState* GameState = Cast<AInventoryGameState>(GetWorld()->GetGameState());
	UDataTable* ItemTable = GameState->GetItemDB();
	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	if (ItemToAdd)
	{
		// If you dont want a Slot- or WeightLimit you have to remove it in this line
		if (Inventory.Num() < InventorySlotLimit && GetInventoryWeight() + ItemToAdd->Weight <= InventoryWeightLimit)
		{
			Inventory.Add(*ItemToAdd);
			ReloadInventory();
			return true;
		}
	}
	return false;
}

void AInventoryController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Interact", IE_Pressed, this, &AInventoryController::Interact);
}

void AInventoryController::Interact()
{
	if (CurrentInteractable)
	{
		CurrentInteractable->Interact(this);
	}
}


