TepekCity_Appt_3F_MapScripts::
	.byte 0

TepekCity_Appt_3F_EventScript_Girl::
	lock
	faceplayer
	msgbox TepekCity_Appt_3F_Text_PidgeyBetter, MSGBOX_NPC
	applymovement LOCALID_PIDGEYGIRL, Common_Movement_FaceOriginalDirection
	end

TepekCity_Appt_3F_EventScript_Boy::
	lock
	faceplayer
	msgbox TepekCity_Appt_3F_Text_MurkrowBetter, MSGBOX_NPC
	applymovement LOCALID_MURKROWBOY, Common_Movement_FaceOriginalDirection
	end

TepekCity_Appt_3F_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox TepekCity_Appt_3F_Text_Pidgey, MSGBOX_NPC
	waitmoncry
	applymovement LOCALID_PIDGEY, Common_Movement_FaceOriginalDirection
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

TepekCity_Appt_3F_Text_PidgeyBetter:
	.string "Pidgey is better! Don't you\n"
	.string "see how cute it is when you\p"
	.string "see its little mouth?!$"

TepekCity_Appt_3F_Text_Murkrow:
	.string "Lefty: Kaw kaw!$"

TepekCity_Appt_3F_Text_Pidgey:
	.string "Gusty: Cheepy cheep!$"
