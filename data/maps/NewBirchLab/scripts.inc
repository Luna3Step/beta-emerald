NewBirchLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBirchLab_EventScript_BallDefault
	.byte 0


NewBirchLab_EventScript_Pokeball::
	lockall
	showmonpic SPECIES_EEVEE, 10, 3
	msgbox NewBirchLab_EventScript_Pokeball_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Pokeball_2
	hidemonpic
	msgbox NewBirchLab_EventScript_Pokeball_Text_3
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
	msgbox NewBirchLab_EventScript_Pokeball_Text_2
	goto NewBirchLab_EventScript_Pokeball_1

NewBirchLab_EventScript_Pokeball_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Pokeball_Text_1
	removeobject 1
	setflag FLAG_EEVEE_LAB
	call NicknamePartyMon
	goto NewBirchLab_EventScript_Pokeball_1

NewBirchLab_EventScript_Pokeball_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Pokeball_Text_1
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
	msgbox NicknameBoxMon_Text_0
	return

NicknameBoxMon_2:
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


NewBirchLab_EventScript_BallDefault::
	setvar VAR_STARTER_GEN, 2
	return


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
	msgbox NewBirchLab_EventScript_Birch_Text_1
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
	goto_if_unset FLAG_WATER_STARTER, NewBirchLab_EventScript_PokeballOne_4
NewBirchLab_EventScript_PokeballOne_3:
	msgbox NewBirchLab_EventScript_PokeballOne_Text_0
NewBirchLab_EventScript_PokeballOne_1:
	setflag FLAG_SYS_POKEMON_GET
	clearflag FLAG_RIVAL_BATTLE_LITTLEROOT
	waitmessage
	releaseall
	end

NewBirchLab_EventScript_PokeballOne_2:
	compare VAR_STARTER_GEN, 0
	goto_if_eq NewBirchLab_EventScript_PokeballOne_9
	compare VAR_STARTER_GEN, 1
	goto_if_eq NewBirchLab_EventScript_PokeballOne_10
	compare VAR_STARTER_GEN, 2
	goto_if_eq NewBirchLab_EventScript_PokeballOne_11
	compare VAR_STARTER_GEN, 3
	goto_if_eq NewBirchLab_EventScript_PokeballOne_12
	compare VAR_STARTER_GEN, 4
	goto_if_eq NewBirchLab_EventScript_PokeballOne_13
	compare VAR_STARTER_GEN, 5
	goto_if_eq NewBirchLab_EventScript_PokeballOne_14
	compare VAR_STARTER_GEN, 6
	goto_if_eq NewBirchLab_EventScript_PokeballOne_15
	compare VAR_STARTER_GEN, 7
	goto_if_eq NewBirchLab_EventScript_PokeballOne_16
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_4:
	goto_if_unset FLAG_GRASS_STARTER, NewBirchLab_EventScript_PokeballOne_6
	goto NewBirchLab_EventScript_PokeballOne_3

NewBirchLab_EventScript_PokeballOne_6:
	goto_if_unset FLAG_FIRE_STARTER, NewBirchLab_EventScript_PokeballOne_2
	goto NewBirchLab_EventScript_PokeballOne_3

NewBirchLab_EventScript_PokeballOne_9:
	call NewBirchLab_EventScript_Squirtle
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_10:
	call NewBirchLab_EventScript_Totodile
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_11:
	call NewBirchLab_EventScript_Mudkip
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_12:
	call NewBirchLab_EventScript_Piplup
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_13:
	call NewBirchLab_EventScript_Oshawott
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_14:
	call NewBirchLab_EventScript_Froakie
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_15:
	call NewBirchLab_EventScript_Popplio
	goto NewBirchLab_EventScript_PokeballOne_1

NewBirchLab_EventScript_PokeballOne_16:
	call NewBirchLab_EventScript_Sobble
	goto NewBirchLab_EventScript_PokeballOne_1


