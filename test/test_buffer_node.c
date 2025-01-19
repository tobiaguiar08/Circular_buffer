/*
 * MIT License
 *
 * Copyright (c) 2025 tobiaguiar08
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "unity.h"
#include "buffer_node.h"

#define DUMMY_DATA 5

static buffer_node_t *test_node;

void setUp(void) {
}

void tearDown(void) {
}

void test_node_create(void) {
    test_node =  buffer_node_create(DUMMY_DATA);
    TEST_ASSERT_NOT_NULL(test_node);
    TEST_ASSERT_EQUAL_UINT32(DUMMY_DATA, buffer_node_get_data(test_node));
    TEST_ASSERT_NULL(buffer_node_get_next(test_node));
    TEST_ASSERT_NULL(buffer_node_get_prev(test_node));

    buffer_node_destroy(test_node);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_node_create);
    return UNITY_END();
}