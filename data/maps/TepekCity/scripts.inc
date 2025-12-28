TepekCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TepekCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TepekCity_OnFrame
	.byte 0

TepekCity_OnTransition:
	setflag FLAG_VISITED_TEPEK_CITY
	call_if_eq VAR_TEPEK_CITY_STATE, 2, TepekCity_EventScript_HideFollower
	call_if_eq VAR_TEPEK_CITY_STATE, 4, TepekCity_EventScript_ShowGrunts
	// call Common_EventScript_SetupRivalGfxId
	// call_if_eq VAR_TEPEK_CITY_STATE, 6, TepekCity_EventScript_HideMapNamePopup
	// getplayerxy VAR_TEMP_0, VAR_TEMP_1
	// goto_if_eq VAR_TEPEK_CITY_STATE, 6, TepekCity_EventScript_PositionScientistForExit
	end
	
TepekCity_EventScript_HideFollower::
	setflag FLAG_HIDE_FOLLOWER_MON
	return
	
TepekCity_EventScript_ShowGrunts::
	clearflag FLAG_HIDE_TEPEK_TRIGRUNT
	return

// TepekCity_EventScript_PositionScientistForExit::
	// goto_if_eq VAR_TEMP_0, 11, TepekCity_EventScript_PositionScientistLeftExit
	// setobjectxyperm LOCALID_TEPEK_SCIENTIST, 12, 15
	// end

// TepekCity_EventScript_PositionScientistLeftExit::
	// setobjectxyperm LOCALID_TEPEK_SCIENTIST, 11, 15
	// end

// TepekCity_EventScript_HideMapNamePopup::
	// setflag FLAG_HIDE_MAP_NAME_POPUP
	// return

TepekCity_OnFrame:
	.2byte 0

// TepekCity_Movement_ScientistWalkInPlaceDown:
	// walk_in_place_down
	// step_end

// TepekCity_Movement_PlayerWalkDown:
	// walk_down
	// step_end

// TepekCity_Movement_ScientistApproachPlayer:
	// walk_down
	// delay_16
	// step_end

// TepekCity_Movement_ScientistLeave:
	// walk_up
	// step_end

TepekCity_EventScript_TeamTriRunBy0::
	lockall
	addobject LOCALID_TEPEK_TRIGRUNT_A
	addobject LOCALID_TEPEK_TRIGRUNT_B
	setobjectxy LOCALID_TEPEK_TRIGRUNT_A, 18, 26
	setobjectxy LOCALID_TEPEK_TRIGRUNT_B, 18, 25
	msgbox TepekCity_Text_TriGrunts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_TRI, FALSE
	applymovement LOCALID_TEPEK_TRIGRUNT_A, TepekCity_Movement_TriGruntA
	applymovement LOCALID_TEPEK_TRIGRUNT_B, TepekCity_Movement_TriGruntB
	applymovement LOCALID_PLAYER, TepekCity_Movement_PlayerPushedRight
	waitmovement 0
	setvar VAR_TEPEK_CITY_STATE, 5
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

TepekCity_Text_TriGrunts:
	.string "???: GET OUT OF OUR WAY!$"

TepekCity_Movement_TriGruntA:
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

TepekCity_Movement_TriGruntB:
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

TepekCity_Movement_PlayerPushed:
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

TepekCity_Movement_PlayerPushedRight:
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

TepekCity_EventScript_TeamTriRunBy1::
	lockall
	addobject LOCALID_TEPEK_TRIGRUNT_A
	addobject LOCALID_TEPEK_TRIGRUNT_B
	setobjectxy LOCALID_TEPEK_TRIGRUNT_A, 19, 26
	setobjectxy LOCALID_TEPEK_TRIGRUNT_B, 19, 25
	msgbox TepekCity_Text_TriGrunts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_TRI, FALSE
	applymovement LOCALID_TEPEK_TRIGRUNT_A, TepekCity_Movement_TriGruntA
	applymovement LOCALID_TEPEK_TRIGRUNT_B, TepekCity_Movement_TriGruntB
	applymovement LOCALID_PLAYER, TepekCity_Movement_PlayerPushed
	waitmovement 0
	removeobject LOCALID_TEPEK_TRIGRUNT_A
	removeobject LOCALID_TEPEK_TRIGRUNT_B
	setvar VAR_TEPEK_CITY_STATE, 5
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

