#pragma once

#include "CoreMinimal.h"
#include "VRGripScriptBase.h"
#include "GameFramework/WorldSettings.h"
#include "GS_Melee.generated.h"


USTRUCT()
struct FBPMelee_SurfacePair
{
	GENERATED_BODY()
public:

	EPhysicalSurface PhysicalSurfaceType;
	float SurfaceVelocityScaler;

	FORCEINLINE bool operator==(const EPhysicalSurface &Other) const
	{
		return PhysicalSurfaceType == Other;
	}

};

// Event, Hit, material object normal
// Event, lodged, material, object, normal

// Event thrown when we the melee weapon becomes lodged
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVROnMeleeIsLodged, bool, IsWeaponLodged);


/**
* A Melee grip script *CURRENTLY WIP, DO NOT USE!!!*
*/
UCLASS(NotBlueprintable, ClassGroup = (VRExpansionPlugin))
class VREXPANSIONPLUGIN_API UGS_Melee : public UVRGripScriptBase
{
	GENERATED_BODY()
public:

	UGS_Melee(const FObjectInitializer& ObjectInitializer);

	TArray<FBPMelee_SurfacePair> SurfaceTypesToPenetrate;
	bool bAllowPenetration;
	bool bUseDensityForPenetrationCalcs;
	bool bTraceComplex;
	bool bLodged;

	FVector StrikeVelocity;
	bool bSubstepTrace;
	float MaxSubsteps;

	float BaseDamage;
	float VelocityDamageScaler;
	float MaximumVelocityForDamage;

	TWeakObjectPtr<class UPrimitiveComponent> LodgeParent;

	// Amount of movement force to apply to the in/out action of penetration.
	float PenetrationFrictionCoefficient;

	//DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FComponentHitSignature, UPrimitiveComponent*, HitComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, FVector, NormalImpulse, const FHitResult&, Hit);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams( FActorHitSignature, AActor*, SelfActor, AActor*, OtherActor, FVector, NormalImpulse, const FHitResult&, Hit );
	
	/*UFUNCTION()
	void OnActorHit(AActor * Self, AActor * Other, FVector NormalImpulse, const FHitResult& HitResult)
	{
		//Normal impulse only has value if simulating
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MyActorHit!"));

		static float MinimumPenetrationVelocity = 10.0f;
		static float DensityToVelocityScaler = 0.5f;

		if (bAllowPenetration && StrikeVelocity.SizeSquared() > FMath::Square(MinimumPenetrationVelocity))
		{

			if (!HitResult.IsValidBlockingHit())
				return;//	continue;

			//FVector VelocityOnNormalPlane;
			if (HitResult.PhysMaterial != nullptr)// && SurfaceTypesToPenetrate.Contains(HitResult.PhysMaterial->SurfaceType.GetValue()))
			{
				float ModifiedPenetrationVelocity = MinimumPenetrationVelocity * (DensityToVelocityScaler * HitResult.PhysMaterial->Density);

				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Penetration!"));
				// We can penetrate it
				// Sample density
			}

			//FHitResult.Normal
			//FHitResult.PenetrationDepth
		}
	}*/

	// Call to use an object
	UPROPERTY(BlueprintAssignable, Category = "MeleeEvents")
		FVROnMeleeIsLodged OnMeleeLodgedChanged;

	virtual void OnGrip_Implementation(UGripMotionControllerComponent * GrippingController, const FBPActorGripInformation & GripInformation) override
	{
		// Not storing an id, we should only be doing this once
	//	GetOwner()->OnActorHit.AddDynamic(this, &UGS_Melee::OnActorHit);

	}

	virtual void OnGripRelease_Implementation(UGripMotionControllerComponent * ReleasingController, const FBPActorGripInformation & GripInformation, bool bWasSocketed = false) override
	{
		//GetOwner()->OnActorHit.RemoveDynamic(this, &UGS_Melee::OnActorHit);
	}

	//virtual void BeginPlay_Implementation() override;
	virtual bool GetWorldTransform_Implementation(UGripMotionControllerComponent * GrippingController, float DeltaTime, FTransform & WorldTransform, const FTransform &ParentTransform, FBPActorGripInformation &Grip, AActor * actor, UPrimitiveComponent * root, bool bRootHasInterface, bool bActorHasInterface, bool bIsForTeleport) override;


};
