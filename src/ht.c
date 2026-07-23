#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HT_SIZE 128
#define KEY_SIZE 1024

typedef struct ht_node {
    char key[KEY_SIZE];
    void* value;
    struct ht_node* next;
} ht_node;

typedef struct hash_table {
    ht_node** buckets;
    size_t size;
} hash_table;

hash_table* ht_init() {
    hash_table* table = (hash_table*) malloc(sizeof(hash_table));
    table->buckets = (ht_node**) malloc(HT_SIZE * sizeof(ht_node*));
    table->size = HT_SIZE;
    for (size_t i = 0; i < HT_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

size_t ht_hash(const char* key) {
    size_t hash = 0;
    for (size_t i = 0; i < strlen(key); i++) {
        hash += key[i];
    }
    return hash % HT_SIZE;
}

void ht_insert(hash_table* table, const char* key, void* value) {
    size_t index = ht_hash(key);
    ht_node* new_node = (ht_node*) malloc(sizeof(ht_node));
    strcpy(new_node->key, key);
    new_node->value = value;
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

void* ht_search(hash_table* table, const char* key) {
    size_t index = ht_hash(key);
    ht_node* current = table->buckets[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

void ht_delete(hash_table* table, const char* key) {
    size_t index = ht_hash(key);
    ht_node* current = table->buckets[index];
    ht_node* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                table->buckets[index] = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void ht_destroy(hash_table* table) {
    for (size_t i = 0; i < HT_SIZE; i++) {
        ht_node* current = table->buckets[i];
        while (current != NULL) {
            ht_node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(table->buckets);
    free(table);
}