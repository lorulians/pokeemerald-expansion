RustboroCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
	.byte 0

RustboroCity_OnTransition:
	setflag FLAG_VISITED_RUSTBORO_CITY
	call_if_eq VAR_RUSTBORO_CITY_STATE, 2, RustboroCity_EventScript_HideFollower
	call_if_eq VAR_RUSTBORO_CITY_STATE, 4, RustboroCity_EventScript_ShowGrunts
	// call Common_EventScript_SetupRivalGfxId
	// call_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_HideMapNamePopup
	// getplayerxy VAR_TEMP_0, VAR_TEMP_1
	// goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_PositionScientistForExit
	end
	
RustboroCity_EventScript_HideFollower::
	setflag FLAG_HIDE_FOLLOWER_MON
	return
	
RustboroCity_EventScript_ShowGrunts::
	clearflag FLAG_HIDE_TEPEK_TRIGRUNT
	return

// RustboroCity_EventScript_PositionScientistForExit::
	// goto_if_eq VAR_TEMP_0, 11, RustboroCity_EventScript_PositionScientistLeftExit
	// setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 12, 15
	// end

// RustboroCity_EventScript_PositionScientistLeftExit::
	// setobjectxyperm LOCALID_RUSTBORO_SCIENTIST, 11, 15
	// end

// RustboroCity_EventScript_HideMapNamePopup::
	// setflag FLAG_HIDE_MAP_NAME_POPUP
	// return

RustboroCity_OnFrame:
	.2byte 0

// RustboroCity_Movement_ScientistWalkInPlaceDown:
	// walk_in_place_down
	// step_end

// RustboroCity_Movement_PlayerWalkDown:
	// walk_down
	// step_end

// RustboroCity_Movement_ScientistApproachPlayer:
	// walk_down
	// delay_16
	// step_end

// RustboroCity_Movement_ScientistLeave:
	// walk_up
	// step_end

RustboroCity_EventScript_TeamTriRunBy0::
	lockall
	addobject LOCALID_TEPEK_TRIGRUNT_A
	addobject LOCALID_TEPEK_TRIGRUNT_B
	setobjectxy LOCALID_TEPEK_TRIGRUNT_A, 18, 26
	setobjectxy LOCALID_TEPEK_TRIGRUNT_B, 18, 25
	msgbox RustboroCity_Text_TriGrunts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_TRI, FALSE
	applymovement LOCALID_TEPEK_TRIGRUNT_A, RustboroCity_Movement_TriGruntA
	applymovement LOCALID_TEPEK_TRIGRUNT_B, RustboroCity_Movement_TriGruntB
	applymovement LOCALID_PLAYER, RustboroCity_Movement_PlayerPushedRight
	waitmovement 0
	setvar VAR_RUSTBORO_CITY_STATE, 5
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

RustboroCity_Text_TriGrunts:
	.string "???: GET OUT OF OUR WAY!$"

RustboroCity_Movement_TriGruntA:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	set_invisible
	step_end

RustboroCity_Movement_TriGruntB:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	set_invisible
	step_end

RustboroCity_Movement_PlayerPushed:
	delay_16
	delay_16
	delay_8
	face_right
	lock_facing_direction
	walk_fast_left
	delay_8
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

RustboroCity_Movement_PlayerPushedRight:
	delay_16
	delay_16
	delay_8
	face_left
	lock_facing_direction
	walk_fast_right
	delay_8
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

RustboroCity_EventScript_TeamTriRunBy1::
	lockall
	addobject LOCALID_TEPEK_TRIGRUNT_A
	addobject LOCALID_TEPEK_TRIGRUNT_B
	setobjectxy LOCALID_TEPEK_TRIGRUNT_A, 19, 26
	setobjectxy LOCALID_TEPEK_TRIGRUNT_B, 19, 25
	msgbox RustboroCity_Text_TriGrunts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_TRI, FALSE
	applymovement LOCALID_TEPEK_TRIGRUNT_A, RustboroCity_Movement_TriGruntA
	applymovement LOCALID_TEPEK_TRIGRUNT_B, RustboroCity_Movement_TriGruntB
	applymovement LOCALID_PLAYER, RustboroCity_Movement_PlayerPushed
	waitmovement 0
	removeobject LOCALID_TEPEK_TRIGRUNT_A
	removeobject LOCALID_TEPEK_TRIGRUNT_B
	setvar VAR_RUSTBORO_CITY_STATE, 5
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

