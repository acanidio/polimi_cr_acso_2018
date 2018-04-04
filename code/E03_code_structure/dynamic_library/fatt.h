#ifndef FATT_H
#define FATT_H

#define FATT_Reset	FATT_Init

void FATT_Init   ( void  );
int  FATT_Next   ( void  );
int  FATT_Current( void  );
int  FATT_Prev   ( void  );
int  FATT_Compute( int n );

#endif
