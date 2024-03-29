.set LOCALID_ARCHIE, 2
.set LOCALID_OLD_LADY, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_GRUNT_3, 6
.set LOCALID_GRUNT_4, 7
.set LOCALID_MAXIE, 8

MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	call_if_eq VAR_PYRE_DEOXYS, 0, MtPyre_Summit_EventScript_RemoveEvent
	call_if_eq VAR_PYRE_DEOXYS, 1, MtPyre_Summit_EventScript_AddEvent
	call_if_eq VAR_PYRE_DEOXYS, 2, MtPyre_Summit_EventScript_BeatenRocket
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MAXIE, 23, 6
	setobjectxyperm LOCALID_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	removeobject 18
	removeobject 19
	removeobject 20
	removeobject 21
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "No! Those TEAM MAGMA goons got\n"
	.string "here ahead of us!\p"
	.string "We can't fall behind!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "I thought you were one of the MAGMAS\n"
	.string "who happened to come back…$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Yeah, so you are strong…\n"
	.string "But there're a lot of us!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Hah!\n"
	.string "Too bad for you!\p"
	.string "If you came earlier, you only would've\n"
	.string "had to battle the wimpy TEAM MAGMA.\p"
	.string "But since you arrived now, you have\n"
	.string "to take on us toughies!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Urgh… I should've let you take on\n"
	.string "TEAM MAGMA first…$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "You don't know anything!\n"
	.string "So why are you messing with us?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "You…\n"
	.string "We saw you at MT. CHIMNEY.\p"
	.string "You don't belong to either TEAM,\n"
	.string "so why would you be here?$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "If you're going to mess with anyone,\n"
	.string "let it be TEAM MAGMA…$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Heh, it doesn't matter!\n"
	.string "We bought ourselves some time!\p"
	.string "The BOSS should have snatched what\n"
	.string "he was after!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Oh, I know!\n"
	.string "You tried to join TEAM MAGMA,\l"
	.string "but they wouldn't have you!\p"
	.string "Well, don't think that we'll let you\n"
	.string "join our TEAM AQUA!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "If you want to join TEAM AQUA that\n"
	.string "badly, we can consider it…$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "We have a great combination going\n"
	.string "with us members and our leader.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "ARCHIE: TEAM MAGMA's MAXIE got ahead\n"
	.string "of us, but we also got what we wanted.\p"
	.string "The RED ORB preserved at MT. PYRE…\n"
	.string "I, ARCHIE, now have it in my possession!\p"
	.string "Fufufu… Now we can bring our ultimate\n"
	.string "objective to fruition!\p"
	.string "Okay, TEAM!\n"
	.string "We're pulling out!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "Oh, no…\n"
	.string "This cannot happen…\p"
	.string "Not only the BLUE ORB, but even\n"
	.string "the RED ORB has been taken…\p"
	.string "The BLUE ORB and RED ORB must never\n"
	.string "be separated. They belong together.\p"
	.string "What are those men trying to do with\n"
	.string "the two ORBS?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Oh, yes. Was it TEAM MAGMA who came\n"
	.string "and took the BLUE ORB first?\p"
	.string "Well, in their haste, they left this\n"
	.string "behind.\p"
	.string "I couldn't imagine what exactly it\n"
	.string "could be.\p"
	.string "I would like you to have it.\n"
	.string "Perhaps it will be useful in some way.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "The BLUE ORB and RED ORB taken by\n"
	.string "those sinister men…\p"
	.string "They must never be apart…\n"
	.string "I fear something terrible will happen…$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "Oh, my goodness…\p"
	.string "You say that both GROUDON and KYOGRE\n"
	.string "have been awakened?\p"
	.string "It is said that the BLUE ORB and\n"
	.string "the RED ORB quelled the rage of\l"
	.string "the two POKéMON…\p"
	.string "It is also said that the true owner\n"
	.string "of the ORBS still exists.\p"
	.string "However, no one knows who, or what\n"
	.string "exactly, the ORBS belong to.\p"
	.string "It could be a human, or perhaps\n"
	.string "a POKéMON, but no one knows.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "The two men who took the ORBS came\n"
	.string "back to return them on their own.\p"
	.string "Those men…\n"
	.string "Perhaps they are not so evil after all…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "The embodiments of the land, sea,\n"
	.string "and the sky…\p"
	.string "That is said to be the identities of\n"
	.string "the super-ancient POKéMON…\p"
	.string "In the same way that we humans and\n"
	.string "POKéMON have life, our world, too,\l"
	.string "is alive…\p"
	.string "The super-ancient POKéMON have\n"
	.string "taught us that…$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "MT. PYRE is where we calm the spirits\n"
	.string "of POKéMON that have passed on…\p"
	.string "This is a high place where one can\n"
	.string "see all of HOENN…\p"
	.string "The disembodied spirits of POKéMON\n"
	.string "must find solace here…\p"
	.string "Is it coincidence that you are here…\p"
	.string "Will you hear out my tale? A tale long\n"
	.string "told in the HOENN region?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the POKéMON of the land\l"
	.string "and the POKéMON of the sea…\p"
	.string "The POKéMON of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The POKéMON of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "infernos and vicious storms.\p"
	.string "The BLUE ORB and the RED ORB brought\n"
	.string "an end to the calamity.\p"
	.string "Light poured from the two ORBS and\n"
	.string "becalmed the enraged adversaries.\p"
	.string "The pair, made docile, dove deep into\n"
	.string "the sea where eventually they\l"
	.string "disappeared…$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "I see…\n"
	.string "Well, that, too, is fine…$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAXIE: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "It is my role to pass on the legends\n"
	.string "of HOENN to future generations.\p"
	.string "And the crisis that just ended in\n"
	.string "SOOTOPOLIS rewrote a legend…\p"
	.string "Have you the time to hear the new\n"
	.string "legend of HOENN?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the POKéMON of the land\l"
	.string "and the POKéMON of the sea…\p"
	.string "The POKéMON of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The POKéMON of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "fires and vicious storms.\p"
	.string "It was then that the POKéMON of\n"
	.string "the sky descended from a storm.\p"
	.string "The POKéMON, shining a vivid green,\n"
	.string "becalmed the two enraged POKéMON.\p"
	.string "Then, its duty done, the green POKéMON\n"
	.string "flew off into the wild blue yonder…$"

