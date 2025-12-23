Route231_MapScripts::
	.byte 0

Route231_EventScript_Youngster::
	msgbox Route231_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route231_EventScript_Boy::
	msgbox Route231_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route231_EventScript_RouteSign::
	msgbox Route231_Text_RouteSign, MSGBOX_SIGN
	end

Route231_Text_TakeTiredPokemonToPokeCenter:
	.string "If your Pokémon's HP gets low, take\n"
	.string "them to a Pokémon Center!\p"
	.string "There's a Pokémon Center in Tepek\n"
	.string "City south of here.$"

Route231_Text_WildPokemonInTallGrass:
	.string "Wild Pokémon will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch Pokémon, you have\n"
	.string "to go into the tall grass and search.$"

Route231_Text_RouteSign:
	.string "Route 231\n"
	.string "{UP_ARROW} Redge Town\l"
	.string "{DOWN_ARROW} Tepek City$"

