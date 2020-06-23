___________________________________________________________________

                      Companion Disc Readme
                               for

                  Developing for Microsoft Agent


            Copyright (c) 1999 by Microsoft Corporation
                       All Rights Reserved
___________________________________________________________________

README CONTENTS
 - SYSTEM REQUIREMENTS
 - WHAT'S ON THIS CD?
 - HOW TO USE THE CD
 - SUPPORT INFORMATION
   - Microsoft Press support information
   - Microsoft Agent support 



System Requirements
=============================== 
Required:
* Windows 95, Windows 98, Windows NT® 4.00(x86), or Windows 2000 
* Internet Explorer version 3.02 or later 
* A Pentium 100 MHz PC (or faster) 
* At least 16 MB of RAM 
* At least 1 MB free disk space for the Microsoft Agent core components 
* An additional 2 - 4 MB free disk space for each character you install 
* An additional 32 KB free disk space for each language component (DLL) 

Recommended:
* An additional 1.6 MB free disk space if you plan to use the Lernout & Hauspie® TruVoice 
  Text-To-Speech engine for speech output 
* An additional 22 MB free disk space and a Pentium 120 MHz PC (or faster) if you plan to 
  use the Microsoft Speech Recognition Engine for speech input 
* A Windows-compatible sound card 
* A compatible set of speakers and microphone 


What's On This CD
=================================
* Microsoft Agent Core Components 
* Microsoft Agent Language Components 
* Microsoft Agent Character Files 
* Microsoft Agent Character Editor 
* Microsoft Office Palette
* Lernout & Hauspie® TruVoice Text-To-Speech Engine 
* Microsoft Speech Recognition Engine
* Microsoft Agent Linguistic Information Sound Editing Tool 
* Microsoft Speech Control Panel 
* Microsoft Agent Visual Basic®, Visual C++®, Java and HTML code samples

How to Use the CD
=================================
Microsoft Agent Core Components
 - To install the Agent core components, follow these steps:
      1. On the taskbar at the bottom of your screen, click the Start button, and then 
         click Run.
      2. Type D:\msagent.exe (or, if your CD-ROM drive uses a drive letter other 
          than "D" substitute with the correct drive letter).
      3. Click OK, and then follow the directions on the screen to install.

~~~~~~~~~~~~~
Microsoft Agent Language Components

Language components (DLLs) add dialogs, windows, tooltips, and balloon text in an additional 
language to the U.S. English core components.

 - To install the Agent language components, follow these steps:
      1. On the taskbar at the bottom of your screen, click the Start button, and then 
         click Run. 
      2. Type D:\intl\agtx****.exe (or, if your CD-ROM drive uses a drive letter other 
         than "D" substitute with the correct drive letter), where **** are replaced with 
         the number corresponding to the language you want to install.  You can install 
         more than one language component on the same system.

         Language                    Number 
         --------                    ------ 
         Arabic                      0401 
         French                      040C 
         German                      0407 
         Hebrew                      040D 
         Italian                     0410 
         Japanese                    0411 
         Korean                      0412 
         Simplified Chinese          0804 
         Spanish                     0C0A 
         Traditional Chinese         0404 

      3. Click OK, and then follow the directions on the screen to install. 

For additional languages, you can download from the Microsoft Agent Web site:
http://www.microsoft.com/workshop/imedia/agent/agentdl.asp#core.  The \Links folder also 
contains a link, othrlang.htm, to this page.

~~~~~~~~~~~~~
Microsoft Agent Character Files 
 - To install the Agent character files, follow these steps:
      1. On the taskbar at the bottom of your screen, click the Start button, and then 
         click Run. 
      2. Type D:\chars\*****.exe (or, if your CD-ROM drive uses a drive letter other 
         than "D" substitute with the correct drive letter), where ***** are replaced with 
         the name of the character (Genie, Merlin, Peedy or Robby) you want to install.  You 
         can install more than one character on the same system. 
      3. Click OK, and then follow the directions on the screen to install. 

~~~~~~~~~~~~~
Microsoft Agent Character Editor (.EXE file, 981 KB)

The Agent Character Editor lets you compose your own characters for use with Microsoft Agent. 