NewBirchLab_EventScript_PokeballTwo::
	lockall
	goto_if_unset FLAG_WATER_STARTER, NewBirchLab_EventScript_PokeballTwo_4
NewBirchLab_EventScript_PokeballTwo_3:
	msgbox NewBirchLab_EventScript_PokeballOne_Text_0
NewBirchLab_EventScript_PokeballTwo_1:
	setflag FLAG_SYS_POKEMON_GET
	clearflag FLAG_RIVAL_BATTLE_LITTLEROOT
	waitmessage
	releaseall
	end

NewBirchLab_EventScript_PokeballTwo_2:
	compare VAR_STARTER_GEN, 0
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_9
	compare VAR_STARTER_GEN, 1
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_10
	compare VAR_STARTER_GEN, 2
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_11
	compare VAR_STARTER_GEN, 3
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_12
	compare VAR_STARTER_GEN, 4
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_13
	compare VAR_STARTER_GEN, 5
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_14
	compare VAR_STARTER_GEN, 6
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_15
	compare VAR_STARTER_GEN, 7
	goto_if_eq NewBirchLab_EventScript_PokeballTwo_16
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_4:
	goto_if_unset FLAG_GRASS_STARTER, NewBirchLab_EventScript_PokeballTwo_6
	goto NewBirchLab_EventScript_PokeballTwo_3

NewBirchLab_EventScript_PokeballTwo_6:
	goto_if_unset FLAG_FIRE_STARTER, NewBirchLab_EventScript_PokeballTwo_2
	goto NewBirchLab_EventScript_PokeballTwo_3

NewBirchLab_EventScript_PokeballTwo_9:
	call NewBirchLab_EventScript_Bulbasaur
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_10:
	call NewBirchLab_EventScript_Chikorita
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_11:
	call NewBirchLab_EventScript_Treecko
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_12:
	call NewBirchLab_EventScript_Turtwig
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_13:
	call NewBirchLab_EventScript_Snivy
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_14:
	call NewBirchLab_EventScript_Chespin
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_15:
	call NewBirchLab_EventScript_Rowlet
	goto NewBirchLab_EventScript_PokeballTwo_1

NewBirchLab_EventScript_PokeballTwo_16:
	call NewBirchLab_EventScript_Grookey
	goto NewBirchLab_EventScript_PokeballTwo_1


NewBirchLab_EventScript_PokeballThree::
	lockall
	goto_if_unset FLAG_WATER_STARTER, NewBirchLab_EventScript_PokeballThree_4
NewBirchLab_EventScript_PokeballThree_3:
	msgbox NewBirchLab_EventScript_PokeballOne_Text_0
NewBirchLab_EventScript_PokeballThree_1:
	setflag FLAG_SYS_POKEMON_GET
	clearflag FLAG_RIVAL_BATTLE_LITTLEROOT
	waitmessage
	releaseall
	end

NewBirchLab_EventScript_PokeballThree_2:
	compare VAR_STARTER_GEN, 0
	goto_if_eq NewBirchLab_EventScript_PokeballThree_9
	compare VAR_STARTER_GEN, 1
	goto_if_eq NewBirchLab_EventScript_PokeballThree_10
	compare VAR_STARTER_GEN, 2
	goto_if_eq NewBirchLab_EventScript_PokeballThree_11
	compare VAR_STARTER_GEN, 3
	goto_if_eq NewBirchLab_EventScript_PokeballThree_12
	compare VAR_STARTER_GEN, 4
	goto_if_eq NewBirchLab_EventScript_PokeballThree_13
	compare VAR_STARTER_GEN, 5
	goto_if_eq NewBirchLab_EventScript_PokeballThree_14
	compare VAR_STARTER_GEN, 6
	goto_if_eq NewBirchLab_EventScript_PokeballThree_15
	compare VAR_STARTER_GEN, 7
	goto_if_eq NewBirchLab_EventScript_PokeballThree_16
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_4:
	goto_if_unset FLAG_GRASS_STARTER, NewBirchLab_EventScript_PokeballThree_6
	goto NewBirchLab_EventScript_PokeballThree_3

