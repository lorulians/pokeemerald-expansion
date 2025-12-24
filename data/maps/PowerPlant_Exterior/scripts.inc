PowerPlant_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PowerPlant_Exterior_OnTransition
	.byte 0

PowerPlant_Exterior_OnTransition:
	setflag FLAG_VISITED_POWER_PLANT
	call_if_eq VAR_POWER_PLANT_RESTORED, 1, PowerPlant_Exterior_SetGruntPosAside
	end

PowerPlant_Exterior_SetGruntPosAside::
	setobjectxy LOCALID_POWERPLANT_OUTDOOR_TRIGRUNTM_2, 19, 16
	setobjectmovementtype LOCALID_POWERPLANT_OUTDOOR_TRIGRUNTM_2, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxy LOCALID_POWERPLANT_OUTDOOR_TRIGRUNTF_1, 22, 16
	setobjectmovementtype LOCALID_POWERPLANT_OUTDOOR_TRIGRUNTF_1, MOVEMENT_TYPE_FACE_LEFT
	return

PowerPlant_Exterior_EventScript_TriGruntM1::
	trainerbattle_single TRAINER_GRUNT1_POWER_PLANT, PowerPlant_Exterior_Text_TriGruntM1Intro, PowerPlant_Exterior_Text_TriGruntM1Defeated
	msgbox PowerPlant_Exterior_Text_TriGruntM1Battle, MSGBOX_AUTOCLOSE
	end

PowerPlant_Exterior_EventScript_TriGruntTrigger::
	lockall
	applymovement LOCALID_POWERPLANT_OUTDOOR_TRIGRUNTM_2, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	msgbox PowerPlant_Exterior_Text_WhatsAKid, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNTS_POWER_PLANT, PowerPlant_Exterior_Text_TriGruntsDefeat
	msgbox PowerPlant_Exterior_Text_TriGruntsStepAside, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_POWERPLANT_OUTDOOR_TRIGRUNTM_2, PowerPlant_Exterior_Movement_TriGruntM2MoveBack
	applymovement LOCALID_POWERPLANT_OUTDOOR_TRIGRUNTF_1, PowerPlant_Exterior_Movement_TriGruntF1MoveBack
	waitmovement 0
	setvar VAR_POWER_PLANT_RESTORED, 1
	releaseall
	end

PowerPlant_Exterior_EventScript_TriGruntM2::
	msgbox PowerPlant_Exterior_Text_TriGruntsStepAside1, MSGBOX_AUTOCLOSE
	end

PowerPlant_Exterior_EventScript_TriGruntF1::
	msgbox PowerPlant_Exterior_Text_TriGruntsStepAside2, MSGBOX_AUTOCLOSE
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

PowerPlant_Exterior_Text_TriGruntsDefeat:
	.string "Oh no!$"

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
	.string "more Pokémon$"

PowerPlant_Exterior_Text_TriGruntM1Battle:
	.string "Team Tri is harnessing the plant's\n"
	.string "electricity!\p"
	.string "Why?\n"
	.string "I don't know, I'm just a grunt!$"
