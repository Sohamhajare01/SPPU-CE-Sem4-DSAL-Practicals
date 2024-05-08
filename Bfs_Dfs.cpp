#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct node {
    int vertex;
    node *next;
}*adj_list[10];

class Graph {
private:
    int n;
public:
    stack<int> s;
    queue<int> q;
    void read_graph(struct node *adj_list[10], int n);
    void create();
    void dfs();
    void bfs();
};

void Graph::read_graph(struct node *adj_list[10], int n) {
    int i, j;
    char reply;
    struct node *p, *c;
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            if (i == j)
                continue;
            cout << "\n Vertices " << i << " & " << j << " are Adjacent ? (Y/N) :";
            cin >> reply;
            if (reply == 'y' || reply == 'Y') {
                c = new node;
                c->vertex = j;
                c->next = NULL;
                if (adj_list[i] == NULL)
                    adj_list[i] = c;
                else {
                    p = adj_list[i];
                    while (p->next != NULL)
                        p = p->next;
                    p->next = c;
                }
            }
        }
    }
}

void Graph::create() {
    struct node *p;
    int deg, i;
    cout << "\n How Many Vertices ? : ";
    cin >> n;
    for (i = 1; i <= n; i++)
        adj_list[i] = NULL;
    read_graph(adj_list, n);
    
}

void Graph::dfs() {
    int sv, num;
    node *t;
    cout << "Enter starting vertex: ";
    cin >> sv;
    int visited[10] = {0};
    s.push(sv);
    while (!s.empty()) {
        num = s.top();
        s.pop();
        if (visited[num] == 0) {
            cout << num << " ";
            visited[num] = 1;
        }
        t = adj_list[num];
        while (t != NULL) {
            if (visited[t->vertex] == 0)
                s.push(t->vertex);
            t = t->next;
        }
    }
    cout << endl;
}

void Graph::bfs() {
    int sv, num;
    node *t;
    cout << "Enter starting vertex: ";
    cin >> sv;
    int visited[10] = {0};
    q.push(sv);
    while (!q.empty()) {
        num = q.front();
        q.pop();
        if (visited[num] == 0) {
            cout << num << " ";
            visited[num] = 1;
        }
        t = adj_list[num];
        while (t != NULL) {
            if (visited[t->vertex] == 0)
                q.push(t->vertex);
            t = t->next;
        }
    }
    cout << endl;
}

int main() {
    Graph obj;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create Graph\n";
        cout << "2. DFS Traversal\n";
        cout << "3. BFS Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                obj.create();
                cout << "Graph created successfully.\n";
                break;
            case 2:
                cout << "DFS Traversal: ";
                obj.dfs();
                cout << endl;
                break;
            case 3:
                cout << "BFS Traversal: ";
                obj.bfs();
                cout << endl;
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 4);

    return 0;
}