#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interactable.h"
#include "InventoryItem.h"
#include "InventoryController.generated.h"

UCLASS()
class INVENTORY_API AInventoryController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AInventoryController();

	UFUNCTION(BlueprintImplementableEvent)
	void ReloadInventory();

	UFUNCTION(BlueprintCallable, Category = "Utils")
	int32 GetInventoryWeight();

	UFUNCTION(BlueprintCallable, Category = "Utils")
	bool AddItemToInventoryByID(FName ID);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class AInteractable* CurrentInteractable;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<FInventoryItem> Inventory;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int32 Money;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 InventorySlotLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 InventoryWeightLimit;

protected:
	void Interact();

	virtual void SetupInputComponent() override;	
};
