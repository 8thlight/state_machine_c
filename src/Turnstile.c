#include "Turnstile.h"
#include <stdlib.h>

struct Turnstile{
  struct turnstileContext fsm;
  TurnstileContextInterface * actions;
};

Turnstile* Turnstile_Create( TurnstileContextInterface * actions ) {
  Turnstile * this = malloc( sizeof( Turnstile ) );
  turnstileContext_Init(&this->fsm, this);
  this->actions = actions;
  return this;
}

void Turnstile_Destroy(Turnstile* this){
  free( this );
}

void Turnstile_Coin(Turnstile* this){
  turnstileContext_Coin( &this->fsm );
}

void Turnstile_Push(Turnstile* this){
  turnstileContext_Push( &this->fsm );
}

void Turnstile_EngageLock( Turnstile* this )
{
  this->actions->EngageLock();
}

void Turnstile_ReleaseLock( Turnstile* this )
{
  this->actions->ReleaseLock();
}

void Turnstile_RefundCoin( Turnstile* this )
{
  this->actions->RefundCoin();
}

void Turnstile_NotifySecurity( Turnstile* this )
{
  this->actions->NotifySecurity();
}