- To install the Agent Character Editor, follow these steps:
      1. On the taskbar at the bottom of your screen, click the Start button, and then 
         click Run.
      2. Type D:\sdk\ace.exe (or, if your CD-ROM drive uses a drive letter other 
          than "D" substitute with the correct drive letter).
      3. Click OK, and then follow the directions on the screen to install.    

~~~~~~~~~~~~~
Microsoft Office Palette (.BMP file, 13KB)

Use the Microsoft Office Palette (\sdk\assistpalet.bmp) when designing Microsoft Agent 
characters for use within Microsoft® Office 2000 to minimize any potential palette 
realization issues.  You should refer to the section <Designing Characters for 
Microsoft Office> in the book for instructions and details about how to create such 
characters.

~~~~~~~~~~~~~
Lernout & Hauspie® TruVoice Text-To-Speech Engine (.EXE file, 1 MB)

Text-to-speech engines provide speech output capabilities for Microsoft Agent and the Agent 
Character Editor. 

 - To install the TruVoice text-to-speech engine, follow these steps:
      1. On the taskbar at the bottom of your screen, click the Start button, and then 
         click Run.
      2. Type D:\speech\tv_enua.exe (or, if your CD-ROM drive uses a drive letter other 
          than "D" substitute with the correct drive letter).
      3. Click OK, and then follow the directions on the screen to install. 

At this time only U.S. English speech engines are available from Microsoft.  However, 
SAPI-compliant engines for other languages may be available from third parties.  The \Links 
folder contains a link, spchreq.htm, to Microsoft's Speech Engine Support Requirements page. 
The \Links folder also contains a link, speech.htm, to Microsoft's Speech research Web page.  

You should also visit the Microsoft Agent Web site.  Text-to-speech engines for other languages 
will be added as they become available.  The \Links folder contains a link, spcheng.htm, to 
this page.

~~~~~~~~~~~~~
Microsoft Speech Recognition Engine (.EXE file, 6MB)

Speech recognition engines provide speech input capabilities for Microsoft Agent. At this time 
Microsoft provides a single U.S. English speech recognition engine for use with Microsoft Agent. 
To use this engine you should have a Pentium 120-MHz PC (or faster).

 - To install the Microsoft Speech Recognition Engine, follow these steps:
      1. On the taskbar at the bottom of your screen, click the Start button, and then 
         click Run.
      2. Type D:\speech\actcnc.exe (or, if your CD-ROM drive uses a drive letter other 
          than "D" substitute with the correct drive letter).
      3. Click OK, and then follow the directions on the screen to install. 

At this time only U.S. English speech engines are available from Microsoft.  However, 
SAPI-compliant engines for other languages may be available from third parties.  The \Links 
folder contains a link, spchreq.htm, to Microsoft's Speech Engine Support Requirements page. 
The \Links folder also contains a link, speech.htm, to Microsoft's Speech research Web page.  

~~~~~~~~~~~~~
Microsoft Agent Linguistic Information Sound Editing Tool

The Linguistic Information Sound Editing Tool enables you to generate phoneme and word-break 
information for enhancing sound (WAV) files to support high-quality lip-syncing character 
animation. 

Microsoft Agent Linguistic Information Sound Editing Tool (.EXE file, 6.3 MB)
 - To install the Agent Linguistic Information Sound Editing Tool, follow these steps:
      1. On the taskbar at the bottom of your screen, click the Start button, and then 
         click Run.
      2. Type D:\sdk\liset.exe (or, if your CD-ROM drive uses a drive letter other 
          than "D" substitute with the correct drive letter).
      3. Click OK, and then follow the directions on the screen to install. 

~~~~~~~~~~~~~
Microsoft Speech Control Panel

The Speech Control Panel enables you to list the compatible speech recognition and text-to-speech 
engines installed on your system and to view and customize their settings for your use. When you 
install the file, it adds a speech icon to your Control Panel that you can open. Note that this 
application will only install on Windows 95, Windows 98, and Windows NT 4.0 systems. 

 - To install the TruVoice text-to-speech engine, follow these steps:
      1. On the taskbar at the bottom of your screen, click the Start button, and then 
         click Run.
      2. Type D:\speech\spchcpl.exe (or, if your CD-ROM drive uses a drive letter other 
          than "D" substitute with the correct drive letter).
      3. Click OK, and then follow the directions on the screen to install. 

