
//1. COVID19 virus is disaster of this year 2020. Professor Roopali asked her students to store the
//following data in BST using Deaths as seed value. Traverse the constructed tree and find
//countries which are having Minimum and maximum deaths.
//    Country ID  Country_Name    Confirmed   Recovered   Deaths
//    591         India           4,421       326         114
//    680         United States   367776      19858       10980
//    521         Spain           140510      43208       13798
//    501         Italy           132547      22837       16523
//    601         China           82883       77678       3339
//    702         Brazil          16238       127         823



#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int countryid;
    char countryname[50];
    int confirmed;
    int recovered;
    int deaths;
}Country;

struct N
{
    struct N *left;
    Country data;
    struct N *right;
};

typedef struct N Node;

Node *getNode()
{
    return(malloc(sizeof(Node)));
}

void readCountryInfo(Country *p)
{
    printf("\nEntry country info [id,name,confirmed,recvd,deaths]\n");
    scanf("%d%s%d%d%d",&p->countryid,p->countryname,&p->confirmed,&p->recovered,&p->deaths);
}

void displayCountryInfo(Country p)
{
    printf("\nID : %d  Name : %s  Confirmed : %d  Recovered : %d   Deaths : %d",p.countryid,p.countryname,p.confirmed,p.recovered,p.deaths);
}

Node *insertNode(Node *cur,Country country)
{
    if(cur == NULL)
    {
        cur = getNode();
        cur->data = country;
        cur->left = cur->right = NULL;
    }
    else if(country.deaths < cur->data.deaths)
        cur->left = insertNode(cur->left,country);
    else
        cur->right = insertNode(cur->right,country);
    return cur;
}

void inorder(Node *cur)
{
    if(cur == NULL)
        return;
    inorder(cur->left);
    displayCountryInfo(cur->data);
    inorder(cur->right);
}

void displayMinimumDeaths(Node *root)
{
    Node *cur=root;
    if(cur == NULL)
    {
        printf("\nNo datas available");
        return;
    }

    while(cur->left != NULL)
    {
        cur = cur->left;
    }
    displayCountryInfo(cur->data);

}

void displayMaximumDeaths(Node *root)
{
    Node *cur=root;
    if(cur == NULL)
    {
        printf("\nNo datas available");
        return;
    }

    while(cur->right != NULL)
    {
        cur = cur->right;
    }
    displayCountryInfo(cur->data);

}

int main()
{
    Node *root=NULL;
    Country country;
    int ch;
    do
    {
        printf("\n1->Insert country detail  2->Display country details  3->Minimum death country   4->Maximum death country   5->Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: readCountryInfo(&country);
                    root = insertNode(root,country);
                    break;
            case 2: printf("\nCountry detail : ");
                    inorder(root);
                    break;
            case 3: displayMinimumDeaths(root);
                    break;
            case 4: displayMaximumDeaths(root);
                    break;
            case 5: break;
        }
    }while(ch!=5);
    return 0;
}


