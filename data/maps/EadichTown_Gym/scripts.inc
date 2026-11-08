EadichTown_Gym_MapScripts::
	.byte 0

EadichTown_Gym_EventScript_Marwick::
	trainerbattle_single TRAINER_MARWICK, EadichTown_Gym_Text_MarwickIntro, EadichTown_Gym_Text_MarwickDefeat, EadichTown_Gym_EventScript_MarwickDefeated, NO_MUSIC
	goto_if_unset FLAG_RECEIVED_MEGA_DRAIN, EadichTown_Gym_EventScript_GiveMegaDrain
	msgbox EadichTown_Gym_Text_MarwickPostBattle, MSGBOX_DEFAULT
	release
	end

EadichTown_Gym_EventScript_MarwickDefeated::
	message EadichTown_Gym_Text_ReceivedGrassBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox EadichTown_Gym_Text_GrassBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_EADICH_GYM
	setflag FLAG_BADGE02_GET
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	goto EadichTown_Gym_EventScript_GiveMegaDrain
	end

EadichTown_Gym_EventScript_GiveMegaDrain::
	giveitem ITEM_TM_MEGA_DRAIN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MEGA_DRAIN
	msgbox EadichTown_Gym_Text_ExplainMegaDrain, MSGBOX_DEFAULT
	release
	end

EadichTown_Gym_EventScript_Sunflora::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SUNFLORA, CRY_MODE_NORMAL
	msgbox EadichTown_Gym_Text_Sunflora, MSGBOX_NPC
	waitmoncry
	release
	end

EadichTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EADICH_GYM, EadichTown_Gym_EventScript_GymGuidePostVictory
	msgbox EadichTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

EadichTown_Gym_EventScript_GymGuidePostVictory::
	msgbox EadichTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

EadichTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, EadichTown_Gym_EventScript_GymStatueCertified
	goto EadichTown_Gym_EventScript_GymStatue
	end

EadichTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, EadichTown_Gym_EventScript_GymStatueCertified
	goto EadichTown_Gym_EventScript_GymStatue
	end

EadichTown_Gym_EventScript_GymStatueCertified::
	msgbox EadichTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

EadichTown_Gym_EventScript_GymStatue::
	msgbox EadichTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

EadichTown_Gym_EventScript_Holly::
	trainerbattle_single TRAINER_HOLLY, TepekCity_Gym_Text_HollyIntro, TepekCity_Gym_Text_HollyDefeat
	msgbox TepekCity_Gym_Text_HollyPostBattle, MSGBOX_AUTOCLOSE
	end

EadichTown_Gym_EventScript_Opal::
	trainerbattle_single TRAINER_OPAL, TepekCity_Gym_Text_OpalIntro, TepekCity_Gym_Text_OpalDefeat
	msgbox TepekCity_Gym_Text_OpalPostBattle, MSGBOX_AUTOCLOSE
	end

EadichTown_Gym_EventScript_Clint::
	trainerbattle_single TRAINER_CLINT, TepekCity_Gym_Text_ClintIntro, TepekCity_Gym_Text_ClintDefeat
	msgbox TepekCity_Gym_Text_ClintPostBattle, MSGBOX_AUTOCLOSE
	end

EadichTown_Gym_EventScript_Flora::
	trainerbattle_single TRAINER_FLORA, TepekCity_Gym_Text_FloraIntro, TepekCity_Gym_Text_FloraDefeat
	msgbox TepekCity_Gym_Text_FloraPostBattle, MSGBOX_AUTOCLOSE
	end

EadichTown_Gym_EventScript_Duke::
	trainerbattle_single TRAINER_DUKE, TepekCity_Gym_Text_DukeIntro, TepekCity_Gym_Text_DukeDefeat
	msgbox TepekCity_Gym_Text_DukePostBattle, MSGBOX_AUTOCLOSE
	end
	
EadichTown_Gym_Text_MarwickIntro:
	.string "Marwick: Hahah, another challenger!\p"
	.string "The name's Marwick. Used to be\n"
	.string "Captain Marwick back in my days as\l"
	.string "as a sailing man! But my real home was\n"
	.string "here as a farmer, tending to the land.\p"
	.string "Care to show this old man what you\n"
	.string "know about battling with Pokémon?$"

