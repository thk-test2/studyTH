#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* src) {
        if (!src) return nullptr;

        //A Map to keep track of all the 
        //nodes which have already been created 
        unordered_map<Node*, Node*> m;
        queue<Node*> q;

        // Enqueue src node 
        q.push(src);
        Node* node;

        // Make a clone Node 
        vector<Node*> empty;
        node = new Node(src->val, empty);

        // Put the clone node into the Map 
        m[src] = node;
        while (!q.empty())
        {
            //Get the front node from the queue 
            //and then visit all its neighbours 
            Node* u = q.front();
            q.pop();
            vector<Node*> v = u->neighbors;
            int n = v.size();
            for (int i = 0; i < n; i++)
            {
                // Check if this node has already been created 
                if (m.count(v[i]) == 0)
                {
                    // If not then create a new Node and 
                    // put into the HashMap 
                    node = new Node(v[i]->val, empty);
                    m[v[i]] = node;
                    q.push(v[i]);
                }

                // add these neighbours to the cloned graph node 
                m[u]->neighbors.push_back(m[v[i]]);
            }
        }
        return m[src];
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	return 0;
}