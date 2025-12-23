RedgeTown_ProfessorCedarsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RedgeTown_ProfessorCedarsLab_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RedgeTown_ProfessorCedarsLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RedgeTown_ProfessorCedarsLab_OnFrame
	.byte 0

	@ State descriptions for VAR_DEX_UPGRADE_JOHTO_STARTER_STATE
	@ 1: Beat Elite Four, Dex upgrade ready
	@ 2: Received National Dex
	@ 3: Left lab after receiving National Dex
	@ 4: Entered lab after catching all Hoenn mons
	@ 5: Cedar told player to choose Johto starter
	@ 6: Chose Johto starter

	@ State descriptions for VAR_CEDAR_LAB_STATE
	@ 1: Never occurs
	@ 2: Chose starter
	@ 3: Received starter in lab
	@ 4: Defeated rival on Route 103
	@ 5: Received pokedex

RedgeTown_ProfessorCedarsLab_OnTransition:
	call_if_le VAR_CEDAR_LAB_STATE, 2, RedgeTown_ProfessorCedarsLab_EventScript_SetObjectPosForSansubaStarters
	call_if_ge VAR_CEDAR_LAB_STATE, 4, RedgeTown_ProfessorCedarsLab_EventScript_NoMoreSansubaStarters
	// call Common_EventScript_SetupRivalGfxId
	// call ProfCedar_EventScript_UpdateLocation
	// goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, RedgeTown_ProfessorCedarsLab_EventScript_SetAfterJohtoStarterLayout
	// goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, RedgeTown_ProfessorCedarsLab_EventScript_SetJohtoStarterLayout
	// goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, RedgeTown_ProfessorCedarsLab_EventScript_CheckReadyForJohtoStarter
	end

RedgeTown_ProfessorCedarsLab_EventScript_MoveTrainer::
	lockall
	applymovement LOCALID_PLAYER, RedgeTown_ProfessorCedarsLab_Movement_PlayerEnterLab
	waitmovement 0
	releaseall
	goto_if_eq VAR_CEDAR_LAB_STATE, 1, RedgeTown_ProfessorCedarsLab_EventScript_Cedar
	goto_if_eq VAR_CEDAR_LAB_STATE, 5, RedgeTown_ProfessorCedarsLab_EventScript_PokeballDelivered
	end

RedgeTown_ProfessorCedarsLab_Movement_PlayerEnterLab:
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
	step_end

// RedgeTown_ProfessorCedarsLab_EventScript_CheckReadyForJohtoStarter::
	// specialvar VAR_RESULT, HasAllHoennMons
	// goto_if_eq VAR_RESULT, TRUE, RedgeTown_ProfessorCedarsLab_EventScript_SetReadyForJohtoStarter
	// setobjectmovementtype LOCALID_CEDARS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	// setobjectxyperm LOCALID_CEDARS_LAB_RIVAL, 5, 10
	// end

// RedgeTown_ProfessorCedarsLab_EventScript_SetReadyForJohtoStarter::
	// setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
	// goto RedgeTown_ProfessorCedarsLab_EventScript_SetJohtoStarterLayout

// RedgeTown_ProfessorCedarsLab_EventScript_SetJohtoStarterLayout::
	// setmaplayoutindex LAYOUT_REDGE_TOWN_PROFESSOR_CEDARS_LAB_WITH_TABLE
	// end

// RedgeTown_ProfessorCedarsLab_EventScript_SetAfterJohtoStarterLayout::
	// setmaplayoutindex LAYOUT_REDGE_TOWN_PROFESSOR_CEDARS_LAB_WITH_TABLE
	// setobjectmovementtype LOCALID_CEDARS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	// setobjectxyperm LOCALID_CEDARS_LAB_RIVAL, 5, 10
	// end

RedgeTown_ProfessorCedarsLab_EventScript_SnivyPokeball::
	goto_if_le VAR_CEDAR_LAB_STATE, 2, RedgeTown_ProfessorCedarsLab_EventScript_ItsAPokeball
	goto_if_ge VAR_CEDAR_LAB_STATE, 3, RedgeTown_ProfessorCedarsLab_EventScript_AlreadyChoseStarter

RedgeTown_ProfessorCedarsLab_EventScript_SquirtlePokeball::
	goto_if_le VAR_CEDAR_LAB_STATE, 2, RedgeTown_ProfessorCedarsLab_EventScript_ItsAPokeball
	goto_if_ge VAR_CEDAR_LAB_STATE, 3, RedgeTown_ProfessorCedarsLab_EventScript_AlreadyChoseStarter

