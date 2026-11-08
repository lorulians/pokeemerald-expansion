EadichTown_House1_MapScripts::
	.byte 0

EadichTown_House1_EventScript_OldMan::
	msgbox EadichTown_House1_Text_UsedToTravel, MSGBOX_NPC
	end

EadichTown_House1_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_unset FLAG_ITEM_EADICH_OLDWOMAN_GET, EadichTown_House1_EventScript_OldWoman_ItemDontGot
	goto_if_set FLAG_ITEM_EADICH_OLDWOMAN_GET, EadichTown_House1_EventScript_OldWoman_ItemGot
	release
	end

EadichTown_House1_EventScript_OldWoman_ItemDontGot::
	msgbox EadichTown_House1_Text_GotThisFromSomewhere, MSGBOX_NPC
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ITEM_EADICH_OLDWOMAN_GET
	msgbox EadichTown_House1_Text_GotThisFromSomewhere, MSGBOX_NPC
	release
	end

EadichTown_House1_EventScript_OldWoman_ItemGot::
	msgbox EadichTown_House1_Text_GotThisFromSomewhere, MSGBOX_NPC
	release
	end

EadichTown_House1_Text_UsedToTravel:
	.string "Oh, to be young and able to\n"
	.string "travel again…$"

EadichTown_House1_Text_TravelingFar:
	.string "Have you traveled far, kiddo?\n"
	.string "Here, have one of these.$"

EadichTown_House1_Text_GotThisFromSomewhere:
	.string "I picked this up in my traveling\n"
	.string "days, but never found a use for it.\p"
	.string "Maybe it'll be of some worth to you.$"

