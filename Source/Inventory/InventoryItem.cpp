#include "InventoryItem.h"

FInventoryItem::FInventoryItem()
{
	this->Name = FText::FromString("No Name");
	this->Weight = 1;
	this->Value = 1;
	this->Description = FText::FromString("No Description");
}