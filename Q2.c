
//2. Consider the integer number X which is divisible by 9 and make that as the root of the BST. Ask
//    the user enter the number and check whether it is multiple of 9 and insert in the BST. Count total
//    number nodes in the tree.



struct N
{
    struct N *left;
    int X;
    struct N *right;
};

typedef struct N Node;

Node *getNode()
{
    return(malloc(sizeof(Node)));
}

Node *insertNode(Node *cur,int X)
{
    if(cur == NULL)
    {
        cur = getNode();
        cur->X = X;
        cur->left = cur->right = NULL;
    }
    else if(X < cur->X)
        cur->left = insertNode(cur->left,X);
    else
        cur->right = insertNode(cur->right,X);
    return cur;
}

void inorder(Node *cur)
{
    if(cur == NULL)
        return;
    inorder(cur->left);
    printf("  %d ",cur->X);
    inorder(cur->right);
}

int countNodes(Node *cur)
{
    int cnt;

    if(cur == NULL)
        return 0;

    cnt = 1 + countNodes(cur->left) + countNodes(cur->right);
    return cnt;
}

int main()
{
    Node *root=NULL;
    int X,cnt;
    int ch;
    do
    {
        printf("\n1->Insert Value 2->Display Values  3->Count nodes  4->Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter number that is divisible by 9");
                    scanf("%d",&X);
                    if(X%9 != 0)
                    {
                        printf("\nValue entered is not divisible by 9, cannot be inserted");
                        break;
                    }
                    root = insertNode(root,X);
                    break;
            case 2: printf("\nValues in BST : ");
                    inorder(root);
                    break;
            case 3: cnt = countNodes(root);
                    printf("\nNo of Values in BST : %d",cnt);
                    break;
            case 4: break;
        }
    }while(ch!=4);
    return 0;
}

