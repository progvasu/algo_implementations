// we need to find the max length of the substring which repeats at least k times
#include<stdio.h>
#include<stdlib.h>

// hash table node
struct node {
    int start_index;
    int count;
    struct node *next;
};

// having the string and length to be matched as GLOBAL
char *str = "abcdefgasdfghjklioyugklakdg;akguietKJvba;uidgpiruegskldvbabcdefgaiogh;vbkfeorighvklbzdf;ogqpiruetlifgudbvabcdefga;sjdknbbarnebg;oriehjkf.dab;kajdfb;aiobrbabcdefgxm,nblskjdfgieuryabcdefgznvbskdjfghoeuwfgabcdefgzmnvblksdjgfpwiueabcdefgzmnvbjfgdaoeuygtabcdefgwruieoghfjkdbvn,abcdefgeioqutpiuerytabcdefgwuirtpypity";
int k_times = 10, str_len;

int find_length()   {
    int len = 0;
    while (str[len++] != '\0')  {}
    return len;
}

int getMaxRepeatedStringCount(struct node **htable, int htable_len)   {
    int i, max = 0, start_index = 0;
    struct node *cnode;

    for (i = 0 ; i < htable_len ; i++)  {
        cnode = htable[i];
        while(cnode != NULL)    {
            if (max < cnode->count) {
                max = cnode->count;
                start_index = cnode->start_index;
            }
            cnode = cnode->next;
        }
    }

    return max;
}

int matchIndexLenL(int index1, int index2, int mid_len)  {
    int i = 0;
    for (i ; i < mid_len ; i++)   {
        if (str[index1 + i] != str[index2 + i])
            return 0;
    }
    return 1;
}

void insertHash(struct node **htable, int hash_value, int start_index, int mid_len)   {
    // check to see if the node already exist
    if (htable[hash_value] == NULL) {
        // not then insert it
        struct node *temp = malloc(sizeof(struct node));
        temp->start_index = start_index;
        temp->count = 1;
        temp->next = NULL;
        htable[hash_value] = temp;
    }
    else    {
        // node exist at that point
        // we need to search th original string in order to determine
        // whether to increment the count or to insert a new node
        struct node *cnode = htable[hash_value];
        while (cnode != NULL)   {
            if (matchIndexLenL(start_index, cnode->start_index, mid_len)) {
                // both sub strings hashed to the same value matches
                cnode->count++;
                return;
            }
            cnode = cnode->next;
        }
        // if control reaches here it means the new index didn't match any value
        // insert a new node
        struct node *temp = malloc(sizeof(struct node));
        temp->start_index = start_index;
        temp->count = 1;
        temp->next = htable[hash_value];
        htable[hash_value] = temp;
    }
}

int findMaxRepeatCount(int mid_len) {
    // initialize hash table
    // hash table variables
    int htable_len = str_len / 10, hash_value, t = 2, i;
    struct node *htable[htable_len];

    // initializing hash table elements to NULL
    for (i = 0 ; i < htable_len ; i++)  htable[i] = NULL;

    // we need to calculate the start hash value before we can loop
    hash_value = str[0];
    for(i = 1 ; i < mid_len; i++) {
        hash_value = (2 * hash_value + str[i]) % htable_len;
        t = 2 * t;
    }

    // inserting this initial value into the hash table
    insertHash(htable, hash_value, 0, mid_len);

    // calculating hash for the remaining string
    for(i = mid_len ; i < str_len ; i++)  {
        hash_value = (2 * hash_value + str[i] - t * str[i - mid_len]) % htable_len;
        if (hash_value < 0)
                hash_value += htable_len;
        insertHash(htable, hash_value, i - mid_len + 1, mid_len);
    }

    // print out the entire hash table
    return getMaxRepeatedStringCount(htable, htable_len);
}

int main()  {
    str_len = find_length();

    int min_len = 1;
    int max_len = str_len - k_times;
    int mid_len;

    // variables for storing max times a string of mid_len is repeated
    int mid_len_res;

    while(min_len <= max_len) {
        mid_len = (min_len + max_len) / 2;
        printf("min_len = %d, max_len = %d, mid = %d\n", min_len, max_len, mid_len);
        mid_len_res = findMaxRepeatCount(mid_len);

        if (mid_len_res >= k_times)
            min_len = mid_len + 1;
        else
            max_len = mid_len - 1;
    }

    printf("Length of the substring which repeats atleast %d number of times: %d\n", k_times, mid_len);

    return 0;
}
