#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 100005

int n, k, q;
int t, x, y;

typedef struct Node {
  int key;
  int value;
  struct Node *next;
} Node;

typedef struct {
  Node *buckets[HASH_SIZE];
} HashMap;

Node *createNode(int key, int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->key = key;
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void initHashMap(HashMap *map) {
  for (int i = 0; i < HASH_SIZE; ++i) {
    map->buckets[i] = NULL;
  }
}

int hashFunction(int key) { return key % HASH_SIZE; }

int get(HashMap *map, int key) {
  int index = hashFunction(key);
  Node *currentNode = map->buckets[index];

  while (currentNode != NULL) {
    if (currentNode->key == key) {
      return currentNode->value;
    }
    currentNode = currentNode->next;
  }

  if (key == 0 || key == n + 1) {
    return 1;
  }

  return key <= k ? 1 : 0;
}

void put(HashMap *map, int key, int value) {
  int index = hashFunction(key);
  Node *newNode = createNode(key, value);

  newNode->next = map->buckets[index];
  map->buckets[index] = newNode;
}

int main() {
  scanf("%d", &t);
  for (int qwq = 1; qwq <= t; ++qwq) {
    printf("Case %d:\n", qwq);

    HashMap map;
    initHashMap(&map);

    scanf("%d%d%d", &n, &k, &q);
    int ans = 1;

    while (q--) {
      scanf("%d%d", &x, &y);
      int cx = get(&map, x - 1) + get(&map, x + 1);
      if (cx == 0) {
        --ans;
      } else if (cx == 2) {
        ++ans;
      }
      put(&map, x, 0);

      int cnt = get(&map, y - 1) + get(&map, y + 1);
      if (cnt == 0) {
        ++ans;
      } else if (cnt == 2) {
        --ans;
      }
      put(&map, y, 1);

      printf("%d\n", ans);
    }
  }

  return 0;
}
