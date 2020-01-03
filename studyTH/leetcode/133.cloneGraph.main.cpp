/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* src) {
        //A Map to keep track of all the 
        //nodes which have already been created 
        map<Node*, Node*> m; 
        queue<Node*> q; 
  
        // Enqueue src node 
        q.push(src); 
        Node *node; 
  
        // Make a clone Node 
        vector<Node*> empty;
        node = new Node(src->val, empty); 
  
        // Put the clone node into the Map 
        m[src] = node; 
        while (!q.empty()) 
        { 
            //Get the front node from the queue 
            //and then visit all its neighbours 
            Node *u = q.front(); 
            q.pop(); 
            vector<Node *> v = u->neighbors; 
            int n = v.size(); 
            for (int i = 0; i < n; i++) 
            { 
                // Check if this node has already been created 
                if (m[v[i]] == NULL) 
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
   
        cout<< "After Cloning"<< endl;
        bfs(m[src]);
        return m[src];
    }
    
    void bfs(Node* src)
    {
        map<Node*, bool> visit; 
        queue<Node*> q; 
        q.push(src); 
        visit[src] = true; 
        while (!q.empty()) 
        { 
            Node *u = q.front(); 
            cout << "Value of Node " << u->val << "\n"; 
            cout << "Address of Node " <<u << "\n"; 
            q.pop(); 
            vector<Node *> v = u->neighbors; 
            int n = v.size(); 
            for (int i = 0; i < n; i++) 
            { 
                if (!visit[v[i]]) 
                { 
                    visit[v[i]] = true; 
                    q.push(v[i]); 
                } 
            } 
        } 
        cout << endl; 
    }
};