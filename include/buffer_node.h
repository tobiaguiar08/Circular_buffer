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

#ifndef BUFFER_NODE_H
#define BUFFER_NODE_H

typedef struct buffer_node buffer_node_t;

buffer_node_t *buffer_node_create(unsigned int data);
void buffer_node_destroy(buffer_node_t *buffer_node);

unsigned int buffer_node_get_data(buffer_node_t *buffer_node);
void buffer_node_set_data(buffer_node_t *buffer_node, unsigned int data);

buffer_node_t *buffer_node_get_next(buffer_node_t *buffer_node);
void buffer_node_set_next(buffer_node_t *buffer_node, buffer_node_t *next);

buffer_node_t *buffer_node_get_prev(buffer_node_t *buffer_node);
void buffer_node_set_prev(buffer_node_t *buffer_node, buffer_node_t *prev);

#endif // BUFFER_NODE_H