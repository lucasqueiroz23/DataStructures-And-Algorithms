import { Edge } from "./edge";

export class GraphAdjList {
  constructor(nodes = [], isDigraph = false) {
    this.nodes = nodes;
    this.isDigraph = isDigraph;
    this.edges = [];
    this.adjacencyList = {};
    nodes.forEach((node) => (this.adjacencyList[node.id] = []));
  }
  /**
   * Adds a node to the graph.
   * @param node The new node.
   */
  addNode(node) {
    this.nodes.push(node);
    this.adjacencyList[node.id] = [];
  }
  /**
   * Checks if a node exists.
   * @param id Identifier of the node of interest.
   * @returns {boolean} `true` if the node exists, `false` otherwise.
   */
  nodeExists(id) {
    return this.nodes.filter((node) => node.id === id).length === 1;
  }
  /**
   * Create an edge from node1, to node2.
   * @param node1 First node.
   * @param node2 Node that node1 points to.
   * @param weight Weight of the edge.
   */
	addEdge(node1, node2, weight){
    this.adjacencyList[node1.id].push(node2);
    this.edges.push(new Edge(node1, node2, weight));
  }
  /**
   * Creates an adjacency, from node1 to node2.
   * If the graph is undirected, this function
   * will also create an adjacency from node2
   * to node1.
   * @param node1 The first node.
   * @param node2 The node that node1 points to.
   * @param weight The weight between the nodes.
   */
  createAdjacency(node1, node2, weight = 1) {
    if (!this.nodeExists(node1.id)) {
      this.addNode(node1);
    }
    if (!this.nodeExists(node2.id)) {
      this.addNode(node2);
    }

		this.addEdge(node1, node2, weight);
    if (!this.isDigraph) {
      this.addEdge(node2, node1, weight);
    }
  }
}