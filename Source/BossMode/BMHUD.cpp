// Fill out your copyright notice in the Description page of Project Settings.


#include "BMHUD.h"
#include "Engine/Canvas.h" 

ABMHUD::ABMHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));

	CrosshairTex = CrosshairTexObj.Object;
}

void ABMHUD::DrawHUD()
{
	Super::DrawHUD();

	// find center of canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset crosshair position to center on the canvas
	const FVector2D CrosshairDrawPosition(
		(Center.X - (CrosshairTex->GetSurfaceWidth() * 0.5f)),
		(Center.Y - (CrosshairTex->GetSurfaceHeight() * 0.5f)));

	// draw the crosshair
	FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);

	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}