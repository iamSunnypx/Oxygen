
Set VOICE = createobject("sapi.spvoice")

set VOICE.Voice = VOICE.GetVoices.Item(4)
VOICE.Speak Wscript.Arguments(0),2
VOICE.WaitUntilDone(1000)