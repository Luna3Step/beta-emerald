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


Mews_Recluse_EventScript_Mew::
	lockall
	setflag FLAG_MEW
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MEW, 5, ITEM_MEWTWONITE_Y
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Mews_Recluse_EventScript_Mew_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Mews_Recluse_EventScript_Mew_3
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Mews_Recluse_EventScript_Mew_4
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Mews_Recluse_EventScript_Mew_5
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Mews_Recluse_EventScript_Mew_6
Mews_Recluse_EventScript_Mew_1:
	waitmessage
	releaseall
	return

Mews_Recluse_EventScript_Mew_2:
	call MewCaught
	goto Mews_Recluse_EventScript_Mew_1

Mews_Recluse_EventScript_Mew_3:
	call MewWon
	goto Mews_Recluse_EventScript_Mew_1

Mews_Recluse_EventScript_Mew_4:
	call RanAway
	goto Mews_Recluse_EventScript_Mew_1

Mews_Recluse_EventScript_Mew_5:
	call RanAway
	goto Mews_Recluse_EventScript_Mew_1

Mews_Recluse_EventScript_Mew_6:
	call RanAway
	goto Mews_Recluse_EventScript_Mew_1


MewCaught::
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	msgbox MewCaught_Text_0
	return


MewWon::
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
	msgbox MewWon_Text_0, MSGBOX_AUTOCLOSE
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	msgbox MewWon_Text_1
	return


RanAway::
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
	msgbox RanAway_Text_0, MSGBOX_AUTOCLOSE
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	msgbox RanAway_Text_1
	return


MewsRecluse_ItemBallTop::
	lockall
	msgbox MewsRecluse_ItemBallTop_Text_0
	additem ITEM_BLUE_ORB, 1
	removeobject 2
	setflag FLAG_MEWTWONITE_X
	waitmessage
	releaseall
	end


MewsRecluse_ItemBallBottom::
	lockall
	msgbox MewsRecluse_ItemBallBottom_Text_0
	additem ITEM_RED_ORB, 1
	removeobject 3
	setflag FLAG_MEWTWONITE_Y
	waitmessage
	releaseall
	end


WrongPokemon:
	walk_left
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

MewCaught_Text_0:
	.string "Mew looks satisified with you$"

MewWon_Text_0:
	.string "Mew!$"

MewWon_Text_1:
	.string "Mew flew into the sky, it looked\n"
	.string "satisfied with you$"

RanAway_Text_0:
	.string "Mewwwww....$"

RanAway_Text_1:
	.string "Mew flew into the sky, it looked\n"
	.string "dissapointed in you$"

MewsRecluse_ItemBallTop_Text_0:
	.string "You found a Blue Orb!$"

MewsRecluse_ItemBallBottom_Text_0:
	.string "You found a Red Orb!$"