RustboroCity_EventScript_TeamTriRunBy2::
	lockall
	addobject LOCALID_TEPEK_TRIGRUNT_A
	addobject LOCALID_TEPEK_TRIGRUNT_B
	setobjectxy LOCALID_TEPEK_TRIGRUNT_A, 20, 26
	setobjectxy LOCALID_TEPEK_TRIGRUNT_B, 20, 25
	msgbox RustboroCity_Text_TriGrunts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_TRI, FALSE
	applymovement LOCALID_TEPEK_TRIGRUNT_A, RustboroCity_Movement_TriGruntA
	applymovement LOCALID_TEPEK_TRIGRUNT_B, RustboroCity_Movement_TriGruntB
	applymovement LOCALID_PLAYER, RustboroCity_Movement_PlayerPushed
	waitmovement 0
	removeobject LOCALID_TEPEK_TRIGRUNT_A
	removeobject LOCALID_TEPEK_TRIGRUNT_B
	setvar VAR_RUSTBORO_CITY_STATE, 5
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

RustboroCity_EventScript_TeamTriRunBy3::
	lockall
	addobject LOCALID_TEPEK_TRIGRUNT_A
	addobject LOCALID_TEPEK_TRIGRUNT_B
	setobjectxy LOCALID_TEPEK_TRIGRUNT_A, 21, 26
	setobjectxy LOCALID_TEPEK_TRIGRUNT_B, 21, 25
	msgbox RustboroCity_Text_TriGrunts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_TRI, FALSE
	applymovement LOCALID_TEPEK_TRIGRUNT_A, RustboroCity_Movement_TriGruntA
	applymovement LOCALID_TEPEK_TRIGRUNT_B, RustboroCity_Movement_TriGruntB
	applymovement LOCALID_PLAYER, RustboroCity_Movement_PlayerPushed
	waitmovement 0
	removeobject LOCALID_TEPEK_TRIGRUNT_A
	removeobject LOCALID_TEPEK_TRIGRUNT_B
	setvar VAR_RUSTBORO_CITY_STATE, 5
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

RustboroCity_EventScript_ParkMother::
	lock
	faceplayer
	msgbox RustboroCity_Text_SoMuchEnergy, MSGBOX_NPC
	release
	end

RustboroCity_EventScript_ParkBoy::
	lock
	faceplayer
	msgbox RustboroCity_Text_GonnaCatchYou, MSGBOX_NPC
	release
	end

RustboroCity_EventScript_ParkPikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_Text_ParkPikachu, MSGBOX_NPC
	waitmoncry
	release
	end

RustboroCity_EventScript_Herdier::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HERDIER, CRY_MODE_NORMAL
	msgbox RustboroCity_Text_Herdier, MSGBOX_NPC
	waitmoncry
	release
	end

RustboroCity_EventScript_ParkSkwovet::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKWOVET, CRY_MODE_NORMAL
	msgbox RustboroCity_Text_ParkSkwovet, MSGBOX_NPC
	waitmoncry
	release
	end


// RustboroCity_EventScript_FatManSawGrunt::
	// msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
	// release
	// end

// RustboroCity_EventScript_DevonEmployee2::
	// lock
	// faceplayer
	// msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
	// release
	// end

RustboroCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_unset FLAG_TEPEK_PARALYZHEAL_RECEIVED, RustboroCity_EventScript_WomanParalyzHealGive
	goto_if_set FLAG_TEPEK_PARALYZHEAL_RECEIVED, RustboroCity_EventScript_WomanParalyzHealGiven
	release
	end