~~~~~~~~~~~~~
Code Samples

Microsoft Agent Visual Basic®, Visual C++®, Java and HTML code samples are found in the 
\SDK\Samples folder.  The Include files for the C++ code samples can be found in the \SDK\Include 
folder on the companion CD.  These header files define the COM (Component Object Model) interfaces 
to the Agent Server. You'll also need these if you plan to call the Agent Server COM interfaces 
from a C++ program. 

Each sample includes a Readme.txt file in their respective folder with further instructions for 
building and running the sample. The instructions assume that you are using Microsoft Visual 
Basic®, Microsoft Visual C++®, or Microsoft Visual J++, as appropriate.

* Visual Basic Samples (\SDK\Samples\VB)
Instructions for installing and running the samples are included in their respective readme document. 
These instructions assume that you are using Microsoft Visual Basic® version 5.0 or higher. 
 - Character Animation Preview Tool Sample (\SDK\Samples\VB\Cap)
   Illustrates how to perform several operations with a character and provides a handy tool for 
   previewing a character's animation. 
   Requires: Agent Core Components, Characters(.ACS format), Text-To-Speech Engine.
   Level: Intermediate. 
 - Hello World Visual Basic Sample (\SDK\Samples\VB\Hello)
   Illustrates using Microsoft Agent with Visual Basic.
   Requires: Agent Core Components, Text-To-Speech Engine.
   Level: Basic.

* Visual C++ Samples (\SDK\Samples\C)
Instructions for installing and running the samples are included in their respective readme document. 
These instructions assume that you are using Microsoft Visual C++® version 5.0 or higher.
 - Character Animation Preview Tool Sample (\SDK\Samples\C\Cap)
   Illustrates how to perform several operations with a character and provides a handy tool for 
   previewing a character's animation. 
   Requires: Agent Core Components, Text-To-Speech Engine, Characters. 
   Level: Advanced. 
 - Hello World C++ Sample (\SDK\Samples\C\Hello)
   Illustrates using Microsoft Agent with C++. 
   Requires: Agent Core Components, Characters. 
   Level: Intermediate. 
 - Hello World 2 C++ Sample (\SDK\Samples\C\Hello2)
   Illustrates Hello World with AgentNotifySink. Demonstrates how to receive Agent events in C++. 
   Requires: Agent Core Components, Characters. 
   Level: Intermediate. 
 - Hello World 3 C++ Sample (\SDK\Samples\C\Hello3)
   Illustrates Hello World with AgentNotifySink and two characters. Demonstrates how to use Agent 
   events to coordinate multiple characters in C++. 
   Requires: Agent Core Components, Characters. 
   Level: Intermediate. 

* Java Samples (\SDK\Samples\Java)
Instructions for installing and running the samples are included in their respective readme document. 
These instructions assume that you are using Microsoft Visual J++®.
 - Character Animation Preview Tool Sample (\SDK\Samples\Java\CapJ)
   Illustrates how to perform several operations with a character and provides a handy tool for 
   previewing a character's animation. 
   Requires: Agent Core Components, Text-To-Speech Engine, Characters. 
   Level: Advanced. 
 - Hello World Java Sample (\SDK\Samples\Java\Hello)
   Illustrates using Microsoft Agent from a Java applet. 
   Requires: Agent Core Components, Text-To-Speech Engine, Characters. 
   Level: Basic. 
 - Hello World 2 Java Sample (\SDK\Samples\Java\Hello2)
   Illustrates Hello World with AgentNotifySink. Demonstrates how to receive Agent events in Java. 
   Requires: Agent Core Components, Text-To-Speech Engine, Characters. 
   Level: Intermediate. 
 - Hello World 3 Java Sample (\SDK\Samples\Java\Hello3)
   Illustrates Hello World with AgentNotifySink and two characters. Demonstrates how to use Agent 
   events to coordinate multiple characters in Java. 
   Requires: Agent Core Components, Text-To-Speech Engine, Characters. 
   Level: Intermediate. 

