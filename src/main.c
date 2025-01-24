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

#include <stdio.h>

#include "buffer_node.h"

int main(void)
{
    buffer_node_t *buff_head = NULL;
    printf("Buffer node sanity main starting\n");

    buffer_node_insert_tail(&buff_head, 21);
    buffer_node_insert_tail(&buff_head, 8);
    buffer_node_insert_head(&buff_head, 14);
    buffer_node_insert_tail(&buff_head, 11);
    buffer_node_print(&buff_head);
    buffer_node_remove_tail(&buff_head);
    printf("After removing tail :");
    buffer_node_print(&buff_head);
    buffer_node_remove_head(&buff_head);
    printf("After removing head :");
    buffer_node_print(&buff_head);    

    return 0;
}