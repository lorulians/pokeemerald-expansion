LittlerootTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_OnWarp
	.byte 0

	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
	@ 1: Met Rival
	@ 2: Saving Birch
	@ 3: Received Pokedex
	@ 4: Received Running Shoes

	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
	@ 1: In truck male
	@ 2: In truck female
	@ 3: Entered house
	@ 4: Told to go set clock
	@ 5: Entered 2F to set clock
	@ 6: Set clock
	@ 7: Told to go meet rival

	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
	@ 1: On Truck (and is corresponding gender)
	@ 2: Met Rival's Mom (and is corresponding gender)
	@ 3: Entered Hall of Fame
	@ 4: Completed Lati TV / SS Ticket event
	@ 5: Exited house after above event

	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
	@ 1: Never occurs
	@ 2: Entered Rival's bedroom
	@ 3: Met Rival
	@ 4: Received Pokedex


LittlerootTown_OnTransition:
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTeenPos
	call_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_SetTeenAtHousePos
	end

LittlerootTown_EventScript_SetTeenPos::
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_EventScript_SetTeenGuardingRoutePos
	setobjectxyperm LOCALID_LITTLEROOT_TEEN, 6, 16
	setobjectmovementtype LOCALID_LITTLEROOT_TEEN, MOVEMENT_TYPE_LOOK_AROUND
	return

LittlerootTown_EventScript_SetTeenGuardingRoutePos::
	setobjectxyperm LOCALID_LITTLEROOT_TEEN, 12, 17
	setobjectmovementtype LOCALID_LITTLEROOT_TEEN, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_EventScript_SetTeenAtHousePos::
	setobjectxyperm LOCALID_LITTLEROOT_TEEN, 6, 16
	setobjectmovementtype LOCALID_LITTLEROOT_TEEN, MOVEMENT_TYPE_LOOK_AROUND
	return

@ LittlerootTown_EventScript_SetMomStandingInFrontOfDoorPos::
	// clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	// setobjectmovementtype LOCALID_LITTLEROOT_MOM, MOVEMENT_TYPE_FACE_DOWN
	// return

LittlerootTown_OnFrame:
	// map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_BeginDexUpgradeScene
	.2byte 0

@ LittlerootTown_EventScript_BeginDexUpgradeScene::
	// lockall
	// playse SE_PIN
	// applymovement LOCALID_LITTLEROOT_BIRCH, Common_Movement_ExclamationMark
	// waitmovement 0
	// delay 80
	// msgbox LittlerootTown_Text_BirchSomethingToShowYouAtLab, MSGBOX_DEFAULT
	// closemessage
	// clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	// clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	// delay 20
	// clearflag FLAG_HIDE_MAP_NAME_POPUP
	// warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
	// waitstate
	// releaseall
	// end

LittlerootTown_OnWarp:
	// map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade
	.2byte 0

// LittlerootTown_EventScript_SetRivalBirchPosForDexUpgrade::
	// addobject LOCALID_LITTLEROOT_BIRCH
	// addobject LOCALID_LITTLEROOT_RIVAL
	// checkplayergender
	// goto_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale
	// goto LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale
	// end

// LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeMale::
	// setobjectxy LOCALID_LITTLEROOT_RIVAL, 6, 10
	// setobjectxy LOCALID_LITTLEROOT_BIRCH, 5, 10
	// end

// LittlerootTown_EventScript_SetRivalBirchPosForDexUpgradeFemale::
	// setobjectxy LOCALID_LITTLEROOT_RIVAL, 13, 10
	// setobjectxy LOCALID_LITTLEROOT_BIRCH, 14, 10
	// end

LittlerootTown_EventScript_FatMan::
	msgbox LittlerootTown_Text_MakeVideoGames, MSGBOX_NPC
	end

LittlerootTown_EventScript_OldWoman::
	msgbox LittlerootTown_Text_AdmiringScenery, MSGBOX_NPC
	end

LittlerootTown_EventScript_Sylveon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SYLVEON, CRY_MODE_WEAK
	msgbox LittlerootTown_Text_Sylveon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LittlerootTown_EventScript_Teen::
	lock
	faceplayer
	goto_if_ge VAR_LITTLEROOT_TOWN_STATE, 4, LittlerootTown_EventScript_GoSaveBirch
	msgbox LittlerootTown_Text_DontGoOutThere, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_GoSaveBirch::
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_DEFAULT
	closemessage
	release
	end

