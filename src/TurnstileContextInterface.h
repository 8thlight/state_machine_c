#ifndef TurnstileContextInterface_H
#define TurnstileContextInterface_H
typedef void(*action_func_t)(void);

typedef struct TurnstileContextInterface
{
  action_func_t EngageLock;
  action_func_t ReleaseLock;
  action_func_t RefundCoin;
  action_func_t NotifySecurity;
} TurnstileContextInterface;

#endif //TurnstileContextInterface_H
