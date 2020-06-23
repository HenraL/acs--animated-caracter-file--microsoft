//==========================================================================
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
//  PURPOSE.
//
//  Copyright (C) 1997 Microsoft Corporation.  All Rights Reserved.
//
//--------------------------------------------------------------------------
//
// This sample demonstrates the simplest use of Microsoft Agent from a 
// Java Applet.
//
//==========================================================================

// Standard java imports

import java.applet.*;
import java.awt.*;

// COM and Microsoft Agent imports

import com.ms.com.Variant;
import agentsvr.AgentServer;
import agentsvr.IAgent;
import agentsvr.IAgentCharacter;

// The HelloAgentJava class (Single threaded)

public class HelloJ extends Applet
{
	// Private members necessary for Agent instantiation

	private IAgent			m_Agent = null;
	private IAgentCharacter	m_Merlin[] = {null};
	private int				m_MerlinID[] = {-1};
	private int				m_RequestID[] = {0};
	private final String	m_CharacterPath = "\\program files\\microsoft agent\\characters\\merlin.acs";

	private final int		FALSE = 0;
	private final int		TRUE = 1;


	public HelloJ()
	{
		// Constructor left intentionally blank
	}

	public String getAppletInfo()
	{
		return "Name: HelloJ\r\n" +
		       "Author: anonymous\r\n" +
		       "Created with Microsoft Visual J++ Version 1.1";
	}

	public void init()
	{
    	resize(0, 0);
	}

	public void destroy()
	{
	}

	public void paint(Graphics g)
	{
	}

	public void start()
	{
		// Start the Microsoft Agent Server

		m_Agent = (IAgent) new AgentServer();

		try
		{
			// The filespec parameter of the Load method is a 
			// COM variant to accept alternate Agent data providers.
			// We want a standard provider so we can just specify
			// the filespec for our character.

			Variant characterPath = new Variant();
			characterPath.putString(m_CharacterPath);

			// Load the character

			m_Agent.Load(characterPath,
						 m_MerlinID,
						 m_RequestID);
			
		}
		catch(com.ms.com.ComException e)
		{
			// Hmmm.  We couldn't load the character so what else
			// can we do?

			stop();
			return;
		}

		try {

			// Get the IAgentCharacter interface for the loaded
			// character by passing it's ID to the Agent server.

			m_Agent.GetCharacter(m_MerlinID[0],
								 m_Merlin);

			// Show the character

			m_Merlin[0].Show(FALSE, m_RequestID);

			// And speak hello

			m_Merlin[0].Speak("Hello World!", null, m_RequestID);

		}
		catch(com.ms.com.ComException e)
		{
			stop();
		}
	}
	
	public void stop()
	{
		if (m_MerlinID[0] > 0)
		{
			m_Merlin[0] = null;
			m_Agent.Unload(m_MerlinID[0]);
			m_MerlinID[0] = -1;
		}

		m_Agent = null;
	}
}
