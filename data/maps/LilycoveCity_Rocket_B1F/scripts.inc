LilycoveCity_Rocket_B1F_MapScripts::
	.byte 0


LilycoveCity_Rocket_B1F_Janet::
	trainerbattle_single TRAINER_JANET, LilycoveCity_Rocket_B1F_Janet_Intro, LilycoveCity_Rocket_B1F_Janet_Outro
	end


LilycoveCity_Rocket_B1F_Kelli::
	trainerbattle_single TRAINER_KELLI, LilycoveCity_Rocket_B1F_Kelli_Intro, LilycoveCity_Rocket_B1F_Kelli_Outro
	end


LilycoveCity_Rocket_B1F_Verna::
	trainerbattle_single TRAINER_VERNA, LilycoveCity_Rocket_B1F_Verna_Intro, LilycoveCity_Rocket_B1F_Verna_Outro
	end


LilycoveCity_Rocket_B1F_Chas::
	trainerbattle_single TRAINER_CHAS, LilycoveCity_Rocket_B1F_Chas_Intro, LilycoveCity_Rocket_B1F_Chas_Outro
	end


LilycoveCity_Rocket_B1F_Danial::
	trainerbattle_single TRAINER_DANIAL, LilycoveCity_Rocket_B1F_Danial_Intro, LilycoveCity_Rocket_B1F_Danial_Outro
	end


LilycoveCity_Rocket_B1F_Lora::
	trainerbattle_single TRAINER_LORA, LilycoveCity_Rocket_B1F_Lora_Intro, LilycoveCity_Rocket_B1F_Lora_Outro
	end


LilycoveCity_Rocket_B1F_Assault_Vest::
	lockall
	msgbox LilycoveCity_Rocket_B1F_Assault_Vest_Text_0
	additem ITEM_ASSAULT_VEST, 1
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_Rocket_B1F_Assault_Vest_1
	call Common_EventScript_ShowBagIsFull
	releaseall
	return

LilycoveCity_Rocket_B1F_Assault_Vest_1:
	removeobject 7
	setflag FLAG_B1F_ASSAULT
	waitmessage
	releaseall
	end


LilycoveCity_Rocket_B1F_Rocky_Helmet::
	lockall
	msgbox LilycoveCity_Rocket_B1F_Rocky_Helmet_Text_0
	additem ITEM_ROCKY_HELMET, 1
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_Rocket_B1F_Rocky_Helmet_1
	call Common_EventScript_ShowBagIsFull
	releaseall
	return

LilycoveCity_Rocket_B1F_Rocky_Helmet_1:
	removeobject 8
	setflag FLAG_B1F_ROCKY
	waitmessage
	releaseall
	end


LilycoveCity_Rocket_B1F_Rare_Candy::
	lockall
	msgbox LilycoveCity_Rocket_B1F_Rare_Candy_Text_0
	additem ITEM_RARE_CANDY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_Rocket_B1F_Rare_Candy_1
	call Common_EventScript_ShowBagIsFull
	releaseall
	return

LilycoveCity_Rocket_B1F_Rare_Candy_1:
	removeobject 9
	setflag FLAG_B1F_RARE_CANDY
	waitmessage
	releaseall
	end


LilycoveCity_Rocket_B1F_Assault_Vest_Text_0:
	.string "You found an Assault Vest!$"

LilycoveCity_Rocket_B1F_Rocky_Helmet_Text_0:
	.string "You found a Rocky Helmet!$"

LilycoveCity_Rocket_B1F_Rare_Candy_Text_0:
	.string "You found a Rare Candy!$"

LilycoveCity_Rocket_B1F_Janet_Intro::
	.string "How did you get in here?$"

LilycoveCity_Rocket_B1F_Janet_Outro::
	.string "Well my contract says I only have to\n"
	.string "fight anyone who enters, not actually\l"
	.string "win.$"

LilycoveCity_Rocket_B1F_Kelli_Intro::
	.string "You aren't the janitor!$"

LilycoveCity_Rocket_B1F_Kelli_Outro::
	.string "If anyone asks, I thought you were the\n"
	.string "janitor.$"

LilycoveCity_Rocket_B1F_Verna_Intro::
	.string "Oh I've been wanting to try my team on\n"
	.string "someone!$"

LilycoveCity_Rocket_B1F_Verna_Outro::
	.string "You only won because you broke the one\n"
	.string "pokemon rule.$"

LilycoveCity_Rocket_B1F_Chas_Intro::
	.string "Hey, you need a hardhat for this area!$"

LilycoveCity_Rocket_B1F_Chas_Outro::
	.string "I guess you can go one without a\n"
	.string "hardhat.$"

LilycoveCity_Rocket_B1F_Danial_Intro::
	.string "Be warned, I have an ultra rare pokemon\n"
	.string "that will kick your arse!$"

LilycoveCity_Rocket_B1F_Danial_Outro::
	.string "... Well that was a scam.$"

LilycoveCity_Rocket_B1F_Lora_Intro::
	.string "Can we just not do this today?$"

LilycoveCity_Rocket_B1F_Lora_Outro::
	.string "Go on, take my money already.$"
