RedgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RedgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RedgeTown_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RedgeTown_OnWarp
	.byte 0

	@ State descriptions for VAR_REDGE_TOWN_STATE
	@ 1: Met Rival
	@ 2: Saving Cedar
	@ 3: Received Pokedex
	@ 4: Received Running Shoes

	@ State descriptions for VAR_REDGE_INTRO_STATE
	@ 1: In truck male
	@ 2: In truck female
	@ 3: Entered house
	@ 4: Told to go set clock
	@ 5: Entered 2F to set clock
	@ 6: Set clock
	@ 7: Told to go meet rival

	@ State descriptions for VAR_REDGE_HOUSES_STATE_MAY
	@                    and VAR_REDGE_HOUSES_STATE_BRENDAN
	@ 1: On Truck (and is corresponding gender)
	@ 2: Met Rival's Mom (and is corresponding gender)
	@ 3: Entered Hall of Fame
	@ 4: Completed Lati TV / SS Ticket event
	@ 5: Exited house after above event

	@ State descriptions for VAR_REDGE_RIVAL_STATE
	@ 1: Never occurs
	@ 2: Entered Rival's bedroom
	@ 3: Met Rival
	@ 4: Received Pokedex


RedgeTown_OnTransition:
	call_if_unset FLAG_SYS_POKEMON_GET, RedgeTown_EventScript_SetTeenPos
	call_if_set FLAG_SYS_POKEMON_GET, RedgeTown_EventScript_SetTeenAtHousePos
	end

RedgeTown_EventScript_SetTeenPos::
	goto_if_eq VAR_REDGE_TOWN_STATE, 0, RedgeTown_EventScript_SetTeenGuardingRoutePos
	setobjectxyperm LOCALID_REDGE_TEEN, 6, 16
	setobjectmovementtype LOCALID_REDGE_TEEN, MOVEMENT_TYPE_LOOK_AROUND
	return

RedgeTown_EventScript_SetTeenGuardingRoutePos::
	setobjectxyperm LOCALID_REDGE_TEEN, 12, 17
	setobjectmovementtype LOCALID_REDGE_TEEN, MOVEMENT_TYPE_FACE_UP
	return

RedgeTown_EventScript_SetTeenAtHousePos::
	setobjectxyperm LOCALID_REDGE_TEEN, 6, 16
	setobjectmovementtype LOCALID_REDGE_TEEN, MOVEMENT_TYPE_LOOK_AROUND
	return

@ RedgeTown_EventScript_SetMomStandingInFrontOfDoorPos::
	// clearflag FLAG_HIDE_REDGE_TOWN_MOM_OUTSIDE
	// setobjectmovementtype LOCALID_REDGE_MOM, MOVEMENT_TYPE_FACE_DOWN
	// return

RedgeTown_OnFrame:
	// map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, RedgeTown_EventScript_BeginDexUpgradeScene
	.2byte 0

@ RedgeTown_EventScript_BeginDexUpgradeScene::
	// lockall
	// playse SE_PIN
	// applymovement LOCALID_REDGE_CEDAR, Common_Movement_ExclamationMark
	// waitmovement 0
	// delay 80
	// msgbox RedgeTown_Text_CedarSomethingToShowYouAtLab, MSGBOX_DEFAULT
	// closemessage
	// clearflag FLAG_HIDE_REDGE_TOWN_RIVAL
	// clearflag FLAG_HIDE_REDGE_TOWN_CEDAR
	// delay 20
	// clearflag FLAG_HIDE_MAP_NAME_POPUP
	// warp MAP_REDGE_TOWN_PROFESSOR_CEDARS_LAB, 6, 5
	// waitstate
	// releaseall
	// end

RedgeTown_OnWarp:
	// map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, RedgeTown_EventScript_SetRivalCedarPosForDexUpgrade
	.2byte 0

