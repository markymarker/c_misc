// Mark Fletcher
// 2021-05-19

int main(void){}

/*
 * Put three values in order, by making a linear pass and adjusting places on
 * the fly. Does not perform swapping, but rather figures out the order before
 * doing a final all-at-once assignment.
 *
 * (Technically, uses 3 temp variables.)
 *
 * Best case:
 *   2 comparisons
 *   6 assignments (3 + final)
 *
 * Worst case:
 *   3 comparisons
 *   9 assignments (6 + final)
 */
void triswap_mover(char * i1, char * i2, char * i3){
	char s1, s2, s3;

	s1 = *i1;

	if(*i2 < s1){
		s2 = s1;
		s1 = *i2;
	} else {
		s2 = *i2;
	}

	if(*i3 < s1){
		s3 = s2;
		s2 = s1;
		s1 = *i3;
	} else if(*i3 < s2) {
		s3 = s2;
		s2 = *i3;
	} else {
		s3 = *i3;
	}

	*i1 = s1;
	*i2 = s2;
	*i3 = s3;
}



/*
 * Put three values in order, performing the full gamut of checks before taking
 * any action. Does not perform swapping, but rather figures out the order,
 * then assigns all at once.
 *
 * (Technically, uses 3 temp variables.)
 *
 * Best case:
 *   2 comparisons
 *   6 assignments (3 + final)
 *
 * Worst case:
 *   3 comparisons
 *   6 assignments (3 + final)
 */
void triswap_checker(char * i1, char * i2, char * i3){
	char s1, s2, s3;

	// Entering: No information
	if(*i1 <= *i2){
		if(*i1 <= *i3){
			// i1 <= (i2, i3)
			s1 = *i1;

			if(*i2 <= *i3){
				// i1 <= i2 <= i3
				s2 = *i2;
				s3 = *i3;
			} else {
				// i1 <= i3 < i2
				s2 = *i3;
				s3 = *i2;
			}

		} else {
			// i3 < i1 <= i2
			s1 = *i3;
			s2 = *i1;
			s3 = *i2;
		}

	// Entering: i2 < i1
	} else if(*i2 <= *i3) {
		// i2 < (i1, i3)
		s1 = *i2;

		if(*i1 <= *i3){
			// i2 < i1 <= i3
			s2 = *i1;
			s3 = *i3;
		} else {
			// i2 < i3 < i1
			s2 = *i3;
			s3 = *i1;
		}

	// Entering: i2 < i1, i3 < i2
	} else {
		// i3 < i2 < i1
		s1 = *i3;
		s2 = *i2;
		s3 = *i1;
	}

	*i1 = s1;
	*i2 = s2;
	*i3 = s3;
}



/*
 * Put three values in order, minimizing the amount of assignments done. Uses a
 * temp variable to perform swapping.
 *
 * (Only uses 1 temp variable.)
 *
 * Best case:
 *   2 comparisons
 *   0 assignments
 *
 * Worst case:
 *   3 comparisons
 *   4 assignments (3 + tmp var)
 */
void triswap_minassign(char * i1, char * i2, char * i3){
	// Unavoidable
	char tmp;

	// Entering: No information
	if(*i1 <= *i2){
		if(*i2 <= *i3){
			// i1 <= i2 <= i3
			return;
		} else if(*i1 <= *i3) {
			// i1 <= i3 < i2
			tmp = *i2;
			*i2 = *i3;
			*i3 = tmp;
			return;
		} else {
			// i3 < i1 <= i2
			tmp = *i2;
			*i2 = *i1;
			*i1 = *i3;
			*i3 = tmp;
			return;
		}
	}

	// Entering: i2 < i1
	if(*i1 <= *i3){
		// i2 < i1 <= i3
		tmp = *i1;
		*i1 = *i2;
		*i2 = tmp;
		return;
	}

	// Entering: i2 < i1, i3 < i1
	if(*i2 <= *i3){
		// i2 <= i3 < i1
		tmp = *i1;
		*i1 = *i2;
		*i2 = *i3;
		*i3 = tmp;
		return;
	}

	// Entering: i2 < i1, i3 < i1, i3 < i2
	// i3 < i2 < i1
	tmp = *i1;
	*i1 = *i3;
	*i3 = tmp;
}

