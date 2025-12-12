 LittlerootTown_BrendansHouse_2F_MapScripts::
	@ map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
	.byte 0

@ LittlerootTown_BrendansHouse_2F_OnTransition:
	@ end

PlayersHouse_EventScript_SetIntroFlags::
	lockall
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	goto PlayersHouse_2F_EventScript_MomComesUpstairs
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_PC::
	lockall
	goto LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

PlayersHouse_2F_EventScript_Notebook::
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
	end

PlayersHouse_2F_EventScript_GameCube::
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
	end

PlayersHouse_2F_Text_ClockIsStopped:
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"

PlayersHouse_2F_Text_SetYourClock:
	.string "MOM: {PLAYER}?\n"
	.string "Oh, good, you're already dressed!\p"
	.string "I got you new batteries for your\n"
	.string "wall clock, don't forget to set it!\p"
	.string "Make sure everything is alright on\n"
	.string "your desk, then come downstairs.$"

PlayersHouse_2F_Text_Notebook:
	.string "{PLAYER} flipped open the notebook.\p"
	.string "ADVENTURE RULE NO. 1\n"
	.string "Open the MENU with START.\p"
	.string "ADVENTURE RULE NO. 2\n"
	.string "Record your progress with SAVE.\p"
	.string "The remaining pages are blank…$"

Common_Text_LookCloserAtMap:
	.string "{PLAYER} took a closer look at the\n"
	.string "SANSUBA region map.$"

PlayersHouse_2F_Text_ItsAGameCube:
	.string "It's a Nintendo GameCube.\p"
	.string "A Game Boy Advance is connected to\n"
	.string "serve as the Controller.$"
