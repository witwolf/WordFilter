/*
 * =====================================================================================
 *
 *       Filename:  FSM.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/17/2012 12:03:00 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  witwolf (ALL), wo dot bian dot shi dot mo0 at gmail dot com
 *        Company:  ...
 *
 * =====================================================================================
 */
#ifndef _FSM_H_
#define _FSM_H_

#include <map>
#include <vector>
#include <string>
using namespace std;
class State;
class FSM
{
 public:
    FSM();
    ~FSM();
    void init(const vector<string>& words);
    State* nextState(State *curState,char input);
    State * begin();
    bool isEnd(State * curState);
    const string & getMatch(State *curState);
    
 private:
    State * insertState(State * state,char input);
    void initFailure(State * state);

 private:
    State * m_start;
};

class State
{
 public:
    State(State * prev,char input);
    ~State();
    friend class FSM;
 private:
    char m_input ;
    State *m_prev ;
    map<char,State*> m_nexts ;
    State * m_failureState ;
    bool m_isEnd;
    string m_match;
};

#endif

