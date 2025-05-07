// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GAM415Fiske : ModuleRules
{
	public GAM415Fiske(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
