#include "Interactable.h"

AInteractable::AInteractable()
{
	Name = "Interactable";
	Action = "interact";
}

void AInteractable::Interact_Implementation(APlayerController* Controller)
{
	return;
}

FString AInteractable::GetInteractText() const 
{
	return FString::Printf(TEXT("%s: Press F to %s"), *Name, *Action); 
}