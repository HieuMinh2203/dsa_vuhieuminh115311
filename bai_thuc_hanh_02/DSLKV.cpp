#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char hoten[30];
    int masv;
    float d1, d2, d3;
} Data;
typedef struct tagNode
{
    Data infor;
    struct tagNode *link;
} Node;
typedef struct
{
    Node *pHead;
    Node *pTail;
    int spt;
} LList;
/////////////////////////////////////
void initList(LList *L)
{
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}
/////////////////////////////////////
int emptyList(LList L)
{
    return (L.spt == 0);
}
/////////////////////////////////////
void insert_Head(LList *L, Data x)
{
    Node *pp;
    pp = (Node *)malloc(sizeof(Node));
    pp->infor = x;
    if (emptyList(*L))
    {
        L->pHead = pp;
        L->pTail = pp;
        pp->link = pp;
    }
    else
    {
        pp->link = L->pHead;
        L->pHead = pp;
        L->pTail->link = L->pHead;
    }
    L->spt++;
}
///////////////////////////////////////
void insert_Tail(LList *L, Data x)
{
    Node *pp;
    pp = (Node *)malloc(sizeof(Node));
    pp->infor = x;
    if (emptyList(*L))
    {
        L->pHead = L->pTail = pp;
        pp->link = pp;
    }
    else
    {
        L->pTail->link = pp;
        L->pTail = pp;
        L->pTail->link = L->pHead;
    }
    L->spt++;
}
///////////////////////////////////////
void del_Head(LList *L)
{
    if (emptyList(*L))
    {
        printf("Danh sach rong\n");
        return;
    }
    else
    {
        Node *pp;
        if (L->spt == 1)
        {
            L->pHead = L->pTail = NULL;
        }
        else
        {
            pp = L->pHead;
            L->pHead = pp->link;
            L->pTail->link = L->pHead;
        }
        free(pp);
        L->spt--;
    }
}
///////////////////////////////////////
void del_After(LList *L, Node *q)
{
    Node *pp;
    if (q == NULL)
    {
        printf("Sinh vien nay khong ton tai\n");
    }
    else
    {
        pp = q->link;
        if (L->pTail == q->link)
            L->pTail = q;
        q->link = pp->link;
        free(pp);
        L->pTail->link = L->pHead;
        L->spt--;
    }
}
///////////////////////////////////////
void del_MaSV(LList *L, int ma)
{
    Node *pp = L->pHead;
    Node *q;
    bool da_tim_thay = false;
    do
    {
        q = pp;
        pp = pp->link;
        if (pp->infor.masv == ma)
            da_tim_thay = true;
    } while (pp != L->pHead && (pp->infor.masv != ma));
    if (pp == L->pHead && da_tim_thay == false)
    {
        printf("Khong tim thay sinh vien co ma %d", ma);
        return;
    }
    else
    {
        if (pp == L->pHead && da_tim_thay == true)
        {
            del_Head(L);
            printf("Da xoa thanh cong sinh vien co ma %d (del_Head)", ma);
        }
        else
        {
            del_After(L, q);
            printf("Da xoa thanh cong sinh vien co ma %d (del_After)", ma);
        }
    }
}
///////////////////////////////////////

///////////////////////////////////////
void insert_After(LList *L, Node *q, Data x)
{
    Node *pp;
    if (q == NULL)
    {
        return;
    }
    else
    {
        pp = (Node *)malloc(sizeof(Node));
        pp->infor = x;
        pp->link = q->link;
        q->link = pp;
        if (q == L->pTail)
        {
            L->pTail = pp;
        }
        L->pTail->link = L->pHead;
    }
    L->spt++;
}
///////////////////////////////////////
void nhap(Data *x)
{
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if (x->masv > 0)
    {
        printf("Nhap ten sv: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
void in(Data x)
{
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 2: %.2f\n",
           x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void processList(LList L)
{
    Node *pp = L.pHead;
    do
    {
        in(pp->infor);
        pp = pp->link;
    } while (pp != L.pHead);
}
/////////////////////////////////////////
void Search_Ma(LList *L, int ma)
{
    Node *pp = L->pHead;
    bool da_tim_thay = false;
    do
    {
        pp = pp->link;
        if (pp->infor.masv == ma)
            da_tim_thay = true;
    } while (pp != L->pHead && (pp->infor.masv != ma));
    if (pp == L->pHead && da_tim_thay == false)
    {
        printf("Khong tim thay sinh vien co ma %d", ma);
        return;
    }
    else
    {
        printf("Da tim thay sinh vien co ma %d\n", ma);
        printf("Thong tin cua sinh vien:\n");
        in(pp->infor);
    }
}
////////////////////////////////////////////

int main()
{
    LList L;
    int kt = 0;
    Data x;
    int y;
    Node *q;
    initList(&L); // tao ra 1 ds rong
    do
    {
        printf("\nChuong trinh lam viec voi DSLK don SV\n");
        printf("\n1: Them nut vao dau danh sach");
        printf("\n2: Them nut vao cuoi danh sach");
        printf("\n3: Them nut vao sau mot nut khac trong danh sach");
        printf("\n4: Xoa sinh vien theo ma");
        printf("\n5: Tim sinh vien theo ma");
        printf("\n9: Duyet ds");
        printf("\n0: Thoat");
        printf("\nMoi ban chon: ");
        int chon;
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
            printf("Nhap so thong tin sv can them\n");
            nhap(&x);
            if (x.masv > 0)
                insert_Head(&L, x);
            break;
        case 2:
            printf("Nhap so thong tin sv can them\n");
            nhap(&x);
            if (x.masv > 0)
                insert_Tail(&L, x);
            break;
        case 3:
            printf("ban muon them sinh vien moi vao sau sinh vien nao (nhap ma sinh vien): ");
            scanf("%d", &y);
            q = L.pHead;
            while (q != NULL && q->infor.masv != y)
            {
                q = q->link;
            }
            if (q == NULL)
            {
                printf("Khong ton tai sinh vien nay\n");
            }
            else
            {
                nhap(&x);
                if (x.masv > 0)
                    insert_After(&L, q, x);
            }
            break;
        case 4:
        {
            if(emptyList(L)) {
                printf("Danh sach rong\n");
                break;
            }
            printf("Nhap ma sinh vien can xoa: ");
            int ma;
            scanf("%d", &ma);
            del_MaSV(&L, ma);
            break;
        }
        case 5:
        {
            printf("Nhap ma sinh vien can tim: ");
            int ma;
            scanf("%d", &ma);
            Search_Ma(&L, ma);
            break;
        }
        case 9:
            if(emptyList(L)) {
                printf("Danh sach rong\n");
                break;
            }
            processList(L);
            break;
        case 0:
            printf("Bye bye\n");
            kt = 1;
        }
    } while (kt == 0);
}