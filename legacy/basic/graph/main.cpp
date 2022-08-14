#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
public:
    class Node {
    public:
        Node(int data) : data_(data) {}

        int data_;
        vector<int> adjacent = {};
        bool marked = false;
    };

    Graph(int size) {
        for (int i = 0; i < size ; i++) {
            node_list.push_back(Node(i));
        }
    }
    void addEdge(int i1, int i2) {
        cout << i1 << ", " << i2 << endl;
        Node& n1 = node_list[i1];
        Node& n2 = node_list[i2];

        n1.adjacent.push_back(i2);
        n2.adjacent.push_back(i1);
    }
    void print() {
        for(const auto& it: node_list) {
            cout << "Node " << it.data_ <<" :";
            for (const auto& it2 : it.adjacent) {
                cout << node_list[it2].data_ << ", ";
            }
            cout << endl;
        }
    }
    void dfs(int index) {
        Node& root = node_list[index];
        stack<Node> node_stack;
        node_stack.push(root);
        root.marked = true;

        while(!node_stack.empty()) {
            Node temp = node_stack.top();
            node_stack.pop();

            for(auto& it : temp.adjacent) {
                if (!node_list[it].marked) {
                    node_list[it].marked = true;
                    node_stack.push(node_list[it]);
                }
            }
            cout << temp.data_ << " ";
        }
    }
    vector<Node> node_list;
};

int main()
{
    Graph graph(9);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(5, 6);
    graph.addEdge(5, 7);
    graph.addEdge(6, 8);

//    graph.print();

    graph.dfs(0);

    return 0;
}
