/**********************************************************************************
// Ball (Arquivo de Cabeçalho)
// 
// Criação:     22 Dez 2012
// Atualização: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Bola do jogo Breakout
//
**********************************************************************************/

#include "Ball.h"

// ---------------------------------------------------------------------------------
Ball::Ball()
{
	ballSprite = new Sprite("Resources/Ball.png");
	velX = 100.00f;
	velY = 100.00f;
	onGround = false;

	MoveTo(window->CenterX() - ballSprite->Width() / 2.0f, window->Height() - 65);


}

Ball::~Ball()
{
	delete ballSprite;
}

void Ball::Update()
{
	if (window->KeyDown(VK_SPACE))
		onGround = true;

	if (onGround) {
		x += velX * gameTime;
		y += velY * gameTime;

		if (x < 0) {
			velX = -velX;
		}
		if (x + ballSprite->Width() > window->Width()) {
			velX = -velX;
		}
		if (y < 0) {
			velY = -velY;
		}
		if (y + ballSprite->Width() > window->Height()) {
			velY = -velY;
		}
	}
	else {
		if (window->KeyDown(VK_LEFT))
			x -= velX * gameTime;
		if (window->KeyDown(VK_RIGHT))
			x += velX * gameTime;

	}
	

}

void Ball::Draw() {
	ballSprite->Draw(x, y, z);
}


// ---------------------------------------------------------------------------------
