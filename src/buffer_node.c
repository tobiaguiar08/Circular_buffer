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

#include "buffer_node.h"

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>


struct buffer_node {
    unsigned int data;
    struct buffer_node *next;
    struct buffer_node *prev;
};

struct buffer_node *buffer_node_create(unsigned int data)
{
    struct buffer_node *new;

    new = (struct buffer_node *)malloc(sizeof(struct buffer_node *));
    assert(new != NULL);

    buffer_node_set_data(new, data);
    buffer_node_set_next(new, NULL);
    buffer_node_set_prev(new, NULL);

    return new;
}

void buffer_node_destroy(buffer_node_t *buffer_node)
{
    assert(buffer_node != NULL);

    free(buffer_node);
}

unsigned int buffer_node_get_data(buffer_node_t *buffer_node)
{
    assert(buffer_node != NULL);

    return buffer_node->data;
}


void buffer_node_set_data(buffer_node_t *buffer_node, unsigned int data)
{
    assert(buffer_node != NULL);

    buffer_node->data = data;
}

void buffer_node_set_next(buffer_node_t *buffer_node, buffer_node_t *next)
{
    assert(buffer_node != NULL);

    buffer_node->next = next;
}

buffer_node_t *buffer_node_get_next(buffer_node_t *buffer_node)
{
    assert(buffer_node != NULL);

    return buffer_node->next;
}

void buffer_node_set_prev(buffer_node_t *buffer_node, buffer_node_t *prev)
{
    assert(buffer_node != NULL);

    buffer_node->prev = prev;
}

buffer_node_t *buffer_node_get_prev(buffer_node_t *buffer_node)
{
    assert(buffer_node != NULL);

    return buffer_node->prev;
}