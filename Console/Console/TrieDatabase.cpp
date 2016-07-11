//
//  TrieDatabase.cpp
//  GameEngine
//
//  Created by Thomas Furst on 11/07/16.
//  Copyright © 2016 Thomas Furst. All rights reserved.
//

#include "TrieDatabase.h"

#include <algorithm>
#include <cstring>

namespace Console { namespace Default
{
/* Trie database */
Console::Default::TrieDatabase::TrieDatabase() : root(new TrieDatabaseNode(separator)) {}

Console::Default::TrieDatabase::~TrieDatabase() {}

Console::CommandList * Console::Default::TrieDatabase::getCommandsFrom(const char * str)
{
	CommandList * list;
	TrieDatabaseNode * fresh = root;
	
	for (int i = 0; i < std::strlen(str); i++)
	{
		fresh = fresh->getChild(str[i]);
		if (fresh == nullptr) return list;
	}
	
	return getCommandsFrom(fresh);
}

Console::CommandList * Console::Default::TrieDatabase::getCommandsFrom(TrieDatabaseNode * from)
{
	CommandList * list;
	DFS(from, list);
	return list;
}

/* Database virtual methods */
int Console::Default::TrieDatabase::addCommand(const Command *)
{
	return 0;
}

int Console::Default::TrieDatabase::removeCommand(const Command *)
{
	return 0;
}

Console::CommandList * Console::Default::TrieDatabase::findCommand(const char *, bool fullMatch) const
{
	return nullptr;
}

Console::CommandList * Console::Default::TrieDatabase::getAllCommands() const
{
	return nullptr;
}

void Console::Default::TrieDatabase::DFS(TrieDatabaseNode * node, CommandList * list)
{
	for (int i = 0; i < node->commands->size(); i++)
	{
		list->addCommand((*node->commands)[i]);
	}
	for (int i = 0; i < node->children.size(); i++)
	{
		DFS(node->children[i], list);
	}
}

/* Trie database node */
	TrieDatabase::TrieDatabaseNode::TrieDatabaseNode(char c) : c(c) {}
	
int TrieDatabase::TrieDatabaseNode::addChild(char c)
{
	if (getChild(c) != nullptr) return 1;
	
	children.push_back(new TrieDatabaseNode(c));
	return 0;
}

int TrieDatabase::TrieDatabaseNode::addChild(TrieDatabaseNode * node)
{
	// Try to fing the node with the same char c
	for (std::vector<TrieDatabaseNode *>::iterator it = children.begin(); it != children.end(); ++it)
	{
		if ((*it)->c == node->c)
		{
			// Assign all commands to the existing node
			for (int i = 0; i < node->commands->size(); i++)
			{
				commands->addCommand((*node->commands)[i]);
			}
			return 1;
		}
	}
	children.push_back(node);
	
	return 0;
}
	
int TrieDatabase::TrieDatabaseNode::removeChild(char c)
{
	for (std::vector<TrieDatabaseNode *>::iterator it = children.begin(); it != children.end(); ++it)
	{
		// We found our node
		if ((*it)->c == c)
		{
			children.erase(it);
			return 0;
		}
	}
	
	return 1;
}

int TrieDatabase::TrieDatabaseNode::removeChild(TrieDatabaseNode * child)
{
	for (std::vector<TrieDatabaseNode *>::iterator it = children.begin(); it != children.end(); ++it)
	{
		if (*it == child)
		{
			children.erase(it);
			return 0;
		}
	}
	
	return 1;
}
	
TrieDatabase::TrieDatabaseNode * TrieDatabase::TrieDatabaseNode::getChild(char c) const
{
	for (std::vector<TrieDatabaseNode *>::iterator it = children.begin(); it != children.end(); ++it)
	{
		
	}
	
	return nullptr;
}
	
int TrieDatabase::TrieDatabaseNode::assignCommand(Command * command)
{
	return 0;
}

int TrieDatabase::TrieDatabaseNode::unassignCommand(Command * command)
{
	return 0;
}

}
}
