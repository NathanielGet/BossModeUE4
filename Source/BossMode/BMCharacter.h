// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BMProjectile.h"
#include "BMCharacter.generated.h"

UCLASS()
class BOSSMODE_API ABMCharacter : public ACharacter
{
	GENERATED_BODY()

	// Pawn Mesh, will only be seen by self
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* FPMesh;

	// Gun Mesh, will only be seen by self
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* FPGunMesh;

	// First person camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FPCameraComponent;

public:
	// Sets default values for this character's properties
	ABMCharacter();

	// Base Turn Rate in deg/sec
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	// Base Lookup/Down rate in deg/sec
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	// Projectile class to use
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Projectile)
	TSubclassOf<ABMProjectile> ProjectileClass;

	// Projectile spawn
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Projectile)
	class USceneComponent* ProjSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Handles forwards and backwards movement
	void MoveForward(float Val);

	// Handles left and right strafing movement
	void MoveRight(float Val);

	/*
	* Will Be called via input axis mapping
	* @param Rate this is the normalized rate, 1.0 means full turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate this is the normalized rate, 1.0 means full turn rate
	*/
	void LookUpAtRate(float Rate);

	// Fires a projectile
	void OnFire();

	class USceneComponent* TrackingSceneComponent;

	void OnTrack();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