LittlerootTown_EventScript_YouSavedBirch::
	special GetPlayerBigGuyGirlString
	msgbox LittlerootTown_Text_YouSavedBirch, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_GoodLuck::
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_EventScript_NeedPokemonTriggerLeft::
	lockall
	applymovement LOCALID_LITTLEROOT_TEEN, LittlerootTown_Movement_TeenApproachPlayerLeft
	waitmovement 0
	call LittlerootTown_EventScript_DangerousWithoutPokemon
	applymovement LOCALID_LITTLEROOT_TEEN, LittlerootTown_Movement_TeenReturnLeft
	waitmovement 0
	releaseall
	end

LittlerootTown_EventScript_DangerousWithoutPokemon::
	msgbox LittlerootTown_Text_DontGoOutThere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LITTLEROOT_TEEN, LittlerootTown_Movement_TeenPushPlayerFromRoute
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
	waitmovement 0
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_Movement_TeenApproachPlayerRight:
	face_left
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_left
	delay_8
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_right
	face_up
	step_end

LittlerootTown_Movement_TeenPushPlayerFromRoute:
	walk_up
	step_end

LittlerootTown_Movement_TeenReturnRight:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_down
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_PushPlayerBackFromRoute:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

LittlerootTown_EventScript_NeedPokemonTriggerRight::
	lockall
	applymovement LOCALID_LITTLEROOT_TEEN, LittlerootTown_Movement_TeenApproachPlayerRight
	waitmovement 0
	call LittlerootTown_EventScript_DangerousWithoutPokemon
	applymovement LOCALID_LITTLEROOT_TEEN, LittlerootTown_Movement_TeenReturnRight
	waitmovement 0
	releaseall
	end

LittlerootTown_Movement_TeenApproachPlayerLeft:
	face_left
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_left
	delay_8
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	face_up
	step_end

LittlerootTown_Movement_TeenReturnLeft:
	walk_right
	walk_up
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_EventScript_TownSign::
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BirchsLabSign::
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BrendansHouseSign::
	lockall
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger0::
	lockall
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_LITTLEROOT_MOM, 9, 9
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger1::
	lockall
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_LITTLEROOT_MOM, 9, 9
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger2::
	lockall
	setvar VAR_0x8008, 2
	setobjectxy LOCALID_LITTLEROOT_MOM, 9, 9
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger::
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
	closemessage
	call LittlerootTown_EventScript_MomApproachPlayer
	call LittlerootTown_EventScript_GiveRunningShoes
	call LittlerootTown_EventScript_MomReturnHome
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
	end

LittlerootTown_EventScript_MomApproachPlayer::
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomApproachPlayer2
	return

LittlerootTown_EventScript_MomApproachPlayer0::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer0
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayer1::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer1
	waitmovement 0
	return

LittlerootTown_EventScript_MomApproachPlayer2::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomApproachPlayer2
	waitmovement 0
	return

LittlerootTown_EventScript_MomReturnHome::
	call_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_MomReturnHome0
	call_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_MomReturnHome1
	call_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_MomReturnHome2
	return

LittlerootTown_EventScript_MomReturnHome0::
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome0
	waitmovement 0
	setflag FLAG_RESCUED_BIRCH
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

LittlerootTown_EventScript_MomReturnHome1::
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome1
	waitmovement 0
	setflag FLAG_RESCUED_BIRCH
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return


LittlerootTown_EventScript_MomReturnHome2::
	applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomReturnHome2
	waitmovement 0
	setflag FLAG_RESCUED_BIRCH
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

LittlerootTown_Movement_MomApproachPlayer0:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayer1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomApproachPlayer2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_MomReturnHome0:
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
	set_invisible
	step_end

LittlerootTown_Movement_MomReturnHome1:
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
	walk_up
	set_invisible
	step_end

LittlerootTown_Movement_MomReturnHome2:
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
	walk_up
	walk_up
	set_invisible
	step_end

