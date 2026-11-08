EadichTown_House2_MapScripts::
	.byte 0

EadichTown_House2_EventScript_TwinA::
	msgbox EadichTown_House2_Text_LunchTime, MSGBOX_NPC
	end

EadichTown_House2_EventScript_TwinB::
	msgbox EadichTown_House2_Text_CantSitStill, MSGBOX_NPC
	end

EadichTown_House2_EventScript_Man::
	msgbox EadichTown_House2_Text_VacationTime, MSGBOX_NPC
	end

EadichTown_House2_EventScript_Woman::
	msgbox EadichTown_House2_Text_Cooking, MSGBOX_NPC
	end

EadichTown_House2_Text_LunchTime:
	.string "Lunch time, lunch time!\p"
	.string "I helped Mommy pick the vegetables\n"
	.string "for the salad!$"

EadichTown_House2_Text_CantSitStill:
	.string "I can't sit still! I wanna go\n"
	.string "play outside!$"

EadichTown_House2_Text_VacationTime:
	.string "I took some vacation time so\n"
	.string "I could spend time with my wife\l"
	.string "and kids.\p"
	.string "I love my family!$"

EadichTown_House2_Text_Cooking:
	.string "I didn't feel like cooking a\n"
	.string "whole meal today, so me and\p"
	.string "my daughter went and picked\n"
	.string "vegetables from the garden.$"

