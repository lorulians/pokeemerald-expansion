Route233_MarwicksHouse_MapScripts::
	.byte 0

Route233_MarwicksHouse_EventScript_Stoutland::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STOUTLAND, CRY_MODE_WEAK
	msgbox Route233_MarwicksHouse_Text_Stoutland, MSGBOX_NPC
	waitmoncry
	release
	end

Route233_MarwicksHouse_Text_Stoutland:
	.string "The old Stoutland is well past his\n"
	.string "battling days. He is lazing in a\p"
	.string "sunny patch and snoring loudly.$"
