TepekCity_Appt_2F_1_MapScripts::
	.byte 0

TepekCity_Appt_2F_1_EventScript_PokeFanM::
	msgbox TepekCity_Appt_2F_1_Text_SentHomeEarly, MSGBOX_NPC
	end

TepekCity_Appt_2F_1_EventScript_PokeFanF::
	msgbox TepekCity_Appt_2F_1_Text_RunToMart, MSGBOX_NPC
	end

TepekCity_Appt_2F_1_EventScript_Kid::
	lock
	msgbox TepekCity_Appt_2F_1_Text_CheckingCalendar, MSGBOX_NPC
	applymovement LOCALID_TEPEK_GYM_GUIDE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

TepekCity_Appt_2F_1_EventScript_Nickit::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NICKIT, CRY_MODE_NORMAL
	msgbox TepekCity_Appt_2F_1_Text_Nickit, MSGBOX_NPC
	waitmoncry
	release
	end

TepekCity_Appt_2F_1_Text_SentHomeEarly:
	.string "You never know what'll happen\n"
	.string "on your journey. There's only\p"
	.string "one way to find out.$"

TepekCity_Appt_2F_1_Text_RunToMart:
	.string "I have to run to the Mart\n"
	.string "later for some cooking supplies.$"

TepekCity_Appt_2F_1_Text_CheckingCalendar:
	.string "I'm checking my calendar!$"

TepekCity_Appt_2F_1_Text_Nickit:
	.string "Swiper: Awwwraaa raaa.$"