RedgeTown_ProfessorCedarsLab_EventScript_ScorbunnyPokeball::
	goto_if_le VAR_CEDAR_LAB_STATE, 2, RedgeTown_ProfessorCedarsLab_EventScript_ItsAPokeball
	goto_if_ge VAR_CEDAR_LAB_STATE, 3, RedgeTown_ProfessorCedarsLab_EventScript_AlreadyChoseStarter

RedgeTown_ProfessorCedarsLab_EventScript_ItsAPokeball::
	lock
	msgbox RedgeTown_ProfessorCedarsLab_Text_ItsAPokeball
	release
	end

RedgeTown_ProfessorCedarsLab_Text_ItsAPokeball:
	.string "It's a shiny, red Pokéball!$"

RedgeTown_ProfessorCedarsLab_OnWarp:
	// map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, RedgeTown_ProfessorCedarsLab_EventScript_SetObjectPosForDexUpgrade
	// map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, RedgeTown_ProfessorCedarsLab_EventScript_SetObjectPosForDexUpgrade
	// map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, RedgeTown_ProfessorCedarsLab_EventScript_AddRivalObject
	// map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, RedgeTown_ProfessorCedarsLab_EventScript_AddRivalObject
	// map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, RedgeTown_ProfessorCedarsLab_EventScript_SetObjectPosForJohtoStarters
	.2byte 0

RedgeTown_ProfessorCedarsLab_EventScript_SetObjectPosForSansubaStarters::
	setobjectxyperm LOCALID_SNIVY_POKEBALL, 7, 1
	setobjectxyperm LOCALID_SQUIRTLE_POKEBALL, 8, 1
	setobjectxyperm LOCALID_SCORBUNNY_POKEBALL, 9, 1
	end

RedgeTown_ProfessorCedarsLab_EventScript_NoMoreSansubaStarters::
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, RedgeTown_ProfessorCedarsLab_EventScript_HidePokeballs
	end

RedgeTown_ProfessorCedarsLab_EventScript_HidePokeballs::
	call_if_eq VAR_STARTER_MON, 0, RedgeTown_ProfessorCedarsLab_EventScript_HideSnivy
	call_if_eq VAR_STARTER_MON, 1, RedgeTown_ProfessorCedarsLab_EventScript_HideScorbunny
	call_if_eq VAR_STARTER_MON, 2, RedgeTown_ProfessorCedarsLab_EventScript_HideSquirtle
	end

RedgeTown_ProfessorCedarsLab_EventScript_SetObjectPosForDexUpgrade::
	turnobject LOCALID_PLAYER, DIR_NORTH
	addobject LOCALID_CEDARS_LAB_CEDAR
	// addobject LOCALID_CEDARS_LAB_RIVAL
	// turnobject LOCALID_CEDARS_LAB_RIVAL, DIR_NORTH
	// setobjectxy LOCALID_CEDARS_LAB_RIVAL, 5, 5
	turnobject LOCALID_CEDARS_LAB_CEDAR, DIR_SOUTH
	setobjectxy LOCALID_CEDARS_LAB_CEDAR, 6, 4
	turnobject LOCALID_CEDARS_LAB_AIDE, DIR_EAST
	setobjectxy LOCALID_CEDARS_LAB_AIDE, 10, 10
	end

RedgeTown_ProfessorCedarsLab_EventScript_AddRivalObject::
	// addobject LOCALID_CEDARS_LAB_RIVAL
	end

RedgeTown_ProfessorCedarsLab_OnFrame:
	map_script_2 VAR_CEDAR_LAB_STATE, 3, RedgeTown_ProfessorCedarsLab_EventScript_GiveStarterEvent
	// map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, RedgeTown_ProfessorCedarsLab_EventScript_UpgradeToNationalDex
	map_script_2 VAR_CEDAR_LAB_STATE, 1, RedgeTown_ProfessorCedarsLab_EventScript_MoveTrainer
	map_script_2 VAR_CEDAR_LAB_STATE, 5, RedgeTown_ProfessorCedarsLab_EventScript_MoveTrainer
	.2byte 0

@ The starter is technically given prior to this on Route 231 by special ChooseStarter
@ This is just where the game tells you its yours and lets you nickname it
RedgeTown_ProfessorCedarsLab_EventScript_GiveStarterEvent::
	lockall
	setflag FLAG_SYS_POKEMON_GET
	bufferleadmonspeciesname STR_VAR_1
	message RedgeTown_ProfessorCedarsLab_Text_LikeYouToHavePokemon
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox RedgeTown_ProfessorCedarsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RedgeTown_ProfessorCedarsLab_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, RedgeTown_ProfessorCedarsLab_EventScript_GoDeliverThat
	end

