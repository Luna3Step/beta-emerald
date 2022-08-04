.set LOCALID_NURSE, 1

SootopolisCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SootopolisCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	end

SootopolisCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn:
	.string "WALLACE is rumored to be the toughest\n"
	.string "TRAINER in the whole HOENN region.\p"
	.string "This town's GYM is led by the TRAINER\n"
	.string "who taught WALLACE.\p"
	.string "But the ELITE FOUR… They're said to be\n"
	.string "even stronger than WALLACE's mentor.\p"
	.string "How strong could they be?$"

SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge:
	.string "Everyone in town has taken refuge\n"
	.string "and won't come out of their homes.\p"
	.string "Even I would rather not venture\n"
	.string "outside.$"

SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon:
	.string "Whenever, wherever, and whatever\n"
	.string "happens, I will always be friends with\l"
	.string "POKéMON.\p"
	.string "Because it's fun to be with POKéMON!$"

SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends:
	.string "Aren't POKéMON our friends?\p"
	.string "Why are they going wild this way?$"

SootopolisCity_PokemonCenter_1F_EventScript_Starters::
	lockall
	faceplayer
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_PokemonCenter_1F_EventScript_Starters_1
	lockall
	msgbox SootopolisCity_PokemonCenter_1F_EventScript_Starters_Text_3
	waitmessage
	releaseall
	return

SootopolisCity_PokemonCenter_1F_EventScript_Starters_1:
	goto_if_set FLAG_RECIEVED_GEN8, SootopolisCity_PokemonCenter_1F_EventScript_Starters_4
	msgbox SootopolisCity_PokemonCenter_1F_EventScript_Starters_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SootopolisCity_PokemonCenter_1F_EventScript_Starters_7
	msgbox SootopolisCity_PokemonCenter_1F_EventScript_Starters_Text_2
	waitmessage
	releaseall
	end

SootopolisCity_PokemonCenter_1F_EventScript_Starters_4:
	lockall
	msgbox SootopolisCity_PokemonCenter_1F_EventScript_Starters_Text_0
	waitmessage
	releaseall
	return

SootopolisCity_PokemonCenter_1F_EventScript_Starters_7:
	trainerbattle_single TRAINER_SOOTOPOLIS_POKECENTER, GymStarter_Gen8Text_Start, GymStarter_Gen8Text_Finish, GymStarter_Gen8BattleOver
	return


GymStarter_Gen8BattleOver::
	lockall
	msgbox GymStarter_Gen8BattleOver_Text_0
	givemon SPECIES_SOBBLE, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen8BattleOver_2
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen8BattleOver_3
	msgbox GymStarter_Gen8BattleOver_Text_2
GymStarter_Gen8BattleOver_1:
	givemon SPECIES_GROOKEY, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen8BattleOver_8
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen8BattleOver_9
	msgbox GymStarter_Gen8BattleOver_Text_2
GymStarter_Gen8BattleOver_7:
	givemon SPECIES_SCORBUNNY, 15, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq GymStarter_Gen8BattleOver_14
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq GymStarter_Gen8BattleOver_15
	msgbox GymStarter_Gen8BattleOver_Text_2
GymStarter_Gen8BattleOver_13:
	msgbox GymStarter_Gen8BattleOver_Text_5
	releaseall
	return

GymStarter_Gen8BattleOver_2:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen8BattleOver_Text_1
	setflag FLAG_RECIEVED_GEN8
	call NicknamePartyMon
	goto GymStarter_Gen8BattleOver_1

GymStarter_Gen8BattleOver_3:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN8
	call NicknameBoxMon
	goto GymStarter_Gen8BattleOver_1

GymStarter_Gen8BattleOver_8:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen8BattleOver_Text_3
	setflag FLAG_RECIEVED_GEN8
	call NicknamePartyMon
	goto GymStarter_Gen8BattleOver_7

GymStarter_Gen8BattleOver_9:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN8
	call NicknameBoxMon
	goto GymStarter_Gen8BattleOver_7

GymStarter_Gen8BattleOver_14:
	playfanfare MUS_OBTAIN_ITEM
	msgbox GymStarter_Gen8BattleOver_Text_4
	setflag FLAG_RECIEVED_GEN8
	call NicknamePartyMon
	goto GymStarter_Gen8BattleOver_13

GymStarter_Gen8BattleOver_15:
	playfanfare MUS_OBTAIN_ITEM
	setflag FLAG_RECIEVED_GEN8
	call NicknameBoxMon
	goto GymStarter_Gen8BattleOver_13


SootopolisCity_PokemonCenter_1F_EventScript_Starters_Text_0:
	.string "Good riddance.$"

SootopolisCity_PokemonCenter_1F_EventScript_Starters_Text_1:
	.string "I recently got scammed in a trade, how\n"
	.string "you feel about taking these pokemon\l"
	.string "off my hands?$"

SootopolisCity_PokemonCenter_1F_EventScript_Starters_Text_2:
	.string "Why does that not surprise me.$"

SootopolisCity_PokemonCenter_1F_EventScript_Starters_Text_3:
	.string "I already have these pokemon, why was I\n"
	.string "such a fool.$"

GymStarter_Gen8BattleOver_Text_0:
	.string "Here, take them. The sooner the better$"

GymStarter_Gen8BattleOver_Text_1:
	.string "You recieved a Sobble!$"

GymStarter_Gen8BattleOver_Text_2:
	.string "There was no room$"

GymStarter_Gen8BattleOver_Text_3:
	.string "You recieved a Grookey!$"

GymStarter_Gen8BattleOver_Text_4:
	.string "You recieved a Scorbunny!$"

GymStarter_Gen8BattleOver_Text_5:
	.string "Well hopefully you atleast get some joy\n"
	.string "from them.$"

GymStarter_Gen8Text_Start::
	.string "Is this not common courtesy among\n"
	.string "trainers?$"

GymStarter_Gen8Text_Finish::
	.string "How violent.$"
