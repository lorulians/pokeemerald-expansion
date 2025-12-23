RedgeTown_NPCHouse1_MapScripts::
	.byte 0

RedgeTown_NPCHouse1_EventScript_Woman::
	msgbox RedgeTown_NPCHouse1_Text_NothingGoodOnTV, MSGBOX_DEFAULT
	release
	end

RedgeTown_NPCHouse1_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox RedgeTown_NPCHouse1_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RedgeTown_NPCHouse1_Text_NothingGoodOnTV:
	.string "Ugh, there's never anything good\n"
	.string "on TV, anymore.$"

RedgeTown_NPCHouse1_Text_Skitty:
	.string "Tiptoe: Nyaa, nyaa!$"
