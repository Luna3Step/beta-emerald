.set LOCALID_NURSE, 1

DewfordTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

DewfordTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

DewfordTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_PokefanF::
	msgbox DewfordTown_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_EventScript_Man::
	msgbox DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_Text_StoneCavern:
	.string "There's a stone cavern at the edge\n"
	.string "of town.\p"
	.string "I've heard you can find rare stones\n"
	.string "there.$"

DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM:
	.string "Even if a POKéMON faints and can't\n"
	.string "battle, it can still use a move learned\l"
	.string "from a HIDDEN MACHINE (HM).$"

DewfordTown_PokemonCenter_1F_EventScript_Starters::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE02_GET, DewfordTown_PokemonCenter_1F_EventScript_Starters_1
	lockall
	msgbox DewfordTown_PokemonCenter_1F_EventScript_Starters_Text_3
	waitmessage
	releaseall
	return

DewfordTown_PokemonCenter_1F_EventScript_Starters_1:
	goto_if_set FLAG_RECIEVED_GEN2, DewfordTown_PokemonCenter_1F_EventScript_Starters_4
	msgbox DewfordTown_PokemonCenter_1F_EventScript_Starters_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DewfordTown_PokemonCenter_1F_EventScript_Starters_7
	msgbox DewfordTown_PokemonCenter_1F_EventScript_Starters_Text_2
	waitmessage
	releaseall
	end

DewfordTown_PokemonCenter_1F_EventScript_Starters_4:
	lockall
	msgbox DewfordTown_PokemonCenter_1F_EventScript_Starters_Text_0
	waitmessage
	releaseall
	return

DewfordTown_PokemonCenter_1F_EventScript_Starters_7:
	trainerbattle_single TRAINER_DEWFORD_POKECENTER, GymStarter_Gen2Text_Start, GymStarter_Gen2Text_Finish, GymStarter_Gen2BattleOver
	return


GymStarter_Gen2BattleOver::
	lockall
	msgbox GymStarter_Gen2BattleOver_Text_0
	givemon SPECIES_CYNDAQUIL, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen2BattleOver_2
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen2BattleOver_3
	msgbox GymStarter_Gen2BattleOver_Text_2
GymStarter_Gen2BattleOver_1:
	givemon SPECIES_TOTODILE, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen2BattleOver_8
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen2BattleOver_9
	msgbox GymStarter_Gen2BattleOver_Text_2
GymStarter_Gen2BattleOver_7:
	givemon SPECIES_CHIKORITA, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen2BattleOver_14
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen2BattleOver_15
	msgbox GymStarter_Gen2BattleOver_Text_2
GymStarter_Gen2BattleOver_13:
	msgbox GymStarter_Gen2BattleOver_Text_5
	releaseall
	return

GymStarter_Gen2BattleOver_2:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen2BattleOver_Text_1
	setflag FLAG_RECIEVED_GEN2
	call NicknamePartyMon
	goto GymStarter_Gen2BattleOver_1

GymStarter_Gen2BattleOver_3:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN2
	call NicknameBoxMon
	goto GymStarter_Gen2BattleOver_1

GymStarter_Gen2BattleOver_8:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen2BattleOver_Text_3
	setflag FLAG_RECIEVED_GEN2
	call NicknamePartyMon
	goto GymStarter_Gen2BattleOver_7

GymStarter_Gen2BattleOver_9:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN2
	call NicknameBoxMon
	goto GymStarter_Gen2BattleOver_7

GymStarter_Gen2BattleOver_14:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen2BattleOver_Text_4
	setflag FLAG_RECIEVED_GEN2
	call NicknamePartyMon
	goto GymStarter_Gen2BattleOver_13

GymStarter_Gen2BattleOver_15:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN2
	call NicknameBoxMon
	goto GymStarter_Gen2BattleOver_13


DewfordTown_PokemonCenter_1F_EventScript_Starters_Text_0:
	.string "Are the young one's handling\n"
	.string "themselves well?$"

DewfordTown_PokemonCenter_1F_EventScript_Starters_Text_1:
	.string "Mhmm, you look like a good trainer. Would\n"
	.string "you like to fight?$"

DewfordTown_PokemonCenter_1F_EventScript_Starters_Text_2:
	.string "Come see me if you want to see what a\n"
	.string "real trainer battle look's like.$"

DewfordTown_PokemonCenter_1F_EventScript_Starters_Text_3:
	.string "That little lad seem's to have grown up,\n"
	.string "he used to spend his days surfing and\l"
	.string "now he's the gym leader of this ol'\l"
	.string "town.$"

GymStarter_Gen2BattleOver_Text_0:
	.string "Truly a sight to behold, your pokemon\n"
	.string "are well trained and yourself well\l"
	.string "disciplined. Please, take these young\l"
	.string "ones off my hands, they are in need of\l"
	.string "good training but I don't have it in me\l"
	.string "to do it anymore.$"

GymStarter_Gen2BattleOver_Text_1:
	.string "You recieved a Cyndaquil!$"

GymStarter_Gen2BattleOver_Text_2:
	.string "There was no room$"

GymStarter_Gen2BattleOver_Text_3:
	.string "You recieved a Totodile!$"

GymStarter_Gen2BattleOver_Text_4:
	.string "You recieved a Chikorita!$"

GymStarter_Gen2BattleOver_Text_5:
	.string "I hope you treat them well.$"

GymStarter_Gen2Text_Start::
	.string "Good choice, I'll show you the power of\n"
	.string "this old man!$"

GymStarter_Gen2Text_Finish::
	.string "Marvelous.$"
