HideawayWoods_MapScripts::
	.byte 0

HideawayWoods_EventScript_Boy1::
	msgbox HideawayWoods_Text_TwistyPaths, MSGBOX_NPC
	end

HideawayWoods_EventScript_Boy2::
	msgbox HideawayWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

HideawayWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SHARP_BEAK, HideawayWoods_EventScript_ExplainSharpBeak
	msgbox HideawayWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SHARP_BEAK
	release
	end

HideawayWoods_EventScript_ExplainSharpBeak::
	msgbox HideawayWoods_Text_SharpBeakExplanation, MSGBOX_DEFAULT
	release
	end

HideawayWoods_EventScript_Sign1::
	msgbox HideawayWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

HideawayWoods_EventScript_Sign2::
	msgbox HideawayWoods_Text_TrainerTipsEffectiveness, MSGBOX_SIGN
	end

HideawayWoods_EventScript_Bill::
	trainerbattle_single TRAINER_BILL, HideawayWoods_Text_MyWeedle, HideawayWoods_Text_ICouldntWin
	msgbox HideawayWoods_Text_CatchALotOfPokemon, MSGBOX_AUTOCLOSE
	end

HideawayWoods_EventScript_Enrique::
	trainerbattle_single TRAINER_ENRIQUE, HideawayWoods_Text_WatchYourStep, HideawayWoods_Text_TrippedOverAShroom
	msgbox HideawayWoods_Text_ScrapedMyKnee, MSGBOX_AUTOCLOSE
	end

HideawayWoods_EventScript_Brian::
	trainerbattle_single TRAINER_BRIAN, HideawayWoods_Text_SchoolProject, HideawayWoods_Text_GetAGoodGrade
	msgbox HideawayWoods_Text_AlolaForVacation, MSGBOX_AUTOCLOSE
	end

HideawayWoods_EventScript_Hillary::
	trainerbattle_single TRAINER_HILLARY, HideawayWoods_Text_CutePokemonInWoods, HideawayWoods_Text_CutenessDontWin
	msgbox HideawayWoods_Text_RarePokemonAroundHere, MSGBOX_AUTOCLOSE
	end

HideawayWoods_EventScript_Kurtis::
	trainerbattle_single TRAINER_KURTIS, HideawayWoods_Text_ScaredOfBugs, HideawayWoods_Text_ILoveBugs
	msgbox HideawayWoods_Text_BugsMisunderstood, MSGBOX_AUTOCLOSE
	end

HideawayWoods_EventScript_Tyler::
	trainerbattle_single TRAINER_TYLER, HideawayWoods_Text_JustBeatCiellus, HideawayWoods_Text_CouldntBeatYou
	msgbox HideawayWoods_Text_BadgesMeanObey, MSGBOX_AUTOCLOSE
	end

HideawayWoods_EventScript_Jolene::
	trainerbattle_single TRAINER_JOLENE, HideawayWoods_Text_EwYuckyBugs, HideawayWoods_Text_NowImDirty
	msgbox HideawayWoods_Text_LastTimeIGoInTheWoods, MSGBOX_AUTOCLOSE
	end

HideawayWoods_EventScript_Nick::
	trainerbattle_single TRAINER_NICK, HideawayWoods_Text_IThinkImLost, HideawayWoods_Text_TheWayOut
	msgbox HideawayWoods_Text_NotTooFar, MSGBOX_DEFAULT
	release
	end

HideawayWoods_Text_EwYuckyBugs:
	.string "EW! YUCK!\p"
	.string "A Bug-type just crawled across my\n"
	.string "shoe! EEK!$"

HideawayWoods_Text_NowImDirty:
	.string "Now I'm all dirty!$"

HideawayWoods_Text_LastTimeIGoInTheWoods:
	.string "This is the last time I go into\n"
	.string "the woods alone! YUCK!$"

HideawayWoods_Text_JustBeatCiellus:
	.string "Hey, I just beat Ciellus!\p"
	.string "Oh, you did too? Guess we're\n"
	.string "on equal footing!$"

HideawayWoods_Text_CouldntBeatYou:
	.string "It wasn't as equal as I thought!$"

