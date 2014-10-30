#ifndef Turnstile_H
#define Turnstile_H

#include "TurnstileContextInterface.h"
#include "TurnstileState.h"

void Turnstile_Create( TurnstileContextInterface * );
void Turnstile_Destroy( void );
void Turnstile_Coin( void );
void Turnstile_Push( void );
void Turnstile_Empty( void );
void Turnstile_Full( void );
void Turnstile_SetState(TurnstileState * state);
extern TurnstileState * UNLOCKED;
extern TurnstileState * LOCKED;
extern TurnstileState * OUT_OF_ORDER;


#endif // Turnstile_H
