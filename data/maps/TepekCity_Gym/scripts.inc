TepekCity_Gym_MapScripts::
	.byte 0

TepekCity_Gym_EventScript_Ciellus::
	trainerbattle_single TRAINER_CIELLUS, TepekCity_Gym_Text_CiellusIntro, TepekCity_Gym_Text_CiellusDefeat, TepekCity_Gym_EventScript_CiellusDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_DOUBLE_TEAM, TepekCity_Gym_EventScript_GiveDoubleTeam
	msgbox TepekCity_Gym_Text_CiellusPostBattle, MSGBOX_DEFAULT
	release
	end

TepekCity_Gym_EventScript_Pidove::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDOVE, CRY_MODE_NORMAL
	msgbox TepekCity_Text_Pidove, MSGBOX_NPC
	waitmoncry
	release
	end

TepekCity_Text_Pidove:
	.string "Stormy: Coo-oo!$"

TepekCity_Gym_EventScript_CiellusDefeated::
	message TepekCity_Gym_Text_ReceivedFlyingBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox TepekCity_Gym_Text_FlyingBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_TEPEK_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_TEPEK_CITY_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	goto TepekCity_Gym_EventScript_GiveDoubleTeam
	end

TepekCity_Gym_EventScript_GiveDoubleTeam::
	giveitem ITEM_TM_DOUBLE_TEAM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_DOUBLE_TEAM
	msgbox TepekCity_Gym_Text_ExplainDoubleTeam, MSGBOX_DEFAULT
	setvar VAR_TEPEK_CITY_STATE, 7
	release
	end

TepekCity_Gym_EventScript_Kenneth::
	trainerbattle_single TRAINER_KENNETH, TepekCity_Gym_Text_KennethIntro, TepekCity_Gym_Text_KennethDefeat
	msgbox TepekCity_Gym_Text_KennethPostBattle, MSGBOX_AUTOCLOSE
	end

TepekCity_Gym_EventScript_Laz::
	trainerbattle_single TRAINER_LAZ, TepekCity_Gym_Text_LazIntro, TepekCity_Gym_Text_LazDefeat
	msgbox TepekCity_Gym_Text_LazPostBattle, MSGBOX_AUTOCLOSE
	end

TepekCity_Gym_EventScript_Ford::
	trainerbattle_single TRAINER_FORD, TepekCity_Gym_Text_FordIntro, TepekCity_Gym_Text_FordDefeat
	msgbox TepekCity_Gym_Text_FordPostBattle, MSGBOX_AUTOCLOSE
	end

TepekCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_TEPEK_GYM, TepekCity_Gym_EventScript_GymGuidePostVictory
	msgbox TepekCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

TepekCity_Gym_EventScript_GymGuidePostVictory::
	msgbox TepekCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

TepekCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, TepekCity_Gym_EventScript_GymStatueCertified_2
	goto_if_set FLAG_BADGE01_GET, TepekCity_Gym_EventScript_GymStatueCertified
	goto TepekCity_Gym_EventScript_GymStatue
	end

TepekCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, TepekCity_Gym_EventScript_GymStatueCertified_2
	goto_if_set FLAG_BADGE01_GET, TepekCity_Gym_EventScript_GymStatueCertified
	goto TepekCity_Gym_EventScript_GymStatue
	end

TepekCity_Gym_EventScript_GymStatueCertified::
	msgbox TepekCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

TepekCity_Gym_EventScript_GymStatueCertified_2::
	msgbox TepekCity_Gym_Text_GymStatueCertified_2, MSGBOX_DEFAULT
	releaseall
	end

TepekCity_Gym_EventScript_GymStatue::
	msgbox TepekCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

TepekCity_Gym_Text_GymGuideAdvice:
	.string "Hey, future Champ, how's it going?\p"
	.string "Thanks again for restoring power to\n"
	.string "our city.\p"
	.string "Let me give you some advice for your\n"
	.string "Pokémon journey:\p"
	.string "Ciellus uses Flying-type Pokémon.\p"
	.string "The Flying type is grounded by Ice-,\n"
	.string "Rock-, and Electric-type moves, but\l"
	.string "Bug- and Ground- types will struggle!\p"
	.string "Go for it, future Champ!$"