NewBirchLab_EventScript_PokeballThree_6:
	goto_if_unset FLAG_FIRE_STARTER, NewBirchLab_EventScript_PokeballThree_2
	goto NewBirchLab_EventScript_PokeballThree_3

NewBirchLab_EventScript_PokeballThree_9:
	call NewBirchLab_EventScript_Charmander
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_10:
	call NewBirchLab_EventScript_Cyndaquil
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_11:
	call NewBirchLab_EventScript_Torchic
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_12:
	call NewBirchLab_EventScript_Chimchar
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_13:
	call NewBirchLab_EventScript_Tepig
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_14:
	call NewBirchLab_EventScript_Fennekin
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_15:
	call NewBirchLab_EventScript_Litten
	goto NewBirchLab_EventScript_PokeballThree_1

NewBirchLab_EventScript_PokeballThree_16:
	call NewBirchLab_EventScript_Scorbunny
	goto NewBirchLab_EventScript_PokeballThree_1


NewBirchLab_EventScript_Mudkip::
	showmonpic SPECIES_MUDKIP, 10, 3
	msgbox NewBirchLab_EventScript_Mudkip_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Mudkip_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Mudkip_1:
	givemon SPECIES_MUDKIP, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Mudkip_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Mudkip_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Mudkip_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Mudkip_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Mudkip_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Mudkip_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Totodile::
	showmonpic SPECIES_TOTODILE, 10, 3
	msgbox NewBirchLab_EventScript_Totodile_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Totodile_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Totodile_1:
	givemon SPECIES_TOTODILE, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Totodile_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Totodile_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Totodile_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Totodile_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Totodile_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Totodile_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Squirtle::
	showmonpic SPECIES_SQUIRTLE, 10, 3
	msgbox NewBirchLab_EventScript_Squirtle_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Squirtle_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Squirtle_1:
	givemon SPECIES_SQUIRTLE, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Squirtle_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Squirtle_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Squirtle_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Squirtle_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Squirtle_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Squirtle_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Piplup::
	showmonpic SPECIES_PIPLUP, 10, 3
	msgbox NewBirchLab_EventScript_Piplup_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Piplup_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Piplup_1:
	givemon SPECIES_PIPLUP, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Piplup_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Piplup_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Piplup_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Piplup_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Piplup_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Piplup_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Oshawott::
	showmonpic SPECIES_OSHAWOTT, 10, 3
	msgbox NewBirchLab_EventScript_Oshawott_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Oshawott_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Oshawott_1:
	givemon SPECIES_OSHAWOTT, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Oshawott_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Oshawott_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Oshawott_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Oshawott_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Oshawott_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Oshawott_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Froakie::
	showmonpic SPECIES_FROAKIE, 10, 3
	msgbox NewBirchLab_EventScript_Froakie_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Froakie_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Froakie_1:
	givemon SPECIES_FROAKIE, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Froakie_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Froakie_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Froakie_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Froakie_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Froakie_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Froakie_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Popplio::
	showmonpic SPECIES_POPPLIO, 10, 3
	msgbox NewBirchLab_EventScript_Popplio_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Popplio_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Popplio_1:
	givemon SPECIES_POPPLIO, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Popplio_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Popplio_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Popplio_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Popplio_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Popplio_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Popplio_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Sobble::
	showmonpic SPECIES_SOBBLE, 10, 3
	msgbox NewBirchLab_EventScript_Sobble_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Sobble_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Sobble_1:
	givemon SPECIES_SOBBLE, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Sobble_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Sobble_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Sobble_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Sobble_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Sobble_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Sobble_Text_1
	removeobject 2
	setflag FLAG_WATER_STARTER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Treecko::
	showmonpic SPECIES_TREECKO, 10, 3
	msgbox NewBirchLab_EventScript_Treecko_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Treecko_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Treecko_1:
	givemon SPECIES_TREECKO, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Treecko_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Treecko_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Treecko_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Treecko_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Treecko_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Treecko_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Chikorita::
	showmonpic SPECIES_CHIKORITA, 10, 3
	msgbox NewBirchLab_EventScript_Chikorita_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Chikorita_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Chikorita_1:
	givemon SPECIES_CHIKORITA, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Chikorita_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Chikorita_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Chikorita_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Chikorita_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Chikorita_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Chikorita_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Bulbasaur::
	showmonpic SPECIES_BULBASAUR, 10, 3
	msgbox NewBirchLab_EventScript_Bulbasaur_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Bulbasaur_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Bulbasaur_1:
	givemon SPECIES_BULBASAUR, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Bulbasaur_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Bulbasaur_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Bulbasaur_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Bulbasaur_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Bulbasaur_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Bulbasaur_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Turtwig::
	showmonpic SPECIES_TURTWIG, 10, 3
	msgbox NewBirchLab_EventScript_Turtwig_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Turtwig_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Turtwig_1:
	givemon SPECIES_TURTWIG, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Turtwig_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Turtwig_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Turtwig_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Turtwig_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Turtwig_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Turtwig_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Snivy::
	showmonpic SPECIES_SNIVY, 10, 3
	msgbox NewBirchLab_EventScript_Snivy_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Snivy_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Snivy_1:
	givemon SPECIES_SNIVY, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Snivy_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Snivy_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Snivy_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Snivy_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Snivy_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Snivy_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Chespin::
	showmonpic SPECIES_CHESPIN, 10, 3
	msgbox NewBirchLab_EventScript_Chespin_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Chespin_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Chespin_1:
	givemon SPECIES_CHESPIN, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Chespin_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Chespin_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Chespin_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Chespin_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Chespin_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Chespin_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Rowlet::
	showmonpic SPECIES_ROWLET, 10, 3
	msgbox NewBirchLab_EventScript_Rowlet_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Rowlet_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Rowlet_1:
	givemon SPECIES_ROWLET, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Rowlet_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Rowlet_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Rowlet_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Rowlet_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Rowlet_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Rowlet_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Grookey::
	showmonpic SPECIES_GROOKEY, 10, 3
	msgbox NewBirchLab_EventScript_Grookey_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Grookey_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Grookey_1:
	givemon SPECIES_GROOKEY, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Grookey_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Grookey_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Grookey_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Grookey_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Grookey_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Grookey_Text_1
	removeobject 3
	setflag FLAG_GRASS_STARTER
	setvar VAR_STARTER_MON, 0
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Torchic::
	showmonpic SPECIES_TORCHIC, 10, 3
	msgbox NewBirchLab_EventScript_Torchic_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Torchic_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Torchic_1:
	givemon SPECIES_TORCHIC, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Torchic_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Torchic_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Torchic_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Torchic_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Torchic_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Torchic_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Cyndaquil::
	showmonpic SPECIES_CYNDAQUIL, 10, 3
	msgbox NewBirchLab_EventScript_Cyndaquil_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Cyndaquil_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Cyndaquil_1:
	givemon SPECIES_CYNDAQUIL, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Cyndaquil_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Cyndaquil_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Cyndaquil_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Cyndaquil_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Cyndaquil_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Cyndaquil_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Charmander::
	showmonpic SPECIES_CHARMANDER, 10, 3
	msgbox NewBirchLab_EventScript_Charmander_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Charmander_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Charmander_1:
	givemon SPECIES_CHARMANDER, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Charmander_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Charmander_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Charmander_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Charmander_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Charmander_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Charmander_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Chimchar::
	showmonpic SPECIES_CHIMCHAR, 10, 3
	msgbox NewBirchLab_EventScript_Chimchar_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Chimchar_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Chimchar_1:
	givemon SPECIES_CHIMCHAR, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Chimchar_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Chimchar_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Chimchar_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Chimchar_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Chimchar_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Chimchar_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Tepig::
	showmonpic SPECIES_TEPIG, 10, 3
	msgbox NewBirchLab_EventScript_Tepig_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Tepig_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Tepig_1:
	givemon SPECIES_TEPIG, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Tepig_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Tepig_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Tepig_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Tepig_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Tepig_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Tepig_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Fennekin::
	showmonpic SPECIES_FENNEKIN, 10, 3
	msgbox NewBirchLab_EventScript_Fennekin_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Fennekin_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Fennekin_1:
	givemon SPECIES_FENNEKIN, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Fennekin_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Fennekin_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Fennekin_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Fennekin_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Fennekin_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Fennekin_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Litten::
	showmonpic SPECIES_LITTEN, 10, 3
	msgbox NewBirchLab_EventScript_Litten_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Litten_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Litten_1:
	givemon SPECIES_LITTEN, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Litten_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Litten_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Litten_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Litten_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Litten_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Litten_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


