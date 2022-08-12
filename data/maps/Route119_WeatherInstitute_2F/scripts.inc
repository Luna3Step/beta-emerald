.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 2
.set LOCALID_SHELLY, 3
.set LOCALID_SCIENTIST, 5
.set LOCALID_GRUNT_3, 7
.set LOCALID_GRUNT_4, 8

Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 2, Route119_WeatherInstitute_2F_EventScript_DeoxysSetup
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
	end

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
	setobjectxyperm LOCALID_SCIENTIST, 1, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
    setflag FLAG_WEATHER_INSTITUTE_2F_DEOXYSNPCS
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
	setobjectxyperm LOCALID_SCIENTIST, 4, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
    setflag FLAG_WEATHER_INSTITUTE_2F_DEOXYSNPCS
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
	setobjectxyperm LOCALID_SCIENTIST, 2, 2
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_UP
    setflag FLAG_WEATHER_INSTITUTE_2F_DEOXYSNPCS
	return

Route119_WeatherInstitute_2F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_ShellyDefeated::
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_GRUNT_3
	applymovement LOCALID_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SHELLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SHELLY, Common_Movement_Delay48
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_SHELLY
	removeobject LOCALID_GRUNT_4
	removeobject LOCALID_GRUNT_3
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_SCIENTIST
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 25, ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end

Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM
	return

Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Both defeated
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_faster_down
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
	slide_down
	walk_in_place_faster_left
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_Text_Grunt2Intro:
	.string "The INSTITUTE created a type of\n"
	.string "POKéMON that has something to do with\l"
	.string "the weather. We're here to take them!$"

Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
	.string "Our plan's being spoiled by a kid?$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
	.string "If the POKéMON they made here can\n"
	.string "control the weather freely, then we of\l"
	.string "TEAM AQUA definitely need it!$"

Route119_WeatherInstitute_2F_Text_Grunt3Intro:
	.string "We're TEAM AQUA!\n"
	.string "We appear wherever anything rare is\l"
	.string "found!$"

Route119_WeatherInstitute_2F_Text_Grunt3Defeat:
	.string "You got me!$"

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle:
	.string "You don't have any idea what we of\n"
	.string "TEAM AQUA are working towards!\l"
	.string "You stay out of our way!$"

Route119_WeatherInstitute_2F_Text_Grunt5Intro:
	.string "Don't tell me you're looking for that\n"
	.string "weather POKéMON, too?\p"
	.string "That's a no-no!\n"
	.string "We were here to get it first!$"

Route119_WeatherInstitute_2F_Text_Grunt5Defeat:
	.string "Oh, will you look at my POKéMON?$"

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle:
	.string "Humph, so what?\n"
	.string "What we want…\p"
	.string "What we really want isn't here…\n"
	.string "Ihihihihi…$"

Route119_WeatherInstitute_2F_Text_ShellyIntro:
	.string "Ahahahaha!\p"
	.string "You're going to meddle in TEAM AQUA's\n"
	.string "affairs?\p"
	.string "You're either absolutely fearless,\n"
	.string "simply ignorant, or both!\p"
	.string "You're so cute, you're disgusting!\n"
	.string "I'll put you down, kiddy!$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat:
	.string "Ahahahaha!\n"
	.string "You're disgustingly strong!$"

Route119_WeatherInstitute_2F_Text_ShellyPostBattle:
	.string "It's bad enough to have TEAM MAGMA\n"
	.string "blunder about, but now there's you!\p"
	.string "What makes you want to sniff around\n"
	.string "in our business, anyway?$"

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
	.string "We have a situation here!\p"
	.string "A TEAM MAGMA mob just passed\n"
	.string "the WEATHER INSTITUTE.\p"
	.string "They appear to be headed for\n"
	.string "MT. PYRE!$"

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
	.string "What?!\p"
	.string "We can't waste any more time here!\n"
	.string "We have to hurry to MT. PYRE, too!\p"
	.string "Ahahahaha!\n"
	.string "TEAM MAGMA, just you wait!$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
	.string "Thanks!\n"
	.string "Thanks to you, we're safe!\p"
	.string "It might be an odd way of thanking you,\n"
	.string "but take this POKéMON.$"

