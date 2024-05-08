#include <iostream>
#include <vector>

using namespace std;

const int INF = 999;

int minCostEdge(int n, const vector<int> &minCost, const vector<bool> &visited)
{
    int minCostEdge = -1;
    int minCostValue = INF;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] && minCost[i] < minCostValue)
        {
            minCostValue = minCost[i];
            minCostEdge = i;
        }
    }

    return minCostEdge;
}

vector<pair<int, int>> primMST(const vector<vector<int>> &graph, int n)
{
    vector<bool> visited(n, false);
    vector<int> minCost(n, INF);
    vector<int> parent(n, -1);
    vector<pair<int, int>> mst;

    minCost[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; ++count)
    {
        int u = minCostEdge(n, minCost, visited);
        if (u == -1)
            break;

        visited[u] = true;

        if (parent[u] != -1)
            mst.push_back({parent[u], u});

        for (int v = 0; v < n; ++v)
        {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < minCost[v])
            {
                minCost[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    return mst;
}

void printMST(const vector<pair<int, int>> &mst, const vector<vector<int>> &graph)
{
    int totalCost = 0;
    cout << "Minimum Spanning Tree (MST) edges:" << endl;
    for (auto &edge : mst)
    {
        cout << edge.first << " - " << edge.second << " (Cost: " << graph[edge.first][edge.second] << ")" << endl;
        totalCost += graph[edge.first][edge.second];
    }
    cout << "Total cost of MST: " << totalCost << endl;
}

int main()
{
    int choice;
    vector<vector<int>> graph;
    int n = 0;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Input Graph\n";
        cout << "2. Find Minimum Spanning Tree (MST)\n";
        cout << "3. Print MST\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the number of vertices: ";
            cin >> n;
            graph.clear();
            graph.resize(n, vector<int>(n));

            cout << "Enter the adjacency matrix (0 for no edge):" << endl;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    cin >> graph[i][j];
                }
            }
            break;
        }
        case 2:
        {
            if (n == 0)
            {
                cout << "Graph not initialized. Please input graph first." << endl;
                break;
            }
            vector<pair<int, int>> mst = primMST(graph, n);
            cout << "Minimum Spanning Tree (MST) found." << endl;
            break;
        }
        case 3:
        {
            if (n == 0)
            {
                cout << "Graph not initialized. Please input graph first." << endl;
                break;
            }
            vector<pair<int, int>> mst = primMST(graph, n);
            printMST(mst, graph);
            break;
        }
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
