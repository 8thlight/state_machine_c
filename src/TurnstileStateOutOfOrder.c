#include "TurnstileStateOutOfOrder.h"
#include "Turnstile.h"

void OutOfOrderState_Coin( TurnstileContextInterface* context ) {
  context->RefundCoin();
}

void OutOfOrderState_Push( TurnstileContextInterface* context ) {
  context->NotifySecurity();
}

void OutOfOrderState_Full( TurnstileContextInterface* context ) {
}

void OutOfOrderState_Empty( TurnstileContextInterface* context ) {
  Turnstile_SetState( LOCKED );
}

TurnstileState TurnstileStateOutOfOrder = {
  OutOfOrderState_Coin,
  OutOfOrderState_Push,
  OutOfOrderState_Full,
  OutOfOrderState_Empty
};
