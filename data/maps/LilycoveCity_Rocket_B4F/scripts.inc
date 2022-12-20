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


LilycoveCity_Rocket_B4F_Giovanni::
	lockall
	goto_if_set FLAG_BEATEN_GIOVANNI, LilycoveCity_Rocket_B4F_Giovanni_2
	faceplayer
	msgbox LilycoveCity_Rocket_B4F_Giovanni_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LilycoveCity_Rocket_B4F_Giovanni_6
LilycoveCity_Rocket_B4F_Giovanni_5:
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_Rocket_B4F_Giovanni_9
LilycoveCity_Rocket_B4F_Giovanni_8:
	trainerbattle_single TRAINER_GIOVANNI, LilycoveCity_Rocket_B4F_Giovanni_Intro, LilycoveCity_Rocket_B4F_Giovanni_Outro, LilycoveCity_Rocket_B4F_Giovanni_Beaten
LilycoveCity_Rocket_B4F_Giovanni_1:
	releaseall
	return

LilycoveCity_Rocket_B4F_Giovanni_2:
	msgbox LilycoveCity_Rocket_B4F_Giovanni_Text_0
	goto LilycoveCity_Rocket_B4F_Giovanni_1

LilycoveCity_Rocket_B4F_Giovanni_6:
	msgbox LilycoveCity_Rocket_B4F_Giovanni_Text_2
	goto LilycoveCity_Rocket_B4F_Giovanni_5

LilycoveCity_Rocket_B4F_Giovanni_9:
	msgbox LilycoveCity_Rocket_B4F_Giovanni_Text_3
	goto LilycoveCity_Rocket_B4F_Giovanni_8


LilycoveCity_Rocket_B4F_Giovanni_Beaten::
	lockall
	applymovement 7, LilycoveCity_Rocket_B4F_Giovanni_Movement
	waitmovement 0
	msgbox LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_0
	waitmessage
	msgbox LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_1
	waitmessage
	faceplayer
	msgbox LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_2
	waitmessage
	msgbox LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_3
	waitmessage
	msgbox LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_4
	waitmessage
	msgbox LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_5
	waitmessage
	msgbox LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_6
	waitmessage
	msgbox LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_7
	waitmessage
	msgbox LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_8
	waitmessage
	msgbox LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_9
	waitmessage
	setflag FLAG_BEATEN_GIOVANNI
	setvar VAR_FINAL_METEOR, 1
	releaseall
	return


LilycoveCity_Rocket_B4F_Giovanni_Movement:
	face_away_player
	step_end

LilycoveCity_Rocket_B4F_Meteor::
	lockall
	goto_if_set FLAG_BEATEN_GIOVANNI, LilycoveCity_Rocket_B4F_Meteor_2
	msgbox LilycoveCity_Rocket_B4F_Meteor_Text_1
LilycoveCity_Rocket_B4F_Meteor_1:
	releaseall
	return

LilycoveCity_Rocket_B4F_Meteor_2:
	fadescreen FADE_TO_BLACK
	removeobject 9
	fadescreen FADE_FROM_BLACK
	setflag FLAG_ROCKET_METEOR
	msgbox LilycoveCity_Rocket_B4F_Meteor_Text_0
	waitmessage
	goto LilycoveCity_Rocket_B4F_Meteor_1


LilycoveCity_Rocket_B4F_PP_MAX_Text_0:
	.string "You found a PP Max!$"

LilycoveCity_Rocket_B4F_Giovanni_Text_0:
	.string "Time to see which fools let you through.$"

LilycoveCity_Rocket_B4F_Giovanni_Text_1:
	.string "I guess you're our uninvited guest?$"

LilycoveCity_Rocket_B4F_Giovanni_Text_2:
	.string "How naive of you to answer my question\n"
	.string "like that.$"

LilycoveCity_Rocket_B4F_Giovanni_Text_3:
	.string "A liar as well.$"

LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_0:
	.string "What is it with children and ruining my\n"
	.string "plans?$"

LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_1:
	.string "Kanto, Johto and now even Hoenn.$"

LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_2:
	.string "Well I assume you are here for these\n"
	.string "meteor?$"

LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_3:
	.string "Wipe that confused look from your face.$"

LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_4:
	.string "I heard of a young child obstructing\n"
	.string "our operatios at Mt.Pyre.$"

LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_5:
	.string "There cannot be that many young\n"
	.string "children that can interfere with my\l"
	.string "Team Rocket.$"

LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_6:
	.string "So I can only assume it was you.$"

LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_7:
	.string "You can take the meteor, the scientists\n"
	.string "found nothing of worth with them and\l"
	.string "the blackmarket isn't crazy for\l"
	.string "meteors like it used to be.$"

LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_8:
	.string "It's more effort to keep it than to\n"
	.string "throw it out.$"

LilycoveCity_Rocket_B4F_Giovanni_Beaten_Text_9:
	.string "Just be warned that the next time we\n"
	.string "cross paths, I will make sure you face\l"
	.string "the true wrath of Team Rocket.$"

LilycoveCity_Rocket_B4F_Meteor_Text_0:
	.string "You took the Meteor!$"

LilycoveCity_Rocket_B4F_Meteor_Text_1:
	.string "That guy is staring at you menacingly,\n"
	.string "maybe you shouldn't touch the meteor.$"

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

LilycoveCity_Rocket_B4F_Giovanni_Intro::
	.string "I'm impressed you have made it this far.$"

LilycoveCity_Rocket_B4F_Giovanni_Outro::
	.string "How nostalgic. I will step aside this\n"
	.string "time.$"
