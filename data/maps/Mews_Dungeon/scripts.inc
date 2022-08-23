Mews_Dungeon_MapScripts::
	.byte 0


Mews_Dungeon_Eventscript_Mewtwo::
	lockall
	setflag FLAG_MEW
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement OBJ_EVENT_ID_PLAYER, Mews_Dungeon_EventScript_PlayerRun
	applymovement 1, Mews_Dungeon_EventScript_MewtwoAgressive
	call Mews_Dungeon_EventScript_MewtwoShake
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Mews_Dungeon_EventScript_PlayerRun
	applymovement 1, Mews_Dungeon_EventScript_MewtwoAgressive
	call Mews_Dungeon_EventScript_MewtwoShake
	waitmovement 0
	setwildbattle SPECIES_MEWTWO, 50, ITEM_TWISTED_SPOON
	special BattleSetup_StartLegendaryBattle
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Mews_Dungeon_Eventscript_Mewtwo_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Mews_Dungeon_Eventscript_Mewtwo_3
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Mews_Dungeon_Eventscript_Mewtwo_4
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Mews_Dungeon_Eventscript_Mewtwo_5
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Mews_Dungeon_Eventscript_Mewtwo_6
Mews_Dungeon_Eventscript_Mewtwo_1:
	waitmessage
	releaseall
	return

Mews_Dungeon_Eventscript_Mewtwo_2:
	call MewCaught
	goto Mews_Dungeon_Eventscript_Mewtwo_1

Mews_Dungeon_Eventscript_Mewtwo_3:
	call MewWon
	goto Mews_Dungeon_Eventscript_Mewtwo_1

Mews_Dungeon_Eventscript_Mewtwo_4:
	call RanAway
	goto Mews_Dungeon_Eventscript_Mewtwo_1

Mews_Dungeon_Eventscript_Mewtwo_5:
	call RanAway
	goto Mews_Dungeon_Eventscript_Mewtwo_1

Mews_Dungeon_Eventscript_Mewtwo_6:
	call RanAway
	goto Mews_Dungeon_Eventscript_Mewtwo_1


Mews_Dungeon_EventScript_MewtwoAgressive:
	walk_down
	step_end

Mews_Dungeon_EventScript_PlayerRun:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

Mews_Dungeon_EventScript_MewtwoShake::
	delay 30
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate
	delay 60
	return


MewCaught::
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	msgbox MewCaught_Text_0
	return


MewWon::
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	msgbox MewWon_Text_0
	return


RanAway::
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	msgbox RanAway_Text_0
	return


MewsDungeon_Mewtwonite_X::
	lockall
	msgbox MewsDungeon_Mewtwonite_X_Text_0
	additem ITEM_MEWTWONITE_X, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MewsDungeon_Mewtwonite_X_1
	call Common_EventScript_ShowBagIsFull
	releaseall
	return

MewsDungeon_Mewtwonite_X_1:
	removeobject 2
	setflag FLAG_MEWTWONITE_X
	waitmessage
	releaseall
	end


MewsDungeon_Mewtwonite_Y::
	lockall
	msgbox MewsDungeon_Mewtwonite_Y_Text_0
	additem ITEM_MEWTWONITE_Y, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MewsDungeon_Mewtwonite_Y_1
	call Common_EventScript_ShowBagIsFull
	releaseall
	return

MewsDungeon_Mewtwonite_Y_1:
	removeobject 3
	setflag FLAG_MEWTWONITE_Y
	waitmessage
	releaseall
	end


MewCaught_Text_0:
	.string "Mewtwo looks satisified with you$"

MewWon_Text_0:
	.string "Mewtwo flew into the sky, it looked\n"
	.string "satisfied with you$"

RanAway_Text_0:
	.string "Mewtwo flew into the sky, it looked\n"
	.string "dissapointed in you$"

MewsDungeon_Mewtwonite_X_Text_0:
	.string "You found a Mewtwonite X!$"

MewsDungeon_Mewtwonite_Y_Text_0:
	.string "You found a Mewtwonite Y!$"
