#include "Overseer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AOverseer::AOverseer()
{
	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->bDoCollisionTest = false; 
	CameraBoom->Deactivate();

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComp->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false; 
	CameraComp->Deactivate();

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	moveComp = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Pawn Movement"));
	moveComp->Deactivate();
}

void AOverseer::BeginPlay()
{
	Super::BeginPlay();
	
}

void AOverseer::SetupPlayerObjects()
{
	CameraBoom->Activate();
	CameraComp->Activate();
	moveComp->Activate();
	
	CameraBoom->TargetArmLength = 3000.f;
	CameraBoom->SetRelativeRotation(FRotator(-90.f, 0.f, 0.f));
}

void AOverseer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}