RustboroCity_EventScript_WomanParalyzHealGive::
	msgbox RustboroCity_Text_SittingWithBoyfriend, MSGBOX_NPC
	giveitem ITEM_PARALYZE_HEAL, 1
	setflag FLAG_TEPEK_PARALYZHEAL_RECEIVED
	return

RustboroCity_EventScript_WomanParalyzHealGiven::
	msgbox RustboroCity_Text_HopefullyThatHelps, MSGBOX_NPC
	return

RustboroCity_EventScript_Man::
	lock
	faceplayer
	msgbox RustboroCity_Text_SittingWithGirlfriend, MSGBOX_NPC
	release
	end

RustboroCity_EventScript_Beauty::
	lock
	faceplayer
	msgbox RustboroCity_Text_WelcomeToTepek, MSGBOX_NPC
	release
	end

RustboroCity_EventScript_SidewalkBoy::
	lock
	faceplayer
	msgbox RustboroCity_Text_CiellusUsesFlyingTypes, MSGBOX_NPC
	release
	end

RustboroCity_EventScript_SidewalkLass::
	lock
	faceplayer
	msgbox RustboroCity_Text_TypesStrongToFlying, MSGBOX_NPC
	release
	end

RustboroCity_EventScript_FatMan::
	lock
	faceplayer
	goto_if_le VAR_RUSTBORO_CITY_STATE, 3, RustboroCity_EventScript_TepekFatManBrownOuts
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 5, RustboroCity_EventScript_TepekFatManSomeoneRanBy
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_TepekFatManPowerBack
	release
	end

RustboroCity_EventScript_Gym_Guide::
	lock
	faceplayer
	goto_if_le VAR_RUSTBORO_CITY_STATE, 5, RustboroCity_EventScript_GymIsClosed
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_TepekGuideGoInside
	release
	end

RustboroCity_EventScript_TepekGuideGoInside::
	delay 30
	applymovement LOCALID_TEPEK_GYM_GUIDE, Common_Movement_Delay48
	waitmovement 0
	playse SE_PIN
    applymovement LOCALID_TEPEK_GYM_GUIDE, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_TEPEK_GYM_GUIDE, Common_Movement_Delay48
    waitmovement 0
	msgbox RustboroCity_Text_TepekGuidePowerBack, MSGBOX_NPC
	waitmessage
	applymovement LOCALID_TEPEK_GYM_GUIDE, Common_Movement_WalkInPlaceFasterUp
	opendoor 8, 31
	waitdooranim
	applymovement LOCALID_TEPEK_GYM_GUIDE, RustboroCity_Movement_TepekGuideEnterDoor
	waitmovement 0
	closedoor 8, 31
	waitdooranim
	removeobject LOCALID_TEPEK_GYM_GUIDE
	release
	end

RustboroCity_Movement_TepekGuideEnterDoor:
	walk_up
	set_invisible
	step_end

RustboroCity_EventScript_GymIsClosed::
	msgbox RustboroCity_Text_GymIsClosed, MSGBOX_NPC
	applymovement LOCALID_TEPEK_GYM_GUIDE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	return

RustboroCity_EventScript_TepekFatManBrownOuts::
	msgbox RustboroCity_Text_TepekFatManBrownOuts, MSGBOX_NPC
	return

RustboroCity_EventScript_TepekFatManSomeoneRanBy::
	msgbox RustboroCity_Text_TepekFatManSomeoneRanBy, MSGBOX_NPC
	return

RustboroCity_EventScript_TepekFatManPowerBack::
	msgbox RustboroCity_Text_TepekFatManPowerBack, MSGBOX_NPC
	return

RustboroCity_Text_TepekFatManSomeoneRanBy:
	.string "Some Trainers dressed in odd clothes\n"
	.string "ran past to the Power Plant.\p"
	.string "They were in such a hurry, I had no\n"
	.string "time to stop them.$"

RustboroCity_Text_TepekFatManBrownOuts:
	.string "Tepek City has been experiencing\n"
	.string "frequent blackouts.\p"
	.string "I wonder what's going on at the\n"
	.string "Power Plant?$"

