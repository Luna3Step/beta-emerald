NewBirchLab_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, NewBirchLab_OnTransition
    .byte 0

NewBirchLab_OnTransition:
    call_if_eq VAR_LITTLEROOT_STATE, 7, NewBirchLab_SetScientist
    call_if_lt VAR_LITTLEROOT_STATE, 7, NewBirchLab_HideScientist
    end

NewBirchLab_EventScript_Pokeball::
	lockall
	showmonpic SPECIES_EEVEE, 10, 3
	msgbox NewBirchLab_EventScript_Pokeball_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Pokeball_2
	hidemonpic
	msgbox NewBirchLab_EventScript_Pokeball_Text_3, MSGBOX_DEFAULT
NewBirchLab_EventScript_Pokeball_1:
	waitmessage
	releaseall
	end

NewBirchLab_EventScript_Pokeball_2:
	givemon SPECIES_EEVEE, 5, ITEM_PREMIER_BALL
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Pokeball_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Pokeball_6
	hidemonpic
	msgbox NewBirchLab_EventScript_Pokeball_Text_2, MSGBOX_DEFAULT
	goto NewBirchLab_EventScript_Pokeball_1

NewBirchLab_EventScript_Pokeball_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Pokeball_Text_1, MSGBOX_DEFAULT
	removeobject 1
	setflag FLAG_EEVEE_LAB
	call NicknamePartyMon
	goto NewBirchLab_EventScript_Pokeball_1

NewBirchLab_EventScript_Pokeball_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Pokeball_Text_1, MSGBOX_DEFAULT
	removeobject 1
	setflag FLAG_EEVEE_LAB
	call NicknameBoxMon
	goto NewBirchLab_EventScript_Pokeball_1


NicknamePartyMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
	call Common_EventScript_TransferredToPC
	msgbox NicknameBoxMon_Text_0, MSGBOX_DEFAULT
	return

NicknameBoxMon_2:
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


Start_StarterChoose_Sequence::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, MeetBirch
	waitmovement 0
	msgbox BeginAdventureText
	waitmessage
	closemessage
	applymovement 5, ProfMove
	waitmovement 0
	setvar VAR_LITTLEROOT_STATE, 1
	release
	return


Start_StarterChoose_Sequence2::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, MeetBirch2
	waitmovement 0
	goto Start_StarterChoose_Sequence
	return


StopLeaving::
	lockall
	msgbox StopLeaving_Text_0, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, DoNotLeave
	waitmovement 0
	releaseall
	return


DoNotLeave:
	walk_up
	step_end

NewBirchLab_EventScript_Birch::
	goto_if_unset FLAG_WATER_STARTER, NewBirchLab_EventScript_Birch_4
NewBirchLab_EventScript_Birch_3:
	msgbox NewBirchLab_EventScript_Birch_Text_2, MSGBOX_NPC
NewBirchLab_EventScript_Birch_1:
	end

NewBirchLab_EventScript_Birch_2:
	lock
	faceplayer
	message NewBirchLab_EventScript_Birch_Text_0
	scrollingmultichoice 0, 25, 5, 3, 0
	closemessage
	compare VAR_RESULT, 0
	goto_if_eq NewBirchLab_EventScript_Birch_10
	compare VAR_RESULT, 1
	goto_if_eq NewBirchLab_EventScript_Birch_11
	compare VAR_RESULT, 2
	goto_if_eq NewBirchLab_EventScript_Birch_12
	compare VAR_RESULT, 3
	goto_if_eq NewBirchLab_EventScript_Birch_13
	compare VAR_RESULT, 4
	goto_if_eq NewBirchLab_EventScript_Birch_14
	compare VAR_RESULT, 5
	goto_if_eq NewBirchLab_EventScript_Birch_15
	compare VAR_RESULT, 6
	goto_if_eq NewBirchLab_EventScript_Birch_16
	compare VAR_RESULT, 7
	goto_if_eq NewBirchLab_EventScript_Birch_17
NewBirchLab_EventScript_Birch_9:
	msgbox NewBirchLab_EventScript_Birch_Text_1, MSGBOX_DEFAULT
	waitmessage
	release
	goto NewBirchLab_EventScript_Birch_1

