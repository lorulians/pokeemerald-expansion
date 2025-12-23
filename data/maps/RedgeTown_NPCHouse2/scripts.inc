RedgeTown_NPCHouse2_MapScripts::
	.byte 0

RedgeTown_NPCHouse2_EventScript_Kid::
	goto_if_eq VAR_KID_CHATOT, 0, RedgeTown_NPCHouse2_Event_MeetMyChatot
	goto_if_ge VAR_KID_CHATOT, 2, RedgeTown_NPCHouse2_Event_IsntHeSilly
	end

RedgeTown_NPCHouse2_EventScript_Chatot::
	goto_if_le VAR_KID_CHATOT, 1, RedgeTown_NPCHouse2_Event_ChatotLaLaLa
	goto_if_eq VAR_KID_CHATOT, 2, RedgeTown_NPCHouse2_Event_ChatotCopy1
	goto_if_ge VAR_KID_CHATOT, 3, RedgeTown_NPCHouse2_Event_ChatotCopy2
	end

RedgeTown_NPCHouse2_Event_MeetMyChatot::
	msgbox RedgeTown_NPCHouse2_Text_MeetMyChatot, MSGBOX_DEFAULT
	setvar VAR_KID_CHATOT, 2
	release
	end

RedgeTown_NPCHouse2_EventScript_Dad::
	faceplayer
	msgbox RedgeTown_NPCHouse2_Text_KidsAreHandful, MSGBOX_DEFAULT
	release
	end

RedgeTown_NPCHouse2_Event_IsntHeSilly::
	msgbox RedgeTown_NPCHouse2_Text_IsntHeSilly, MSGBOX_DEFAULT
	release
	end

RedgeTown_NPCHouse2_Event_ChatotLaLaLa::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
	msgbox RedgeTown_Text_Chatot, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RedgeTown_NPCHouse2_Event_ChatotCopy1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
	msgbox RedgeTown_Text_ChatotCopy1, MSGBOX_DEFAULT
	waitmoncry
	setvar VAR_KID_CHATOT, 3
	release
	end

RedgeTown_NPCHouse2_Event_ChatotCopy2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
	msgbox RedgeTown_Text_ChatotCopy2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RedgeTown_NPCHouse2_Text_MeetMyChatot:
	.string "This is my Chatot. He copies whatever\n"
	.string "I say.$"

RedgeTown_NPCHouse2_Text_KidsAreHandful:
	.string "Kids are a handful. You'll understand\n"
	.string "when you're older.$"

RedgeTown_NPCHouse2_Text_IsntHeSilly:
	.string "See? Isn't he funny?$"

RedgeTown_Text_Chatot:
	.string "Chatterbox: La la la!$"

RedgeTown_Text_ChatotCopy1:
	.string "Chatterbox: He copies whatever I\n"
	.string "say! La la la!$"

RedgeTown_Text_ChatotCopy2:
	.string "Chatterbox: Isn't he funny! La la la!$"
