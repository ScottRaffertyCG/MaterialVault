// Copyright Epic Games, Inc. All Rights Reserved.

#include "MaterialVault.h"
#include "MaterialVaultStyle.h"
#include "MaterialVaultCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "CoreMinimal.h"
#include "Editor/Blutility/Public/EditorUtilitySubsystem.h"

static const FName MaterialVaultTabName("MaterialVault");

#define LOCTEXT_NAMESPACE "FMaterialVaultModule"

void FMaterialVaultModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FMaterialVaultStyle::Initialize();
	FMaterialVaultStyle::ReloadTextures();

	FMaterialVaultCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FMaterialVaultCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FMaterialVaultModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMaterialVaultModule::RegisterMenus));
}

void FMaterialVaultModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FMaterialVaultStyle::Shutdown();

	FMaterialVaultCommands::Unregister();
}

void FMaterialVaultModule::PluginButtonClicked()
{
	//Open window
	UObject* WidgetObj = LoadObject<UObject>(nullptr, TEXT("/MaterialVault/MaterialVault/MaterialVault_EUW.MaterialVault_EUW"));
	UEditorUtilityWidgetBlueprint* WidgetBP = (UEditorUtilityWidgetBlueprint*)WidgetObj;
	UEditorUtilitySubsystem* EditorUtilitySubsystem = GEditor->GetEditorSubsystem<UEditorUtilitySubsystem>();
	EditorUtilitySubsystem->SpawnAndRegisterTab(WidgetBP);

}

void FMaterialVaultModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FMaterialVaultCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FMaterialVaultCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMaterialVaultModule, MaterialVault)