NewBirchLab_EventScript_Birch_4:
	goto_if_unset FLAG_GRASS_STARTER, NewBirchLab_EventScript_Birch_6
	goto NewBirchLab_EventScript_Birch_3

NewBirchLab_EventScript_Birch_6:
	goto_if_unset FLAG_FIRE_STARTER, NewBirchLab_EventScript_Birch_2
	goto NewBirchLab_EventScript_Birch_3

NewBirchLab_EventScript_Birch_10:
	call StarterFade
	setvar VAR_STARTER_GEN, 0
	goto NewBirchLab_EventScript_Birch_9

NewBirchLab_EventScript_Birch_11:
	call StarterFade
	setvar VAR_STARTER_GEN, 1
	goto NewBirchLab_EventScript_Birch_9

NewBirchLab_EventScript_Birch_12:
	call StarterFade
	setvar VAR_STARTER_GEN, 2
	goto NewBirchLab_EventScript_Birch_9

NewBirchLab_EventScript_Birch_13:
	call StarterFade
	setvar VAR_STARTER_GEN, 3
	goto NewBirchLab_EventScript_Birch_9

NewBirchLab_EventScript_Birch_14:
	call StarterFade
	setvar VAR_STARTER_GEN, 4
	goto NewBirchLab_EventScript_Birch_9

NewBirchLab_EventScript_Birch_15:
	call StarterFade
	setvar VAR_STARTER_GEN, 5
	goto NewBirchLab_EventScript_Birch_9

NewBirchLab_EventScript_Birch_16:
	call StarterFade
	setvar VAR_STARTER_GEN, 6
	goto NewBirchLab_EventScript_Birch_9

NewBirchLab_EventScript_Birch_17:
	call StarterFade
	setvar VAR_STARTER_GEN, 7
	goto NewBirchLab_EventScript_Birch_9


StarterFade::
	fadescreen FADE_TO_BLACK
	delay 20
	fadescreen FADE_FROM_BLACK
	return


NewBirchLab_EventScript_PokeballOne::
	lockall
	setvar VAR_TEMP_0, 2
	goto_if_unset FLAG_SYS_POKEMON_GET, NewBirchLab_EventScript_PokeballOne_2
	msgbox NewBirchLab_EventScript_PokeballOne_Text_0, MSGBOX_DEFAULT
NewBirchLab_EventScript_PokeballOne_1:
	waitmessage
	releaseall
	end

NewBirchLab_EventScript_PokeballOne_2:
	compare VAR_STARTER_GEN, 0
	goto_if_eq NewBirchLab_EventScript_PokeballOne_5
	compare VAR_STARTER_GEN, 1
	goto_if_eq NewBirchLab_EventScript_PokeballOne_6
	compare VAR_STARTER_GEN, 2
	goto_if_eq NewBirchLab_EventScript_PokeballOne_7
	compare VAR_STARTER_GEN, 3
	goto_if_eq NewBirchLab_EventScript_PokeballOne_8
	compare VAR_STARTER_GEN, 4
	goto_if_eq NewBirchLab_EventScript_PokeballOne_9
	compare VAR_STARTER_GEN, 5
	goto_if_eq NewBirchLab_EventScript_PokeballOne_10
	compare VAR_STARTER_GEN, 6
	goto_if_eq NewBirchLab_EventScript_PokeballOne_11
	compare VAR_STARTER_GEN, 7
	goto_if_eq NewBirchLab_EventScript_PokeballOne_12
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_5:
	bufferspeciesname STR_VAR_1, SPECIES_SQUIRTLE
	setvar VAR_STARTER_CHOICE, SPECIES_SQUIRTLE
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_6:
	bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
	setvar VAR_STARTER_CHOICE, SPECIES_CHIKORITA
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_7:
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
	setvar VAR_STARTER_CHOICE, SPECIES_MUDKIP
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_8:
	bufferspeciesname STR_VAR_1, SPECIES_PIPLUP
	setvar VAR_STARTER_CHOICE, SPECIES_PIPLUP
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_9:
	bufferspeciesname STR_VAR_1, SPECIES_OSHAWOTT
	setvar VAR_STARTER_CHOICE, SPECIES_OSHAWOTT
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_10:
	bufferspeciesname STR_VAR_1, SPECIES_FROAKIE
	setvar VAR_STARTER_CHOICE, SPECIES_FROAKIE
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_11:
	bufferspeciesname STR_VAR_1, SPECIES_POPPLIO
	setvar VAR_STARTER_CHOICE, SPECIES_POPPLIO
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_12:
	bufferspeciesname STR_VAR_1, SPECIES_SOBBLE
	setvar VAR_STARTER_CHOICE, SPECIES_SOBBLE
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballOne_1


