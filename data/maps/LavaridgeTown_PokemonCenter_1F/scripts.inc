.set LOCALID_NURSE, 1

LavaridgeTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether:
	.string "I think POKéMON get closer to their\n"
	.string "TRAINERS if they spend time together.\p"
	.string "The longer the better.\n"
	.string "That's what I think.$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate:
	.string "It's sort of magical how just sitting\n"
	.string "in a hot-spring pool can invigorate.\p"
	.string "I wish I could let my POKéMON\n"
	.string "soak, too.$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo:
	.string "Hohoho! Hey, kid, you can reach\n"
	.string "the hot springs from here.\p"
	.string "If POKéMON are getting rest, so too\n"
	.string "should their TRAINERS.$"

LavaridgeTown_PokemonCenter_1F_EventScript_Starters::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_PokemonCenter_1F_EventScript_Starters_1
	lockall
	msgbox LavaridgeTown_PokemonCenter_1F_EventScript_Starters_Text_3
	waitmessage
	releaseall
	return

LavaridgeTown_PokemonCenter_1F_EventScript_Starters_1:
	goto_if_set FLAG_RECIEVED_GEN4, LavaridgeTown_PokemonCenter_1F_EventScript_Starters_4
	msgbox LavaridgeTown_PokemonCenter_1F_EventScript_Starters_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeTown_PokemonCenter_1F_EventScript_Starters_7
	msgbox LavaridgeTown_PokemonCenter_1F_EventScript_Starters_Text_2
	waitmessage
	releaseall
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Starters_4:
	lockall
	msgbox LavaridgeTown_PokemonCenter_1F_EventScript_Starters_Text_0
	waitmessage
	releaseall
	return

LavaridgeTown_PokemonCenter_1F_EventScript_Starters_7:
	trainerbattle_single TRAINER_LAVARIDGE_POKECENTER, GymStarter_Gen4Text_Start, GymStarter_Gen4Text_Finish, GymStarter_Gen4BattleOver
	return


GymStarter_Gen4BattleOver::
	lockall
	msgbox GymStarter_Gen4BattleOver_Text_0
	givemon SPECIES_PIPLUP, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen4BattleOver_2
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen4BattleOver_3
	msgbox GymStarter_Gen4BattleOver_Text_2
GymStarter_Gen4BattleOver_1:
	givemon SPECIES_TURTWIG, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen4BattleOver_8
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen4BattleOver_9
	msgbox GymStarter_Gen4BattleOver_Text_2
GymStarter_Gen4BattleOver_7:
	givemon SPECIES_CHIMCHAR, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen4BattleOver_14
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen4BattleOver_15
	msgbox GymStarter_Gen4BattleOver_Text_2
GymStarter_Gen4BattleOver_13:
	msgbox GymStarter_Gen4BattleOver_Text_5
	releaseall
	return

GymStarter_Gen4BattleOver_2:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen4BattleOver_Text_1
	setflag FLAG_RECIEVED_GEN4
	call NicknamePartyMon
	goto GymStarter_Gen4BattleOver_1

GymStarter_Gen4BattleOver_3:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN4
	call NicknameBoxMon
	goto GymStarter_Gen4BattleOver_1

GymStarter_Gen4BattleOver_8:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen4BattleOver_Text_3
	setflag FLAG_RECIEVED_GEN4
	call NicknamePartyMon
	goto GymStarter_Gen4BattleOver_7

GymStarter_Gen4BattleOver_9:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN4
	call NicknameBoxMon
	goto GymStarter_Gen4BattleOver_7

GymStarter_Gen4BattleOver_14:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen4BattleOver_Text_4
	setflag FLAG_RECIEVED_GEN4
	call NicknamePartyMon
	goto GymStarter_Gen4BattleOver_13

GymStarter_Gen4BattleOver_15:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN4
	call NicknameBoxMon
	goto GymStarter_Gen4BattleOver_13


LavaridgeTown_PokemonCenter_1F_EventScript_Starters_Text_0:
	.string "I still don't know how those critters\n"
	.string "got up that mountain, they were far\l"
	.string "too weak to be living there.$"

LavaridgeTown_PokemonCenter_1F_EventScript_Starters_Text_1:
	.string "What to do, what to do. Just came down\n"
	.string "that mountain and found these\l"
	.string "critters. Can't take them in myself but\l"
	.string "you look like you could take care of\l"
	.string "them. But I'll have to test ya first.\l"
	.string "You up for it?$"

LavaridgeTown_PokemonCenter_1F_EventScript_Starters_Text_2:
	.string "Fair enough, I'll have a look round for\n"
	.string "other trainers. Come see me again if\l"
	.string "you change your mind.$"

LavaridgeTown_PokemonCenter_1F_EventScript_Starters_Text_3:
	.string "Would Flannery be able to take them in?$"

GymStarter_Gen4BattleOver_Text_0:
	.string "After seeing your team, I'm confident\n"
	.string "they will be done well by you. Please\l"
	.string "take them.$"

GymStarter_Gen4BattleOver_Text_1:
	.string "You recieved a Piplup!$"

GymStarter_Gen4BattleOver_Text_2:
	.string "There was no room$"

GymStarter_Gen4BattleOver_Text_3:
	.string "You recieved a Turtwig!$"

GymStarter_Gen4BattleOver_Text_4:
	.string "You recieved a Chimchar!$"

GymStarter_Gen4BattleOver_Text_5:
	.string "I hope you treat them well.$"

GymStarter_Gen4Text_Start::
	.string "I hope you live upto my expectations!$"

GymStarter_Gen4Text_Finish::
	.string "Perfect!$"
