#include "Turnstile.h"

typedef enum TURNSTILE_STATES { LOCKED, UNLOCKED } TURNSTILE_STATES;
static TURNSTILE_STATES currentState;
static TurnstileContextInterface * context;

void Turnstile_Create( TurnstileContextInterface * turnstileContext ) {
  context = turnstileContext;
  currentState = LOCKED;
}

void Turnstile_Destroy(void){
}

void Turnstile_Coin(void){
  switch (currentState) {
    case LOCKED:
      context->ReleaseLock();
      currentState = UNLOCKED;
      break;
    case UNLOCKED:
      context->RefundCoin();
      break;
  }
}

void Turnstile_Push(void){
  switch (currentState) {
    case LOCKED:
      context->NotifySecurity();
      break;
    case UNLOCKED:
      context->EngageLock();
      currentState = LOCKED;
      break;
  }
}