TepekCity_EventScript_TeamTriRunBy2::
	lockall
	addobject LOCALID_TEPEK_TRIGRUNT_A
	addobject LOCALID_TEPEK_TRIGRUNT_B
	setobjectxy LOCALID_TEPEK_TRIGRUNT_A, 20, 26
	setobjectxy LOCALID_TEPEK_TRIGRUNT_B, 20, 25
	msgbox TepekCity_Text_TriGrunts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_TRI, FALSE
	applymovement LOCALID_TEPEK_TRIGRUNT_A, TepekCity_Movement_TriGruntA
	applymovement LOCALID_TEPEK_TRIGRUNT_B, TepekCity_Movement_TriGruntB
	applymovement LOCALID_PLAYER, TepekCity_Movement_PlayerPushed
	waitmovement 0
	removeobject LOCALID_TEPEK_TRIGRUNT_A
	removeobject LOCALID_TEPEK_TRIGRUNT_B
	setvar VAR_TEPEK_CITY_STATE, 5
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

TepekCity_EventScript_TeamTriRunBy3::
	lockall
	addobject LOCALID_TEPEK_TRIGRUNT_A
	addobject LOCALID_TEPEK_TRIGRUNT_B
	setobjectxy LOCALID_TEPEK_TRIGRUNT_A, 21, 26
	setobjectxy LOCALID_TEPEK_TRIGRUNT_B, 21, 25
	msgbox TepekCity_Text_TriGrunts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_TRI, FALSE
	applymovement LOCALID_TEPEK_TRIGRUNT_A, TepekCity_Movement_TriGruntA
	applymovement LOCALID_TEPEK_TRIGRUNT_B, TepekCity_Movement_TriGruntB
	applymovement LOCALID_PLAYER, TepekCity_Movement_PlayerPushed
	waitmovement 0
	removeobject LOCALID_TEPEK_TRIGRUNT_A
	removeobject LOCALID_TEPEK_TRIGRUNT_B
	setvar VAR_TEPEK_CITY_STATE, 5
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

TepekCity_EventScript_ParkMother::
	lock
	faceplayer
	msgbox TepekCity_Text_SoMuchEnergy, MSGBOX_NPC
	release
	end

TepekCity_EventScript_ParkBoy::
	lock
	faceplayer
	msgbox TepekCity_Text_GonnaCatchYou, MSGBOX_NPC
	release
	end

TepekCity_EventScript_ParkPikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox TepekCity_Text_ParkPikachu, MSGBOX_NPC
	waitmoncry
	release
	end

TepekCity_EventScript_Herdier::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HERDIER, CRY_MODE_NORMAL
	msgbox TepekCity_Text_Herdier, MSGBOX_NPC
	waitmoncry
	release
	end

TepekCity_EventScript_ParkSkwovet::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKWOVET, CRY_MODE_NORMAL
	msgbox TepekCity_Text_ParkSkwovet, MSGBOX_NPC
	waitmoncry
	release
	end


// TepekCity_EventScript_FatManSawGrunt::
	// msgbox TepekCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
	// release
	// end

// TepekCity_EventScript_DevonEmployee2::
	// lock
	// faceplayer
	// msgbox TepekCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
	// release
	// end

TepekCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_unset FLAG_TEPEK_PARALYZHEAL_RECEIVED, TepekCity_EventScript_WomanParalyzHealGive
	goto_if_set FLAG_TEPEK_PARALYZHEAL_RECEIVED, TepekCity_EventScript_WomanParalyzHealGiven
	release
	end

TepekCity_EventScript_WomanParalyzHealGive::
	msgbox TepekCity_Text_SittingWithBoyfriend, MSGBOX_NPC
	giveitem ITEM_PARALYZE_HEAL, 1
	setflag FLAG_TEPEK_PARALYZHEAL_RECEIVED
	return

TepekCity_EventScript_WomanParalyzHealGiven::
	msgbox TepekCity_Text_HopefullyThatHelps, MSGBOX_NPC
	return

TepekCity_EventScript_Man::
	lock
	faceplayer
	msgbox TepekCity_Text_SittingWithGirlfriend, MSGBOX_NPC
	release
	end

TepekCity_EventScript_Beauty::
	lock
	faceplayer
	msgbox TepekCity_Text_WelcomeToTepek, MSGBOX_NPC
	release
	end

