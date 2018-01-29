#include "AutoPickup.h"
#include "InventoryController.h"

AAutoPickup::AAutoPickup()
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
	RootComponent = Cast<USceneComponent>(PickupMesh);

	ItemID = FName("No ID");
}

void AAutoPickup::Collect_Implementation(APlayerController* Controller)
{
	AInventoryController* IController = Cast<AInventoryController>(Controller);
	if(IController->AddItemToInventoryByID(ItemID))
		Destroy();
}

FName AAutoPickup::GetItemID()
{
	return ItemID;
}