RustboroCity_Text_TepekFatManPowerBack:
	.string "Looks like the power's back, now.$"

RustboroCity_EventScript_ParkGirl::
	lock
	faceplayer
	msgbox RustboroCity_Text_RacingMySkwovet, MSGBOX_NPC
	release
	end

RustboroCity_EventScript_JudeEmerge0::
	lock
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	opendoor 33, 34
	waitdooranim
	addobject LOCALID_TEPEK_RIVAL
	applymovement LOCALID_TEPEK_RIVAL, RustboroCity_Movement_TepekRivalExitDoor
	setvar VAR_0x8008, 0
	waitmovement 0
	closedoor 33, 34
	waitdooranim
	delay 5
	applymovement LOCALID_TEPEK_RIVAL, RustboroCity_Movement_TurnToPlayer0
	waitmovement 0
	msgbox RustboroCity_Text_JudeWaitUpLetsGo, MSGBOX_NPC
	waitmessage
	goto RustboroCity_EventScript_WalkToArea
	release
	end

RustboroCity_EventScript_JudeEmerge1::
	lock
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	opendoor 33, 34
	waitdooranim
	addobject LOCALID_TEPEK_RIVAL
	applymovement LOCALID_TEPEK_RIVAL, RustboroCity_Movement_TepekRivalExitDoor
	setvar VAR_0x8008, 1
	waitmovement 0
	closedoor 33, 34
	waitdooranim
	delay 5
	applymovement LOCALID_TEPEK_RIVAL, RustboroCity_Movement_TurnToPlayer1
	waitmovement 0
	msgbox RustboroCity_Text_JudeWaitUpLetsGo, MSGBOX_NPC
	waitmessage
	goto RustboroCity_EventScript_WalkToArea
	release
	end

RustboroCity_EventScript_JudeEmerge2::
	lock
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	opendoor 33, 34
	waitdooranim
	addobject LOCALID_TEPEK_RIVAL
	applymovement LOCALID_TEPEK_RIVAL, RustboroCity_Movement_TepekRivalExitDoor
	setvar VAR_0x8008, 2
	waitmovement 0
	closedoor 33, 34
	waitdooranim
	delay 5
	applymovement LOCALID_TEPEK_RIVAL, RustboroCity_Movement_TurnToPlayer2
	waitmovement 0
	msgbox RustboroCity_Text_JudeWaitUpLetsGo, MSGBOX_NPC
	waitmessage
	goto RustboroCity_EventScript_WalkToArea
	release
	end

RustboroCity_EventScript_WalkToArea::
	call_if_eq VAR_0x8008, 0, RustboroCity_EventScript_WalkToArea0
	call_if_eq VAR_0x8008, 1, RustboroCity_EventScript_WalkToArea1
	call_if_eq VAR_0x8008, 2, RustboroCity_EventScript_WalkToArea2

RustboroCity_EventScript_WalkToArea0::
	applymovement LOCALID_PLAYER, RustboroCity_Movement_TepekPlayerWalkToArea0
	applymovement LOCALID_TEPEK_RIVAL, RustboroCity_Movement_TepekRivalWalkToArea0
	waitmovement 0
	goto RustboroCity_EventScript_JudeRivalBattle
	end

RustboroCity_EventScript_WalkToArea1::
	applymovement LOCALID_PLAYER, RustboroCity_Movement_TepekPlayerWalkToArea1
	applymovement LOCALID_TEPEK_RIVAL, RustboroCity_Movement_TepekRivalWalkToArea1
	waitmovement 0
	goto RustboroCity_EventScript_JudeRivalBattle
	end

RustboroCity_EventScript_WalkToArea2::
	applymovement LOCALID_PLAYER, RustboroCity_Movement_TepekPlayerWalkToArea2
	applymovement LOCALID_TEPEK_RIVAL, RustboroCity_Movement_TepekRivalWalkToArea2
	waitmovement 0
	goto RustboroCity_EventScript_JudeRivalBattle
	end

RustboroCity_Movement_TurnToPlayer0:
	walk_in_place_left
	step_end

