
#include "Game.h"
#include "TileSet.h"
#include "Animation.h"
#include "Anima.h"

// ------------------------------------------------------------------------------

class Jogo : public Game
{
private:
    Anima* anima = nullptr;

public:
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// -----------------------------------------------------------------------------
