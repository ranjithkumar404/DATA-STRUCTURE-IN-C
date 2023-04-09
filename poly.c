#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
struct poly
{
    int cf, px, py, pz;
    int flag;
    struct poly *next;
};
typedef struct poly node;
node *getnode()
{
    node *nn;
    nn = (node *)malloc(sizeof(node));
    if (nn == NULL)
    {
        printf("Insufficient memory\n");
        exit(0);
    }
    return nn;
}
void display(node *head)
{
    node *p;
    if (head->next == head)
    {
        printf("Polynomial does not exist\n");
        return;
    }
    p = head->next;
    while (p != head)
    {
        printf("%dx^%dy^%dz^%d", p->cf, p->px, p->py, p->pz);
        if (p->next != head)
            printf(" + ");
        p = p->next;
    }
}
node *insert_rear(int cf, int x, int y, int z, node *head)
{
    node *p, *v;
    p = getnode();
    p->cf = cf;
    p->px = x;
    p->py = y;
    p->pz = z;
    v = head->next;
    while (v->next != head)
    {
        v = v->next;
    }
    v->next = p;
    p->next = head;
    return head;
}
node *read_poly(node *head)
{
    int px, py, pz, cf, ch;
    do
    {
        printf("Enter coeff: ");
        scanf("%d", &cf);
        printf("Enter powers of x,y,z\n ");
        scanf("%d%d%d", &px, &py, &pz);
        head = insert_rear(cf, px, py, pz, head);
        printf("If your wish to continue press 1 otherwise 0\n");
        scanf("%d", &ch);
    } while (ch != 0);
    return head;
}
node *add_poly(node *h1, node *h2, node *h3)
{
    node *p1, *p2;
    int x1, x2, y1, y2, z1, z2, cf1, cf2, cf;
    p1 = h1->next;
    while (p1 != h1)
    {
        x1 = p1->px;
        y1 = p1->py;
        z1 = p1->pz;
        cf1 = p1->cf;
        p2 = h2->next;
        while (p2 != h2)
        {
            x2 = p2->px;
            y2 = p2->py;
            z2 = p2->pz;
            cf2 = p2->cf;
            if (x1 == x2 && y1 == y2 && z1 == z2)
                break;
            p2 = p2->next;
        }
        if (p2 != h2)
        {
            cf = cf1 + cf2;
            p2->flag = 1;
            if (cf != 0)
                h3 = insert_rear(cf, x1, y1, z1, h3);
        }
        else
            h3 = insert_rear(cf1, x1, y1, z1, h3);
        p1 = p1->next;
    }
    p2 = h2->next;
    while (p2 != h2)
    {
        if (p2->flag == 0)
            h3 = insert_rear(p2->cf, p2->px, p2->py, p2->pz, h3);
        p2 = p2->next;
    }
    return h3;
}
void evaluate(node *head)
{
    node *p;
    int x, y, z;
    int result = 0;
    p = head->next;
    printf("\nEnter x,y,z terms to evaluate:\n");
    scanf("%d%d%d", &x, &y, &z);
    while (p != head)
    {
        result = result + (p->cf * pow(x, p->px) * pow(y, p->py) * pow(z, p->pz));
        p = p->next;
    }
    printf("Polynomial result is: %d", result);
}
void main()
{
    node *h1, *h2, *h3;
    int ch;
    h1 = getnode();
    h2 = getnode();
    h3 = getnode();
    h1->next = h1;
    h2->next = h2;
    h3->next = h3;
    while (1)
    {
        printf("\n\n1.Evaluate polynomial\n2.Add two polynomials\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            h1->next = h1;
            printf("\nEnter polynomial to evaluate:\n");
            h1 = read_poly(h1);
            printf("The polynomial is :");
            display(h1);
            valuate(h1);
            break;
        case 2:
            h1->next = h1;
            printf("\nEnter the first polynomial:\n");
            h1 = read_poly(h1);
            printf("\nEnter the second polynomial:\n");
            h2 = read_poly(h2);
            h3 = add_poly(h1, h2, h3);
            printf("\nFirst polynomial is: ");
            display(h1);
            printf("\nSecond polynomial is: ");
            display(h2);
            printf("\nThe sum of 2 polynomials is: \n");
            display(h3);
        case 3:
            exit(0);
        default:
            printf("\nInvalid entry");
            break;
        }
    }
}
