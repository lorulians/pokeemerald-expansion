RustboroCity_House2_MapScripts::
	.byte 0

RustboroCity_House2_EventScript_PokefanF::
	msgbox RustboroCity_House2_Text_TakingCareOfGrandpa, MSGBOX_NPC
	end

RustboroCity_House2_EventScript_Grandpa::
	msgbox RustboroCity_House2_Text_Stories, MSGBOX_NPC
	end

RustboroCity_House2_EventScript_Rattata::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox RustboroCity_Text_Rattata, MSGBOX_NPC
	waitmoncry
	release
	end

RustboroCity_House2_EventScript_LittleGirl::
	msgbox RustboroCity_House2_Text_ILoveStories, MSGBOX_NPC
	end

RustboroCity_Text_Rattata:
	.string "Yvette: Ratatata!!$"

RustboroCity_House2_Text_TakingCareOfGrandpa:
	.string "My father moved in recently so we\n"
	.string "could take care of him.$"

RustboroCity_House2_Text_Stories:
	.string "Alright kiddo, this one is about\n"
	.string "Zapdos, guardian of eastern Sansuba…$"

RustboroCity_House2_Text_ILoveStories:
	.string "My Pawpaw tells the best stories!$"

