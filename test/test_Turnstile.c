#include "unity.h"
#include "Turnstile.h"


void TurnstyleTest_Create(void) { }
void TurnstyleTest_Destroy(void) { }
void TurnstyleTest_EngageLock(void) { }
void TurnstyleTest_ReleaseLock(void) { }
void TurnstyleTest_RefundCoin(void) { }
void TurnstyleTest_NotifySecurity(void) { }

TurnstileContextInterface testContext = {
  &TurnstyleTest_EngageLock,
  &TurnstyleTest_ReleaseLock,
  &TurnstyleTest_RefundCoin,
  &TurnstyleTest_NotifySecurity
};

void setUp(void)
{
  Turnstile_Create(&testContext);
}

void tearDown(void)
{
  Turnstile_Destroy();
}

void test_(void)
{
}
