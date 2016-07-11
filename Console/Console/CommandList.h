//
//  CommandList.h
//  GameEngine
//
//  Created by Thomas Furst on 11/07/16.
//  Copyright © 2016 Thomas Furst. All rights reserved.
//

#ifndef CommandList_h
#define CommandList_h

#include "Command.h"

namespace Console
{
	
	class CommandList
	{
	public:
		virtual int addCommand(Command *) = 0;
		virtual int removeCommand(Command *) = 0;
		
		virtual int size() = 0;
		virtual Command * operator[](std::size_t i) = 0;
	};
	
}

#endif /* CommandList_h */
