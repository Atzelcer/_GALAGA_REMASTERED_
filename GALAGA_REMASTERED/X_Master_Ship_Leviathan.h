// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "X_Master_Ship_P.h"
#include "AC_MOVEMENT_EPIC.h"
#include "X_Master_Ship_Leviathan.generated.h"

UCLASS()
class GALAGA_REMASTERED_API AX_Master_Ship_Leviathan : public AX_Master_Ship_P
{
	GENERATED_BODY()

public:

	AX_Master_Ship_Leviathan();


	//audio component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	class UAudioComponent* Au_Lev;



	//niagara Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Niagara")
	class UNiagaraComponent* Nia_Lev;


public:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void Recibir_Danio(float Danio) override;

	virtual void Disparo_Nave(float DeltaTime) override;

	virtual void Movimiento_Nave(float DeltaTime) override;


private:

	TArray<void (UAC_MOVEMENT_EPIC::*)(float)> Movimientos;
	
};
