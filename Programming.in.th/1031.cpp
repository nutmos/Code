//Copyright 2013 Nutmos' Studio
//Nattapong Ekdomsuk
//All Right Reserved
#include <iostream>
#include <cstdlib>
#define UNPROCESS 0
#define PROCEED 1

using namespace std;

int *status;
int *fromFirstNode;
int *stairs;

struct node {
    int id;
    //int fromFirstNode;
    node *next;
};

struct graph {
    node **nodeHead;
};

struct queue {
    int *qArray;
    int first;
    int last;
    int num;
};

class queueOper {
public:
    void enqueue (queue *q, int n) {
        q->num++;
        q->qArray[++q->last] = n;
    }
    int dequeue (queue *q) {
        q->num--;
        int en = q->qArray[q->first++];
        return en;
    }
    void print (queue *q) {
        //cout << "queue have" << endl;
        for (int i = q->first; i <= q->last; i++) {
            cout << q->qArray[i] << endl;
        }
    }
};

class graphOper {
public:
    void addEdge(graph *g, int from, int to) {
        node *n = (node *)malloc(sizeof(node));
        n->id = to;
        n->next = g->nodeHead[from-1]->next;
        g->nodeHead[from-1]->next = n;
    }
    void print(graph *g, int num) {
        for (int i = 0; i < num; i++) {
            node *n_ptr = g->nodeHead[i]->next;
            //cout << "head " << i+1 << " point to:" << endl;
            while (n_ptr != NULL) {
                cout << n_ptr->id << endl;
                n_ptr = n_ptr->next;
            }
        }
    }
};

void bfs(graph *g, int num) {
    //start at floor 1
    /*queueOper qOper;
    queue *q = new queue;
    q->qArray = new int[num];
    q->first = 0;
    q->last = -1;
    q->num = 0;
    qOper.enqueue(q, 1);*/
    //graphOper gOper;
    for (int i = 0; i < num; i++) {
        //qOper.print(q);
        //cout << "process at node: " << i << endl;
        node *n_ptr = g->nodeHead[i]->next;
        //cout << "i = " << i << endl;
        //cout << "fromFirstNode[i] = " << fromFirstNode[i] << endl;
        while (n_ptr != NULL) {
            if (fromFirstNode[n_ptr->id-1] > fromFirstNode[i] + 1) {
                fromFirstNode[n_ptr->id-1] = fromFirstNode[i] + 1;
            }
            n_ptr = n_ptr->next;
        }
    }
}

int main() {
    int k,n,m;
    cin >> k >> n >> m;
    graph *g = (graph *)malloc(sizeof(graph));
    g->nodeHead = (node**)malloc(sizeof(node*)*n);
    status = (int*)calloc(sizeof(int),n);
    fromFirstNode = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        if (i != 0) fromFirstNode[i] = k+1;
        else fromFirstNode[i] = 0;
    }
    stairs = (int*)calloc(sizeof(int), n);
    /*queue *q = (queue *)malloc(sizeof(queue));
    q->first = 0;
    q->last = -1;
    q->num = 0;
    q->qArray = (int *)malloc(sizeof(queue)*n);*/
    graphOper gOper;
    for (int i = 0; i < n; i++) {
        g->nodeHead[i] = (node*)malloc(sizeof(node));
        g->nodeHead[i]->next = NULL;
        g->nodeHead[i]->id = i;
    }
    for (int i = 0; i < m; i++) {
        int from,to;
        cin >> from >> to;
        gOper.addEdge(g, from, to);
        stairs[from-1]++;
    }
    //gOper.print(g, n);
    //sorting stairs by goal floor
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < stairs[g->nodeHead[i]->id]; j++) {
            //cout << "test" << endl;
            node *n_ptr = g->nodeHead[i]->next;
            while (n_ptr->next != NULL) {
                if (n_ptr->id > n_ptr->next->id) {
                    int temp = n_ptr->id;
                    n_ptr->id = n_ptr->next->id;
                    n_ptr->next->id = temp;
                }
                n_ptr = n_ptr->next;
            }
        }
    }
    //gOper.print(g, n);
    //cout << "test1" << endl;
    bfs(g, n);
    /*for (int i = 0; i < n; i++) {
        cout << "floor " << i+1 << " from first node " << fromFirstNode[i] << endl;
    }
    cout << "highest floor can reach" << endl;*/
    for (int i = n-1; i >= 0; i--) {
        if (fromFirstNode[i] <= k) {
            cout << i+1;
            break;
        }
    }
}
