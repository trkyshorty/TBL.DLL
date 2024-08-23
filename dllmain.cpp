// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <map>
#include <string>
#include <iostream>

typedef struct __TABLE_UPC_SKILL
{
    uint32_t			iID;
    std::string			szEngName;
    std::string			szName;
    std::string			szDesc;
    int32_t				iSelfAnimID1;
    int32_t				iSelfAnimID2;

    int32_t				idwTargetAnimID;
    int32_t				iSelfFX1;
    int32_t				iSelfPart1;
    int32_t				iSelfFX2;
    int32_t				iSelfPart2;
    int32_t				iFlyingFX;
    int32_t				iTargetFX;

    int32_t				iTargetPart;
    int32_t				iTarget;
    int32_t				iNeedLevel;
    int32_t				iNeedSkill;

    int32_t				iExhaustMSP;
    int32_t				iExhaustHP;
    int16_t				iExhaustStamina;

    uint32_t			iCastTime;

    uint32_t			dwNeedItem;
    int32_t				iReCastTime;
    int32_t				iCooldown;
    float				fUnknown1;
    uint8_t				iUnknown2;
    float				fUnknown3;
    int32_t				iPercentSuccess;
    uint32_t			dw1stTableType;
    uint32_t			dw2ndTableType;
    int32_t				iValidDist;

    int32_t				iUnknown4;
    uint32_t			dwUnknown5;
    int32_t				iUnknown6;
    uint32_t			iBaseId;
    uint8_t				byUnknown8;
    uint8_t				byUnknown9;
    int32_t				iUnknown10;
} TABLE_UPC_SKILL;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
        {
			DWORD skillTable = *reinterpret_cast<DWORD*>(0x010A5968); // __TABLE_UPC_SKILL address

			std::map<uint32_t, __TABLE_UPC_SKILL>& skillTableList =
				*reinterpret_cast<std::map<uint32_t, __TABLE_UPC_SKILL>*>(skillTable + 0x10); // Data offset

			size_t skillTableSize = *reinterpret_cast<size_t*>(skillTable + 0x14); // Data size offset

            for (auto& x : skillTableList)
            {
                std::cout << x.second.iID << " - " << x.second.szName << std::endl;
            }
        }
        break;

        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}