NewBirchLab_EventScript_PokeballTwo::
	lockall
	setvar VAR_TEMP_0, 3
	goto_if_unset FLAG_SYS_POKEMON_GET, NewBirchLab_EventScript_PokeballTwo_2
	msgbox NewBirchLab_EventScript_PokeballOne_Text_0, MSGBOX_DEFAULT
NewBirchLab_EventScript_PokeballTwo_1:
	waitmessage
	releaseall
	end

NewBirchLab_EventScript_PokeballTwo_2:
	compare VAR_STARTER_GEN, 0
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_5
	compare VAR_STARTER_GEN, 1
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_6
	compare VAR_STARTER_GEN, 2
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_7
	compare VAR_STARTER_GEN, 3
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_8
	compare VAR_STARTER_GEN, 4
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_9
	compare VAR_STARTER_GEN, 5
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_10
	compare VAR_STARTER_GEN, 6
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_11
	compare VAR_STARTER_GEN, 7
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_12
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_5:
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	setvar VAR_STARTER_CHOICE, SPECIES_BULBASAUR
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_6:
	bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
	setvar VAR_STARTER_CHOICE, SPECIES_CHIKORITA
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_7:
	bufferspeciesname STR_VAR_1, SPECIES_TREECKO
	setvar VAR_STARTER_CHOICE, SPECIES_TREECKO
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_8:
	bufferspeciesname STR_VAR_1, SPECIES_TURTWIG
	setvar VAR_STARTER_CHOICE, SPECIES_TURTWIG
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_9:
	bufferspeciesname STR_VAR_1, SPECIES_SNIVY
	setvar VAR_STARTER_CHOICE, SPECIES_SNIVY
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_10:
	bufferspeciesname STR_VAR_1, SPECIES_CHESPIN
	setvar VAR_STARTER_CHOICE, SPECIES_CHESPIN
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_11:
	bufferspeciesname STR_VAR_1, SPECIES_ROWLET
	setvar VAR_STARTER_CHOICE, SPECIES_ROWLET
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_12:
	bufferspeciesname STR_VAR_1, SPECIES_GROOKEY
	setvar VAR_STARTER_CHOICE, SPECIES_GROOKEY
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballTwo_1


NewBirchLab_EventScript_PokeballThree::
	lockall
	setvar VAR_TEMP_0, 4
	goto_if_unset FLAG_SYS_POKEMON_GET, NewBirchLab_EventScript_PokeballThree_2
	msgbox NewBirchLab_EventScript_PokeballOne_Text_0, MSGBOX_DEFAULT
NewBirchLab_EventScript_PokeballThree_1:
	waitmessage
	releaseall
	end

