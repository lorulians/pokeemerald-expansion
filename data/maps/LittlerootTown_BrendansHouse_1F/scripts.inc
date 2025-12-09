LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 7, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 5, 6
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_Yampy::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_YAMPER, CRY_MODE_NORMAL
	msgbox LittlerootTown_BrendansHouse_1F_Text_Yampy, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LittlerootTown_BrendansHouse_1F_Text_Yampy:
	.string "YAMPY: Yip yip!$"


@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
@ LittlerootTown_BrendansHouse_1F_OnFrame:
	@ .2byte 0

LittlerootTown_BrendansHouse_1F_Movement_LookMom:
	walk_in_place_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_LookPlayer:
	walk_in_place_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_LookUp:
	walk_in_place_up
	step_end

PlayersHouse_1F_Event_CallFromCedarMale::
	msgbox PlayersHouse_1F_Text_CallFromCedarMale
	return

PlayersHouse_1F_Event_CallFromCedarFemale::
	msgbox PlayersHouse_1F_Text_CallFromCedarFemale
	return

LittlerootTown_BrendansHouse_1F_EventScript_SeeCedar0::
	lockall
	setvar VAR_0x8008, 0
	delay 10
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PlayersHouse_1F_Event_CallFromCedarMale
	call_if_eq VAR_RESULT, FEMALE, PlayersHouse_1F_Event_CallFromCedarFemale
	delay 2
	msgbox PlayersHouse_1F_Text_ComeHerePlayer
	waitmessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_MoveToMom0
	waitmovement
	goto LittlerootTown_BrendansHouse_1F_EventScript_SeeCedar
	end

LittlerootTown_BrendansHouse_1F_EventScript_SeeCedar1::
	lockall
	setvar VAR_0x8008, 1
	delay 10
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PlayersHouse_1F_Event_CallFromCedarMale
	call_if_eq VAR_RESULT, FEMALE, PlayersHouse_1F_Event_CallFromCedarFemale
	msgbox PlayersHouse_1F_Text_ComeHerePlayer
	waitmessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_LookMom
	waitmovement
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_MoveToMom1
	waitmovement
	goto LittlerootTown_BrendansHouse_1F_EventScript_SeeCedar
	end

LittlerootTown_BrendansHouse_1F_EventScript_SeeCedar2::
	lockall
	setvar VAR_0x8008, 2
	delay 10
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PlayersHouse_1F_Event_CallFromCedarMale
	call_if_eq VAR_RESULT, FEMALE, PlayersHouse_1F_Event_CallFromCedarFemale
	msgbox PlayersHouse_1F_Text_ComeHerePlayer
	waitmessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_LookMom
	waitmovement
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_MoveToMom2
	waitmovement
	goto LittlerootTown_BrendansHouse_1F_EventScript_SeeCedar
	end

LittlerootTown_BrendansHouse_1F_Movement_MoveToMom0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_MoveToMom1:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_MoveToMom2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_SeeCedar::
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_LookPlayer
	msgbox PlayersHouse_1F_Text_CedarCalled
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	releaseall
	end

PlayersHouse_1F_Text_CallFromCedarMale:
	.string "MOM: ...Uh huh...\n"
	.string "...Yep, okay! I'll send him on over!\p"
	.string "Alright, goodbye, FOSTER.$"

PlayersHouse_1F_Text_CallFromCedarFemale:
	.string "MOM: ...Uh huh...\n"
	.string "...Yep, okay! I'll send her on over!\p"
	.string "Alright, goodbye, FOSTER.$"

PlayersHouse_1F_Text_ComeHerePlayer:
	.string "MOM: {PLAYER}, can you come here?$"

PlayersHouse_1F_Text_CedarCalled:
	.string "MOM: PROF. CEDAR just called, he'd\n"
	.string "like to see you over at his LAB.$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MOM: {PLAYER}.\p"
	.string "Go set the clock in your room, honey.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MOM: See you, honey!$"

PlayersHouse_1F_Text_DidYouSeeCedar:
	.string "MOM: PROF. CEDAR is waiting for you!$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MOM: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MOM: Take care, honey!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Don't push yourself too hard, dear.\n"
	.string "You can always come home.\p"
	.string "Go for it, honey!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MOM: What is that, honey? A POKéNAV?\n"
	.string "Someone from DEVON gave it to you?\p"
	.string "Well, honey, how about registering\n"
	.string "your mom?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "Registered MOM\n"
	.string "in the POKéNAV.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "It's the instruction booklet for the\n"
	.string "RUNNING SHOES.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your RUNNING SHOES.\p"
	.string "“Lace up your RUNNING SHOES and hit\n"
	.string "the road running!”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "DAD: Hm?\p"
	.string "Hey, it's {PLAYER}!\p"
	.string "It's been a while since I saw you,\n"
	.string "but you look…stronger, somehow.\p"
	.string "That's the impression I get.\n"
	.string "But your old man hasn't given up yet!\p"
	.string "Oh, yes, I have something for you.\n"
	.string "This came to you from someone named\l"
	.string "MR. BRINEY.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MOM: Is that a breaking news story?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "We bring you this emergency\n"
	.string "news flash!\p"
	.string "In various HOENN locales, there have\n"
	.string "been reports of a BZZT…colored\l"
	.string "POKéMON in flight.\p"
	.string "The identity of this POKéMON is\n"
	.string "currently unknown.\p"
	.string "We now return you to the regular\n"
	.string "movie program.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MOM: {PLAYER}, did you catch that?\p"
	.string "What color did the announcer say\n"
	.string "that POKéMON was?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MOM: Well, isn't that something!\n"
	.string "There are still unknown POKéMON.$"