// RedgeTown_EventScript_SetRivalCedarPosForDexUpgrade::
	// addobject LOCALID_REDGE_CEDAR
	// addobject LOCALID_REDGE_RIVAL
	// checkplayergender
	// goto_if_eq VAR_RESULT, MALE, RedgeTown_EventScript_SetRivalCedarPosForDexUpgradeMale
	// goto RedgeTown_EventScript_SetRivalCedarPosForDexUpgradeFemale
	// end

// RedgeTown_EventScript_SetRivalCedarPosForDexUpgradeMale::
	// setobjectxy LOCALID_REDGE_RIVAL, 6, 10
	// setobjectxy LOCALID_REDGE_CEDAR, 5, 10
	// end

// RedgeTown_EventScript_SetRivalCedarPosForDexUpgradeFemale::
	// setobjectxy LOCALID_REDGE_RIVAL, 13, 10
	// setobjectxy LOCALID_REDGE_CEDAR, 14, 10
	// end

RedgeTown_EventScript_FatMan::
	msgbox RedgeTown_Text_MakeVideoGames, MSGBOX_NPC
	end

RedgeTown_EventScript_OldWoman::
	msgbox RedgeTown_Text_AdmiringScenery, MSGBOX_NPC
	end

RedgeTown_EventScript_Sylveon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SYLVEON, CRY_MODE_WEAK
	msgbox RedgeTown_Text_Sylveon, MSGBOX_NPC
	waitmoncry
	release
	end

RedgeTown_EventScript_Teen::
	lock
	faceplayer
	goto_if_ge VAR_REDGE_TOWN_STATE, 4, RedgeTown_EventScript_GoSaveCedar
	msgbox RedgeTown_Text_DontGoOutThere, MSGBOX_NPC
	release
	end

RedgeTown_EventScript_GoSaveCedar::
	msgbox RedgeTown_Text_CanYouGoSeeWhatsHappening, MSGBOX_NPC
	closemessage
	release
	end

RedgeTown_EventScript_GoodLuck::
	msgbox RedgeTown_Text_GoodLuckCatchingPokemon, MSGBOX_NPC
	release
	end

RedgeTown_EventScript_NeedPokemonTriggerLeft::
	lockall
	applymovement LOCALID_REDGE_TEEN, RedgeTown_Movement_TeenApproachPlayerLeft
	waitmovement 0
	call RedgeTown_EventScript_DangerousWithoutPokemon
	applymovement LOCALID_REDGE_TEEN, RedgeTown_Movement_TeenReturnLeft
	waitmovement 0
	releaseall
	end

RedgeTown_EventScript_DangerousWithoutPokemon::
	msgbox RedgeTown_Text_DontGoOutThere, MSGBOX_NPC
	closemessage
	applymovement LOCALID_REDGE_TEEN, RedgeTown_Movement_TeenPushPlayerFromRoute
	applymovement LOCALID_PLAYER, RedgeTown_Movement_PushPlayerBackFromRoute
	waitmovement 0
	msgbox RedgeTown_Text_DangerousIfYouDontHavePokemon, MSGBOX_NPC
	closemessage
	return

RedgeTown_EventScript_NeedPokemonTriggerRight::
	lockall
	applymovement LOCALID_REDGE_TEEN, RedgeTown_Movement_TeenApproachPlayerRight
	waitmovement 0
	call RedgeTown_EventScript_DangerousWithoutPokemon
	applymovement LOCALID_REDGE_TEEN, RedgeTown_Movement_TeenReturnRight
	waitmovement 0
	releaseall
	end

RedgeTown_EventScript_TownSign::
	msgbox RedgeTown_Text_TownSign, MSGBOX_SIGN
	end

RedgeTown_EventScript_CedarsLabSign::
	msgbox RedgeTown_Text_ProfCedarsLab, MSGBOX_SIGN
	end

RedgeTown_EventScript_PlayersHouseSign::
	lockall
	msgbox RedgeTown_Text_PlayersHouse, MSGBOX_SIGN
	releaseall
	end

