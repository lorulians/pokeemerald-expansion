EadichTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EadichTown_OnTransition
	// map_script MAP_SCRIPT_ON_FRAME_TABLE, EadichTown_OnFrame
	.byte 0

EadichTown_OnTransition:
	setflag FLAG_VISITED_EADICH_TOWN
	end

EadichTown_EventScript_Clerk_1::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EadichTown_Market_Mart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
EadichTown_Market_Mart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	pokemartlistend

EadichTown_EventScript_Clerk_2::
	lock
	faceplayer
	message EadichTown_Text_FarmerClerk
	waitmessage
	pokemart EadichTown_Market_Farmer
	msgbox EadichTown_Text_Farmer_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
EadichTown_Market_Farmer:
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_PECHA_BERRY
	.2byte ITEM_CHERI_BERRY
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_ASPEAR_BERRY
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_REVIVAL_HERB
	pokemartlistend

EadichTown_EventScript_Gentleman::
	msgbox EadichTown_Text_Gentleman, MSGBOX_NPC
	end

EadichTown_EventScript_Beauty::
	msgbox EadichTown_Text_Beauty, MSGBOX_NPC
	end

EadichTown_EventScript_Farmer::
	msgbox EadichTown_Text_Farmer, MSGBOX_NPC
	end

EadichTown_EventScript_FarmersHusband::
	lock
	faceplayer
	goto_if_set FLAG_EADICH_SITRUS_RECEIVED, EadichTown_EventScript_FarmersHusband_BerryGiven
	msgbox EadichTown_Text_FarmersHusband_GiveBerry, MSGBOX_NPC
	giveitem ITEM_SITRUS_BERRY, 1
	setflag FLAG_EADICH_SITRUS_RECEIVED
	release
	end

EadichTown_EventScript_FarmersHusband_BerryGiven::
	msgbox EadichTown_Text_FarmersHusband_BerryGiven, MSGBOX_NPC
	return

EadichTown_EventScript_FarmersMarketSign::
	msgbox EadichTown_Text_FarmersMarketSign, MSGBOX_SIGN
	end

EadichTown_EventScript_TownSign::
	msgbox EadichTown_Text_TownSign, MSGBOX_SIGN
	end

EadichTown_EventScript_GymSign::
	msgbox EadichTown_Text_GymSign, MSGBOX_SIGN
	end

EadichTown_EventScript_TownCenter::
	msgbox EadichTown_Text_TownCenter, MSGBOX_NPC
	end

EadichTown_EventScript_LittleBoy::
	msgbox EadichTown_Text_LittleBoy, MSGBOX_NPC
	end
	
EadichTown_EventScript_Tauros_1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TAUROS, CRY_MODE_NORMAL
	msgbox EadichTown_Text_Tauros_1, MSGBOX_NPC
	waitmoncry
	release
	end
	
EadichTown_EventScript_Tauros_2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TAUROS, CRY_MODE_NORMAL
	msgbox EadichTown_Text_Tauros_2, MSGBOX_NPC
	waitmoncry
	release
	end
	
EadichTown_EventScript_Tauros_3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TAUROS, CRY_MODE_NORMAL
	msgbox EadichTown_Text_Tauros_3, MSGBOX_NPC
	waitmoncry
	release
	end

EadichTown_Text_FarmerClerk:
	.string "Welcome!\p"
	.string "Take a look at my goods.$"

EadichTown_Text_Farmer_PleaseComeAgain:
	.string "Come again!$"

EadichTown_Text_Farmer:
	.string "Marwick lends his Tauros out to\n"
	.string "help prepare new land for crops.\p"
	.string "They're a hard-working bunch of 'mons.$"

EadichTown_Text_Gentleman:
	.string "What a charming little market!\p"
	.string "You don't see these in Monpas!$"

EadichTown_Text_FarmersHusband_GiveBerry:
	.string "Our berries are picked fresh\n"
	.string "every morning! Here, have one\p"
	.string "on the house!$"

EadichTown_Text_FarmersHusband_BerryGiven:
	.string "It's important to water your berries\n"
	.string "every day so they grow big and\p"
	.string "strong, and produce lots of fruit.$"

EadichTown_Text_Beauty:
	.string "I came all this way for a stinky\n"
	.string "little, dinky little farmer's market?\p"
	.string "LA-AME. I'm going home.$"

EadichTown_Text_Tauros_1:
	.string "Mooo!$"

EadichTown_Text_Tauros_2:
	.string "Snort…!$"

EadichTown_Text_Tauros_3:
	.string "Moooo!!$"

EadichTown_Text_FarmersMarketSign:
	.string "Eadich Town Farmer's Market\n"
	.string "Open 24/7$"

EadichTown_Text_TownSign:
	.string "Eadich Town\p"
	.string "“A place full of smiling\n"
	.string "people and home-grown food!”$"

EadichTown_Text_GymSign:
	.string "Eadich Town Pokémon Gym\n"
	.string "Leader: Marwick\p"
	.string "“The Deep-Rooted Grass-type Captain!”$"

EadichTown_Text_TownCenter:
	.string "People from Eadich go\n"
	.string "on vacation to Blutoll,\p"
	.string "but people from Blutoll\n"
	.string "go on vacation to Eadich.\p"
	.string "Isn't that amusing?$"

EadichTown_Text_LittleBoy:
	.string "When I grow up, I'm gonna be\n"
	.string "big and strong like Marwick!$"
