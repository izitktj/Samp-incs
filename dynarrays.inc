//original autor: https://forums.alliedmods.net/member.php?u=228599
//original link: https://forums.alliedmods.net/showthread.php?t=264650

#if defined _dynarrays_included
	#endinput
#endif
#define _dynarrays_included

#include <a_samp>

/*
Maximum of 4096 cells (16384 Bytes) of memory are allocatable by each dynamic array, by default (should be enough in most cases)
You could change this number by either defining it before including this file, or by typing:
		MAX_DYNMEMORY=8192
in compile options.
Also, DATA section will grow by this many cells, meaning whole plugin will grow by this much.

Keep in mind that you can't allocate more than 16384 bytes (4096 cells) of memory (*IN TOTAL*) by default.
If you want to allow more memory to be allocated, use "#pragma dynamic <AMOUNT IN CELLS>" (4096 by default, I believe)
These dynamic arrays can only be local, never global. Don't try to save their pointer.
*/
#if !defined MAX_DYNMEMORY
	#define MAX_DYNMEMORY	4096
#endif
new any: __DA@Memory[1][MAX_DYNMEMORY];

#if !defined NULL
	#define NULL			0
#endif

/*
Just trying to make the syntax prettier here, letting a user use something close to what C++ uses for allocating.

new mymemory = new[random_num(16, 64)];
_$mymemory[14] = 5;

//

new mystring = new[256];
copy(_$mystring[0], 255, "Hello World!");
server_print("mystring[]: %s", _$mystring[0]);
*/
#define new[%0]		__DA@Allocate(%0)
//#define delete[%0]	__DA@Free(%0)	// Not needed anymore!
#define ref<%0>		__DA@Reference(%0)

#define _$%0[		(__DA@Pointer(%0), __DA@Memory[0][0])[

stock any: __DA@Allocate(size)
{
	if(size > MAX_DYNMEMORY)
	{
		print("Run-time error: Tried to dynamically allocate more than %d cells of memory.", MAX_DYNMEMORY);
		return 1;
	}

	new ptr;

	#emit LOAD.S.pri size 			// Load "size" value into PRI
	#emit SMUL.C 4 					// Multiply it by 4 to get number of bytes
	#emit MOVE.alt 					// Move the value to alt
	#emit LCTRL 2					// Load HEA into PRI
	#emit STOR.S.pri ptr 			// Load HEA into "ptr"
	#emit ADD 						// Add HEA(pri) and size(alt) together
	#emit SCTRL 2 					// Allocate memory by moving the heap pointer

	return ptr;
}

stock __DA@Pointer(any: ptr) 
{
	// This is where the magic happens
	#emit CONST.alt __DA@Memory 	// Get "__DA@Memory"'s header address
	#emit LOAD.S.pri ptr			// Load "ptr" value into PRI
	#emit SUB						// PRI -= ALT / get the distance between the two
	#emit STOR.I 					// Store the distance in the header
}

/* Not needed anymore!
stock __DA@Free(&any: ptr)
{
	new hea;
	#emit LCTRL 2 					// Load HEA into PRI
	#emit STOR.S.pri hea			// Store HEA into "hea"
	if(ptr < hea)					// Only free memory if it's below the heap pointer
	{
		#emit LREF.S.pri ptr 		// Load "ptr" value into PRI
		#emit SCTRL 2 				// Put HEA to where it belongs
	}

	ptr = NULL;
}
*/

stock any: __DA@Reference(...)
{
	#emit LOAD.S.pri 12				// Load first param's address
	#emit RETN
}

public __DA@WTFIsThisFunctionDoingHere()
{
	__DA@Memory[0][0] = 0;
}