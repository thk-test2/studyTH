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

        bool operator==(const Node& obj2) const
        {
            if(this->data_ == obj2.data_)
                return true;
            else
                return false;
        }

        int data_;
        vector<Node> adjacent = {};
        bool visited = false;
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

        vector<Node>::iterator n1_it;
        vector<Node>::iterator n2_it;

        n1_it = find(n1.adjacent.begin(), n1.adjacent.end(), n2);
        n2_it = find(n2.adjacent.begin(), n2.adjacent.end(), n1);

        if(n1_it == n1.adjacent.end()) {;
            n1.adjacent.push_back(n2);
        }
        if(n2_it == n2.adjacent.end()) {
            n2.adjacent.push_back(n1);
        }
        print();
    }
    void print() {
        for(const auto& it: node_list) {
            for (const auto& it2 : it.adjacent) {
                cout << it2.data_ << ", ";
            }
            cout << endl;
        }
    }
    void dfs(int index) {
        Node root = node_list[index];
        stack<Node> node_stack;

        node_stack.push(root);
        while(!node_stack.empty()) {
            Node temp = node_stack.top();
            node_stack.pop();

            if (!temp.visited) {
                temp.visited = true;
                cout << temp.data_ << ", ";
            }
            for(const auto& it : temp.adjacent) {
                if (!it.visited)
                    node_stack.push(it);
            }
        }
    }
    vector<Node> node_list;
};

int main()
{
    vector<vector<int>> edge;
    edge.push_back(vector<int>(0, 1));
    edge.push_back(vector<int>(0, 2));
    edge.push_back(vector<int>(0, 3));
    edge.push_back(vector<int>(2, 3));

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
