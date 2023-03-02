#pragma once

#include "CoreMinimal.h"
#include <GameFramework/FloatingPawnMovement.h>
#include "Overseer.generated.h"

UCLASS()
class FACTIONWARS_API AOverseer : public APawn
{
	GENERATED_BODY()

public:
	AOverseer();
	virtual void Tick(float DeltaTime) override;
	
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return CameraComp; }

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	void SetupPlayerObjects();

protected:
	virtual void BeginPlay() override;

	UPROPERTY();
	UFloatingPawnMovement* moveComp;

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComp;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;
};