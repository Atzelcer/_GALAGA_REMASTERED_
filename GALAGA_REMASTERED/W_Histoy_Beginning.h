#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"
#include "W_Histoy_Beginning.generated.h"

UCLASS()
class GALAGA_REMASTERED_API UW_Histoy_Beginning : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    // Imagen que cambia durante la historia
    UPROPERTY(meta = (BindWidget))
    class UImage* Image_Current_His;

    // TextBox multilinea que cambia durante la historia
    UPROPERTY(meta = (BindWidget))
    class URichTextBlock* Multi_Linea_History;

    // Botón para continuar la historia
    UPROPERTY(meta = (BindWidget))
    class UButton* Next_History_Button;

    // Botón para saltar la historia
    UPROPERTY(meta = (BindWidget))
    class UButton* Saltar_Button;

private:
    int32 CurrentIndex;
    TArray<FText> HistoryTexts;
    TArray<USoundBase*> HistorySounds;
    UAudioComponent* AudioComponent;

    // Imágenes de la historia
    UPROPERTY(EditAnywhere, Category = "Images")
    UTexture2D* Image1;

    UPROPERTY(EditAnywhere, Category = "Images")
    UTexture2D* Image2;

    UPROPERTY(EditAnywhere, Category = "Images")
    UTexture2D* Image3;

    UPROPERTY(EditAnywhere, Category = "Images")
    UTexture2D* Image4;

    UPROPERTY(EditAnywhere, Category = "Images")
    UTexture2D* Image5;

    UPROPERTY(EditAnywhere, Category = "Images")
    UTexture2D* Image6;

    TArray<UTexture2D*> HistoryImages;

    UFUNCTION()
    void OnContinuarHistoriaClicked();

    UFUNCTION()
    void OnSaltarHistoriaClicked();

    void UpdateHistory();
    void ComenzarJuego();
};
