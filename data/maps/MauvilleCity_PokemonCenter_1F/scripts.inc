.set LOCALID_NURSE, 1

MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	call Common_EventScript_SetupRivalGfxId
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx::
	special SetMauvilleOldManObjEventGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings:
	.string "That man over there, he says weird\n"
	.string "things!\p"
	.string "He's funny in a weird way.\n"
	.string "I doubt I'll forget about him!$"

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner:
	.string "When I accessed the RECORD CORNER,\n"
	.string "the data for what's hot in DEWFORD\l"
	.string "got updated.\p"
	.string "Now that bit of data is the same\n"
	.string "as my friend's!$"

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun:
	.string "A RECORD CORNER opened upstairs in\n"
	.string "the POKéMON CENTER.\p"
	.string "I don't know what it's about, but it\n"
	.string "sounds fun. I'll go check it out!$"

MauvilleCity_PokemonCenter_1F_EventScript_RivalBattleStart::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_PokemonCenter_1F_EventScript_RivalBattleStart_1
	lockall
	msgbox MauvilleCity_PokemonCenter_1F_EventScript_RivalBattleStart_Text_2
	waitmessage
	releaseall
	return

MauvilleCity_PokemonCenter_1F_EventScript_RivalBattleStart_1:
	goto_if_set FLAG_RECIEVED_GEN3, MauvilleCity_PokemonCenter_1F_EventScript_RivalBattleStart_4
	msgbox MauvilleCity_PokemonCenter_1F_EventScript_RivalBattleStart_Text_1
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MauvilleCity_PokemonCenter_1F_EventScript_RivalBattleStart_7
	call MauvilleCity_PokemonCenter_1F_EventScript_FemaleStarters
	return

MauvilleCity_PokemonCenter_1F_EventScript_RivalBattleStart_4:
	lockall
	msgbox MauvilleCity_PokemonCenter_1F_EventScript_RivalBattleStart_Text_0
	waitmessage
	releaseall
	return

MauvilleCity_PokemonCenter_1F_EventScript_RivalBattleStart_7:
	call MauvilleCity_PokemonCenter_1F_EventScript_MaleStarters
	return


MauvilleCity_PokemonCenter_1F_EventScript_MaleStarters::
	trainerbattle_single TRAINER_MAUVILLE_POKECENTERM, GymStarter_Gen3Text_Start, GymStarter_Gen3Text_Finish, GymStarter_Gen3BattleOver
	return


MauvilleCity_PokemonCenter_1F_EventScript_FemaleStarters::
	trainerbattle_single TRAINER_MAUVILLE_POKECENTERF, GymStarter_Gen3Text_Start, GymStarter_Gen3Text_Finish, GymStarter_Gen3BattleOver
	return


GymStarter_Gen3BattleOver::
	lockall
	msgbox GymStarter_Gen3BattleOver_Text_0
	givemon SPECIES_TORCHIC, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen3BattleOver_2
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen3BattleOver_3
	msgbox GymStarter_Gen3BattleOver_Text_2
GymStarter_Gen3BattleOver_1:
	givemon SPECIES_MUDKIP, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen3BattleOver_8
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen3BattleOver_9
	msgbox GymStarter_Gen3BattleOver_Text_2
GymStarter_Gen3BattleOver_7:
	givemon SPECIES_TREECKO, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen3BattleOver_14
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen3BattleOver_15
	msgbox GymStarter_Gen3BattleOver_Text_2
GymStarter_Gen3BattleOver_13:
	msgbox GymStarter_Gen3BattleOver_Text_5
	releaseall
	return

GymStarter_Gen3BattleOver_2:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen3BattleOver_Text_1
	setflag FLAG_RECIEVED_GEN3
	call NicknamePartyMon
	goto GymStarter_Gen3BattleOver_1

GymStarter_Gen3BattleOver_3:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN3
	call NicknameBoxMon
	goto GymStarter_Gen3BattleOver_1

GymStarter_Gen3BattleOver_8:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen3BattleOver_Text_3
	setflag FLAG_RECIEVED_GEN3
	call NicknamePartyMon
	goto GymStarter_Gen3BattleOver_7

GymStarter_Gen3BattleOver_9:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN3
	call NicknameBoxMon
	goto GymStarter_Gen3BattleOver_7

GymStarter_Gen3BattleOver_14:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen3BattleOver_Text_4
	setflag FLAG_RECIEVED_GEN3
	call NicknamePartyMon
	goto GymStarter_Gen3BattleOver_13

GymStarter_Gen3BattleOver_15:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN3
	call NicknameBoxMon
	goto GymStarter_Gen3BattleOver_13


MauvilleCity_PokemonCenter_1F_EventScript_RivalBattleStart_Text_0:
	.string "My dad really has too many pokemon, I\n"
	.string "wish he would atleast buy a lot of land\l"
	.string "to let them roam$"

MauvilleCity_PokemonCenter_1F_EventScript_RivalBattleStart_Text_1:
	.string "I see you've beaten Wattson! Let me\n"
	.string "test how good you are!$"

MauvilleCity_PokemonCenter_1F_EventScript_RivalBattleStart_Text_2:
	.string "I'm just resting here for now, my\n"
	.string "pokemon are tired. Need them in their\l"
	.string "best condition for the gym$"

GymStarter_Gen3BattleOver_Text_0:
	.string "Well while I'm here, you should take\n"
	.string "these lot. There isn't space for them\l"
	.string "back in the lab and I don't want to\l"
	.string "sideline them.$"

GymStarter_Gen3BattleOver_Text_1:
	.string "You recieved a Torchic!$"

GymStarter_Gen3BattleOver_Text_2:
	.string "There was no room$"

GymStarter_Gen3BattleOver_Text_3:
	.string "You recieved a Mudkip!$"

GymStarter_Gen3BattleOver_Text_4:
	.string "You recieved a Treeko!$"

GymStarter_Gen3BattleOver_Text_5:
	.string "I hope you treat them well.$"

GymStarter_Gen3Text_Start::
	.string "I'll show you how much I've grown!$"

GymStarter_Gen3Text_Finish::
	.string "Has anyone ever told you that you might\n"
	.string "be a bit too strong?$"
