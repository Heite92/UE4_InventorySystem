#include "ManPickup.h"
#include "InventoryController.h"

AManPickup::AManPickup()
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
	RootComponent = Cast<USceneComponent>(PickupMesh);

	ItemID = FName("No ID");

	Super::Name = "Item";
	Super::Action = "pickup";
}

void AManPickup::Interact_Implementation(APlayerController* Controller)
{
	Super::Interact_Implementation(Controller);

	AInventoryController* IController = Cast<AInventoryController>(Controller);
	if(IController->AddItemToInventoryByID(ItemID))
		Destroy();
}