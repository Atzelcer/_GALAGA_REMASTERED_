#include "W_Transition_CP.h"
#include "Components/Image.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundWave.h"
#include "Engine/Texture2D.h"
#include "Kismet/GameplayStatics.h"
#include "HUD_P_Principal.h"

int32 UW_Transition_CP::CurrentImageIndex = 0;

void UW_Transition_CP::NativeConstruct()
{
    Super::NativeConstruct();

    // Agregar las imágenes al array
    TransitionImages = { Image1, Image2, Image3, Image4, Image5, Image6, Image7, Image8, Image9, Image10, Image11, Image12, Image13 , Image14 };

    // Iniciar la transición
    StartTransition();
}

void UW_Transition_CP::ChangeImage()
{
    // Obtener el HUD
    AHUD_P_Principal* HUD = Cast<AHUD_P_Principal>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
    if (HUD && TransitionImages.Num() > 0)
    {
        // Seleccionar una imagen aleatoria del array
        int32 RandomIndex = FMath::RandRange(0, TransitionImages.Num() - 1);
        UTexture2D* SelectedImage = TransitionImages[RandomIndex];

        // Establecer la imagen seleccionada en el Brush
        if (SelectedImage)
        {
            Transition_Image_P->SetBrushFromTexture(SelectedImage);
        }
    }
}

void UW_Transition_CP::SetTransitionImage(UTexture2D* NewImage)
{
    if (Transition_Image_P && NewImage)
    {
        Transition_Image_P->SetBrushFromTexture(NewImage);
    }
}

void UW_Transition_CP::StartTransition()
{
    ChangeImage();
}