TepekCity_Gym_Text_GymGuidePostVictory:
	.string "You pulled off that battle with\n"
	.string "some spectacular moves!\p"
	.string "Make sure you check out your new\n"
	.string "Flight Badge in your Trainer Card!\p"
	.string "Good luck, future Champ!$"

TepekCity_Gym_Text_KennethIntro:
	.string "Don't let your guard down!\p"
	.string "Gym Trainers are no pushovers!$"

TepekCity_Gym_Text_KennethDefeat:
	.string "I was no match for you…$"

TepekCity_Gym_Text_KennethPostBattle:
	.string "Just wait until you face off against\n"
	.string "our Gym Leader, Ciellus!$"

TepekCity_Gym_Text_LazIntro:
	.string "Can you beat me? You'll have to if\n"
	.string "you want to fight against Ciellus!$"

TepekCity_Gym_Text_LazDefeat:
	.string "Wow, you're pretty good!$"

TepekCity_Gym_Text_LazPostBattle:
	.string "I'm pretty strong, but Ciellus\n"
	.string "is even stronger.$"

TepekCity_Gym_Text_FordIntro:
	.string "I need to let my Pokémon fly free!\n"
	.string "Go, my bird Pokémon!$"

TepekCity_Gym_Text_FordDefeat:
	.string "Yeowch!\n"
	.string "We've been grounded!$"

TepekCity_Gym_Text_FordPostBattle:
	.string "I heard the first Gym in the Johto\n"
	.string "region uses Flying-types too.$"

TepekCity_Gym_Text_CiellusIntro:
	.string "Ciellus: Heya, I'm Ciellus, the Tepek\n"
	.string "City Pokémon Gym Leader.\p"
	.string "I wanted to be just like my Dad and\n"
	.string "train with Flying-type Pokémon!\p"
	.string "Let me show you how to properly take\n"
	.string "flight with Pokémon!$"

TepekCity_Gym_Text_CiellusDefeat:
	.string "Hey, you're pretty good at this!\n"
	.string "My Pokémon were no match for you!\p"
	.string "Here, the Pokémon League's rules say\n"
	.string "that I have to give you this Badge\l"
	.string "for beating me!\p"
	.string "Please accept the official Pokémon\n"
	.string "League Flight Badge!$"

TepekCity_Gym_Text_ReceivedFlyingBadge:
	.string "{PLAYER} received the Flight Badge\n"
	.string "from Ciellus.$"

TepekCity_Gym_Text_FlyingBadgeInfoTakeThis:
	.string "The Flight Badge raises the Speed\n"
	.string "power of your Pokémon.\p"
	.string "It also enables them to use the HM move\n"
	.string "Cut outside of battle.\p"
	.string "Please take this with you, too!$"

TepekCity_Gym_Text_ExplainDoubleTeam:
	.string "That Technical Machine, TM32,\n"
	.string "contains Double Team.\p"
	.string "It raises your Pokémon's evasiveness,\n"
	.string "meaning it'll be harder to hit in\l"
	.string "battle!$"
	.string "If you use a TM, it instantly teaches\n"
	.string "the move to a Pokémon.\p"
	.string "TMs can be used infinitely, so don't\n"
	.string "worry about running out!$"

TepekCity_Gym_Text_CiellusPostBattle:
	.string "Since you are so strong, you should\n"
	.string "challenge other Gym Leaders.\p"
	.string "The next Gym is in Eadich Town through\n"
	.string "Hideaway Woods. Good luck!$"

TepekCity_Gym_Text_GymStatue:
	.string "Tepek City Pokémon Gym$"

TepekCity_Gym_Text_GymStatueCertified:
	.string "Tepek City Pokémon Gym\p"
	.string "Ciellus' Certified Trainers:\n"
	.string "{PLAYER}$"

TepekCity_Gym_Text_GymStatueCertified_2:
	.string "Tepek City Pokémon Gym\p"
	.string "Ciellus' Certified Trainers:\n"
	.string "{PLAYER}$"
