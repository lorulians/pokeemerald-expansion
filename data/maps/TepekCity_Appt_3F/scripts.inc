TepekCity_Appt_3F_MapScripts::
	.byte 0

TepekCity_Appt_3F_EventScript_Girl::
	lock
	faceplayer
	msgbox TepekCity_Appt_3F_Text_TaillowBetter, MSGBOX_NPC
	applymovement LOCALID_TAILLOWGIRL, Common_Movement_FaceOriginalDirection
	end

TepekCity_Appt_3F_EventScript_Boy::
	lock
	faceplayer
	msgbox TepekCity_Appt_3F_Text_MurkrowBetter, MSGBOX_DEFAULT
	applymovement LOCALID_MURKROWBOY, Common_Movement_FaceOriginalDirection
	end

TepekCity_Appt_3F_EventScript_Taillow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TAILLOW, CRY_MODE_NORMAL
	msgbox TepekCity_Appt_3F_Text_Taillow, MSGBOX_NPC
	waitmoncry
	applymovement LOCALID_TAILLOW, Common_Movement_FaceOriginalDirection
	release
	end

TepekCity_Appt_3F_EventScript_Murkrow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox TepekCity_Appt_3F_Text_Murkrow, MSGBOX_NPC
	waitmoncry
	applymovement LOCALID_MURKROW, Common_Movement_FaceOriginalDirection
	release
	end

TepekCity_Appt_3F_Text_MurkrowBetter:
	.string "Murkrow is better! It's little\n"
	.string "hat and tail are so cute!$"

TepekCity_Appt_3F_Text_TaillowBetter:
	.string "Taillow is better! Don't you\n"
	.string "see how cute it is when you\p"
	.string "see its little mouth?!$"

TepekCity_Appt_3F_Text_Murkrow:
	.string "Lefty: Kaw kaw!$"

TepekCity_Appt_3F_Text_Taillow:
	.string "Gusty: Cheepy cheep!$"
