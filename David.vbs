Option Explicit
Dim David

'David's Voice
Set David = CreateObject("SAPI.spVoice")
Set David.Voice = David.GetVoices.Item(1)
David.Speak  "You can use only these commands currently "

David.Rate = 2
David.Volume = 100