RedgeTown_EventScript_GiveNavTrigger0::
	lockall
	addobject LOCALID_REDGE_MOM
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_REDGE_MOM, 9, 9
	goto RedgeTown_EventScript_GiveNavTrigger
	end

RedgeTown_EventScript_GiveNavTrigger1::
	lockall
	addobject LOCALID_REDGE_MOM
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_REDGE_MOM, 9, 10
	goto RedgeTown_EventScript_GiveNavTrigger
	end

RedgeTown_EventScript_GiveNavTrigger2::
	lockall
	addobject LOCALID_REDGE_MOM
	setvar VAR_0x8008, 2
	setobjectxy LOCALID_REDGE_MOM, 9, 11
	goto RedgeTown_EventScript_GiveNavTrigger
	end

RedgeTown_EventScript_GiveNavTrigger::
	msgbox RedgeTown_Text_HoldUpPlayer, MSGBOX_DEFAULT
	closemessage
	call RedgeTown_EventScript_MomApproachPlayer
	call RedgeTown_EventScript_OneMoreThingForYou
	call RedgeTown_EventScript_MomReturnHome
	goto RedgeTown_EventScript_SetReceivedRunningShoes

RedgeTown_EventScript_OneMoreThingForYou::
	msgbox RedgeTown_Text_OutOfBreath, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_REDGE_MOM, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox RedgeTown_Text_OneMoreThingForYou, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RedgeTown_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_HAS_MATCH_CALL
	msgbox RedgeTown_Text_ExplainPokenav, MSGBOX_DEFAULT
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox PlayersHouse_1F_Text_RegisteredMom, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	msgbox RedgeTown_Text_ComeHomeIfAnythingHappens, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ENABLE_MOM_MATCH_CALL
	return

RedgeTown_EventScript_GiveRunningShoesTrigger0::
	lockall
	addobject LOCALID_REDGE_MOM
	setvar VAR_0x8008, 0
	setobjectxy LOCALID_REDGE_MOM, 9, 9
	goto RedgeTown_EventScript_GiveRunningShoesTrigger
	end

RedgeTown_EventScript_GiveRunningShoesTrigger1::
	lockall
	addobject LOCALID_REDGE_MOM
	setvar VAR_0x8008, 1
	setobjectxy LOCALID_REDGE_MOM, 9, 10
	goto RedgeTown_EventScript_GiveRunningShoesTrigger
	end

RedgeTown_EventScript_GiveRunningShoesTrigger2::
	lockall
	addobject LOCALID_REDGE_MOM
	setvar VAR_0x8008, 2
	setobjectxy LOCALID_REDGE_MOM, 9, 11
	goto RedgeTown_EventScript_GiveRunningShoesTrigger
	end

RedgeTown_EventScript_GiveRunningShoesTrigger::
	msgbox RedgeTown_Text_WaitPlayer, MSGBOX_DEFAULT
	closemessage
	call RedgeTown_EventScript_MomApproachPlayer
	call RedgeTown_EventScript_DidYouSeeCedar
	call RedgeTown_EventScript_MomReturnHome
	goto RedgeTown_EventScript_SetReceivedRunningShoes
	end

RedgeTown_EventScript_MomApproachPlayer::
	call_if_eq VAR_0x8008, 0, RedgeTown_EventScript_MomApproachPlayer0
	call_if_eq VAR_0x8008, 1, RedgeTown_EventScript_MomApproachPlayer1
	call_if_eq VAR_0x8008, 2, RedgeTown_EventScript_MomApproachPlayer2
	return

RedgeTown_EventScript_MomApproachPlayer0::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_REDGE_MOM, RedgeTown_Movement_MomApproachPlayer0
	waitmovement 0
	return

RedgeTown_EventScript_MomApproachPlayer1::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_REDGE_MOM, RedgeTown_Movement_MomApproachPlayer1
	waitmovement 0
	return

