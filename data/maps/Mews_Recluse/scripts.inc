Mews_Recluse_MapScripts::
	.byte 0


Mews_Recluse_Statues::
	lockall
	specialvar VAR_RESULT, CheckMewtwoParty
	compare VAR_RESULT, TRUE
	goto_if_eq Mews_Recluse_Statues_1
	msgbox Mews_Recluse_Statues_Text_1
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, WrongPokemon
	waitmovement 0
	releaseall
	return

Mews_Recluse_Statues_1:
	lockall
	msgbox Mews_Recluse_Statues_Text_0
	playfanfare SE_THUNDER
	waitmessage
	setflag FLAG_CLEARSTATUES
	setvar VAR_MEWS_RECLUSE_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	removeobject 8
	removeobject 3
	fadescreen FADE_FROM_BLACK
	releaseall
	return


WrongPokemon:
	walk_down
	step_end

Mews_Recluse_Statues_Text_0:
	.string "Your pokemon start rumbling in their\n"
	.string "balls$"

Mews_Recluse_Statues_Text_1:
	.string "You see an etching in the statues.\n"
	.string "'Although I was furious being made by\l"
	.string "humans, you were happy being made by\l"
	.string "me. You accepted the gift of life\l"
	.string "without hesitation and have taught me\l"
	.string "what it means to live. You were truly my\l"
	.string "greatest friends and guides. It is my\l"
	.string "only shame that I outlived you all.'$"
