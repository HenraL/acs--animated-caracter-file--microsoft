StrText = InputBox("What should I say?", "I can talk!")

On Error Resume Next
StrAgentName2 = "NAME"
StrAgentPath2 = "C:\Windows\Msagent\Chars\" & strAgentName2 & ".Acs"
Set objAgent2 = CreateObject("Agent.Control.2")
ObjAgent2.Connected = TRUE
ObjAgent2.Characters.Load strAgentName2, strAgentPath2
Set objPeter = objAgent2.Characters.Character(strAgentName2)
ObjPeter.MoveTo 700,300
ObjPeter.Show
ObjPeter.Play "GetAttention"
ObjPeter.Play "GetAttentionReturn"
ObjPeter.Speak StrText
Wscript.Sleep 1000
Set objAction= objPeter.Hide
Do While objPeter.Visible = True
Wscript.Sleep 250
Loop