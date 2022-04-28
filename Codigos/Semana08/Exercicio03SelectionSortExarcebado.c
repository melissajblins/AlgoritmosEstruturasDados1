typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

LinkedNode *selection_sort(LinkedNode *inicio, int *trocas, int *comparacoes) {
    LinkedNode *a, *b, *c, *d, *r;
    a = b = inicio;

    while (b->next){
        c = d = b->next;
        while(d){
            if(b->data > d->data){
                *comparacoes = *comparacoes + 1;
                if(b->next == d){
                    if(b == inicio){
                        b->next = d->next;
                        d->next = b;
                        r = b;
                        b = d;
                        d = r;
                        c = d;
                        inicio = b;
                        d = d->next;
                    }
                    else {
                        b->next = d->next;
                        d->next = b;
                        a->next = d;
                        r = b;
                        b = d;
                        d = r;
                        c = d;
                        d = d->next;
                    }
                } else {
                    if (b == inicio){
                        r = b->next;
                        b->next = d->next;
                        d->next = r;
                        c->next = b;
                        r = b;
                        b = d;
                        d = r;
                        c = d;
                        d = d->next;
                        inicio = b;
                    } else {
                        r = b->next;
                        b->next = d->next;
                        d->next = r;
                        c->next = b;
                        a->next = d;

                        r = b;
                        b = d;
                        d = r;
                        c = d;

                        d = d->next;
                    }
                }
            } else {
                c = d;
                d = d->next;
            }
        }
        a = b;
        b = b->next;
    }
    return inicio;
}

