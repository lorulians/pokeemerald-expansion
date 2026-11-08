EadichTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EadichTown_PokemonCenter_OnTransition
	.byte 0

EadichTown_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_EADICH_TOWN
	end

EadichTown_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_EADICH_NURSE
	setvar VAR_0x800A, LOCALID_EADICH_AUDINO
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EadichTown_PokemonCenter_EventScript_Audino::
	call Common_EventScript_PkmnCenterAudino
	waitmessage
	waitbuttonpress
	release
	end

EadichTown_PokemonCenter_EventScript_GothGirl::
	msgbox EadichTown_PokemonCenter_Text_MarwicksGrassTypes, MSGBOX_NPC
	end

EadichTown_PokemonCenter_EventScript_Youngster::
	msgbox EadichTown_PokemonCenter_Text_Confusion, MSGBOX_NPC
	end


EadichTown_PokemonCenter_EventScript_Woman::
	msgbox EadichTown_PokemonCenter_Text_Woman, MSGBOX_NPC
	end


EadichTown_PokemonCenter_EventScript_Snover::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNOVER, CRY_MODE_NORMAL
	msgbox EadichTown_PokemonCenter_Text_Snover, MSGBOX_NPC
	waitmoncry
	release
	end

EadichTown_PokemonCenter_EventScript_Rattata::
	lock
	faceplayer
	applymovement LOCALID_EADICH_PC_RATTATA, EadichTown_PokemonCenter_Movement_RattataHop
	waitmovement
	faceplayer
	delay 5
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_ENCOUNTER
	msgbox EadichTown_PokemonCenter_Text_Rattata, MSGBOX_NPC
	waitmoncry
	release
	end

EadichTown_PokemonCenter_Movement_RattataHop::
	disable_jump_landing_ground_effect
	jump_in_place_right
	disable_jump_landing_ground_effect
	jump_in_place_up
	disable_jump_landing_ground_effect
	jump_in_place_left
	disable_jump_landing_ground_effect
	jump_in_place_down
	step_end

// EadichTown_PokemonCenter_EventScript_Woman::
// 	lock
// 	faceplayer
// 	msgbox EadichTown_PokemonCenter_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
// 	specialvar VAR_RESULT, IsStarterInParty
// 	goto_if_eq VAR_RESULT, TRUE, EadichTown_PokemonCenter_EventScript_SayStarterTypeInfo
// 	release
// 	end

// EadichTown_PokemonCenter_EventScript_SayStarterTypeInfo::
// 	call_if_eq VAR_STARTER_MON, 0, EadichTown_PokemonCenter_EventScript_SayTreeckoType
// 	call_if_eq VAR_STARTER_MON, 1, EadichTown_PokemonCenter_EventScript_SayTorchicType
// 	call_if_eq VAR_STARTER_MON, 2, EadichTown_PokemonCenter_EventScript_SayMudkipType
// 	release
// 	end

// EadichTown_PokemonCenter_EventScript_SayTreeckoType::
// 	msgbox EadichTown_PokemonCenter_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
// 	return

// EadichTown_PokemonCenter_EventScript_SayTorchicType::
// 	msgbox EadichTown_PokemonCenter_Text_TorchicIsFireType, MSGBOX_DEFAULT
// 	return

// EadichTown_PokemonCenter_EventScript_SayMudkipType::
// 	msgbox EadichTown_PokemonCenter_Text_MudkipIsWaterType, MSGBOX_DEFAULT
// 	return

EadichTown_PokemonCenter_Text_MarwicksGrassTypes:
	.string "Marwick's got some strong Grass-\n"
	.string "type Pokémon. Make sure you're\l"
	.string "prepared.$"

EadichTown_PokemonCenter_Text_Confusion:
	.string "I gave my Rattata a Persim berry\n"
	.string "and it cured his Confusion right up!$"

EadichTown_PokemonCenter_Text_Rattata:
	.string "Jerry: Squeak, squeak!$"

EadichTown_PokemonCenter_Text_Woman:
	.string "You'd think an Ice-type like\n"
	.string "Snover would hate the sun,\p"
	.string "but my lovely little guy here\n"
	.string "is also part Grass-type.$"

EadichTown_PokemonCenter_Text_Snover:
	.string "Cypress: Uewuu!$"

