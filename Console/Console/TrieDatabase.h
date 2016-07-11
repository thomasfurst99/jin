//
//  TrieDatabase.h
//  GameEngine
//
//  Created by Thomas Furst on 11/07/16.
//  Copyright © 2016 Thomas Furst. All rights reserved.
//

#ifndef TrieDatabase_hpp
#define TrieDatabase_hpp

#include <vector>

#include "Database.h"
#include "CommandList.h"
#include "Command.h"

namespace Console { namespace Default
{
	
	class TrieDatabase : Database
	{
	public:
		struct TrieDatabaseNode
		{
			TrieDatabaseNode(char);
			
			int addChild(char);
			int addChild(TrieDatabaseNode *);
			
			int removeChild(char);
			int removeChild(TrieDatabaseNode *);
						
			TrieDatabaseNode * getChild(char) const;
			
			int assignCommand(Command *);
			int unassignCommand(Command *);
			
			char c;
			CommandList * commands;
			
			TrieDatabaseNode * parent;
			std::vector<TrieDatabaseNode *> children;
		};
		
		TrieDatabase();
		~TrieDatabase();
		
		CommandList * getCommandsFrom(const char *);
		CommandList * getCommandsFrom(TrieDatabaseNode *);
		
		/* Database virtual methods */
		int addCommand(const Command *);
		int removeCommand(const Command *);
		
		CommandList * findCommand(const char *, bool fullMatch) const;
		CommandList * getAllCommands() const;
		
	private:
		void DFS(TrieDatabaseNode *, CommandList *);
		
		TrieDatabaseNode * root;
		
		static const char separator;
	};
	
	const char TrieDatabase::separator = '.';
	
} }

#endif /* TrieDatabase_h */
