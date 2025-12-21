RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_JudeDad::
	goto_if_unset FLAG_HIDE_TEPEK_APPT_RIVAL, RustboroCity_Flat1_2F_EventScript_JudeDadRoom
	goto_if_set FLAG_HIDE_TEPEK_APPT_RIVAL, RustboroCity_Flat1_2F_EventScript_JudeDadOutside
	end

RustboroCity_Flat1_2F_EventScript_JudeDadRoom::
	msgbox RustboroCity_Flat1_2F_Text_JudesInRoom, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_JudeDadOutside::
	msgbox RustboroCity_Flat1_2F_Text_JudesOutisde, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_JudeSister::
	msgbox RustboroCity_Flat1_2F_Text_BeautifulWeather, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_Jude::
	lockall
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 2, RustboroCity_Flat1_2F_EventScript_JudeWaiting
	goto_if_eq VAR_RUSTBORO_CITY_STATE, 3, RustboroCity_Flat1_2F_EventScript_HeyPlayer
	msgbox RustboroCity_Flat1_2F_Text_CheckingThings, MSGBOX_DEFAULT
    delay 10
	waitmovement 0
	playse SE_PIN
    applymovement LOCALID_TEPEKAPPT_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    delay 10
	faceplayer
	msgbox RustboroCity_Flat1_2F_Text_WhoAreYou, MSGBOX_DEFAULT
	msgbox RustboroCity_Flat1_2F_Text_DeliveryForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_PARCEL
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_JUDE_POKEBALL
	msgbox RustboroCity_Flat1_2F_Text_WeShouldBattle, MSGBOX_DEFAULT
	waitmessage
    delay 5
    applymovement LOCALID_TEPEKAPPT_RIVALDAD, RustboroCity_Flat1_2F_Movement_JudeDadToJude
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_NotInAppt, MSGBOX_NPC
	waitmessage
	applymovement LOCALID_TEPEKAPPT_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	msgbox RustboroCity_Flat1_2F_Text_SorryDad, MSGBOX_NPC
	applymovement LOCALID_TEPEKAPPT_RIVALDAD, RustboroCity_Flat1_2F_Movement_JudeDadToTable
	faceplayer
	msgbox RustboroCity_Flat1_2F_Text_MeetMeOutside, MSGBOX_NPC
	setflag FLAG_HIDE_TEPEK_APPT_RIVAL
	setvar VAR_RUSTBORO_CITY_STATE, 2
	releaseall
	end

RustboroCity_Flat1_2F_EventScript_HeyPlayer::
	faceplayer
	msgbox RustboroCity_Flat1_2F_Text_HeyPlayer, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Flat1_2F_EventScript_JudeWaiting::
	msgbox RustboroCity_Flat1_2F_Text_IllBeWaiting, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Flat1_2F_Text_HeyPlayer:
	.string "Jude: Hey, {PLAYER}{KUN}!$"

RustboroCity_Flat1_2F_Text_IllBeWaiting:
	.string "Jude: I'll be waiting!$"

RustboroCity_Flat1_2F_Movement_JudeDadToJude:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_right
	step_end

RustboroCity_Flat1_2F_Movement_JudeDadToTable:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_right
	step_end

RustboroCity_Flat1_2F_Text_MeetMeOutside:
	.string "Jude: Go outside, I'll meet you\n"
	.string "there and we can battle!$"

RustboroCity_Flat1_2F_Text_SorryDad:
	.string "Jude: Sorry, Dad…$"

RustboroCity_Flat1_2F_Text_NotInAppt:
	.string "Not in the apartment! Go outside\n"
	.string "if you want to battle!$"

RustboroCity_Flat1_2F_Text_JudesInRoom:
	.string "Jude? Oh, he's in the other room.$"

RustboroCity_Flat1_2F_Text_JudesOutisde:
	.string "Jude? Oh, he's outside waiting for\n"
	.string "you.$"

RustboroCity_Flat1_2F_Text_WhoAreYou:
	.string "???: Who are you?\p"
	.string "Oh, {PLAYER}{KUN}? Nice to meet you!\n"
	.string "My name's Jude!$"

RustboroCity_Flat1_2F_Text_DeliveryForMe: 
	.string "Jude: So what's up?\p"
	.string "Oh, a delivery for me? That's gotta\n"
	.string "be my Pokémon!$"

RustboroCity_Flat1_2F_Text_BeautifulWeather:
	.string "The weather is so beautiful today!\n"
	.string "So, why am I spending it inside?\p"
	.string "I don't want to ruin my lovely skin\n"
	.string "of course!$"

RustboroCity_Flat1_2F_Text_WeShouldBattle:
	.string "Jude: Wow! My own Pokémon!\p"
	.string "I know, we should have a battle!$"

RustboroCity_Flat1_2F_Text_CheckingThings:
	.string "???: Okay, I have my Bag ready…$"
