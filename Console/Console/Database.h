//
//  Database.h
//  GameEngine
//
//  Created by Thomas Furst on 11/07/16.
//  Copyright © 2016 Thomas Furst. All rights reserved.
//

#ifndef Database_h
#define Database_h

#include "CommandList.h"

namespace Console
{

	class Database
	{
	public:
		virtual int addCommand(const Command *) = 0;
		virtual int removeCommand(const Command *) = 0;
		
		virtual CommandList * findCommand(const char *, bool fullMatch) const = 0;
		virtual CommandList * getAllCommands() const = 0;
	};
	
}

#endif /* Database_h */
