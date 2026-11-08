PowerPlant_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PowerPlant_Interior_OnTransition
	.byte 0

PowerPlant_Interior_OnTransition:
	call_if_eq VAR_POWER_PLANT_RESTORED, 2, PowerPlant_Interior_EventScript_RestorePlant
	end

PowerPlant_Interior_EventScript_TriGruntM1::
	trainerbattle_single TRAINER_GRUNT1_POWER_PLANT_INT, PowerPlant_Interior_Text_TriGruntM1Intro, PowerPlant_Interior_Text_TriGruntM1Defeated
	msgbox PowerPlant_Interior_Text_TriGruntM1Battle, MSGBOX_AUTOCLOSE
	end

PowerPlant_Interior_EventScript_TriGruntM2::
	trainerbattle_single TRAINER_GRUNT2_POWER_PLANT_INT, PowerPlant_Interior_Text_TriGruntM2Intro, PowerPlant_Interior_Text_TriGruntM2Defeated
	msgbox PowerPlant_Interior_Text_TriGruntM2Battle, MSGBOX_AUTOCLOSE
	end

PowerPlant_Interior_EventScript_TriGruntM3::
	trainerbattle_single TRAINER_GRUNT3_POWER_PLANT_INT, PowerPlant_Interior_Text_TriGruntM3Intro, PowerPlant_Interior_Text_TriGruntM3Defeated
	msgbox PowerPlant_Interior_Text_TriGruntM3Battle, MSGBOX_AUTOCLOSE
	end

PowerPlant_Interior_EventScript_TriGruntF1::
	trainerbattle_single TRAINER_GRUNT4_POWER_PLANT_INT, PowerPlant_Interior_Text_TriGruntF1Intro, PowerPlant_Interior_Text_TriGruntF1Defeated
	msgbox PowerPlant_Interior_Text_TriGruntF1Battle, MSGBOX_AUTOCLOSE
	end

PowerPlant_Interior_EventScript_TriGruntF2::
	trainerbattle_single TRAINER_GRUNT5_POWER_PLANT_INT, PowerPlant_Interior_Text_TriGruntF2Intro, PowerPlant_Interior_Text_TriGruntF2Defeated
	msgbox PowerPlant_Interior_Text_TriGruntF2Battle, MSGBOX_AUTOCLOSE
	end

PowerPlant_Interior_EventScript_Raichu::
	lock
	faceplayer
	call_if_eq VAR_POWER_PLANT_RESTORED, 2, PowerPlant_Interior_EventScript_RaichuRestored
	call_if_le VAR_POWER_PLANT_RESTORED, 1, PowerPlant_Interior_EventScript_RaichuStuck

PowerPlant_Interior_EventScript_RaichuRestored::
	waitse
	playmoncry SPECIES_RAICHU, CRY_MODE_NORMAL
	msgbox PowerPlant_Interior_Text_RaichuRestored, MSGBOX_NPC
	waitmoncry
	release
	end

PowerPlant_Interior_EventScript_RaichuStuck::
	waitse
	playmoncry SPECIES_RAICHU, CRY_MODE_WEAK
	msgbox PowerPlant_Interior_Text_RaichuStuck, MSGBOX_NPC
	waitmoncry
	release
	end

PowerPlant_Interior_EventScript_Magnemite::
	lock
	faceplayer
	call_if_eq VAR_POWER_PLANT_RESTORED, 2, PowerPlant_Interior_EventScript_MagnemiteRestored
	call_if_le VAR_POWER_PLANT_RESTORED, 1, PowerPlant_Interior_EventScript_MagnemiteStuck

PowerPlant_Interior_EventScript_Magnemite2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGNEMITE, CRY_MODE_NORMAL
	msgbox PowerPlant_Interior_Text_Magnemite2, MSGBOX_NPC
	waitmoncry
	release
	end

PowerPlant_Interior_EventScript_Electabuzz::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ELECTABUZZ, CRY_MODE_NORMAL
	msgbox PowerPlant_Interior_Text_Electabuzz, MSGBOX_NPC
	waitmoncry
	release
	end

