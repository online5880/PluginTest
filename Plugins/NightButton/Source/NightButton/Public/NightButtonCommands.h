// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "NightButtonStyle.h"

class FNightButtonCommands : public TCommands<FNightButtonCommands>
{
public:

	FNightButtonCommands()
		: TCommands<FNightButtonCommands>(TEXT("NightButton"), NSLOCTEXT("Contexts", "NightButton", "NightButton Plugin"), NAME_None, FNightButtonStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
