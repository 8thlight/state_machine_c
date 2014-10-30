#include "Turnstile.h"
#include "TurnstileStateLocked.h"
#include "TurnstileStateUnlocked.h"
#include "TurnstileStateOutOfOrder.h"

static TurnstileState * currentState;
static TurnstileContextInterface * context;
TurnstileState* UNLOCKED;
TurnstileState* LOCKED;
TurnstileState* OUT_OF_ORDER;

void Turnstile_Create( TurnstileContextInterface * turnstileContext )
{
  context = turnstileContext;
  UNLOCKED = &TurnstileStateUnlocked;
  LOCKED = &TurnstileStateLocked;
  OUT_OF_ORDER = &TurnstileStateOutOfOrder;
  currentState = LOCKED;
}

void Turnstile_Destroy(void){
}

void Turnstile_SetState(TurnstileState * state) {
  currentState = state;
}

void Turnstile_Coin(void){
  currentState->Coin(context);
}

void Turnstile_Push(void){
  currentState->Push(context);
}

void Turnstile_Empty( void ){
  currentState->Empty(context);
}
void Turnstile_Full( void ) {
  currentState->Full(context);
}
