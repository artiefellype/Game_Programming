
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
    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// -----------------------------------------------------------------------------
