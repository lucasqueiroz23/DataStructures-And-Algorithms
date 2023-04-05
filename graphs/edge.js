/**
 * An Edge of a Graph.
 */
export class Edge {
  constructor(node1, node2, weight){
    this.id1 = node1.id;
    this.id2 = node2.id;
    this.weight = weight;
  }
}