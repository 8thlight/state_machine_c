#ifndef Turnstile_H
#define Turnstile_H

#include "TurnstileContextInterface.h"

typedef enum TURNSTILE_STATES { LOCKED, UNLOCKED } TURNSTILE_STATES;
extern TURNSTILE_STATES currentState;

void Turnstile_Create( );
void Turnstile_Destroy( void );
void Turnstile_Coin( void );
void Turnstile_Push( void );


#endif // Turnstile_H
