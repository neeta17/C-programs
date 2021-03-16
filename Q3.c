3. Rating of the product by Amazon is considered depending on the sales. The rating is as follows:
//       GOOD: if sales is greater than X sales.
//       AVERAGE: if sales is equal to X
//       BAD: if sales is less than X
//Sales and X are integers. Save this data in BST with X as root of the tree. Help Amazon by
//counting all three ratings.


#include <stdio.h>
#include <stdlib.h>

struct N
{
    struct N *left;
    int sales;
    struct N *right;
};

typedef struct N Node;

Node *getNode()
{
    return(malloc(sizeof(Node)));
}

Node *insertNode(Node *cur,int sales)
{
    if(cur == NULL)
    {
        cur = getNode();
        cur->sales = sales;
        cur->left = cur->right = NULL;
    }
    else if(sales < cur->sales)
        cur->left = insertNode(cur->left,sales);
    else
        cur->right = insertNode(cur->right,sales);
    return cur;
}

void inorder(Node *cur)
{
    if(cur == NULL)
        return;
    inorder(cur->left);
    printf("  %d ",cur->sales);
    inorder(cur->right);
}

int bad(Node *cur)
{
    int cnt;

    if(cur == NULL)
        return 0;

    cnt = 1 + bad(cur->left) + bad(cur->right);
    return cnt;
}

int average(Node *cur,int X)
{
    int cnt=0;

    if(cur == NULL)
        return 0;

    if(cur->sales == X)
        cnt = 1;

    cnt = cnt + average(cur->left,X) + average(cur->right,X);
    return cnt;
}

int good(Node *cur,int X)
{
    int cnt=0;

    if(cur == NULL)
        return 0;

    if(cur->sales != X)
        cnt = 1;

    cnt = cnt + good(cur->left,X) + good(cur->right,X);
    return cnt;
}


int main()
{
    Node *root=NULL;
    int X,cnt,N,i,sales;
    printf("\nEnter value of X : ");
    scanf("%d",&X);
    root = insertNode(root,X);

    printf("\nEnter number of records : ");
    scanf("%d",&N);

    printf("\nEnter %d sales figure : ",N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&sales);
        root = insertNode(root,sales);
    }

    cnt = good(root->right,X);
    printf("\nGood : %d",cnt);

    cnt = average(root->right,X);
    printf("\nAverage : %d",cnt);

    cnt = bad(root->left);
    printf("\nBad : %d",cnt);
    return 0;
}