MtPyre_Summit_Sablenite::
	lockall
	msgbox MtPyre_Summit_Sablenite_Text_0
	additem ITEM_SABLENITE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MtPyre_Summit_Sablenite_1
	call Common_EventScript_ShowBagIsFull
	releaseall
	return

MtPyre_Summit_Sablenite_1:
	removeobject 9
	setflag FLAG_SABLENITE
	waitmessage
	releaseall
	end


MtPyre_Summit_EventScript_RemoveEvent::
	removeobject 10
	setflag FLAG_PYRE_METEOR
	removeobject 11
	setflag FLAG_PYRE_JEWEL
	removeobject 12
	setflag FLAG_PYRE_BILL
	removeobject 13
	setflag FLAG_PYRE_LIL
	removeobject 14
	setflag FLAG_PYRE_TERRELL
	removeobject 15
	setflag FLAG_PYRE_STONE
	removeobject 16
	setflag FLAG_SUMMIT_SCIENTIST_HIDING
	setflag FLAG_SUMMIT_SCIENTIST_METEOR
	removeobject 17
	return


MtPyre_Summit_EventScript_AddEvent::
	clearflag FLAG_PYRE_METEOR
	clearflag FLAG_PYRE_JEWEL
	clearflag FLAG_PYRE_BILL
	clearflag FLAG_PYRE_LIL
	clearflag FLAG_PYRE_TERRELL
	clearflag FLAG_PYRE_STONE
	clearflag FLAG_SUMMIT_SCIENTIST_HIDING
	setflag FLAG_SUMMIT_SCIENTIST_METEOR
	removeobject 17
	return


MtPyre_Summit_EventScript_FuckYouScientist::
	removeobject 17
	return


MtPyre_Summit_EventScript_GruntJewel::
	lockall
	msgbox MtPyre_Summit_EventScript_GruntJewel_Text_0
	waitmessage
	msgbox MtPyre_Summit_EventScript_GruntJewel_Text_1
	waitmessage
	trainerbattle_single TRAINER_JEWEL, MtPyre_Summit_Text_JewelIntro, MtPyre_Summit_Text_JewelOutro
	releaseall
	return


MtPyre_Summit_EventScript_GruntBill::
	lockall
	msgbox MtPyre_Summit_EventScript_GruntBill_Text_0
	waitmessage
	trainerbattle_single TRAINER_ROCKET_BILL, MtPyre_Summit_Text_BillIntro, MtPyre_Summit_Text_BillOutro
	releaseall
	return


MtPyre_Summit_EventScript_GruntLil::
	lockall
	msgbox MtPyre_Summit_EventScript_GruntLil_Text_0
	waitmessage
	trainerbattle_single TRAINER_ROCKET_LIL, MtPyre_Summit_Text_LilIntro, MtPyre_Summit_Text_LilOutro
	releaseall
	return


MtPyre_Summit_EventScript_GruntTerrell::
	lockall
	trainerbattle_single TRAINER_ROCKET_TERREL, MtPyre_Summit_Text_TerrellIntro, MtPyre_Summit_Text_TerrellOutro, MtPyre_Summit_EventScript_ClearRocket
	releaseall
	return


