/*
 * =====================================================================================
 *
 *       Filename:  WordFilter.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/17/2012 12:03:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  witwolf (ALL), wo dot bian dot shi dot mo0 at gmail dot com
 *        Company:  ...
 *
 * =====================================================================================
 */

#include "WordFilter.h"
using namespace std;

void WordFilter::initFilterWithWords(const vector<string> & words)
{
    m_fsm.init(words);
}

string WordFilter::applyFilter(const string &src)
{
    string ret = src;
    for(int i=0;i<ret.length();)
	{
	    m_fsm.nextState(ret[i]);
	    if(m_fsm.isEnd())
		{
		    int len = m_fsm.getMatch().length();
		    ret.replace(i-len+1,len,len,'*');
		}
	    i++;
	}
    return ret;
}
