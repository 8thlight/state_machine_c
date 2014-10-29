#ifndef Turnstile_H
#define Turnstile_H

#include "TurnstileContextInterface.h"


void Turnstile_Create( TurnstileContextInterface * );
void Turnstile_Destroy( void );
void Turnstile_Coin( void );
void Turnstile_Push( void );


#endif // Turnstile_H
