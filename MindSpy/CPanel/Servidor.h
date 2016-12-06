#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define NO_PUERTO			9900
#define NO_SRV_CMDS			3
#define IP_NO_REGISTRADA	-1

namespace MindSpy 
{
	class Servidor {
	private:
		enum SRV_CMD {
			CLOSE,
			NAME,
			VERSION,
			SYSINFO
		};

		typedef struct stCon{
			int ID;
			char IP[32];
			char Alias[32];
			bool Activa;
			SOCKET c_socket;

			struct stSystemInfo {
				UINT32 Build;
				UINT16 VersionMayor;
				UINT16 VersionMenor;
				UINT16 Arquitectura;
				CHAR NombreOS[64];
				CHAR MAC[18];
				CHAR NombreUsuario[64];
				bool EsWindowsServer;
			} SistemaCliente;
		} CONEXION, *PCONEXION;
		WSADATA wsa;
		SOCKET s;
		vector<CONEXION> Conexiones;
		sockaddr_in server, client;
		int c, resultado;

		void HiloConexion();
		void HiloEscucha();

		static DWORD CALLBACK HiloConexionStatic(LPVOID lParam) {
			Servidor * c = reinterpret_cast<Servidor*> (lParam);
			c->HiloConexion();
			return TRUE;
		}

		static DWORD CALLBACK HiloEscuchaStatic(LPVOID lParam) {
			Servidor * c = reinterpret_cast<Servidor*> (lParam);
			c->HiloEscucha();
			return TRUE;
		}
	protected:
	public:
		Servidor();
		~Servidor();

		bool Listo();
		bool SetAlias(const char* IP, const char* Alias);
		bool EnviarMensaje(const char* IP, const char* Mensaje);
		void IniciarEscucha();
		int IpRegistrada(const char*IP);
	};
}