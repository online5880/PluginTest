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

	void AddMenuExtension(const FMenuExtensionDelegate& ExtensionDelegate, FName ExtensionHook,
		const TSharedPtr<FUICommandList>& CommandList = nullptr, EExtensionHook::Position Position = EExtensionHook::Before);

	TSharedRef<FWorkspaceItem> GetMenuRoot() { return MenuRoot; }

protected:
	TSharedPtr<FExtensibilityManager> LevelEditorMenuExtensibilityManager;
	TSharedPtr<FExtender> MenuExtender;

	static TSharedRef<FWorkspaceItem> MenuRoot;

	void MakePulldownMenu(FMenuBarBuilder& MenuBarBuilder);
	void FillPulldownMenu(FMenuBuilder& MenuBuilder);
	
private:

	void RegisterMenus();

	AActor* FindActor(TSubclassOf<AActor> ActorClass);
	AActor* AddActor(TSubclassOf<AActor> ActorClass);

	static inline FNightButtonModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FNightButtonModule>("NightButtonModule");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("NightButtonModule");
	}


private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
