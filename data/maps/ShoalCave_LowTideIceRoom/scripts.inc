ShoalCave_LowTideIceRoom_MapScripts::
	.byte 0

ShoalCave_LowTideIceRoom_Glalitite::
	lockall
	msgbox ShoalCave_LowTideIceRoom_Glalitite_Text_0
	additem ITEM_GLALITITE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq ShoalCave_LowTideIceRoom_Glalitite_1
	call Common_EventScript_ShowBagIsFull
	releaseall
	return

ShoalCave_LowTideIceRoom_Glalitite_1:
	removeobject 3
	setflag FLAG_GLALITITE
	waitmessage
	releaseall
	end


ShoalCave_LowTideIceRoom_Glalitite_Text_0:
	.string "You found a Glalitite!$"
