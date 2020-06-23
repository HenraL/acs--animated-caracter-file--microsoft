//==========================================================================
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
//  PURPOSE.
//
//  Copyright (C) 1997 Microsoft Corporation.  All Rights Reserved.
//
//==========================================================================

// Standard java imports

import java.applet.*;
import java.awt.*;

// COM and Microsoft Agent imports

import com.ms.com.Variant;
import agentsvr.IAgentNotifySink;
import agentsvr.IAgentCharacter;

// This class is an implementation of an IAgentNotifySink.
// All methods are stubs except Click.

public class Notify implements IAgentNotifySink
{
	public  int				m_DoneID[] = {-1};
	private Hello3J			m_Applet;

	public Notify(Hello3J applet)
	{
		m_Applet = applet;
	}

	public void Click(int characterID, short keys, int x, int y)
	{
	}

	public void DblClick(int characterID, short keys, int x, int y)
	{
	}

	public void Restart()
	{
	}

	public void BookMark(int bookmarkID)
	{
	}

	public void Shutdown()
	{
	}

	public void DragStart(int characterID, short keys, int x, int y)
	{
	}

	public void DragComplete(int characterID, short keys, int x, int y)
	{
	}

	public void ActivateInputState(int characterID, int activated)
	{
	}

	public void Command(int commandID, com.ms.com.IUnknown userInput)
	{
	}

	public void RequestStart(int requestID)
	{
	}

	public void RequestComplete(int requestID, int status)
	{
		if (requestID == m_DoneID[0])
		{
			m_Applet.HideCharacters();
		}
	}

	public void VisibleState(int characterID, int visible, int cause)
	{
	}

	public void Idle(int characterID, int start)
	{
	}

	public void Move(int characterID, int x, int y, int cause)
	{
	}

	public void Size(int characterID, int width, int height)
	{
	}

	public void BalloonVisibleState(int characterID, int visible)
	{
	}
}
