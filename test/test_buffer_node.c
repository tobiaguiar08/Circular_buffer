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
#define DUMMY_DATA_TAIL 62
#define DUMMY_DATA_HEAD 70

static buffer_node_t *test_node;

void setUp(void) {
    test_node =  buffer_node_create(DUMMY_DATA);
}

void tearDown(void) {
    buffer_node_destroy_all(&test_node);
}

void test_node_create(void) {
    TEST_ASSERT_NOT_NULL(test_node);
    TEST_ASSERT_EQUAL_UINT32(DUMMY_DATA, buffer_node_get_data(test_node));
}

void test_node_tail_insertion(void) {
    buffer_node_insert_tail(&test_node, DUMMY_DATA_TAIL);
    TEST_ASSERT_EQUAL_UINT32(DUMMY_DATA_TAIL, buffer_node_get_tail_data(test_node));
}

void test_node_head_insertion(void) {
    buffer_node_t *before, *after;

    before = test_node;

    buffer_node_insert_head(&test_node, DUMMY_DATA_HEAD);
    TEST_ASSERT_EQUAL_UINT32(DUMMY_DATA_HEAD, buffer_node_get_data(test_node));
    after = test_node;

    TEST_ASSERT_TRUE(after != before);
}

void test_node_tail_remove(void) {
    buffer_node_insert_tail(&test_node, 1);
    buffer_node_insert_tail(&test_node, 888);
    buffer_node_remove_tail(&test_node);
    TEST_ASSERT_EQUAL_UINT32(1, buffer_node_get_tail_data(test_node));
}

void test_node_head_remove(void) {
    buffer_node_insert_head(&test_node, 12);
    buffer_node_insert_head(&test_node, 13);
    buffer_node_insert_head(&test_node, 14);
    TEST_ASSERT_EQUAL_UINT32(14, buffer_node_get_data(test_node));
    buffer_node_remove_head(&test_node);
    TEST_ASSERT_EQUAL_UINT32(13, buffer_node_get_data(test_node));
}

void test_node_print(void) {
    buffer_node_insert_tail(&test_node, 21);
    buffer_node_insert_tail(&test_node, 8);
    buffer_node_insert_head(&test_node, 14);
    buffer_node_insert_tail(&test_node, 11);
    TEST_ASSERT(buffer_node_print(&test_node) == 0);
}

void test_node_print_empty(void)
{
    buffer_node_t *nil_buffer = NULL;
    TEST_ASSERT(buffer_node_print(&nil_buffer) == -1);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_node_create);
    RUN_TEST(test_node_tail_insertion);
    RUN_TEST(test_node_head_insertion);
    RUN_TEST(test_node_tail_remove);
    RUN_TEST(test_node_head_remove);
    RUN_TEST(test_node_print);
    RUN_TEST(test_node_print_empty);
    return UNITY_END();
}