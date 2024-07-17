#include "W_Histoy_Beginning.h"
#include "Components/Image.h"
#include "Components/RichTextBlock.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Texture2D.h"
#include "HUD_P_Principal.h"

void UW_Histoy_Beginning::NativeConstruct()
{
    Super::NativeConstruct();

    // Inicializar el índice de la historia
    CurrentIndex = 0;

    // Asignar las imágenes de la historia
    HistoryImages = { Image1, Image2, Image3, Image4, Image5, Image6 };

    // Cargar los textos de la historia
    HistoryTexts.Add(FText::FromString("La historia comienza con nuestra nave, la Estrella de Andromeda, patrullando la galaxia en busca de aventuras."));
    HistoryTexts.Add(FText::FromString("De repente, una alerta se activa en un planeta cercano, indicando una posible amenaza."));
    HistoryTexts.Add(FText::FromString("Al llegar, inesperadamente, es atacada por los ArcoBox, una civilizacion extraterrestre hostil."));
    HistoryTexts.Add(FText::FromString("Intenta defenderse, pero la cantidad de naves enemigas es abrumadora. No tiene otra alternativa que aterrizar en el planeta de donde provino la alerta."));
    HistoryTexts.Add(FText::FromString("En el planeta, descubre que los ArcoBox intentan obtener la TERRA - BLEY, una gema que otorga poderes inimaginables y que puede aniquilar planetas enteros."));
    HistoryTexts.Add(FText::FromString("Al tratar de detenerlos, los disparos de los ArcoBox impactan la TERRA-BLEY, fragmentandola en trece gemas que se dispersan por toda la galaxia. Nuestro objetivo es recuperarlas."));

    // Vincular las funciones de los botones
    if (Next_History_Button)
    {
        Next_History_Button->OnClicked.AddDynamic(this, &UW_Histoy_Beginning::OnContinuarHistoriaClicked);
    }

    if (Saltar_Button)
    {
        Saltar_Button->OnClicked.AddDynamic(this, &UW_Histoy_Beginning::OnSaltarHistoriaClicked);
    }

    // Actualizar la historia al primer índice
    UpdateHistory();
}

void UW_Histoy_Beginning::OnContinuarHistoriaClicked()
{
    if (CurrentIndex < HistoryImages.Num() - 1)
    {
        CurrentIndex++;
        UpdateHistory();
        AHUD_P_Principal* HUD = Cast<AHUD_P_Principal>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
        if (HUD)
        {
            HUD->OnContinueHistoryClicked();
        }
    }
    else
    {
        ComenzarJuego();
        AHUD_P_Principal* HUD = Cast<AHUD_P_Principal>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
        if (HUD)
        {
            HUD->OnSkipHistoryClicked();
        }
    }
}

void UW_Histoy_Beginning::OnSaltarHistoriaClicked()
{
    AHUD_P_Principal* HUD = Cast<AHUD_P_Principal>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
    if (HUD)
    {
        HUD->OnSkipHistoryClicked();
    }
    ComenzarJuego();
}

void UW_Histoy_Beginning::UpdateHistory()
{
    if (HistoryImages.IsValidIndex(CurrentIndex) && Image_Current_His)
    {
        FSlateBrush Brush;
        Brush.DrawAs = ESlateBrushDrawType::Image;
        Brush.SetResourceObject(HistoryImages[CurrentIndex]);
        Image_Current_His->SetBrush(Brush);
    }
    if (HistoryTexts.IsValidIndex(CurrentIndex) && Multi_Linea_History)
    {
        Multi_Linea_History->SetText(HistoryTexts[CurrentIndex]);
    }
    if (HistorySounds.IsValidIndex(CurrentIndex) && AudioComponent)
    {
        AudioComponent->SetSound(HistorySounds[CurrentIndex]);
        AudioComponent->Play();
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to update history"));
    }
}

void UW_Histoy_Beginning::ComenzarJuego()
{
    // Detener el audio al comenzar el juego
    if (AudioComponent)
    {
        AudioComponent->Stop();
    }
    AHUD_P_Principal* HUD = Cast<AHUD_P_Principal>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
    if (HUD)
    {
        HUD->ShowLoadingScreen(); // Mostrar la pantalla de carga final
        GetWorld()->GetTimerManager().SetTimerForNextTick([HUD]()
            {
                HUD->StartGameplay(); // Comenzar el juego después de la pantalla de carga final
            });
    }
}
