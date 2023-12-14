/* StrOps
 *
 * (c) Copyright 2023, izitktj
 * This file is provided as is (no warranties).
 */

#if defined StrOps
  #endinput
#endif
#define StrOps

#include <a_samp>

forward ConvertStrToInt(str[]);

forward StringSize(str[]);

forward bool:IsEqual(str[], str2[]);

forward StrClone(str[], str2[]);

/*
Convert a string to a Integer number.
WARNING: If there are some letters in the string, maybe can occur some bugs

Usage:
ConvertStrToInt(MyString[0]) *Will return a integer number*

Example:
new StrEx1[3];

StrClone(StrEx1[0], "34");

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
Get the string size.

Usage:
StringSize(MyString[0]) *Will return the amount of characters*

Example:
new StrEx1[7];

StrClone(StrEx1[0], "Hello");

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
IsEqual(MyString[0], MySecondString[0]) *If this 2 strings are the exatly the same, will return true*

Example:
new StrEx1[7];
new StrEx2[7];

StrClone(StrEx1[0], "Hello");
StrClone(StrEx2[0], "Hello");

if(IsEqual(StrEx1[0], StrEx1[0])) 
{
	//this block will be executed
}
*/

public bool:IsEqual(str[], str2[]) {
	new str1size = StringSize(str[0]), str2size = StringSize(str2[0]);

	if(str1size != str2size) return false;

	for(new i = 0; i < str1size; i++) {
		if(str[i] != str2[i]) return false;
	}



	return true;
}

/*
Copy a string to another.

Usage:
public StrClone(MyString[0], MySecondString[0]) *Copy the content of the "MySecondString[]" to "MyString[]"*
public StrClone(MyString[0], "My Text") *Copy the text "My Text" to "MyString[]"*

Example:
new StrEx1[7];

StrClone(StrEx1[0], "Hello");

print(StrEx1[0]); //will output "Hello"
*/

public StrClone(str[], str2[]) {
	new str2size = StringSize(str2[0]);

	for(new i = 0; i < str2size; i++) {
		str[i] = str2[i];
	}
	return 1;
}