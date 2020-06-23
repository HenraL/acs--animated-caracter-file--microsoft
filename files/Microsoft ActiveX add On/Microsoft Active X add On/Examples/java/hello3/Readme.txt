Hello World 3 (Java) Sample for Microsoft Agent
-----------------------------------------------

*** Required components ***

1. This sample requires the Microsoft Agent Core Components and the
TruVoice Text-To-Speech Engine.  These should be installed before
running this sample.

2. This sample reads character animations from the following
path: \Program Files\Microsoft Agent\Characters\.
The character animation files Merlin.acs and Genie.acs should be
copied to that location before running this sample.

3. This sample requires that the Agent Server COM class be imported
to Java.  To do this:  Start up Microsoft Visual J++.  Run the
Java Type Library Wizard from the Tools menu.  Scroll through the
list of items and find the entry for "Microsoft Agent Server 1.5".
Place a check mark in the box next to this entry, then click OK.


*** To run the sample ***

1. Start up Microsoft Visual J++.  From the File menu, select Open Workspace.
Navigate to the folder containing this Readme file.  Select the workspace file
(Hello3J.dsw) for this sample.  Click Open.

2. From the Build menu, select Execute.  When prompted that files need to be
built, click Yes.  When prompted for a Class File Name, enter the name of
the sample: "Hello3J", then click OK.  Note that the name is case sensitive.