RedgeTown_EventScript_MomApproachPlayer2::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement LOCALID_REDGE_MOM, RedgeTown_Movement_MomApproachPlayer2
	waitmovement 0
	return

RedgeTown_EventScript_MomReturnHome::
	call_if_eq VAR_0x8008, 0, RedgeTown_EventScript_MomReturnHome0
	call_if_eq VAR_0x8008, 1, RedgeTown_EventScript_MomReturnHome1
	call_if_eq VAR_0x8008, 2, RedgeTown_EventScript_MomReturnHome2
	return

RedgeTown_EventScript_MomReturnHome0::
	applymovement LOCALID_REDGE_MOM, RedgeTown_Movement_MomReturnHome0
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

RedgeTown_EventScript_MomReturnHome1::
	applymovement LOCALID_REDGE_MOM, RedgeTown_Movement_MomReturnHome1
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return


RedgeTown_EventScript_MomReturnHome2::
	applymovement LOCALID_REDGE_MOM, RedgeTown_Movement_MomReturnHome2
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

RedgeTown_EventScript_Mom::
	lock
	faceplayer
	call RedgeTown_EventScript_GiveRunningShoes
	// applymovement LOCALID_REDGE_MOM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	// applymovement LOCALID_REDGE_MOM, RedgeTown_Movement_MomExitThroughDoor
	waitmovement 0
	// hideobjectat LOCALID_REDGE_MOM, MAP_REDGE_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	goto RedgeTown_EventScript_SetReceivedRunningShoes
	end

RedgeTown_EventScript_SetReceivedRunningShoes::
	setflag FLAG_HIDE_REDGE_TOWN_MOM_OUTSIDE
	setflag FLAG_SYS_B_DASH
	setvar VAR_REDGE_TOWN_STATE, 4
	release
	end

RedgeTown_EventScript_DidYouSeeCedar::
	msgbox RedgeTown_Text_DidYouSeeCedar, MSGBOX_DEFAULT
	waitmessage
	goto_if_eq VAR_0x8008, 0, RedgeTown_EventScript_StarterMovement0
	goto_if_eq VAR_0x8008, 1, RedgeTown_EventScript_StarterMovement1
	goto_if_eq VAR_0x8008, 2, RedgeTown_EventScript_StarterMovement2


RedgeTown_EventScript_GiveRunningShoes::
	msgbox RedgeTown_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RedgeTown_Text_SwitchShoesWithRunningShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	msgbox RedgeTown_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	msgbox RedgeTown_Text_StaySafeHoney, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

RedgeTown_Text_StaySafeHoney:
	.string "Mom: Stay safe, honey. If your\n"
	.string "Pokemon need healing, you can\p"
	.string "come home and rest up.$"

RedgeTown_EventScript_StarterMovement0::
	applymovement LOCALID_FOLLOWING_POKEMON, RedgeTown_Movement_StarterApproachMom0
	waitmovement
	delay 5
	call_if_eq VAR_STARTER_MON, 0, RedgeTown_EventScript_SnivyCry
	call_if_eq VAR_STARTER_MON, 1, RedgeTown_EventScript_ScorbunnyCry
	call_if_eq VAR_STARTER_MON, 2, RedgeTown_EventScript_SquirtleCry
	delay 48
	applymovement LOCALID_REDGE_MOM, Common_Movement_FaceDown
	waitmovement
	msgbox RedgeTown_Text_CutePokemon, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_REDGE_MOM, Common_Movement_FaceRight
	waitmovement
	applymovement LOCALID_FOLLOWING_POKEMON, RedgeTown_Movement_StarterReturnToPlayer0
	waitmovement
	goto RedgeTown_EventScript_GiveRunningShoes

