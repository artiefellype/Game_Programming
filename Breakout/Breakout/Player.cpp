/**********************************************************************************
// Player (Arquivo de Cabeçalho)
// 
// Criação:     22 Dez 2012
// Atualização: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Player do jogo Breakout
//
**********************************************************************************/

#include "Player.h"

// ---------------------------------------------------------------------------------
Player::Player()
{
	playerSprite = new Sprite("Resources/Player.png");
	vel = 100.0f;

	MoveTo(window->CenterX() - (playerSprite->Width() / 2.0f), window->Height() - 50.0f);
}
void Player::Update()
{
    if (window->KeyDown(VK_LEFT))
        x -= vel * gameTime;
    if (window->KeyDown(VK_RIGHT))
        x += vel * gameTime;


	if (x < 0) MoveTo(0, y);
	if (x + playerSprite->Width() > window->Width()) {
		MoveTo(window->Width() - playerSprite->Width(), y);
	}
}

Player::~Player()
{
	delete playerSprite;
}

void Player::Draw()
{
	playerSprite->Draw(x, y, z);
}


// ---------------------------------------------------------------------------------
