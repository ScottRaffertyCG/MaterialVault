// Copyright Epic Games, Inc. All Rights Reserved.

#include "MaterialVaultStyle.h"
#include "MaterialVault.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FMaterialVaultStyle::StyleInstance = nullptr;

void FMaterialVaultStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FMaterialVaultStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FMaterialVaultStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MaterialVaultStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FMaterialVaultStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("MaterialVaultStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("MaterialVault")->GetBaseDir() / TEXT("Resources"));

	Style->Set("MaterialVault.PluginAction", new IMAGE_BRUSH(TEXT("Icon128"), Icon20x20));
	return Style;
}

void FMaterialVaultStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FMaterialVaultStyle::Get()
{
	return *StyleInstance;
}
