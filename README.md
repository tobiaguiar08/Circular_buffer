# Circular buffer
A simple implementation of a circular buffer using Test-Driven Development.

# Requirements list
## General
The circular buffer will be a linked-list-like structure implemented as an ADT.
The buffer will store unsigned integer data. A size must be provided by the user.
## Encapsulation
The ADT will provide a clear interface for interacting with the buffer.
Internal details like node structures, pointers, and sizes will be hidden.
## Initialization and Cleanup
The ADT will include functions to initialize and clean up the buffer safely.
Cleanup must handle memory deallocation and ensure no resource leaks.
## Operations
Add nodes at the head, tail, or after a filtered node.
Remove nodes from the head, tail, or based on a filtering pattern.
Support traversal through the buffer for inspection or manipulation.
## Filtering
Filters will be defined as user-provided functions (e.g., callbacks).
Only one filter can be applied per operation.
## Memory Management
Nodes will be dynamically allocated and deallocated as needed.
Memory allocation failures will be gracefully handled.
## Error Handling
The ADT will return meaningful status codes for invalid operations or errors.
Provide clear feedback for edge cases, such as operating on an empty buffer.
## Edge Cases
Handle operations like adding or removing nodes in an empty buffer or removing the only node in the buffer.
## Documentation
Provide comprehensive documentation for the ADT interface.
Hide internal implementation details from users of the ADT.