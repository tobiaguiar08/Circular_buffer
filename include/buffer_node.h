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

/**
 * @brief Creates a new buffer node with the given data.
 *
 * Allocates memory for a new node, sets its data, and initializes next and prev pointers to NULL.
 *
 * @param data The data to be stored in the new node.
 *
 * @return A pointer to the newly created buffer node.
 */
buffer_node_t *buffer_node_create(unsigned int data);

/**
 * @brief Destroys a buffer node, freeing its memory.
 *
 * @param buffer_node A pointer to a pointer to the node to be destroyed.
 */
void buffer_node_destroy(buffer_node_t **buffer_node);

/**
 * @brief Destroys all the nodes in the circular list.
 *
 * Iterates through the list, freeing each node's memory until the entire list is destroyed.
 *
 * @param buffer_node_head A pointer to a pointer to the head of the list.
 */
void buffer_node_destroy_all(buffer_node_t **buffer_node_head);

/**
 * @brief Gets the data stored in a buffer node.
 *
 * @param buffer_node A pointer to the buffer node whose data is to be retrieved.
 *
 * @return The data stored in the node.
 */
unsigned int buffer_node_get_data(buffer_node_t *buffer_node);

/**
 * @brief Inserts a new node with the given data at the tail of the list.
 *
 * If the list is empty, the new node becomes the head.
 *
 * @param head A pointer to the head of the list.
 * @param data The data to be stored in the new tail node.
 */
void buffer_node_insert_tail(buffer_node_t **head, unsigned int data);

/**
 * @brief Gets the data of the last node in the list (the tail node).
 *
 * @param buffer_node_head A pointer to the head of the list.
 *
 * @return The data of the tail node.
 */
unsigned int buffer_node_get_tail_data(buffer_node_t *buffer_node_head);

/**
 * @brief Removes the last node from the list (the tail node).
 *
 * Frees the memory of the removed node and adjusts the list's links accordingly.
 *
 * @param head A pointer to the head of the list.
 */
void buffer_node_remove_tail(buffer_node_t **head);

/**
 * @brief Inserts a new node with the given data at the head of the list.
 *
 * If the list is not empty, the new node becomes the new head.
 *
 * @param head A pointer to the head of the list.
 * @param data The data to be stored in the new head node.
 */
void buffer_node_insert_head(buffer_node_t **head, unsigned int data);

/**
 * @brief Removes the first node from the list (the head node).
 *
 * Frees the memory of the removed node and adjusts the list's links accordingly.
 *
 * @param head A pointer to the head of the list.
 */
void buffer_node_remove_head(buffer_node_t **head);

/**
 * @brief Gets the data of the first node in the list (the head node).
 *
 * @param buffer_node_head A pointer to the head of the list.
 *
 * @return The data of the head node.
 */
unsigned int buffer_node_get_head_data(buffer_node_t *buffer_node_head);

/**
 * @brief Prints the contents of the circular buffer.
 *
 * This function traverses the list, printing the data of each node until it loops back to the head.
 *
 * @param head A pointer to the head of the list.
 *
 * @return 0 if the list is not empty, -1 if the list is empty.
 */
int buffer_node_print(buffer_node_t **head);
#endif // BUFFER_NODE_H