PowerPlant_Interior_Text_Magnemite2:
	.string "Platinum: Bzzrt, bzzrt!$"


PowerPlant_Interior_Text_Electabuzz:
	.string "Electro: Blblblrblrlbl!$"

PowerPlant_Interior_EventScript_MagnemiteRestored::
	waitse
	playmoncry SPECIES_MAGNEMITE, CRY_MODE_NORMAL
	msgbox PowerPlant_Interior_Text_MagnemiteRestored, MSGBOX_NPC
	waitmoncry
	release
	end

PowerPlant_Interior_EventScript_MagnemiteStuck::
	waitse
	playmoncry SPECIES_MAGNEMITE, CRY_MODE_WEAK
	msgbox PowerPlant_Interior_Text_MagnemiteStuck, MSGBOX_NPC
	waitmoncry
	release
	end

PowerPlant_Interior_EventScript_Scientist1::
	call_if_eq VAR_POWER_PLANT_RESTORED, 2, PowerPlant_Interior_EventScript_Scientist1Restored
	call_if_le VAR_POWER_PLANT_RESTORED, 1, PowerPlant_Interior_EventScript_Scientist1Stuck

PowerPlant_Interior_EventScript_Scientist3::
	msgbox PowerPlant_Interior_Text_NoOneHarmed, MSGBOX_NPC
	end

PowerPlant_Interior_EventScript_Scientist4::
	msgbox PowerPlant_Interior_Text_ScaryLookingJolteon, MSGBOX_NPC
	end

PowerPlant_Interior_Text_NoOneHarmed:
	.string "We are grateful that no one\n"
	.string "was harmed in the ordeal.$"

PowerPlant_Interior_Text_ScaryLookingJolteon:
	.string "That Jolteon had a scary look\n"
	.string "on its face!$"

PowerPlant_Interior_EventScript_Scientist1Restored::
	msgbox PowerPlant_Interior_Text_WereSaved, MSGBOX_NPC
	end

PowerPlant_Interior_EventScript_Scientist1Stuck::
	msgbox PowerPlant_Interior_Text_StuckInHere, MSGBOX_NPC
	end

PowerPlant_Interior_EventScript_Scientist2::
	call_if_eq VAR_POWER_PLANT_RESTORED, 2, PowerPlant_Interior_EventScript_Scientist2Restored
	call_if_le VAR_POWER_PLANT_RESTORED, 1, PowerPlant_Interior_EventScript_Scientist2Stuck

PowerPlant_Interior_EventScript_Scientist2Restored::
	msgbox PowerPlant_Interior_Text_InfoStillHere, MSGBOX_NPC
	end

PowerPlant_Interior_EventScript_Scientist2Stuck::
	msgbox PowerPlant_Interior_Text_OurResearch, MSGBOX_NPC
	end

PowerPlant_Interior_EventScript_Engineer::
	call_if_eq VAR_POWER_PLANT_RESTORED, 2, PowerPlant_Interior_EventScript_EngineerRestored
	call_if_le VAR_POWER_PLANT_RESTORED, 1, PowerPlant_Interior_EventScript_EngineerStuck

PowerPlant_Interior_EventScript_EngineerRestored::
	msgbox PowerPlant_Interior_Text_TrainingTakesLongTime, MSGBOX_NPC
	end

PowerPlant_Interior_EventScript_Engineer2::
	msgbox PowerPlant_Interior_Text_GaugesLookAlright, MSGBOX_NPC
	end

PowerPlant_Interior_Text_GaugesLookAlright:
	.string "The gauges look alright, looks like\n"
	.string "the power is back in full swing!$"

PowerPlant_Interior_Text_GoodWrench:
	.string "I think one of those Tri goons took\n"
	.string "my best wrench…$"

PowerPlant_Interior_EventScript_Engineer3::
	msgbox PowerPlant_Interior_Text_GoodWrench, MSGBOX_NPC
	end

PowerPlant_Interior_Text_TrainingTakesLongTime:
	.string "Training can take years, and even\n"
	.string "then, you have to be cautious.$"

