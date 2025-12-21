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
	msgbox LittlerootTown_Text_Sylveon, MSGBOX_NPC
	waitmoncry
	release
	end

LittlerootTown_EventScript_Teen::
	lock
	faceplayer
	goto_if_ge VAR_LITTLEROOT_TOWN_STATE, 4, LittlerootTown_EventScript_GoSaveBirch
	msgbox LittlerootTown_Text_DontGoOutThere, MSGBOX_NPC
	release
	end

LittlerootTown_EventScript_GoSaveBirch::
	msgbox LittlerootTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_NPC
	closemessage
	release
	end

LittlerootTown_EventScript_GoodLuck::
	msgbox LittlerootTown_Text_GoodLuckCatchingPokemon, MSGBOX_NPC
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
	msgbox LittlerootTown_Text_DontGoOutThere, MSGBOX_NPC
	closemessage
	applymovement LOCALID_LITTLEROOT_TEEN, LittlerootTown_Movement_TeenPushPlayerFromRoute
	applymovement LOCALID_PLAYER, LittlerootTown_Movement_PushPlayerBackFromRoute
	waitmovement 0
	msgbox LittlerootTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_NPC
	closemessage
	return

LittlerootTown_EventScript_NeedPokemonTriggerRight::
	lockall
	applymovement LOCALID_LITTLEROOT_TEEN, LittlerootTown_Movement_TeenApproachPlayerRight
	waitmovement 0
	call LittlerootTown_EventScript_DangerousWithoutPokemon
	applymovement LOCALID_LITTLEROOT_TEEN, LittlerootTown_Movement_TeenReturnRight
	waitmovement 0
	releaseall
	end

LittlerootTown_EventScript_TownSign::
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BirchsLabSign::
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BrendansHouseSign::
	lockall
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_SIGN
	releaseall
	end

LittlerootTown_EventScript_GiveNavTrigger0::
	lockall
	addobject LOCALID_LITTLEROOT_MOM
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_LITTLEROOT_MOM, 9, 9
	goto LittlerootTown_EventScript_GiveNavTrigger
	end

LittlerootTown_EventScript_GiveNavTrigger1::
	lockall
	addobject LOCALID_LITTLEROOT_MOM
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_LITTLEROOT_MOM, 9, 10
	goto LittlerootTown_EventScript_GiveNavTrigger
	end

LittlerootTown_EventScript_GiveNavTrigger2::
	lockall
	addobject LOCALID_LITTLEROOT_MOM
	setvar VAR_0x8008, 2
	setobjectxy LOCALID_LITTLEROOT_MOM, 9, 11
	goto LittlerootTown_EventScript_GiveNavTrigger
	end

LittlerootTown_EventScript_GiveNavTrigger::
	msgbox LittlerootTown_Text_HoldUpPlayer, MSGBOX_DEFAULT
	closemessage
	call LittlerootTown_EventScript_MomApproachPlayer
	call LittlerootTown_EventScript_OneMoreThingForYou
	call LittlerootTown_EventScript_MomReturnHome
	goto LittlerootTown_EventScript_SetReceivedRunningShoes

LittlerootTown_EventScript_OneMoreThingForYou::
	msgbox LittlerootTown_Text_OutOfBreath, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox LittlerootTown_Text_OneMoreThingForYou, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_HAS_MATCH_CALL
	msgbox LittlerootTown_Text_ExplainPokenav, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox PlayersHouse_1F_Text_RegisteredMom, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	msgbox LittlerootTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ENABLE_MOM_MATCH_CALL
	return

LittlerootTown_EventScript_GiveRunningShoesTrigger0::
	lockall
	addobject LOCALID_LITTLEROOT_MOM
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_LITTLEROOT_MOM, 9, 9
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger1::
	lockall
	addobject LOCALID_LITTLEROOT_MOM
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_LITTLEROOT_MOM, 9, 10
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger2::
	lockall
	addobject LOCALID_LITTLEROOT_MOM
	setvar VAR_0x8008, 2
	setobjectxy LOCALID_LITTLEROOT_MOM, 9, 11
	goto LittlerootTown_EventScript_GiveRunningShoesTrigger
	end

