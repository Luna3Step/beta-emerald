MeteorFalls_B1F_1R_MapScripts::
	.byte 0

MeteorFalls_B1F_1R_Lucarionite::
	lockall
	msgbox MeteorFalls_B1F_1R_Lucarionite_Text_0
	additem ITEM_LUCARIONITE, 1
	removeobject 1
	setflag FLAG_LUCARIONITE
	waitmessage
	releaseall
	end


MeteorFalls_B1F_1R_Lucarionite_Text_0:
	.string "You found a Lucarionite!$"