RustboroCity_Movement_TurnToPlayer1:
	walk_in_place_down
	step_end

RustboroCity_Movement_TurnToPlayer2:
	walk_in_place_right
	step_end

RustboroCity_EventScript_JudeRivalBattle::
	delay 10
	msgbox RustboroCity_Text_JudeLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_StartJudeBattleSnivy
	case 1, RustboroCity_EventScript_StartJudeBattleScorbunny
	case 2, RustboroCity_EventScript_StartJudeBattleSquirtle

RustboroCity_EventScript_StartJudeBattleSnivy::
	trainerbattle_no_intro TRAINER_JUDE_TEPEK_CITY_SNIVY, RustboroCity_Text_JudeDefeated
	goto RustboroCity_EventScript_AfterJudeBattle
	end

RustboroCity_EventScript_StartJudeBattleScorbunny::
	trainerbattle_no_intro TRAINER_JUDE_TEPEK_CITY_SCORBUNNY, RustboroCity_Text_JudeDefeated
	goto RustboroCity_EventScript_AfterJudeBattle
	end

RustboroCity_EventScript_StartJudeBattleSquirtle::
	trainerbattle_no_intro TRAINER_JUDE_TEPEK_CITY_SQUIRTLE, RustboroCity_Text_JudeDefeated
	goto RustboroCity_EventScript_AfterJudeBattle
	end

RustboroCity_EventScript_AfterJudeBattle::
	msgbox RustboroCity_Text_JudeTimeToHeadBack, MSGBOX_DEFAULT
	closemessage
	goto RustboroCity_EventScript_RivalExit
	end

RustboroCity_EventScript_RivalExit::
	applymovement LOCALID_TEPEK_RIVAL, RustboroCity_Movement_RivalLeave
	waitmovement 0
	setvar VAR_RUSTBORO_CITY_STATE, 3
	setvar VAR_CEDAR_LAB_STATE, 5
	clearflag FLAG_HIDE_FOLLOWER_MON
	callnative UpdateFollowingPokemon
	removeobject LOCALID_TEPEK_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

RustboroCity_EventScript_NoGo::
	lockall
	applymovement LOCALID_TEPEK_FATMAN, Common_Movement_WalkInPlaceRight
	msgbox RustboroCity_Text_FM_HeyKid
	waitmessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	msgbox RustboroCity_Text_FM_NoGo
	waitmessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_TEPEK_FATMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end


RustboroCity_Movement_RivalLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RustboroCity_Movement_TepekPlayerWalkToArea0:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_2
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_in_place_right
	step_end

RustboroCity_Movement_TepekRivalWalkToArea0:
	walk_down
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_left
	step_end

RustboroCity_Movement_TepekPlayerWalkToArea1:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_in_place_right
	step_end

RustboroCity_Movement_TepekRivalWalkToArea1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_left
	step_end

RustboroCity_Movement_TepekPlayerWalkToArea2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_in_place_right
	step_end

RustboroCity_Movement_TepekRivalWalkToArea2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_left
	step_end

RustboroCity_Movement_TepekRivalExitDoor:
	walk_down
	delay_8
	step_end

RustboroCity_EventScript_Boy1::
	lock
	faceplayer
	msgbox RustboroCity_Text_LockedOut, MSGBOX_NPC
	applymovement LOCALID_LOCKEDBOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_GameBoyKidLeft::
	lock
	faceplayer
	msgbox RustboroCity_Text_GameBoyKidLeft, MSGBOX_NPC
	applymovement LOCALID_GBKIDL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end


RustboroCity_EventScript_GameBoyKidRight::
	lock
	faceplayer
	msgbox RustboroCity_Text_GameBoyKidRight, MSGBOX_NPC
	applymovement LOCALID_GBKIDR, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_Boy2::
	lock
	faceplayer
	msgbox RustboroCity_Text_Banners, MSGBOX_NPC
	release
	end