LittlerootTown_EventScript_GiveRunningShoesTrigger::
	msgbox LittlerootTown_Text_WaitPlayer, MSGBOX_DEFAULT
	closemessage
	call LittlerootTown_EventScript_MomApproachPlayer
	call LittlerootTown_EventScript_DidYouSeeCedar
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
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	release
	end

LittlerootTown_EventScript_DidYouSeeCedar::
	msgbox LittlerootTown_Text_DidYouSeeCedar, MSGBOX_DEFAULT
	waitmessage
	goto_if_eq VAR_0x8008, 0, LittlerootTown_EventScript_StarterMovement0
	goto_if_eq VAR_0x8008, 1, LittlerootTown_EventScript_StarterMovement1
	goto_if_eq VAR_0x8008, 2, LittlerootTown_EventScript_StarterMovement2


LittlerootTown_EventScript_GiveRunningShoes::
	msgbox LittlerootTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	msgbox LittlerootTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	msgbox LittlerootTown_Text_StaySafeHoney, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

LittlerootTown_Text_StaySafeHoney:
	.string "Mom: Stay safe, honey. If your\n"
	.string "Pokemon need healing, you can\p"
	.string "come home and rest up.$"

LittlerootTown_EventScript_StarterMovement0::
	applymovement LOCALID_FOLLOWING_POKEMON, LittlerootTown_Movement_StarterApproachMom0
	waitmovement
	delay 5
	call_if_eq VAR_STARTER_MON, 0, LittlerootTown_EventScript_SnivyCry
	call_if_eq VAR_STARTER_MON, 1, LittlerootTown_EventScript_ScorbunnyCry
	call_if_eq VAR_STARTER_MON, 2, LittlerootTown_EventScript_SquirtleCry
	delay 48
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_FaceDown
	waitmovement
	msgbox LittlerootTown_Text_CutePokemon, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_FaceRight
	waitmovement
	applymovement LOCALID_FOLLOWING_POKEMON, LittlerootTown_Movement_StarterReturnToPlayer0
	waitmovement
	goto LittlerootTown_EventScript_GiveRunningShoes

LittlerootTown_EventScript_StarterMovement1::
	applymovement LOCALID_FOLLOWING_POKEMON, LittlerootTown_Movement_StarterApproachMom1
	waitmovement
	delay 5
	call_if_eq VAR_STARTER_MON, 0, LittlerootTown_EventScript_SnivyCry
	call_if_eq VAR_STARTER_MON, 1, LittlerootTown_EventScript_ScorbunnyCry
	call_if_eq VAR_STARTER_MON, 2, LittlerootTown_EventScript_SquirtleCry
	delay 48
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_FaceUp
	waitmovement
	msgbox LittlerootTown_Text_CutePokemon, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_FaceRight
	waitmovement
	applymovement LOCALID_FOLLOWING_POKEMON, LittlerootTown_Movement_StarterReturnToPlayer1
	waitmovement
	goto LittlerootTown_EventScript_GiveRunningShoes

LittlerootTown_EventScript_StarterMovement2::
	applymovement LOCALID_FOLLOWING_POKEMON, LittlerootTown_Movement_StarterApproachMom2
	waitmovement
	delay 5
	call_if_eq VAR_STARTER_MON, 0, LittlerootTown_EventScript_SnivyCry
	call_if_eq VAR_STARTER_MON, 1, LittlerootTown_EventScript_ScorbunnyCry
	call_if_eq VAR_STARTER_MON, 2, LittlerootTown_EventScript_SquirtleCry
	delay 48
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_FaceUp
	waitmovement
	msgbox LittlerootTown_Text_CutePokemon, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_LITTLEROOT_MOM, Common_Movement_FaceRight
	waitmovement
	applymovement LOCALID_FOLLOWING_POKEMON, LittlerootTown_Movement_StarterReturnToPlayer2
	waitmovement
	goto LittlerootTown_EventScript_GiveRunningShoes

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

