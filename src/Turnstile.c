#include "Turnstile.h"
#include "TurnstileStateLocked.h"
#include "TurnstileStateUnlocked.h"

static TurnstileState * currentState;
static TurnstileContextInterface * context;
TurnstileState* UNLOCKED;
TurnstileState* LOCKED;

void Turnstile_Create( TurnstileContextInterface * turnstileContext )
{
  context = turnstileContext;
  UNLOCKED = &TurnstileStateUnlocked;
  LOCKED = &TurnstileStateLocked;
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