TepekCity_EventScript_SidewalkBoy::
	lock
	faceplayer
	msgbox TepekCity_Text_CiellusUsesFlyingTypes, MSGBOX_NPC
	release
	end

TepekCity_EventScript_SidewalkLass::
	lock
	faceplayer
	msgbox TepekCity_Text_TypesStrongToFlying, MSGBOX_NPC
	release
	end

TepekCity_EventScript_FatMan::
	lock
	faceplayer
	goto_if_le VAR_TEPEK_CITY_STATE, 3, TepekCity_EventScript_TepekFatManBrownOuts
	goto_if_eq VAR_TEPEK_CITY_STATE, 5, TepekCity_EventScript_TepekFatManSomeoneRanBy
	goto_if_ge VAR_TEPEK_CITY_STATE, 6, TepekCity_EventScript_TepekFatManPowerBack
	release
	end

TepekCity_EventScript_Gym_Guide::
	lock
	faceplayer
	goto_if_le VAR_TEPEK_CITY_STATE, 5, TepekCity_EventScript_GymIsClosed
	goto_if_eq VAR_TEPEK_CITY_STATE, 6, TepekCity_EventScript_TepekGuideGoInside
	release
	end

TepekCity_EventScript_TepekGuideGoInside::
	delay 30
	applymovement LOCALID_TEPEK_GYM_GUIDE, Common_Movement_Delay48
	waitmovement 0
	playse SE_PIN
    applymovement LOCALID_TEPEK_GYM_GUIDE, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_TEPEK_GYM_GUIDE, Common_Movement_Delay48
    waitmovement 0
	msgbox TepekCity_Text_TepekGuidePowerBack, MSGBOX_NPC
	waitmessage
	applymovement LOCALID_TEPEK_GYM_GUIDE, Common_Movement_WalkInPlaceFasterUp
	opendoor 7, 31
	waitdooranim
	applymovement LOCALID_TEPEK_GYM_GUIDE, TepekCity_Movement_TepekGuideEnterDoor
	waitmovement 0
	closedoor 7, 31
	waitdooranim
	removeobject LOCALID_TEPEK_GYM_GUIDE
	release
	end

TepekCity_Movement_TepekGuideEnterDoor:
	walk_up
	set_invisible
	step_end

TepekCity_EventScript_GymIsClosed::
	msgbox TepekCity_Text_GymIsClosed, MSGBOX_NPC
	applymovement LOCALID_TEPEK_GYM_GUIDE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	return

TepekCity_EventScript_TepekFatManBrownOuts::
	msgbox TepekCity_Text_TepekFatManBrownOuts, MSGBOX_NPC
	return

TepekCity_EventScript_TepekFatManSomeoneRanBy::
	msgbox TepekCity_Text_TepekFatManSomeoneRanBy, MSGBOX_NPC
	return

TepekCity_EventScript_TepekFatManPowerBack::
	msgbox TepekCity_Text_TepekFatManPowerBack, MSGBOX_NPC
	return

TepekCity_Text_TepekFatManSomeoneRanBy:
	.string "Some Trainers dressed in odd clothes\n"
	.string "ran past to the Power Plant.\p"
	.string "They were in such a hurry, I had no\n"
	.string "time to stop them.$"

TepekCity_Text_TepekFatManBrownOuts:
	.string "Tepek City has been experiencing\n"
	.string "frequent blackouts.\p"
	.string "I wonder what's going on at the\n"
	.string "Power Plant?$"

TepekCity_Text_TepekFatManPowerBack:
	.string "Looks like the power's back, now.$"

TepekCity_EventScript_ParkGirl::
	lock
	faceplayer
	msgbox TepekCity_Text_RacingMySkwovet, MSGBOX_NPC
	release
	end

TepekCity_EventScript_JudeEmerge0::
	lock
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	opendoor 33, 34
	waitdooranim
	addobject LOCALID_TEPEK_RIVAL
	applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_TepekRivalExitDoor
	setvar VAR_0x8008, 0
	waitmovement 0
	closedoor 33, 34
	waitdooranim
	delay 5
	applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_TurnToPlayer0
	waitmovement 0
	msgbox TepekCity_Text_JudeWaitUpLetsGo, MSGBOX_NPC
	waitmessage
	goto TepekCity_EventScript_WalkToArea
	release
	end

