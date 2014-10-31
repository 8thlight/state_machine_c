#include "unity.h"
#include "Turnstile.h"
#include "turnstile_sm.h"

int lockEngaged = 0;
void TurnstileTest_EngageLock(void) { lockEngaged = 1; }

int lockReleased = 0;
void TurnstileTest_ReleaseLock(void) { lockReleased = 1; }

int coinRefunded = 0;
void TurnstileTest_RefundCoin(void) { coinRefunded = 1; }

int securityNotified = 0;
void TurnstileTest_NotifySecurity(void) { securityNotified = 1; }

void resetMocks() {
  lockReleased = 0;
  lockEngaged = 0;
  coinRefunded = 0;
  securityNotified = 0;
}

TurnstileContextInterface testContext = {
  &TurnstileTest_EngageLock,
  &TurnstileTest_ReleaseLock,
  &TurnstileTest_RefundCoin,
  &TurnstileTest_NotifySecurity
};

Turnstile * turnstile;

void setUp(void)
{
  turnstile = Turnstile_Create( &testContext );
  resetMocks();
}

void tearDown( void )
{
  Turnstile_Destroy( turnstile );
}

void test_coin_releases_lock( void )
{
  Turnstile_Coin( turnstile );
  TEST_ASSERT_TRUE(lockReleased);
}

void test_second_coin_is_refunded( void )
{
  Turnstile_Coin( turnstile );
  lockReleased = 0;
  Turnstile_Coin( turnstile );
  TEST_ASSERT_TRUE( coinRefunded );
  TEST_ASSERT_FALSE( lockReleased );
}

void test_pass_engages_lock( void )
{
  Turnstile_Coin( turnstile );
  Turnstile_Push( turnstile );
  TEST_ASSERT_TRUE( lockEngaged );
}

void test_multiple_locks_released( void )
{
  Turnstile_Coin( turnstile );
  Turnstile_Push( turnstile );
  resetMocks();
  Turnstile_Coin( turnstile );
  TEST_ASSERT_TRUE(lockReleased);
}

void test_security_is_notified( void )
{
  Turnstile_Push( turnstile );
  TEST_ASSERT_TRUE( securityNotified );
}

// void test_out_of_order_coin( void )
// {
//   Turnstile_Full( turnstile );
//   Turnstile_Coin( turnstile );
//   TEST_ASSERT_FALSE( lockReleased );
//   TEST_ASSERT_TRUE( coinRefunded );
// }
//
// void test_out_of_order_push( void )
// {
//   Turnstile_Full( turnstile );
//   Turnstile_Push( turnstile );
//   TEST_ASSERT_FALSE( lockReleased );
//   TEST_ASSERT_TRUE( securityNotified );
// }
