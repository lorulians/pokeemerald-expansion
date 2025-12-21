RustboroCity_Flat1_1F_MapScripts::
	.byte 0

RustboroCity_Flat1_1F_EventScript_Beauty::
	msgbox RustboroCity_Flat1_1F_Text_HiddenAbilitys, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman::
	msgbox RustboroCity_Flat1_1F_Text_PokemonAbilities, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Lillipup::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_LILLIPUP, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat1_1F_Text_Lillipup, MSGBOX_NPC
	waitmoncry
	release
	end

RustboroCity_Flat1_1F_Text_Lillipup:
	.string "Cooper: Awuff…$"

RustboroCity_Flat1_1F_Text_HiddenAbilitys:
	.string "Did you know some Pokémon have\n"
	.string "what's known as a Hidden Ability?$"

RustboroCity_Flat1_1F_Text_PokemonAbilities:
	.string "Pokémon abilities are usually\n"
	.string "helpful, but some can be more of\p"
	.string "a hinderance.$"

