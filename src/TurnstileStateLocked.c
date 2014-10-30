#include "TurnstileStateLocked.h"
#include "Turnstile.h"

void LockedState_Coin( TurnstileContextInterface* context ) {
  context->ReleaseLock();
  Turnstile_SetState( UNLOCKED );
}

void LockedState_Push( TurnstileContextInterface* context ) {
  context->NotifySecurity();
}

TurnstileState TurnstileStateLocked = {
  LockedState_Coin,
  LockedState_Push
};
