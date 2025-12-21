RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_unset FLAG_TEPEK_ESCAPEROPE_RECEIVED, RustboroCity_EventScript_OldManRopeGive
	goto_if_set FLAG_TEPEK_ESCAPEROPE_RECEIVED, RustboroCity_EventScript_OldManRopeGiven
	release
	end
	msgbox RustboroCity_CuttersHouse_Text_EscapeRopes, MSGBOX_DEFAULT
	end

RustboroCity_EventScript_OldManRopeGive::
	msgbox RustboroCity_CuttersHouse_Text_EscapeRopes, MSGBOX_NPC
	giveitem ITEM_ESCAPE_ROPE, 1
	setflag FLAG_TEPEK_ESCAPEROPE_RECEIVED
	return

RustboroCity_EventScript_OldManRopeGiven::
	msgbox RustboroCity_Text_QuickEscape, MSGBOX_NPC
	return

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_PeopleWorkAtPlant, MSGBOX_NPC
	end

RustboroCity_Text_QuickEscape:
	.string "Use an Escape Rope to make a\n"
	.string "quick escape!$"

RustboroCity_CuttersHouse_Text_EscapeRopes:
	.string "Tarountula silk is used to create\n"
	.string "Escape Ropes! Here, have one on the\p"
	.string "house. Don't be shy!$"

RustboroCity_CuttersHouse_Text_PeopleWorkAtPlant:
	.string "Lots of people in Tepek City work at\n"
	.string "the Power Plant. It helps supply\p"
	.string "power to all of the Sansuba region!$"