NewBirchLab_EventScript_Scorbunny::
	showmonpic SPECIES_SCORBUNNY, 10, 3
	msgbox NewBirchLab_EventScript_Scorbunny_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq NewBirchLab_EventScript_Scorbunny_1
	hidemonpic
	msgbox NewBirchLab_NotChosen
	return

NewBirchLab_EventScript_Scorbunny_1:
	givemon SPECIES_SCORBUNNY, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq NewBirchLab_EventScript_Scorbunny_4
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq NewBirchLab_EventScript_Scorbunny_5
	hidemonpic
	msgbox NewBirchLab_EventScript_Mudkip_Text_2
	return

NewBirchLab_EventScript_Scorbunny_4:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Scorbunny_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknamePartyMon
	return

NewBirchLab_EventScript_Scorbunny_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox NewBirchLab_EventScript_Scorbunny_Text_1
	removeobject 4
	setflag FLAG_FIRE_STARTER
	setvar VAR_STARTER_MON, 1
	setflag FLAG_RESCUED_BIRCH
	call NicknameBoxMon
	return


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

NewBirchLab_EventScript_Birch_Text_0:
	.string "Would you like to see more?$"

NewBirchLab_EventScript_Birch_Text_1:
	.string "Choose wisely.$"

NewBirchLab_EventScript_Birch_Text_2:
	.string "Take care of your Pokemon$"