PowerPlant_Interior_EventScript_EngineerStuck::
	msgbox PowerPlant_Interior_Text_MachinesDangerous, MSGBOX_NPC
	end

PowerPlant_Interior_Text_InfoStillHere:
	.string "Good, our information is still here.$"

PowerPlant_Interior_Text_WereSaved:
	.string "We're saved! Thank you!$"

PowerPlant_Interior_EventScript_EncounterGunter0::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playbgm MUS_ENCOUNTER_TRI, FALSE
	delay 10
	msgbox PowerPlant_Interior_Text_AlmostDone, MSGBOX_DEFAULT
	closemessage
	delay 5
	playse SE_PIN
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, Common_Movement_FaceRight
    waitmovement 0
	msgbox PowerPlant_Interior_Text_KidInHere, MSGBOX_DEFAULT
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, PowerPlant_Interior_Movement_WalkToPlayer0
    applymovement LOCALID_POWERPLANT_GUNTER_JOLTEON, PowerPlant_Interior_Movement_WalkToPlayer0
	waitmovement
	msgbox PowerPlant_Interior_Text_TeamTrisGoal, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_GUNTER_POWER_PLANT_INT, PowerPlant_Interior_Text_GunterIntro, PowerPlant_Exterior_Text_GunterDefeat, PowerPlant_Interior_EventScript_GunterPostBattle0

PowerPlant_Interior_EventScript_GunterPostBattle0:
	msgbox PowerPlant_Interior_Text_TakeHMCut, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox PowerPlant_Interior_Text_ExplainCut, MSGBOX_DEFAULT
	msgbox PowerPlant_Interior_Text_NotWorthTheTime, MSGBOX_DEFAULT
	closemessage
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, PowerPlant_Interior_Movement_LeaveGunter0
    applymovement LOCALID_POWERPLANT_GUNTER_JOLTEON, PowerPlant_Interior_Movement_LeaveJolteon0
	waitmovement
	delay 10
	fadescreen FADE_TO_BLACK
    applymovement LOCALID_PP_INT_TRIGRUNT_M_1, PowerPlant_Interior_Movement_SetInvis
    applymovement LOCALID_PP_INT_TRIGRUNT_M_2, PowerPlant_Interior_Movement_SetInvis
    applymovement LOCALID_PP_INT_TRIGRUNT_M_3, PowerPlant_Interior_Movement_SetInvis
    applymovement LOCALID_PP_INT_TRIGRUNT_F_1, PowerPlant_Interior_Movement_SetInvis
    applymovement LOCALID_PP_INT_TRIGRUNT_F_2, PowerPlant_Interior_Movement_SetInvis
	waitmovement
	goto PowerPlant_Interior_EventScript_HideTeamTri
	end

PowerPlant_Interior_Movement_SetInvis:
	set_invisible
	step_end

PowerPlant_Interior_Movement_LeaveGunter0:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	set_invisible
	delay_16
	step_end

PowerPlant_Interior_Movement_LeaveJolteon0:
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	set_invisible
	step_end

PowerPlant_Interior_Movement_LeaveGunter1:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	set_invisible
	delay_16
	step_end

PowerPlant_Interior_Movement_LeaveJolteon1:
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	set_invisible
	step_end

PowerPlant_Interior_Movement_LeaveGunter2:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	set_invisible
	delay_16
	step_end

PowerPlant_Interior_Movement_LeaveJolteon2:
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	set_invisible
	step_end


PowerPlant_Interior_Movement_LeaveGunter3:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	set_invisible
	delay_16
	step_end

PowerPlant_Interior_Movement_LeaveJolteon3:
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	set_invisible
	step_end

