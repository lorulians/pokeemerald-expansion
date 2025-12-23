TepekCity_House_MapScripts::
	.byte 0

TepekCity_House_EventScript_PokefanF::
	msgbox TepekCity_House_Text_TakingCareOfGrandpa, MSGBOX_NPC
	end

TepekCity_House_EventScript_Grandpa::
	msgbox TepekCity_House_Text_Stories, MSGBOX_NPC
	end

TepekCity_House_EventScript_Rattata::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox TepekCity_Text_Rattata, MSGBOX_NPC
	waitmoncry
	release
	end

TepekCity_House_EventScript_LittleGirl::
	msgbox TepekCity_House_Text_ILoveStories, MSGBOX_NPC
	end

TepekCity_Text_Rattata:
	.string "Yvette: Ratatata!!$"

TepekCity_House_Text_TakingCareOfGrandpa:
	.string "My father moved in recently so we\n"
	.string "could take care of him.$"

TepekCity_House_Text_Stories:
	.string "Alright kiddo, this one is about\n"
	.string "Zapdos, guardian of eastern Sansuba…$"

TepekCity_House_Text_ILoveStories:
	.string "My Pawpaw tells the best stories!$"

