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
// This sample demonstrates the use of Microsoft Agent from a Java Applet
// and the use of a notification sink to receive callbacks from the Agent
// server.
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

// The Hello2J class (Single threaded)

public class Hello2J extends Applet
{
	// Private members necessary for Agent instantiation

	private IAgent			m_Agent = null;
	private IAgentCharacter	m_Merlin[] = {null};
	private int				m_MerlinID[] = {-1};
	private int				m_RequestID[] = {0};
	private final String	m_CharacterPath = "\\program files\\microsoft agent\\characters\\merlin.acs";

	// Declare an Agent Notify Sink so that we can get
	// notification callbacks from the Agent server.

	private Notify			m_Sink = null;
	private int				m_SinkID[] = {-1};

	private final int		FALSE = 0;
	private final int		TRUE = 1;


	public Hello2J()
	{
		// Constructor left intentionally blank
	}

	public String getAppletInfo()
	{
		return "Name: Hello2J\r\n" +
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

		// Create and register a notify sink

		m_Sink = new Notify();

		m_Agent.Register(m_Sink, m_SinkID);

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

			// Give our notify sink access to the character

			m_Sink.SetCharacter(m_Merlin[0]);

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
		// Unload the character

		if (m_MerlinID[0] > 0)
		{
			m_Merlin[0] = null;
			m_Agent.Unload(m_MerlinID[0]);
			m_MerlinID[0] = -1;
		}

		// Unregister the notify sink, we're done with the
		// Agent server.

		if (m_SinkID[0] > 0)
		{
			m_Agent.Unregister(m_SinkID[0]);
			m_SinkID[0] = -1;
		}

		m_Sink = null;
		m_Agent = null;
	}
}
