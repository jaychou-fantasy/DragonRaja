// Fill out your copyright notice in the Description page of Project Settings.


#include "SRicardo.h"

#include "SActionComponent.h"
#include "SAttributeComponent.h"
#include "SInteractionComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"


ASRicardo::ASRicardo()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
	
	InteractionComp = CreateDefaultSubobject<USInteractionComponent>("InteractionComp");
	
	AttributeComp = CreateDefaultSubobject<USAttributeComponent>("AttributeComp");
	
	ActionComp = CreateDefaultSubobject<USActionComponent>("ActionComp");
	
	//rpg
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;

}

//to add "AddDynamic"
void ASRicardo::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ASRicardo::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	//"Axis" is a continuous input that need to be checked constantly
	PlayerInputComponent->BindAxis("MoveForward",this,&ASRicardo::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&ASRicardo::MoveRight);
	PlayerInputComponent->BindAxis("Turn",this,&APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp",this,&APawn::AddControllerPitchInput);
	
	
	//Action is A discrete input, only triggered when pressed or released
	PlayerInputComponent->BindAction("Jump",IE_Pressed,this,&ASRicardo::Jump);

}

void ASRicardo::MoveForward(float Value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;
	AddMovementInput(ControlRot.Vector(),Value);
}

void ASRicardo::MoveRight(float Value)
{
	FRotator ControlRot  = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;
	//X = Forward(red)
	//Y = Right(green)
	//Z = Up(blue)
	//Matrix used for transform a "rotation" to a "coordinate system" 
	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);
	
	AddMovementInput(RightVector,Value);
}