RedgeTown_ProfessorCedarsLab_EventScript_HideSnivy::
	setflag FLAG_HIDE_SNIVY_POKEBALL
	return

RedgeTown_ProfessorCedarsLab_EventScript_HideScorbunny::
	setflag FLAG_HIDE_SCORBUNNY_POKEBALL
	return

RedgeTown_ProfessorCedarsLab_EventScript_HideSquirtle::
	setflag FLAG_HIDE_SQUIRTLE_POKEBALL
	return

RedgeTown_ProfessorCedarsLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto RedgeTown_ProfessorCedarsLab_EventScript_GoDeliverThat
	end

RedgeTown_ProfessorCedarsLab_EventScript_GoDeliverThat::
	setvar VAR_CEDAR_LAB_STATE, 4
	setvar VAR_REDGE_TOWN_STATE, 3
	msgbox RedgeTown_ProfessorCedarsLab_Text_GoDeliverThat, MSGBOX_DEFAULT
	releaseall
	end

RedgeTown_ProfessorCedarsLab_Text_GoDeliverThat:
	.string "Prof. Cedar: Come back once you deliver\n"
	.string "that, okay?  You'll be delivering that\p"
	.string "to Jude.\p"
	.string "His apartment complex is near the Mart,\n"
	.string "so it shouldn't be too hard to find!$"

RedgeTown_ProfessorCedarsLab_Text_GoDeliverThatReminder:
	.string "Prof. Cedar: Come back once you deliver\n"
	.string "that, okay?  You'll be delivering that\p"
	.string "to Jude.\p"
	.string "His apartment complex is near the Mart,\n"
	.string "so it shouldn't be too hard to find!$"

RedgeTown_ProfessorCedarsLab_EventScript_UpgradeToNationalDex::
	lockall
	delay 30
	msgbox RedgeTown_ProfessorCedarsLab_Text_OtherRegionsUpgradeToNational, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CEDARS_LAB_CEDAR, RedgeTown_ProfessorCedarsLab_Movement_CedarRetrievePokedexes
	waitmovement 0
	delay 20
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	// applymovement LOCALID_CEDARS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PC_ON
	waitse
	delay 20
	applymovement LOCALID_CEDARS_LAB_CEDAR, RedgeTown_ProfessorCedarsLab_Movement_CedarReturnPokedex
	waitmovement 0
	// applymovement LOCALID_CEDARS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox RedgeTown_ProfessorCedarsLab_Text_OkayAllDone, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RedgeTown_ProfessorCedarsLab_Text_PokedexUpgradedToNational
	waitmessage
	waitfanfare
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	msgbox RedgeTown_ProfessorCedarsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_REDGE_TOWN_CEDAR
	setflag FLAG_HIDE_REDGE_TOWN_RIVAL
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	releaseall
	end

RedgeTown_ProfessorCedarsLab_Movement_CedarRetrievePokedexes:
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

RedgeTown_ProfessorCedarsLab_Movement_CedarReturnPokedex:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_in_place_faster_down
	step_end

RedgeTown_ProfessorCedarsLab_EventScript_ChooseJohtoStarter::
	lockall
	applymovement LOCALID_PLAYER, RedgeTown_ProfessorCedarsLab_Movement_PlayerEnterLabForJohtoStarter
	waitmovement 0
	msgbox RedgeTown_ProfessorCedarsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
	releaseall
	end

RedgeTown_ProfessorCedarsLab_Movement_PlayerEnterLabForJohtoStarter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RedgeTown_ProfessorCedarsLab_EventScript_AideBooks::
	lock
	faceplayer
	msgbox RedgeTown_ProfessorCedarsLab_Text_LookingThroughBooks, MSGBOX_DEFAULT
	release
	end

RedgeTown_ProfessorCedarsLab_EventScript_AidePC::
	lock
	faceplayer
	msgbox RedgeTown_ProfessorCedarsLab_Text_OnPC, MSGBOX_DEFAULT
	release
	end

RedgeTown_ProfessorCedarsLab_EventScript_AideGeodude::
	lock
	faceplayer
	msgbox RedgeTown_ProfessorCedarsLab_Text_StudyingWildPokemon, MSGBOX_DEFAULT
	release
	end

