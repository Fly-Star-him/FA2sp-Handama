#include <Helpers/Macro.h>
#include <CMapData.h>

#include <map>

#include "../FA2sp.h"
#include "../Helpers/STDHelpers.h"
#include "../Helpers/ControlHelpers.h"

DEFINE_HOOK(43CE50, Miscs_LoadParamToCombobox, 7)
{
    GET_STACK(ppmfc::CComboBox*, pComboBox, 0x4);
    GET_STACK(int, nCode, 0x8);

    if (nCode <= 30) // 30 is our float
        return 0;

    if (nCode >= 500) // Custom params from FAData TriggerParamTypes section
	{
        ControlHelpers::ComboBox::LoadTriggerParamType(*pComboBox, nCode);
	    return 0x43D058;
	}
    auto const pINI = CMapData::GetMapDocument(true);
	
    // Consistence with FA2Ext
    switch (nCode)
    {
    case 31: // Enter Status
        pComboBox->DeleteAllStrings();
        pComboBox->AddString("0 - ��Sleep (���ߣ�������)");
        pComboBox->AddString("1 - Attack nearest enemy");
        pComboBox->AddString("2 - Move");
        pComboBox->AddString("3 - QMove");
        pComboBox->AddString("4 - Retreat (�����ͼ)");
        pComboBox->AddString("5 - ��Guard (ԭ�ؾ���)");
        pComboBox->AddString("6 - Sticky (���أ�����������)");
        pComboBox->AddString("7 - Enter object");
        pComboBox->AddString("8 - Capture object");
        pComboBox->AddString("9 - Move into & get eaten");
        pComboBox->AddString("10 - Harvest (�ɿ�)");
        pComboBox->AddString("11 - ��Area Guard (���򾯽�)");
        pComboBox->AddString("12 - Return (to refinery)");
        pComboBox->AddString("13 - Stop");
        pComboBox->AddString("14 - Ambush (wait until discovered)");
        pComboBox->AddString("15 - ��Hunt (����)");
        pComboBox->AddString("16 - ��Unload (ж�ػ���)");
        pComboBox->AddString("17 - Sabotage (move in & destroy)");
        pComboBox->AddString("18 - Construction");
        pComboBox->AddString("19 - Deconstruction");
        pComboBox->AddString("20 - Repair");
        pComboBox->AddString("21 - Rescue");
        pComboBox->AddString("22 - Missile");
        pComboBox->AddString("23 - ��Harmless (����в)");
        pComboBox->AddString("24 - Open");
        pComboBox->AddString("25 - Patrol");
        pComboBox->AddString("26 - Paradrop approach drop zone");
        pComboBox->AddString("27 - Paradrop overlay drop zone");
        pComboBox->AddString("28 - Wait");
        pComboBox->AddString("29 - Attack again");
        pComboBox->AddString("30 - Spyplane approach (YR)");
        pComboBox->AddString("31 - Spyplane overfly (YR)");
        break;
    case 32: // Targets
        pComboBox->DeleteAllStrings();
        pComboBox->AddString("0 - ����Ŀ��");
        pComboBox->AddString("1 - ����Ŀ��");
        pComboBox->AddString("2 - ������");
        pComboBox->AddString("3 - �󳵿�");
        pComboBox->AddString("4 - ����");
        pComboBox->AddString("5 - ����");
        pComboBox->AddString("6 - ��������");
        pComboBox->AddString("7 - ��������");
        pComboBox->AddString("8 - ������в");
        pComboBox->AddString("9 - �糧");
        pComboBox->AddString("10 - פ������");
        pComboBox->AddString("11 - �Ƽ�����");
        break;
    case 33: // Facing
        pComboBox->DeleteAllStrings();
        pComboBox->AddString("0 - �J");
        pComboBox->AddString("1 - ��");
        pComboBox->AddString("2 - �K");
        pComboBox->AddString("3 - ��");
        pComboBox->AddString("4 - �L");
        pComboBox->AddString("5 - ��");
        pComboBox->AddString("6 - �I");
        pComboBox->AddString("7 - ��");
        break;
    case 34: // Split
        pComboBox->DeleteAllStrings();
        pComboBox->AddString("0 - �����ؾߣ�������Ա");
        pComboBox->AddString("1 - �����ؾߣ�������Ա");
        pComboBox->AddString("2 - �����ؾߣ�������Ա");
        pComboBox->AddString("3 - �����ؾߣ�������Ա");
        break;
    case 35: // Camera Move Speed
        pComboBox->DeleteAllStrings();
        pComboBox->AddString("0 - �ǳ���");
        pComboBox->AddString("1 - ��");
        pComboBox->AddString("2 - ����");
        pComboBox->AddString("3 - ��");
        pComboBox->AddString("4 - �ǳ���");
        break;
    case 37: // Radar Event Type
        pComboBox->DeleteAllStrings();
        pComboBox->AddString("0 - ս��");
        pComboBox->AddString("1 - ��ս��");
        pComboBox->AddString("2 - �ս���");
        pComboBox->AddString("3 - �����ܻ�");
        pComboBox->AddString("4 - ���ܻ�");
        pComboBox->AddString("5 - ���ֵо�");
        pComboBox->AddString("6 - ��λ����");
        pComboBox->AddString("7 - ��λ����");
        pComboBox->AddString("8 - ��λά��");
        pComboBox->AddString("9 - ��������͸");
        pComboBox->AddString("10 - ������ռ��");
        pComboBox->AddString("11 - �ű����");
        pComboBox->AddString("12 - ���ֳ���");
        pComboBox->AddString("13 - ��������");
        pComboBox->AddString("14 - ����ά��");
        pComboBox->AddString("15 - ����פ��");
        pComboBox->AddString("16 - �Ѿ��ܻ�");
        break;
    case 38: // Tabpage
        pComboBox->DeleteAllStrings();
        pComboBox->AddString("0 - ������");
        pComboBox->AddString("1 - ��������");
        pComboBox->AddString("2 - ����");
        pComboBox->AddString("3 - ��λ");
        break;
    case 39: // SuperWeaponTypes (ID)
        ControlHelpers::ComboBox::LoadGenericList(*pComboBox, "SuperWeaponTypes", true, false, true);
        break;
    case 40: // Variable Operators
        pComboBox->AddString("0 - ��ֵ (=)     A=B");
        pComboBox->AddString("1 - �� (+)         A=A+B");
        pComboBox->AddString("2 - �� (-)         A=A-B");
        pComboBox->AddString("3 - �� (*)         A=A*B");
        pComboBox->AddString("4 - �� (/)         A=A/B");
        pComboBox->AddString("5 - ���� (%)    A=A%B");
        pComboBox->AddString("6 - ���� (<<)   A=A<<B");
        pComboBox->AddString("7 - ���� (>>)   A=A>>B");
        pComboBox->AddString("8 - ��ת (~)     A=~A");
        pComboBox->AddString("9 - ���           A=A��B");
        pComboBox->AddString("10 - ��            A=A|B");
        pComboBox->AddString("11 - ��            A=A&B");
		break;
    case 41: // House Addons
        ControlHelpers::ComboBox::LoadCountries(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddonMulti(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddon(*pComboBox, true);
        break;
    case 42: // House Addons for pb events
        ControlHelpers::ComboBox::LoadCountries(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddonMulti(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddon2(*pComboBox, true);
        break;
    case 43: //Tag List for action 70

        pComboBox->DeleteAllStrings();

        
        pComboBox->LockWindowUpdate();

        if (ExtConfigs::SortByTriggerName && pComboBox->GetDlgCtrlID() == 1402)
        {
            std::map<ppmfc::CString, ppmfc::CString> collector;

            if (auto const pSection = pINI->GetSection("Tags"))
            {
                for (auto& pair : pSection->GetEntities())
                {
                    auto splits = STDHelpers::SplitString(pair.second, 2);
                    ppmfc::CString buffer(pair.first);
                    buffer += " (" + splits[1] + ")" + " (" + splits[2] + ")";
                    collector.insert(std::make_pair(splits[1], buffer));
                }
            }

            for (auto& pair : collector)
                pComboBox->AddString(pair.second);

            collector.clear();
        }
        else
        {
            if (auto pSection = pINI->GetSection("Tags"))
            {
                for (auto& pair : pSection->GetEntities())
                {
                    auto splits = STDHelpers::SplitString(pair.second, 2);
                    ppmfc::CString buffer = pair.first;
                    buffer += " (" + splits[1] + ")" + " (" + splits[2] + ")";
                    pComboBox->AddString(buffer);
                }
            }
        }

        pComboBox->UnlockWindowUpdate();
        break;
    case 44: // Country Addons -1
        ControlHelpers::ComboBox::LoadCountries(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddon3(*pComboBox, true);
        break;
    case 45: // pure House
        ControlHelpers::ComboBox::LoadCountries(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddonMulti(*pComboBox, true);
        break;
    case 46: // Country Addons -1 + multi (ares)
        ControlHelpers::ComboBox::LoadCountries(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddonMultiAres(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddon3(*pComboBox, true);
        break;
    case 47: // Country + multi (ares)
        ControlHelpers::ComboBox::LoadCountries(*pComboBox, true);
        ControlHelpers::ComboBox::LoadHousesAddonMultiAres(*pComboBox, true);
        break;
    default: // Not a valid param
        break;
    }

    return 0x43D058;
}

DEFINE_HOOK(43D037, Miscs_LoadParams_AdjustComboboxDropdownWidth, C)
{
    if (ExtConfigs::AdjustDropdownWidth)
    {
        GET_STACK(ppmfc::CComboBox*, pComboBox, STACK_OFFS(0x18, -0x4));

        int nWidth = 120;
        for (int i = 0; i < pComboBox->GetCount() && nWidth <= ExtConfigs::AdjustDropdownWidth_Max; ++i)
            nWidth = std::max(nWidth, pComboBox->GetLBTextLen(i) * ExtConfigs::AdjustDropdownWidth_Factor);

        nWidth = std::min(nWidth, ExtConfigs::AdjustDropdownWidth_Max);
        pComboBox->SetDroppedWidth(nWidth);
    }

    return 0;
}

DEFINE_HOOK(43CFE4, Miscs_LoadParams_SpeechBubble, 6)
{
    auto AddString = [](HWND hComboBox, const char* lpString)
    {
        SendMessage(hComboBox, CB_ADDSTRING, NULL, (LPARAM)lpString);
    };

    GET(HWND, hComboBox, ECX);
    while (SendMessage(hComboBox, CB_GETCOUNT, 0, NULL) > 0)
        SendMessage(hComboBox, CB_DELETESTRING, 0, 0);
    AddString(hComboBox, "0 - ��");
    AddString(hComboBox, "1 - �Ǻ�(*)");
    AddString(hComboBox, "2 - �ʺ�(?)");
    AddString(hComboBox, "3 - ��̾��(!)");
    return 0x43D037;
}

DEFINE_HOOK(441910, Miscs_LoadParams_TutorialTexts, 7)
{
    GET_STACK(ppmfc::CComboBox*, pComboBox, 0x4);
    if (ExtConfigs::TutorialTexts_Hide)
    {
        pComboBox->DeleteAllStrings();
        return 0x441A34;
    }
    if (ExtConfigs::TutorialTexts_Fix)
    {   
        pComboBox->DeleteAllStrings();
        for (auto& x : FA2sp::TutorialTextsMap)
            pComboBox->AddString(x.first + " : " + x.second);
        Logger::Debug("%d csf entities added.\n", FA2sp::TutorialTextsMap.size());
        return 0x441A34;
    }
    return 0;
}

DEFINE_HOOK(441A40, Miscs_LoadParams_Triggers, 6)
{
    GET_STACK(ppmfc::CComboBox*, pComboBox, 0x4);

    pComboBox->DeleteAllStrings();

    auto const pINI = CMapData::GetMapDocument(true);
    pComboBox->LockWindowUpdate();

    if (ExtConfigs::SortByTriggerName && pComboBox->GetDlgCtrlID() == 1402)
    {
        std::map<ppmfc::CString, ppmfc::CString> collector;
        
        if (auto const pSection = pINI->GetSection("Triggers"))
        {
            for (auto& pair : pSection->GetEntities())
            {
                auto splits = STDHelpers::SplitString(pair.second, 2);
                ppmfc::CString buffer(pair.first);
                buffer += " (" + splits[2] + ")";
                collector.insert(std::make_pair(splits[2], buffer));
            }
        }

        for (auto& pair : collector)
            pComboBox->AddString(pair.second);

        collector.clear();
    }
    else
    {
        if (auto pSection = pINI->GetSection("Triggers"))
        {
            for (auto& pair : pSection->GetEntities())
            {
                auto splits = STDHelpers::SplitString(pair.second, 2);
                ppmfc::CString buffer = pair.first;
                buffer += " (" + splits[2] + ")";
                pComboBox->AddString(buffer);
            }
        }
    }

    pComboBox->UnlockWindowUpdate();
    return 0x441DF6;
}

