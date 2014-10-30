#include "TurnstileStateUnlocked.h"
#include "Turnstile.h"

void UnlockedState_Coin( TurnstileContextInterface* context ) {
  context->RefundCoin();
}

void UnlockedState_Push( TurnstileContextInterface* context ) {
  context->EngageLock();
  Turnstile_SetState( LOCKED );
}

TurnstileState TurnstileStateUnlocked = {
  UnlockedState_Coin,
  UnlockedState_Push
};