@ Unused
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon:
	.string "Hm? You don't seem to have any room\n"
	.string "for this POKéMON.$"

Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform:
	.string "{PLAYER} received CASTFORM!$"

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather:
	.string "That POKéMON changes shape according\n"
	.string "to the weather conditions.\p"
	.string "There're plenty of them in the\n"
	.string "INSTITUTE--go ahead and take it.$"

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
	.string "I've been researching rain for many\n"
	.string "years, but it's ridiculous to think that\l"
	.string "humans can freely change the weather.$"

Route119_WeatherInstitute_2F_Text_GroudonWeather:
	.string "I track weather patterns over\n"
	.string "the HOENN region.\p"
	.string "Presently, a drought has been recorded\n"
	.string "in {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_KyogreWeather:
	.string "I track weather patterns over\n"
	.string "the HOENN region.\p"
	.string "Presently, heavy rainfall has been\n"
	.string "recorded over {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
	.string "Abnormal weather conditions are\n"
	.string "no longer being reported.\p"
	.string "The occasional rainfall is a blessing,\n"
	.string "really.$"

Route119_WeatherInstitute_2F_EventScript_DeoxysSetup::
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	setflag FLAG_WEATHER_INSTITUTE_2F_SCIENTIST
	clearflag FLAG_WEATHER_INSTITUTE_2F_DEOXYSNPCS
	return


Route119_WeatherInstitute_2F_EventScript_PacingNPC::
	lockall
	msgbox Route119_WeatherInstitute_2F_EventScript_PacingNPC_Text_0
	waitmessage
	releaseall
	return


Route119_WeatherInstitute_2F_EventScript_TopNPC::
	lockall
	msgbox Route119_WeatherInstitute_2F_EventScript_TopNPC_Text_0
	waitmessage
	releaseall
	return


Route119_WeatherInstitute_2F_EventScript_ScientistNPC::
	lockall
	msgbox Route119_WeatherInstitute_2F_EventScript_ScientistNPC_Text_0
	waitmessage
	releaseall
	return


Route119_WeatherInstitute_2F_EventScript_BottomNPC::
	lockall
	faceplayer
	msgbox Route119_WeatherInstitute_2F_EventScript_BottomNPC_Text_0
	waitmessage
	releaseall
	return


Route119_WeatherInstitute_2F_EventScript_MiddleNPC::
	lockall
	msgbox Route119_WeatherInstitute_2F_EventScript_MiddleNPC_Text_0
	waitmessage
	releaseall
	return


Route119_WeatherInstitute_2F_EventScript_StevenNPC::
	lockall
	faceplayer
	specialvar VAR_RESULT, CheckRayquazaParty
	compare VAR_RESULT, TRUE
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_StevenNPC_2
	msgbox Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_10
	releaseall
Route119_WeatherInstitute_2F_EventScript_StevenNPC_1:
	releaseall
	return

Route119_WeatherInstitute_2F_EventScript_StevenNPC_2:
	faceplayer
	msgbox Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_0
	waitmessage
	msgbox Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_1
	applymovement 14, Route119_WeatherInstitute_2F_Movement_Steven
	delay 15
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_Player
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_2
	waitmessage
	msgbox Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_3
	waitmessage
	msgbox Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_4
	waitmessage
	msgbox Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_5
	waitmessage
	msgbox Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_6, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_StevenNPC_5
	msgbox Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_9
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	setvar VAR_SKY_PILLAR_STATE, 4
	setvar VAR_DEOXYS_STATE, 1
	call Route119_WeatherInstitute_1F_EventScript_Normal
	releaseall
	goto Route119_WeatherInstitute_2F_EventScript_StevenNPC_1

