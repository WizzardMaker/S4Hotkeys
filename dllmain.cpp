// dllmain.cpp : Definiert den Einstiegspunkt für die DLL-Anwendung.
#include "pch.h"
#include "S4ModApi.h"
#include <string>     // std::string, std::to_string
#pragma comment(lib, "S4ModApi")

static S4API s4; // the interface to the Settlers 4 Mod API

static void CleanUp() {
	if (NULL != s4) {
		s4->Release();
		s4 = NULL;
	}
};

HRESULT S4HCALL S4TickProc(DWORD dwTick, BOOL bHasEvent, BOOL bIsDelayed);

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH: {
		s4 = S4ApiCreate(); // get an interface to the mod api
		if (NULL == s4) break;

		s4->AddTickListener(S4TickProc);

		break;
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		CleanUp();
		break;
	}
	return TRUE;
}
S4_OBJECT_TYPE SetBuilding(int vKey, S4_GUI_ENUM menu) {
	DWORD playerId;
	DWORD baseModuleAdress = (DWORD)GetModuleHandle(NULL);
	ReadProcessMemory(GetCurrentProcess(), (LPCVOID)(baseModuleAdress + 0x05975688+0xC), &playerId, sizeof(DWORD), NULL); //THANKS VICITEN!
	
	LPWSTR psz = NULL;
	TCHAR buf[sizeof(playerId) * 8 + 1];
	wsprintf(buf, TEXT("%d"), playerId);
	psz = buf;
	MessageBoxW(NULL, psz, L"Player race", MB_OK);

	switch (vKey)
	{
	case('U'):
		switch (menu)
		{
		case S4_MENU_BUILDINGS_FOUNDATION:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_WOODCUTTERHUT;
		case S4_MENU_BUILDINGS_METAL:
			break;
		case S4_MENU_BUILDINGS_FOOD:

		case S4_MENU_BUILDINGS_MISC:
			break;
		case S4_MENU_BUILDINGS_MISC_DECOSUB:
			break;
		case S4_MENU_BUILDINGS_MILITARY:
			break;
		}
		break;
	case('I'):
		switch (menu)
		{
		case S4_MENU_BUILDINGS_FOUNDATION:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_STONECUTTERHUT;
		case S4_MENU_BUILDINGS_METAL:
			break;
		case S4_MENU_BUILDINGS_FOOD:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_GRAINFARM;//TODO: MAKE CHECK FOR TRIBE
		case S4_MENU_BUILDINGS_MISC:
			break;
		case S4_MENU_BUILDINGS_MISC_DECOSUB:
			break;
		case S4_MENU_BUILDINGS_MILITARY:
			break;
		}
		break;
	case('J'):
		switch (menu)
		{
		case S4_MENU_BUILDINGS_FOUNDATION:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_SAWMILL;
		case S4_MENU_BUILDINGS_METAL:
			break;
		case S4_MENU_BUILDINGS_FOOD:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_GRAINFARM;
		case S4_MENU_BUILDINGS_MISC:
			break;
		case S4_MENU_BUILDINGS_MISC_DECOSUB:
			break;
		case S4_MENU_BUILDINGS_MILITARY:
			break;
		}
		break;
	case('K'):
		switch (menu)
		{
		case S4_MENU_BUILDINGS_FOUNDATION:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_FORESTERHUT;
		case S4_MENU_BUILDINGS_METAL:
			break;
		case S4_MENU_BUILDINGS_FOOD:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_GRAINFARM;
		case S4_MENU_BUILDINGS_MISC:
			break;
		case S4_MENU_BUILDINGS_MISC_DECOSUB:
			break;
		case S4_MENU_BUILDINGS_MILITARY:
			break;
		}
		break;
	case('N'):
		switch (menu)
		{
		case S4_MENU_BUILDINGS_FOUNDATION:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_RESIDENCESMALL;
		case S4_MENU_BUILDINGS_METAL:
			break;
		case S4_MENU_BUILDINGS_FOOD:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_GRAINFARM;
		case S4_MENU_BUILDINGS_MISC:
			break;
		case S4_MENU_BUILDINGS_MISC_DECOSUB:
			break;
		case S4_MENU_BUILDINGS_MILITARY:
			break;
		}
		break;
	case('M'):
		switch (menu)
		{
		case S4_MENU_BUILDINGS_FOUNDATION:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_RESIDENCEMEDIUM;
		case S4_MENU_BUILDINGS_METAL:
			break;
		case S4_MENU_BUILDINGS_FOOD:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_GRAINFARM;
		case S4_MENU_BUILDINGS_MISC:
			break;
		case S4_MENU_BUILDINGS_MISC_DECOSUB:
			break;
		case S4_MENU_BUILDINGS_MILITARY:
			break;
		}
		break;
	case('V'):
		switch (menu)
		{
		case S4_MENU_BUILDINGS_FOUNDATION:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_RESIDENCEBIG;
		case S4_MENU_BUILDINGS_METAL:
			break;
		case S4_MENU_BUILDINGS_FOOD:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_GRAINFARM;
		case S4_MENU_BUILDINGS_MISC:
			break;
		case S4_MENU_BUILDINGS_MISC_DECOSUB:
			break;
		case S4_MENU_BUILDINGS_MILITARY:
			break;
		}
		break;
	case('B'):
		switch (menu)
		{
		case S4_MENU_BUILDINGS_FOUNDATION:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_STONEMINE;
		case S4_MENU_BUILDINGS_METAL:
			break;
		case S4_MENU_BUILDINGS_FOOD:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_GRAINFARM;
		case S4_MENU_BUILDINGS_MISC:
			break;
		case S4_MENU_BUILDINGS_MISC_DECOSUB:
			break;
		case S4_MENU_BUILDINGS_MILITARY:
			break;
		}
		break;
	case('O'):
		switch (menu)
		{
		case S4_MENU_BUILDINGS_FOUNDATION:
			break; //No building
		case S4_MENU_BUILDINGS_METAL:
			break;
		case S4_MENU_BUILDINGS_FOOD:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_GRAINFARM;
		case S4_MENU_BUILDINGS_MISC:
			break;
		case S4_MENU_BUILDINGS_MISC_DECOSUB:
			break;
		case S4_MENU_BUILDINGS_MILITARY:
			break;
		}
		break;
	case('L'):
		switch (menu)
		{
		case S4_MENU_BUILDINGS_FOUNDATION:
			break; //No building
		case S4_MENU_BUILDINGS_METAL:
			break;
		case S4_MENU_BUILDINGS_FOOD:
			return S4_OBJECT_TYPE::S4_OBJECT_BUILDING_GRAINFARM;
		case S4_MENU_BUILDINGS_MISC:
			break;
		case S4_MENU_BUILDINGS_MISC_DECOSUB:
			break;
		case S4_MENU_BUILDINGS_MILITARY:
			break;
		}
		break;
	}
}

