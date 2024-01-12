// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MaterialVaultStyle.h"

class FMaterialVaultCommands : public TCommands<FMaterialVaultCommands>
{
public:

	FMaterialVaultCommands()
		: TCommands<FMaterialVaultCommands>(TEXT("MaterialVault"), NSLOCTEXT("Contexts", "MaterialVault", "MaterialVault Plugin"), NAME_None, FMaterialVaultStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
