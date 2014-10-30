#include "Turnstile.h"
#include "TurnstileContext.h"

TURNSTILE_STATES currentState;

void Turnstile_Create() {
  currentState = LOCKED;
}

void Turnstile_Destroy(void){
}

void Turnstile_Coin(void){
  switch (currentState) {
    case LOCKED:
      TurnstileContext_ReleaseLock();
      currentState = UNLOCKED;
      break;
    case UNLOCKED:
      TurnstileContext_RefundCoin();
      break;
  }
}

void Turnstile_Push(void){
  switch (currentState) {
    case LOCKED:
      TurnstileContext_NotifySecurity();
      break;
    case UNLOCKED:
      TurnstileContext_EngageLock();
      currentState = LOCKED;
      break;
  }
}

