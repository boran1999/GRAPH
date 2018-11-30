#include <iostream>
#include "graf.h"

using namespace std;

void addNode(Node* node){
nodes.push(node);
for (set<Node*>::iterator it = nodes.begin();it != nodes.end(); it++) {
 (*it)->addNeighbour(node);

}

void Graph::removeNode(Node* node) {
 nodes.erase(node);
 for (set<Node*>::iterator it = nodes.begin();
 it != nodes.end(); it++) {
 (*it)->removeNeighbour(node);
 }
}

void Graph::addEdge(Node* begin, Node* end) {
 if (nodes.find(begin) == nodes.end())
	 return;
 if (nodes.find(end) == nodes.end())
	return;
 begin->addNeighbour(end);
 end->addNeighbour(begin);
}

void Graph::removeEdge(Node* begin, Node* end) {
 if (nodes.find(begin) == nodes.end())
	 return;
 if (nodes.find(end) == nodes.end())
	return;
 begin->addNeighbour(end);
 end->addNeighbour(begin);
}

bool BFS::connected(Node* begin, Node* end) {
 queue<Node*> nodes; nodes.push(begin);
 set<Node*> visited;
 while (!nodes.empty()) {
 Node* next = nodes.front(); nodes.pop();
 if (end == next) return true;
 visited.insert(next);
 for (node_iterator it = next->nb_begin();
 it != next->nb_end(); it++)
 if (visited.find(*it) == visited.end())
 nodes.push(*it);
 }
 return false;
} 
