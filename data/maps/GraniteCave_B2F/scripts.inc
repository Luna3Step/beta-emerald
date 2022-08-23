GraniteCave_B2F_MapScripts::
	.byte 0

GraniteCave_B2F_Aerodactylite::
	lockall
	msgbox GraniteCave_B2F_Aerodactylite_Text_0
	additem ITEM_AERODACTYLITE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq GraniteCave_B2F_Aerodactylite_1
	call Common_EventScript_ShowBagIsFull
	releaseall
	return

GraniteCave_B2F_Aerodactylite_1:
	removeobject 10
	setflag FLAG_AERODACTYLITE
	waitmessage
	releaseall
	end


GraniteCave_B2F_Aerodactylite_Text_0:
	.string "You found an Aerodactylite!$"
