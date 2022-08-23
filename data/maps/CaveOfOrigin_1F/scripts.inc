CaveOfOrigin_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CaveOfOrigin_1F_OnTransition
	.byte 0

CaveOfOrigin_1F_OnTransition:
	call_if_set FLAG_UNUSED_RS_LEGENDARY_BATTLE_DONE, CaveOfOrigin_EventScript_DisableTriggers
	end

CaveOfOrigin_1f_Absolite::
	lockall
	msgbox CaveOfOrigin_1f_Absolite_Text_0
	additem ITEM_ABSOLITE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq CaveOfOrigin_1f_Absolite_1
	call Common_EventScript_ShowBagIsFull
	releaseall
	return

CaveOfOrigin_1f_Absolite_1:
	removeobject 1
	setflag FLAG_ABSOLITE
	waitmessage
	releaseall
	end


CaveOfOrigin_1f_Absolite_Text_0:
	.string "You found an Absolite!$"
