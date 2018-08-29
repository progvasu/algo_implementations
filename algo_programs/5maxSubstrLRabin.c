// only displays the first substring of length l_len which occurs max number of times.
// to see other strings we need to modify the printMaxRepeatedString function

#include<stdio.h>
#include<stdlib.h>

// hash table node
struct node {
    int start_index;
    int count;
    struct node *next;
};

// having the string and length to be matched as GLOBAL
char *str = "vasubskfkvasublfklafklnklnkjvasubegvasubhqowtvasubuipq;oirgehnbvjvasubkdsvbkasjvgb;qoirehgvasuboiqehgovncbxbcmnvbjhfhvasubsgdfyuergfjsbhvcvbsghfyuwgefouywvasubgefbjreqovbieiuquvasub";;
int l_len = 5;

void printMaxRepeatedString(struct node **htable, int htable_len)   {
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

    char sub_str[l_len + 1];
    for(i = 0 ; i < l_len ; i++)
        sub_str[i] = str[start_index + i];
    sub_str[i] = '\0';

    printf("String %s is repeated max %d times\n", sub_str, max);
}

int matchIndexLenL(int index1, int index2)  {
    int i = 0;
    for (i ; i < l_len ; i++)   {
        if (str[index1 + i] != str[index2 + i])
            return 0;
    }
    return 1;
}

void insertHash(struct node **htable, int hash_value, int start_index)   {
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
            if (matchIndexLenL(start_index, cnode->start_index)) {
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

int main()  {
    int i = 0, str_len = 0;
    char curr_char;

    // calculating input string length
    while (str[i++] != '\0')
        str_len++;

    // hash table variables
    int htable_len = str_len / 10, hash_value, t = 2;
    struct node *htable[htable_len];

    // initializing hash table elements to NULL
    for (i = 0 ; i < htable_len ; i++)  htable[i] = NULL;

    // we need to calculate the start hash value before we can loop
    hash_value = str[0];
    for(i = 1 ; i < l_len; i++) {
        hash_value = (2 * hash_value + str[i]) % htable_len;
        t = 2 * t;
    }

    // inserting this initial value into the hash table
    insertHash(htable, hash_value, 0);

    // calculating hash for the remaining string
    for(i = l_len ; i < str_len ; i++)  {
        hash_value = (2 * hash_value + str[i] - t * str[i - l_len]) % htable_len;
        if (hash_value < 0)
                hash_value += htable_len;
        insertHash(htable, hash_value, i - l_len + 1);
    }

    // print out the entire hash table
    printMaxRepeatedString(htable, htable_len);

    return 0;
}