LittlerootTown_EventScript_Mom::
	lock
	faceplayer
	call LittlerootTown_EventScript_GiveRunningShoes
	// applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	// applymovement LOCALID_LITTLEROOT_MOM, LittlerootTown_Movement_MomExitThroughDoor
	waitmovement 0
	// hideobjectat LOCALID_LITTLEROOT_MOM, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	goto LittlerootTown_EventScript_SetReceivedRunningShoes
	end

LittlerootTown_EventScript_SetReceivedRunningShoes::
	removeobject LOCALID_LITTLEROOT_MOM
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	release
	end

LittlerootTown_EventScript_GiveRunningShoes::
	msgbox LittlerootTown_Text_DidYouSeeCedar, MSGBOX_DEFAULT
	waitmessage
	goto_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_StarterMovement0
	goto_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_StarterMovement1
	goto_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_StarterMovement2
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

LittlerootTown_EventScript_StarterMovement0::
	applymovement LOCALID_FOLLOWING_POKEMON, LittlerootTown_Movement_StarterApproachMom0
	waitmovement
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_FaceDown
	waitmovement
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_EventScript_StarterCry
	special ChoosePartyMon
    waitstate
	msgbox LittlerootTown_Text_CutePokemon, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_FaceRight
	waitmovement
	applymovement LOCALID_FOLLOWING_POKEMON, LittlerootTown_Movement_StarterReturnToPlayer0
	waitmovement
	return

LittlerootTown_EventScript_StarterMovement1::
	applymovement LOCALID_FOLLOWING_POKEMON, LittlerootTown_Movement_StarterApproachMom1
	waitmovement
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_FaceUp
	waitmovement
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_EventScript_StarterCry
	special ChoosePartyMon
    waitstate
	msgbox LittlerootTown_Text_CutePokemon, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_FaceRight
	waitmovement
	applymovement LOCALID_FOLLOWING_POKEMON, LittlerootTown_Movement_StarterReturnToPlayer1
	waitmovement
	return

LittlerootTown_EventScript_StarterMovement2::
	applymovement LOCALID_FOLLOWING_POKEMON, LittlerootTown_Movement_StarterApproachMom2
	waitmovement
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_FaceUp
	waitmovement
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_EventScript_StarterCry
	special ChoosePartyMon
    waitstate
	msgbox LittlerootTown_Text_CutePokemon, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_FaceRight
	waitmovement
	applymovement LOCALID_FOLLOWING_POKEMON, LittlerootTown_Movement_StarterReturnToPlayer2
	waitmovement
	return

LittlerootTown_EventScript_StarterCry::
	call_if_eq VAR_STARTER_MON, 0, LittlerootTown_EventScript_SnivyCry
	call_if_eq VAR_STARTER_MON, 1, LittlerootTown_EventScript_ScorbunnyCry
	call_if_eq VAR_STARTER_MON, 2, LittlerootTown_EventScript_SquirtleCry
	return

LittlerootTown_EventScript_SnivyCry::
	waitse
	playmoncry SPECIES_SNIVY, CRY_MODE_NORMAL
	return

LittlerootTown_EventScript_ScorbunnyCry::
	waitse
	playmoncry SPECIES_SCORBUNNY, CRY_MODE_NORMAL
	return

LittlerootTown_EventScript_SquirtleCry::
	waitse
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_NORMAL
	return

LittlerootTown_Movement_StarterApproachMom0:
	jump_in_place_left
	delay_8
	walk_fast_down
	walk_fast_left
	walk_fast_left
	jump_in_place_up
	jump_in_place_up
	step_end

LittlerootTown_Movement_StarterApproachMom1:
	jump_in_place_left
	delay_8
	walk_fast_up
	walk_fast_left
	walk_fast_left
	jump_in_place_down
	jump_in_place_down
	step_end

LittlerootTown_Movement_StarterApproachMom2:
	jump_in_place_left
	delay_8
	walk_fast_up
	walk_fast_left
	walk_fast_left
	jump_in_place_down
	jump_in_place_down
	step_end

LittlerootTown_Movement_StarterReturnToPlayer0:
	walk_fast_right
	walk_fast_right
	walk_fast_up
	face_left
	step_end

LittlerootTown_Movement_StarterReturnToPlayer1:
	walk_fast_right
	walk_fast_right
	walk_fast_down
	face_left
	step_end

