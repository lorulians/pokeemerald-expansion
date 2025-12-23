#include "global.h"
#include "event_data.h"
#include "field_message_box.h"
#include "pokedex.h"
#include "strings.h"

bool16 ScriptGetPokedexInfo(void)
{
    if (gSpecialVar_0x8004 == 0) // is national dex not present?
    {
        gSpecialVar_0x8005 = GetHoennPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetHoennPokedexCount(FLAG_GET_CAUGHT);
    }
    else
    {
        gSpecialVar_0x8005 = GetNationalPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetNationalPokedexCount(FLAG_GET_CAUGHT);
    }

    return IsNationalPokedexEnabled();
}

#define CEDAR_DEX_STRINGS 21

static const u8 *const sCedarDexRatingTexts[CEDAR_DEX_STRINGS] =
{
    gCedarDexRatingText_LessThan10,
    gCedarDexRatingText_LessThan20,
    gCedarDexRatingText_LessThan30,
    gCedarDexRatingText_LessThan40,
    gCedarDexRatingText_LessThan50,
    gCedarDexRatingText_LessThan60,
    gCedarDexRatingText_LessThan70,
    gCedarDexRatingText_LessThan80,
    gCedarDexRatingText_LessThan90,
    gCedarDexRatingText_LessThan100,
    gCedarDexRatingText_LessThan110,
    gCedarDexRatingText_LessThan120,
    gCedarDexRatingText_LessThan130,
    gCedarDexRatingText_LessThan140,
    gCedarDexRatingText_LessThan150,
    gCedarDexRatingText_LessThan160,
    gCedarDexRatingText_LessThan170,
    gCedarDexRatingText_LessThan180,
    gCedarDexRatingText_LessThan190,
    gCedarDexRatingText_LessThan200,
    gCedarDexRatingText_DexCompleted,
};

// This shows your Hoenn Pokédex rating and not your National Dex.
const u8 *GetPokedexRatingText(u32 count)
{
    u32 i, j;
    u16 maxDex = HOENN_DEX_COUNT - 1;
    // doesNotCountForRegionalPokedex
    for(i = 0; i < HOENN_DEX_COUNT; i++)
    {
        j = NationalPokedexNumToSpecies(HoennToNationalOrder(i + 1));
        if (gSpeciesInfo[j].isMythical && !gSpeciesInfo[j].dexForceRequired)
        {
            if (GetSetPokedexFlag(j, FLAG_GET_CAUGHT))
                count--;
            maxDex--;
        }
    }
    return sCedarDexRatingTexts[(count * (CEDAR_DEX_STRINGS - 1)) / maxDex];
}

void ShowPokedexRatingMessage(void)
{
    ShowFieldMessage(GetPokedexRatingText(gSpecialVar_0x8004));
}