RustboroCity_EventScript_ParkSign::
	msgbox RustboroCity_Text_ParkSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_PowerPlantSign::
	msgbox RustboroCity_Text_PowerPlantSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_ApartmentSign::
	msgbox RustboroCity_Text_ApartmentSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_GymSign::
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CitySign::
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
	end

// RustboroCity_EventScript_Rival::
// lockall
// call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_FacePlayer
// waitmovement 0
// goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_PlayRivalMusic::
	//checkplayergender
	//goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_PlayMayMusic
	//goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_PlayBrendanMusic
	end

// RustboroCity_EventScript_PlayMayMusic::
// playbgm MUS_ENCOUNTER_MAY, TRUE
// return
// 
// RustboroCity_EventScript_PlayBrendanMusic::
// playbgm MUS_ENCOUNTER_BRENDAN, TRUE
// return
// 
// RustboroCity_EventScript_RivalTrigger0::
// lockall
// call RustboroCity_EventScript_PlayRivalMusic
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto RustboroCity_EventScript_RivalEncounter
// 
// RustboroCity_EventScript_RivalTrigger1::
// lockall
// call RustboroCity_EventScript_PlayRivalMusic
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto RustboroCity_EventScript_RivalEncounter
// 
// RustboroCity_EventScript_RivalTrigger2::
// lockall
// call RustboroCity_EventScript_PlayRivalMusic
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto RustboroCity_EventScript_RivalEncounter
// 
// RustboroCity_EventScript_RivalTrigger3::
// lockall
// call RustboroCity_EventScript_PlayRivalMusic
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto RustboroCity_EventScript_RivalEncounter
// 
// RustboroCity_EventScript_RivalTrigger4::
// lockall
// call RustboroCity_EventScript_PlayRivalMusic
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto RustboroCity_EventScript_RivalEncounter
// 
// RustboroCity_EventScript_RivalTrigger5::
// lockall
// call RustboroCity_EventScript_PlayRivalMusic
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto RustboroCity_EventScript_RivalEncounter
// 
// RustboroCity_EventScript_RivalTrigger6::
// lockall
// call RustboroCity_EventScript_PlayRivalMusic
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto RustboroCity_EventScript_RivalEncounter
// 
// RustboroCity_EventScript_RivalTrigger7::
// lockall
// call RustboroCity_EventScript_PlayRivalMusic
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_RUSTBORO_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto RustboroCity_EventScript_RivalEncounter
// 
// RustboroCity_EventScript_RivalEncounter::
// checkplayergender
// goto_if_eq VAR_RESULT, MALE, RustboroCity_EventScript_MayEncounter
// goto_if_eq VAR_RESULT, FEMALE, RustboroCity_EventScript_BrendanEncounter
// end
// 
// RustboroCity_EventScript_MayEncounter::
// goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
// goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
// setflag FLAG_MET_RIVAL_RUSTBORO
// msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
// closemessage
// delay 30
// playfanfare MUS_REGISTER_MATCH_CALL
// msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
// waitfanfare
// closemessage
// delay 30
// setflag FLAG_ENABLE_RIVAL_MATCH_CALL
// setvar VAR_RUSTBORO_CITY_STATE, 8
// setvar VAR_ROUTE104_STATE, 2
// msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
// goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
// msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
// call RustboroCity_EventScript_RestoreBgm
// releaseall
// end
// 
// RustboroCity_EventScript_MayAskToBattle::
// msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
// goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleMay
// msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
// releaseall
// end
// 
// RustboroCity_EventScript_BattleMay::
// msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
// switch VAR_STARTER_MON
// case 0, RustboroCity_EventScript_BattleMayTreecko
// case 1, RustboroCity_EventScript_BattleMayTorchic
// case 2, RustboroCity_EventScript_BattleMayMudkip
// end
// 
// RustboroCity_EventScript_MayBrineyHint::
// msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
// releaseall
// end
// 
// RustboroCity_EventScript_RestoreBgm::
// savebgm MUS_DUMMY
// fadedefaultbgm
// return
// 
// RustboroCity_EventScript_BattleMayTreecko::
// trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
// setflag FLAG_DEFEATED_RIVAL_RUSTBORO
// goto RustboroCity_EventScript_MayBrineyHint
// end
// 
// RustboroCity_EventScript_BattleMayTorchic::
// trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
// setflag FLAG_DEFEATED_RIVAL_RUSTBORO
// goto RustboroCity_EventScript_MayBrineyHint
// end
// 
// RustboroCity_EventScript_BattleMayMudkip::
// trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
// setflag FLAG_DEFEATED_RIVAL_RUSTBORO
// goto RustboroCity_EventScript_MayBrineyHint
// end
// 
// RustboroCity_EventScript_BrendanEncounter::
// goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
// goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
// setflag FLAG_MET_RIVAL_RUSTBORO
// msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
// closemessage
// delay 30
// playfanfare MUS_REGISTER_MATCH_CALL
// msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
// waitfanfare
// closemessage
// delay 30
// setflag FLAG_ENABLE_RIVAL_MATCH_CALL
// setvar VAR_RUSTBORO_CITY_STATE, 8
// setvar VAR_ROUTE104_STATE, 2
// msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
// goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
// call RustboroCity_EventScript_RestoreBgm
// releaseall
// end
// 
// RustboroCity_EventScript_BrendanAskToBattle::
// msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
// goto_if_eq VAR_RESULT, YES, RustboroCity_EventScript_BattleBrendan
// releaseall
// end
// 
// RustboroCity_EventScript_BattleBrendan::
// msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
// switch VAR_STARTER_MON
// case 0, RustboroCity_EventScript_BattleBrendanTreecko
// case 1, RustboroCity_EventScript_BattleBrendanTorchic
// case 2, RustboroCity_EventScript_BattleBrendanMudkip
// end
// 
// RustboroCity_EventScript_BrendanBrineyHint::
// msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
// releaseall
// end
// 
// RustboroCity_EventScript_BattleBrendanTreecko::
// trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
// setflag FLAG_DEFEATED_RIVAL_RUSTBORO
// goto RustboroCity_EventScript_BrendanBrineyHint
// end
// 
// RustboroCity_EventScript_BattleBrendanTorchic::
// trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
// setflag FLAG_DEFEATED_RIVAL_RUSTBORO
// goto RustboroCity_EventScript_BrendanBrineyHint
// end
// 
// RustboroCity_EventScript_BattleBrendanMudkip::
// trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
// setflag FLAG_DEFEATED_RIVAL_RUSTBORO
// goto RustboroCity_EventScript_BrendanBrineyHint
// end

