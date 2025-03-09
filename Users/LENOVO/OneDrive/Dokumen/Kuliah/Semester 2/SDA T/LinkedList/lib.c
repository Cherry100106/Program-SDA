#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void Create_Node(address *p) {
    *p = NULL;
}

void Isi_Node(infotype Nilai, address *p) {
    *p = (address)malloc(sizeof(Node));
    if (*p != NULL) {
        (*p)->info = Nilai;
        (*p)->next = NULL;
    }
}

void Tampil_List(address p) {
    while (p != NULL) {
        printf("%d -> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

void Add_Awal(address *p, int nilai) {
    address temp;
    Isi_Node(nilai, &temp);
    if (temp != NULL) {
        temp->next = *p;
        *p = temp;
    }
}

void Add_Akhir(address *p, int nilai) {
    address temp, last = *p;
    Isi_Node(nilai, &temp);
    if (temp != NULL) {
        if (*p == NULL) {
            *p = temp;
        } else {
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = temp;
        }
    }
}

void Add_Tengah(address *p, int nilai, int posisi) {
    address temp, curr = *p;
    int count = 1;
    while (curr != NULL && count < posisi - 1) {
        curr = curr->next;
        count++;
    }
    if (curr != NULL) {
        Isi_Node(nilai, &temp);
        if (temp != NULL) {
            temp->next = curr->next;
            curr->next = temp;
        }
    }
}

void cariNode(address p, infotype nilai) {
    while (p != NULL) {
        if (p->info == nilai) {
            printf("Node dengan nilai %d ditemukan.\n", nilai);
            return;
        }
        p = p->next;
    }
    printf("Node dengan nilai %d tidak ditemukan.\n", nilai);
}

void hapus_NodeAwal(address *p) {
    if (*p != NULL) {
        address temp = *p;
        *p = (*p)->next;
        free(temp);
    }
}

void hapus_NodeAkhir(address *p) {
    if (*p != NULL) {
        address temp = *p, prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
        } else {
            *p = NULL;
        }
        free(temp);
    }
}

void hapus_node(address *p, int posisi) {
    if (*p == NULL) return;
    address temp = *p;
    if (posisi == 1) {
        *p = temp->next;
        free(temp);
        return;
    }
    address prev = NULL;
    for (int i = 1; temp != NULL && i < posisi; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

int jumtot_Node(address p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

int node_Max(address p) {
    int max = p->info;
    while (p != NULL) {
        if (p->info > max) {
            max = p->info;
        }
        p = p->next;
    }
    return max;
}

float rata2Node(address p) {
    int sum = 0, count = 0;
    while (p != NULL) {
        sum += p->info;
        count++;
        p = p->next;
    }
    return count == 0 ? 0 : (float)sum / count;
}

void tukar_Node(address *p) {
    if (*p == NULL || (*p)->next == NULL) return;
    address prev = NULL, curr = *p, next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev= curr;
        curr = next;
    }
    *p = prev;
}