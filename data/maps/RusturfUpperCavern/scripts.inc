RusturfUpperCavern_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, RusturfUpperCavern_OnTransition
    .byte 0

RusturfUpperCavern_OnTransition:
    call_if_eq VAR_RUSTURF_DEOXYS, 0, RusturfUpperCavern_EventScript_RemoveMeteor
    call_if_eq VAR_RUSTURF_DEOXYS, 1, RusturfUpperCavern_EventScript_AddMeteor
    call_if_eq VAR_RUSTURF_DEOXYS, 2, RusturfUpperCavern_EventScript_RemoveMeteor
    end

RusturfUpperCavern_EventScript_RemoveMeteor::
	setflag FLAG_RUSTURF_METEOR
	setflag FLAG_RUSTURF_ROCKET
	return


RusturfUpperCavern_EventScript_AddMeteor::
	clearflag FLAG_RUSTURF_METEOR
	setflag FLAG_RUSTURF_ROCKET
	return


RusturfUpperCavern_EventScript_Meteor::
	lockall
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_0
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_1, MSGBOX_YESNO
	delay 50
	call RusturfUpperCavern_EventScript_Screenshake
	applymovement 6, RusturfUpperCavern_Movement_RocketBalloon
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, RusturfUpperCavern_Movement_CameraUp
	waitmovement 0
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_2
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_3
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_4
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_5
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_6
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_7
	waitmessage
	addobject 3
	applymovement 3, RusturfUpperCavern_Movement_RocketTwats
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_8
	waitmovement 0
	waitmessage
	addobject 4
	applymovement 4, RusturfUpperCavern_Movement_RocketTwats
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_9
	waitmovement 0
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_10
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_11
	waitmessage
	addobject 5
	applymovement 5, RusturfUpperCavern_Movement_RocketTwats
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_12
	waitmessage
	waitmovement 0
	applymovement 3, RusturfUpperCavern_Movement_JessieHuddle
	applymovement 4, RusturfUpperCavern_Movement_JamesHuddle
	waitmovement 0
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_13
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_14
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_15
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_16
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_17
	applymovement 3, Common_Movement_QuestionMark
	applymovement 4, Common_Movement_QuestionMark
	applymovement 5, Common_Movement_QuestionMark
	waitmovement 0
	applymovement 3, RusturfUpperCavern_Movement_FacePlayer
	applymovement 4, RusturfUpperCavern_Movement_FacePlayer
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_18
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_19
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_20
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_21
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_22
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_23
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_24
	waitmessage
	msgbox RusturfUpperCavern_EventScript_Meteor_Text_25
	waitmessage
	fadescreen FADE_TO_BLACK
	removeobject 1
	delay 15
	fadescreen FADE_FROM_BLACK
	applymovement 3, RusturfUpperCavern_Movement_RocketRetreat
	applymovement 4, RusturfUpperCavern_Movement_RocketRetreat
	applymovement 5, RusturfUpperCavern_Movement_RocketRetreat
	waitmovement 0
	removeobject 3
	removeobject 4
	removeobject 5
	delay 30
	call RusturfUpperCavern_EventScript_Screenshake
	applymovement 6, RusturfUpperCavern_Movement_RocketBalloonEscape
	waitmovement 0
	removeobject 6
	applymovement OBJ_EVENT_ID_CAMERA, RusturfUpperCavern_Movement_CameraDown
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_RUSTURF_DEOXYS, 2
	releaseall
	return


RusturfUpperCavern_EventScript_Screenshake::
	delay 30
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 6
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate
	delay 60
	return


RusturfUpperCavern_Movement_RocketBalloon:
	walk_down
	walk_down
	walk_down
	step_end

RusturfUpperCavern_Movement_RocketTwats:
	walk_fast_down
	walk_fast_down
	step_end

RusturfUpperCavern_Movement_JessieHuddle:
	face_right
	step_end

RusturfUpperCavern_Movement_JamesHuddle:
	face_left
	step_end

RusturfUpperCavern_Movement_FacePlayer:
	face_down
	step_end

