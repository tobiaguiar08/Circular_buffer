# Circular buffer
A simple implementation of a circular buffer using Test-Driven Development.

# Requirements list
## General
The circular buffer will be either a double-linked-list-like structure using an ADT. 

## Encapsulation
The ADT will provide a clear interface for interacting with the buffer.
Internal details like node structures, pointers, and sizes will be hidden.
## Initialization and Cleanup
The ADT will include functions to initialize and clean up the buffer safely.
Cleanup must handle memory deallocation (if used) and ensure no resource leaks.
## Operations
Add nodes at the head and tail.
Remove nodes from the head, tail.

## Memory Management
Nodes will be dynamically allocated and deallocated as needed.
Memory allocation failures will be gracefully handled.
## Edge Cases
Handle operations like adding or removing nodes in an empty buffer or removing the only node in the buffer.
## Documentation
Provide comprehensive documentation for the ADT interface.
Hide internal implementation details from users of the ADT.