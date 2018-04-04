#include "fatt.h"

static int FATT_State = 0;

void FATT_Init( void ) {
	FATT_State = 0;
}

int FATT_Next( void ) {
	FATT_State++;
	return FATT_Compute( FATT_State );
}

int FATT_Current( void ) {
	return FATT_Compute( FATT_State );
}

int FATT_Prev( void ) {
	if( FATT_State > 0 ) {
		FATT_State--;
	}
	return FATT_Compute( FATT_State );
}