Route119_WeatherInstitute_2F_EventScript_StevenNPC_5:
	msgbox Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_7
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerExit
	delay 45
	applymovement 14, Route119_WeatherInstitute_2F_Movement_StevenExit
	waitmovement 0
	removeobject 14
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	setvar VAR_SKY_PILLAR_STATE, 4
	setvar VAR_DEOXYS_STATE, 1
	call Route119_WeatherInstitute_1F_EventScript_Normal
	msgbox Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_8, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route119_WeatherInstitute_2F_EventScript_StevenNPC_8
	goto Route119_WeatherInstitute_2F_EventScript_StevenNPC_1

Route119_WeatherInstitute_2F_EventScript_StevenNPC_8:
	warp MAP_SKY_PILLAR_5F, 3, 2
	releaseall
	goto Route119_WeatherInstitute_2F_EventScript_StevenNPC_1


Route119_WeatherInstitute_1F_EventScript_Normal::
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	clearflag FLAG_WEATHER_INSTITUTE_2F_SCIENTIST
	setflag FLAG_WEATHER_INSTITUTE_2F_DEOXYSNPCS
	setflag FLAG_WEATHER_INSTITUTE_2F_DEOXYSFINISH
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	return


Route119_WeatherInstitute_2F_Movement_Steven:
	walk_up
	walk_up
	face_right
	step_end

Route119_WeatherInstitute_2F_Movement_Player:
	walk_up
	walk_up
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerExit:
	walk_down
	walk_down
	walk_down
	step_end

Route119_WeatherInstitute_2F_Movement_StevenExit:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_PacingNPC_Text_0:
	.string "What could it be? It look's controlled\n"
	.string "but it can't be.$"

Route119_WeatherInstitute_2F_EventScript_TopNPC_Text_0:
	.string "It kind of look's like a meteor?$"

Route119_WeatherInstitute_2F_EventScript_ScientistNPC_Text_0:
	.string "It can't be a meteor, do you see it's\n"
	.string "trajectory?$"

Route119_WeatherInstitute_2F_EventScript_BottomNPC_Text_0:
	.string "Something weirds popped up on all alert\n"
	.string "systems, we are currently working on it\l"
	.string "but it's not looking to be fixed\l"
	.string "anytime soon.$"

Route119_WeatherInstitute_2F_EventScript_MiddleNPC_Text_0:
	.string "That make's no sense. What could\n"
	.string "produce that kind of data?$"

Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_0:
	.string "I see you have arrived! And with\n"
	.string "Rayquaza!$"

Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_1:
	.string "You should come see this$"

Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_2:
	.string "Look at this. At first glance it looks\n"
	.string "like a weird anomoly and that's why the\l"
	.string "scientists are freaking out.$"

Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_3:
	.string "But if you look at this data, it's pretty\n"
	.string "much the same.$"

Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_4:
	.string "This data is from the moment Rayquaza\n"
	.string "took off to fight Kyogre and Groudon.$"

Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_5:
	.string "I think the anomoly is a pokemon and\n"
	.string "that's why I need Rayquaza, it's one of\l"
	.string "the only pokemon able to enter the\l"
	.string "atmosphere.$"

Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_6:
	.string "What do you say? Think you can offer\n"
	.string "your help once more?$"

Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_7:
	.string "Brilliant! Meet me at the top of Sky\n"
	.string "Pillar where you caught Rayquaza$"

Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_8:
	.string "Do you wish to fast travel to Sky Pillar\n"
	.string "5F?$"

Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_9:
	.string "If you change your mind, meet me at Sky\n"
	.string "Pillar.$"

Route119_WeatherInstitute_2F_EventScript_StevenNPC_Text_10:
	.string "You are probably going to need\n"
	.string "Rayquaza for this, please talk to me\l"
	.string "when you have them.$"
