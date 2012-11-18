/*
 * =====================================================================================
 *
 *       Filename: WordFilterTest.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/17/2012 12:03:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  witwolf (ALL), wo dot bian dot shi dot mo0 at gmail dot com
 *        Company:  ...
 *
 * =====================================================================================
 */

#include "WordFilter.h"
#include <iostream>
using namespace std;
int main()
{
    char* _words[] = 
	{
	    "fuck you"
	    ,"aad"
	    ,"ac"
	    ,"ababd"
	    ,"abc"
	    ,"you"
	};
    string src = "aac fuck You ababc haha aaababd" ;
    vector<string> words;
    for(int i = 0 ; i < sizeof(_words)/sizeof(char*) ;i++)
	{
	    words.push_back(_words[i]);
	}
   
    WordFilter wordFilter;
    wordFilter.initFilterWithWords(words);

    string ret = wordFilter.applyFilter(src);

    cout << "before filter : " << src << endl ;
    cout << "after filter : " << ret << endl ;
}
