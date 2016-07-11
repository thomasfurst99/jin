//
//  Console.h
//  GameEngine
//
//  Created by Thomas Furst on 11/07/16.
//  Copyright © 2016 Thomas Furst. All rights reserved.
//

#ifndef Console_h
#define Console_h

#include "Database.h"
#include "Command.h"
#include "CommandList.h"
#include "History.h"

namespace Console
{
	
	class Console
	{
	public:
		virtual void processInput(const char *) = 0;
		virtual void write(const char *) = 0;
		
		virtual int registerCommand(const Command * command) = 0;
		virtual int unregisterCommand(const Command * command) = 0;
		
		virtual int runCommand(const char *, bool write) = 0;
		
		virtual CommandList * getHind(const char *) = 0;
		virtual CommandList * getAllCommands() = 0;
		
	protected:
		History * history;
		Database * database;
	};
	
}

#endif /* Console_h */
