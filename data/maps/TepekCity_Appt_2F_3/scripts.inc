TepekCity_Appt_2F_3_MapScripts::
	.byte 0

TepekCity_Appt_2F_3_EventScript_Beauty::
	msgbox TepekCity_Appt_2F_3_Text_HiddenAbilitys, MSGBOX_NPC
	end

TepekCity_Appt_2F_3_EventScript_Woman::
	msgbox TepekCity_Appt_2F_3_Text_PokemonAbilities, MSGBOX_NPC
	end

TepekCity_Appt_2F_3_EventScript_Lillipup::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_LILLIPUP, CRY_MODE_NORMAL
	msgbox TepekCity_Appt_2F_3_Text_Lillipup, MSGBOX_NPC
	waitmoncry
	release
	end

TepekCity_Appt_2F_3_Text_Lillipup:
	.string "Cooper: Awuff…$"

TepekCity_Appt_2F_3_Text_HiddenAbilitys:
	.string "Did you know some Pokémon have\n"
	.string "what's known as a Hidden Ability?$"

TepekCity_Appt_2F_3_Text_PokemonAbilities:
	.string "Pokémon abilities are usually\n"
	.string "helpful, but some can be more of\p"
	.string "a hinderance.$"