RedgeTown_ProfessorCedarsLab_EventScript_Geodude::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_GEODUDE, CRY_MODE_NORMAL
	msgbox RedgeTown_Text_Geodude, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RedgeTown_ProfessorCedarsLab_Text_LookingThroughBooks:
	.string "I'm looking through these books to find\n"
	.string "information on Pokémon!$"

RedgeTown_ProfessorCedarsLab_Text_OnPC:
	.string "Did you know sometimes published\n"
	.string "scientists post their books online\l"
	.string "so other scientists can read them?$"

RedgeTown_ProfessorCedarsLab_Text_StudyingWildPokemon:
	.string "The best way to study Pokémon is\n"
	.string "to get a hands-on approach!\p"
	.string "Unfortunately, this Geodude isn't one\n"
	.string "for being handled.$"

RedgeTown_Text_Geodude:
	.string "Geodude: Duuuuude!$"

RedgeTown_ProfessorCedarsLab_EventScript_AideAlreadyMet::
	release
	end

RedgeTown_ProfessorCedarsLab_EventScript_AideReceivedStarter::
	release
	end

RedgeTown_ProfessorCedarsLab_EventScript_AlreadyChoseStarter::
	msgbox RedgeTown_ProfessorCedarsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
	releaseall
	end

RedgeTown_ProfessorCedarsLab_EventScript_TakeYourTime::
	hidemonpic
	msgbox RedgeTown_ProfessorCedarsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
	releaseall
	end

// RedgeTown_ProfessorCedarsLab_EventScript_GiveChikorita::
	// bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
	// setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIKORITA
	// givemon SPECIES_CHIKORITA, 5
	// goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RedgeTown_ProfessorCedarsLab_EventScript_SendChikoritaToParty
	// goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RedgeTown_ProfessorCedarsLab_EventScript_SendChikoritaToPC
	// hidemonpic
	// goto Common_EventScript_NoMoreRoomForPokemon
	// end

// RedgeTown_ProfessorCedarsLab_EventScript_SendChikoritaToParty::
	// call RedgeTown_ProfessorCedarsLab_EventScript_ReceivedJohtoStarter
	// removeobject LOCALID_CEDARS_LAB_CHIKORITA_BALL
	// msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	// goto_if_eq VAR_RESULT, NO, RedgeTown_ProfessorCedarsLab_EventScript_ReceivedChikorita
	// call Common_EventScript_GetGiftMonPartySlot
	// call Common_EventScript_NameReceivedPartyMon
	// goto RedgeTown_ProfessorCedarsLab_EventScript_ReceivedChikorita
	// end

// RedgeTown_ProfessorCedarsLab_EventScript_ReceivedChikorita::
	// hidemonpic
	// msgbox RedgeTown_ProfessorCedarsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	// setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	// releaseall
	// end

// RedgeTown_ProfessorCedarsLab_EventScript_ReceivedJohtoStarter::
	// playfanfare MUS_OBTAIN_ITEM
	// message RedgeTown_ProfessorCedarsLab_Text_ReceivedJohtoStarter
	// waitmessage
	// waitfanfare
	// return

RedgeTown_ProfessorCedarsLab_EventScript_Cedar::
	lock
	faceplayer
	goto_if_eq VAR_CEDAR_LAB_STATE, 1, RedgeTown_ProfessorCedarsLab_EventScript_HelloPlayer
	goto_if_eq VAR_CEDAR_LAB_STATE, 4, RedgeTown_ProfessorCedarsLab_EventScript_DeliveredYet
	goto_if_eq VAR_CEDAR_LAB_STATE, 5, RedgeTown_ProfessorCedarsLab_EventScript_PokeballDelivered
	goto_if_unset FLAG_HAS_MATCH_CALL, RedgeTown_ProfessorCedarsLab_EventScript_TryRatePokedexOrRegister
	goto_if_unset FLAG_ENABLE_PROF_CEDAR_MATCH_CALL, EventScript_RegisterProfCedar
	goto RedgeTown_ProfessorCedarsLab_EventScript_TryRatePokedexOrRegister
	end

RedgeTown_ProfessorCedarsLab_EventScript_DeliveredYet::
	msgbox RedgeTown_ProfessorCedarsLab_Text_DeliveredYet, MSGBOX_DEFAULT
	release
	end

RedgeTown_ProfessorCedarsLab_EventScript_PokeballDelivered::
	msgbox RedgeTown_ProfessorCedarsLab_Text_DeliveredYet, MSGBOX_DEFAULT
	closemessage
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RedgeTown_ProfessorCedarsLab_EventScript_IHaveSomethingElseMale
	goto_if_eq VAR_RESULT, FEMALE, RedgeTown_ProfessorCedarsLab_EventScript_IHaveSomethingElseFemale

