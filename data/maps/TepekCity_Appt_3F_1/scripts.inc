TepekCity_Appt_3F_1_MapScripts::
	.byte 0

TepekCity_Appt_3F_1_EventScript_JudeDad::
	goto_if_unset FLAG_HIDE_TEPEK_APPT_RIVAL, TepekCity_Appt_3F_1_EventScript_JudeDadRoom
	goto_if_set FLAG_HIDE_TEPEK_APPT_RIVAL, TepekCity_Appt_3F_1_EventScript_JudeDadOutside
	end

TepekCity_Appt_3F_1_EventScript_JudeDadRoom::
	msgbox TepekCity_Appt_3F_1_Text_JudesInRoom, MSGBOX_NPC
	end

TepekCity_Appt_3F_1_EventScript_JudeDadOutside::
	msgbox TepekCity_Appt_3F_1_Text_JudesOutisde, MSGBOX_NPC
	end

TepekCity_Appt_3F_1_EventScript_JudeSister::
	msgbox TepekCity_Appt_3F_1_Text_BeautifulWeather, MSGBOX_NPC
	end

TepekCity_Appt_3F_1_EventScript_Jude::
	lockall
	goto_if_eq VAR_TEPEK_CITY_STATE, 2, TepekCity_Appt_3F_1_EventScript_JudeWaiting
	goto_if_eq VAR_TEPEK_CITY_STATE, 3, TepekCity_Appt_3F_1_EventScript_HeyPlayer
	msgbox TepekCity_Appt_3F_1_Text_CheckingThings, MSGBOX_DEFAULT
    delay 10
	waitmovement 0
	playse SE_PIN
    applymovement LOCALID_TEPEKAPPT_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    delay 10
	faceplayer
	msgbox TepekCity_Appt_3F_1_Text_WhoAreYou, MSGBOX_DEFAULT
	msgbox TepekCity_Appt_3F_1_Text_DeliveryForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_PARCEL
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_JUDE_POKEBALL
	msgbox TepekCity_Appt_3F_1_Text_WeShouldBattle, MSGBOX_DEFAULT
	waitmessage
    delay 5
    applymovement LOCALID_TEPEKAPPT_RIVALDAD, TepekCity_Appt_3F_1_Movement_JudeDadToJude
	waitmovement 0
	msgbox TepekCity_Appt_3F_1_Text_NotInAppt, MSGBOX_NPC
	waitmessage
	applymovement LOCALID_TEPEKAPPT_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	msgbox TepekCity_Appt_3F_1_Text_SorryDad, MSGBOX_NPC
	applymovement LOCALID_TEPEKAPPT_RIVALDAD, TepekCity_Appt_3F_1_Movement_JudeDadToTable
	faceplayer
	msgbox TepekCity_Appt_3F_1_Text_MeetMeOutside, MSGBOX_NPC
	setflag FLAG_HIDE_TEPEK_APPT_RIVAL
	setvar VAR_TEPEK_CITY_STATE, 2
	releaseall
	end

TepekCity_Appt_3F_1_EventScript_HeyPlayer::
	faceplayer
	msgbox TepekCity_Appt_3F_1_Text_HeyPlayer, MSGBOX_DEFAULT
	releaseall
	end

TepekCity_Appt_3F_1_EventScript_JudeWaiting::
	msgbox TepekCity_Appt_3F_1_Text_IllBeWaiting, MSGBOX_DEFAULT
	releaseall
	end

TepekCity_Appt_3F_1_Text_HeyPlayer:
	.string "Jude: Hey, {PLAYER}{KUN}!$"

TepekCity_Appt_3F_1_Text_IllBeWaiting:
	.string "Jude: I'll be waiting!$"

TepekCity_Appt_3F_1_Movement_JudeDadToJude:
	disable_jump_landing_ground_effect
	jump_in_place_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_in_place_right
	walk_in_place_right
	step_end

TepekCity_Appt_3F_1_Movement_JudeDadToTable:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_right
	step_end

TepekCity_Appt_3F_1_Text_MeetMeOutside:
	.string "Jude: Go outside, I'll meet you\n"
	.string "there and we can battle!$"

TepekCity_Appt_3F_1_Text_SorryDad:
	.string "Jude: Sorry, Dad…$"

TepekCity_Appt_3F_1_Text_NotInAppt:
	.string "Not in the apartment! Go outside\n"
	.string "if you want to battle!$"

TepekCity_Appt_3F_1_Text_JudesInRoom:
	.string "Jude? Oh, he's in the other room.$"

TepekCity_Appt_3F_1_Text_JudesOutisde:
	.string "Jude? Oh, he's outside waiting for\n"
	.string "you.$"

TepekCity_Appt_3F_1_Text_WhoAreYou:
	.string "???: Who are you?\p"
	.string "Oh, {PLAYER}{KUN}? Nice to meet you!\n"
	.string "My name's Jude!$"

TepekCity_Appt_3F_1_Text_DeliveryForMe: 
	.string "Jude: So what's up?\p"
	.string "Oh, a delivery for me? That's gotta\n"
	.string "be my Pokémon!$"

TepekCity_Appt_3F_1_Text_BeautifulWeather:
	.string "The weather is so beautiful today!\n"
	.string "So, why am I spending it inside?\p"
	.string "I don't want to ruin my lovely skin\n"
	.string "of course!$"

TepekCity_Appt_3F_1_Text_WeShouldBattle:
	.string "Jude: Wow! My own Pokémon!\p"
	.string "I know, we should have a battle!$"

TepekCity_Appt_3F_1_Text_CheckingThings:
	.string "???: Okay, I have my Bag ready…$"