TepekCity_EventScript_JudeEmerge1::
	lock
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	opendoor 33, 34
	waitdooranim
	addobject LOCALID_TEPEK_RIVAL
	applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_TepekRivalExitDoor
	setvar VAR_0x8008, 1
	waitmovement 0
	closedoor 33, 34
	waitdooranim
	delay 5
	applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_TurnToPlayer1
	waitmovement 0
	msgbox TepekCity_Text_JudeWaitUpLetsGo, MSGBOX_NPC
	waitmessage
	goto TepekCity_EventScript_WalkToArea
	release
	end

TepekCity_EventScript_JudeEmerge2::
	lock
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	opendoor 33, 34
	waitdooranim
	addobject LOCALID_TEPEK_RIVAL
	applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_TepekRivalExitDoor
	setvar VAR_0x8008, 2
	waitmovement 0
	closedoor 33, 34
	waitdooranim
	delay 5
	applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_TurnToPlayer2
	waitmovement 0
	msgbox TepekCity_Text_JudeWaitUpLetsGo, MSGBOX_NPC
	waitmessage
	goto TepekCity_EventScript_WalkToArea
	release
	end

TepekCity_EventScript_WalkToArea::
	call_if_eq VAR_0x8008, 0, TepekCity_EventScript_WalkToArea0
	call_if_eq VAR_0x8008, 1, TepekCity_EventScript_WalkToArea1
	call_if_eq VAR_0x8008, 2, TepekCity_EventScript_WalkToArea2

TepekCity_EventScript_WalkToArea0::
	applymovement LOCALID_PLAYER, TepekCity_Movement_TepekPlayerWalkToArea0
	applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_TepekRivalWalkToArea0
	waitmovement 0
	goto TepekCity_EventScript_JudeRivalBattle
	end

TepekCity_EventScript_WalkToArea1::
	applymovement LOCALID_PLAYER, TepekCity_Movement_TepekPlayerWalkToArea1
	applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_TepekRivalWalkToArea1
	waitmovement 0
	goto TepekCity_EventScript_JudeRivalBattle
	end

TepekCity_EventScript_WalkToArea2::
	applymovement LOCALID_PLAYER, TepekCity_Movement_TepekPlayerWalkToArea2
	applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_TepekRivalWalkToArea2
	waitmovement 0
	goto TepekCity_EventScript_JudeRivalBattle
	end

TepekCity_Movement_TurnToPlayer0:
	walk_in_place_left
	step_end

TepekCity_Movement_TurnToPlayer1:
	walk_in_place_down
	step_end

TepekCity_Movement_TurnToPlayer2:
	walk_in_place_right
	step_end

TepekCity_EventScript_JudeRivalBattle::
	delay 10
	msgbox TepekCity_Text_JudeLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, TepekCity_EventScript_StartJudeBattleSnivy
	case 1, TepekCity_EventScript_StartJudeBattleScorbunny
	case 2, TepekCity_EventScript_StartJudeBattleSquirtle

TepekCity_EventScript_StartJudeBattleSnivy::
	trainerbattle_no_intro TRAINER_JUDE_TEPEK_CITY_SNIVY, TepekCity_Text_JudeDefeated
	goto TepekCity_EventScript_AfterJudeBattle
	end

TepekCity_EventScript_StartJudeBattleScorbunny::
	trainerbattle_no_intro TRAINER_JUDE_TEPEK_CITY_SCORBUNNY, TepekCity_Text_JudeDefeated
	goto TepekCity_EventScript_AfterJudeBattle
	end

TepekCity_EventScript_StartJudeBattleSquirtle::
	trainerbattle_no_intro TRAINER_JUDE_TEPEK_CITY_SQUIRTLE, TepekCity_Text_JudeDefeated
	goto TepekCity_EventScript_AfterJudeBattle
	end

TepekCity_EventScript_AfterJudeBattle::
	applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_WalkToPlayer
	waitmovement
	msgbox TepekCity_Text_LetMeHealYou, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	fadescreen FADE_FROM_BLACK
	delay 10
	msgbox TepekCity_Text_JudeTimeToHeadBack, MSGBOX_DEFAULT
	closemessage
	goto TepekCity_EventScript_RivalExit
	end

