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
// This sample demonstrates loading and showing 2 Microsoft Agent characters
// and synchronizing their actions.  It also demonstrates the use of the 
// RequestComplete notification and an Agent notify sink.
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

// The Hello3J class (Single threaded)

public class Hello3J extends Applet
{
	// Private members necessary for Agent instantiation.  Change the
	// location of the characters to where they are stored on your system.

	private IAgent			m_Agent = null;
	private int				m_WaitID[] = {-1};
	private int				m_RequestID[] = {0};
	private IAgentCharacter	m_Merlin[] = {null};
	private int				m_MerlinID[] = {-1};
	private IAgentCharacter	m_Genie[] = {null};
	private int				m_GenieID[] = {-1};
	private final String	m_MerlinPath = "\\program files\\microsoft agent\\characters\\merlin.acs";
	private final String	m_GeniePath = "\\program files\\microsoft agent\\characters\\genie.acs";

	// Declare an Agent Notify Sink so that we can get
	// notification callbacks from the Agent server.

	private Notify			m_Sink = null;
	private int				m_SinkID[] = {-1};

	private final int		FALSE = 0;
	private final int		TRUE = 1;


	public Hello3J()
	{
		// Constructor left intentionally blank
	}

	public String getAppletInfo()
	{
		return "Name: Hello3J\r\n" +
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

		m_Sink = new Notify(this);

		m_Agent.Register(m_Sink, m_SinkID);

		try
		{
			// The filespec parameter of the Load method is a 
			// COM variant to accept alternate Agent data providers.
			// We want a standard provider so we can just specify
			// the filespec for our character.

			Variant characterPath = new Variant();
			characterPath.putString(m_MerlinPath);

			// Load the characters

			m_Agent.Load(characterPath,
						 m_MerlinID,
						 m_RequestID);

			characterPath.putString(m_GeniePath);

			m_Agent.Load(characterPath,
						 m_GenieID,
						 m_RequestID);
			
		}
		catch(com.ms.com.ComException e)
		{
			// Hmmm.  We couldn't load a character so what else
			// can we do?

			stop();
			return;
		}

		try {

			// Get the IAgentCharacter interface for the loaded
			// characters by passing IDs to the Agent server.

			m_Agent.GetCharacter(m_MerlinID[0],
								 m_Merlin);

			m_Agent.GetCharacter(m_GenieID[0],
								 m_Genie);

			// Position the characters

			m_Genie[0].MoveTo((short)0, (short)100, 0, m_RequestID);
			m_Merlin[0].MoveTo((short)200, (short)100, 0, m_RequestID);

			// Show them

			m_Genie[0].Show(FALSE, m_RequestID);
			m_Merlin[0].Show(FALSE, m_RequestID);

			// Have Genie gesture towards Merlin

			m_Genie[0].GestureAt((short)150, (short)100, m_RequestID);

			// And have Genie say hello to Merlin

			m_Genie[0].Speak("Hi there Merlin.", null, m_WaitID);

			// Make Merlin wait for Genie to finish speaking

			m_Merlin[0].Wait(m_WaitID[0], m_RequestID);

			// Have Merlin gesture towards Genie

			m_Merlin[0].GestureAt((short)0, (short)100, m_RequestID);

			// And then speak back to Genie.  Use a request id owned by the
			// sink object.  When we get a request complete notification, the
			// sink will call back into the applet.

			m_Merlin[0].Speak("Hi Genie.  See you later", null, m_Sink.m_DoneID);

		}
		catch(com.ms.com.ComException e)
		{
			stop();
		}
	}
	
	public void stop()
	{
		// Unload the characters

		if (m_MerlinID[0] > 0)
		{
			m_Merlin[0] = null;
			m_Agent.Unload(m_MerlinID[0]);
			m_MerlinID[0] = -1;
		}

		if (m_GenieID[0] > 0)
		{
			m_Genie[0] = null;
			m_Agent.Unload(m_GenieID[0]);
			m_GenieID[0] = -1;
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

	public void HideCharacters()
	{
		// This method is called by the notification sink when the
		// last Agent request has completed.  We'll just hide the
		// characters.

		m_Merlin[0].Hide(FALSE, m_RequestID);
		m_Genie[0].Hide(FALSE, m_RequestID);
	}
}