bool StartBuildMode(DWORD currentTick) {
	S4_OBJECT_TYPE building;

	bool picked = false;
	
	S4_GUI_ENUM menu = S4_GUI_ENUM::S4_GUI_UNKNOWN;
	if (s4->IsCurrentlyOnScreen(S4_GUI_ENUM::S4_MENU_BUILDINGS_FOUNDATION)) {
		menu = S4_MENU_BUILDINGS_FOUNDATION;
	} else if (s4->IsCurrentlyOnScreen(S4_GUI_ENUM::S4_MENU_BUILDINGS_METAL)) {
		menu = S4_MENU_BUILDINGS_METAL;
	} else if (s4->IsCurrentlyOnScreen(S4_GUI_ENUM::S4_MENU_BUILDINGS_FOOD)) {
		menu = S4_MENU_BUILDINGS_FOOD;
	} else if (s4->IsCurrentlyOnScreen(S4_GUI_ENUM::S4_MENU_BUILDINGS_MISC)) {
		menu = S4_MENU_BUILDINGS_MISC;
	} else if (s4->IsCurrentlyOnScreen(S4_GUI_ENUM::S4_MENU_BUILDINGS_MILITARY)) {
		menu = S4_MENU_BUILDINGS_MILITARY;
	}

	if(menu == S4_GUI_UNKNOWN)
		return false;

	int keys[] = {'U', 'I','J','K','N','M','V', 'B','O','L'};

	for (int k = 0; k < 10; k++) {
		if (GetAsyncKeyState(keys[k])) {
			building = SetBuilding(keys[k], menu);
			picked = true;
			//s4->StartBuildingPlacement();
		}
	}

	if (picked == true) {
		s4->StartBuildingPlacement(building);
		return true;
	}
	return false;
}


HRESULT S4HCALL S4TickProc(DWORD dwTick, BOOL bHasEvent, BOOL bIsDelayed) {
	if (bIsDelayed) return FALSE; // someone is already requesting to create an event

	//if (GetAsyncKeyState('Q')) { // check if the condition for creating an event is met
			// append \splash.bmp to the filename of the module
	

	return StartBuildMode(dwTick); // e.g. destroying a building or commanding units
	//}


	//return FALSE; // we do not intend to create an event for this tick
}




/*
QWERTZ
ASDF
  XC


*/