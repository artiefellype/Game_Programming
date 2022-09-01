/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
// 
// Cria��o:     22 Dez 2012
// Atualiza��o: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Bola do jogo Breakout
//
**********************************************************************************/

#ifndef _BREAKOUT_BALL_H_
#define _BREAKOUT_BALL_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"            // tipos espec�ficos da engine
#include "Object.h"            // interface de Object
#include "Sprite.h"            // interface de Sprites
#include "Player.h"            // jogador do Breakout

// ---------------------------------------------------------------------------------

class Ball : public Object
{
    private:
        Sprite* ballSprite;             // plano de fundo
        float velX, velY;               // Velocidades
        boolean onGround;			    // Verifica se a bola esta no objeto player

    public:

        Ball();
        ~Ball();

        void Update();              // atualiza��o
        void Draw();                // desenha

};

// ---------------------------------------------------------------------------------

#endif