#ifndef Turnstile_H
#define Turnstile_H

#include "TurnstileContext.h"

typedef struct Turnstile Turnstile;

void Turnstile_Create(void );
void Turnstile_Destroy(void);
void Turnstile_Coin(void);
void Turnstile_Push(void);


#endif // Turnstile_H
