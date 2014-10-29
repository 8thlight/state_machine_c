#ifndef TurnstileContext_H
#define TurnstileContext_H

typedef struct TurnstileContext TurnstileContext;

void TurnstileContext_Create(void);
void TurnstileContext_Destroy();
void TurnstileContext_EngageLock();
void TurnstileContext_ReleaseLock();
void TurnstileContext_RefundCoin();
void TurnstileContext_NotifySecurity();
#endif // TurnstileContext_H