* Microsoft Foundation Classes (MFC) Samples (\SDK\Samples\C\CapMFC)
Instructions for installing and running the sample are included in its readme document. These 
instructions assume that you are using MFC.
 - Character Animation Preview Tool Sample (\SDK\Samples\C\CapMFC)
   Illustrates how to perform several operations with a character and provides a handy tool for 
   previewing a character's animation. 
   Requires: Agent Core Components, Text-To-Speech Engine, Characters. 
   Level: Intermediate. 

* HTML Samples (\SDK\Samples\Html)
These HTML pages demonstrate how to use Microsoft Agent from Visual Basic® Scripting Edition 
(VBScript) or JScript® on a Web page. You can browse a sample by double-clicking on it in the 
\SDK\Samples\Html folder. Each sample will attempt to install its required components if they are 
not already installed. These samples download their character animations from 
http://agent.microsoft.com/agent2/chars/, so you must be connected to the Internet. You need to be 
running Microsoft® Windows 95, Windows 98, Windows NT® 4.0(x86) or Windows 2000, and Internet 
Explorer 3.02 or later to download and run the samples. 
 - Hello World (VBScript) Sample (\SDK\Samples\Html\hello.htm)
   Illustrates using Microsoft Agent on a Web page in HTML and VBScript. 
   Requires: Agent Core Components, Text-To-Speech Engine. 
   Level: Basic. 
 - Hello World (JScript) Sample (\SDK\Samples\Html\jello.htm)
   Illustrates using Microsoft Agent on a Web page in HTML and JScript. 
   Requires: Agent Core Components, Text-To-Speech Engine. 
   Level: Basic. 
 - Goodbye World Sample (\SDK\Samples\Html\goodbye.htm)
   Demonstrates scripting a Microsoft Agent character to respond to voice commands on a Web page. 
   Requires: Agent Core Components, Text-To-Speech Engine, Speech Recognition Engine. 
   Level: Basic. 
 - Character Viewer Sample (\SDK\Samples\Html\charview.htm)
   Demonstrates enumerating the animations in a character file, detecting a specific version of Agent, 
   and using RequestStart and RequestComplete events. This sample can open a specified character file 
   (.acf format) and play any of the animations contained therein. 
   Requires: Agent Core Components, Internet Explorer 4.0. 
   Level: Intermediate. 
 - Peedy's Pizza Plaza Sample (\SDK\Samples\Html\PeedyPza.htm)
   A speech enabled Web page that demonstrates managing speech input in parallel with direct 
   manipulation. 
   Requires: Agent Core Components, Text-To-Speech Engine, Speech Recognition Engine. 
   Level: Advanced. 


SUPPORT INFORMATION
=================================

Microsoft Press Support Information
-----------------------------------
Every effort has been made to ensure the accuracy of the book
and the contents of this companion disc. Microsoft Press
provides corrections for books through the World Wide Web at

    http://mspress.microsoft.com/mspress/support/

If you have comments, questions, or ideas regarding the book or
this companion disc, please send them to Microsoft Press via 
e-mail to:

    MSPINPUT@MICROSOFT.COM

or via postal mail to:

    Microsoft Press
    Attn:  Developing for Microsoft Agent Editor
    One Microsoft Way
    Redmond, WA  98052-6399

Please note that product support is not offered through the
above addresses. 

Developing for Microsoft Agent Support
--------------------------------------

For additional or updated information about Microsoft Agent, visit
the Microsoft Agent Web site at
    http://www.microsoft.com/msagent

Customers can receive technical support for Microsoft Agent by calling 
1-800-936-5800 (this is the developer support phone line). If you are 
an MSDN member, you can use one of your MSDN support incidents for this 
support. If you are not an MSDN member, you can choose the 
"pay-per-incident" option. You can also submit questions electronically 
through the Support Web site at
    http://www.microsoft.com/isapi/gosupport.asp?target=/support/
Note that this is also pay-per-incident unless you already have a support 
contract with Microsoft. 

To report Microsoft Agent bugs, please use the bug form at
    http://www.microsoft.com/workshop/imedia/agent/agentbugform.asp

To contact the community of active Microsoft Agent developers, visit the 
public newgroup
    microsoft.public.msagent
Note that Microsoft does not actively monitor this peer-to-peer support
forum.


