// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "GameFramework/PlayerController.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
	i_StunCount = i_MaxStunCount;

	f_MaxLife = 1000;
	f_Life = f_MaxLife;
	f_AttackDamage = 20;



}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//Called to check distance from first player, returns a float value
float AEnemyBase::CheckDistance()
{

	if (GetWorld()) {
		FVector FV_Distance = GetActorLocation() - GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		f_Distance = FV_Distance.Size();
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("GetWorld Returns Null"));
		return 0;
	}
  
  return f_Distance;
}

//Called to check if the object is in stun state, returns a bool
bool AEnemyBase::CheckIfStun() {
	b_IsStun = true;
	if (i_StunCount <= 0) {
		i_StunCount = i_MaxStunCount;
		return true;
	}
	i_StunCount--;
	return false;
}


//Called to check if the object is in attacking state, returns a bool
bool AEnemyBase::CheckIfInAttackingState() {
	if (b_IsAlive) {
		if (!b_IsStun && !b_IsAttacking) {
			return false;
		}
	}

	return true;
}