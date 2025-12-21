RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House3_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_CUBCHOO
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House3_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House3_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House3_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House3_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox RustboroCity_House3_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House3_EventScript_DeclineTrade::
	msgbox RustboroCity_House3_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House3_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House3_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House3_EventScript_TradeCompleted::
	msgbox RustboroCity_House3_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House3_Text_IllTradeIfYouWant:
	.string "Have you seen any Pikachu around?\n"
	.string "I heard they live near the Power\p"
	.string "Plant, but all I ever find are\n"
	.string "Pichu. If you can get me a Pikachu\p"
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "it.$"

RustboroCity_House3_Text_YouDontWantToThatsOkay:
	.string "Oh, it's okay if you don't want to.\n"
	.string "I'm sure I'll find a Pikachu soon.$"

RustboroCity_House3_Text_DoesntLookLikeMonToMe:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

RustboroCity_House3_Text_PleaseBeGoodToMyPokemon:
	.string "Thank you!\n"
	.string "Please be good to my Pokémon!$"

RustboroCity_House3_Text_AnyPokemonCanBeCute:
	.string "Pikachu has such cute, red cheeks!$"

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_ApartmentHousing, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_Magnemite::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGNEMITE, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Magnemite, MSGBOX_NPC
	waitmoncry
	release
	end

RustboroCity_House3_Text_ApartmentHousing:
	.string "This apartment houses many families.\n"
	.string "It's an affordable way for people and\p"
	.string "Pokémon to live together.$"

RustboroCity_House3_Text_Magnemite:
	.string "Maggie: Bzzzrt!$"
