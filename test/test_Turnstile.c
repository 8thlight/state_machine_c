#include "unity.h"
#include "Turnstile.h"
#include "TurnstileState.h"
#include "TurnstileStateLocked.h"
#include "TurnstileStateUnlocked.h"


int lockEngaged = 0;
void TurnstyleTest_EngageLock(void) { lockEngaged = 1; }

int lockReleased = 0;
void TurnstyleTest_ReleaseLock(void) { lockReleased = 1; }

int coinRefunded = 0;
void TurnstyleTest_RefundCoin(void) { coinRefunded = 1; }

int securityNotified = 0;
void TurnstyleTest_NotifySecurity(void) { securityNotified = 1; }

void resetMocks() {
  lockReleased = 0;
  lockEngaged = 0;
  coinRefunded = 0;
  securityNotified = 0;
}

TurnstileContextInterface testContext = {
  &TurnstyleTest_EngageLock,
  &TurnstyleTest_ReleaseLock,
  &TurnstyleTest_RefundCoin,
  &TurnstyleTest_NotifySecurity
};

void setUp(void)
{
  Turnstile_Create(&testContext);
  resetMocks();
}

void tearDown( void )
{
  Turnstile_Destroy();
}

void test_coin_releases_lock( void )
{
  Turnstile_Coin();
  TEST_ASSERT_TRUE(lockReleased);
}

void test_second_coin_is_refunded( void )
{
  Turnstile_Coin();
  lockReleased = 0;
  Turnstile_Coin();
  TEST_ASSERT_TRUE( coinRefunded );
  TEST_ASSERT_FALSE( lockReleased );
}

void test_pass_engages_lock( void )
{
  Turnstile_Coin();
  Turnstile_Push();
  TEST_ASSERT_TRUE( lockEngaged );
}

void test_multiple_locks_released( void )
{
  Turnstile_Coin();
  Turnstile_Push();
  resetMocks();
  Turnstile_Coin();
  TEST_ASSERT_TRUE(lockReleased);
}

void test_security_is_notified( void )
{
  Turnstile_Push();
  TEST_ASSERT_TRUE( securityNotified );
}

// void test_out_of_order_coin( void )
// {
//   Turnstile_Full();
//   Turnstile_Coin();
//   TEST_ASSERT_FALSE( lockReleased );
//   TEST_ASSERT_TRUE( coinRefunded );
// }
//
// void test_out_of_order_push( void )
// {
//   Turnstile_Full();
//   Turnstile_Push();
//   TEST_ASSERT_FALSE( lockReleased );
//   TEST_ASSERT_TRUE( securityNotified );
// }
//void test_empty( void )
//{
//  Turnstile_Full();
//  Turnstile_Empty();
//  Turnstile_Coin();
//  TEST_ASSERT_TRUE(lockReleased);
//}
