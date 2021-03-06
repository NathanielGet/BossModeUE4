// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BMHUD.generated.h"

/**
 * 
 */
UCLASS()
class BOSSMODE_API ABMHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	ABMHUD();

	/* Primary draw call for the hud */
	virtual void DrawHUD() override;

private:
	/* Crosshair asset pointer */
	class UTexture2D* CrosshairTex;
};