PowerPlant_Interior_EventScript_EncounterGunter1::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playbgm MUS_ENCOUNTER_TRI, FALSE
	delay 10
	msgbox PowerPlant_Interior_Text_AlmostDone, MSGBOX_DEFAULT
	closemessage
	delay 5
	playse SE_PIN
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, Common_Movement_FaceRight
    waitmovement 0
	msgbox PowerPlant_Interior_Text_KidInHere, MSGBOX_DEFAULT
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, PowerPlant_Interior_Movement_WalkToPlayer1
    applymovement LOCALID_POWERPLANT_GUNTER_JOLTEON, PowerPlant_Interior_Movement_WalkToPlayer1
	waitmovement
	msgbox PowerPlant_Interior_Text_TeamTrisGoal, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_GUNTER_POWER_PLANT_INT, PowerPlant_Interior_Text_GunterIntro, PowerPlant_Exterior_Text_GunterDefeat, PowerPlant_Interior_EventScript_GunterPostBattle1

PowerPlant_Interior_EventScript_GunterPostBattle1::
	msgbox PowerPlant_Interior_Text_TakeHMCut, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox PowerPlant_Interior_Text_ExplainCut, MSGBOX_DEFAULT
	msgbox PowerPlant_Interior_Text_NotWorthTheTime, MSGBOX_DEFAULT
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, PowerPlant_Interior_Movement_LeaveGunter1
    applymovement LOCALID_POWERPLANT_GUNTER_JOLTEON, PowerPlant_Interior_Movement_LeaveJolteon1
	waitmovement
	delay 10
	fadescreen FADE_TO_BLACK
	goto PowerPlant_Interior_EventScript_HideTeamTri
	end

PowerPlant_Interior_Text_TakeHMCut:
	.string "Take this. I don't care what you\n"
	.string "do with it.$"

PowerPlant_Interior_Text_ExplainCut:
	.string "That HM contains the move Cut.\p"
	.string "You can use it to cut down small\n"
	.string "trees. Like I said, I don't care\p"
	.string "what you do with it.$"

PowerPlant_Interior_EventScript_EncounterGunter2::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playbgm MUS_ENCOUNTER_TRI, FALSE
	delay 10
	msgbox PowerPlant_Interior_Text_AlmostDone, MSGBOX_DEFAULT
	closemessage
	delay 5
	playse SE_PIN
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, Common_Movement_FaceRight
    waitmovement 0
	msgbox PowerPlant_Interior_Text_KidInHere, MSGBOX_DEFAULT
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, PowerPlant_Interior_Movement_WalkToPlayer2
    applymovement LOCALID_POWERPLANT_GUNTER_JOLTEON, PowerPlant_Interior_Movement_WalkToPlayer2
	waitmovement
	msgbox PowerPlant_Interior_Text_TeamTrisGoal, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_GUNTER_POWER_PLANT_INT, PowerPlant_Interior_Text_GunterIntro, PowerPlant_Exterior_Text_GunterDefeat, PowerPlant_Interior_EventScript_GunterPostBattle2

PowerPlant_Exterior_Text_GunterDefeat:
	.string "You've got some nerve…$"

PowerPlant_Interior_EventScript_GunterPostBattle2::
	msgbox PowerPlant_Interior_Text_TakeHMCut, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox PowerPlant_Interior_Text_ExplainCut, MSGBOX_DEFAULT
	msgbox PowerPlant_Interior_Text_NotWorthTheTime, MSGBOX_DEFAULT
	closemessage
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, PowerPlant_Interior_Movement_LeaveGunter2
    applymovement LOCALID_POWERPLANT_GUNTER_JOLTEON, PowerPlant_Interior_Movement_LeaveJolteon2
	waitmovement
	delay 10
	fadescreen FADE_TO_BLACK
	goto PowerPlant_Interior_EventScript_HideTeamTri
	end

PowerPlant_Interior_EventScript_EncounterGunter3::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playbgm MUS_ENCOUNTER_TRI, FALSE
	delay 10
	msgbox PowerPlant_Interior_Text_AlmostDone, MSGBOX_DEFAULT
	closemessage
	delay 10
	playse SE_PIN
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, Common_Movement_FaceRight
    waitmovement 0
	msgbox PowerPlant_Interior_Text_KidInHere, MSGBOX_DEFAULT
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, PowerPlant_Interior_Movement_WalkToPlayer3
    applymovement LOCALID_POWERPLANT_GUNTER_JOLTEON, PowerPlant_Interior_Movement_WalkToPlayer3
	waitmovement
	msgbox PowerPlant_Interior_Text_TeamTrisGoal, MSGBOX_DEFAULT
	closemessage
	trainerbattle_single TRAINER_GUNTER_POWER_PLANT_INT, PowerPlant_Interior_Text_GunterIntro, PowerPlant_Exterior_Text_GunterDefeat, PowerPlant_Interior_EventScript_GunterPostBattle3

