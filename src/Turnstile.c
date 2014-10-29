#include "Turnstile.h"

static int currentState;
static TurnstileContextInterface * context;

void Turnstile_Create( TurnstileContextInterface * turnstileContext ) {
  context = turnstileContext;
}

void Turnstile_Destroy(void){
}

void Turnstile_Coin(void){
}

void Turnstile_Push(void){
}