// RustboroCity_Movement_RivalApproachPlayer0:
// walk_down
// walk_left
// walk_left
// walk_left
// walk_left
// walk_down
// step_end
// 
// RustboroCity_Movement_RivalApproachPlayer1:
// walk_down
// walk_left
// walk_left
// walk_left
// walk_down
// step_end
// 
// RustboroCity_Movement_RivalApproachPlayer2:
// walk_down
// walk_left
// walk_left
// walk_down
// step_end
// 
// RustboroCity_Movement_RivalApproachPlayer3:
// walk_down
// walk_left
// walk_down
// step_end
// 
// RustboroCity_Movement_RivalApproachPlayer4:
// walk_down
// walk_down
// step_end
// 
// RustboroCity_Movement_RivalApproachPlayer5:
// walk_down
// walk_right
// walk_down
// step_end
// 
// RustboroCity_Movement_RivalApproachPlayer6:
// walk_down
// walk_right
// walk_right
// walk_down
// step_end
// 
// RustboroCity_Movement_RivalApproachPlayer7:
// walk_down
// walk_right
// walk_right
// walk_right
// walk_down
// step_end

RustboroCity_Text_TepekGuidePowerBack:
	.string "The power is back! That means we\n"
	.string "can reopen the Gym!\p"
	.string "Let me get things turned back on.$"

RustboroCity_Text_GymIsClosed:
	.string "Sorry, kid, the Gym is closed\n"
	.string "due to the blackouts.$"

