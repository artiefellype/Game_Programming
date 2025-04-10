/**********************************************************************************
// Jump (Arquivo de Cabe�alho)
// 
// Cria��o:     10 Jul 2019
// Atualiza��o: 05 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Exerc�cio de uso da classe Controller
//
**********************************************************************************/

#ifndef _JUMP_H_
#define _JUMP_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Controller.h"
#include "Resources.h"
#include <vector>
using std::vector;

// ------------------------------------------------------------------------------

struct Coord
{
    float x;
    float y;
};

// ------------------------------------------------------------------------------

class Jump : public Game
{
private:
    Sprite * dot = nullptr;             // sprite de um ponto
    TileSet * braidSet = nullptr;       // folha de sprites do personagem
    Animation * anim = nullptr;         // anima��o do pulo
    Controller* gamepad = nullptr;
    bool gamepadOn;

    Timer jumpTimer;                    // controla tempo do pulo
    Timer dotTimer;                     // controla exibi��o do rastro

    vector<Coord> trail;                // vetor de coordenadas
    bool jumping = false;               // personagem est� pulando
    float velX = 0;                     // velocidade horizontal
    float velY = 0;                     // velocidade vertical
    float posX = 0;                     // posi��o no eixo X
    float posY = 0;                     // posi��o no eixo Y
    float oldX = 0;                     // antiga posi��o X
    float oldY = 0;                     // antiga posi��o Y

public:
    void Init();                        // inicializa jogo
    void Update();                      // atualiza l�gica do jogo
    void Draw();                        // desenha jogo
    void Finalize();                    // finaliza jogo
};

// ---------------------------------------------------------------------------------

#endif