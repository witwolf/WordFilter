/*
 * =====================================================================================
 *
 *       Filename:  Utils.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/18/2012 01:43:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  witwolf (ALL), wo dot bian dot shi dot mo0 at gmail dot com
 *        Company:  ...
 *
 * =====================================================================================
 */

#include "Utils.h"
char toLowercase(char input)
{
    if(input > 65 && input < 90)
	return input+32 ;
    return input;
}