RedgeTown_ProfessorCedarsLab_EventScript_IHaveSomethingElseMale::
	msgbox RedgeTown_ProfessorCedarsLab_Text_PokeballDeliveredMale, MSGBOX_DEFAULT
	goto RedgeTown_ProfessorCedarsLab_EventScript_GivePokedex

RedgeTown_ProfessorCedarsLab_EventScript_IHaveSomethingElseFemale::
	msgbox RedgeTown_ProfessorCedarsLab_Text_PokeballDeliveredFemale, MSGBOX_DEFAULT
	goto RedgeTown_ProfessorCedarsLab_EventScript_GivePokedex

RedgeTown_ProfessorCedarsLab_Text_DeliveredYet:
	.string "Prof. Cedar: Have you delivered that\n"
	.string "Ball, yet?$"

RedgeTown_ProfessorCedarsLab_Text_PokeballDeliveredMale:
	.string "Prof. Cedar: Good job, my boy!\n"
	.string "While you were gone, I managed to\p"
	.string "get something else, for you.$"

RedgeTown_ProfessorCedarsLab_Text_PokeballDeliveredFemale:
	.string "Prof. Cedar: Good job, my girl!\n"
	.string "While you were gone, I managed to\p"
	.string "get something else, for you.$"

RedgeTown_ProfessorCedarsLab_EventScript_HelloPlayer::
	clearflag FLAG_HIDE_REDGE_TOWN_MOM_OUTSIDE
	applymovement LOCALID_CEDARS_LAB_CEDAR, Common_Movement_WalkInPlaceFasterLeft
	msgbox RedgeTown_ProfessorCedarsLab_Text_HelloPlayer, MSGBOX_DEFAULT
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RedgeTown_ProfessorCedarsLab_EventScript_IHaveSomethingMale
	goto_if_eq VAR_RESULT, FEMALE, RedgeTown_ProfessorCedarsLab_EventScript_IHaveSomethingFemale

RedgeTown_ProfessorCedarsLab_EventScript_Delivery::
	msgbox RedgeTown_ProfessorCedarsLab_Text_TepekDelivery, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RedgeTown_ProfessorCedarsLab_EventScript_AgreeToDelivery
	goto_if_eq VAR_RESULT, NO, RedgeTown_ProfessorCedarsLab_EventScript_DeclineDelivery
	release
	end

RedgeTown_ProfessorCedarsLab_Text_HelloPlayer:
	.string "Prof. Cedar: Ah, hello, {PLAYER}{KUN}!$"

RedgeTown_ProfessorCedarsLab_EventScript_IHaveSomethingMale::
	msgbox RedgeTown_ProfessorCedarsLab_Text_IHaveSomethingMale, MSGBOX_DEFAULT
	goto RedgeTown_ProfessorCedarsLab_EventScript_Delivery

RedgeTown_ProfessorCedarsLab_EventScript_IHaveSomethingFemale::
	msgbox RedgeTown_ProfessorCedarsLab_Text_IHaveSomethingFemale, MSGBOX_DEFAULT
	goto RedgeTown_ProfessorCedarsLab_EventScript_Delivery

RedgeTown_ProfessorCedarsLab_Text_IHaveSomethingMale:
	.string "I have a favor to ask of you, my boy.$"

RedgeTown_ProfessorCedarsLab_Text_IHaveSomethingFemale:
	.string "I have a favor to ask of you, my girl.$"

RedgeTown_ProfessorCedarsLab_Text_TepekDelivery:
	.string "I have a delivery to make to Tepek\n"
	.string "City, but something has come up. I was\l"
	.string "wondering if you would make it for me?$"

RedgeTown_ProfessorCedarsLab_EventScript_AgreeToDelivery::
	msgbox RedgeTown_ProfessorCedarsLab_Text_AgreeToDelivery, MSGBOX_DEFAULT
	giveitem ITEM_PARCEL, 1
	delay 30
	applymovement LOCALID_CEDARS_LAB_CEDAR, Common_Movement_Delay48
	waitmovement 0
	playse SE_PIN
    applymovement LOCALID_CEDARS_LAB_CEDAR, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_CEDARS_LAB_CEDAR, Common_Movement_Delay48
    waitmovement 0
	msgbox RedgeTown_ProfessorCedarsLab_Text_NeedStarter, MSGBOX_DEFAULT
	setvar VAR_CEDAR_LAB_STATE, 3
	special ChooseStarter
	release
	end

