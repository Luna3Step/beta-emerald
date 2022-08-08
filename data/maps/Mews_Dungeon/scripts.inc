Mews_Dungeon_MapScripts::
	.byte 0


Mews_Dungeon_EventScript_Mew::
	lockall
	setflag FLAG_MEW
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MEW, 5, ITEM_MEWTWONITE_Y
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Mews_Dungeon_EventScript_Mew_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Mews_Dungeon_EventScript_Mew_3
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Mews_Dungeon_EventScript_Mew_4
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Mews_Dungeon_EventScript_Mew_5
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Mews_Dungeon_EventScript_Mew_6
Mews_Dungeon_EventScript_Mew_1:
	waitmessage
	releaseall
	return

Mews_Dungeon_EventScript_Mew_2:
	call MewCaught
	goto Mews_Dungeon_EventScript_Mew_1

Mews_Dungeon_EventScript_Mew_3:
	call MewWon
	goto Mews_Dungeon_EventScript_Mew_1

Mews_Dungeon_EventScript_Mew_4:
	call RanAway
	goto Mews_Dungeon_EventScript_Mew_1

Mews_Dungeon_EventScript_Mew_5:
	call RanAway
	goto Mews_Dungeon_EventScript_Mew_1

Mews_Dungeon_EventScript_Mew_6:
	call RanAway
	goto Mews_Dungeon_EventScript_Mew_1


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


MewsDungeon_Mewtwonite_X::
	lockall
	msgbox MewsDungeon_Mewtwonite_X_Text_0
	additem ITEM_MEWTWONITE_X, 1
	removeobject 2
	setflag FLAG_MEWTWONITE_X
	waitmessage
	releaseall
	end


MewsDungeon_Mewtwonite_Y::
	lockall
	msgbox MewsDungeon_Mewtwonite_Y_Text_0
	additem ITEM_MEWTWONITE_Y, 1
	removeobject 3
	setflag FLAG_MEWTWONITE_Y
	waitmessage
	releaseall
	end


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

MewsDungeon_Mewtwonite_X_Text_0:
	.string "You found a Mewtwonite X!$"

MewsDungeon_Mewtwonite_Y_Text_0:
	.string "You found a Mewtwonite Y!$"
