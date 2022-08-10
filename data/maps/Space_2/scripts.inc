Space_2_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Space_2_EventScript_Messages
	.byte 0

Space_2_EventScript_Messages::
	lockall
	compare VAR_SPACE_STATE, 0
	goto_if_eq Space_2_EventScript_Messages_2
	call Space_2_EventScript_RayquazaSave
Space_2_EventScript_Messages_1:
	releaseall
	return

Space_2_EventScript_Messages_2:
	call Space_2_EventScript_Warning
	goto Space_2_EventScript_Messages_1


Space_2_EventScript_Warning::
	lockall
	setvar VAR_SPACE_STATE, 1
	msgbox Space_2_EventScript_Warning_Text_0
	waitmessage
	releaseall
	return


Space_2_EventScript_RayquazaSave::
	lockall
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	msgbox Space_2_EventScript_RayquazaSave_Text_0
	waitmessage
	releaseall
	return


Space_2_Trigger_Screenshake::
	lockall
	delay 30
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 4
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate
	delay 60
	releaseall
	return


Space_2_Trigger_DeoxysInitiate::
	lockall
	setflag FLAG_DEFEATED_DEOXYS
	playmoncry SPECIES_DEOXYS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	call Space_Trigger_Screenshake
	setwildbattle SPECIES_DEOXYS, 70, ITEM_NONE
	special BattleSetup_StartLegendaryBattle
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Space_2_Trigger_DeoxysInitiate_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Space_2_Trigger_DeoxysInitiate_3
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq Space_2_Trigger_DeoxysInitiate_4
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Space_2_Trigger_DeoxysInitiate_5
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Space_2_Trigger_DeoxysInitiate_6
Space_2_Trigger_DeoxysInitiate_1:
	waitmessage
	releaseall
	return

Space_2_Trigger_DeoxysInitiate_2:
	call Space_2_EventScript_DeoxysCaught
	goto Space_2_Trigger_DeoxysInitiate_1

Space_2_Trigger_DeoxysInitiate_3:
	call Space_2_EventScript_DeoxysBeaten
	goto Space_2_Trigger_DeoxysInitiate_1

Space_2_Trigger_DeoxysInitiate_4:
	call Space_2_EventScript_PlayerLost
	goto Space_2_Trigger_DeoxysInitiate_1

Space_2_Trigger_DeoxysInitiate_5:
	call Space_2_EventScript_PlayerLost
	goto Space_2_Trigger_DeoxysInitiate_1

Space_2_Trigger_DeoxysInitiate_6:
	call Space_2_EventScript_PlayerLost
	goto Space_2_Trigger_DeoxysInitiate_1


Space_2_EventScript_DeoxysCaught::
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	return


Space_2_EventScript_DeoxysBeaten::
	playmoncry SPECIES_DEOXYS, CRY_MODE_ENCOUNTER
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	msgbox Space_2_EventScript_DeoxysBeaten_Text_0
	return


Space_2_EventScript_PlayerLost::
	playmoncry SPECIES_DEOXYS, CRY_MODE_ENCOUNTER
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	msgbox Space_2_EventScript_PlayerLost_Text_0
	return


Space_2_EventScript_Warning_Text_0:
	.string "Please save before continuing.$"

Space_2_EventScript_RayquazaSave_Text_0:
	.string "Rayquaza bought you back. Be careful\n"
	.string "of drifting into space$"

Space_2_EventScript_DeoxysBeaten_Text_0:
	.string "Deoxys retreated into space.$"

Space_2_EventScript_PlayerLost_Text_0:
	.string "Deoxys flew back into space$"
