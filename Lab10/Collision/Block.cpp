/**********************************************************************************
// Block (Arquivo de Cabeçalho)
// 
// Criação:     22 Dez 2012
// Atualização: 20 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Bloco do jogo Breakout
//
**********************************************************************************/

#include "Block.h"
#include "Breakout.h"
#include "Ball.h"

// ---------------------------------------------------------------------------------

Block::Block(Image * img)
{
    // tamanho do bloco é 60x24
    BBox(new Rect(0, 0, 59, 23));

    // sprite do bloco
    sprite  = new Sprite(img);

    // velocidades iniciais
    velX = 0.0f;
    velY = 0.0f;

    // tipo do objeto
    type = BLOCK;
}
// ---------------------------------------------------------------------------------

void Block::OnCollision(Object* obj) {
    if (obj->Type() == BALL)
    {
        
        Ball* ball = (Ball*)obj;
        Circle* ci = (Circle*)ball->BBox();

        Rect* ret = (Rect*)BBox();

        if ((ci->CenterX() > ret->Left() && ci->CenterX() < ret->Right()) && (ci->CenterY() >= ret->Bottom() || ci->CenterY() <= ret->Top())) {
            ball->velY = -ball->velY;
        }
        else if ((ci->CenterY() > ret->Top() && ci->CenterY() < ret->Bottom()) && (ci->CenterX() >= ret->Right() || ci->CenterX() <= ret->Left())) {
            ball->velX = -ball->velX;
        }
        else {
            ball->velY = -ball->velY;
            ball->velX = -ball->velX;
        }
    }
}

// ---------------------------------------------------------------------------------

Block::~Block()
{
    delete sprite;
}

// ---------------------------------------------------------------------------------

void Block::Update()
{
    // desloca o bloco
    Translate(velX * gameTime, velY * gameTime);

    // destrói ao sair da janela
    if (y > window->Height())
        Breakout::scene->Delete();
}

// ---------------------------------------------------------------------------------