LittlerootTown_Text_ExplainPokenav:
	.string "Mom: Isn't it neat? You can use it\n"
	.string "to view your map easily!\p"
	.string "I'll even add my number so you can\n"
	.string "call me without having to use a\l"
	.string "payphone!$"

LittlerootTown_Text_ReceivedPokenav:
	.string "{PLAYER} received a PokéNav.$"

LittlerootTown_Text_OutOfBreath:
	.string "Mom: Huff, huff… I need to dig those\n"
	.string "exercise DVDs out of the attic… Huff…$"

LittlerootTown_Text_OneMoreThingForYou:
	.string "Mom: I've got one more thing for\n"
	.string "you to take on your journey.\p"
	.string "It's a brand new PokéNav!$"

LittlerootTown_Text_HoldUpPlayer:
	.string "Mom: Hold on, {PLAYER}!$"

LittlerootTown_Text_Sylveon:
	.string "Silly: Zzz… zzz…$"

LittlerootTown_Text_WaitPlayer:
	.string "Mom: Wait, {PLAYER}!$"

LittlerootTown_Text_DidYouSeeCedar:
	.string "Mom: {PLAYER}! {PLAYER}! Did you see what\n"
	.string "Prof. Cedar had to say?$"

LittlerootTown_Text_CutePokemon:
	.string "Mom: Oh, what a cute Pokémon!\n"
	.string "Oh, Prof. Cedar gave it to you?\p"
	.string "Well, it's adorable!$"

LittlerootTown_Text_WearTheseRunningShoes:
	.string "Mom: What's wrong honey?\p"
	.string "…He wants you to deliver something to\n"
	.string "Tepek City? Alright, honey, be careful.\p"
	.string "I know! Here If you're going out on an\n"
	.string "adventure, wear these running shoes.\p"
	.string "They'll put a zip in your step!$"

LittlerootTown_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER} switched shoes with the\n"
	.string "running shoes.$"

LittlerootTown_Text_ExplainRunningShoes:
	.string "Mom: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "running shoes to run extra-fast!\p"
	.string "“Slip on these running shoes and race\n"
	.string "around like a wild Zebstrika!”$"

LittlerootTown_Text_ComeHomeIfAnythingHappens:
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "Pokémon now…\l"
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
	.string "I know you don't have your own Pokémon\n"
	.string "yet, so I can't let you go. It's\l"
	.string "reckless to go out without at least one.$"

LittlerootTown_Text_CanYouGoSeeWhatsHappening:
	.string "Hey, {PLAYER}{KUN}! Nice Pokémon!$"

LittlerootTown_Text_GoodLuckCatchingPokemon:
	.string "Are you heading out?\n"
	.string "Good luck!$"

LittlerootTown_Text_TownSign:
	.string "Redge Town\n"
	.string "“A quiet town for quiet people.”$"

LittlerootTown_Text_ProfBirchsLab:
	.string "Prof. Cedar'S Pokémon Lab$"

LittlerootTown_Text_PlayersHouse:
	.string "{PLAYER}'s House$"

LittlerootTown_Movement_StarterApproachMom0:
	disable_jump_landing_ground_effect
	jump_in_place_left
	delay_8
	walk_fast_down
	walk_fast_left
	walk_fast_left
	disable_jump_landing_ground_effect
	jump_in_place_up
	disable_jump_landing_ground_effect
	jump_in_place_up
	step_end

LittlerootTown_Movement_StarterApproachMom1:
	disable_jump_landing_ground_effect
	jump_in_place_left
	delay_8
	walk_fast_up
	walk_fast_left
	walk_fast_left
	disable_jump_landing_ground_effect
	jump_in_place_down
	disable_jump_landing_ground_effect
	jump_in_place_down
	step_end

LittlerootTown_Movement_StarterApproachMom2:
	disable_jump_landing_ground_effect
	jump_in_place_left
	delay_8
	walk_fast_up
	walk_fast_left
	walk_fast_left
	disable_jump_landing_ground_effect
	jump_in_place_down
	disable_jump_landing_ground_effect
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