MtPyre_Summit_EventScript_ClearRocket::
	msgbox MtPyre_Summit_EventScript_ClearRocket_Text_0
	waitmessage
	fadescreen FADE_TO_BLACK
	removeobject 11
	removeobject 12
	removeobject 13
	removeobject 14
	goto_if_set FLAG_PYRE_FOUND_SCIENTIST, MtPyre_Summit_EventScript_ClearRocket_2
MtPyre_Summit_EventScript_ClearRocket_1:
	delay 30
	fadescreen FADE_FROM_BLACK
	releaseall
	return

MtPyre_Summit_EventScript_ClearRocket_2:
	setflag FLAG_SUMMIT_SCIENTIST_HIDING
	removeobject 16
	clearflag FLAG_SUMMIT_SCIENTIST_METEOR
	addobject 17
	goto MtPyre_Summit_EventScript_ClearRocket_1


MtPyre_Summit_EventScript_BeatenRocket::
	setflag 11
	setflag 12
	setflag 13
	setflag 14
	return


MtPyre_Summit_EventScript_Stone::
	lockall
	faceplayer
	setflag FLAG_RESCUED_STONE
	msgbox MtPyre_Summit_EventScript_Stone_Text_0
	waitmessage
	msgbox MtPyre_Summit_EventScript_Stone_Text_1
	waitmessage
	msgbox MtPyre_Summit_EventScript_Stone_Text_2
	waitmessage
	msgbox MtPyre_Summit_EventScript_Stone_Text_3
	waitmessage
	msgbox MtPyre_Summit_EventScript_Stone_Text_4
	waitmessage
	releaseall
	return


MtPyre_Summit_EventScript_Scientist::
	lockall
	faceplayer
	goto_if_set FLAG_RESCUED_STONE, MtPyre_Summit_EventScript_Scientist_1
	setflag FLAG_PYRE_FOUND_SCIENTIST
	msgbox MtPyre_Summit_EventScript_Scientist_Text_2
	waitmessage
	msgbox MtPyre_Summit_EventScript_Scientist_Text_3
	waitmessage
	releaseall
	return

MtPyre_Summit_EventScript_Scientist_1:
	setflag FLAG_PYRE_FOUND_SCIENTIST
	msgbox MtPyre_Summit_EventScript_Scientist_Text_0
	waitmessage
	msgbox MtPyre_Summit_EventScript_Scientist_Text_1
	waitmessage
	applymovement 16, Movement_ScientistTakePositionPlease
	setvar VAR_PYRE_DEOXYS, 2
	releaseall
	return


MtPyre_Summit_EventScript_ScientistMeteor::
	lockall
	faceplayer
	msgbox MtPyre_Summit_EventScript_ScientistMeteor_Text_0
	waitmessage
	msgbox MtPyre_Summit_EventScript_ScientistMeteor_Text_1
	waitmessage
	msgbox MtPyre_Summit_EventScript_ScientistMeteor_Text_2
	waitmessage
	applymovement 17, Common_Movement_QuestionMark
	waitmovement 0
	msgbox MtPyre_Summit_EventScript_ScientistMeteor_Text_3
	waitmessage
	msgbox MtPyre_Summit_EventScript_ScientistMeteor_Text_4
	waitmessage
	msgbox MtPyre_Summit_EventScript_ScientistMeteor_Text_5
	waitmessage
	setvar VAR_RUSTURF_DEOXYS, 1
	releaseall
	return


Movement_ScientistTakePositionPlease:
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_LeftGrunt::
	lockall
	faceplayer
	msgbox MtPyre_Summit_LeftGrunt_Text_0
	waitmessage
	releaseall
	return


MtPyre_Summit_RightGrunt::
	lockall
	faceplayer
	msgbox MtPyre_Summit_RightGrunt_Text_0
	waitmessage
	releaseall
	return


MtPyre_Summit_LefterGrunt::
	lockall
	faceplayer
	msgbox MtPyre_Summit_LefterGrunt_Text_0
	waitmessage
	releaseall
	return


MtPyre_Summit_RighterGrunt::
	lockall
	faceplayer
	msgbox MtPyre_Summit_RighterGrunt_Text_0
	waitmessage
	releaseall
	return


MtPyre_Summit_Sablenite_Text_0:
	.string "You found a Sablenite!$"

MtPyre_Summit_EventScript_GruntJewel_Text_0:
	.string "You won't get this rock!$"

MtPyre_Summit_EventScript_GruntJewel_Text_1:
	.string "It is the rightful property of Team\n"
	.string "Rocket!$"

MtPyre_Summit_EventScript_GruntBill_Text_0:
	.string "Team Rocket is investigating here.$"

MtPyre_Summit_EventScript_GruntLil_Text_0:
	.string "Huh? Is that a person I see?$"

