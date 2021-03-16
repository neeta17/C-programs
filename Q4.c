//4. Prof. Sharmila asked her research scholar Shravan to list the size of his research files in an
//   array. For efficient access Shravan constructed the BST by taking sizes of files in the array. Now
//   professor asked him to find the followings:
//      (i) Height of the BST.
//      (ii) Number of files their size is less than root node of BST


#include <stdio.h>
#include <stdlib.h>

int BST[100];

void initializeBST()
{
    int i;
    for(i=0;i<100;i++)
        BST[i] = -1;
}

void insertNode(int cur,int size)
{
    if(BST[cur] == -1)
    {
        BST[cur] = size;
    }
    else if(size < BST[cur])
        insertNode(cur*2,size);
    else
        insertNode(cur*2+1,size);
}

void inorder(int cur)
{
    if(BST[cur] == -1)
        return;
    inorder(cur*2);
    printf("  %d ",BST[cur]);
    inorder(cur*2+1);
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

    int N,i,size,root;

    root = 1;
    initializeBST();

    printf("\nEnter number of files : ");
    scanf("%d",&N);

    printf("\nEnter %d file size : ",N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&size);
        insertNode(root,size);
    }

    printf("\nInorder : ");
    inorder(root);

    printf("\nHeight of BST : %d",heightBST(root));
    return 0;
}