PowerPlant_Interior_EventScript_GunterPostBattle3::
	msgbox PowerPlant_Interior_Text_TakeHMCut, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox PowerPlant_Interior_Text_ExplainCut, MSGBOX_DEFAULT
	msgbox PowerPlant_Interior_Text_NotWorthTheTime, MSGBOX_DEFAULT
	closemessage
    applymovement LOCALID_PP_INT_ADMIN_GUNTER, PowerPlant_Interior_Movement_LeaveGunter3
    applymovement LOCALID_POWERPLANT_GUNTER_JOLTEON, PowerPlant_Interior_Movement_LeaveJolteon3
	waitmovement
	delay 10
	fadescreen FADE_TO_BLACK
	goto PowerPlant_Interior_EventScript_HideTeamTri
	end

PowerPlant_Interior_Movement_WalkToPlayer0:
	walk_right
	walk_right
	step_end

PowerPlant_Interior_Movement_WalkToPlayer1:
	walk_down
	walk_right
	walk_right
	step_end

PowerPlant_Interior_Movement_WalkToPlayer2:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

PowerPlant_Interior_Movement_WalkToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

PowerPlant_Interior_Text_AlmostDone:
	.string "Gunter: Almost done, and then the\n"
	.string "Power Plant's electricity will belong\p"
	.string "to Team Tri!$"

PowerPlant_Interior_Text_KidInHere:
	.string "Gunter: Who let you in here? Are my\n"
	.string "grunts so imcompetent that they can't\p"
	.string "stop one child?$"

PowerPlant_Interior_Text_TeamTrisGoal:
	.string "Gunter: Team Tri's goal is simple:\p"
	.string "If we control the power, we control\n"
	.string "the entire Sansuba region.$"

PowerPlant_Interior_Text_GunterIntro:
	.string "The Power Plant is just the start,\n"
	.string "you'll see… Or maybe you won't,\p"
	.string "not if I stop you here!$"

PowerPlant_Interior_Text_NotWorthTheTime:
	.string "Whatever. A kid like you isn't\n"
	.string "worth Team Tri's time. Now step\p"
	.string "aside, we're leaving.$"

PowerPlant_Interior_EventScript_HideTeamTri::
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	removeobject LOCALID_PP_INT_ADMIN_GUNTER
	removeobject LOCALID_POWERPLANT_GUNTER_JOLTEON
	removeobject LOCALID_PP_INT_TRIGRUNT_F_1
	removeobject LOCALID_PP_INT_TRIGRUNT_F_2
	removeobject LOCALID_PP_INT_TRIGRUNT_M_1
	removeobject LOCALID_PP_INT_TRIGRUNT_M_2
	removeobject LOCALID_PP_INT_TRIGRUNT_M_3
	setflag FLAG_HIDE_TRI_GRUNTS_POWERPLANT
	setvar VAR_POWER_PLANT_RESTORED, 2
	setvar VAR_TEPEK_CITY_STATE, 6
	setobjectmovementtype LOCALID_PP_INT_RAICHU, MOVEMENT_TYPE_JOG_IN_PLACE_RIGHT
	setobjectmovementtype LOCALID_PP_INT_MAGNEMITE, MOVEMENT_TYPE_JOG_IN_PLACE_DOWN
	delay 5
	callnative UpdateFollowingPokemon
	clearflag FLAG_HIDE_POWERPLANT_INDOOR_STAFF
	setflag FLAG_HIDE_POWERPLANT_OUTDOOR_STAFF
	call PowerPlant_Interior_EventScript_RestorePlant
	fadescreen FADE_FROM_BLACK
	releaseall
	savebgm MUS_DUMMY
	fadedefaultbgm
	end

