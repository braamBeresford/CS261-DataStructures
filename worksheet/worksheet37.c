#include <stdlib.h>
#include <assert.h>
#define TYPE double

struct openHashTable
{
    TYPE **table;
    int tablesize;
    int count;
};

void openHashTableAdd(struct openHashTable *ht, TYPE newValue);
void _resizeOpenHashTable(struct openHashTable *ht);

void initOpenHashTable(struct openHashTable *ht, int size)
{
    int i;
    assert(size > 0);
    ht->table = (TYPE **)malloc(size * sizeof(TYPE *));
    assert(ht->table != 0);
    for (i = 0; i < size; i++)
        ht->table[i] = 0; /* initialize empty */
    ht->tablesize = size;
    ht->count = 0;
}

int openHashTableSize(struct openHashTable *ht) { return ht->count; }

void openHashTableAdd(struct openHashTable *ht, TYPE newValue)
{
    int idx;

    /* Make sure we have space and under the load factor threshold*/
    if ((ht->count / (double)ht->tablesize) > 0.75)
        _resizeOpenHashTable(ht);
    ht->count++;

    idx = HASH(newValue) % ht->tablesize;

    /* To be safe, use only positive arithmetic.  % may behave very differently on diff	 
      implementations or diff languages .  However, you can do the following to deal with a 
      negative result from HASH  */

    if (idx < 0)
        idx += ht->tablesize;

    TYPE *newValPtr = malloc(sizeof(TYPE));
    assert(newValPtr);
    *newValPtr = newValue;

    for (int i = 0; i < ht->tablesize; i++)
    {
        if (ht->table[idx] == NULL)
        {
            ht->table[idx] = newValPtr;
            ht->count++;
            return;
        }
        idx++;
        idx = idx < (ht->tablesize - 1) ? idx + 1 : 0;
    }
}

int openHashTableBagContains(struct openHashTable *ht, TYPE newValue)
{

    int idx;

    idx = HASH(newValue) % ht->tablesize;
    if (idx < 0)
        idx += ht->tablesize;
    
    for (int i = 0; i < ht->tablesize; i++)
    {
        if (ht->table[idx] != NULL && *(ht->table[idx]) == newValue)
        {
            return 1;
        }
        idx++;
        idx = idx < (ht->tablesize - 1) ? idx + 1 : 0;
    }

    return 0;
}

//To get capacity that gives load factor of 0.5 divide the count by the current load factor.
void _resizeOpenHashTable(struct openHashTable *ht)
{

    int newTableSize = ht->count / (ht->count / ((double)ht->tablesize) > 0.75);

    TYPE **oldTable = ht->table;
    int oldTableSize = ht->tablesize;

    ht->table = malloc(sizeof(newTableSize * sizeof(TYPE *)));
    assert(ht->table);
    ht->tablesize = newTableSize;

    for (int i = 0; i < oldTableSize; i++)
    {
        if (oldTable[i] != NULL)
        {
            openHashTableAdd(ht, *(oldTable[i]));
        }
    }

    free(oldTable);
    oldTable = NULL;
}

int main(){
    return 0;
}