// Copyright Epic Games, Inc. All Rights Reserved.

#include "MaterialVaultCommands.h"

#define LOCTEXT_NAMESPACE "FMaterialVaultModule"

void FMaterialVaultCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "MaterialVault", "Open the Material Vault Library interface", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
