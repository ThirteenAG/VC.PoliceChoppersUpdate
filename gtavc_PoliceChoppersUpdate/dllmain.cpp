#include "stdafx.h"
#include "include\IniReader.h"
#include "include\injector\injector.hpp"
#include "include\injector\assembly.hpp"
#include <vector>


struct RwV3D
{
	float x, y, z;
};
struct CHeliVC
{
	char pad[0x34];
	RwV3D pos;
	char pad2[0x284];
	RwV3D shadowPos;
	char pad3[0xC];
	float unk;
	char pad4[0x7C];
};

int g_1StarHeliAmount, g_2StarHeliAmount, g_3StarHeliAmount, g_4StarHeliAmount, g_5StarHeliAmount, g_6StarHeliAmount, g_HeliHealth;
unsigned int g_HeliLimit;
unsigned int g_Time1, g_Time2;

std::vector<CHeliVC *> PoliceHelisPtrs;

void IncreasePoliceHelisArray()
{
	injector::AdjustPointer(0x5AC506, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     ecx, ds:dword_813D10[ebx*4]; int
	injector::AdjustPointer(0x5AC5B3, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     edx, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AC64D, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AC669, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AC67D, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AC690, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AC6E3, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AC732, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AC8CB, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     edx, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AC8D8, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AC92F, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AC94C, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AC960, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AC9B3, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     edx, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5ACA2F, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5ACA4B, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5ACA5F, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5ACD66, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     ebx, ds:dword_813D10[ebx*4]
	injector::AdjustPointer(0x5ACE1D, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> cmp     ds:dword_813D10, 0
	injector::AdjustPointer(0x5ACE26, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     ds:dword_813D10, eax
	injector::AdjustPointer(0x5ACE95, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     edi, ds:dword_813D10[esi*4]
	injector::AdjustPointer(0x5ACEC3, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     ecx, ds:dword_813D10[esi*4]
	injector::AdjustPointer(0x5ACED8, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     ds:dword_813D10[esi*4], 0
	injector::AdjustPointer(0x5ACEF9, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     ecx, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AD033, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AD19A, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     ecx, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AD1A8, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     ecx, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AD1B6, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     ecx, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AD1C4, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AD1D1, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AD1E0, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     ecx, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AD1F5, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     ds:dword_813D10[ebp*4], 0
	injector::AdjustPointer(0x5AD324, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     ecx, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AD332, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     eax, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AD350, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     edi, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AD361, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     edx, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AD380, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     esi, ds:dword_813D10[ebp*4]
	injector::AdjustPointer(0x5AD423, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     ebx, ds:dword_813D10[eax*4]
	injector::AdjustPointer(0x5AD477, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     ecx, ds:dword_813D10[eax*4]
	injector::AdjustPointer(0x5AD4BC, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D10 + 0x0  -> mov     ds:dword_813D10, 0
	injector::AdjustPointer(0x5ACE32, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D14 + 0x0->cmp     ds : dword_813D14, 0
	injector::AdjustPointer(0x5ACE3A, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D14 + 0x0->mov     ds : dword_813D14, eax
	injector::AdjustPointer(0x5AD4CD, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D14 + 0x0->mov     ds : dword_813D14, 0
	injector::AdjustPointer(0x5ACE52, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D18 + 0x0->cmp     ds : dword_813D18, 0
	injector::AdjustPointer(0x5ACE61, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D18 + 0x0->mov     ds : dword_813D18, eax
	injector::AdjustPointer(0x5ACE81, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D18 + 0x0->mov     eax, ds : dword_813D18
	injector::AdjustPointer(0x5AD4D7, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D18 + 0x0->mov     ds : dword_813D18, 0
	injector::AdjustPointer(0x5AD4E1, &PoliceHelisPtrs.front(), 0x813D10, 0x813D1C);  //0x813D1C + 0x0->mov     ds : dword_813D1C, 0

	//CHeli::UpdateHelis(void)
	injector::WriteMemory<char>(0x5ACEEF + 0x2, (char)g_HeliLimit, true);
	injector::WriteMemory<char>(0x5AD413 + 0x2, (char)g_HeliLimit, true);
	injector::WriteMemory<char>(0x5AD490 + 0x2, (char)g_HeliLimit, true);
	injector::WriteMemory<char>(0x5AD448 + 0x2, (char)g_HeliLimit, true);

	//CHeli::TestSniperCollision(CVector *,CVector *)
	injector::WriteMemory<char>(0x5AC69E + 0x2, (char)g_HeliLimit, true);

	//CHeli::TestRocketCollision(CVector *)
	injector::WriteMemory<char>(0x5ACA72 + 0x2, (char)g_HeliLimit, true);

	//CHeli::TestBulletCollision(CVector *,CVector *,CVector *,int)
	injector::WriteMemory<char>(0x5AC975 + 0x2, (char)g_HeliLimit, true);

	//CHeli::SpecialHeliPreRender(void)
	injector::WriteMemory<char>(0x5AC514 + 0x2, (char)g_HeliLimit, true);

	//CHeli::ProcessControl(void)
	//injector::WriteMemory<char>(0x5AF04A + 0x2, (char)g_HeliLimit, true);

	//GenerateHeli(bool)
	injector::WriteMemory<char>(0x5ACD7C + 0x3, (char)g_HeliLimit, true);


	injector::MakeNOP(0x5ACEE0, 2, true);
	injector::MakeNOP(0x5ACEE5, 2, true);

	injector::MakeNOP(0x5AD1FD, 2, true);
	injector::MakeNOP(0x5AD202, 2, true);
}

signed int __fastcall CWanted__NumOfHelisRequired(int CPlayerPed_wanted)
{
	signed int result;

	if ((*(BYTE *)(CPlayerPed_wanted + 30) >> 1) & 1 || *(BYTE *)(CPlayerPed_wanted + 30) & 1)
	{
		result = 0;
	}
	else
	{
		switch (*(DWORD *)(CPlayerPed_wanted + 32))
		{
		case 1:
			result = g_1StarHeliAmount;
			break;
		case 2:
			result = g_2StarHeliAmount;
			break;
		case 3:
			result = g_3StarHeliAmount;
			break;
		case 4:
			result = g_4StarHeliAmount;
			break;
		case 5:
			result = g_5StarHeliAmount;
			break;
		case 6:
			result = g_6StarHeliAmount;
			break;
		default:
			result = 0;
			break;
		}
	}
	return result;
}


auto asm_CHeli__UpdateHelisFix = [](injector::reg_pack& regs)
{
	for (DWORD it = (DWORD)&PoliceHelisPtrs.front(); it < (DWORD)&PoliceHelisPtrs.front() + (g_HeliLimit*4); it += 4)
		{
			if (*(DWORD*)it == 0)
			{
				injector::WriteMemory(it, regs.eax);
				break;
			}
		}
	
};

DWORD WINAPI Thread(LPVOID)
{
	CIniReader iniReader("");
		g_HeliLimit = iniReader.ReadInteger("MAIN", "HeliLimit", 100);
		g_1StarHeliAmount = iniReader.ReadInteger("MAIN", "1StarHeliAmount", 0);
		g_2StarHeliAmount = iniReader.ReadInteger("MAIN", "2StarHeliAmount", 1);
		g_3StarHeliAmount = iniReader.ReadInteger("MAIN", "3StarHeliAmount", 2);
		g_4StarHeliAmount = iniReader.ReadInteger("MAIN", "4StarHeliAmount", 3);
		g_5StarHeliAmount = iniReader.ReadInteger("MAIN", "5StarHeliAmount", 4);
		g_6StarHeliAmount = iniReader.ReadInteger("MAIN", "6StarHeliAmount", 5);
		g_HeliHealth = iniReader.ReadInteger("MAIN", "HeliHealth", 100);

		g_Time1 = iniReader.ReadInteger("MAIN", "Time1", 15000);
		g_Time2 = iniReader.ReadInteger("MAIN", "Time2", 50000);

		PoliceHelisPtrs.resize(g_HeliLimit);
		IncreasePoliceHelisArray();

		injector::MakeCALL(0x409083, CWanted__NumOfHelisRequired);
		injector::MakeCALL(0x5ACDB5, CWanted__NumOfHelisRequired);

		injector::MakeInline<0x5ACE23, 0x5ACE3E>(asm_CHeli__UpdateHelisFix);

		injector::WriteMemory(0x5AC8FC + 0x6, g_HeliHealth, true);
		injector::WriteMemory(0x5AC8E7 + 0x6, (unsigned int)(g_HeliHealth / 1.75f), true);

		injector::WriteMemory(0x5ACDEE + 0x2, g_Time1, true);
		injector::WriteMemory(0x5AD26E + 0x1, g_Time2, true);

	return 0;
}

BOOL APIENTRY DllMain(HMODULE /*hModule*/, DWORD reason, LPVOID /*lpReserved*/)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)&Thread, NULL, 0, NULL);
	}
	return TRUE;
}


