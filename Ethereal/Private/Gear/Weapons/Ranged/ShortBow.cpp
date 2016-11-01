// © 2014 - 2016 Soverance Studios
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
#include "ShortBow.h"

#define LOCTEXT_NAMESPACE "EtherealText"

// Sets default values
AShortBow::AShortBow(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshObject(TEXT("SkeletalMesh'/Game/VFX/sphere_skeletal.sphere_skeletal'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObject(TEXT("StaticMesh'/Game/Weapons/Ranged/ShortBow.ShortBow'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> OffhandMeshObject(TEXT("StaticMesh'/Game/VFX/sphere.sphere'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/WeaponIcon_ShortBow.WeaponIcon_ShortBow'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/WeaponIcon_ShortBow-small.WeaponIcon_ShortBow-small'"));


	// Set Default Objects

	Name = EMasterGearList::GL_ShortBow;
	NameText = LOCTEXT("ShortBowName", "Short Bow");
	Type = EMasterGearTypes::GT_Ranged;
	TypeText = LOCTEXT("ShortBowType", "Ranged");
	Description = "A simple bow designed for hunting.";
	Price = 5000;
	MPCost = 0.0f;
	ATK = 10.0f;
	DEF = 5.0f;
	SPD = 5.0f;
	HP = 50.0f;
	MP = 10.0f;
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;

	SK_WeaponSkeletalMesh = SkeletalMeshObject.Object;
	SM_WeaponStaticMesh = StaticMeshObject.Object;
	SM_WeaponOffhandMesh = StaticMeshObject.Object;

	// Set Mesh
	WeaponSkeletalMesh->SetSkeletalMesh(SK_WeaponSkeletalMesh);
	WeaponSkeletalMesh->SetHiddenInGame(true);
	WeaponStaticMesh->SetStaticMesh(SM_WeaponStaticMesh);
	WeaponStaticMesh->SetWorldScale3D(FVector(30, 30, 30));  // scale correction
	WeaponStaticMesh->SetRelativeLocation(FVector(20, -2, -2));  // location correction
	WeaponStaticMesh->SetRelativeRotation(FRotator(-80, 180, 0));  // location correction
	WeaponOffhandMesh->SetStaticMesh(SM_WeaponOffhandMesh);
	WeaponOffhandMesh->SetHiddenInGame(true);
}

// Called when the game starts or when spawned
void AShortBow::BeginPlay()
{
	Super::BeginPlay();

	// Bind this function to the event dispatcher for Bind Gear
	OnBindGear.AddDynamic(this, &AShortBow::BindWeapon);
}

// Custom code when binding
void AShortBow::BindWeapon()
{
	WeaponSkeletalMesh->SetVisibility(false);
	WeaponStaticMesh->SetVisibility(true);
	WeaponOffhandMesh->SetVisibility(false);
	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Magenta, "Weapon was bound.");
}

#undef LOCTEXT_NAMESPACE