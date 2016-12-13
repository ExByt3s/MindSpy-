﻿/**
*	@file main.cpp
*	@author Carlos D. Alvarez
*	@date 10/12/2016
*	@brief Contiene la función de arranque del servidor
*/
#include "CPanel.h"
using namespace MindSpy;

/**
* @fn main
* Punto de entrada del programa
*/
//int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
int main()
{
	CPanel cp;
	cp.Run();
	return 0;
}