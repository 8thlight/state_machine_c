#include "TurnstileStateLocked.h"
#include "Turnstile.h"

void LockedState_Coin( TurnstileContextInterface* context ) {
  context->ReleaseLock();
  Turnstile_SetState( UNLOCKED );
}

void LockedState_Push( TurnstileContextInterface* context ) {
  context->NotifySecurity();
}

void LockedState_Full( TurnstileContextInterface* context ) {
  Turnstile_SetState( OUT_OF_ORDER );
}
void LockedState_Empty( TurnstileContextInterface* context ) { }

TurnstileState TurnstileStateLocked = {
  LockedState_Coin,
  LockedState_Push,
  LockedState_Full,
  LockedState_Empty
};

