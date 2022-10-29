// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FNightButtonModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command. */
	void PluginButtonClicked();
	
private:

	void RegisterMenus();

	AActor* FindActor(TSubclassOf<AActor> ActorClass);
	AActor* AddActor(TSubclassOf<AActor> ActorClass);


private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
