#include "Turnstile.h"

typedef void (*event_func_t)(TurnstileContextInterface*);

typedef struct TurnstyleState {
  event_func_t Coin;
  event_func_t Push;
} TurnstyleState;

static TurnstyleState * currentState;
static TurnstileContextInterface * context;
static TurnstyleState* UNLOCKED;
static TurnstyleState* LOCKED;


void LockedState_Coin( TurnstileContextInterface* context ) {
  context->ReleaseLock();
  currentState = UNLOCKED;
}

void LockedState_Push( TurnstileContextInterface* context ) {
  context->NotifySecurity();
}

TurnstyleState locked = {
  LockedState_Coin,
  LockedState_Push
};

void UnlockedState_Coin( TurnstileContextInterface* context ) {
  context->RefundCoin();
}

void UnlockedState_Push( TurnstileContextInterface* context ) {
  context->EngageLock();
  currentState = LOCKED;
}

TurnstyleState unlocked = {
  UnlockedState_Coin,
  UnlockedState_Push
};


void Turnstile_Create( TurnstileContextInterface * turnstileContext )
{
  context = turnstileContext;
  UNLOCKED = &unlocked;
  LOCKED = &locked;
  currentState = LOCKED;
}

void Turnstile_Destroy(void){
}

void Turnstile_Coin(void){
  currentState->Coin(context);
}

void Turnstile_Push(void){
  currentState->Push(context);
}

