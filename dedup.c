#include <stdio.h>
#include <stdlib.h>
#define MASK(x) (x?(~((1u<<(32u-x))-1u)):0)

unsigned current;
struct Trie {
	char flag;
	struct Trie *child[2];
} *root=NULL;

char merge(struct Trie *p) {
    // this node is marked
    if(p->flag) return 1;
    // missing either child
    if(!p->child[0]||!p->child[1]) return 0;
    // true when both true;
    return (p->flag = merge(p->child[0]) && merge(p->child[1]));
}

void print(struct Trie *p, unsigned depth) {
    // print whole subnet
    if(p->flag) {
        unsigned ip = current & MASK(depth);
        printf("%u.%u.%u.%u/%u\n", ip>>24&0xff, ip>>16&0xff, ip>>8&0xff, ip&0xff, depth);
        return;
    }
    // dig deeper
    if(p->child[0]) {
        current &= ~(1<<(31-depth));
        print(p->child[0], depth+1);
    }
    if(p->child[1]) {
        current |= 1<<(31-depth);
        print(p->child[1], depth+1);
    }
}

int main() {
    unsigned ip1, ip2, ip3, ip4, prefix_len;
    while(scanf("%u.%u.%u.%u/%u", &ip1, &ip2, &ip3, &ip4, &prefix_len)==5) {
        // convert to binary
        unsigned ip = (ip1<<24) | (ip2<<16) | (ip3<<8) | (ip4);
        unsigned mask = MASK(prefix_len);
        // build trie
        struct Trie **p = &root;
        while(mask) {
            // walk
            if((*p)==NULL) (*p) = calloc(1, sizeof(struct Trie));
            p = &((*p)->child[ip>>31]);
            // next bit
            ip <<= 1;
            mask <<= 1;
        }
        // mark node
        if((*p)==NULL) (*p) = calloc(1, sizeof(struct Trie));
        (*p)->flag = 1;
    }
    if(root) {
        // merge trie
        merge(root);
        // print trie
        print(root, 0);
    }
    return 0;
}
