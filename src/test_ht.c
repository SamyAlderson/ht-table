#include "ht.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NUM_TESTS 5

static void test_insert_and_search() {
  // Create a new hash table with initial size 10
  htable_t *ht = htable_create(10);
  assert(ht != NULL);

  // Insert key-value pairs
  assert(htable_insert(ht, "key1", "value1"));
  assert(htable_insert(ht, "key2", "value2"));
  assert(htable_insert(ht, "key3", "value3"));

  // Search for existing and non-existing keys
  assert(strcmp(htable_search(ht, "key1"), "value1") == 0);
  assert(strcmp(htable_search(ht, "key4"), NULL_KEY) == 0);

  // Clean up
  htable_destroy(ht);
}

static void test_insert_overload() {
  // Create a new hash table with initial size 10
  htable_t *ht = htable_create(10);
  assert(ht != NULL);

  // Insert key-value pairs with duplicate keys
  assert(htable_insert(ht, "key1", "value1"));
  assert(htable_insert(ht, "key1", "value1")); // Duplicate key
  assert(htable_insert(ht, "key2", "value2"));

  // Search for existing and non-existing keys
  assert(strcmp(htable_search(ht, "key1"), "value1") == 0);
  assert(strcmp(htable_search(ht, "key3"), NULL_KEY) == 0);

  // Clean up
  htable_destroy(ht);
}

static void test_delete() {
  // Create a new hash table with initial size 10
  htable_t *ht = htable_create(10);
  assert(ht != NULL);

  // Insert key-value pairs
  assert(htable_insert(ht, "key1", "value1"));
  assert(htable_insert(ht, "key2", "value2"));

  // Delete a key
  assert(htable_delete(ht, "key1"));

  // Search for existing and non-existing keys
  assert(strcmp(htable_search(ht, "key1"), NULL_KEY) == 0);
  assert(strcmp(htable_search(ht, "key2"), "value2") == 0);

  // Clean up
  htable_destroy(ht);
}

static void test_collision() {
  // Create a new hash table with initial size 10
  htable_t *ht = htable_create(10);
  assert(ht != NULL);

  // Insert key-value pairs with colliding keys
  assert(htable_insert(ht, "key1", "value1"));
  assert(htable_insert(ht, "key2", "value2"));
  assert(htable_insert(ht, "key1", "new_value1")); // Colliding key

  // Search for existing and non-existing keys
  assert(strcmp(htable_search(ht, "key1"), "new_value1") == 0);
  assert(strcmp(htable_search(ht, "key3"), NULL_KEY) == 0);

  // Clean up
  htable_destroy(ht);
}

int main() {
  // Run tests
  test_insert_and_search();
  test_insert_overload();
  test_delete();
  test_collision();

  printf("All tests passed!\n");
  return 0;
}