EadichTown_Gym_Text_MarwickDefeat:
	.string "Hahahah, what a fight!\n"
	.string "You sure showed me a thing or two!\p"
	.string "Whaddaya think about meeting me at\n"
	.string "my cabin back on Route 233?\p"
	.string "I've got a gift for you, kid!\p"
	.string "Oh, and take this; the Official\n"
	.string "Pokémon League Seedling Badge!$"

EadichTown_Gym_Text_ReceivedGrassBadge:
	.string "{PLAYER} received the Seedling\n"
	.string "Badge from Marwick.$"

EadichTown_Gym_Text_GrassBadgeInfoTakeThis:
	.string "The Seedling Badge will let you\n"
	.string "use the HM Move Cut out of battle.\p"
	.string "Go ahead and take this, too.$"

EadichTown_Gym_Text_ExplainMegaDrain:
	.string "That's TM51, Mega Drain.\p"
	.string "It's a stronger version of Absorb,\n"
	.string "so you'll be able to regain even\l"
	.string "more HP in battle.$"

EadichTown_Gym_Text_MarwickPostBattle:
	.string "Remember to stop by on your\n"
	.string "way back through the woods.\p"
	.string "Me and Greta would love to see ya!$"

EadichTown_Gym_Text_Sunflora:
	.string "Sunny: Flora!$"

EadichTown_Gym_Text_GymStatue:
	.string "Eadich Town Pokémon Gym$"
	.string "Marick's Certified Trainers:\n"
	.string "JUDE$"

EadichTown_Gym_Text_GymStatueCertified:
	.string "Eadich Town Pokémon Gym\p"
	.string "Marick's Certified Trainers:\n"
	.string "JUDE\p"
	.string "{PLAYER}$"

EadichTown_Gym_Text_GymGuideAdvice:
	.string "Hey again, future Champ, how'sit?\p"
	.string "Let me give you some more advice for\n"
	.string "your Pokémon journey:\p"
	.string "Marick knows his Grass-types like\n"
	.string "the back of his hand.\p"
	.string "But throw a Flying- or Fire-type move\n"
	.string "at his 'mons and you'll be mowin'\l"
	.string "the lawn in no time!\p"
	.string "Go for it, future Champ!$"

EadichTown_Gym_Text_GymGuidePostVictory:
	.string "You pulled off that battle with\n"
	.string "some spectacular moves!\p"
	.string "Make sure you check out your new\n"
	.string "Flight Badge in your Trainer Card!\p"
	.string "Good luck, future Champ!$"

TepekCity_Gym_Text_HollyIntro:
	.string "Hehe, lost yet?$"

TepekCity_Gym_Text_HollyDefeat:
	.string "You're good!$"

TepekCity_Gym_Text_HollyPostBattle:
	.string "Hehe, have you noticed the\n"
	.string "secret, yet?$"

TepekCity_Gym_Text_OpalIntro:
	.string "You gotta find your way through\n"
	.string "if you wanna fight Marwick!$"

TepekCity_Gym_Text_OpalDefeat:
	.string "You just gotta keep going!$"

TepekCity_Gym_Text_OpalPostBattle:
	.string "Marwick made this gym as\n"
	.string "natural as possible so his\p"
	.string "Grass-types would be happy.$"

TepekCity_Gym_Text_ClintIntro:
	.string "We're twisting and turning,\n"
	.string "just like the ocean.$"

TepekCity_Gym_Text_ClintDefeat:
	.string "Shipwrecked!$"

TepekCity_Gym_Text_ClintPostBattle:
	.string "I used to be a part of\n"
	.string "Marwick's sailing crew.$"

TepekCity_Gym_Text_FloraIntro:
	.string "Getting tired?$"

TepekCity_Gym_Text_FloraDefeat:
	.string "I guess not!$"

TepekCity_Gym_Text_FloraPostBattle:
	.string "You're almost to the end\n"
	.string "Keep going!$"

TepekCity_Gym_Text_DukeIntro:
	.string "Bright in here? Thank\n"
	.string "the giant skylights!$"

TepekCity_Gym_Text_DukeDefeat:
	.string "It's too bright, sometimes!$"

TepekCity_Gym_Text_DukePostBattle:
	.string "When it rains, you can hear\n"
	.string "it pounding against the\l"
	.string "skylights$."
