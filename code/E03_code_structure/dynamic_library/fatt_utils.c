#include "fatt.h"

int FATT_Compute( int n ) {
	if( n <= 1 )
		return 1;
	return n * FATT_Compute( n - 1 );
}
