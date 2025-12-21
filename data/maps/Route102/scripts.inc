Route102_MapScripts::
	.byte 0

Route102_EventScript_Girl::
	msgbox Route102_Text_Ledges, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Shana::
	trainerbattle_single TRAINER_SHANA, Route102_Text_ShanaIntro, Route102_Text_ShanaDefeated
	msgbox Route102_Text_ShanaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA_1, Route102_Text_ClarissaIntro, Route102_Text_ClarissaDefeated, Route102_EventScript_ClarissaRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_ClarissaRematch
	setvar VAR_0x8004, TRAINER_CLARISSA_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_ClarissaTryRegister
	msgbox Route102_Text_ClarissaPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_ClarissaRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_ClarissaRegisterMatchCall
	release
	end

Route102_EventScript_ClarissaRegisterMatchCall::
	msgbox Route102_Text_ClarissaRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CLARISSA_1
	release
	end

Route102_EventScript_ClarissaTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_ClarissaRegister
	msgbox Route102_Text_ClarissaPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_ClarissaRegister::
	msgbox Route102_Text_ClarissaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CLARISSA_1
	release
	end

Route102_EventScript_ClarissaRematch::
	trainerbattle_rematch TRAINER_CLARISSA_1, Route102_Text_ClarissaRematchIntro, Route102_Text_ClarissaRematchDefeated
	msgbox Route102_Text_ClarissaRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Mick::
	trainerbattle_single TRAINER_MICK, Route102_Text_MickIntro, Route102_Text_MickDefeated
	msgbox Route102_Text_MickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, Route102_Text_EricIntro, Route102_Text_EricDefeated
	msgbox Route102_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_TriGruntF::
	trainerbattle_single TRAINER_GRUNT_ROUTE_232, Route232_Text_TriGruntFIntro, Route232_Text_TriGruntFDefeated
	msgbox Route232_Text_TriGruntFPostBattle, MSGBOX_AUTOCLOSE
	goto_if_unset FLAG_HIDE_ROUTE_232_TRIGRUNT, Route102_EventScript_HideGrunt
	end

Route102_EventScript_HideGrunt::
	setflag FLAG_HIDE_ROUTE_232_TRIGRUNT
	end

Route102_Text_Ledges:
	.string "You can jump down ledges to get to\n"
	.string "places quicker!\p"
	.string "Watch out, though. Ledges are a\n"
	.string "one-way trip.$"

Route102_Text_CatchWholeBunchOfPokemon:
	.string "I'm going to catch every Pokémon\n"
	.string "in the whole region, watch me!$"

Route102_Text_RouteSignOldale:
	.string "Route 232\n"
	.string "{LEFT_ARROW} Tepek City\l"
	.string "{RIGHT_ARROW} Power Plant$"
