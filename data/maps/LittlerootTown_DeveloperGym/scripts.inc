LittlerootTown_DeveloperGym_MapScripts::
	.byte 0


LittlerootTown_DeveloperGym_EventScript_AdrianBattle::
	lockall
	trainerbattle_single TRAINER_ADRIAN, Adrian_Intro, Adrian_Outro, RivalBattleOver
	end


AdrianBattleOver::
	lockall
	msgbox AdrianBattleOver_Text_0
	giveitem ITEM_MASTER_BALL, 1
	waitmessage
	releaseall
	return


LittlerootTown_DeveloperGym_EventScript_LunaBattle::
	lockall
	trainerbattle_single TRAINER_LUNA, Luna_Intro, Luna_Outro, RivalBattleOver
	end


LunaBattleOver::
	lockall
	msgbox LunaBattleOver_Text_0
	giveitem ITEM_MASTER_BALL, 1
	waitmessage
	releaseall
	return


AdrianBattleOver_Text_0:
	.string "Here, take this.$"

LunaBattleOver_Text_0:
	.string "Thank you for getting this far. If you\n"
	.string "wish to see future updates or future\l"
	.string "hacks made by me and other members of\l"
	.string "the team, please follow the discord. As\l"
	.string "a thank you, take this.$"

Adrian_Intro::
	.string "This is a test$"

Adrian_Outro::
	.string "This was a good test$"

Luna_Intro::
	.string "Hi, I'm the developer of this hack, Luna, I hope you enjoyed the game.$"

Luna_Outro::
	.string "I hope you enjoyed my favourite team! If you can guess the theme, I'll give you a cookie.$"