PowerPlant_Interior_EventScript_RestorePlant::
	setobjectxyperm LOCALID_PP_INT_SCIENTIST1, 4, 6
	setobjectmovementtype LOCALID_PP_INT_SCIENTIST1, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_PP_INT_RAICHU, 3, 6
	setobjectmovementtype LOCALID_PP_INT_RAICHU, MOVEMENT_TYPE_JOG_IN_PLACE_UP
	setobjectxyperm LOCALID_PP_INT_SCIENTIST2, 19, 21
	setobjectmovementtype LOCALID_PP_INT_SCIENTIST2, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_PP_INT_ENGINEER, 11, 3
	setobjectmovementtype LOCALID_PP_INT_ENGINEER, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_PP_INT_MAGNEMITE, 26, 7
	setobjectmovementtype LOCALID_PP_INT_MAGNEMITE, MOVEMENT_TYPE_JOG_IN_PLACE_LEFT
	return

PowerPlant_Interior_Text_StuckInHere:
	.string "We're all huddled in this room.\n"
	.string "Thankfully, we're all okay.$"

PowerPlant_Interior_Text_OurResearch:
	.string "Our research! What will happen\n"
	.string "to it?!$"

PowerPlant_Interior_Text_MachinesDangerous:
	.string "Those heavy machines are dangerous\n"
	.string "if you aren't properly trained to\p"
	.string "handle them.$"

PowerPlant_Interior_Text_RaichuStuck:
	.string "Squeakers: Chu…$"

PowerPlant_Interior_Text_RaichuRestored:
	.string "Squeakers: Rai, rai!$"

PowerPlant_Interior_Text_MagnemiteStuck:
	.string "Tungsten: Bzzrt…$"

PowerPlant_Interior_Text_MagnemiteRestored:
	.string "Tungsten: Bzzrt!!$"

PowerPlant_Interior_Text_TriGruntM1Intro:
	.string "How did you get past our guards?$"

PowerPlant_Interior_Text_TriGruntM1Defeated:
	.string "Oh, that's how!$"

PowerPlant_Interior_Text_TriGruntM1Battle:
	.string "We almost have everything we need.\p"
	.string "We're just waiting for the signal\n"
	.string "from our Admin.$"

PowerPlant_Interior_Text_TriGruntM2Intro:
	.string "The hum in the air makes my skin\n"
	.string "crawl, but I have to battle you!$"

PowerPlant_Interior_Text_TriGruntM2Defeated:
	.string "I should invest in some earplugs.$"

PowerPlant_Interior_Text_TriGruntM2Battle:
	.string "I wish I wasn't a lowly grunt.\n"
	.string "Maybe I could afford nicer things.$"

PowerPlant_Interior_Text_TriGruntM3Intro:
	.string "Stop right there! We can't let\n"
	.string "you pass!$"

PowerPlant_Interior_Text_TriGruntM3Defeated:
	.string "Urgh… You're strong…$"

PowerPlant_Interior_Text_TriGruntM3Battle:
	.string "Be glad we're only allowed basic\n"
	.string "Pokémon on our teams.$"

PowerPlant_Interior_Text_TriGruntF1Intro:
	.string "Hey, I'm busy! Get lost!$"

PowerPlant_Interior_Text_TriGruntF1Defeated:
	.string "Maybe it's me who should get lost!$"

PowerPlant_Interior_Text_TriGruntF1Battle:
	.string "I was tasked with finding useful\n"
	.string "info for Gunter, but all these\p"
	.string "computers are password locked!$"

PowerPlant_Interior_Text_TriGruntF2Intro:
	.string "Gunter is up ahead, are you ready?$"

PowerPlant_Interior_Text_TriGruntF2Defeated:
	.string "Ugh… Seems so…$"

PowerPlant_Interior_Text_TriGruntF2Battle:
	.string "I wish I had a cool Jolteon like\n"
	.string "Gunter does!$"