RedgeTown_ProfessorCedarsLab_Text_NeedStarter:
	.string "Oh, I can't send you off to Tepek\n"
	.string "City without a Pokémon!\p"
	.string "Here, take one of these with you.$"

RedgeTown_ProfessorCedarsLab_EventScript_DeclineDelivery::
	msgbox RedgeTown_ProfessorCedarsLab_Text_DeclineDelivery, MSGBOX_DEFAULT
	msgbox RedgeTown_ProfessorCedarsLab_Text_TepekDelivery, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RedgeTown_ProfessorCedarsLab_EventScript_AgreeToDelivery
	goto_if_eq VAR_RESULT, NO, RedgeTown_ProfessorCedarsLab_EventScript_DeclineDelivery
	end

RedgeTown_ProfessorCedarsLab_Text_AgreeToDelivery:
	.string "Prof. Cedar: Great! Here is the item\n"
	.string "I need you to deliver.$"

RedgeTown_ProfessorCedarsLab_Text_DeclineDelivery:
	.string "Oh, come on, don't be like that!$"

RedgeTown_ProfessorCedarsLab_EventScript_GrassyPatchWaiting::
	msgbox RedgeTown_ProfessorCedarsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	release
	end

RedgeTown_ProfessorCedarsLab_EventScript_TryRatePokedexOrRegister::
	goto_if_set FLAG_ADVENTURE_STARTED, ProfCedar_EventScript_RatePokedexOrRegister
	// goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, ProfCedar_EventScript_RatePokedexOrRegister
	// goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, ProfCedar_EventScript_RatePokedexOrRegister
	// goto_if_eq VAR_CEDAR_LAB_STATE, 6, RedgeTown_ProfessorCedarsLab_EventScript_PokemonAwait
	release
	end

EventScript_RegisterProfCedar::
	msgbox MatchCall_Text_CedarRegisterCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredCedar, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_CEDAR_MATCH_CALL
	setvar VAR_REGISTER_CEDAR_STATE, 2
	release
	end

RedgeTown_ProfessorCedarsLab_EventScript_GivePokedex::
	msgbox RedgeTown_ProfessorCedarsLab_Text_TakePokedex, MSGBOX_DEFAULT
	call RedgeTown_ProfessorCedarsLab_EventScript_ReceivePokedex
	msgbox RedgeTown_ProfessorCedarsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	msgbox RedgeTown_ProfessorCedarsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
	closemessage
	// applymovement LOCALID_CEDARS_LAB_RIVAL, RedgeTown_ProfessorCedarsLab_Movement_RivalApproachPlayer
	// waitmovement 0
	// applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	// waitmovement 0
	// checkplayergender
	// call_if_eq VAR_RESULT, MALE, RedgeTown_ProfessorCedarsLab_EventScript_MayGivePokeBalls
	// call_if_eq VAR_RESULT, FEMALE, RedgeTown_ProfessorCedarsLab_EventScript_BrendanGivePokeBalls
	setvar VAR_CEDAR_LAB_STATE, 6
	setflag FLAG_ADVENTURE_STARTED
	// setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_REDGE_TOWN_STATE, 5,
	setvar VAR_TEPEK_CITY_STATE, 4,
	releaseall
	end

RedgeTown_ProfessorCedarsLab_EventScript_GivePokeballs0::
	lock
	delay 5
	applymovement LOCALID_CEDARLAB_AIDE, RedgeTown_ProfessorCedarsLab_Movement_AideToPlayer0
	setvar VAR_0x8008, 3
	goto RedgeTown_ProfessorCedarsLab_EventScript_GivePokeballs
	end

RedgeTown_ProfessorCedarsLab_EventScript_GivePokeballs1::
	lock
	delay 5
	applymovement LOCALID_CEDARLAB_AIDE, RedgeTown_ProfessorCedarsLab_Movement_AideToPlayer1
	setvar VAR_0x8008, 4
	goto RedgeTown_ProfessorCedarsLab_EventScript_GivePokeballs
	end

RedgeTown_ProfessorCedarsLab_EventScript_GivePokeballs2::
	lock
	delay 5
	applymovement LOCALID_CEDARLAB_AIDE, RedgeTown_ProfessorCedarsLab_Movement_AideToPlayer2
	setvar VAR_0x8008, 5
	goto RedgeTown_ProfessorCedarsLab_EventScript_GivePokeballs
	end

