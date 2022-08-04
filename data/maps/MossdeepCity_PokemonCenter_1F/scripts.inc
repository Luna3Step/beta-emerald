.set LOCALID_NURSE, 1

MossdeepCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MossdeepCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
	end

MossdeepCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_Woman::
	msgbox MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_EventScript_Girl::
	msgbox MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable:
	.string "The GYM LEADERS in this town are\n"
	.string "a formidable duo.\p"
	.string "Their combination attacks are, like,\n"
	.string "excellent and wow!$"

MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves:
	.string "Depending on the special abilities of\n"
	.string "POKéMON, some moves might change\l"
	.string "or not work at all.$"

MossdeepCity_PokemonCenter_1F_EventScript_Starters::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_PokemonCenter_1F_EventScript_Starters_1
	lockall
	msgbox MossdeepCity_PokemonCenter_1F_EventScript_Starters_Text_3
	waitmessage
	releaseall
	return

MossdeepCity_PokemonCenter_1F_EventScript_Starters_1:
	goto_if_set FLAG_RECIEVED_GEN7, MossdeepCity_PokemonCenter_1F_EventScript_Starters_4
	msgbox MossdeepCity_PokemonCenter_1F_EventScript_Starters_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MossdeepCity_PokemonCenter_1F_EventScript_Starters_7
	msgbox MossdeepCity_PokemonCenter_1F_EventScript_Starters_Text_2
	waitmessage
	releaseall
	end

MossdeepCity_PokemonCenter_1F_EventScript_Starters_4:
	lockall
	msgbox MossdeepCity_PokemonCenter_1F_EventScript_Starters_Text_0
	waitmessage
	releaseall
	return

MossdeepCity_PokemonCenter_1F_EventScript_Starters_7:
	trainerbattle_double TRAINER_MOSSDEEP_POKECENTER, GymStarter_Gen7Text_Start, GymStarter_Gen7Text_Finish, GymStarter_Gen7Text_TooFewPokemon, GymStarter_Gen7BattleOver
	return


GymStarter_Gen7BattleOver::
	lockall
	msgbox GymStarter_Gen7BattleOver_Text_0
	givemon SPECIES_POPPLIO, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen7BattleOver_2
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen7BattleOver_3
	msgbox GymStarter_Gen7BattleOver_Text_2
GymStarter_Gen7BattleOver_1:
	givemon SPECIES_ROWLET, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen7BattleOver_8
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen7BattleOver_9
	msgbox GymStarter_Gen7BattleOver_Text_2
GymStarter_Gen7BattleOver_7:
	givemon SPECIES_LITTEN, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen7BattleOver_14
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen7BattleOver_15
	msgbox GymStarter_Gen7BattleOver_Text_2
GymStarter_Gen7BattleOver_13:
	msgbox GymStarter_Gen7BattleOver_Text_5
	releaseall
	return

GymStarter_Gen7BattleOver_2:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen7BattleOver_Text_1
	setflag FLAG_RECIEVED_GEN7
	call NicknamePartyMon
	goto GymStarter_Gen7BattleOver_1

GymStarter_Gen7BattleOver_3:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN7
	call NicknameBoxMon
	goto GymStarter_Gen7BattleOver_1

GymStarter_Gen7BattleOver_8:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen7BattleOver_Text_3
	setflag FLAG_RECIEVED_GEN7
	call NicknamePartyMon
	goto GymStarter_Gen7BattleOver_7

GymStarter_Gen7BattleOver_9:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN7
	call NicknameBoxMon
	goto GymStarter_Gen7BattleOver_7

GymStarter_Gen7BattleOver_14:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen7BattleOver_Text_4
	setflag FLAG_RECIEVED_GEN7
	call NicknamePartyMon
	goto GymStarter_Gen7BattleOver_13

GymStarter_Gen7BattleOver_15:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN7
	call NicknameBoxMon
	goto GymStarter_Gen7BattleOver_13


MossdeepCity_PokemonCenter_1F_EventScript_Cameraman::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_PokemonCenter_1F_EventScript_Cameraman_1
	lockall
	msgbox MossdeepCity_PokemonCenter_1F_EventScript_Cameraman_Text_2
	waitmessage
	releaseall
	return

MossdeepCity_PokemonCenter_1F_EventScript_Cameraman_1:
	goto_if_set FLAG_RECIEVED_GEN7, MossdeepCity_PokemonCenter_1F_EventScript_Cameraman_4
	msgbox MossdeepCity_PokemonCenter_1F_EventScript_Cameraman_Text_1
	waitmessage
	releaseall
	return

MossdeepCity_PokemonCenter_1F_EventScript_Cameraman_4:
	lockall
	msgbox MossdeepCity_PokemonCenter_1F_EventScript_Cameraman_Text_0
	waitmessage
	releaseall
	return


MossdeepCity_PokemonCenter_1F_EventScript_Starters_Text_0:
	.string "I hope you enjoy our segment on TV!$"

MossdeepCity_PokemonCenter_1F_EventScript_Starters_Text_1:
	.string "Hi, we are doing a documentary on\n"
	.string "trainers however we are running low on\l"
	.string "pokemon footage, mind showing us\l"
	.string "yours?$"

MossdeepCity_PokemonCenter_1F_EventScript_Starters_Text_2:
	.string "Oh that's fine, theres loads of trainers\n"
	.string "round here, shouldn't be hard to find\l"
	.string "others.$"

MossdeepCity_PokemonCenter_1F_EventScript_Starters_Text_3:
	.string "Look at this footage, it's terrible. I'm\n"
	.string "telling you that metapod battles\l"
	.string "aren't interesting yet you keep\l"
	.string "recording them.$"

GymStarter_Gen7BattleOver_Text_0:
	.string "Here take them. We found them as we\n"
	.string "were going around but I'm too busy to\l"
	.string "look after them$"

GymStarter_Gen7BattleOver_Text_1:
	.string "You recieved a Popplio!$"

GymStarter_Gen7BattleOver_Text_2:
	.string "There was no room$"

GymStarter_Gen7BattleOver_Text_3:
	.string "You recieved a Rowlet!$"

GymStarter_Gen7BattleOver_Text_4:
	.string "You recieved a Litten!$"

GymStarter_Gen7BattleOver_Text_5:
	.string "Those little menaces should serve you\n"
	.string "well!$"

MossdeepCity_PokemonCenter_1F_EventScript_Cameraman_Text_0:
	.string "I hope this footage is good, I need a\n"
	.string "break from the higher up's nagging me\l"
	.string "constantly.$"

MossdeepCity_PokemonCenter_1F_EventScript_Cameraman_Text_1:
	.string "Hey, you look perfect, talk to my\n"
	.string "colleague over there, she might have a\l"
	.string "job for you.$"

MossdeepCity_PokemonCenter_1F_EventScript_Cameraman_Text_2:
	.string "God I love metapods, their little cute\n"
	.string "noses and idle stare. I wish I could\l"
	.string "have one$"

GymStarter_Gen7Text_Start::
	.string "Might as well make it interesting!$"

GymStarter_Gen7Text_Finish::
	.string "Oh wow, this is top notch stuff. The\n"
	.string "boss will be pleased with this$"

GymStarter_Gen7Text_TooFewPokemon::
	.string "You might want to get some more\n"
	.string "pokemon, we don't want to make this\l"
	.string "look one sided$"
