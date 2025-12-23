 RedgeTown_PlayersHouse_2F_MapScripts::
	@ map_script MAP_SCRIPT_ON_TRANSITION, RedgeTown_PlayersHouse_2F_OnTransition
	.byte 0

@ RedgeTown_PlayersHouse_2F_OnTransition:
	@ end

PlayersHouse_EventScript_SetIntroFlags::
	lockall
	setflag FLAG_VISITED_REDGE_TOWN
	setrespawn HEAL_LOCATION_REDGE_TOWN_PLAYERS_HOUSE_2F
	setvar VAR_REDGE_HOUSES_STATE_BRENDAN, 1
	goto PlayersHouse_2F_EventScript_MomComesUpstairs
	releaseall
	end

RedgeTown_PlayersHouse_2F_EventScript_PC::
	lockall
	goto RedgeTown_PlayersHouse_2F_EventScript_CheckPlayersPC
	end

RedgeTown_PlayersHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

RedgeTown_PlayersHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
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
	.string "Mom: {PLAYER}?\n"
	.string "Oh, good, you're already dressed!\p"
	.string "I got you new batteries for your\n"
	.string "wall clock, don't forget to set it!\p"
	.string "Make sure everything is alright on\n"
	.string "your desk, then come downstairs.$"

PlayersHouse_2F_Text_Notebook:
	.string "{PLAYER} flipped open the notebook.\p"
	.string "ADVENTURE RULE NO. 1\n"
	.string "Talk to every NPC you meet.\p"
	.string "ADVENTURE RULE NO. 2\n"
	.string "Report bugs when you see them!\p"
	.string "The remaining pages are blank…$"

Common_Text_LookCloserAtMap:
	.string "{PLAYER} took a closer look at the\n"
	.string "Sansuba region map.$"

PlayersHouse_2F_Text_ItsAGameCube:
	.string "It's a Nintendo GameCube.\p"
	.string "A Game Boy Advance is connected to\n"
	.string "serve as the Controller.$"
