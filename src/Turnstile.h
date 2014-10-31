#ifndef Turnstile_H
#define Turnstile_H

#include "turnstile_sm.h"
#include "TurnstileContextInterface.h"

typedef struct Turnstile Turnstile;

Turnstile * Turnstile_Create( TurnstileContextInterface * actions );
void Turnstile_Destroy( Turnstile* );

/* Events */
void Turnstile_Coin( Turnstile* );
void Turnstile_Push( Turnstile* );

/* Actions */
void Turnstile_EngageLock( Turnstile* );
void Turnstile_ReleaseLock( Turnstile* );
void Turnstile_RefundCoin( Turnstile* );
void Turnstile_NotifySecurity( Turnstile* );

#endif // Turnstile_H
