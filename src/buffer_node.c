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

static void buffer_node_set_next(buffer_node_t *buffer_node, buffer_node_t *next)
{
    assert(buffer_node != NULL);

    buffer_node->next = next;
}

static void buffer_node_set_prev(buffer_node_t *buffer_node, buffer_node_t *prev)
{
    assert(buffer_node != NULL);

    buffer_node->prev = prev;
}

static buffer_node_t *buffer_node_get_next(buffer_node_t *buffer_node)
{
    assert(buffer_node != NULL);

    return buffer_node->next;
}

static buffer_node_t *buffer_node_get_prev(buffer_node_t *buffer_node)
{
    assert(buffer_node != NULL);

    return buffer_node->prev;
}

struct buffer_node *buffer_node_create(unsigned int data)
{
    struct buffer_node *new;

    new = (struct buffer_node *)malloc(sizeof(struct buffer_node));
    assert(new != NULL);

    buffer_node_set_data(new, data);
    buffer_node_set_next(new, NULL);
    buffer_node_set_prev(new, NULL);

    return new;
}

void buffer_node_destroy(buffer_node_t **buffer_node)
{
    assert(buffer_node != NULL);

    free(*buffer_node);
}

void buffer_node_destroy_all(buffer_node_t **buffer_node_head)
{
    assert(*buffer_node_head != NULL);
    buffer_node_t *current, *next;

    current = *buffer_node_head;
    do {
        next = current->next != NULL ? buffer_node_get_next(current) : NULL;
        buffer_node_destroy(&current);
        current = next;
    } while (current != NULL);
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

void buffer_node_insert_tail(buffer_node_t **head, unsigned int data)
{
    buffer_node_t *last_tail_node;
    buffer_node_t *new_tail_node = buffer_node_create(data);

    if (*head == NULL) {
        *head = new_tail_node; 
    } else {
        if ((*head)->prev) {
            last_tail_node = buffer_node_get_prev(*head);
            buffer_node_set_prev(*head, new_tail_node);
            buffer_node_set_prev(new_tail_node, last_tail_node);
            buffer_node_set_next(last_tail_node, new_tail_node);
        } else {
            buffer_node_set_prev(new_tail_node, *head);
            buffer_node_set_prev(*head, new_tail_node);
            buffer_node_set_next(*head, new_tail_node);
        }       
    }
}

unsigned int buffer_node_get_tail_data(buffer_node_t *buffer_node_head)
{
    assert(buffer_node_head != NULL);

    buffer_node_t *tail = buffer_node_get_prev(buffer_node_head) ? buffer_node_get_prev(buffer_node_head) : buffer_node_head;

    return tail->data;
}

void buffer_node_remove_tail(buffer_node_t **head)
{
    buffer_node_t *tail_node;
    if (*head) {
        if ((*head)->prev) {
            tail_node = buffer_node_get_prev(*head);
            if (tail_node->prev != *head) {
                buffer_node_set_prev(*head, tail_node->prev);
            } else {
                buffer_node_set_prev(*head, NULL);
            }
            
            buffer_node_set_next(tail_node->prev, tail_node->next);
        } else {
            tail_node = *head;
        }

        buffer_node_destroy(&tail_node);
    }
}

void buffer_node_insert_head(buffer_node_t **head, unsigned int data)
{
    buffer_node_t *new_head_node = buffer_node_create(data);

    if (*head) {
        buffer_node_set_next(new_head_node, *head);
        buffer_node_set_prev(new_head_node, (*head)->prev);
        buffer_node_set_prev(*head, new_head_node);
    }

    *head = new_head_node;
}

void buffer_node_remove_head(buffer_node_t **head)
{
    buffer_node_t *new_head_node = NULL;
    buffer_node_t *tail_node = NULL;
    buffer_node_t *head_to_destroy = NULL;
    if(*head) {
        head_to_destroy = *head;
        if ((*head)->next) {
            new_head_node = buffer_node_get_next(*head);
            tail_node = buffer_node_get_prev(*head);
            buffer_node_set_prev(new_head_node, tail_node);
            buffer_node_destroy(&head_to_destroy);
            *head = new_head_node;
        } else {
            buffer_node_destroy(&head_to_destroy);
            head = NULL;            
        }
    }
}