RedgeTown_ProfessorCedarsLab_EventScript_GivePokeballs::
	msgbox RedgeTown_ProfessorCedarsLab_Text_AideGivePokeballs, MSGBOX_NPC
	closemessage
	giveitem ITEM_POKE_BALL, 10
	goto_if_eq VAR_0x8008, 3, RedgeTown_ProfessorCedarsLab_Movement_AideToOriginalLoc0
	goto_if_eq VAR_0x8008, 4, RedgeTown_ProfessorCedarsLab_Movement_AideToOriginalLoc1
	goto_if_eq VAR_0x8008, 5, RedgeTown_ProfessorCedarsLab_Movement_AideToOriginalLoc2
	setvar VAR_CEDAR_LAB_STATE, 7
	release
	end

RedgeTown_ProfessorCedarsLab_Text_AideGivePokeballs:
	.string "Here, take these Pokéballs.\p"
	.string "They'll help you fill out your\n"
	.string "Pokédex! You can buy more Pokéballs\p"
	.string "at any Mart.$"

RedgeTown_ProfessorCedarsLab_Movement_AideToPlayer0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_up
	step_end

RedgeTown_ProfessorCedarsLab_Movement_AideToPlayer1:
	walk_left
	walk_left
	walk_left
	walk_in_place_up
	step_end

RedgeTown_ProfessorCedarsLab_Movement_AideToPlayer2:
	walk_left
	walk_left
	walk_in_place_up
	step_end

RedgeTown_ProfessorCedarsLab_Movement_AideToOriginalLoc0:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_right
	step_end

RedgeTown_ProfessorCedarsLab_Movement_AideToOriginalLoc1:
	walk_right
	walk_right
	walk_right
	walk_in_place_right
	step_end

RedgeTown_ProfessorCedarsLab_Movement_AideToOriginalLoc2:
	walk_right
	walk_right
	walk_in_place_right
	step_end

RedgeTown_ProfessorCedarsLab_EventScript_ReceivePokedex::
	playfanfare MUS_OBTAIN_ITEM
	message RedgeTown_ProfessorCedarsLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_CEDAR
	return

RedgeTown_ProfessorCedarsLab_EventScript_PokemonAwait::
	msgbox RedgeTown_ProfessorCedarsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
	release
	end

RedgeTown_ProfessorCedarsLab_EventScript_AideNoRoomForPokeBalls::
	msgbox RedgeTown_ProfessorCedarsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
	return

RedgeTown_ProfessorCedarsLab_Movement_RivalApproachPlayer:
	walk_down
	walk_in_place_faster_left
	step_end

RedgeTown_ProfessorCedarsLab_EventScript_PC::
	msgbox RedgeTown_ProfessorCedarsLab_Text_PCUsedForResearch, MSGBOX_SIGN
	end

RedgeTown_ProfessorCedarsLab_EventScript_Bookshelf::
	msgbox RedgeTown_ProfessorCedarsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
	end

RedgeTown_ProfessorCedarsLab_Text_LikeYouToHavePokemon:
	.string "Prof. Cedar: So, {PLAYER}{KUN},\n"
	.string "you chose {STR_VAR_1}? Great choice!\p"
	.string "{PLAYER} received the {STR_VAR_1}!$"

RedgeTown_ProfessorCedarsLab_Text_WhyNotGiveNicknameToMon:
	.string "Prof. Cedar: While you're at it, why not\n"
	.string "give a nickname to that {STR_VAR_1}?$"

RedgeTown_ProfessorCedarsLab_Text_TakePokedex:
	.string "Prof. Cedar: It's a Pokédex!\p"
	.string "They are technically for researchers,\n"
	.string "but I managed to convince my higher-\l"
	.string "ups to let me lend this one to you.\p"
	.string "Go on, take it!$"

RedgeTown_ProfessorCedarsLab_Text_ReceivedPokedex:
	.string "{PLAYER} received the Pokédex!$"

RedgeTown_ProfessorCedarsLab_Text_ExplainPokedex:
	.string "Prof. Cedar: The Pokédex is a high-tech\n"
	.string "tool that automatically makes a record\l"
	.string "of any Pokémon you meet or catch.$"

RedgeTown_ProfessorCedarsLab_Text_CountlessPokemonAwait:
	.string "Prof. Cedar: Try taking on the Gym\n"
	.string "challenge, or fill out your Pokédex!\p"
	.string "You can do anything you put your mind\n"
	.string "to. I believe in you!$"

RedgeTown_ProfessorCedarsLab_Text_OhYourBagsFull:
	.string "Oh? Your Bag's full.$"

