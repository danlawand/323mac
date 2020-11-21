
void stDelete(int key) {
  Link *s, p, q;

  int k, levels;

  p = first[lgN-1];

  for (k = lgN-1; k >= 0; k--) {
    p = rank(key, p, k);
    q = p->next[k];
    if (q != NULL && compare(key, q->key) == 0) {
      p->next[k] = q->next[k];
      q = NULL;
    }
  }

  levels = randLevel();

  if (levels == lgN - 1) {
    first->next[lgN-1] = NULL;
    lgN--;
  }
  n--;
}

skiplist *list

void skiplist_delete(int key)
{
    int i;
    Link update[SKIPLIST_MAX_LEVEL + 1];
    Link x = first;

    for (i = lgN; i >= 1; i--) {
        while (x->next[i]->key < key)
            x = x->next[i];
        update[i] = x;
    }

    x = x->next[1];
    if (x->key == key) {
        for (i = 1; i <= lgN; i++) {
            if (update[i]->next[i] != x)
                break;
            update[i]->next[1] = x->next[i];
        }
        skiplist_node_free(x);

        while (list->level > 1 && list->header->forward[list->level] == list->header)
            list->level--;
    }
}
