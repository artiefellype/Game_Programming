/**********************************************************************************
// Platformer (Código Fonte)
//
// Criação:     05 Out 2011
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Exemplo de jogo estilo platforma
//
**********************************************************************************/

#include "Engine.h"
#include "Platformer.h"
#include "Resources.h"

// -----------------------------------------------------------------------------

Scene * Platformer::scene = nullptr;

// -----------------------------------------------------------------------------

void Platformer::Init()
{
    // cria cena do jogo
    scene = new Scene();

    // pano de fundo do jogo
    backg = new Background();
    scene->Add(backg, STATIC);

    player = new Player();
    scene->Add(player, MOVING);


    Platform* plat0 = new Platform(300, 150, SMALL);
    scene->Add(plat0, STATIC);

    Platform* plat1 = new Platform(1000, 20, LARGE);
    scene->Add(plat1, STATIC);

    Platform* plat2 = new Platform(1700, 150, SMALL);
    scene->Add(plat2, STATIC);

    Platform* plat3 = new Platform(2400, 20, SMALL);
    scene->Add(plat3, STATIC);

    Platform* plat4 = new Platform(3100, 150, LARGE);
    scene->Add(plat4, STATIC);

    Platform* plat5 = new Platform(3800, 20, LARGE);
    scene->Add(plat5, STATIC);

}

// ------------------------------------------------------------------------------

void Platformer::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza cena do jogo
    scene->Update();
    scene->CollisionDetection();
} 

// ------------------------------------------------------------------------------

void Platformer::Draw()
{
    scene->Draw();
} 

// ------------------------------------------------------------------------------

void Platformer::Finalize()
{
    delete scene;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                    _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura o motor do jogo
    engine->window->Mode(WINDOWED);
    engine->window->Size(600, 300);
    engine->window->Color(150, 200, 230);
    engine->window->Title("Platformer");
    engine->window->Icon(IDI_ICON);
    //engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);
    
    // inicia o jogo
    int status = engine->Start(new Platformer());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

