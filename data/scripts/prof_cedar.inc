ProfCedar_EventScript_RatePokedexOrRegister::
	lock
	faceplayer
	goto_if_unset FLAG_HAS_MATCH_CALL, ProfCedar_EventScript_AskRatePokedex
	goto_if_unset FLAG_ENABLE_PROF_CEDAR_MATCH_CALL, EventScript_RegisterProfCedar

ProfCedar_EventScript_AskRatePokedex::
	msgbox gCedarDexRatingText_AreYouCurious, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ProfCedar_EventScript_DeclineRating
	call ProfCedar_EventScript_RatePokedex
	release
	end

ProfCedar_EventScript_DeclineRating::
	msgbox gCedarDexRatingText_Cancel, MSGBOX_DEFAULT
	release
	end

ProfCedar_EventScript_ShowRatingMessage::
	copyvar VAR_0x8004, VAR_0x8009
	special ShowPokedexRatingMessage
	waitmessage
	waitbuttonpress
	return

ProfCedar_EventScript_RatePokedex::
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008  @ Num Hoenn seen
	buffernumberstring STR_VAR_2, VAR_0x8009  @ Num Hoenn caught
	msgbox gCedarDexRatingText_SoYouveSeenAndCaught, MSGBOX_DEFAULT
	call ProfCedar_EventScript_ShowRatingMessage
	goto_if_eq VAR_0x800A, 0, Common_EventScript_NopReturn  @ National dex not enabled
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring STR_VAR_1, VAR_0x8008  @ Num National seen
	buffernumberstring STR_VAR_2, VAR_0x8009  @ Num National caught
	msgbox gCedarDexRatingText_OnANationwideBasis, MSGBOX_DEFAULT
	return
