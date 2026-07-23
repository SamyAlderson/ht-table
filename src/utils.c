#include <stdio.h>
#include <stdlib.h>

// Simple hash function: returns a value between 0 and n-1
size_t hash(size_t key, size_t n) {
    return key % n;
}

// Helper function to create a new node
typedef struct Node {
    size_t key;
    void* value;
    struct Node* next;
} Node;

// Initialize a new node
Node* new_node(size_t key, void* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

// Helper function to resize the hash table
void resize_table(Node** table, size_t old_size, size_t new_size) {
    // Create a new table with the new size
    Node** new_table = (Node**)malloc(new_size * sizeof(Node*));
    for (size_t i = 0; i < new_size; i++) {
        new_table[i] = NULL;
    }

    // Copy elements from the old table to the new table
    for (size_t i = 0; i < old_size; i++) {
        Node* curr = table[i];
        while (curr != NULL) {
            size_t index = hash(curr->key, new_size);
            Node* next_node = curr->next;
            curr->next = new_table[index];
            new_table[index] = curr;
            curr = next_node;
        }
    }

    // Free the old table
    for (size_t i = 0; i < old_size; i++) {
        Node* curr = table[i];
        while (curr != NULL) {
            Node* next_node = curr->next;
            free(curr);
            curr = next_node;
        }
    }

    // Update the table pointer
    free(table);
    table = new_table;
}

// Function to insert a new key-value pair into the hash table
void insert(Node** table, size_t size, size_t key, void* value) {
    // Resize the table if necessary
    if (size * 2 >= key) {
        resize_table(table, size, size * 2);
    }

    // Get the index of the key in the hash table
    size_t index = hash(key, size);

    // If the index is empty, create a new node
    if (table[index] == NULL) {
        table[index] = new_node(key, value);
    }
    // Otherwise, append the new node to the list
    else {
        Node* curr = table[index];
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node(key, value);
    }
}