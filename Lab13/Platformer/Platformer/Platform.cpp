/**********************************************************************************
// Platform (C�digo Fonte)
// 
// Cria��o:     21 Abr 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plataformas do jogo
//
**********************************************************************************/

#include "Platform.h"

// ---------------------------------------------------------------------------------

Platform::Platform(float posX, float posY, uint platType)
{
    platform = new Sprite("Resources/LongGray.png");
    

    BBox(new Rect(-1.0f * platform->Width() / 2,
        -1.0f * platform->Height() /2,
        +1.0f * platform->Width() / 2,
        +1.0f * platform->Height() /2
    ));

    MoveTo(posX, posY);
    
}

// ---------------------------------------------------------------------------------

Platform::~Platform()
{
    delete platform;
}

// -------------------------------------------------------------------------------

void Platform::Update()
{
    Translate(-100.0f * gameTime, 0);
}

// -------------------------------------------------------------------------------
