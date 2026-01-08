PowerPlant_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PowerPlant_Exterior_OnTransition
	.byte 0

PowerPlant_Exterior_OnTransition:
	setflag FLAG_VISITED_POWER_PLANT
	call_if_eq VAR_POWER_PLANT_RESTORED, 1, PowerPlant_Exterior_SetGruntPosAside
	end

PowerPlant_Exterior_SetGruntPosAside::
	setobjectxyperm LOCALID_POWERPLANT_OUTDOOR_TRIGRUNTM_2, 21, 16
	setobjectmovementtype LOCALID_POWERPLANT_OUTDOOR_TRIGRUNTM_2, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm LOCALID_POWERPLANT_OUTDOOR_TRIGRUNTF_1, 24, 16
	setobjectmovementtype LOCALID_POWERPLANT_OUTDOOR_TRIGRUNTF_1, MOVEMENT_TYPE_FACE_DOWN
	return

PowerPlant_Exterior_EventScript_TriGruntM1::
	trainerbattle_single TRAINER_GRUNT1_POWER_PLANT, PowerPlant_Exterior_Text_TriGruntM1Intro, PowerPlant_Exterior_Text_TriGruntM1Defeated
	msgbox PowerPlant_Exterior_Text_TriGruntM1Battle, MSGBOX_AUTOCLOSE
	end

PowerPlant_Exterior_EventScript_TriGruntTrigger::
	lockall
	playbgm MUS_ENCOUNTER_TRI, FALSE
	applymovement LOCALID_POWERPLANT_OUTDOOR_TRIGRUNTM_2, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_POWERPLANT_OUTDOOR_TRIGRUNTF_1, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox PowerPlant_Exterior_Text_WhatsAKid, MSGBOX_DEFAULT
	closemessage
	trainerbattle_two_trainers TRAINER_GRUNT2_POWER_PLANT, PowerPlant_Exterior_Text_TriGruntsDefeatM, TRAINER_GRUNT3_POWER_PLANT, PowerPlant_Exterior_Text_TriGruntsDefeatF
	goto PowerPlant_Exterior_EventScript_TriGruntPostBattle

PowerPlant_Exterior_EventScript_TriGruntPostBattle::
	msgbox PowerPlant_Exterior_Text_TriGruntsStepAside, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_POWERPLANT_OUTDOOR_TRIGRUNTM_2, PowerPlant_Exterior_Movement_TriGruntM2MoveBack
	applymovement LOCALID_POWERPLANT_OUTDOOR_TRIGRUNTF_1, PowerPlant_Exterior_Movement_TriGruntF1MoveBack
	waitmovement 0
	savebgm MUS_DUMMY
	setvar VAR_POWER_PLANT_RESTORED, 1
	releaseall
	end

PowerPlant_Exterior_EventScript_TriGruntF1::
	msgbox PowerPlant_Exterior_Text_TriGruntsStepAside2, MSGBOX_NPC
	end

PowerPlant_Exterior_EventScript_TriGruntM2::
	msgbox PowerPlant_Exterior_Text_TriGruntsStepAside1, MSGBOX_NPC
	end

PowerPlant_Exterior_EventScript_Scientist1::
	msgbox PowerPlant_Exterior_Text_WhatDoWeDo, MSGBOX_NPC
	end

PowerPlant_Exterior_EventScript_Scientist2::
	msgbox PowerPlant_Exterior_Text_IHopePokemonOK, MSGBOX_NPC
	end

PowerPlant_Exterior_EventScript_Engineer1::
	msgbox PowerPlant_Exterior_Text_WillTheyTrustUs, MSGBOX_NPC
	end

PowerPlant_Exterior_EventScript_Engineer2::
	msgbox PowerPlant_Exterior_Text_HarnessingPower, MSGBOX_NPC
	end

PowerPlant_Exterior_EventScript_Electabuzz::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ELECTABUZZ, CRY_MODE_WEAK
	msgbox PowerPlant_Exterior_Text_Electabuzz, MSGBOX_NPC
	waitmoncry
	release
	end

PowerPlant_Exterior_EventScript_Magnemite::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGNEMITE, CRY_MODE_WEAK
	msgbox PowerPlant_Exterior_Text_Magnemite, MSGBOX_NPC
	waitmoncry
	release
	end

PowerPlant_Exterior_Movement_TriGruntM2MoveBack:
	face_right
	lock_facing_direction
	walk_left
	step_end

PowerPlant_Exterior_Movement_TriGruntF1MoveBack:
	face_left
	lock_facing_direction
	walk_right
	step_end

PowerPlant_Exterior_Text_TriGruntsStepAside:
	.string "Since you won't take no for an\n"
	.string "answer: Go. You can answer to our\p"
	.string "Admin, Gunter.$"

PowerPlant_Exterior_Text_TriGruntsStepAside1:
	.string "Since you won't take no for an\n"
	.string "answer: Go. You can answer to our\p"
	.string "Admin, Gunter.$"

PowerPlant_Exterior_Text_TriGruntsStepAside2:
	.string "There's still more of us inside.\n"
	.string "Hope you're ready to fight.$"

PowerPlant_Exterior_Text_TriGruntsDefeatM:
	.string "Oh no!$"

PowerPlant_Exterior_Text_TriGruntsDefeatF:
	.string "You beat us good!$"

PowerPlant_Exterior_Text_WhatsAKid:
	.string "What's a kid doing here?\p"
	.string "Oh well, we'll trounce anyone who\n"
	.string "gets in the way of Team Tri!$"

PowerPlant_Exterior_Text_TriGruntM1Intro:
	.string "Scram, kid! Team Tri is here on\n"
	.string "some important business!$"

PowerPlant_Exterior_Text_TriGruntM1Defeated:
	.string "Snot-nosed brat, I'll teach you!\n"
	.string "…Is what I'd say if I had any\p"
	.string "more Pokémon…$"

PowerPlant_Exterior_Text_TriGruntM1Battle:
	.string "Team Tri is harnessing the plant's\n"
	.string "electricity!\p"
	.string "Why?\n"
	.string "I don't know, I'm just a grunt!$"

PowerPlant_Exterior_Text_WhatDoWeDo:
	.string "What do we do? These Trainers just\n"
	.string "took over the whole Power Plant!$"

PowerPlant_Exterior_Text_HarnessingPower:
	.string "Some of them were talking about\n"
	.string "using the plant's power for some-\l"
	.string "thing, but I don't know what for.$"

PowerPlant_Exterior_Text_IHopePokemonOK:
	.string "I hope the Pokémon inside are\n"
	.string "alright…$"

PowerPlant_Exterior_Text_WillTheyTrustUs:
	.string "We work in harmony with the Pokémon\n"
	.string "here at the Plant. Will they still\p"
	.string "trust us after this?$"

PowerPlant_Exterior_Text_Electabuzz:
	.string "Electro: Blblrblbrlblr…$"

PowerPlant_Exterior_Text_Magnemite:
	.string "Platinum: Bzzrt bzzrt…$"
