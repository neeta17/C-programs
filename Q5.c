//  5.Imagine that you work for a database company, which has a popular system for maintaining
//  sorted sets. After a negative review in an influential technology website, the company has
//  decided it needs to convert all of its indexing software from using sorted arrays to an indexing
//  strategy based on using binary search trees, so as to be able to support insertions and deletions
//  more efficiently. Your job is to write a program that can take a sorted array, A, of n elements,
//  and construct a binary search tree, T





#include <stdio.h>
#include <stdlib.h>

int BST[100];

void initializeBST()
{
    int i;
    for(i=0;i<100;i++)
        BST[i] = -1;
}

void insertNode(int cur,int data)
{
    if(BST[cur] == -1)
    {
        BST[cur] = data;
    }
    else if(data < BST[cur])
        insertNode(cur*2,data);
    else
        insertNode(cur*2+1,data);
}

void storeIntoBST(int sortedarray[],int l, int r)
{
    int m;
    if(l>r)
        return;
    m = (l+r)/2;
    insertNode(1,sortedarray[m]);
    storeIntoBST(sortedarray,l,m-1);
    storeIntoBST(sortedarray,m+1,r);
}

void inorder(int cur)
{
    if(BST[cur] == -1)
        return;
    inorder(cur*2);
    printf("  %d ",BST[cur]);
    inorder(cur*2+1);
}

void preorder(int cur)
{
    if(BST[cur] == -1)
        return;
    printf("  %d ",BST[cur]);
    preorder(cur*2);
    preorder(cur*2+1);
}


int max(int a,int b)
{
    int m;
    m = a>b? a: b;
    return m;
}

int heightBST(int cur)
{
    int h=0,ld,rd;

    if(BST[cur] == -1)
        return -1;
    ld = heightBST(cur*2);
    rd = heightBST(cur*2+1);
    h =max(ld,rd)+1;
    return h;
}


int main()
{

    int N,i,root;
    int sortedarray[50];


    root = 1;
    initializeBST();

    printf("\nEnter number of elements : ");
    scanf("%d",&N);

    printf("\nEnter %d file data : ",N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&sortedarray[i]);
    }

    storeIntoBST(sortedarray,0,N-1);

    printf("\nInorder : ");
    inorder(root);

    printf("\nPreorder : ");
    preorder(root);

    printf("\nHeight of tree : %d",heightBST(1));

    return 0;
}




