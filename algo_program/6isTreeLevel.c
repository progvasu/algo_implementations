#include<stdio.h>
#include<math.h>

int main()  {
    int level[] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3};
    int level_len = 8;

    // height of the given possible tree
    int max_level = level[level_len];

    int i, j = level_len, max_nodes, min_nodes, curr_nodes, child_nodes = 0, isTree = 1;

    // looping for each level/height
    for (i = max_level ; i >= 0 ; i--)    {
        // calculating nodes at current level
        for (curr_nodes = 0 ; j >= 0 && level[j] == i; j--)  curr_nodes++;

        // for this level we calculate the max possible nodes and min possible nodes
        // max nodes are dependent on the height
        max_nodes = pow(2, i);
        // min nodes are dependent on the number of children
        min_nodes = child_nodes / 2 + child_nodes % 2;

        if (curr_nodes < min_nodes || curr_nodes > max_nodes)   {
            isTree = 0;
            break;
        }

        child_nodes = curr_nodes;
    }

    if (isTree) printf("Tree is possible\n");
    else    printf("Tree is not possible\n");

    return 0;
}
