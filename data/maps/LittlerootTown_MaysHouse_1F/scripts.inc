LittlerootTown_MaysHouse_1F_MapScripts::
	.byte 0

LittlerootTown_NPCHouse1_EventScript_Woman::
	msgbox LittlerootTown_NPCHouse1_Text_NothingGoodOnTV, MSGBOX_DEFAULT
	release
	end

LittlerootTown_NPCHouse1_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox LittlerootTown_NPCHouse1_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LittlerootTown_NPCHouse1_Text_NothingGoodOnTV:
	.string "Ugh, there's never anything good\n"
	.string "on TV, anymore.$"

LittlerootTown_NPCHouse1_Text_Skitty:
	.string "TIPTOE: Nyaa, nyaa!$"
