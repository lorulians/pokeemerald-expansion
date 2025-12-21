TriHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TriHideout_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, TriHideout_B1F_OnTransition
	.byte 0

TriHideout_B1F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TriHideout_B1F_EventScript_TryRemoveElectrode
	end

TriHideout_B1F_EventScript_TryRemoveElectrode::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

TriHideout_B1F_OnTransition:
	call_if_unset FLAG_DEFEATED_ELECTRODE_1_TRI_HIDEOUT, TriHideout_B1F_EventScript_ShowElectrode1
	call_if_unset FLAG_DEFEATED_ELECTRODE_2_TRI_HIDEOUT, TriHideout_B1F_EventScript_ShowElectrode2
	end

TriHideout_B1F_EventScript_ShowElectrode1::
	clearflag FLAG_HIDE_TRI_HIDEOUT_B1F_ELECTRODE_1
	return

TriHideout_B1F_EventScript_ShowElectrode2::
	clearflag FLAG_HIDE_TRI_HIDEOUT_B1F_ELECTRODE_2
	return

TriHideout_B1F_EventScript_Electrode1::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TriHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TriHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TriHideout_B1F_EventScript_DefeatedElectrode1
	setflag FLAG_DEFEATED_ELECTRODE_1_TRI_HIDEOUT
	release
	end

TriHideout_B1F_EventScript_DefeatedElectrode1::
	setflag FLAG_DEFEATED_ELECTRODE_1_TRI_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

TriHideout_B1F_EventScript_Electrode2::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TriHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TriHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TriHideout_B1F_EventScript_DefeatedElectrode2
	setflag FLAG_DEFEATED_ELECTRODE_2_TRI_HIDEOUT
	release
	end

TriHideout_B1F_EventScript_DefeatedElectrode2::
	setflag FLAG_DEFEATED_ELECTRODE_2_TRI_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

TriHideout_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_TRI_HIDEOUT_2, TriHideout_B1F_Text_Grunt2Intro, TriHideout_B1F_Text_Grunt2Defeat, TriHideout_B1F_EventScript_Grunt2Defeated
	msgbox TriHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

TriHideout_B1F_EventScript_Grunt2Defeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox TriHideout_B1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

TriHideout_B1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_TRI_HIDEOUT_3, TriHideout_B1F_Text_Grunt3Intro, TriHideout_B1F_Text_Grunt3Defeat, TriHideout_B1F_EventScript_Grunt3Defeated
	msgbox TriHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

TriHideout_B1F_EventScript_Grunt3Defeated::
	msgbox TriHideout_B1F_Text_Grunt3PostBattle, MSGBOX_DEFAULT
	release
	end

TriHideout_B1F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_TRI_HIDEOUT_5, TriHideout_B1F_Text_Grunt5Intro, TriHideout_B1F_Text_Grunt5Defeat
	msgbox TriHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

TriHideout_B1F_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_TRI_HIDEOUT_7, TriHideout_B1F_Text_Grunt7Intro, TriHideout_B1F_Text_Grunt7Defeat
	msgbox TriHideout_B1F_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

TriHideout_B1F_Text_Grunt2Intro:
	.string "If you want to know the secret about\n"
	.string "our HIDEOUT, you have me to beat!$"

TriHideout_B1F_Text_Grunt2Defeat:
	.string "I can't win at all…$"

TriHideout_B1F_Text_Grunt2PostBattle:
	.string "Our HIDEOUT's secret?\p"
	.string "Well, let's just say…\n"
	.string "There's a submarine at the far end!\p"
	.string "But, by now…\n"
	.string "Kekekeke…$"

TriHideout_B1F_Text_Grunt3Intro:
	.string "Fuel supply loaded A-OK!\n"
	.string "In-cruise snacks loaded A-OK!\p"
	.string "Nothing left to do but KO a pesky\n"
	.string "meddler!$"

TriHideout_B1F_Text_Grunt3Defeat:
	.string "I took a serious licking!$"

TriHideout_B1F_Text_Grunt3PostBattle:
	.string "Humph!\n"
	.string "This was supposed to happen!\p"
	.string "My mission was to just hold you up!$"

TriHideout_B1F_Text_Grunt5Intro:
	.string "Yawn… Keeping watch over the\n"
	.string "HIDEOUT bores me. I'll take you on.$"

TriHideout_B1F_Text_Grunt5Defeat:
	.string "Yawn…\n"
	.string "Oh, I lost…$"

TriHideout_B1F_Text_Grunt5PostBattle:
	.string "If you scurry too much, other TEAM\n"
	.string "TRI members might get you.$"

TriHideout_B1F_Text_Grunt7Intro:
	.string "Hey!\n"
	.string "You there!\p"
	.string "Which do you think is cooler?\n"
	.string "TEAM TRI's uniform or TEAM MAGMA's?$"

TriHideout_B1F_Text_Grunt7Defeat:
	.string "I lost in a cool way…$"

TriHideout_B1F_Text_Grunt7PostBattle:
	.string "If you have a cool uniform, you look\n"
	.string "good even in a loss, don't you think?$"