NewBirchLab_EventScript_PokeballOne_Text_0:
	.string "Don't Take Another$"

NewBirchLab_EventScript_Mudkip_Text_0:
	.string "Do you want to choose Mudkip?$"

NewBirchLab_EventScript_Mudkip_Text_1:
	.string "Recieved Mudkip$"

NewBirchLab_EventScript_Mudkip_Text_2:
	.string "No More Room$"

NewBirchLab_EventScript_Totodile_Text_0:
	.string "Do you want to choose Totodile?$"

NewBirchLab_EventScript_Totodile_Text_1:
	.string "Recieved Totodile$"

NewBirchLab_EventScript_Squirtle_Text_0:
	.string "Do you want to choose Squirtle?$"

NewBirchLab_EventScript_Squirtle_Text_1:
	.string "Recieved Squirtle$"

NewBirchLab_EventScript_Piplup_Text_0:
	.string "Do you want to choose Piplup?$"

NewBirchLab_EventScript_Piplup_Text_1:
	.string "Recieved Piplup$"

NewBirchLab_EventScript_Oshawott_Text_0:
	.string "Do you want to choose Oshawott?$"

NewBirchLab_EventScript_Oshawott_Text_1:
	.string "Recieved Oshawott$"

NewBirchLab_EventScript_Froakie_Text_0:
	.string "Do you want to choose Froakie?$"

NewBirchLab_EventScript_Froakie_Text_1:
	.string "Recieved Froakie$"