NewBirchLab_EventScript_PokeballThree_2:
	compare VAR_STARTER_GEN, 0
	goto_if_eq NewBirchLab_EventScript_PokeballThree_5
	compare VAR_STARTER_GEN, 1
	goto_if_eq NewBirchLab_EventScript_PokeballThree_6
	compare VAR_STARTER_GEN, 2
	goto_if_eq NewBirchLab_EventScript_PokeballThree_7
	compare VAR_STARTER_GEN, 3
	goto_if_eq NewBirchLab_EventScript_PokeballThree_8
	compare VAR_STARTER_GEN, 4
	goto_if_eq NewBirchLab_EventScript_PokeballThree_9
	compare VAR_STARTER_GEN, 5
	goto_if_eq NewBirchLab_EventScript_PokeballThree_10
	compare VAR_STARTER_GEN, 6
	goto_if_eq NewBirchLab_EventScript_PokeballThree_11
	compare VAR_STARTER_GEN, 7
	goto_if_eq NewBirchLab_EventScript_PokeballThree_12
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_5:
	bufferspeciesname STR_VAR_1, SPECIES_CHARMANDER
	setvar VAR_STARTER_CHOICE, SPECIES_CHARMANDER
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_6:
	bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
	setvar VAR_STARTER_CHOICE, SPECIES_CYNDAQUIL
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_7:
	bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
	setvar VAR_STARTER_CHOICE, SPECIES_TORCHIC
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_8:
	bufferspeciesname STR_VAR_1, SPECIES_CHIMCHAR
	setvar VAR_STARTER_CHOICE, SPECIES_CHIMCHAR
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_9:
	bufferspeciesname STR_VAR_1, SPECIES_TEPIG
	setvar VAR_STARTER_CHOICE, SPECIES_TEPIG
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_10:
	bufferspeciesname STR_VAR_1, SPECIES_FENNEKIN
	setvar VAR_STARTER_CHOICE, SPECIES_FENNEKIN
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_11:
	bufferspeciesname STR_VAR_1, SPECIES_LITTEN
	setvar VAR_STARTER_CHOICE, SPECIES_LITTEN
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_12:
	bufferspeciesname STR_VAR_1, SPECIES_SCORBUNNY
	setvar VAR_STARTER_CHOICE, SPECIES_SCORBUNNY
	call NewBirchLab_EventScript_GiveStarter
	goto NewBirchLab_EventScript_PokeballThree_1


NewBirchLab_EventScript_GiveStarter::
	showmonpic VAR_STARTER_CHOICE, 10, 3
	msgbox NewBirchLab_EventScript_GiveStarter_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_GiveStarter_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_GiveStarter_1:
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_LITTLEROOT_STATE, 2
	givemon VAR_STARTER_CHOICE, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_GiveStarter_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_GiveStarter_5
	hidemonpic
	msgbox NewBirchLab_EventScript_GiveStarter_Text_3, MSGBOX_DEFAULT
	return

NewBirchLab_EventScript_GiveStarter_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_GiveStarter_Text_1, MSGBOX_DEFAULT
	removeobject VAR_TEMP_0
	clearflag FLAG_RIVAL_BATTLE_LITTLEROOT
	call SetBallFlag
	call NicknamePartyMon
	return

NewBirchLab_EventScript_GiveStarter_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_GiveStarter_Text_1, MSGBOX_DEFAULT
	removeobject VAR_TEMP_0
	clearflag FLAG_RIVAL_BATTLE_LITTLEROOT
	call SetBallFlag
	call NicknameBoxMon
	msgbox NewBirchLab_EventScript_GiveStarter_Text_2, MSGBOX_DEFAULT
	return


SetBallFlag::
	compare VAR_TEMP_0, 2
	goto_if_eq SetBallFlag_2
	compare VAR_TEMP_0, 3
	goto_if_eq SetBallFlag_5
	compare VAR_TEMP_0, 4
	goto_if_eq SetBallFlag_7
	return

SetBallFlag_2:
	setflag FLAG_WATER_STARTER
	return

SetBallFlag_5:
	setflag FLAG_GRASS_STARTER
	return

SetBallFlag_7:
	setflag FLAG_FIRE_STARTER
	return


InitiatePokedexSequence::
	lock
	msgbox InitiatePokedexSequence_Text_0, MSGBOX_DEFAULT
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, TurnToProf
	waitmovement 0
	applymovement 5, NewBirchLab_Movement_Pokedex
	msgbox InitiatePokedexSequence_Text_1, MSGBOX_DEFAULT
	delay 20
	call GivePokedex
	release
	return


InitiatePokedexSequence_2::
	lock
	msgbox InitiatePokedexSequence_Text_0, MSGBOX_DEFAULT
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, TurnToProf
	waitmovement 0
	applymovement 5, NewBirchLab_Movement_Pokedex_2
	waitmovement 0
	msgbox InitiatePokedexSequence_Text_1, MSGBOX_DEFAULT
	delay 20
	call GivePokedex
	release
	return


GivePokedex::
	lock
	playfanfare MUS_OBTAIN_ITEM
	message GivePokedex_Text_0
	waitfanfare
	closemessage
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_ADVENTURE_STARTED
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	setvar VAR_LITTLEROOT_STATE, 4
	msgbox GivePokedex_Text_1, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	msgbox GivePokedex_Text_2, MSGBOX_DEFAULT
	waitmessage
	call UpgradeNationalDex
	release
	return


