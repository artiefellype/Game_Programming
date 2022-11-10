#include "Jogo.h"
#include "Window.h"
#include "Engine.h"
#include "Resources.h"
#include "Anima.h"

void Jogo::Init()
{
    anima = new Anima();
}

// ------------------------------------------------------------------------------

void Jogo::Finalize()
{
    delete anima;
}

// ------------------------------------------------------------------------------

void Jogo::Update()
{
    anima->Update();
}

// ------------------------------------------------------------------------------

void Jogo::Draw()
{
    anima->Draw();
}

// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine* engine = new Engine();

    // configura janela
    engine->window->Mode(WINDOWED);
    engine->window->Size(960, 540);
    engine->window->Color(0, 0, 0);
    engine->window->Title("Animation");
    engine->window->Icon(IDI_ICON);

    // configura dispositivo gráfico
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new Jogo());

    delete engine;
    return status;
}