MtPyre_Summit_EventScript_ClearRocket_Text_0:
	.string "Boss won't be happy to hear this.$"

MtPyre_Summit_EventScript_Stone_Text_0:
	.string "Mr. Stone: Thank goodness you cleared\n"
	.string "out those ruffians, they were trying\l"
	.string "to steal this meteor here.$"

MtPyre_Summit_EventScript_Stone_Text_1:
	.string "The second I heard that some strange\n"
	.string "meteors had landed in Hoenn, I just\l"
	.string "couldn't resist coming out to see them\l"
	.string "myself.$"

MtPyre_Summit_EventScript_Stone_Text_2:
	.string "But when I arrived, these brutes calling\n"
	.string "themselves 'Team Rocket' were here and\l"
	.string "they quickly took control of the site.$"

MtPyre_Summit_EventScript_Stone_Text_3:
	.string "Thankfully you cleared them out pretty\n"
	.string "quickly, I just hope that's the last we\l"
	.string "will hear of them for the foreseeable\l"
	.string "future$"

MtPyre_Summit_EventScript_Stone_Text_4:
	.string "Talk to the scientist next to me for\n"
	.string "some more details on the meteor.$"

MtPyre_Summit_EventScript_Scientist_Text_0:
	.string "Oh thank goodness Mr.Stone is safe,\n"
	.string "when I saw those Team Rocket people, I\l"
	.string "ran as soon as I could.$"

MtPyre_Summit_EventScript_Scientist_Text_1:
	.string "I just hope Mr.Stone doesn't mind that\n"
	.string "I ran off without helping him.$"

MtPyre_Summit_EventScript_Scientist_Text_2:
	.string "Oh thank goodness you are here, those\n"
	.string "Team Rocket fellows have taken over\l"
	.string "the whole area, it's a disaster, they\l"
	.string "have even got Mr. Stone.$"

MtPyre_Summit_EventScript_Scientist_Text_3:
	.string "I refuse to move from this spot until\n"
	.string "those brute's are gone, no way am I\l"
	.string "being kidnapped today.$"

MtPyre_Summit_EventScript_ScientistMeteor_Text_0:
	.string "Thank you for saving us, those team\n"
	.string "rocket thugs were terrifying.$"

MtPyre_Summit_EventScript_ScientistMeteor_Text_1:
	.string "This meteor is very interesting.\n"
	.string "Comparing the data from Steven, they\l"
	.string "seem to have been a part of the same\l"
	.string "meteor at some point. It's also\l"
	.string "emitting a wave of some sort but my\l"
	.string "tool's aren't giving me much on it.$"

MtPyre_Summit_EventScript_ScientistMeteor_Text_2:
	.string "I hope to get a better look with the lab\n"
	.string "tech once it's transported back.$"

MtPyre_Summit_EventScript_ScientistMeteor_Text_3:
	.string "...$"

MtPyre_Summit_EventScript_ScientistMeteor_Text_4:
	.string "I just got some more information from\n"
	.string "the Weather Institute. With the data\l"
	.string "from these two meteors, they are able\l"
	.string "to roughly calculate the trajectory of\l"
	.string "the other meteors.$"

MtPyre_Summit_EventScript_ScientistMeteor_Text_5:
	.string "They say to check inbetween\n"
	.string "Verdanturf town and Rustboro city.\l"
	.string "They'll double check the math's on the\l"
	.string "final meteor and then send you the\l"
	.string "location for it.$"

MtPyre_Summit_LeftGrunt_Text_0:
	.string "You should talk to our boss.$"

MtPyre_Summit_RightGrunt_Text_0:
	.string "We are so close to our goals.$"

MtPyre_Summit_LefterGrunt_Text_0:
	.string "We will finally stomp those Magma runts\n"
	.string "with this conquest!$"

MtPyre_Summit_RighterGrunt_Text_0:
	.string "Why is that maggots seem to be buzz\n"
	.string "around our boss so often?$"

MtPyre_Summit_Text_BillIntro::
	.string "You'll be sorry for interrupting!$"

MtPyre_Summit_Text_BillOutro::
	.string "Oh, what will the boss say.$"

MtPyre_Summit_Text_TerrellIntro::
	.string "Boss wants this old man, best be on your\n"
	.string "way if you don't wish to be losing those\l"
	.string "pokemon of yours!$"

MtPyre_Summit_Text_TerrellOutro::
	.string "This isn't good.$"

MtPyre_Summit_Text_LilIntro::
	.string "What is the guard doing?!$"

MtPyre_Summit_Text_LilOutro::
	.string "How did you beat me? This shouldn't be\n"
	.string "possible$"

MtPyre_Summit_Text_JewelIntro::
	.string "I'll show you how we deal with types like\n"
	.string "you!$"

MtPyre_Summit_Text_JewelOutro::
	.string "I can't believe this.$"
