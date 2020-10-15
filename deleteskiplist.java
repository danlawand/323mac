private class Node    {
  ITEM item;
  Node[] next;
  int sz;
  Node(ITEM x, int k)
  {
    item = x;
    sz = k;
    next = new Node[sz]; /*sz = size = levels*/ 
  }
}
private static final int L = 50;
private Node head;
private int N, lgN;
ST(int maxN)    {
  N = 0; lgN = 0;
  head = new Node(null, L);
}

private void removeR(Node t, KEY v, int k)
{
  Node x = t.next[k];
  if (!less(x.item.key(), v))
  {
    if (equals(v, x.item.key()))
    { t.next[k] = x.next[k]; }
    if (k == 0) return;
    removeR(t, v, k-1); return;
  }
  removeR(t.next[k], v, k);
}
void remove(ITEM x)
{ removeR(head, x.key(), lgN);
  N--;
}
