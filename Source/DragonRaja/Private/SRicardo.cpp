// Fill out your copyright notice in the Description page of Project Settings.


#include "SRicardo.h"

void ASRicardo::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

ASRicardo::ASRicardo()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void ASRicardo::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

