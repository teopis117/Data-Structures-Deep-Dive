#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int value;
};

struct node* array;
int capacity = 10;
int size = 0;

int hashFunction(int key) {
    return (key % capacity);
}

void insert(int key, int value) {
    int index = hashFunction(key);
    while (array[index].value != 0) {
        if (array[index].key == key) {
            printf("\n key (%d) already present, updating its value \n ", key);
            array[index].value = value;
            size++;
            return;
        }
        index = (index + 1) % capacity;
    }
    array[index].key = key;
    array[index].value = value;
    size++;
}

void remove_element(int key) {
    int index = hashFunction(key);
    while (array[index].key != 0) {
        if (array[index].key == key) {
            array[index].key = 0;
            array[index].value = 0;
            size--;
            printf("\n Key (%d) has been removed \n", key);
            return;
        }
        index = (index + 1) % capacity;
    }
    printf("\n Key does not exist \n");
}

void display() {
   int i = 0;
   for (i = 0; i < capacity; i++) {
      if (array[i].value == 0) {
         printf("\n array[%d]: / ", i);
      }
      else {
         printf("\n key: %d array[%d]: %d \t", array[i].key, i, array[i].value);
      }
   }
}

int size_of_hashtable() {
    return size;
}

int main() {
    array = (struct node*) malloc(capacity * sizeof(struct node));
    insert(10, 20);
    insert(15, 25);
    insert(20, 30);
    display();
    remove_element(20);
    display();
    return 0;
}
