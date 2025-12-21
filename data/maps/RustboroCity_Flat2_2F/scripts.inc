RustboroCity_Flat2_2F_MapScripts::
	.byte 0

RustboroCity_Flat2_2F_EventScript_Girl::
	msgbox RustboroCity_Flat2_2F_Text_TaillowBetter, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_Boy::
	msgbox RustboroCity_Flat2_2F_Text_MurkrowBetter, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_Taillow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TAILLOW, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat2_2F_Text_Taillow, MSGBOX_NPC
	waitmoncry
	release
	end

RustboroCity_Flat2_2F_EventScript_Murkrow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RustboroCity_Flat2_2F_Text_Murkrow, MSGBOX_NPC
	waitmoncry
	release
	end

RustboroCity_Flat2_2F_Text_MurkrowBetter:
	.string "Murkrow is better! It's little\n"
	.string "hat and tail are so cute!$"

RustboroCity_Flat2_2F_Text_TaillowBetter:
	.string "Taillow is better! Don't you\n"
	.string "see how cute it is when you\p"
	.string "see its little mouth?!$"

RustboroCity_Flat2_2F_Text_Murkrow:
	.string "Lefty: Kaw kaw!$"

RustboroCity_Flat2_2F_Text_Taillow:
	.string "Gusty: Cheepy cheep!$"
