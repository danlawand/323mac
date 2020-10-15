typedef struct node *Link;
struct node {
  Key key;
  Value val;
  Link *next;
}

Link newNode(Key key, Value val, int levels) {
  Link p = mallocSafe(sizeof(*p));
  int k;
  p->key = key;
  p->val = val;
  p->next = mallocSafe(levels * sizeof(Link));
  for (k = 0; k < levels; k++) p->next[k] = NULL;/* ou sentinela */
  return p;
}