UpgradeNationalDex::
	lock
	msgbox UpgradeNationalDex_Text_0, MSGBOX_DEFAULT
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
	waitmessage
	waitfanfare
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	closemessage
	release
	return


NewBirchLab_SetScientist::
	clearflag FLAG_NEW_BIRCH_SCIENTIST
	return


NewBirchLab_HideScientist::
	setflag FLAG_NEW_BIRCH_SCIENTIST
	return


NewBirchLab_Scientist::
	lockall
	faceplayer
	msgbox NewBirchLab_Scientist_Text_0
	waitmessage
	releaseall
	return


MeetBirch:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MeetBirch2:
	walk_left
	step_end

ProfMove:
	walk_right
	walk_right
	walk_up
	face_down
	step_end

TurnToProf:
	face_up
	step_end

NewBirchLab_Movement_Pokedex:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBirchLab_Movement_Pokedex_2:
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBirchLab_EventScript_Pokeball_Text_0:
	.string "You found an Eevee. Do you wish to take\n"
	.string "it?$"

NewBirchLab_EventScript_Pokeball_Text_1:
	.string "You found an Eevee!$"

NewBirchLab_EventScript_Pokeball_Text_2:
	.string "There was no room$"

NewBirchLab_EventScript_Pokeball_Text_3:
	.string "You did not take the eevee$"

NicknamePartyMon_Text_0:
	.string "Give it a nickname?$"

NicknameBoxMon_Text_0:
	.string "Transferred to PC$"

StopLeaving_Text_0:
	.string "You Need To Choose a Pokemon$"

NewBirchLab_EventScript_Birch_Text_0:
	.string "Would you like to see more?$"

NewBirchLab_EventScript_Birch_Text_1:
	.string "Choose wisely.$"

NewBirchLab_EventScript_Birch_Text_2:
	.string "Take care of your Pokemon$"

NewBirchLab_EventScript_PokeballOne_Text_0:
	.string "Don't Take Another$"

NewBirchLab_EventScript_GiveStarter_Text_0:
	.string "Do you want to choose {STR_VAR_1}?$"

NewBirchLab_EventScript_GiveStarter_Text_1:
	.string "Recieved {STR_VAR_1}$"

NewBirchLab_EventScript_GiveStarter_Text_2:
	.string "Transferred {STR_VAR_1} to PC$"

NewBirchLab_EventScript_GiveStarter_Text_3:
	.string "No More Room For Pokemon$"

InitiatePokedexSequence_Text_0:
	.string "WAIT A SECOND!!!$"

InitiatePokedexSequence_Text_1:
	.string "This is a gift from me. It will let you\n"
	.string "record pokemon that you encounter on\l"
	.string "your journey. Originally these would be\l"
	.string "used to help research but it's better\l"
	.string "used to help the user with their\l"
	.string "journey.$"

GivePokedex_Text_0:
	.string "{PLAYER} received the POKéDEX!$"

GivePokedex_Text_1:
	.string "Also take these with you$"

GivePokedex_Text_2:
	.string "These allow you to catch your own\n"
	.string "Pokemon$"

UpgradeNationalDex_Text_0:
	.string "Also let me just apply this little tweak.\n"
	.string "We used to give this upgrade for when\l"
	.string "you had seen a certain amount of\l"
	.string "pokemon in Hoenn however it's so cheap\l"
	.string "and easy to make that I might as well\l"
	.string "give it you now.$"

NewBirchLab_Scientist_Text_0:
	.string "It's so nice to be in this new lab. It's\n"
	.string "cleaner and the internet is actually\l"
	.string "useable.$"

BeginAdventureText::
	.string "Birch: Hello {PLAYER}, my name is Prof Birch\n"
	.string "This is my lab.\p"
	.string "Today is the day that you will be\n"
	.string "receiving a Pokemon!\p"
	.string "Now Choose Wisely,\n"
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}If you would like to see more options\l"
	.string "come and talk to me.\n$"

NewBirchLab_NotChosen::
	.string "You did not choose {STR_VAR_1}$"