RedgeTown_EventScript_StarterMovement1::
	applymovement LOCALID_FOLLOWING_POKEMON, RedgeTown_Movement_StarterApproachMom1
	waitmovement
	delay 5
	call_if_eq VAR_STARTER_MON, 0, RedgeTown_EventScript_SnivyCry
	call_if_eq VAR_STARTER_MON, 1, RedgeTown_EventScript_ScorbunnyCry
	call_if_eq VAR_STARTER_MON, 2, RedgeTown_EventScript_SquirtleCry
	delay 48
	applymovement LOCALID_REDGE_MOM, Common_Movement_FaceUp
	waitmovement
	msgbox RedgeTown_Text_CutePokemon, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_REDGE_MOM, Common_Movement_FaceRight
	waitmovement
	applymovement LOCALID_FOLLOWING_POKEMON, RedgeTown_Movement_StarterReturnToPlayer1
	waitmovement
	goto RedgeTown_EventScript_GiveRunningShoes

RedgeTown_EventScript_StarterMovement2::
	applymovement LOCALID_FOLLOWING_POKEMON, RedgeTown_Movement_StarterApproachMom2
	waitmovement
	delay 5
	call_if_eq VAR_STARTER_MON, 0, RedgeTown_EventScript_SnivyCry
	call_if_eq VAR_STARTER_MON, 1, RedgeTown_EventScript_ScorbunnyCry
	call_if_eq VAR_STARTER_MON, 2, RedgeTown_EventScript_SquirtleCry
	delay 48
	applymovement LOCALID_REDGE_MOM, Common_Movement_FaceUp
	waitmovement
	msgbox RedgeTown_Text_CutePokemon, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_REDGE_MOM, Common_Movement_FaceRight
	waitmovement
	applymovement LOCALID_FOLLOWING_POKEMON, RedgeTown_Movement_StarterReturnToPlayer2
	waitmovement
	goto RedgeTown_EventScript_GiveRunningShoes

RedgeTown_EventScript_StarterCry::
	call_if_eq VAR_STARTER_MON, 0, RedgeTown_EventScript_SnivyCry
	call_if_eq VAR_STARTER_MON, 1, RedgeTown_EventScript_ScorbunnyCry
	call_if_eq VAR_STARTER_MON, 2, RedgeTown_EventScript_SquirtleCry
	return

RedgeTown_EventScript_SnivyCry::
	waitse
	playmoncry SPECIES_SNIVY, CRY_MODE_NORMAL
	return

RedgeTown_EventScript_ScorbunnyCry::
	waitse
	playmoncry SPECIES_SCORBUNNY, CRY_MODE_NORMAL
	return

RedgeTown_EventScript_SquirtleCry::
	waitse
	playmoncry SPECIES_SQUIRTLE, CRY_MODE_NORMAL
	return

RedgeTown_Text_ExplainPokenav:
	.string "Mom: Isn't it neat? You can use it\n"
	.string "to view your map easily!\p"
	.string "I'll even add my number so you can\n"
	.string "call me without having to use a\l"
	.string "payphone!$"

RedgeTown_Text_ReceivedPokenav:
	.string "{PLAYER} received a PokéNav.$"

RedgeTown_Text_OutOfBreath:
	.string "Mom: Huff, huff… I need to dig those\n"
	.string "exercise DVDs out of the attic… Huff…$"

RedgeTown_Text_OneMoreThingForYou:
	.string "Mom: I've got one more thing for\n"
	.string "you to take on your journey.\p"
	.string "It's a brand new PokéNav!$"

RedgeTown_Text_HoldUpPlayer:
	.string "Mom: Hold on, {PLAYER}!$"

RedgeTown_Text_Sylveon:
	.string "Silly: Zzz… zzz…$"

RedgeTown_Text_WaitPlayer:
	.string "Mom: Wait, {PLAYER}!$"

RedgeTown_Text_DidYouSeeCedar:
	.string "Mom: {PLAYER}! {PLAYER}! Did you see what\n"
	.string "Prof. Cedar had to say?$"

RedgeTown_Text_CutePokemon:
	.string "Mom: Oh, what a cute Pokémon!\n"
	.string "Oh, Prof. Cedar gave it to you?\p"
	.string "Well, it's adorable!$"

