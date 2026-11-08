TepekCity_Mart_MapScripts::
	.byte 0

TepekCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, TepekCity_Mart_ExpandedItems
	pokemart TepekCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

TepekCity_Mart_EventScript_PokemartBasic::
	pokemart TepekCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TepekCity_Mart_Pokemart_Basic:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_REPEL
	pokemartlistend

TepekCity_Mart_ExpandedItems::
	pokemart TepekCity_Mart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TepekCity_Mart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	pokemartlistend

TepekCity_Mart_EventScript_Picknicker::
	msgbox TepekCity_Mart_Text_LetsRecoup, MSGBOX_NPC
	end

TepekCity_Mart_EventScript_Boy::
	msgbox TepekCity_Mart_Text_MartsChangeStock, MSGBOX_NPC
	end

TepekCity_Mart_EventScript_Camper::
	msgbox TepekCity_Mart_Text_IThinkWereGood, MSGBOX_NPC
	end

TepekCity_Mart_Text_LetsRecoup:
	.string "Alright, so we have the Antidotes\n"
	.string "in case of Paras, the Paralyze\p"
	.string "Heals in case of Paras…\n"
	.string "Do we need anything else?$"

TepekCity_Mart_Text_MartsChangeStock:
	.string "Different Marts have different\n"
	.string "stock. This one only sells basic\p"
	.string "items like Potions.$"

TepekCity_Mart_Text_IThinkWereGood:
	.string "What about Repels? You know, in\n"
	.string "case of Paras?$"

