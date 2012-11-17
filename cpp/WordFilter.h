/*
 * =====================================================================================
 *
 *       Filename:  WordFilter.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/17/2012 12:03:24 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  witwolf (ALL), wo dot bian dot shi dot mo0 at gmail dot com
 *        Company:  ...
 *
 * =====================================================================================
 */

#ifndef __WORDFILTERH__
#define __WORDFILTERH__
#include <vector>
#include <string>
#include "FSM.h"
using namespace std;

class WordFilter
{
 public:
    void initFilterWithWords(const vector<string> & words);
    string applyFilter(const string &src);
 private:
    FSM m_fsm;
};





#endif

