LilycoveCity_Rocket_B4F_MapScripts::
	.byte 0


LilycoveCity_Rocket_B4F_Dario::
	trainerbattle_single TRAINER_DARIO, LilycoveCity_Rocket_B4F_Dario_Intro, LilycoveCity_Rocket_B4F_Dario_Outro
	end


LilycoveCity_Rocket_B4F_Eugenia::
	trainerbattle_single TRAINER_EUGENIA, LilycoveCity_Rocket_B4F_Eugenia_Intro, LilycoveCity_Rocket_B4F_Eugenia_Outro
	end


LilycoveCity_Rocket_B4F_Jordan::
	trainerbattle_single TRAINER_JORDAN, LilycoveCity_Rocket_B4F_Jordan_Intro, LilycoveCity_Rocket_B4F_Jordan_Outro
	end


LilycoveCity_Rocket_B4F_Ray::
	trainerbattle_single TRAINER_RAY, LilycoveCity_Rocket_B4F_Ray_Intro, LilycoveCity_Rocket_B4F_Ray_Outro
	end


LilycoveCity_Rocket_B4F_Glenna::
	trainerbattle_single TRAINER_GLENNA, LilycoveCity_Rocket_B4F_Glenna_Intro, LilycoveCity_Rocket_B4F_Glenna_Outro
	end


LilycoveCity_Rocket_B4F_Tricia::
	trainerbattle_single TRAINER_TRICIA, LilycoveCity_Rocket_B4F_Tricia_Intro, LilycoveCity_Rocket_B4F_Tricia_Outro
	end


LilycoveCity_Rocket_B4F_PP_MAX::
	lockall
	msgbox LilycoveCity_Rocket_B4F_PP_MAX_Text_0
	additem ITEM_PP_MAX, 1
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_Rocket_B4F_PP_MAX_1
	call Common_EventScript_ShowBagIsFull
	releaseall
	return

LilycoveCity_Rocket_B4F_PP_MAX_1:
	removeobject 8
	setflag FLAG_B4F_PPMAX
	waitmessage
	releaseall
	end


LilycoveCity_Rocket_B4F_PP_MAX_Text_0:
	.string "You found a PP Max!$"

LilycoveCity_Rocket_B4F_Dario_Intro::
	.string "You've done well to make it this far\n"
	.string "down.$"

LilycoveCity_Rocket_B4F_Dario_Outro::
	.string "I wonder how far you will go.$"

LilycoveCity_Rocket_B4F_Eugenia_Intro::
	.string "Are those lousy louts slacking on the\n"
	.string "job?$"

LilycoveCity_Rocket_B4F_Eugenia_Outro::
	.string "Those bloody idiots couldn't even\n"
	.string "weaken you up enough?!??$"

LilycoveCity_Rocket_B4F_Jordan_Intro::
	.string "Guess I'm the last one.$"

LilycoveCity_Rocket_B4F_Jordan_Outro::
	.string "If the boss asks, it was Dario who was\n"
	.string "posted here.$"

LilycoveCity_Rocket_B4F_Ray_Intro::
	.string "Well what do we have here? A little rat\n"
	.string "I'd say.$"

LilycoveCity_Rocket_B4F_Ray_Outro::
	.string "Mhm. Should have held my tongue there.$"

LilycoveCity_Rocket_B4F_Glenna_Intro::
	.string "Hey, if you have bad pokemon, I'd just\n"
	.string "give them up now.$"

LilycoveCity_Rocket_B4F_Glenna_Outro::
	.string "If I see you again, you are dead meat.$"

LilycoveCity_Rocket_B4F_Tricia_Intro::
	.string "Why do you rat's have to show?$"

LilycoveCity_Rocket_B4F_Tricia_Outro::
	.string "Well, what are you waiting for? Scuttle\n"
	.string "on.$"