LittlerootTown_Movement_StarterReturnToPlayer2:
	walk_fast_right
	walk_fast_right
	walk_fast_down
	face_left
	step_end

LittlerootTown_Text_Sylveon:
	.string "SILLY: Zzz… zzz…$"

LittlerootTown_Text_OurNewHomeLetsGoInside:
	.string "MOM: {PLAYER}, we're here, honey!\p"
	.string "It must be tiring riding with our things\n"
	.string "in the moving truck.\p"
	.string "Well, this is LITTLEROOT TOWN.\p"
	.string "How do you like it?\n"
	.string "This is our new home!\p"
	.string "It has a quaint feel, but it seems to be\n"
	.string "an easy place to live, don't you think?\p"
	.string "And, you get your own room, {PLAYER}!\n"
	.string "Let's go inside.$"

LittlerootTown_Text_WaitPlayer:
	.string "MOM: Wait, {PLAYER}!$"

LittlerootTown_Text_DidYouSeeCedar:
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
	.string "see what PROF. CEDAR had to say?$"

LittlerootTown_Text_CutePokemon:
	.string "MOM: Oh, what a cute POKéMON!\n"
	.string "Oh, PROF. CEDAR gave it to you?\p"
	.string "Well, {CHOSEN_MON_NAME} is adorable!$"

LittlerootTown_Text_WearTheseRunningShoes:
	.string "MOM: What's wrong honey?\p"
	.string "…He wants you to deliver something to\n"
	.string "TEPEK CITY? Alright, honey, be careful.\p"
	.string "I know! Here If you're going out on an\n"
	.string "adventure, wear these RUNNING SHOES.\p"
	.string "They'll put a zip in your step!$"

LittlerootTown_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

LittlerootTown_Text_ExplainRunningShoes:
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "RUNNING SHOES to run extra-fast!\p"
	.string "“Slip on these RUNNING SHOES and race\n"
	.string "around like a wild ZEBSTRIKA!”$"

LittlerootTown_Text_ComeHomeIfAnythingHappens:
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "POKéMON now…\l"
	.string "I'm proud of you, {PLAYER}.\p"
	.string "…But please be careful.\n"
	.string "You can always come home if you need.\p"
	.string "Go on, go get them, honey!$"

LittlerootTown_Text_MakeVideoGames:
	.string "It's easier than ever these days to\n"
	.string "make your own video games!\p"
	.string "The power of science is astounding!$"

LittlerootTown_Text_AdmiringScenery:
	.string "Sometimes, it's good to slow down and\n"
	.string "admire the scenery.$"

LittlerootTown_Text_DontGoOutThere:
	.string "Wait up, kid, don't go out there.$"

LittlerootTown_Text_DangerousIfYouDontHavePokemon:
	.string "I know you don't have your own POKéMON\n"
	.string "yet, so I can't let you go. It's\l"
	.string "reckless to go out without at least one.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening:
	.string "Hey, {PLAYER}{KUN}! Nice POKéMON!$"

LittlerootTown_Text_YouSavedBirch:
	.string "You saved PROF. BIRCH!\n"
	.string "I'm so glad!$"

LittlerootTown_Text_GoodLuckCatchingPokemon:
	.string "Are you heading out?\n"
	.string "Good luck!$"

LittlerootTown_Text_TownSign:
	.string "REDGE TOWN\n"
	.string "“A quiet town for quiet people.”$"

LittlerootTown_Text_ProfBirchsLab:
	.string "PROF. BIRCH'S POKéMON LAB$"

LittlerootTown_Text_PlayersHouse:
	.string "{PLAYER}'s HOUSE$"

LittlerootTown_Text_RivalsHouse:
	.string "PROF. BIRCH'S HOUSE$"

LittlerootTown_Text_BirchSomethingToShowYouAtLab:
	.string "PROF. BIRCH: Well, well, {PLAYER}{KUN}!\n"
	.string "That was good work out there!\p"
	.string "I knew there was something special\n"
	.string "about you when I first saw you,\l"
	.string "but I never expected this.\p"
	.string "Oh, yes. Do you still have the POKéDEX\n"
	.string "I gave you?\p"
	.string "I have something to show you.\n"
	.string "Let's go to my LAB.$"

