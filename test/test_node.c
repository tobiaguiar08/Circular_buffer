#include "unity.h"
#include "node.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_node_init(void) {
    TEST_FAIL_MESSAGE("Starting here");
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_node_init);
    return UNITY_END();
}