//
//  Command.h
//  GameEngine
//
//  Created by Thomas Furst on 11/07/16.
//  Copyright © 2016 Thomas Furst. All rights reserved.
//

#ifndef Command_h
#define Command_h


namespace Console
{
	
	class Command
	{
	public:
		virtual int perform(int argv, const char ** argc) = 0;
		
	protected:
		const char * name;
	};

}

#endif /* Command_h */
