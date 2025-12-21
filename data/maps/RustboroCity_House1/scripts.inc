RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_PokeFanM::
	msgbox RustboroCity_House1_Text_SentHomeEarly, MSGBOX_NPC
	end

RustboroCity_House1_EventScript_PokeFanF::
	msgbox RustboroCity_House1_Text_RunToMart, MSGBOX_NPC
	end

RustboroCity_House1_EventScript_Kid::
	lock
	msgbox RustboroCity_House1_Text_CheckingCalendar, MSGBOX_NPC
	applymovement LOCALID_TEPEK_GYM_GUIDE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_House1_EventScript_Nickit::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NICKIT, CRY_MODE_NORMAL
	msgbox RustboroCity_House1_Text_Nickit, MSGBOX_NPC
	waitmoncry
	release
	end

RustboroCity_House1_Text_SentHomeEarly:
	.string "You never know what'll happen\n"
	.string "on your journey. There's only\p"
	.string "one way to find out.$"

RustboroCity_House1_Text_RunToMart:
	.string "I have to run to the Mart\n"
	.string "later for some cooking supplies.$"

RustboroCity_House1_Text_CheckingCalendar:
	.string "I'm checking my calendar!$"

RustboroCity_House1_Text_Nickit:
	.string "Swiper: Awwwraaa raaa.$"
