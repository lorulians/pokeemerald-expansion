MtWhirl_1F_Clearing_MapScripts::
	.byte 0

MtWhirl_1F_Clearing_EventScript_LittleKid::
	lock
	faceplayer
	goto_if_unset FLAG_MTWHIRL_CLEARING_CLOAK_RECEIVED, MtWhirl_1F_Clearing_EventScript_KidGiveCloak
	goto_if_set FLAG_MTWHIRL_CLEARING_CLOAK_RECEIVED, MtWhirl_1F_Clearing_EventScript_KidGaveCloak
	release
	end

MtWhirl_1F_Clearing_EventScript_Chandler::
	trainerbattle_single TRAINER_CHANDLER, MtWhirl_1F_Clearing_Text_ChandlerIntro, MtWhirl_1F_Clearing_Text_ChandlerDefeated
	msgbox MtWhirl_1F_Clearing_Text_ChandlerPostBattle, MSGBOX_AUTOCLOSE
	end

MtWhirl_1F_Clearing_EventScript_Casey::
	trainerbattle_single TRAINER_CASEY, MtWhirl_1F_Clearing_Text_CaseyIntro, MtWhirl_1F_Clearing_Text_CaseyDefeated
	msgbox MtWhirl_1F_Clearing_Text_CaseyPostBattle, MSGBOX_AUTOCLOSE
	end

MtWhirl_1F_Clearing_EventScript_KidGiveCloak::
	msgbox MtWhirl_1F_Clearing_Text_MyHidingSpot, MSGBOX_NPC
	giveitem ITEM_COVERT_CLOAK, 1
	setflag FLAG_MTWHIRL_CLEARING_CLOAK_RECEIVED
	return

MtWhirl_1F_Clearing_EventScript_KidGaveCloak::
	msgbox MtWhirl_1F_Clearing_Text_PleaseDontTell, MSGBOX_NPC
	return

MtWhirl_1F_Clearing_Text_ChandlerIntro:
	.string "Feel that chill in the air?\n"
	.string "How about warming up with a\l"
	.string "battle?$"

MtWhirl_1F_Clearing_Text_ChandlerDefeated:
	.string "Nice and toasty!$"

MtWhirl_1F_Clearing_Text_ChandlerPostBattle:
	.string "The trees up on Mt. Whirl make\n"
	.string "for some great firewood!$"

MtWhirl_1F_Clearing_Text_CaseyIntro:
	.string "It only goes up from here!$"

MtWhirl_1F_Clearing_Text_CaseyDefeated:
	.string "Guess I'm going down, though!$"

MtWhirl_1F_Clearing_Text_CaseyPostBattle:
	.string "This is the way to Snotop City\n"
	.string "and the Snotop Research Facility.$"

MtWhirl_1F_Clearing_Text_MyHidingSpot:
	.string "Oh no, you found my secret hiding\n"
	.string "spot! If I give you this, will you\l"
	.string "promise not to tell anyone?$"

MtWhirl_1F_Clearing_Text_PleaseDontTell:
	.string "Alright, since I gave you that,\n"
	.string "that means you promise!$"
