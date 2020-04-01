// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class art497Target : TargetRules
{
	public art497Target(TargetInfo Target) : base(Target)
	{
        //bUseLoggingInShipping = true;
        Type = TargetType.Game;
        ExtraModuleNames.AddRange(new string[] { "art497" });
		//bUsePCHFiles = false;
		//bUseUnityBuild = false;
    }

	//
	// TargetRules interface.
	//

	/*public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.AddRange( new string[] { "art497" } );
	}*/
}