HideawayWoods_Text_BadgesMeanObey:
	.string "Having more Badges mean higher-level\n"
	.string "Pokémon will obey you.\p"
	.string "But it doesn't mean you'll always\n"
	.string "win, though!$"

HideawayWoods_Text_ScaredOfBugs:
	.string "Are you scared of bugs?$"

HideawayWoods_Text_ILoveBugs:
	.string "I love you, Bug-type Pokémon!$"

HideawayWoods_Text_BugsMisunderstood:
	.string "I think Bug-type Pokémon are\n"
	.string "misunderstood. They don't want to\l"
	.string "hurt anybody!$"

HideawayWoods_Text_MyWeedle:
	.string "Look at how many Weedle I have!$"

HideawayWoods_Text_ICouldntWin:
	.string "My Weedle couldn't win…$"

HideawayWoods_Text_CatchALotOfPokemon:
	.string "If you catch a lot of Pokémon, then\n"
	.string "your Boxes will fill up super fast!$"

HideawayWoods_Text_SchoolProject:
	.string "I have a school project due on\n"
	.string "Pokémon battles tonight, can you help?$"

HideawayWoods_Text_GetAGoodGrade:
	.string "I'm gonna get an “A” for sure!$"

HideawayWoods_Text_AlolaForVacation:
	.string "If I get a good grade, my dads will\n"
	.string "take us to Alola for Summer Vacation!$"

HideawayWoods_Text_WatchYourStep:
	.string "Watch your step! Wild Paras\n"
	.string "everywhere!$"

HideawayWoods_Text_TrippedOverAShroom:
	.string "I tripped over something!$"

HideawayWoods_Text_ScrapedMyKnee:
	.string "I think I scraped my knee…$"

HideawayWoods_Text_CutePokemonInWoods:
	.string "Check out my cute Pokémon!\p"
	.string "I caught it right here in Hideaway\n"
	.string "Woods!$"

HideawayWoods_Text_CutenessDontWin:
	.string "Cuteness doesn't equal victory…$"

HideawayWoods_Text_RarePokemonAroundHere:
	.string "Everywhere you go, there's at least\n"
	.string "one or two rare Pokémon to find!$"

HideawayWoods_Text_IThinkImLost:
	.string "Help, I think I'm lost!$"

HideawayWoods_Text_TheWayOut:
	.string "Wait, do you at least know the way\n"
	.string "out of here?$"

HideawayWoods_Text_NotTooFar:
	.string "…So you're saying the exit is just\n"
	.string "around the corner…?!$"

HideawayWoods_Text_TwistyPaths:
	.string "Hideaway Woods is full of twisting\n"
	.string "paths, so you better watch your\p"
	.string "step if you want to avoid Trainers\n"
	.string "and Pokémon!$"

HideawayWoods_Text_HiddenItemsExplanation:
	.string "Sometimes there's items hidden in the\n"
	.string "grass or dirt. Look carefully and you\p"
	.string "might find some of them!$"

HideawayWoods_Text_TryUsingThisItem:
	.string "Cool, that's the Flight Badge from\n"
	.string "Tepek City Gym! You must be a strong\l"
	.string "Trainer!\p"
	.string "Here, give this to your Pokémon.$"

HideawayWoods_Text_SharpBeakExplanation:
	.string "It's called a Sharp Beak!\p"
	.string "If a Pokémon holds that, its Flying-\n"
	.string "type moves become stronger!\p"
	.string "I bet there's other items for other\n"
	.string "types of Pokémon, too!$"

HideawayWoods_Text_TrainerTipsExperience:
	.string "TRAINER TIPS\p"
	.string "The Exp. Share affects all Pokémon\n"
	.string "present in the party once a battle\l"
	.string "ends.\p"
	.string "It can be disabled and reenabled in the\n"
	.string "Key Items pocket.$"

HideawayWoods_Text_TrainerTipsEffectiveness:
	.string "TRAINER TIPS\p"
	.string "When battling Pokémon, you can check a\n"
	.string "Move's effectiveness by looking at the\l"
	.string "symbol!\p"
	.string "A super-effective move will look like a\n"
	.string "ring inside of a ring, for example.$"

