#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

BOOL ammoOn = false;
DWORD ammoAddress = 0x00697A10;
char infAmmoOp[] = "\x90\x90\x90";
char originalAmmoOp[] = "\x89\x50\x04";

void playOn() {
	Beep(523, 200);
	Beep(659, 200);
}

void playOff() {
	Beep(659, 200);
	Beep(523, 200);
}

// Writes char array to the given address in memory
void writeToMemory(DWORD addressToWrite, char* valueToWrite, int numBytes) {
	unsigned long oldProtection;

	VirtualProtect((LPVOID)addressToWrite, numBytes, PAGE_EXECUTE_READWRITE, &oldProtection);
	memcpy((LPVOID)addressToWrite, valueToWrite, numBytes);
	VirtualProtect((LPVOID)addressToWrite, numBytes, oldProtection, NULL);
}


void writeInfAmmo() {
	writeToMemory(ammoAddress, infAmmoOp, 3);
	playOn();
}

void disableInfAmmo() {
	writeToMemory(ammoAddress, originalAmmoOp, 3);
	playOff();
}


void loop() {
	while (1) {
		if (GetAsyncKeyState(VK_F1)) {
			if (!ammoOn) {
				ammoOn = true;
				writeInfAmmo();
			}
			else {
				ammoOn = false;
				disableInfAmmo();
			}
		}
		Sleep(100);
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		MessageBoxA(NULL, "Zombies Mod by chr0m3playa.", "", MB_OK);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&loop, 0, 0, 0);
	}
	return TRUE;
}

