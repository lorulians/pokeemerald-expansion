TriHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
TriHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, TriHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, TriHideout_1F_EventScript_MagmaHideoutHint1
	msgbox TriHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

TriHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox TriHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

TriHideout_1F_EventScript_SlateportHint1::
	msgbox TriHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

TriHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, TriHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, TriHideout_1F_EventScript_MagmaHideoutHint2
	msgbox TriHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

TriHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox TriHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

TriHideout_1F_EventScript_SlateportHint2::
	msgbox TriHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

TriHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "What? What? What do you want with \n"
	.string "TEAM TRI?\p"
	.string "Our BOSS isn't here! He's gone off to\n"
	.string "snatch something important!\p"
	.string "… …\n"
	.string "Where did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

TriHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "What? What?\n"
	.string "Are you a TEAM MAGMA grunt?\p"
	.string "I hear that TEAM MAGMA is trying to\n"
	.string "awaken an awesome POKéMON at their\l"
	.string "HIDEOUT.\p"
	.string "But where might their HIDEOUT be?$"

TriHideout_1F_Text_BossWentToJackASubmarine:
	.string "What? What? What do you want with \n"
	.string "TEAM TRI?\p"
	.string "Our BOSS isn't here!\n"
	.string "He's gone off to jack a submarine!\p"
	.string "… …\n"
	.string "Where did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

TriHideout_1F_Text_BossIsOnRoute122:
	.string "What? What? What do you want with \n"
	.string "TEAM TRI?\p"
	.string "Our BOSS isn't here! He's on his way to\n"
	.string "MT. PYRE on ROUTE 122!\p"
	.string "… …\n"
	.string "Why did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

TriHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "What? What?\n"
	.string "Are you a TEAM MAGMA grunt?\p"
	.string "I hear that TEAM MAGMA is after\n"
	.string "an awesome POKéMON at MT. CHIMNEY.\p"
	.string "But what is that POKéMON like?$"

TriHideout_1F_Text_BossIsInSlateportCity:
	.string "What? What? What do you want with\n"
	.string "TEAM TRI?\p"
	.string "Our BOSS isn't here!\n"
	.string "He's on his way to SLATEPORT CITY!\p"
	.string "… …\n"
	.string "Why did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

