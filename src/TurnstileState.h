#ifndef TurnstileState_H
#define TurnstileState_H
#include "TurnstileContextInterface.h"

typedef void ( *event_func_t )( TurnstileContextInterface* );

typedef struct TurnstileState TurnstileState;

struct TurnstileState {
  event_func_t Coin;
  event_func_t Push;
};
#endif // TurnstileState_H
