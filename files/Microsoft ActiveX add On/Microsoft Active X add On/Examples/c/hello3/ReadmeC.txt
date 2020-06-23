How to Install a C++ Sample for Microsoft Agent
-----------------------------------------------


*** Perform the following steps once for all samples ***

1. Install the Microsoft Agent core control. To run samples which produce
speech output, install the TruVoice text-to-speech engine.  To run samples
which take speech input, install the Microsoft Command and Control speech
engine.

2. Copy to your hard disk the character animation files for the three standard
characters: Genie.acs, Merlin.acs and Robby.acs.  Create a directory
/Program Files/Microsoft Agent/Characters/ and put the three character
files in it.  (You may select a different location for these files, but
then you will need to replace the path string within each sample to
refer to the new location.)


*** Perform the following steps once for all C++ samples ***

1. Copy the required include files.  Create a local directory for
these files.  (For instance, /Program Files/Micrsoft Agent/Include/)
Copy the files from the CD to the local directory you created.

2. Start up Microsoft Visual C++.  From the Tools menu, select Options,
then click on the Directories tab.  Type the complete path to the local
directory you created in step 2 into the list of include directories.
Click OK.


*** Perform the following steps for each C++ sample ***

1. Copy the sample.  Create a local directory for the sample.  (For instance,
/Program Files/DevStudio/MyProjects/AgentSample/)  Copy the samples files
into the directory you created.

2. Start up Microsoft Visual C++.  From the File menu, select Open Workspace.
Navigate to the folder you created in step 1.  Select the workspace file (it
has a .dsw file extension) for this sample.  Click Open.

3. From the Build menu, select Execute.  When prompted to build the exe file,
click Yes.