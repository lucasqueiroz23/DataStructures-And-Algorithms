import { Edge } from "./edge";

export class GraphAdjList {
  constructor(numberOfNodes = 0){
    this.numberOfNodes = numberOfNodes;
    this.numberOfEdges = 0;
    this.edges = [];
    this.adjacencyList = {};
  }
  /**
   * Adds a node to the graph.
   * @param node The new node.
   */
  addNode(node){
    this.adjacencyList[node.id] = [];
    this.numberOfNodes++;
  }
  /**
   * Creates an adjacency, from node1 to node2.
   * @param node1 The first node.
   * @param node2 The node that node1 points to.
   * @param weight The weight between the nodes.
   */
  createAdjacency(node1, node2, weight){
    this.adjacencyList[node1.id].push(node2);
    this.edges.push(new Edge(node1, node2, weight));
  }


}