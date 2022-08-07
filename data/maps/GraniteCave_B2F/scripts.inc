GraniteCave_B2F_MapScripts::
	.byte 0

GraniteCave_B2F_Aerodactylite::
	lockall
	msgbox GraniteCave_B2F_Aerodactylite_Text_0
	additem ITEM_AERODACTYLITE, 1
	removeobject 10
	setflag FLAG_AERODACTYLITE
	waitmessage
	releaseall
	end


GraniteCave_B2F_Aerodactylite_Text_0:
	.string "You found an Aerodactylite!$"