RustboroCity_Text_TypesStrongToFlying:
	.string "Do you know what types are strong\n"
	.string "against Flying-types?\p"
	.string "Electric-, Rock-, and Ice-types!$"

RustboroCity_Text_CiellusUsesFlyingTypes:
	.string "Ciellus uses Flying-type Pokémon!\n"
	.string "Her father was a pilot, so it runs\l"
	.string "in the family.$"

RustboroCity_Text_WelcomeToTepek:
	.string "Heya, welcome to Tepek City!$"

RustboroCity_Text_JudeTimeToHeadBack:
	.string "Jude: Wow, that was a great battle!\n"
	.string "I should probably head back inside,\p"
	.string "now. You should probably go and tell\n"
	.string "Prof. Cedar you made the delivery.\p"
	.string "See you, {PLAYER}{KUN}!$"

RustboroCity_Text_JudeDefeated:
	.string "Jude: That was fun! Thanks!$"

RustboroCity_Text_JudeLetsBattle:
	.string "Jude: Alright, let's battle!$"

RustboroCity_Text_JudeWaitUpLetsGo:
	.string "Jude: Wait up, {PLAYER}{KUN}!\p"
	.string "Let's go, I know where we can\n"
	.string "battle!$"

RustboroCity_Text_SoMuchEnergy:
	.string "On nice days, I bring my son and\n"
	.string "his Pikachu to the park. They can\l"
	.string "run for hours!\p"
	.string "I wish I had that much energy!$"

RustboroCity_Text_GonnaCatchYou:
	.string "I'm gonna catch you!$"

RustboroCity_Text_ParkPikachu:
	.string "Zapper: Chuuu!$"

RustboroCity_Text_Herdier:
	.string "Bessie: Rrrrruff!!$"

RustboroCity_Text_RacingMySkwovet:
	.string "Me and my Skwovet are having\n"
	.string "a race!\p"
	.string "He's winning.$"

RustboroCity_Text_ParkSkwovet:
	.string "Appi: Chchchcha!$"

RustboroCity_Text_GameBoyKidLeft:
	.string "Me and my friend are trading\n"
	.string "our Pokémon!$"

RustboroCity_Text_GameBoyKidRight:
	.string "This guy doesn't have very good\n"
	.string "trades…$"

RustboroCity_Text_LockedOut:
	.string "I think I left my key inside\n"
	.string "when I locked the door…$"

RustboroCity_Text_Banners:
	.string "Tepek City's streets are lined\n"
	.string "with banners! Aren't they super\p"
	.string "cool when they sway in the wind?$"

RustboroCity_Text_SittingWithGirlfriend:
	.string "My girlfriend is smart. She gets\n"
	.string "the best discounts at the Mart!$"

RustboroCity_Text_SittingWithBoyfriend:
	.string "My boyfriend doesn't know the\n"
	.string "difference between an Antidote\p"
	.string "and a Paralyze Heal. Here, I\n"
	.string "don't need this.$"

RustboroCity_Text_HopefullyThatHelps:
	.string "Paralyze Heal cure Paralysis, while\n"
	.string "Antidotes cure Poison.$"

RustboroCity_Text_ParkSign:
	.string "Tepek City Park\n"
	.string "Paid for by Sansuba Power Plant$"

RustboroCity_Text_PowerPlantSign:
	.string "Sansuba Power Plant {RIGHT_ARROW}$"

RustboroCity_Text_ApartmentSign:
	.string "Tepek City Apartments$"

RustboroCity_Text_GymSign:
	.string "Tepek City Pokémon Gym\n"
	.string "Leader: Ciellus\p"
	.string "“Taking flight with Flying-types!”$"

RustboroCity_Text_CitySign:
	.string "Tepek City\p"
	.string "“A city that soars above in\n"
	.string "excellence!”$"

RustboroCity_Text_FM_HeyKid:
	.string "Hey, kid.$"

RustboroCity_Text_FM_NoGo:
	.string "Something's up at the Power Plant.\p"
	.string "It isn't safe for a kid, so you\n"
	.string "better come back this way.$"