LittlerootTown_NPCHouse2_MapScripts::
	.byte 0

LittlerootTown_NPCHouse2_EventScript_Kid::
	goto_if_eq VAR_KID_CHATOT, 0, LittlerootTown_NPCHouse2_Event_MeetMyChatot
	goto_if_ge VAR_KID_CHATOT, 2, LittlerootTown_NPCHouse2_Event_IsntHeSilly
	end

LittlerootTown_NPCHouse2_EventScript_Chatot::
	goto_if_le VAR_KID_CHATOT, 1, LittlerootTown_NPCHouse2_Event_ChatotLaLaLa
	goto_if_eq VAR_KID_CHATOT, 2, LittlerootTown_NPCHouse2_Event_ChatotCopy1
	goto_if_ge VAR_KID_CHATOT, 3, LittlerootTown_NPCHouse2_Event_ChatotCopy2
	end

LittlerootTown_NPCHouse2_Event_MeetMyChatot::
	msgbox LittlerootTown_NPCHouse2_Text_MeetMyChatot, MSGBOX_DEFAULT
	setvar VAR_KID_CHATOT, 2
	release
	end

LittlerootTown_NPCHouse2_EventScript_Dad::
	faceplayer
	msgbox LittlerootTown_NPCHouse2_Text_KidsAreHandful, MSGBOX_DEFAULT
	release
	end

LittlerootTown_NPCHouse2_Event_IsntHeSilly::
	msgbox LittlerootTown_NPCHouse2_Text_IsntHeSilly, MSGBOX_DEFAULT
	release
	end

LittlerootTown_NPCHouse2_Event_ChatotLaLaLa::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
	msgbox LittlerootTown_Text_Chatot, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LittlerootTown_NPCHouse2_Event_ChatotCopy1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
	msgbox LittlerootTown_Text_ChatotCopy1, MSGBOX_DEFAULT
	waitmoncry
	setvar VAR_KID_CHATOT, 3
	release
	end

LittlerootTown_NPCHouse2_Event_ChatotCopy2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHATOT, CRY_MODE_NORMAL
	msgbox LittlerootTown_Text_ChatotCopy2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LittlerootTown_NPCHouse2_Text_MeetMyChatot:
	.string "This is my CHATOT. He copies whatever\n"
	.string "I say.$"

LittlerootTown_NPCHouse2_Text_KidsAreHandful:
	.string "Kids are a handful. You'll understand\n"
	.string "when you're older.$"

LittlerootTown_NPCHouse2_Text_IsntHeSilly:
	.string "See? Isn't he funny?.$"

LittlerootTown_Text_Chatot:
	.string "CHATTERBOX: La la la!$"

LittlerootTown_Text_ChatotCopy1:
	.string "CHATTERBOX: He copies whatever I say!$"

LittlerootTown_Text_ChatotCopy2:
	.string "CHATTERBOX: Isn't he funny! La la la!$"
