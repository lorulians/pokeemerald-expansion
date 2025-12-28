Route232_MapScripts::
	.byte 0

Route232_EventScript_Girl::
	msgbox Route232_Text_Ledges, MSGBOX_NPC
	end

Route232_EventScript_RouteSignOldale::
	msgbox Route232_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route232_EventScript_Boy::
	msgbox Route232_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route232_EventScript_Shana::
	trainerbattle_single TRAINER_SHANA, Route232_Text_ShanaIntro, Route232_Text_ShanaDefeated
	msgbox Route232_Text_ShanaPostBattle, MSGBOX_AUTOCLOSE
	end

Route232_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA, Route232_Text_ClarissaIntro, Route232_Text_ClarissaDefeated
	msgbox Route232_Text_ClarissaPostBattle, MSGBOX_DEFAULT
	release
	end

Route232_EventScript_Mick::
	trainerbattle_single TRAINER_MICK, Route232_Text_MickIntro, Route232_Text_MickDefeated
	msgbox Route232_Text_MickPostBattle, MSGBOX_AUTOCLOSE
	end

Route232_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, Route232_Text_EricIntro, Route232_Text_EricDefeated
	msgbox Route232_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

Route232_EventScript_TriGruntF::
	trainerbattle_single TRAINER_GRUNT_ROUTE_232, Route232_Text_TriGruntFIntro, Route232_Text_TriGruntFDefeated
	msgbox Route232_Text_TriGruntFPostBattle, MSGBOX_AUTOCLOSE
	end

Route232_Text_Ledges:
	.string "You can jump down ledges to get to\n"
	.string "places quicker!\p"
	.string "Watch out, though. Ledges are a\n"
	.string "one-way trip.$"

Route232_Text_CatchWholeBunchOfPokemon:
	.string "I'm going to catch every Pokémon\n"
	.string "in the whole region, watch me!$"

Route232_Text_RouteSignOldale:
	.string "Route 232\n"
	.string "{LEFT_ARROW} Tepek City\l"
	.string "{RIGHT_ARROW} Power Plant$"
