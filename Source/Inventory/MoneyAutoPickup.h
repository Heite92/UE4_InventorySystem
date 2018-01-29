#pragma once

#include "CoreMinimal.h"
#include "AutoPickup.h"
#include "MoneyAutoPickup.generated.h"

UCLASS()
class INVENTORY_API AMoneyAutoPickup : public AAutoPickup
{
	GENERATED_BODY()
	
public:
	AMoneyAutoPickup();
	
	void Collect_Implementation(APlayerController* Controller) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Value;
};