RedgeTown_Text_WearTheseRunningShoes:
	.string "Mom: What's wrong honey?\p"
	.string "…He wants you to deliver something to\n"
	.string "Tepek City? Alright, honey, be careful.\p"
	.string "I know! Here If you're going out on an\n"
	.string "adventure, wear these running shoes.\p"
	.string "They'll put a zip in your step!$"

RedgeTown_Text_SwitchShoesWithRunningShoes:
	.string "{PLAYER} switched shoes with the\n"
	.string "running shoes.$"

RedgeTown_Text_ExplainRunningShoes:
	.string "Mom: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "running shoes to run extra-fast!\p"
	.string "“Slip on these running shoes and race\n"
	.string "around like a wild Zebstrika!”$"

RedgeTown_Text_ComeHomeIfAnythingHappens:
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "Pokémon now…\l"
	.string "I'm proud of you, {PLAYER}.\p"
	.string "…But please be careful.\n"
	.string "You can always come home if you need.\p"
	.string "Go on, go get them, honey!$"

RedgeTown_Text_MakeVideoGames:
	.string "It's easier than ever these days to\n"
	.string "make your own video games!\p"
	.string "The power of science is astounding!$"

RedgeTown_Text_AdmiringScenery:
	.string "Sometimes, it's good to slow down and\n"
	.string "admire the scenery.$"

RedgeTown_Text_DontGoOutThere:
	.string "Wait up, kid, don't go out there.$"

RedgeTown_Text_DangerousIfYouDontHavePokemon:
	.string "I know you don't have your own Pokémon\n"
	.string "yet, so I can't let you go. It's\l"
	.string "reckless to go out without at least one.$"

RedgeTown_Text_CanYouGoSeeWhatsHappening:
	.string "Hey, {PLAYER}{KUN}! Nice Pokémon!$"

RedgeTown_Text_GoodLuckCatchingPokemon:
	.string "Are you heading out?\n"
	.string "Good luck!$"

RedgeTown_Text_TownSign:
	.string "Redge Town\n"
	.string "“A quiet town for quiet people.”$"

RedgeTown_Text_ProfCedarsLab:
	.string "Prof. Cedar'S Pokémon Lab$"

RedgeTown_Text_PlayersHouse:
	.string "{PLAYER}'s House$"

RedgeTown_Movement_StarterApproachMom0:
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

RedgeTown_Movement_StarterApproachMom1:
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

RedgeTown_Movement_StarterApproachMom2:
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

RedgeTown_Movement_StarterReturnToPlayer0:
	walk_fast_right
	walk_fast_right
	walk_fast_up
	face_left
	step_end

RedgeTown_Movement_StarterReturnToPlayer1:
	walk_fast_right
	walk_fast_right
	walk_fast_down
	face_left
	step_end

RedgeTown_Movement_StarterReturnToPlayer2:
	walk_fast_right
	walk_fast_right
	walk_fast_down
	face_left
	step_end

RedgeTown_Movement_MomApproachPlayer0:
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

RedgeTown_Movement_MomApproachPlayer1:
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

RedgeTown_Movement_MomApproachPlayer2:
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

RedgeTown_Movement_MomReturnHome0:
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

RedgeTown_Movement_MomReturnHome1:
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

RedgeTown_Movement_MomReturnHome2:
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

RedgeTown_Movement_TeenApproachPlayerLeft:
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

RedgeTown_Movement_TeenReturnLeft:
	walk_right
	walk_up
	walk_right
	walk_in_place_faster_up
	step_end

RedgeTown_Movement_TeenApproachPlayerRight:
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

RedgeTown_Movement_TeenPushPlayerFromRoute:
	walk_up
	step_end

RedgeTown_Movement_TeenReturnRight:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_down
	walk_in_place_faster_up
	step_end

RedgeTown_Movement_PushPlayerBackFromRoute:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end
