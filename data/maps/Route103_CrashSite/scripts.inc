Route103_CrashSite_MapScripts::
	return


Route103_CrashSite_EventScript_Steven::
	lockall
	faceplayer
	msgbox Route103_CrashSite_EventScript_Steven_Text_0
	waitmessage
	msgbox Route103_CrashSite_EventScript_Steven_Text_1
	waitmessage
	msgbox Route103_CrashSite_EventScript_Steven_Text_2
	waitmessage
	msgbox Route103_CrashSite_EventScript_Steven_Text_3
	waitmessage
	applymovement 1, Common_Movement_QuestionMark
	waitmovement 0
	msgbox Route103_CrashSite_EventScript_Steven_Text_4
	applymovement 1, Route103_CrashSite_Movement_StevenPhoneCall
	waitmovement 0
	msgbox Route103_CrashSite_EventScript_Steven_Text_5
	waitmessage
	msgbox Route103_CrashSite_EventScript_Steven_Text_6
	waitmessage
	msgbox Route103_CrashSite_EventScript_Steven_Text_7
	waitmessage
	msgbox Route103_CrashSite_EventScript_Steven_Text_6
	waitmessage
	msgbox Route103_CrashSite_EventScript_Steven_Text_8
	waitmessage
	faceplayer
	msgbox Route103_CrashSite_EventScript_Steven_Text_9
	waitmessage
	msgbox Route103_CrashSite_EventScript_Steven_Text_10
	waitmessage
	msgbox Route103_CrashSite_EventScript_Steven_Text_11
	waitmessage
	releaseall
	return


Route103_CrashSite_EventScript_Meteor::
	lockall
	msgbox Route103_CrashSite_EventScript_Meteor_Text_0
	waitmessage
	releaseall
	return


Route103_CrashSite_Movement_StevenPhoneCall:
	face_away_player
	step_end

Route103_CrashSite_EventScript_Steven_Text_0:
	.string "I see you've arrived {PLAYER}.$"

Route103_CrashSite_EventScript_Steven_Text_1:
	.string "I got here just a moment ago, this\n"
	.string "meteor is very fascinating.$"

Route103_CrashSite_EventScript_Steven_Text_2:
	.string "Even though it had a rough entry\n"
	.string "through the atmosphere, it's still in\l"
	.string "one piece and look around, this barely\l"
	.string "constitutes a crash site.$"

Route103_CrashSite_EventScript_Steven_Text_3:
	.string "It's easy to say that this is an unusual\n"
	.string "meteor.$"

Route103_CrashSite_EventScript_Steven_Text_4:
	.string "Let me just take this.$"

Route103_CrashSite_EventScript_Steven_Text_5:
	.string "Hi dad, to what do I owe the pleasure?$"

Route103_CrashSite_EventScript_Steven_Text_6:
	.string "...$"

Route103_CrashSite_EventScript_Steven_Text_7:
	.string "Mt. Pyre you say?$"

Route103_CrashSite_EventScript_Steven_Text_8:
	.string "Okay, I'll send someone there.$"

Route103_CrashSite_EventScript_Steven_Text_9:
	.string "They've found the other meteor,\n"
	.string "according to the data, this one was\l"
	.string "incredibly fast but has left next to\l"
	.string "nothing for a crash site so it's harder\l"
	.string "to find.$"

Route103_CrashSite_EventScript_Steven_Text_10:
	.string "You should head upto Mt.Pyre, it's\n"
	.string "somewhere along the east side of it.$"

Route103_CrashSite_EventScript_Steven_Text_11:
	.string "My dad will meet you there, he couldn't\n"
	.string "hold himself back when stones were\l"
	.string "mentioned.$"

Route103_CrashSite_EventScript_Meteor_Text_0:
	.string "It's just a standard Meteor.$"
