#include "TurnstileStateUnlocked.h"
#include "Turnstile.h"

void UnlockedState_Coin( TurnstileContextInterface* context ) {
  context->RefundCoin();
}

void UnlockedState_Push( TurnstileContextInterface* context ) {
  context->EngageLock();
  Turnstile_SetState( LOCKED );
}
void UnlockedState_Full( TurnstileContextInterface* context ) { }
void UnlockedState_Empty( TurnstileContextInterface* context ) { }

TurnstileState TurnstileStateUnlocked = {
  UnlockedState_Coin,
  UnlockedState_Push,
  UnlockedState_Full,
  UnlockedState_Empty
};
