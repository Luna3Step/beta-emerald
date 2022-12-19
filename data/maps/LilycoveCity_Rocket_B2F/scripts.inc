LilycoveCity_Rocket_B2F_MapScripts::
	.byte 0


LilycoveCity_Rocket_B2F_Booker::
	trainerbattle_single TRAINER_BOOKER, LilycoveCity_Rocket_B2F_Booker_Intro, LilycoveCity_Rocket_B2F_Booker_Outro
	end


LilycoveCity_Rocket_B2F_Lucien::
	trainerbattle_single TRAINER_LUCIEN, LilycoveCity_Rocket_B2F_Lucien_Intro, LilycoveCity_Rocket_B2F_Lucien_Outro
	end


LilycoveCity_Rocket_B2F_Kasey::
	trainerbattle_single TRAINER_KASEY, LilycoveCity_Rocket_B2F_Kasey_Intro, LilycoveCity_Rocket_B2F_Kasey_Outro
	end


LilycoveCity_Rocket_B2F_Rene::
	trainerbattle_single TRAINER_RENE, LilycoveCity_Rocket_B2F_Rene_Intro, LilycoveCity_Rocket_B2F_Rene_Outro
	end


LilycoveCity_Rocket_B2F_Alicia::
	trainerbattle_single TRAINER_ALICIA, LilycoveCity_Rocket_B2F_Alicia_Intro, LilycoveCity_Rocket_B2F_Alicia_Outro
	end


LilycoveCity_Rocket_B2F_Leftovers::
	lockall
	msgbox LilycoveCity_Rocket_B2F_Leftovers_Text_0
	additem ITEM_LEFTOVERS, 1
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_Rocket_B2F_Leftovers_1
	call Common_EventScript_ShowBagIsFull
	releaseall
	return

LilycoveCity_Rocket_B2F_Leftovers_1:
	removeobject 6
	setflag FLAG_B2F_LEFTOVERS
	waitmessage
	releaseall
	end


LilycoveCity_Rocket_B2F_Leftovers_Text_0:
	.string "You found some Leftovers!$"

LilycoveCity_Rocket_B2F_Booker_Intro::
	.string "Great. My shift was just about to finish\n"
	.string "up as well.$"

LilycoveCity_Rocket_B2F_Booker_Outro::
	.string "Hope I can clock out before I get the\n"
	.string "blame for this.$"

LilycoveCity_Rocket_B2F_Lucien_Intro::
	.string "You shouldn't be so loud if you're\n"
	.string "attacking a base otherwise it's easy\l"
	.string "for people to wait in anticipation for\l"
	.string "you.$"

LilycoveCity_Rocket_B2F_Lucien_Outro::
	.string "Maybe I should get stronger pokemon\n"
	.string "before trying sneak attacks.$"

LilycoveCity_Rocket_B2F_Kasey_Intro::
	.string "Hey, you can't go ahead. This is like, our\n"
	.string "secret base.$"

LilycoveCity_Rocket_B2F_Kasey_Outro::
	.string "Can you like, please go home?$"

LilycoveCity_Rocket_B2F_Rene_Intro::
	.string "What terrible timing, this book just got\n"
	.string "to the good part.$"

LilycoveCity_Rocket_B2F_Rene_Outro::
	.string "Well now I can atleast read in peace.$"

LilycoveCity_Rocket_B2F_Alicia_Intro::
	.string "What terrible timing, this book just got\n"
	.string "to the good part.$"

LilycoveCity_Rocket_B2F_Alicia_Outro::
	.string "Well now I can atleast read in peace.$"
