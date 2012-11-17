/*
 * =====================================================================================
 *
 *       Filename:  FSM.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/17/2012 12:03:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  witwolf (ALL), wo dot bian dot shi dot mo0 at gmail dot com
 *        Company:  ...
 *
 * =====================================================================================
 */

#include "FSM.h"
#include <queue>
using namespace std;
FSM::FSM()
{
    m_start = new State(NULL,0);
    m_curState = m_start;
}
FSM::~FSM()
{
    delete m_start;
}
void FSM::init(const vector<string> &words)
{
    State * state;
    vector<string>::const_iterator iter = words.begin();
    for(; iter!=words.end(); iter++)
	{
	    state = m_start;
	    for(int i=0;i<iter->length();i++)
		{
		    state = insertState(state,(*iter)[i]);
		}
	    state->m_isEnd = true;
	    state->m_match = *iter;
	}
    
    queue<State *> states;
    states.push(m_start);
    while(!states.empty())
	{
	    state = states.front();
	    states.pop();
	    initFailure(state);
	    for(map<char,State*>::iterator iter = state->m_nexts.begin();
		iter != state->m_nexts.end();
		iter++)
		{
		    states.push(iter->second);
		}
	}
	    
}
void FSM::nextState(char input)
{
    if(m_curState->m_nexts.count(input))
	{
	    m_curState =  m_curState->m_nexts.find(input)->second;
	    return ;
	}
    else if(m_curState == m_start)
	{
	    return;
	}
    else
	{
	    m_curState = m_curState->m_failureState;
	    nextState(input);
	}
}

bool FSM::isEnd()
{
    return m_curState->m_isEnd;
}

const string & FSM::getMatch()
{
    return m_curState->m_match;
}

State * FSM::insertState(State *state,char input)
{
    State *next = NULL ;
    if(state->m_nexts.count(input))
	next = state->m_nexts.find(input)->second;
    else
	{
	    next = new State(state,input);
	    state->m_nexts[input] = next;
	}
    return next ;
}
    
void FSM::initFailure(State * state)
{
    if( !state->m_prev || state->m_prev == m_start )
	{
	    state->m_failureState = m_start ;
	    return;
	}
    else if( state->m_prev->m_failureState->m_nexts.count(state->m_input))
	{
	    state->m_failureState = state->m_prev->m_failureState->m_nexts.find(state->m_input)->second;
	    return;
	}
       else
	   state->m_failureState = m_start;
}

/**************
 *****State****
 **************/

State::State(State* prev,char input)
    :m_prev(prev)
    ,m_input(input)
    ,m_failureState(NULL)
    ,m_isEnd(false)
{}

State::~State()
{
    map<char,State*>::iterator iter = m_nexts.begin();
    for(;iter != m_nexts.end(); iter++)
	{
	    delete iter->second;
	}
}

	    



