#include "stdafx.h"
#include "CPatch.h"
#include "IniReader.h"
#include <vector>

int g_1StarHeliAmount, g_2StarHeliAmount, g_3StarHeliAmount, g_4StarHeliAmount, g_5StarHeliAmount, g_6StarHeliAmount, g_HeliHealth;
unsigned int g_HeliLimit, g_HeliLimitx4;
unsigned int g_Time1, g_Time2;

std::vector<int> PoliceHelis;

#define	 	GenerateHeli	 	0x5ACB30
#define	 	CHeli__UpdateHelis	 	0x5ACDA0
#define	 	CHeli__TestSniperCollision	 	0x5AC520
#define	 	CHeli__TestRocketCollision	 	0x5AC9A0
#define	 	CHeli__TestBulletCollision	 	0x5AC6C0
#define	 	CHeli__InitHelis	 	0x5AD4A0

DWORD jmpAddr;
void __declspec(naked)asm_GenerateHeli()
{
	_asm
	{
		inc     ebp
		cmp     ebp, g_HeliLimit
		mov jmpAddr, 0x5ACD80
		jmp jmpAddr
	}
}

void __declspec(naked)asm_CHeli__UpdateHelis()
{
	_asm
	{
		inc esi
		cmp esi, g_HeliLimit
		jl loc_5ACE92
		mov jmpAddr, 0x5ACEF4
		jmp jmpAddr
	loc_5ACE92:
		mov jmpAddr, 0x5ACE92
		jmp jmpAddr
	}
}

void __declspec(naked)asm_CHeli__UpdateHelis2()
{
	_asm
	{
		inc ebp
		cmp ebp, g_HeliLimit
		jl loc_5ACEF6
		mov jmpAddr, 0x5AD41C
		jmp jmpAddr
	loc_5ACEF6:
		mov jmpAddr, 0x5ACEF6
		jmp jmpAddr
	}
}

void __declspec(naked)asm_CHeli__UpdateHelis3()
{
	_asm
	{
		inc eax
		cmp eax, g_HeliLimit
		jl loc_5AD474
		mov jmpAddr, 0x5AD495
		jmp jmpAddr
	loc_5AD474:
		mov jmpAddr, 0x5AD474
		jmp jmpAddr
	}
}

void __declspec(naked)asm_CHeli__TestSniperCollision()
{
	_asm
	{
		inc ebp
		cmp ebp, g_HeliLimit
		jl      loc_5AC5B0
		mov jmpAddr, 0x5AC6A7
		jmp jmpAddr
loc_5AC5B0:
		mov jmpAddr, 0x5AC5B0
		jmp jmpAddr
	}
}

void __declspec(naked)asm_CHeli__TestRocketCollision()
{
	_asm
	{
		inc     ebp
		cmp     ebp, g_HeliLimit
		jl      loc_5AC9B0
		mov jmpAddr, 0x5ACA7B
		jmp jmpAddr
loc_5AC9B0:
		mov jmpAddr, 0x5AC9B0
		jmp jmpAddr
	}
}

void __declspec(naked)asm_CHeli__TestBulletCollision()
{
	_asm
	{
		inc ebp
		cmp ebp, g_HeliLimit
		jl      loc_5AC6E0
		mov jmpAddr, 0x5AC97E
		jmp jmpAddr
loc_5AC6E0:
		mov jmpAddr, 0x5AC6E0
		jmp jmpAddr
	}
}


DWORD HeliCount;
DWORD temp_eax;
void test()
{
	for (unsigned int it = HeliCount; it < (HeliCount + g_HeliLimitx4); it++)
	{
		
		if (*(DWORD *)it == 0)
		{
			CPatch::SetUInt(it, temp_eax);
			break;
		}
		it + 3;
	}
}


void __declspec(naked)asm_CHeli__UpdateHelisFix()
{
	_asm
	{
		pop     ecx

			mov temp_eax, eax

			mov eax, dword ptr ds : [0xA10A6A]
			dec eax
			imul eax, 4
			mov HeliCount, eax
			/*add*/mov HeliCount, offset PoliceHelis
	}
	//CPatch::SetUInt(HeliCount, temp_eax);
	__asm call test
_asm
{
			mov jmpAddr, 0x5ACE3E
			jmp jmpAddr
		
	}
}

void __declspec(naked)asm_CHeli__UpdateHelis4()
{
	_asm
	{
		add     esp, 40
		cmp     esi, g_HeliLimit
		mov jmpAddr, 0x5AD17A
		jmp jmpAddr
	}
}


void __declspec(naked)asm_CHeli__UpdateHelis5()
{
	_asm
	{
		inc     eax
		cmp     eax, g_HeliLimit
		jl loc_5AD420
		mov jmpAddr, 0x5AD44D
		jmp jmpAddr
	loc_5AD420:
		mov jmpAddr, 0x5AD420
		jmp jmpAddr
	}
}

