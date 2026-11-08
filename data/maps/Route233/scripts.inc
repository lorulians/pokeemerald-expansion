Route233_MapScripts::
	.byte 0

Route233_EventScript_LocSign::
	msgbox Route233_Text_LocSign, MSGBOX_SIGN
	end

Route233_EventScript_BerryFarmer::
	msgbox Route233_Text_BerryFarmer, MSGBOX_NPC
	end

Route233_EventScript_FencedFarmer::
	msgbox Route233_Text_FencedFarmer, MSGBOX_NPC
	end

Route233_EventScript_Sofia::
	trainerbattle_single TRAINER_SOFIA, Route233_Text_SofiaIntro, Route233_Text_SofiaDefeated
	msgbox Route233_Text_SofiaPostBattle, MSGBOX_DEFAULT
	release
	end

Route233_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, Route233_Text_MarkIntro, Route233_Text_MarkDefeated
	msgbox Route233_Text_MarkPostBattle, MSGBOX_DEFAULT
	release
	end

Route233_EventScript_Garth::
	trainerbattle_single TRAINER_GARTH, Route233_Text_GarthIntro, Route233_Text_GarthDefeated
	msgbox Route233_Text_GarthPostBattle, MSGBOX_DEFAULT
	release
	end

Route233_EventScript_Beau::
	trainerbattle_single TRAINER_BEAU, Route233_Text_BeauIntro, Route233_Text_BeauDefeated
	msgbox Route233_Text_BeauPostBattle, MSGBOX_DEFAULT
	release
	end

Route233_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, Route233_Text_BlakeIntro, Route233_Text_BlakeDefeated
	msgbox Route233_Text_BlakePostBattle, MSGBOX_DEFAULT
	release
	end
	
Route233_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox Route233_Text_Miltank, MSGBOX_NPC
	waitmoncry
	release
	end

Route233_Text_LocSign:
	.string "Route 233\n"
	.string "{UP_ARROW} Hideaway Woods\l"
	.string "{DOWN_ARROW} Eadich Town$"

Route233_Text_BerryFarmer:
	.string "Running a farm is hard work!\p"
	.string "More than half of all new farms don't\n"
	.string "make it past the first year.$"

Route233_Text_FencedFarmer:
	.string "Nothing is more rewarding than seeing\n"
	.string "happy Pokémon faces every morning!$"

Route233_Text_Miltank:
	.string "Moo!$"
