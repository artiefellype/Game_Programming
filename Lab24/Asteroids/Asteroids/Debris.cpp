/**********************************************************************************
// Debris (Código Fonte)
//
// Criação:     07 Fev 2013
// Atualização: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Animação de explosão
//
**********************************************************************************/

#include "Debris.h"
#include "Asteroids.h"

// ---------------------------------------------------------------------------------

Debris::Debris(float posX, float posY)
{
    // configura gerador de partículas
    Generator starmaker;
    starmaker.imgFile = "Resources/Particle.png";   // arquivo de imagem
    starmaker.angle = 360.0f;            // direção das estrelas
    starmaker.spread = 360.0f;                  // espalhamento em graus
    starmaker.lifetime = 2.0f;                  // tempo de vida (em segundos)
    starmaker.frequency = 0.000f;               // tempo entre geração de novas partículas
    starmaker.percentToDim = 0.6f;              // desaparece após 60% da vida
    starmaker.minSpeed = 60.0f;                 // velocidade mínima das partículas
    starmaker.maxSpeed = 250.0f;                // velocidade máxima das partículas
    starmaker.color.r = 0.7f;          // cor aleatória para partícula
    starmaker.color.g = 0.7f;          // cor aleatória para partícula
    starmaker.color.b = 0.7f;          // cor aleatória para partícula
    starmaker.color.a = 1.0f;                   // transparência da partícula

    // cria sistema de partículas
    dParticles = new Particles(starmaker);

    // gera 50 partículas na posição do mouse
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