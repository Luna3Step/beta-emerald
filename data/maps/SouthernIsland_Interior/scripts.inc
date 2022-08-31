.set LOCALID_LATI, 2

SouthernIsland_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SouthernIsland_Interior_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SouthernIsland_Interior_OnTransition
	.byte 0

SouthernIsland_Interior_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SouthernIsland_Interior_EventScript_TryRemoveLati
	end

SouthernIsland_Interior_EventScript_TryRemoveLati::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_LATI
	return

SouthernIsland_Interior_OnTransition:
	call_if_unset FLAG_TEAM_ROCKET, SouthernIsland_Interior_EventScript_ClearRocket
	call_if_eq VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetUpLatios
	call_if_ne VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetUpLatias
	call SouthernIsland_Interior_EventScript_SetUpPlayerGfx
	end

SouthernIsland_Interior_EventScript_SetUpLatios::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIOS
	setvar VAR_TEMP_4, SPECIES_LATIOS
	return

SouthernIsland_Interior_EventScript_SetUpLatias::
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_LATIAS
	setvar VAR_TEMP_4, SPECIES_LATIAS
	return

SouthernIsland_Interior_EventScript_SetUpPlayerGfx::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SouthernIsland_Interior_EventScript_SetBrendanGfx
	goto_if_eq VAR_RESULT, FEMALE, SouthernIsland_Interior_EventScript_SetMayGfx
	end

SouthernIsland_Interior_EventScript_SetBrendanGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return

SouthernIsland_Interior_EventScript_SetMayGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

SouthernIsland_Interior_EventScript_TryLatiEncounter::
	lockall
	setvar VAR_0x8008, 12  @ Player's Y coordinate. Not read
	goto SouthernIsland_Interior_EventScript_Lati
	end

SouthernIsland_Interior_EventScript_Lati::
	goto_if_set FLAG_TEMP_2, SouthernIsland_Interior_EventScript_Sign
	goto_if_set FLAG_DEFEATED_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_Sign
	goto_if_set FLAG_CAUGHT_LATIAS_OR_LATIOS, SouthernIsland_Interior_EventScript_Sign
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, SouthernIsland_Interior_EventScript_Sign
	setflag FLAG_ENCOUNTERED_LATIAS_OR_LATIOS
	setflag FLAG_TEMP_2
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanUp
	waitmovement 0
	delay 50
	waitse
	playmoncry VAR_TEMP_4, CRY_MODE_NORMAL
	delay 30
	waitmoncry
	addobject LOCALID_LATI
	delay 30
	applymovement OBJ_EVENT_ID_CAMERA, SouthernIsland_Interior_Movement_CameraPanDown
	applymovement LOCALID_LATI, SouthernIsland_Interior_Movement_LatiApproach
	waitmovement 0
	delay 50
	special RemoveCameraObject
	setvar VAR_LAST_TALKED, LOCALID_LATI
	call_if_eq VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetLatiosBattleVars
	call_if_ne VAR_ROAMER_POKEMON, 0, SouthernIsland_Interior_EventScript_SetLatiasBattleVars
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLatiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, SouthernIsland_Interior_EventScript_PlayerWon
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SouthernIsland_Interior_EventScript_LatiDefeated
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SouthernIsland_Interior_EventScript_RanFromLati
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SouthernIsland_Interior_EventScript_RanFromLati
	setflag FLAG_CAUGHT_LATIAS_OR_LATIOS
	releaseall
	end

SouthernIsland_Interior_EventScript_LatiDefeated::
	setflag FLAG_DEFEATED_LATIAS_OR_LATIOS
	copyvar VAR_0x8004, VAR_TEMP_4
	goto Common_EventScript_LegendaryFlewAway
	end

SouthernIsland_Interior_EventScript_RanFromLati::
	copyvar VAR_0x8004, VAR_TEMP_4
	goto Common_EventScript_LegendaryFlewAway
	end

SouthernIsland_Interior_EventScript_Sign::
	msgbox SouthernIsland_Interior_Text_Sign, MSGBOX_DEFAULT
	releaseall
	end

SouthernIsland_Interior_EventScript_SetLatiosBattleVars::
	seteventmon SPECIES_LATIOS, 50, ITEM_SOUL_DEW
	return

SouthernIsland_Interior_EventScript_SetLatiasBattleVars::
	seteventmon SPECIES_LATIAS, 50, ITEM_SOUL_DEW
	return

SouthernIsland_Interior_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

SouthernIsland_Interior_Movement_CameraPanDown:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	step_end

SouthernIsland_Interior_Movement_LatiApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SouthernIsland_Interior_EventScript_ClearRocket::
	setflag FLAG_TEAM_ROCKET
	return


