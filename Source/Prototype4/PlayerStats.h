// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerStats.generated.h"



UCLASS()
class PROTOTYPE4_API APlayerStats : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerStats();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | Life")
		bool b_IsAlive = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | State")
		bool b_IsStamina;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | State")
		bool b_IsAttacking;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | State")
		bool b_IsParry;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | State")
		bool b_IsChainAttack;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | State")
		bool b_IsDodge = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | State")
		bool b_IFrame;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | State")
		bool b_CanAttack;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | State")
		bool b_CanMove;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | State")
		bool b_IsUsingSkill;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | Life")
		float f_Life = 100;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | Life")
		float f_Stamina = 100;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | Cheat")
		bool b_IsGodMode;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		UAnimMontage * DodgeFunction(bool b_IsLockOn, float f_Forward, float f_Right, float& f_Launch, float& f_LaunchSide, UAnimMontage* m_DodgeFrontAnim, UAnimMontage* m_DodgeBackAnim, UAnimMontage* m_DodgeRightAnim, UAnimMontage* m_DodgeLeftAnim);
	
	UFUNCTION(BlueprintCallable)
		void SureTakeDamage(float f_damage);
};


USTRUCT(BlueprintType)
struct FSkillTypeStruct
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill Type")
		UTexture2D* SkillImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill Type")
		int SkillType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill Type")
		float AttackDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill Type")
		float MoveDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill Type")
		UAnimMontage* Skillanimation;
};