PetalburgCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
PetalburgCity_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

PetalburgCity_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

PetalburgCity_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

PetalburgCity_PokemonCenter_1F_EventScript_Starters::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_PokemonCenter_1F_EventScript_Starters_1
	lockall
	msgbox PetalburgCity_PokemonCenter_1F_EventScript_Starters_Text_3
	waitmessage
	releaseall
	return

PetalburgCity_PokemonCenter_1F_EventScript_Starters_1:
	goto_if_set FLAG_RECIEVED_GEN5, PetalburgCity_PokemonCenter_1F_EventScript_Starters_4
	msgbox PetalburgCity_PokemonCenter_1F_EventScript_Starters_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_Starters_7
	msgbox PetalburgCity_PokemonCenter_1F_EventScript_Starters_Text_2
	waitmessage
	releaseall
	end

PetalburgCity_PokemonCenter_1F_EventScript_Starters_4:
	lockall
	msgbox PetalburgCity_PokemonCenter_1F_EventScript_Starters_Text_0
	waitmessage
	releaseall
	return

PetalburgCity_PokemonCenter_1F_EventScript_Starters_7:
	trainerbattle_single TRAINER_PETALBURG_POKECENTER, GymStarter_Gen5Text_Start, GymStarter_Gen5Text_Finish, GymStarter_Gen5BattleOver
	return


GymStarter_Gen5BattleOver::
	lockall
	msgbox GymStarter_Gen5BattleOver_Text_0
	givemon SPECIES_OSHAWOTT, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen5BattleOver_2
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen5BattleOver_3
	msgbox GymStarter_Gen5BattleOver_Text_2
GymStarter_Gen5BattleOver_1:
	givemon SPECIES_SNIVY, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen5BattleOver_8
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen5BattleOver_9
	msgbox GymStarter_Gen5BattleOver_Text_2
GymStarter_Gen5BattleOver_7:
	givemon SPECIES_TEPIG, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen5BattleOver_14
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen5BattleOver_15
	msgbox GymStarter_Gen5BattleOver_Text_2
GymStarter_Gen5BattleOver_13:
	msgbox GymStarter_Gen5BattleOver_Text_5
	releaseall
	return

GymStarter_Gen5BattleOver_2:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen5BattleOver_Text_1
	setflag FLAG_RECIEVED_GEN5
	call NicknamePartyMon
	goto GymStarter_Gen5BattleOver_1

GymStarter_Gen5BattleOver_3:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN5
	call NicknameBoxMon
	goto GymStarter_Gen5BattleOver_1

GymStarter_Gen5BattleOver_8:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen5BattleOver_Text_3
	setflag FLAG_RECIEVED_GEN5
	call NicknamePartyMon
	goto GymStarter_Gen5BattleOver_7

GymStarter_Gen5BattleOver_9:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN5
	call NicknameBoxMon
	goto GymStarter_Gen5BattleOver_7

GymStarter_Gen5BattleOver_14:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen5BattleOver_Text_4
	setflag FLAG_RECIEVED_GEN5
	call NicknamePartyMon
	goto GymStarter_Gen5BattleOver_13

GymStarter_Gen5BattleOver_15:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN5
	call NicknameBoxMon
	goto GymStarter_Gen5BattleOver_13


PetalburgCity_PokemonCenter_1F_EventScript_Starters_Text_0:
	.string "Thank you for taking them off my hand,\n"
	.string "my grandparents can be a bit\l"
	.string "overzealous with gifts.$"

PetalburgCity_PokemonCenter_1F_EventScript_Starters_Text_1:
	.string "My grandparents keep sending me gifts,\n"
	.string "it's getting a bit much now. Would you\l"
	.string "like to have some?$"

PetalburgCity_PokemonCenter_1F_EventScript_Starters_Text_2:
	.string "Sorry to put pressure on you.$"

PetalburgCity_PokemonCenter_1F_EventScript_Starters_Text_3:
	.string "How do I stop this, why do they keep\n"
	.string "sending them. I doubt even the gym\l"
	.string "leaders have these many pokemon?$"

GymStarter_Gen5BattleOver_Text_0:
	.string "You are such a great trainer, these\n"
	.string "pokemon will definitely be fine in your\l"
	.string "hands. Please take care of them$"

GymStarter_Gen5BattleOver_Text_1:
	.string "You recieved a Oshawott!$"

GymStarter_Gen5BattleOver_Text_2:
	.string "There was no room$"

GymStarter_Gen5BattleOver_Text_3:
	.string "You recieved a Snivy!$"

GymStarter_Gen5BattleOver_Text_4:
	.string "You recieved a Tepig!$"

GymStarter_Gen5BattleOver_Text_5:
	.string "Take care of them!$"

GymStarter_Gen5Text_Start::
	.string "I'll just make sure that you are a good\n"
	.string "trainer!$"

GymStarter_Gen5Text_Finish::
	.string "!!!!!$"
