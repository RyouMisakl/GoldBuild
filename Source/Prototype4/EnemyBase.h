// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"

UENUM(BlueprintType)
enum class EGameEnum : uint8
{
	VE_Easy		UMETA(DisplayName="Easy"),
	VE_Normal	UMETA(DisplayName="Normal"),
	VE_Hard		UMETA(DisplayName="Hard")
};


UCLASS()
class PROTOTYPE4_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | Life")
		bool b_IsAlive = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | State")
		bool b_IsStun;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | State")
		bool b_IsAttacking;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | Check")
		int i_StunCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | Check")
		int i_MaxStunCount = 2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | Life")
		float f_Life;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | Life")
		float f_MaxLife;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | Damage")
		float f_AttackDamage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		EGameEnum GameEnum;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat | Distance")
		float f_Distance;

	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void TakeDamage(float f_Damage, bool b_ArmorBreakSkill, bool b_KnockBackSkill, bool b_ChargeSkill);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void GotParryed();

	UFUNCTION(BlueprintCallable)
		float CheckDistance();

	UFUNCTION(BlueprintCallable)
		bool CheckIfStun();

	UFUNCTION(BlueprintCallable)
		bool CheckIfInAttackingState();
};
