#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>

#include "Servidor.h"
#include "../Cliente/Datos.h"
using namespace std;
using namespace MindSpy;
namespace MindSpy
{
	class CPanel {
	private:
		int TipoComando(const char*c);
	public:
		void Run();
	};
}