SouthernIsland_Interior_EventScript_PlayerWon::
	lockall
	setflag FLAG_DEFEATED_LATIAS_OR_LATIOS
	delay 30
	addobject 3
	addobject 4
	addobject 5
	applymovement 3, SouthernIsland_Interior_EventScript_RocketWalkUp
	applymovement 4, SouthernIsland_Interior_EventScript_RocketWalkUp
	waitmovement 0
	msgbox SouthernIsland_Interior_EventScript_PlayerWon_Text_0
	waitmessage
	msgbox SouthernIsland_Interior_EventScript_PlayerWon_Text_1
	waitmessage
	msgbox SouthernIsland_Interior_EventScript_PlayerWon_Text_2
	waitmessage
	msgbox SouthernIsland_Interior_EventScript_PlayerWon_Text_3
	waitmessage
	msgbox SouthernIsland_Interior_EventScript_PlayerWon_Text_4
	waitmessage
	msgbox SouthernIsland_Interior_EventScript_PlayerWon_Text_5
	waitmessage
	msgbox SouthernIsland_Interior_EventScript_PlayerWon_Text_6
	waitmessage
	msgbox SouthernIsland_Interior_EventScript_PlayerWon_Text_7
	waitmessage
	msgbox SouthernIsland_Interior_EventScript_PlayerWon_Text_8
	waitmessage
	msgbox SouthernIsland_Interior_EventScript_PlayerWon_Text_9
	waitmessage
	applymovement 5, SouthernIsland_Interior_EventScript_MeowthRun
	msgbox SouthernIsland_Interior_EventScript_PlayerWon_Text_10
	waitmessage
	applymovement 3, Common_Movement_QuestionMark
	applymovement 4, Common_Movement_QuestionMark
	applymovement 5, Common_Movement_QuestionMark
	waitmovement 0
	msgbox SouthernIsland_Interior_EventScript_PlayerWon_Text_11
	waitmessage
	msgbox SouthernIsland_Interior_EventScript_PlayerWon_Text_12
	waitmessage
	msgbox SouthernIsland_Interior_EventScript_PlayerWon_Text_13
	waitmessage
	trainerbattle_double TRAINER_JESSIE_JAMES, SouthernIsland_Interior_Text_RocketOpening, SouthernIsland_Interior_Text_RocketBeaten, SouthernIsland_Interior_Text_RocketNotEnoughPokemon, SouthernIsland_Interior_EventScript_TeamRocketPlayerWin
	releaseall
	return


SouthernIsland_Interior_EventScript_TeamRocketPlayerWin::
	lockall
	msgbox SouthernIsland_Interior_EventScript_TeamRocketPlayerWin_Text_0
	waitmessage
	msgbox SouthernIsland_Interior_EventScript_TeamRocketPlayerWin_Text_1
	delay 50
	applymovement 3, SouthernIsland_Interior_EventScript_RocketRetreat
	applymovement 4, SouthernIsland_Interior_EventScript_RocketRetreat
	waitmovement 0
	removeobject 3
	removeobject 4
	waitmessage
	applymovement 5, Common_Movement_QuestionMark
	msgbox SouthernIsland_Interior_EventScript_TeamRocketPlayerWin_Text_2
	delay 30
	applymovement 5, SouthernIsland_Interior_EventScript_MeowthRetreat
	waitmovement 0
	removeobject 5
	releaseall
	return


SouthernIsland_Interior_EventScript_RocketWalkUp:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SouthernIsland_Interior_EventScript_MeowthRun:
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	face_up
	step_end

SouthernIsland_Interior_EventScript_RocketRetreat:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SouthernIsland_Interior_EventScript_MeowthRetreat:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

SouthernIsland_Interior_EventScript_PlayerWon_Text_0:
	.string "??????: Prepare for trouble!$"

SouthernIsland_Interior_EventScript_PlayerWon_Text_1:
	.string "??????: Make it double!$"

SouthernIsland_Interior_EventScript_PlayerWon_Text_2:
	.string "??????: To protect the world from\n"
	.string "devastation!$"

SouthernIsland_Interior_EventScript_PlayerWon_Text_3:
	.string "??????: To unite all peoples within our\n"
	.string "nation!$"

SouthernIsland_Interior_EventScript_PlayerWon_Text_4:
	.string "??????: To denounce the evils of truth\n"
	.string "and love!$"

SouthernIsland_Interior_EventScript_PlayerWon_Text_5:
	.string "??????: To extend our reach to the\n"
	.string "stars above!$"

SouthernIsland_Interior_EventScript_PlayerWon_Text_6:
	.string "??????: Jessie!$"

SouthernIsland_Interior_EventScript_PlayerWon_Text_7:
	.string "??????: James!$"

SouthernIsland_Interior_EventScript_PlayerWon_Text_8:
	.string "Jessie: Team Rocket blasts off at the\n"
	.string "speed of light!$"

SouthernIsland_Interior_EventScript_PlayerWon_Text_9:
	.string "James: Surrender now or prepare to\n"
	.string "fight!$"

SouthernIsland_Interior_EventScript_PlayerWon_Text_10:
	.string "Meowth: Meowth! That's right!$"

SouthernIsland_Interior_EventScript_PlayerWon_Text_11:
	.string "James: Jessie, I don't see the rare\n"
	.string "pokemon that was meant to be here$"

SouthernIsland_Interior_EventScript_PlayerWon_Text_12:
	.string "Jessie: Yeah, all I see is a twerp$"

SouthernIsland_Interior_EventScript_PlayerWon_Text_13:
	.string "Meowth: The twerp look's like they have\n"
	.string "some good pokemon on them?$"

SouthernIsland_Interior_EventScript_TeamRocketPlayerWin_Text_0:
	.string "James: This doesn't look good!$"

SouthernIsland_Interior_EventScript_TeamRocketPlayerWin_Text_1:
	.string "Jessie: Let's scram!$"

SouthernIsland_Interior_EventScript_TeamRocketPlayerWin_Text_2:
	.string "Meowth: Wait, don't leave me behind!$"

SouthernIsland_Interior_Text_RocketOpening::
	.string "Jessie: Well let's take them!$"

SouthernIsland_Interior_Text_RocketBeaten::
	.string "James: What are we going to tell the\n"
	.string "boss?$"

SouthernIsland_Interior_Text_RocketNotEnoughPokemon::
	.string "Meowth: Hey kid, we aren't mean enough\n"
	.string "to fight you when you are down a\l"
	.string "Pokemon.$"

SouthernIsland_Interior_Text_RocketClosing::
	.string "Meowth: I don't like where this going,\n"
	.string "Let's scramble!$"