NewBirchLab_EventScript_Popplio_Text_0:
	.string "Do you want to choose Popplio?$"

NewBirchLab_EventScript_Popplio_Text_1:
	.string "Recieved Popplio$"

NewBirchLab_EventScript_Sobble_Text_0:
	.string "Do you want to choose Sobble?$"

NewBirchLab_EventScript_Sobble_Text_1:
	.string "Recieved Sobble$"

NewBirchLab_EventScript_Treecko_Text_0:
	.string "Do you want to choose Treecko?$"

NewBirchLab_EventScript_Treecko_Text_1:
	.string "Recieved Treecko$"

NewBirchLab_EventScript_Chikorita_Text_0:
	.string "Do you want to choose Chikorita?$"

NewBirchLab_EventScript_Chikorita_Text_1:
	.string "Recieved Chikorita$"

NewBirchLab_EventScript_Bulbasaur_Text_0:
	.string "Do you want to choose Bulbasaur?$"

NewBirchLab_EventScript_Bulbasaur_Text_1:
	.string "Recieved Bulbasaur$"

NewBirchLab_EventScript_Turtwig_Text_0:
	.string "Do you want to choose Turtwig?$"

NewBirchLab_EventScript_Turtwig_Text_1:
	.string "Recieved Turtwig$"

NewBirchLab_EventScript_Snivy_Text_0:
	.string "Do you want to choose Snivy?$"

NewBirchLab_EventScript_Snivy_Text_1:
	.string "Recieved Snivy$"

NewBirchLab_EventScript_Chespin_Text_0:
	.string "Do you want to choose Chespin?$"

NewBirchLab_EventScript_Chespin_Text_1:
	.string "Recieved Chespin$"

NewBirchLab_EventScript_Rowlet_Text_0:
	.string "Do you want to choose Rowlet?$"

NewBirchLab_EventScript_Rowlet_Text_1:
	.string "Recieved Rowlet$"

NewBirchLab_EventScript_Grookey_Text_0:
	.string "Do you want to choose Grookey?$"

NewBirchLab_EventScript_Grookey_Text_1:
	.string "Recieved Grookey$"

NewBirchLab_EventScript_Torchic_Text_0:
	.string "Do you want to choose Torchic?$"

NewBirchLab_EventScript_Torchic_Text_1:
	.string "Recieved Torchic$"

NewBirchLab_EventScript_Cyndaquil_Text_0:
	.string "Do you want to choose Cyndaquil?$"

NewBirchLab_EventScript_Cyndaquil_Text_1:
	.string "Recieved Cyndaquil$"

NewBirchLab_EventScript_Charmander_Text_0:
	.string "Do you want to choose Charmander?$"

NewBirchLab_EventScript_Charmander_Text_1:
	.string "Recieved Charmander$"

NewBirchLab_EventScript_Chimchar_Text_0:
	.string "Do you want to choose Chimchar?$"

NewBirchLab_EventScript_Chimchar_Text_1:
	.string "Recieved Chimchar$"

NewBirchLab_EventScript_Tepig_Text_0:
	.string "Do you want to choose Tepig?$"

NewBirchLab_EventScript_Tepig_Text_1:
	.string "Recieved Tepig$"

NewBirchLab_EventScript_Fennekin_Text_0:
	.string "Do you want to choose Fennekin?$"

NewBirchLab_EventScript_Fennekin_Text_1:
	.string "Recieved Fennekin$"

NewBirchLab_EventScript_Litten_Text_0:
	.string "Do you want to choose Litten?$"

NewBirchLab_EventScript_Litten_Text_1:
	.string "Recieved Litten$"

NewBirchLab_EventScript_Scorbunny_Text_0:
	.string "Do you want to choose Scorbunny?$"

NewBirchLab_EventScript_Scorbunny_Text_1:
	.string "Recieved Scorbunny$"

NewBirchLab_NotChosen::
	.string "You did not choose the Pokemon$"
