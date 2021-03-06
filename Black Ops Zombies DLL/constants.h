#pragma once
#include <Windows.h>

// OFFSETS
DWORD AMMO_DEC_ADDR_OFF = 0x297A10;
DWORD HEALTH_DEC_ADDR_OFF = 0x3DADD0;
DWORD NOCLIP_ADDR_OFF = 0x180A74C;
DWORD POINTS_ADDR_OFF = 0x180A6C8;

// OP CODES
char INF_AMMO_OP_CODE[] = "\x90\x90\x90";
char INF_HEALTH_OP_CODE[] = "\x90\x90\x90\x90\x90\x90";

char ORIG_HEALTH_OP_CODE[] = "\x89\x85\x84\x01\x00\x00";
char ORIG_AMMO_OP_CODE[] = "\x89\x50\x04";

// DVAR VALUES
int NOCLIP_ON = 1;
int NOCLIP_OFF = 0;
int POINTS_LOTTO = 1073741824;