TepekCity_Appt_3F_2_MapScripts::
	.byte 0

TepekCity_Appt_3F_2_EventScript_OldMan::
	lock
	faceplayer
	goto_if_unset FLAG_TEPEK_ESCAPEROPE_RECEIVED, TepekCity_EventScript_OldManRopeGive
	goto_if_set FLAG_TEPEK_ESCAPEROPE_RECEIVED, TepekCity_EventScript_OldManRopeGiven
	release
	end
	msgbox TepekCity_Appt_3F_2_Text_EscapeRopes, MSGBOX_DEFAULT
	end

TepekCity_EventScript_OldManRopeGive::
	msgbox TepekCity_Appt_3F_2_Text_EscapeRopes, MSGBOX_NPC
	giveitem ITEM_ESCAPE_ROPE, 1
	setflag FLAG_TEPEK_ESCAPEROPE_RECEIVED
	return

TepekCity_EventScript_OldManRopeGiven::
	msgbox TepekCity_Text_QuickEscape, MSGBOX_NPC
	return

TepekCity_Appt_3F_2_EventScript_Lass::
	msgbox TepekCity_Appt_3F_2_Text_PeopleWorkAtPlant, MSGBOX_NPC
	end

TepekCity_Text_QuickEscape:
	.string "Use an Escape Rope to make a\n"
	.string "quick escape!$"

TepekCity_Appt_3F_2_Text_EscapeRopes:
	.string "Tarountula silk is used to create\n"
	.string "Escape Ropes! Here, have one on the\p"
	.string "house. Don't be shy!$"

TepekCity_Appt_3F_2_Text_PeopleWorkAtPlant:
	.string "Lots of people in Tepek City work at\n"
	.string "the Power Plant. It helps supply\p"
	.string "power to all of the Sansuba region!$"