RedgeTown_ProfessorCedarsLab_Text_PCUsedForResearch:
	.string "It's a PC used for research.\n"
	.string "Better not mess around with it.$"

RedgeTown_ProfessorCedarsLab_Text_CrammedWithBooksOnPokemon:
	.string "It's crammed with books on Pokémon.$"

RedgeTown_ProfessorCedarsLab_Text_OtherRegionsUpgradeToNational:
	.string "Prof. Cedar: Now…\p"
	.string "{PLAYER}{KUN} and {RIVAL}, I've had the two\n"
	.string "of you help me study Pokémon.\p"
	.string "Thanks to your help, new facts\n"
	.string "are coming to light.\p"
	.string "It appears that in the HOENN region,\n"
	.string "there are also Pokémon from other\l"
	.string "regions.\p"
	.string "It goes to show how rich and varied\n"
	.string "the natural environments of HOENN\l"
	.string "happen to be.\p"
	.string "That's why I think it's necessary for\n"
	.string "me to upgrade your POKéDEX to\l"
	.string "the NATIONAL Mode.\p"
	.string "Here, let me see your POKéDEX units.$"

RedgeTown_ProfessorCedarsLab_Text_OkayAllDone:
	.string "Prof. Cedar: Okay, all done!$"

RedgeTown_ProfessorCedarsLab_Text_PokedexUpgradedToNational:
	.string "{PLAYER}'s POKéDEX was upgraded\n"
	.string "to the NATIONAL Mode!$"

RedgeTown_ProfessorCedarsLab_Text_GrassyPatchWaiting2:
	.string "Prof. Cedar: But listen.\n"
	.string "You've become the CHAMPION,\l"
	.string "but your Pokémon journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is Pokémon.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"

RedgeTown_ProfessorCedarsLab_Text_CompletedDexChoosePokemon:
	.string "Prof. Cedar: Oh, {PLAYER}{KUN}!\n"
	.string "Let's have a look at your POKéDEX.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Yes, there's no doubt about it.\p"
	.string "You really have completed the HOENN\n"
	.string "region's POKéDEX.\p"
	.string "That's more than just impressive.\p"
	.string "I have a gift for you.\p"
	.string "Consider it my show of appreciation\n"
	.string "for the fantastic work you've done.\p"
	.string "My gift is a rare Pokémon only found\n"
	.string "in another region!\p"
	.string "You can have any one of these\n"
	.string "three Pokémon!$"

RedgeTown_ProfessorCedarsLab_Text_CanHaveAnyOneOfRarePokemon:
	.string "Prof. Cedar: These are rare Pokémon\n"
	.string "only found in another region!\p"
	.string "You can have any one of these\n"
	.string "three Pokémon!$"

RedgeTown_ProfessorCedarsLab_Text_YoullTakeCyndaquil:
	.string "Prof. Cedar: The FIRE Pokémon\n"
	.string "CYNDAQUIL caught your eye!\p"
	.string "You're as sharp as ever!\p"
	.string "So the CYNDAQUIL is your choice?$"

RedgeTown_ProfessorCedarsLab_Text_YoullTakeTotodile:
	.string "Prof. Cedar: The WATER Pokémon\n"
	.string "TOTODILE is your choice!\p"
	.string "You know how to pick a good one.\p"
	.string "So, you'll take the TOTODILE?$"

RedgeTown_ProfessorCedarsLab_Text_YoullTakeChikorita:
	.string "Prof. Cedar: The GRASS Pokémon\n"
	.string "CHIKORITA is your choice!\p"
	.string "You sure know what you're doing.\p"
	.string "So, you'll take the CHIKORITA?$"

RedgeTown_ProfessorCedarsLab_Text_TakeYourTimeAllInvaluable:
	.string "Prof. Cedar: Take your time before\n"
	.string "you decide.\p"
	.string "They're all invaluable Pokémon.$"

RedgeTown_ProfessorCedarsLab_Text_ReceivedJohtoStarter:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from Prof. Cedar!$"

RedgeTown_ProfessorCedarsLab_Text_ReceivedSansubaStarter:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from Prof. Cedar!$"

RedgeTown_ProfessorCedarsLab_Text_GrassyPatchWaiting:
	.string "Prof. Cedar: Listen, {PLAYER}{KUN}.\n"
	.string "You've completed the HOENN POKéDEX,\l"
	.string "but your Pokémon journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is Pokémon.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"

RedgeTown_ProfessorCedarsLab_Text_BetterLeaveOthersAlone:
	.string "You already got your Pokémon!\n"
	.string "Better leave the others alone.$"
