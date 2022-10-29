// Copyright Epic Games, Inc. All Rights Reserved.

#include "NightButtonStyle.h"
#include "NightButton.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush(RootToContentDir(RelativePath, TEXT(".png")), __VA_ARGS__)

TSharedPtr<FSlateStyleSet> FNightButtonStyle::StyleInstance = nullptr;

void FNightButtonStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FNightButtonStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FNightButtonStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("NightButtonStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon32x32(32.0f, 32.0f);

TSharedRef< FSlateStyleSet > FNightButtonStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("NightButtonStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("NightButton")->GetBaseDir() / TEXT("Resources"));

	Style->Set("NightButton.PluginAction", new IMAGE_BRUSH(TEXT("ButtonIcon"), Icon20x20));
	return Style;
}

void FNightButtonStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FNightButtonStyle::Get()
{
	return *StyleInstance;
}