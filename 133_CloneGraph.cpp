/****************************************************************
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
OJ's undirected graph serialization:
Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.
The graph has a total of three nodes, and therefore contains three parts as separated by #.
First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
****************************************************************/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    void clone_node(UndirectedGraphNode *&p, UndirectedGraphNode *&q, unordered_map<int, UndirectedGraphNode*> &um) {
        q = new UndirectedGraphNode(p->label);
        um[p->label] = q;
        for (int i = 0; i < p->neighbors.size(); i++) {
            int label = p->neighbors[i]->label;
            if (um.find(label) != um.end()) {
                q->neighbors.push_back(um[label]);
            } else {
                UndirectedGraphNode *cn;
                clone_node(p->neighbors[i], cn, um);
                q->neighbors.push_back(cn);
            }
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        UndirectedGraphNode *cn = NULL;
        unordered_map<int, UndirectedGraphNode*> um;
        clone_node(node, cn, um);
        return cn;
    }
};