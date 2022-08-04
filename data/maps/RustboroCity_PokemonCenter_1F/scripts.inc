.set LOCALID_NURSE, 1

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "My POKéMON has a NAIVE nature, and my\n"
	.string "friend's has a JOLLY nature.\p"
	.string "It's fascinating how POKéMON have\n"
	.string "personalities!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Just like people, there are male and\n"
	.string "female POKéMON.\p"
	.string "But no one seems to have any idea how\n"
	.string "they're different.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "The man next door gave me an HM!\p"
	.string "I used it to teach my POKéMON how to\n"
	.string "CUT down skinny trees.$"

RustboroCity_PokemonCenter_1F_EventScript_Starters::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonCenter_1F_EventScript_Starters_1
	lockall
	msgbox RustboroCity_PokemonCenter_1F_EventScript_Starters_Text_3
	waitmessage
	releaseall
	return

RustboroCity_PokemonCenter_1F_EventScript_Starters_1:
	goto_if_set FLAG_RECIEVED_GEN1, RustboroCity_PokemonCenter_1F_EventScript_Starters_4
	msgbox RustboroCity_PokemonCenter_1F_EventScript_Starters_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_PokemonCenter_1F_EventScript_Starters_7
	msgbox RustboroCity_PokemonCenter_1F_EventScript_Starters_Text_2
	waitmessage
	releaseall
	end

RustboroCity_PokemonCenter_1F_EventScript_Starters_4:
	lockall
	msgbox RustboroCity_PokemonCenter_1F_EventScript_Starters_Text_0
	waitmessage
	releaseall
	return

RustboroCity_PokemonCenter_1F_EventScript_Starters_7:
	trainerbattle_single TRAINER_RUSTBORO_POKECENTER, GymStarter_Gen1Text_Start, GymStarter_Gen1Text_Finish, GymStarter_Gen1BattleOver
	return


GymStarter_Gen1BattleOver::
	lockall
	msgbox GymStarter_Gen1BattleOver_Text_0
	givemon SPECIES_SQUIRTLE, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen1BattleOver_2
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen1BattleOver_3
	msgbox GymStarter_Gen1BattleOver_Text_2
GymStarter_Gen1BattleOver_1:
	givemon SPECIES_CHARMANDER, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen1BattleOver_8
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen1BattleOver_9
	msgbox GymStarter_Gen1BattleOver_Text_2
GymStarter_Gen1BattleOver_7:
	givemon SPECIES_BULBASAUR, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen1BattleOver_14
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen1BattleOver_15
	msgbox GymStarter_Gen1BattleOver_Text_2
GymStarter_Gen1BattleOver_13:
	msgbox GymStarter_Gen1BattleOver_Text_5
	releaseall
	return

GymStarter_Gen1BattleOver_2:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen1BattleOver_Text_1
	setflag FLAG_RECIEVED_GEN1
	call NicknamePartyMon
	goto GymStarter_Gen1BattleOver_1

GymStarter_Gen1BattleOver_3:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN1
	call NicknameBoxMon
	goto GymStarter_Gen1BattleOver_1

GymStarter_Gen1BattleOver_8:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen1BattleOver_Text_3
	setflag FLAG_RECIEVED_GEN1
	call NicknamePartyMon
	goto GymStarter_Gen1BattleOver_7

GymStarter_Gen1BattleOver_9:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN1
	call NicknameBoxMon
	goto GymStarter_Gen1BattleOver_7

GymStarter_Gen1BattleOver_14:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen1BattleOver_Text_4
	setflag FLAG_RECIEVED_GEN1
	call NicknamePartyMon
	goto GymStarter_Gen1BattleOver_13

GymStarter_Gen1BattleOver_15:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN1
	call NicknameBoxMon
	goto GymStarter_Gen1BattleOver_13


RustboroCity_PokemonCenter_1F_EventScript_Starters_Text_0:
	.string "Hope the little ones are doing okay.$"

RustboroCity_PokemonCenter_1F_EventScript_Starters_Text_1:
	.string "Hi there, I notice you have a Pokedex,\n"
	.string "I'm one of Birch's old apprentices. He\l"
	.string "asked that if I see any Dex holders to\l"
	.string "give them these Pokemon. But what's\l"
	.string "the fun in just giving it away, let's\l"
	.string "fight$"

RustboroCity_PokemonCenter_1F_EventScript_Starters_Text_2:
	.string "Ah that's a shame, come visit when you\n"
	.string "want these little ones.$"

RustboroCity_PokemonCenter_1F_EventScript_Starters_Text_3:
	.string "I hope my little one's find a good\n"
	.string "trainer one day, hopefully a strong one\l"
	.string "that can even beat that studious\l"
	.string "Roxanne.$"

GymStarter_Gen1BattleOver_Text_0:
	.string "That was an amazing battle, I can see\n"
	.string "why Birch picked you! Here, have your\l"
	.string "pokemon$"

GymStarter_Gen1BattleOver_Text_1:
	.string "You recieved a Squirtle!$"

GymStarter_Gen1BattleOver_Text_2:
	.string "There was no room$"

GymStarter_Gen1BattleOver_Text_3:
	.string "You recieved a Charmander!$"

GymStarter_Gen1BattleOver_Text_4:
	.string "You recieved a Bulbasaur!$"

GymStarter_Gen1BattleOver_Text_5:
	.string "Take good care of them! They can put up\n"
	.string "a right fight when they want to$"

GymStarter_Gen1Text_Start::
	.string "Show me all the Pokemon you have!$"

GymStarter_Gen1Text_Finish::
	.string "Oh how lovely!$"
