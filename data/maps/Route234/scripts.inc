Route234_MapScripts::
	// map_script MAP_SCRIPT_ON_TRANSITION, Route234_OnTransition
	// map_script MAP_SCRIPT_ON_LOAD, Route234_OnLoad
	.byte 0

// Route234_OnTransition:
	// end

// Route234_OnLoad:
	// call_if_set FLAG_SYS_GAME_CLEAR, Route234_EventScript_OpenAlteringCave
	// end

// Route234_EventScript_OpenAlteringCave::
	// setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
	// setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
	// return

Route234_EventScript_Man::
	msgbox Route234_Text_SnotopAndMonpas, MSGBOX_NPC
	end

Route234_EventScript_RouteSign::
	msgbox Route234_Text_RouteSign, MSGBOX_SIGN
	end

Route234_EventScript_Jonty::
	trainerbattle_single TRAINER_JONTY, Route234_Text_JontyIntro, Route234_Text_JontyDefeated
	msgbox Route234_Text_JontyPostBattle, MSGBOX_AUTOCLOSE
	end

Route234_EventScript_Hugo::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route234_EventScript_HugoMaleBattle
	goto_if_eq VAR_RESULT, FEMALE, Route234_EventScript_HugoFemaleBattle

Route234_EventScript_HugoMaleBattle::
	trainerbattle_single TRAINER_HUGO, Route234_Text_HugoIntroMale, Route234_Text_HugoDefeated
	msgbox Route234_Text_HugoPostBattle, MSGBOX_AUTOCLOSE
	end

Route234_EventScript_HugoFemaleBattle::
	trainerbattle_single TRAINER_HUGO, Route234_Text_HugoIntroMale, Route234_Text_HugoDefeated
	msgbox Route234_Text_HugoPostBattle, MSGBOX_AUTOCLOSE
	end

Route234_EventScript_Todd::
	trainerbattle_single TRAINER_TODD, Route234_Text_ToddIntro, Route234_Text_ToddDefeated
	msgbox Route234_Text_ToddPostBattle, MSGBOX_AUTOCLOSE
	end

Route234_EventScript_Tria::
	trainerbattle_double TRAINER_TRIA_AND_IMA, Route234_Text_TriaImaIntro, Route234_Text_TriaImaDefeated, Route234_Text_ImaNotEnoughPokemon
	msgbox Route234_Text_TriaPostBattle, MSGBOX_AUTOCLOSE
	end

Route234_EventScript_Ima::
	trainerbattle_double TRAINER_TRIA_AND_IMA, Route234_Text_TriaImaIntro, Route234_Text_TriaImaDefeated, Route234_Text_ImaNotEnoughPokemon
	msgbox Route234_Text_ImaPostBattle, MSGBOX_AUTOCLOSE
	end

Route234_EventScript_Engineer1::
	msgbox Route234_Text_RockSlide, MSGBOX_NPC
	end

Route234_EventScript_Engineer2::
	msgbox Route234_Text_WorkingOurHardest, MSGBOX_NPC
	end

Route234_EventScript_FishingGuy::
	lock
	goto_if_set FLAG_RECEIVED_OLD_ROD, Route234_EventScript_HowsFishing
	msgbox Route234_Text_LandedBigFish, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_FISHINGGUY_OLDROD, Common_Movement_Delay48
	waitmovement 0
	playse SE_PIN
    applymovement LOCALID_FISHINGGUY_OLDROD, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_FISHINGGUY_OLDROD, Common_Movement_Delay48
    waitmovement 0
	faceplayer
	msgbox Route234_Text_WantToFishToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route234_EventScript_GiveOldRod
	goto_if_eq VAR_RESULT, NO, Route234_EventScript_DontWantToFish
	msgbox Route234_Text_FishingAdvice, MSGBOX_DEFAULT
	release
	end

Route234_EventScript_GiveOldRod::
	msgbox Route234_Text_TakeRod, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox Route234_Text_FishingAdvice, MSGBOX_DEFAULT
	release
	end

Route234_EventScript_DontWantToFish::
	msgbox Route234_Text_ComeBackLaterThen, MSGBOX_DEFAULT
	release
	end

Route234_EventScript_HowsFishing::
	faceplayer
	message Route234_Text_HowsFishing
	waitmessage
	multichoice 20, 8, MULTI_HOWS_FISHING, TRUE
	goto_if_eq VAR_RESULT, 0, Route234_EventScript_FishingExcellent
	goto_if_eq VAR_RESULT, 1, Route234_EventScript_FishingNotSoGood
	end

Route234_EventScript_FishingExcellent::
	msgbox Route234_Text_CatchSomethingGood, MSGBOX_DEFAULT
	release
	end

Route234_EventScript_FishingNotSoGood::
	msgbox Route234_Text_FishingAdvice, MSGBOX_DEFAULT
	release
	end

Route234_EventScript_Machop::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	msgbox Route234_Text_Machop, MSGBOX_NPC
	waitmoncry
	release
	end

Route234_Text_RockSlide:
	.string "Watch out, there's been a\n"
	.string "rock slide.\p"
	.string "The path to Mt. Whirl is\n"
	.string "blocked off at this time.$"

Route234_Text_WorkingOurHardest:
	.string "We're working our hardest to\n"
	.string "clear the rock slide!\p"
	.string "Don't you worry!$"

Route234_Text_Machop:
	.string "Bruiser: Chop, Chop! Machop!$"

Route234_Text_LandedBigFish:
	.string "Wahoo! I just landed a massive\n"
	.string "Magikarp!$"

Route234_Text_WantToFishToo:
	.string "Hey, want to fish, too?\n"
	.string "They're biting like mad!$"

Route234_EventScript_GiveOldRod:
	.string "Great! Here, take one of\n"
	.string "my Old Rods.\p"
	.string "Don't worry, I got plenty!$"

Route234_Text_ComeBackLaterThen:
	.string "No? Oh well, come back later\n"
	.string "when you change your mind.\p"
	.string "I'll be here catching more\n"
	.string "Magikarp!$"

Route234_Text_FishingAdvice:
	.string "If you Register your Rod in\n"
	.string "your Bag, you can pull it out\p"
	.string "without having to reopen your\n"
	.string "Bag every single time.$"

Route234_Text_HowsFishing:
	.string "How's your fishing going?$"

Route234_Text_CatchSomethingGood:
	.string "That's amazing!\p"
	.string "Catch something good!$"

Route234_Text_SnotopAndMonpas:
	.string "If you keep going west, you'll\n"
	.string "reach Mt. Whirl.\p"
	.string "From there, you can choose to go\n"
	.string "to Snotop City or Monpas Town.$"

Route234_Text_RouteSign:
	.string "Route 234\n"
	.string "{RIGHT_ARROW} Tepek City$"
	.string "{LEFT_ARROW} Mt. Whirl$"

