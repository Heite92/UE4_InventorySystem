#include "MoneyAutoPickup.h"
#include "InventoryController.h"

AMoneyAutoPickup::AMoneyAutoPickup()
{
	Super::ItemID = FName("money");
	Value = 1;
}

void AMoneyAutoPickup::Collect_Implementation(APlayerController* Controller)
{
	AInventoryController* IController = Cast<AInventoryController>(Controller);
	IController->Money += Value;
	Destroy();
}