TepekCity_Text_LetMeHealYou:
	.string "Jude: Here, let me heal your\n"
	.string "Pokémon!$"

TepekCity_Movement_WalkToPlayer:
	walk_left
	walk_left
	walk_left
	step_end

TepekCity_EventScript_RivalExit::
	applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_RivalLeave
	waitmovement 0
	setvar VAR_TEPEK_CITY_STATE, 3
	setvar VAR_CEDAR_LAB_STATE, 5
	clearflag FLAG_HIDE_FOLLOWER_MON
	callnative UpdateFollowingPokemon
	removeobject LOCALID_TEPEK_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

TepekCity_EventScript_NoGo::
	lockall
	applymovement LOCALID_TEPEK_FATMAN, Common_Movement_WalkInPlaceRight
	msgbox TepekCity_Text_FM_HeyKid
	waitmessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	msgbox TepekCity_Text_FM_NoGo
	waitmessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_TEPEK_FATMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

TepekCity_Movement_RivalLeave:
	walk_down
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

TepekCity_Movement_TepekPlayerWalkToArea0:
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

TepekCity_Movement_TepekRivalWalkToArea0:
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

TepekCity_Movement_TepekPlayerWalkToArea1:
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

TepekCity_Movement_TepekRivalWalkToArea1:
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

TepekCity_Movement_TepekPlayerWalkToArea2:
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

TepekCity_Movement_TepekRivalWalkToArea2:
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

TepekCity_Movement_TepekRivalExitDoor:
	walk_down
	delay_8
	step_end

TepekCity_EventScript_Boy1::
	lock
	faceplayer
	msgbox TepekCity_Text_LockedOut, MSGBOX_NPC
	applymovement LOCALID_LOCKEDBOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

TepekCity_EventScript_GameBoyKidLeft::
	lock
	faceplayer
	msgbox TepekCity_Text_GameBoyKidLeft, MSGBOX_NPC
	applymovement LOCALID_GBKIDL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end


TepekCity_EventScript_GameBoyKidRight::
	lock
	faceplayer
	msgbox TepekCity_Text_GameBoyKidRight, MSGBOX_NPC
	applymovement LOCALID_GBKIDR, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

TepekCity_EventScript_Boy2::
	lock
	faceplayer
	msgbox TepekCity_Text_Banners, MSGBOX_NPC
	release
	end

TepekCity_EventScript_ParkSign::
	msgbox TepekCity_Text_ParkSign, MSGBOX_SIGN
	end

TepekCity_EventScript_PowerPlantSign::
	msgbox TepekCity_Text_PowerPlantSign, MSGBOX_SIGN
	end

TepekCity_EventScript_ApartmentSign::
	msgbox TepekCity_Text_ApartmentSign, MSGBOX_SIGN
	end

TepekCity_EventScript_GymSign::
	msgbox TepekCity_Text_GymSign, MSGBOX_SIGN
	end

TepekCity_EventScript_CitySign::
	msgbox TepekCity_Text_CitySign, MSGBOX_SIGN
	end

// TepekCity_EventScript_Rival::
// lockall
// call_if_unset FLAG_MET_RIVAL_TEPEK, TepekCity_EventScript_PlayRivalMusic
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_FacePlayer
// waitmovement 0
// goto TepekCity_EventScript_RivalEncounter

TepekCity_EventScript_PlayRivalMusic::
	//checkplayergender
	//goto_if_eq VAR_RESULT, MALE, TepekCity_EventScript_PlayMayMusic
	//goto_if_eq VAR_RESULT, FEMALE, TepekCity_EventScript_PlayBrendanMusic
	end

