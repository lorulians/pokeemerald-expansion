TepekCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TepekCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

TepekCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_TEPEK_CITY
	// call Common_EventScript_UpdateBrineyLocation
	end

TepekCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TEPEK_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TepekCity_PokemonCenter_1F_EventScript_Man::
	msgbox TepekCity_PokemonCenter_1F_Text_PokemonHaveValues, MSGBOX_NPC
	end

TepekCity_PokemonCenter_1F_EventScript_Boy::
	msgbox TepekCity_PokemonCenter_1F_Text_DifferentPokemonTimes, MSGBOX_NPC
	end

TepekCity_PokemonCenter_1F_EventScript_Hoothoot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_HOOTHOOT, CRY_MODE_NORMAL
	msgbox TepekCity_Text_Hoothoot, MSGBOX_NPC
	waitmoncry
	release
	end

TepekCity_PokemonCenter_1F_EventScript_Girl::
	msgbox TepekCity_PokemonCenter_1F_Text_HMCut, MSGBOX_NPC
	end

TepekCity_Text_Hoothoot:
	.string "Cedric: Hoohoo!$"

TepekCity_PokemonCenter_1F_Text_PokemonHaveValues:
	.string "Pokémon have special values that\n"
	.string "dictate how powerful they are.\p"
	.string "You can check these values while\n"
	.string "looking at a Pokémon's Summary!$"

TepekCity_PokemonCenter_1F_Text_DifferentPokemonTimes:
	.string "Some Pokémon appear at different\n"
	.string "times of the day!\p"
	.string "My Hoothoot is a nighttime encounter!$"

TepekCity_PokemonCenter_1F_Text_HMCut:
	.string "You'll need Cut to get through to\n"
	.string "Eadich Town. Hideaway Woods is\p"
	.string "filled with thick brush.$"

