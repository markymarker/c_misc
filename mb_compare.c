// Mark Fletcher
// 2021-05-20
// vim: noet ts=4 sts=0 sw=0

#include <stdlib.h>

int main(void){}


/*
 * Compare two values that span an arbitrary number of bytes.
 * Big-endian version (0A0B0C => 0A, 0B, 0C)
 *
 * See mb_compare for parameters and return values.
 */
int mb_compare_be(char * a, char * b, size_t s){
	if(s == 1)
		return *a == *b ? 0 : (*a < *b ? -1 : 1);
	for(size_t j = 0; j < s; ++j){
		if(a[j] == b[j]) continue;
		return a[j] < b[j] ? -1 : 1;
	}
	return 0;
}


/*
 * Compare two values that span an arbitrary number of bytes.
 * Little-endian version (0A0B0C => 0C, 0B, 0A)
 *
 * See mb_compare for parameters and return values.
 */
int mb_compare_le(char * a, char * b, size_t s){
	if(s == 1)
		return *a == *b ? 0 : (*a < *b ? -1 : 1);
	for(size_t j = s - 1; j >= 0; --j){
		if(a[j] == b[j]) continue;
		return a[j] < b[j] ? -1 : 1;
	}
	return 0;
}


/*
 * Test endianness.
 * Will return 1 if detected to be big endian, 0 if little endian.
 */
int is_big_endian(){
	long test = 0x1;
	return ((char *)&test)[0] != 1;
}


/*
 * Check endianness and perform the appropriate comparison.
 * Will cache the result of the check and use in all subsequent calls. If it is
 * desired that the endianness should be checked every time, then the caller
 * should use the is_big_endian function to determine which specific method to
 * call themself.
 *
 * Parameters:
 *   a : Pointer to first (lowest) byte of first value
 *   b : Pointer to first (lowest) byte of second value
 *   s : Size of data type to compare, used for both a and b
 * Return values:
 *   -1 : a < b
 *    0 : a = b
 *    1 : a > b
 */
int mb_compare(char * a, char * b, size_t s){
	static int big_endian = -1;
	if(big_endian < 0) big_endian = is_big_endian();
	return (big_endian
		? mb_compare_be(a, b, s)
		: mb_compare_le(a, b, s)
	);
}

