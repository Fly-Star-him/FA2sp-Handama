#include "Body.h"

#include <Helpers/Macro.h>

#include "../../Helpers/Translations.h"

DEFINE_HOOK(502E66, CTriggerOption_OnInitDialog_RepeatTypeFix, 7)
{
    GET(CTriggerOption*, pThis, ESI);

    pThis->CCBHouse.DeleteAllStrings();
    pThis->CCBRepeatType.DeleteAllStrings();

    pThis->CCBRepeatType.AddString(Translations::TranslateOrDefault("TriggerRepeatType.OneTimeOr", "0 - ��һ������������������ִ��һ��"));
    pThis->CCBRepeatType.AddString(Translations::TranslateOrDefault("TriggerRepeatType.OneTimeAnd", "1 - ���й�����������������ִ��һ��"));
    pThis->CCBRepeatType.AddString(Translations::TranslateOrDefault("TriggerRepeatType.RepeatingOr", "2 - ��һ�������������������ظ�ִ��"));

    return 0;
}
