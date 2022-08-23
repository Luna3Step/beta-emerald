.set LOCALID_FOSSIL, 1

DesertUnderpass_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
	.byte 0

DesertUnderpass_OnTransition:
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
	end

DesertUnderpass_EventScript_Fossil::
	lock
	faceplayer
	goto_if_set FLAG_CHOSE_ROOT_FOSSIL, DesertUnderpass_EventScript_GiveClawFossil
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, DesertUnderpass_EventScript_GiveRootFossil
	release
	end

DesertUnderpass_EventScript_GiveClawFossil::
	giveitem ITEM_CLAW_FOSSIL
	removeobject LOCALID_FOSSIL
	release
	end

DesertUnderpass_EventScript_GiveRootFossil::
	giveitem ITEM_ROOT_FOSSIL
	removeobject LOCALID_FOSSIL
	release
	end

@ Unused
DesertUnderpass_Text_FoundRootFossil::
	.string "{PLAYER} found the ROOT FOSSIL.$"

@ Unused
DesertUnderpass_Text_FoundClawFossil::
	.string "{PLAYER} found the CLAW FOSSIL.$"

DesertUnderpass_Aggronite::
	lockall
	msgbox DesertUnderpass_Aggronite_Text_0
	additem ITEM_AGGRONITE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq DesertUnderpass_Aggronite_1
	call Common_EventScript_ShowBagIsFull
	releaseall
	return

DesertUnderpass_Aggronite_1:
	removeobject 2
	setflag FLAG_AGGRONITE
	waitmessage
	releaseall
	end


DesertUnderpass_Aggronite_Text_0:
	.string "You found an Aggronite!$"