void __declspec(naked)CHeli_InitHelis()
{
	_asm
	{
			mov ds : [0x9785D4], 00000000
			mov word ptr ds : [0xA10A6A], 0000
			mov byte ptr ds : [0xA10B40], 00
			mov ds : [PoliceHelis], 00000000
			mov byte ptr ds : [0xA10ADB], 00
			mov ds : [PoliceHelis + 0x4], 00000000
			mov ds : [PoliceHelis + 0x8], 00000000
			mov ds : [PoliceHelis + 0xC], 00000000
			mov ds : [PoliceHelis + 0xC + 0x4], 00000000
			ret
	}
}


void IncreasePoliceHelisArray()
{
	PoliceHelis.resize(g_HeliLimit);

	CPatch::AdjustPointer(GenerateHeli + 0x233, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(0x5AD474, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(0x5AD420, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(0x5ACEF6, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(0x5ACE92, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x85, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x7B, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x5DD, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x5BE, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x5AD, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x58F, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x581, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x452, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x43D, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x42E, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x421, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x413, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x405, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x3F7, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x290, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x135, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x120, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(0x5AC5B0, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__TestSniperCollision + 0x16D, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__TestSniperCollision + 0x15A, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__TestSniperCollision + 0x146, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__TestSniperCollision + 0x12A, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(0x5AC9B0, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__TestRocketCollision + 0xBC, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__TestRocketCollision + 0xA8, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__TestRocketCollision + 0x8C, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(0x5AC6E0, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__TestBulletCollision + 0x6F, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__TestBulletCollision + 0x29D, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__TestBulletCollision + 0x289, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__TestBulletCollision + 0x26C, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__TestBulletCollision + 0x215, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__TestBulletCollision + 0x208, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(0x5AC503, &PoliceHelis, 0x813D10, 0x813D10);
	CPatch::AdjustPointer(CHeli__InitHelis + 0x1A, &PoliceHelis, 0x813D10, 0x813D10);

	CPatch::AdjustPointer(0x5ACE30, &PoliceHelis, 0x813D10, 0x813D14);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0x99, &PoliceHelis, 0x813D10, 0x813D14);
	CPatch::AdjustPointer(CHeli__InitHelis + 0x2B, &PoliceHelis, 0x813D10, 0x813D14);

	/*CPatch::AdjustPointer(CHeli__UpdateHelis + 0xB0, &PoliceHelis, 0x813D10, 0x813D18);
	CPatch::AdjustPointer(CHeli__UpdateHelis + 0xC0, &PoliceHelis, 0x813D10, 0x813D18);
	CPatch::AdjustPointer(0x5ACE80, &PoliceHelis, 0x813D10, 0x813D18);
	CPatch::AdjustPointer(CHeli__InitHelis + 0x35, &PoliceHelis, 0x813D10, 0x813D18);

	CPatch::AdjustPointer(CHeli__InitHelis + 0x3F, &PoliceHelis, 0x813D10, 0x813D1C);*/


	//GenerateHeli
	CPatch::SetUShort(0x5ACD60, 0xDD8B); // mov ebx,ebp
	CPatch::Nop(0x5ACD60 + 0x2, 1);
	CPatch::RedirectJump(0x5ACD7B, asm_GenerateHeli);

	//CHeli__UpdateHelis
	CPatch::RedirectJump(0x5ACEEE, asm_CHeli__UpdateHelis);
	CPatch::RedirectJump(0x5AD412, asm_CHeli__UpdateHelis2);
	CPatch::RedirectJump(0x5AD48F, asm_CHeli__UpdateHelis3);

	//CHeli__TestSniperCollision
	CPatch::RedirectJump(0x5AC69D, asm_CHeli__TestSniperCollision);

	//CHeli__TestRocketCollision
	CPatch::RedirectJump(0x5ACA71, asm_CHeli__TestRocketCollision);
	//CHeli__TestBulletCollision
	CPatch::RedirectJump(0x5AC974, asm_CHeli__TestBulletCollision);
	//CHeli__InitHelis
	CPatch::RedirectJump(CHeli__InitHelis, CHeli_InitHelis);

	//CHeli__UpdateHelis fix
	CPatch::RedirectJump(0x5ACE1B, asm_CHeli__UpdateHelisFix);
	CPatch::RedirectJump(0x5AD174, asm_CHeli__UpdateHelis4);
	//CPatch::Nop(0x5ACEE0, 2);
	CPatch::Nop(0x5ACEE5, 2);

	CPatch::Nop(0x5AD1FD, 2);
	CPatch::Nop(0x5AD202, 2);

	CPatch::RedirectJump(0x5AD447, asm_CHeli__UpdateHelis5);
}

signed int __fastcall CWanted__NumOfHelisRequired(int CPlayerPed_wanted)
{
	signed int result; // eax@3

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

		g_HeliLimitx4 = g_HeliLimit * 4;

		IncreasePoliceHelisArray();

		CPatch::RedirectCall(0x409083, CWanted__NumOfHelisRequired);
		CPatch::RedirectCall(0x5ACDB5, CWanted__NumOfHelisRequired);

		CPatch::SetUInt(0x5AC8FC + 0x6, g_HeliHealth);
		CPatch::SetUInt(0x5AC8E7 + 0x6, g_HeliHealth / 1.75f);

		CPatch::SetUInt(0x5ACDEE + 0x2, g_Time1);
		CPatch::SetUInt(0x5AD26E + 0x1, g_Time2);

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