// TepekCity_EventScript_PlayMayMusic::
// playbgm MUS_ENCOUNTER_MAY, TRUE
// return
// 
// TepekCity_EventScript_PlayBrendanMusic::
// playbgm MUS_ENCOUNTER_BRENDAN, TRUE
// return
// 
// TepekCity_EventScript_RivalTrigger0::
// lockall
// call TepekCity_EventScript_PlayRivalMusic
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_RivalApproachPlayer0
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto TepekCity_EventScript_RivalEncounter
// 
// TepekCity_EventScript_RivalTrigger1::
// lockall
// call TepekCity_EventScript_PlayRivalMusic
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_RivalApproachPlayer1
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto TepekCity_EventScript_RivalEncounter
// 
// TepekCity_EventScript_RivalTrigger2::
// lockall
// call TepekCity_EventScript_PlayRivalMusic
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_RivalApproachPlayer2
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto TepekCity_EventScript_RivalEncounter
// 
// TepekCity_EventScript_RivalTrigger3::
// lockall
// call TepekCity_EventScript_PlayRivalMusic
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_RivalApproachPlayer3
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto TepekCity_EventScript_RivalEncounter
// 
// TepekCity_EventScript_RivalTrigger4::
// lockall
// call TepekCity_EventScript_PlayRivalMusic
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_RivalApproachPlayer4
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto TepekCity_EventScript_RivalEncounter
// 
// TepekCity_EventScript_RivalTrigger5::
// lockall
// call TepekCity_EventScript_PlayRivalMusic
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_RivalApproachPlayer5
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto TepekCity_EventScript_RivalEncounter
// 
// TepekCity_EventScript_RivalTrigger6::
// lockall
// call TepekCity_EventScript_PlayRivalMusic
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_RivalApproachPlayer6
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto TepekCity_EventScript_RivalEncounter
// 
// TepekCity_EventScript_RivalTrigger7::
// lockall
// call TepekCity_EventScript_PlayRivalMusic
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_WalkInPlaceFasterDown
// waitmovement 0
// playse SE_PIN
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_ExclamationMark
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, Common_Movement_Delay48
// waitmovement 0
// applymovement LOCALID_TEPEK_RIVAL, TepekCity_Movement_RivalApproachPlayer7
// waitmovement 0
// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
// waitmovement 0
// goto TepekCity_EventScript_RivalEncounter
// 
// TepekCity_EventScript_RivalEncounter::
// checkplayergender
// goto_if_eq VAR_RESULT, MALE, TepekCity_EventScript_MayEncounter
// goto_if_eq VAR_RESULT, FEMALE, TepekCity_EventScript_BrendanEncounter
// end
// 
// TepekCity_EventScript_MayEncounter::
// goto_if_set FLAG_DEFEATED_RIVAL_TEPEK, TepekCity_EventScript_MayBrineyHint
// goto_if_set FLAG_MET_RIVAL_TEPEK, TepekCity_EventScript_MayAskToBattle
// setflag FLAG_MET_RIVAL_TEPEK
// msgbox TepekCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
// closemessage
// delay 30
// playfanfare MUS_REGISTER_MATCH_CALL
// msgbox TepekCity_Text_RegisteredMay, MSGBOX_DEFAULT
// waitfanfare
// closemessage
// delay 30
// setflag FLAG_ENABLE_RIVAL_MATCH_CALL
// setvar VAR_TEPEK_CITY_STATE, 8
// setvar VAR_ROUTE104_STATE, 2
// msgbox TepekCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
// goto_if_eq VAR_RESULT, YES, TepekCity_EventScript_BattleMay
// msgbox TepekCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
// call TepekCity_EventScript_RestoreBgm
// releaseall
// end
// 
// TepekCity_EventScript_MayAskToBattle::
// msgbox TepekCity_Text_MayWantToBattle, MSGBOX_YESNO
// goto_if_eq VAR_RESULT, YES, TepekCity_EventScript_BattleMay
// msgbox TepekCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
// releaseall
// end
// 
// TepekCity_EventScript_BattleMay::
// msgbox TepekCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
// switch VAR_STARTER_MON
// case 0, TepekCity_EventScript_BattleMayTreecko
// case 1, TepekCity_EventScript_BattleMayTorchic
// case 2, TepekCity_EventScript_BattleMayMudkip
// end
// 
// TepekCity_EventScript_MayBrineyHint::
// msgbox TepekCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
// releaseall
// end
// 
// TepekCity_EventScript_RestoreBgm::
// savebgm MUS_DUMMY
// fadedefaultbgm
// return
// 
// TepekCity_EventScript_BattleMayTreecko::
// trainerbattle_no_intro TRAINER_MAY_TEPEK_TREECKO, TepekCity_Text_MayDefeat
// setflag FLAG_DEFEATED_RIVAL_TEPEK
// goto TepekCity_EventScript_MayBrineyHint
// end
// 
// TepekCity_EventScript_BattleMayTorchic::
// trainerbattle_no_intro TRAINER_MAY_TEPEK_TORCHIC, TepekCity_Text_MayDefeat
// setflag FLAG_DEFEATED_RIVAL_TEPEK
// goto TepekCity_EventScript_MayBrineyHint
// end
// 
// TepekCity_EventScript_BattleMayMudkip::
// trainerbattle_no_intro TRAINER_MAY_TEPEK_MUDKIP, TepekCity_Text_MayDefeat
// setflag FLAG_DEFEATED_RIVAL_TEPEK
// goto TepekCity_EventScript_MayBrineyHint
// end
// 
// TepekCity_EventScript_BrendanEncounter::
// goto_if_set FLAG_DEFEATED_RIVAL_TEPEK, TepekCity_EventScript_BrendanBrineyHint
// goto_if_set FLAG_MET_RIVAL_TEPEK, TepekCity_EventScript_BrendanAskToBattle
// setflag FLAG_MET_RIVAL_TEPEK
// msgbox TepekCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
// closemessage
// delay 30
// playfanfare MUS_REGISTER_MATCH_CALL
// msgbox TepekCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
// waitfanfare
// closemessage
// delay 30
// setflag FLAG_ENABLE_RIVAL_MATCH_CALL
// setvar VAR_TEPEK_CITY_STATE, 8
// setvar VAR_ROUTE104_STATE, 2
// msgbox TepekCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
// goto_if_eq VAR_RESULT, YES, TepekCity_EventScript_BattleBrendan
// call TepekCity_EventScript_RestoreBgm
// releaseall
// end
// 
// TepekCity_EventScript_BrendanAskToBattle::
// msgbox TepekCity_Text_BrendanWantToBattle, MSGBOX_YESNO
// goto_if_eq VAR_RESULT, YES, TepekCity_EventScript_BattleBrendan
// releaseall
// end
// 
// TepekCity_EventScript_BattleBrendan::
// msgbox TepekCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
// switch VAR_STARTER_MON
// case 0, TepekCity_EventScript_BattleBrendanTreecko
// case 1, TepekCity_EventScript_BattleBrendanTorchic
// case 2, TepekCity_EventScript_BattleBrendanMudkip
// end
// 
// TepekCity_EventScript_BrendanBrineyHint::
// msgbox TepekCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
// releaseall
// end
// 
// TepekCity_EventScript_BattleBrendanTreecko::
// trainerbattle_no_intro TRAINER_BRENDAN_TEPEK_TREECKO, TepekCity_Text_BrendanDefeat
// setflag FLAG_DEFEATED_RIVAL_TEPEK
// goto TepekCity_EventScript_BrendanBrineyHint
// end
// 
// TepekCity_EventScript_BattleBrendanTorchic::
// trainerbattle_no_intro TRAINER_BRENDAN_TEPEK_TORCHIC, TepekCity_Text_BrendanDefeat
// setflag FLAG_DEFEATED_RIVAL_TEPEK
// goto TepekCity_EventScript_BrendanBrineyHint
// end
// 
// TepekCity_EventScript_BattleBrendanMudkip::
// trainerbattle_no_intro TRAINER_BRENDAN_TEPEK_MUDKIP, TepekCity_Text_BrendanDefeat
// setflag FLAG_DEFEATED_RIVAL_TEPEK
// goto TepekCity_EventScript_BrendanBrineyHint
// end

