#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "W_Transition_CP.generated.h"

UCLASS()
class GALAGA_REMASTERED_API UW_Transition_CP : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    class UImage* Transition_Image_P;

    void SetTransitionImage(UTexture2D* NewImage);

protected:

    TArray<UTexture2D*> TransitionImages;
    static int32 CurrentImageIndex; 

    void ChangeImage();

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

    UPROPERTY(EditAnywhere, Category = "Images")
    UTexture2D* Image7;

    UPROPERTY(EditAnywhere, Category = "Images")
    UTexture2D* Image8;

    UPROPERTY(EditAnywhere, Category = "Images")
    UTexture2D* Image9;

    UPROPERTY(EditAnywhere, Category = "Images")
    UTexture2D* Image10;

    UPROPERTY(EditAnywhere, Category = "Images")
    UTexture2D* Image11;

    UPROPERTY(EditAnywhere, Category = "Images")
    UTexture2D* Image12;

    UPROPERTY(EditAnywhere, Category = "Images")
    UTexture2D* Image13;

    UPROPERTY(EditAnywhere, Category = "Images")
    UTexture2D* Image14;

public:
    void StartTransition();
};