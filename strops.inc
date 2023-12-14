/* StrOps
 *
 * (c) Copyright 2023, unnietktj
 * This file is provided as is (no warranties).
 */

#if defined StrOps
  #endinput
#endif
#define StrOps

#include <a_samp>

forward ConvertStrToInt(str[]);

forward StringSize(str[]);

forward bool:IsStrEqual(str[], str2[]);

/*
Convert a string to a Integer number
WARNING: If there are some letters in the string, maybe can occur some bugs

Usage:
ConvertStrToInt(MyString[0]) *Will return a integer number*

Example:
new StrEx[3];
StrEx[0] = '3';
StrEx[1] = '4';
StrEx[2] = 0; //String end

if(ConvertStrToInt(StrEx[0]) == 34) 
{
	//this block will be executed
}
*/

public ConvertStrToInt(str[]) {
    new answer = 0, factor = 1;
    for (new i = StringSize(str)-1; i >= 0; i--) {
        answer += (str[i] - '0') * factor;
        factor = factor * 10;
    }
    return answer;
}

/*
Get the string size

Usage:
StringSize(MyString[0]) *Will return the amount of characters*

Example:
 !PSEUDO CODE ! StrEx = "Hello";

if(StringSize(StrEx[0]) == 5) 
{
	//this block will be executed
}
*/

public StringSize(str[]) {
	new length = 0;
	new AChar = -1;
	while(AChar != 0) {
		length++;
		AChar = str[length];
	}
	return length;
}

/*
Compare 2 Strings.

Usage:
IsStrEqual(MyString[0], MySecondString[0]) *If this 2 strings are the exatly the same, will return true*

Example:
 !PSEUDO CODE ! StrEx1 = "Hello";
 !PSEUDO CODE ! StrEx2 = "Hello";

if(IsStrEqual(StrEx1[0], StrEx1[0])) 
{
	//this block will be executed
}
*/

public bool:IsStrEqual(str[], str2[]) {
	new str1size = StringSize(str[]), str2size = StringSize(str2[]);

	if(str1size != str2size) return false;

	for(new i = 0; i < str1size; i++) {
		if(str[i] != str2[i]) return false;
	}

	return true;
}