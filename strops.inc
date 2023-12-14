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

public ConvertStrToInt(str[]) {
    new answer = 0, factor = 1;
    for (new i = StringSize(str)-1; i >= 0; i--) {
        answer += (str[i] - '0') * factor;
        factor = factor * 10;
    }
    return answer;
}

public StringSize(str[]) {
	new length = 0;
	new AChar = -1;
	while(AChar != 0) {
		length++;
		AChar = str[length];
	}
	return length;
}
