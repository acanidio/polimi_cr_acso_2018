#include <stdio.h>
#include "fatt.h"

int main( int argc, char **argv ) {
	FATT_Init();
	printf("Initialized.\n");
	printf("Current: %d\n", FATT_Current() );
	printf("Next:    %d\n", FATT_Next()    );
	printf("Next:    %d\n", FATT_Next()    );
	printf("Next:    %d\n", FATT_Next()    );
	printf("Next:    %d\n", FATT_Prev()    );
	printf("Resetted.\n");
	printf("Current: %d\n", FATT_Current() );
	printf("Next:    %d\n", FATT_Next()    );
	printf("Prev:    %d\n", FATT_Prev()    );
	printf("Prev:    %d\n", FATT_Prev()    );
	printf("Prev:    %d\n", FATT_Prev()    );

	return 0;
}