// TepekCity_Movement_RivalApproachPlayer0:
// walk_down
// walk_left
// walk_left
// walk_left
// walk_left
// walk_down
// step_end
// 
// TepekCity_Movement_RivalApproachPlayer1:
// walk_down
// walk_left
// walk_left
// walk_left
// walk_down
// step_end
// 
// TepekCity_Movement_RivalApproachPlayer2:
// walk_down
// walk_left
// walk_left
// walk_down
// step_end
// 
// TepekCity_Movement_RivalApproachPlayer3:
// walk_down
// walk_left
// walk_down
// step_end
// 
// TepekCity_Movement_RivalApproachPlayer4:
// walk_down
// walk_down
// step_end
// 
// TepekCity_Movement_RivalApproachPlayer5:
// walk_down
// walk_right
// walk_down
// step_end
// 
// TepekCity_Movement_RivalApproachPlayer6:
// walk_down
// walk_right
// walk_right
// walk_down
// step_end
// 
// TepekCity_Movement_RivalApproachPlayer7:
// walk_down
// walk_right
// walk_right
// walk_right
// walk_down
// step_end

TepekCity_Text_TepekGuidePowerBack:
	.string "The power is back! That means we\n"
	.string "can reopen the Gym!\p"
	.string "Let me get things turned back on.$"

