/**********************************************************************************
// WinGame 
// 
// Criação:     19 Mai 2007
// Atualização: 04 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Um jogo para Windows é uma classe derivada de Game.
//              Crie uma classe derivada e sobrescreva os métodos Init, 
//              Update, Draw e Finalize.
//
**********************************************************************************/

#include "Resources.h"
#include "Engine.h"
#include "Game.h"
#include <sstream>
#include "Window.h"
using std::stringstream;

// ------------------------------------------------------------------------------

class WinGame : public Game
{
private:
	stringstream textSize;
	stringstream textMode;
	stringstream textMouse;
	HDC hdc;
	int xPoint, yPoint, xSecondPoint, ySecondPoint;
	int velX, velY, lineVelX, lineVelY;

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};

// ------------------------------------------------------------------------------

void WinGame::Init() 
{

	hdc = GetDC(window->Id());

	xPoint = 200;
	yPoint = 100;
	velX = 3;
	velY = 3;
	lineVelX = 2;
	lineVelY = 4;

	 
}

// ------------------------------------------------------------------------------

void WinGame::Update()
{

	xPoint += velX;
	yPoint += velY; 

	xSecondPoint += lineVelX;
	ySecondPoint += lineVelY;

	// LINE POINT 01
	if (xPoint > window->Width()) {
		velX = -velX;
	}
	if (xPoint < 0) {
		velX =  -velX;
	}
	if (yPoint > window->Height()) {
		velY = -velY;
	}
	if (yPoint < 0) {
		velY = -velY;
	}

	
	// LINE POINT 02
	if (xSecondPoint > window->Width()) {
		lineVelX = -lineVelX;
	}
	if (xSecondPoint < 0) {
		lineVelX = -lineVelX;
	}
	if (ySecondPoint > window->Height()) {
		lineVelY = -lineVelY;
	}
	if (ySecondPoint < 0) {
		lineVelY = -lineVelY;
	}
	
	

	// CLOSE WINDOW
	if (window->KeyDown(VK_ESCAPE))
		window->Close();

} 

// ------------------------------------------------------------------------------

void WinGame::Draw()
{	
	
	MoveToEx(hdc, xPoint, yPoint, NULL);
	LineTo(hdc, xSecondPoint, ySecondPoint);
	
} 

// ------------------------------------------------------------------------------

void WinGame::Finalize()
{
	ReleaseDC(window->Id(), hdc);
}	


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
	                 _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// cria motor e configura a janela
	Engine * engine = new Engine();
	engine->window->Mode(WINDOWED);
	engine->window->Size(960, 540);
	engine->window->Color(240, 240, 140);
	engine->window->Title("Window Game");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// cria e inicia o jogo
	engine->Start(new WinGame());
}

// ----------------------------------------------------------------------------

