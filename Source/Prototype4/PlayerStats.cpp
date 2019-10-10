// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStats.h"

// Sets default values
APlayerStats::APlayerStats()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerStats::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerStats::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerStats::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//Plays the animation of the dodge but check the value of the current axis to find out which dodge animation to play 
UAnimMontage * APlayerStats::DodgeFunction(bool b_IsLockOn, float f_Forward, float f_Right, float& f_Launch, float& f_LaunchSide, UAnimMontage* m_DodgeFrontAnim, UAnimMontage* m_DodgeBackAnim, UAnimMontage* m_DodgeRightAnim, UAnimMontage* m_DodgeLeftAnim) {
	if (b_IsAlive) {
		//check if the player is using lock on mode
		if (b_IsLockOn) {

			if (f_Right > 0.0f && !b_IsDodge) {
				b_IsDodge = true;
				b_CanMove = false;
				b_CanAttack = false;
				f_LaunchSide = 1500.0f;
				return m_DodgeRightAnim;
			}
			if (f_Right < 0.0f && !b_IsDodge) {
				b_IsDodge = true;
				b_CanMove = false;
				b_CanAttack = false;
				f_LaunchSide = -1500.0f;
				return m_DodgeLeftAnim;
			}

			if (f_Forward > 0 && !b_IsDodge) {
				b_IsDodge = true;
				b_CanMove = false;
				b_CanAttack = false;
				f_Launch = 1500.0f;
				return m_DodgeFrontAnim;
			}
			if (f_Forward < 0 && !b_IsDodge) {
				b_IsDodge = true;
				b_CanMove = false;
				b_CanAttack = false;
				f_Launch = -1500.0f;
				return m_DodgeBackAnim;
			}
		}
		//how dodge works when player is not using lock on mode
		if (f_Forward != 0 || f_Right != 0 && !b_IsDodge) {
			b_IsDodge = true;
			b_CanMove = false;
			b_CanAttack = false;
			f_Launch = 1500.0f;
			return m_DodgeFrontAnim;
		}
	}
	//if player is not using the axis the default mode will be dodge back
	b_IsDodge = true;
	b_CanMove = false;
	b_CanAttack = false;
	f_Launch = -1500.0f;
	return m_DodgeBackAnim;
}

void APlayerStats::SureTakeDamage(float f_damage) 
{
	if (!b_IsGodMode) {
		if (f_Life > 0) {
			f_Life = f_Life - f_damage;
			if (f_Life <= 0) {
				b_IsAlive = false;
			}
		}
	}
}