TepekCity_Text_GymIsClosed:
	.string "Sorry, kid, the Gym is closed\n"
	.string "due to the blackouts.$"

TepekCity_Text_TypesStrongToFlying:
	.string "Do you know what types are strong\n"
	.string "against Flying-types?\p"
	.string "Electric-, Rock-, and Ice-types!$"

TepekCity_Text_CiellusUsesFlyingTypes:
	.string "Ciellus uses Flying-type Pokémon!\n"
	.string "Her father was a pilot, so it runs\l"
	.string "in the family.$"

TepekCity_Text_WelcomeToTepek:
	.string "Heya, welcome to Tepek City!$"

TepekCity_Text_JudeTimeToHeadBack:
	.string "Jude: You should probably go and\n"
	.string "tell Prof. Cedar you made the\l"
	.string "delivery, by the way.\p"
	.string "See you, {PLAYER}{KUN}!$"

TepekCity_Text_JudeDefeated:
	.string "Jude: That was fun! Thanks!$"

TepekCity_Text_JudeLetsBattle:
	.string "Jude: Alright, let's battle!$"

TepekCity_Text_JudeWaitUpLetsGo:
	.string "Jude: Wait up, {PLAYER}{KUN}!\p"
	.string "Let's go, I know where we can\n"
	.string "battle!$"

TepekCity_Text_SoMuchEnergy:
	.string "On nice days, I bring my son and\n"
	.string "his Pikachu to the park. They can\l"
	.string "run for hours!\p"
	.string "I wish I had that much energy!$"

TepekCity_Text_GonnaCatchYou:
	.string "I'm gonna catch you!$"

TepekCity_Text_ParkPikachu:
	.string "Zapper: Chuuu!$"

TepekCity_Text_Herdier:
	.string "Bessie: Rrrrruff!!$"

TepekCity_Text_RacingMySkwovet:
	.string "Me and my Skwovet are having\n"
	.string "a race!\p"
	.string "He's winning.$"

TepekCity_Text_ParkSkwovet:
	.string "Appi: Chchchcha!$"

TepekCity_Text_GameBoyKidLeft:
	.string "Me and my friend are trading\n"
	.string "our Pokémon!$"

TepekCity_Text_GameBoyKidRight:
	.string "This guy doesn't have very good\n"
	.string "trades…$"

TepekCity_Text_LockedOut:
	.string "I think I left my key inside\n"
	.string "when I locked the door…$"

TepekCity_Text_Banners:
	.string "Tepek City's streets are lined\n"
	.string "with banners! Aren't they super\p"
	.string "cool when they sway in the wind?$"

TepekCity_Text_SittingWithGirlfriend:
	.string "My girlfriend is smart. She gets\n"
	.string "the best discounts at the Mart!$"

TepekCity_Text_SittingWithBoyfriend:
	.string "My boyfriend doesn't know the\n"
	.string "difference between an Antidote\p"
	.string "and a Paralyze Heal. Here, I\n"
	.string "don't need this.$"

TepekCity_Text_HopefullyThatHelps:
	.string "Paralyze Heal cure Paralysis, while\n"
	.string "Antidotes cure Poison.$"

TepekCity_Text_ParkSign:
	.string "Tepek City Park\n"
	.string "Paid for by Sansuba Power Plant$"

TepekCity_Text_PowerPlantSign:
	.string "Sansuba Power Plant {RIGHT_ARROW}$"

TepekCity_Text_ApartmentSign:
	.string "Tepek City Apartments$"

TepekCity_Text_GymSign:
	.string "Tepek City Pokémon Gym\n"
	.string "Leader: Ciellus\p"
	.string "“Taking flight with Flying-types!”$"

TepekCity_Text_CitySign:
	.string "Tepek City\p"
	.string "“A city that soars above in\n"
	.string "excellence!”$"

TepekCity_Text_FM_HeyKid:
	.string "Hey, kid.$"

TepekCity_Text_FM_NoGo:
	.string "Something's up at the Power Plant.\p"
	.string "It isn't safe for a kid, so you\n"
	.string "better come back this way.$"
