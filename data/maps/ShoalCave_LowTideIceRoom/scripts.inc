ShoalCave_LowTideIceRoom_MapScripts::
	.byte 0

ShoalCave_LowTideIceRoom_Glalitite::
	lockall
	msgbox ShoalCave_LowTideIceRoom_Glalitite_Text_0
	additem ITEM_GLALITITE, 1
	removeobject 3
	setflag FLAG_GLALITITE
	waitmessage
	releaseall
	end


ShoalCave_LowTideIceRoom_Glalitite_Text_0:
	.string "You found a Glalitite!$"
