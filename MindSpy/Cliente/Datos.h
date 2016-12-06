#pragma once
#define MAX_BUFFER 4096
namespace MindSpy
{
	// Estructura para los datos del cliente
	enum CLNT_CMDS {	
		CLOSE,			// Cerrar la conexion
		NAME,			// Obtener nombre del servidor
		VERSION,		// Version del cliente
		SYSINFO			// Informaci�n del sistema
	};

	enum SRV_CMDS {
		CLOSE,
		NAME,
		VERSION,
		SYSINFO
	};

	// Estructura para los datos del sistema
	struct stSystemInfoResponse {
		UINT32 Build;					// Compilaci�n del OS
		UINT16 VersionMayor;			// Versi�n mayor del OS
		UINT16 VersionMenor;			// Versi�n menor del OS
		UINT16 Arquitectura;			// Arquitectura del OS
		WCHAR NombreOS[64];				// Nombre del OS basado en la versi�n
		WCHAR MAC[18];					// Direcci�n f�sica de la interface de red conectada al router
		WCHAR NombreUsuario[64];		// Nombre del usuario que usa el cliente
		bool EsWindowsServer;			// Detecci�n para Windows server
	};
}