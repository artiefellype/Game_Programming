/**********************************************************************************
// Debris (C�digo Fonte)
//
// Cria��o:     07 Fev 2013
// Atualiza��o: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Anima��o de explos�o
//
**********************************************************************************/

#include "Debris.h"
#include "Asteroids.h"

// ---------------------------------------------------------------------------------

Debris::Debris(float posX, float posY)
{
    // configura gerador de part�culas
    Generator starmaker;
    starmaker.imgFile = "Resources/Particle.png";   // arquivo de imagem
    starmaker.angle = 360.0f;            // dire��o das estrelas
    starmaker.spread = 360.0f;                  // espalhamento em graus
    starmaker.lifetime = 2.0f;                  // tempo de vida (em segundos)
    starmaker.frequency = 0.000f;               // tempo entre gera��o de novas part�culas
    starmaker.percentToDim = 0.6f;              // desaparece ap�s 60% da vida
    starmaker.minSpeed = 60.0f;                 // velocidade m�nima das part�culas
    starmaker.maxSpeed = 250.0f;                // velocidade m�xima das part�culas
    starmaker.color.r = 0.7f;          // cor aleat�ria para part�cula
    starmaker.color.g = 0.7f;          // cor aleat�ria para part�cula
    starmaker.color.b = 0.7f;          // cor aleat�ria para part�cula
    starmaker.color.a = 1.0f;                   // transpar�ncia da part�cula

    // cria sistema de part�culas
    dParticles = new Particles(starmaker);

    // gera 50 part�culas na posi��o do mouse
    dParticles->Generate(posX,posY, 50);
}

// ---------------------------------------------------------------------------------

Debris::~Debris()
{
    delete dParticles ;
}

// ---------------------------------------------------------------------------------

void Debris::Update()
{
    dParticles->Update(gameTime);

    if (dParticles->Inactive())
        Asteroids::scene->Delete();    
}

// ---------------------------------------------------------------------------------