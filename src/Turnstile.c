#include "Turnstile.h"

typedef enum TURNSTILE_STATES { LOCKED, UNLOCKED, OUT_OF_ORDER } TURNSTILE_STATES;
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
    case OUT_OF_ORDER:
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
    case OUT_OF_ORDER:
      context->NotifySecurity();
      break;
  }
}

void Turnstile_Full( void ) {
  switch (currentState) {
    case LOCKED:
      currentState = OUT_OF_ORDER;
      break;
    case UNLOCKED:
      break;
    case OUT_OF_ORDER:
      break;
  }
}

void Turnstile_Empty( void ) {
  switch (currentState) {
    case LOCKED:
      break;
    case UNLOCKED:
      break;
    case OUT_OF_ORDER:
      currentState = LOCKED;
      break;
  }
}
