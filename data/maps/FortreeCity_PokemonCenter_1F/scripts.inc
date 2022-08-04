.set LOCALID_NURSE, 1

FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Listen, kid, are you working\n"
	.string "on a POKéDEX?\p"
	.string "Hmm… Go to the SAFARI ZONE.\n"
	.string "That's my suggestion.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Have you done anything at\n"
	.string "the RECORD CORNER?\p"
	.string "It's pretty neat. It mixes and matches\n"
	.string "the records of TRAINERS.\p"
	.string "I don't know quite how it works,\n"
	.string "but it's cool. It's exciting, even!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Oh, wow, you have a POKéNAV!\n"
	.string "And it's just like mine!\p"
	.string "Do you know about POKéNAV's\n"
	.string "MATCH CALL system?\p"
	.string "Access it, and you can chat with\n"
	.string "registered TRAINERS anytime.\p"
	.string "It also shows you which TRAINERS\n"
	.string "want a rematch with you.\p"
	.string "It's really nifty! Those DEVON guys\n"
	.string "sure know what they're doing!$"

FortreeCity_PokemonCenter_1F_EventScript_Starters::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE06_GET, FortreeCity_PokemonCenter_1F_EventScript_Starters_1
	lockall
	msgbox FortreeCity_PokemonCenter_1F_EventScript_Starters_Text_3
	waitmessage
	releaseall
	return

FortreeCity_PokemonCenter_1F_EventScript_Starters_1:
	goto_if_set FLAG_RECIEVED_GEN6, FortreeCity_PokemonCenter_1F_EventScript_Starters_4
	msgbox FortreeCity_PokemonCenter_1F_EventScript_Starters_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FortreeCity_PokemonCenter_1F_EventScript_Starters_7
	msgbox FortreeCity_PokemonCenter_1F_EventScript_Starters_Text_2
	waitmessage
	releaseall
	end

FortreeCity_PokemonCenter_1F_EventScript_Starters_4:
	lockall
	msgbox FortreeCity_PokemonCenter_1F_EventScript_Starters_Text_0
	waitmessage
	releaseall
	return

FortreeCity_PokemonCenter_1F_EventScript_Starters_7:
	trainerbattle_single TRAINER_FORTREE_POKECENTER, GymStarter_Gen6Text_Start, GymStarter_Gen6Text_Finish, GymStarter_Gen6BattleOver
	return


GymStarter_Gen6BattleOver::
	lockall
	msgbox GymStarter_Gen6BattleOver_Text_0
	givemon SPECIES_FROAKIE, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen6BattleOver_2
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen6BattleOver_3
	msgbox GymStarter_Gen6BattleOver_Text_2
GymStarter_Gen6BattleOver_1:
	givemon SPECIES_CHESPIN, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen6BattleOver_8
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen6BattleOver_9
	msgbox GymStarter_Gen6BattleOver_Text_2
GymStarter_Gen6BattleOver_7:
	givemon SPECIES_FENNEKIN, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen6BattleOver_14
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen6BattleOver_15
	msgbox GymStarter_Gen6BattleOver_Text_2
GymStarter_Gen6BattleOver_13:
	msgbox GymStarter_Gen6BattleOver_Text_5
	releaseall
	return

GymStarter_Gen6BattleOver_2:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen6BattleOver_Text_1
	setflag FLAG_RECIEVED_GEN6
	call NicknamePartyMon
	goto GymStarter_Gen6BattleOver_1

GymStarter_Gen6BattleOver_3:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN6
	call NicknameBoxMon
	goto GymStarter_Gen6BattleOver_1

GymStarter_Gen6BattleOver_8:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen6BattleOver_Text_3
	setflag FLAG_RECIEVED_GEN6
	call NicknamePartyMon
	goto GymStarter_Gen6BattleOver_7

GymStarter_Gen6BattleOver_9:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN6
	call NicknameBoxMon
	goto GymStarter_Gen6BattleOver_7

GymStarter_Gen6BattleOver_14:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen6BattleOver_Text_4
	setflag FLAG_RECIEVED_GEN6
	call NicknamePartyMon
	goto GymStarter_Gen6BattleOver_13

GymStarter_Gen6BattleOver_15:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN6
	call NicknameBoxMon
	goto GymStarter_Gen6BattleOver_13


FortreeCity_PokemonCenter_1F_EventScript_Starters_Text_0:
	.string "I hope you like them.$"

FortreeCity_PokemonCenter_1F_EventScript_Starters_Text_1:
	.string "Hey you, I found these pokemon around\n"
	.string "here. They aren't really my thing\l"
	.string "though, would you like them?$"

FortreeCity_PokemonCenter_1F_EventScript_Starters_Text_2:
	.string "Eh whatever. Maybe the next trainer will\n"
	.string "take them.$"

FortreeCity_PokemonCenter_1F_EventScript_Starters_Text_3:
	.string "Todays catch was terrible, absolutely\n"
	.string "no bugs.$"

GymStarter_Gen6BattleOver_Text_0:
	.string "Well here they are, should do better in\n"
	.string "your hands than mine$"

GymStarter_Gen6BattleOver_Text_1:
	.string "You recieved a Froakie!$"

GymStarter_Gen6BattleOver_Text_2:
	.string "There was no room$"

GymStarter_Gen6BattleOver_Text_3:
	.string "You recieved a Chespin!$"

GymStarter_Gen6BattleOver_Text_4:
	.string "You recieved a Fennekin!$"

GymStarter_Gen6BattleOver_Text_5:
	.string "Thanks for taking them off my hands$"

GymStarter_Gen6Text_Start::
	.string "What? You think I would give them to\n"
	.string "you without a battle atleast?$"

GymStarter_Gen6Text_Finish::
	.string "Well that's about expected. I didn't\n"
	.string "have my bug pokemon$"
