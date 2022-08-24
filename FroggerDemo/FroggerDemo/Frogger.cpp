/**********************************************************************************
// Frogger (Código Fonte)
// 
// Criação:     19 Dez 2012
// Atualização: 14 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define o objeto Sapo no jogo Frogger
//
**********************************************************************************/

#include "Frogger.h"

// ---------------------------------------------------------------------------------

Frogger::Frogger()
{

    frogSprite = "Resources/frog.png";

    sprite = new Sprite(frogSprite);

    

    MoveTo(window->CenterX() - sprite->Width()/2.0f, 545.0f, Layer::FRONT);
    ctrlUp = true;
    ctrlDown = true;
    ctrlRight = true;
    ctrlLeft = true;
}

// ---------------------------------------------------------------------------------

Frogger::~Frogger()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Frogger::Update()
{
    // desloca sapo para cima
    if (ctrlUp && window->KeyDown(VK_UP))
    {
        frogSprite = "Resources/frog.png";
        sprite = new Sprite(frogSprite);
        Translate(0.0f, -40.0f);
        ctrlUp = false;
    }
    else if (window->KeyUp(VK_UP))
    {
        ctrlUp = true;
    }

    // desloca sapo para direita
    if (ctrlRight && window->KeyDown(VK_RIGHT))
    {
        frogSprite = "Resources/frogRight.png";
        sprite = new Sprite(frogSprite);
        Translate(40.0f, 0.0f);
        ctrlRight = false;
    }
    else if (window->KeyUp(VK_RIGHT))
    {
        ctrlRight = true;
    }

    // desloca sapo para esquerda
    if (ctrlLeft && window->KeyDown(VK_LEFT))
    {
        frogSprite = "Resources/frogLeft.png";
        sprite = new Sprite(frogSprite);
        Translate(-40.0f, 0.0f);
        ctrlLeft = false;
    }
    else if (window->KeyUp(VK_LEFT))
    {
        ctrlLeft = true;
    }
    
    // desloca sapo para baixo
    if (ctrlDown && window->KeyDown(VK_DOWN))
    {
        frogSprite = "Resources/frogDown.png";
        sprite = new Sprite(frogSprite);
        Translate(0.0f, 40.0f);
        ctrlDown = false;
    }
    else if (window->KeyUp(VK_DOWN))
    {
        ctrlDown = true;
    }
    
    // mantém sapo dentro da tela
    if (y < 65)
        MoveTo(x, 65);

    if (y > 545)
        MoveTo(x, 545);
}

// ---------------------------------------------------------------------------------
