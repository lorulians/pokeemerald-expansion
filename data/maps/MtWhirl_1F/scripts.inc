MtWhirl_1F_MapScripts::
	.byte 0

MtWhirl_1F_EventScript_Jesus::
	trainerbattle_single TRAINER_JESUS, MtWhirl_1F_Text_JesusIntro, MtWhirl_1F_Text_JesusDefeated
	msgbox MtWhirl_1F_Text_JesusPostBattle, MSGBOX_AUTOCLOSE
	end

MtWhirl_1F_EventScript_Topher::
	trainerbattle_single TRAINER_TOPHER, MtWhirl_1F_Text_TopherIntro, MtWhirl_1F_Text_TopherDefeated
	msgbox MtWhirl_1F_Text_TopherPostBattle, MSGBOX_AUTOCLOSE
	end

MtWhirl_1F_Text_JesusIntro:

MtWhirl_1F_Text_TopherIntro:

MtWhirl_1F_Text_JesusDefeated:

MtWhirl_1F_Text_TopherDefeated:

MtWhirl_1F_Text_JesusPostBattle:

MtWhirl_1F_Text_TopherPostBattle:

