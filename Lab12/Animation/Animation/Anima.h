#pragma once

#include "Object.h"
#include "TileSet.h"
#include "Animation.h"

// ------------------------------------------------------------------------------

class Anima : public Object
{
private:
    TileSet* mario = nullptr;       // pano de fundo
    Animation* anim = nullptr;

public:
   
    Anima();
    ~Anima();

    void Draw();
    void Update();

   
};

// -----------------------------------------------------------------------------
