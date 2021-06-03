#ifndef LL_H_INCLUDED
#define LL_H_INCLUDED

struct nodell
{
    int *data;
    struct nodell *next;
};

struct nodell *insertll(struct nodell*,int*);
struct nodell *search(struct nodell*,int*);

#endif // LL_H_INCLUDED
