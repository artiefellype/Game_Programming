#include "Window.h"
#include "Engine.h"
#include "Resources.h"
#include "Anima.h"


Anima::Anima() 
{
	mario = new TileSet("Resources/hero.png", 64.8, 65, 6, 6);
	anim = new Animation(mario, 0.110f, true);
}

Anima::~Anima() 
{
	delete anim;
	delete mario;
}

void Anima::Update()
{
	anim->NextFrame();
}

void Anima::Draw()
{
	anim->Draw(window->CenterX(), window->CenterY());

}

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------


// ----------------------------------------------------------------------------

