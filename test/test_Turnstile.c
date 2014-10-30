#include "unity.h"
#include "Turnstile.h"
#include "TurnstileContext.h"


void setUp(void)
{
  Turnstile_Create();
}

void tearDown( void )
{
  Turnstile_Destroy();
}

void test_coin_releases_lock( void )
{
  Turnstile_Coin();
  TEST_ASSERT_EQUAL(currentState, UNLOCKED);
}

void test_second_coin_is_refunded( void )
{
  Turnstile_Coin();
  Turnstile_Coin();
  TEST_ASSERT_EQUAL(currentState, UNLOCKED);
}

void test_pass_engages_lock( void )
{
  Turnstile_Coin();
  Turnstile_Push();
  TEST_ASSERT_EQUAL(currentState, LOCKED);
}

void test_multiple_locks_released( void )
{
  Turnstile_Coin();
  Turnstile_Push();
  Turnstile_Coin();
  TEST_ASSERT_EQUAL(currentState, UNLOCKED);
}

void test_security_is_notified( void )
{
  Turnstile_Push();
  TEST_ASSERT_EQUAL(currentState, LOCKED);
}
