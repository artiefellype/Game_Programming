/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     20 Abr 2012
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Player.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    tileset = new TileSet("Resources/GravityGuy.png", 32, 48, 5, 10);
    anim = new Animation(tileset, 0.120f, true);

   

    BBox(new Rect(-16, -24, 16, 24));

    uint seqNormal[4] = { 1, 2, 3, 4 };
    uint seqInvert[4] = { 6, 7, 8, 9 };

    anim->Add(INVERTED, seqInvert, 4);
    anim->Add(NORMAL, seqNormal, 4);

    BBox(new Rect ( - 1.0f * tileset->TileWidth() / 2,
        -1.0f * tileset->TileHeight() /2,
        +1.0f * tileset->TileWidth() /2,
        +1.0f * tileset->TileHeight() /2
        ));

    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete tileset;
    delete anim;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    if (gravity == NORMAL) {
        MoveTo(window->CenterX(), obj->Y() - 32);
    }
    else {
        MoveTo(window->CenterX(), obj->Y() + 32);
    }

    if (keyCtrl && window->KeyDown(VK_SPACE))
    {
        keyCtrl = false;
        gravity = ~gravity;
        // tira player da plataforma para evitar 
        // detecção de colisão no quadro seguinte
        if (gravity == NORMAL) {
            Translate(0, 12);
            anim->Select(NORMAL);

        }
        else {
            Translate(0, -12);
            anim->Select(INVERTED);
        }

    }
    else if (window->KeyUp(VK_SPACE))
    {
        keyCtrl = true;
    }
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    anim->NextFrame();
    if (gravity == NORMAL) Translate(0, 300 * gameTime);
    else Translate(0, -300 * gameTime);

    if (gravity == NORMAL) Translate(0, 100 * gameTime);
    else Translate(0, -100 * gameTime);

   
}

// ---------------------------------------------------------------------------------