RusturfUpperCavern_Movement_RocketRetreat:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RusturfUpperCavern_Movement_RocketBalloonEscape:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RusturfUpperCavern_Movement_CameraUp:
	walk_up
	walk_up
	step_end

RusturfUpperCavern_Movement_CameraDown:
	walk_down
	walk_down
	step_end

RusturfUpperCavern_EventScript_Meteor_Text_0:
	.string "It just look's like a normal meteor as\n"
	.string "far as you are concerned.$"

RusturfUpperCavern_EventScript_Meteor_Text_1:
	.string "Do you wish to take it with you?$"

RusturfUpperCavern_EventScript_Meteor_Text_2:
	.string "??????: Prepare for trouble!$"

RusturfUpperCavern_EventScript_Meteor_Text_3:
	.string "??????: Make it double!$"

RusturfUpperCavern_EventScript_Meteor_Text_4:
	.string "??????: To protect the world from\n"
	.string "devastation!$"

RusturfUpperCavern_EventScript_Meteor_Text_5:
	.string "??????: To unite all peoples within our\n"
	.string "nation!$"

RusturfUpperCavern_EventScript_Meteor_Text_6:
	.string "??????: To denounce the evils of truth\n"
	.string "and love!$"

RusturfUpperCavern_EventScript_Meteor_Text_7:
	.string "??????: To extend our reach to the\n"
	.string "stars above!$"

RusturfUpperCavern_EventScript_Meteor_Text_8:
	.string "??????: Jessie!$"

RusturfUpperCavern_EventScript_Meteor_Text_9:
	.string "??????: James!$"

RusturfUpperCavern_EventScript_Meteor_Text_10:
	.string "Jessie: Team Rocket blasts off at the\n"
	.string "speed of light!$"

RusturfUpperCavern_EventScript_Meteor_Text_11:
	.string "James: Surrender now or prepare to\n"
	.string "fight!$"

RusturfUpperCavern_EventScript_Meteor_Text_12:
	.string "Meowth: Meowth! That's right!$"

RusturfUpperCavern_EventScript_Meteor_Text_13:
	.string "James: I guess this is the meteor the\n"
	.string "boss was talking about.$"

RusturfUpperCavern_EventScript_Meteor_Text_14:
	.string "Jessie: Yes, the gadget thing that we\n"
	.string "were given is saying so.$"

RusturfUpperCavern_EventScript_Meteor_Text_15:
	.string "Meowth: So what are we waiting for!\n"
	.string "Let's nab it and scramble before\l"
	.string "anyone see's us.$"

RusturfUpperCavern_EventScript_Meteor_Text_16:
	.string "James: Like that person over there?$"

RusturfUpperCavern_EventScript_Meteor_Text_17:
	.string "Meowth: Like who?$"

RusturfUpperCavern_EventScript_Meteor_Text_18:
	.string "Jessie: Meowth! You said no one would\n"
	.string "be here!$"

RusturfUpperCavern_EventScript_Meteor_Text_19:
	.string "Meowth: Yeah and thing's change, get\n"
	.string "over it.$"

RusturfUpperCavern_EventScript_Meteor_Text_20:
	.string "Jessie: Oh why do I bother.$"

RusturfUpperCavern_EventScript_Meteor_Text_21:
	.string "Meowth: See you later twerp, you didn't\n"
	.string "see us and you definitely won't find us\l"
	.string "at the Rocket Base with this Meteor\l"
	.string "located at Lilycove city.$"

RusturfUpperCavern_EventScript_Meteor_Text_22:
	.string "James: Meowth you fool, why would you\n"
	.string "say that?$"

RusturfUpperCavern_EventScript_Meteor_Text_23:
	.string "Meowth: Gotta keep tradition in\n"
	.string "screwing up ya'know!$"

RusturfUpperCavern_EventScript_Meteor_Text_24:
	.string "James: Oh that make's sense.$"

RusturfUpperCavern_EventScript_Meteor_Text_25:
	.string "Jessie: NO THAT DOESN'T, GET IN THE\n"
	.string "BALLOON.$"
