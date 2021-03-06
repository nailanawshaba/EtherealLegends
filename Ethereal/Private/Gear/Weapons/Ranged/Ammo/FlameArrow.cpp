// © 2014 - 2017 Soverance Studios
// http://www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "Ethereal.h"
#include "FlameArrow.h"

#define LOCTEXT_NAMESPACE "EtherealText"

// Sets default values
AFlameArrow::AFlameArrow(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshObject(TEXT("SkeletalMesh'/Game/VFX/sphere_skeletal.sphere_skeletal'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObject(TEXT("StaticMesh'/Game/Weapons/Ranged/Ammo/FlameArrow.FlameArrow'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> OffhandMeshObject(TEXT("StaticMesh'/Game/VFX/sphere.sphere'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/WeaponIcon_FlameArrows.WeaponIcon_FlameArrows'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/WeaponIcon_FlameArrows_small.WeaponIcon_FlameArrows_small'"));

	Name = EMasterGearList::GL_FlameArrow;
	NameText = LOCTEXT("FlameArrowName", "Flame Arrow");
	Type = EMasterGearTypes::GT_Ammo;
	TypeText = LOCTEXT("FlameArrowType", "Ammunition");
	Description = "Arrows tipped with flaming wax.";
	Price = 25000;
	MPCost = 0.0f;
	ATK = 15.0f;
	DEF = 5.0f;
	SPD = 5.0f;
	HP = 0.0f;
	MP = 0.0f;
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;

	SK_WeaponSkeletalMesh = SkeletalMeshObject.Object;
	SM_WeaponStaticMesh = StaticMeshObject.Object;
	SM_WeaponOffhandMesh = StaticMeshObject.Object;

	// Set Mesh
	WeaponSkeletalMesh->SetSkeletalMesh(SK_WeaponSkeletalMesh);
	WeaponSkeletalMesh->SetHiddenInGame(true);
	WeaponStaticMesh->SetStaticMesh(SM_WeaponStaticMesh);
	//WeaponStaticMesh->SetWorldScale3D(FVector(30, 30, 30));  // scale correction
	//WeaponStaticMesh->SetRelativeLocation(FVector(20, -2, -2));  // location correction
	//WeaponStaticMesh->SetRelativeRotation(FRotator(-80, 180, 0));  // location correction
	WeaponOffhandMesh->SetStaticMesh(SM_WeaponOffhandMesh);
	WeaponOffhandMesh->SetHiddenInGame(true);
}

// Called when the game starts or when spawned
void AFlameArrow::BeginPlay()
{
	Super::BeginPlay();
}

#undef LOCTEXT_NAMESPACE
