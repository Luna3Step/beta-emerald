LilycoveCity_Rocket_B3F_MapScripts::
	.byte 0


LilycoveCity_Rocket_B3F_Mona::
	trainerbattle_single TRAINER_MONA, LilycoveCity_Rocket_B3F_Mona_Intro, LilycoveCity_Rocket_B3F_Mona_Outro
	end


LilycoveCity_Rocket_B3F_Brant::
	trainerbattle_single TRAINER_BRANT, LilycoveCity_Rocket_B3F_Brant_Intro, LilycoveCity_Rocket_B3F_Brant_Outro
	end


LilycoveCity_Rocket_B3F_Lee::
	trainerbattle_single TRAINER_LEE, LilycoveCity_Rocket_B3F_Lee_Intro, LilycoveCity_Rocket_B3F_Lee_Outro
	end


LilycoveCity_Rocket_B3F_Luann::
	trainerbattle_single TRAINER_LUANN, LilycoveCity_Rocket_B3F_Luann_Intro, LilycoveCity_Rocket_B3F_Luann_Outro
	end


LilycoveCity_Rocket_B3F_Malcom::
	trainerbattle_single TRAINER_MALCOM, LilycoveCity_Rocket_B3F_Malcom_Intro, LilycoveCity_Rocket_B3F_Malcom_Outro
	end


LilycoveCity_Rocket_B3F_Marylou::
	trainerbattle_single TRAINER_MARYLOU, LilycoveCity_Rocket_B3F_Marylou_Intro, LilycoveCity_Rocket_B3F_Marylou_Outro
	end


LilycoveCity_Rocket_B3F_Elixir::
	lockall
	msgbox LilycoveCity_Rocket_B3F_Elixir_Text_0
	additem ITEM_ELIXIR, 1
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_Rocket_B3F_Elixir_1
	call Common_EventScript_ShowBagIsFull
	releaseall
	return

LilycoveCity_Rocket_B3F_Elixir_1:
	removeobject 7
	setflag FLAG_B3F_ELIXIR
	waitmessage
	releaseall
	end


LilycoveCity_Rocket_B3F_Max_Ether::
	lockall
	msgbox LilycoveCity_Rocket_B3F_Max_Ether_Text_0
	additem ITEM_MAX_ETHER, 1
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_Rocket_B3F_Max_Ether_1
	call Common_EventScript_ShowBagIsFull
	releaseall
	return

LilycoveCity_Rocket_B3F_Max_Ether_1:
	removeobject 8
	setflag FLAG_B3F_MAX_ELIXIR
	waitmessage
	releaseall
	end


LilycoveCity_Rocket_B3F_Life_Orb::
	lockall
	msgbox LilycoveCity_Rocket_B3F_Life_Orb_Text_0
	additem ITEM_LIFE_ORB, 1
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_Rocket_B3F_Life_Orb_1
	call Common_EventScript_ShowBagIsFull
	releaseall
	return

LilycoveCity_Rocket_B3F_Life_Orb_1:
	removeobject 9
	setflag FLAG_B3F_LIFE_ORB
	waitmessage
	releaseall
	end


LilycoveCity_Rocket_B3F_Elixir_Text_0:
	.string "You found an Elixir!$"

LilycoveCity_Rocket_B3F_Max_Ether_Text_0:
	.string "You found a Max Ether!$"

LilycoveCity_Rocket_B3F_Life_Orb_Text_0:
	.string "You found a Life Orb!$"

LilycoveCity_Rocket_B3F_Mona_Intro::
	.string "Is this going to take long?$"

LilycoveCity_Rocket_B3F_Mona_Outro::
	.string "My team really isn't built around\n"
	.string "endurance.$"

LilycoveCity_Rocket_B3F_Brant_Intro::
	.string "Ah, someone to shake up this boring\n"
	.string "day!$"

LilycoveCity_Rocket_B3F_Brant_Outro::
	.string "Amazing! Your team is amazing!$"

LilycoveCity_Rocket_B3F_Lee_Intro::
	.string "I simply must have your team.$"

LilycoveCity_Rocket_B3F_Lee_Outro::
	.string "Maybe next time.$"

LilycoveCity_Rocket_B3F_Luann_Intro::
	.string "Hey, you don't look like you should be\n"
	.string "here.$"

LilycoveCity_Rocket_B3F_Luann_Outro::
	.string "Can't wait to see the boss get his\n"
	.string "hands on you.$"

LilycoveCity_Rocket_B3F_Malcom_Intro::
	.string "Nothing to see back here.$"

LilycoveCity_Rocket_B3F_Malcom_Outro::
	.string "Go on, waste your time.$"

LilycoveCity_Rocket_B3F_Marylou_Intro::
	.string "Hey, make sure you put a good fight.\n"
	.string "Don't need to be losing to wimps.$"

LilycoveCity_Rocket_B3F_Marylou_Outro::
	.string "Good job I guess. Should save my arse in\n"
	.string "the next round of redundancies\l"
	.string "atleast.$"
