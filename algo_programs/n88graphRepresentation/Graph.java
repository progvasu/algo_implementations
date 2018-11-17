package n88graphRepresentation;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author vasu
 */

// graph object
public class Graph {
    private int n;  // number of vertices 
    private int m;  // number of edges
    
    // a list of lists for representing - Adjacencey List
    // every position represents a vertex
    private List<List<Edge>> adj = new ArrayList<>();
    // List of all edges
    private List<Edge> allEdges;
    // vertex properties
    private List<Vertex> allVertexs = new ArrayList<>();
    
    // constructor for graph
    public Graph(int n, int m)  {
        this.n = n;
        this.m = m;
        
        // creating EdgeList object for each Vertex
        // and create vertex property object for each vertex
        for (int i = 0 ; i < n ; i++)   {
            adj.add(i, new ArrayList<Edge>());
            allVertexs.add(i, new Vertex(i, 'R'));
        }
    }
    
    public void addEdges(List<Edge> edges) {
        // storing all edges
        setAllEdges(edges);
        
        // adding edges to the graph
        // the way we add edges will specify whether the graph is directed or undirected
        for (Edge current : edges)  {
            // for directed edges
            adj.get(current.getSrc()).add(current);
        }
    }
    
    public void addEdgesUndirected(List<Edge> edges) {
        // storing all edges
        setAllEdges(edges);
        
        // adding edges to the graph
        // the way we add edges will specify whether the graph is directed or undirected
        for (Edge current : edges)  {
            // for directed edges
            adj.get(current.getSrc()).add(current);
            // for undirected graphs
            adj.get(current.getDest()).add(current);
        }
    }
    
    // get a single vertex's properties as a vertex object
    public Vertex getVertex(int vert_no)    {
        return allVertexs.get(vert_no);
    }
    
    public List<Edge> getEdgeList(int vertex)    {
        return adj.get(vertex);
    }
    
    public void printGraph() {
        for (int i = 0 ; i < getN() ; i++) {
            // print current vertex and all of its neighbouring vertex's
            for (Edge edge : adj.get(i))   {
                System.out.print("(" + edge.getSrc() + "|" + i + " --> " + edge.getDest() + ")  ");
            }
            
            System.out.println();
        }
    }
    
    public void printWeightedGraph() {
        for (int i = 0 ; i < getN() ; i++) {
            // print current vertex and all of its neighbouring vertex's
            for (Edge edge : adj.get(i))   {
                System.out.printf("%3s --> %3s(%3s)  ", edge.getSrc(), edge.getDest(), edge.getWeight());
            }
            
            System.out.println();
        }
    }

    /**
     * @return the n
     */
    public int getN() {
        return n;
    }

    /**
     * @param n the n to set
     */
    private void setN(int n) {
        this.n = n;
    }

    /**
     * @return the m
     */
    public int getM() {
        return m;
    }

    /**
     * @param m the m to set
     */
    private void setM(int m) {
        this.m = m;
    }

    /**
     * @return the allEdges
     */
    public List<Edge> getAllEdges() {
        return allEdges;
    }

    /**
     * @param allEdges the allEdges to set
     */
    private void setAllEdges(List<Edge> allEdges) {
        this.allEdges = allEdges;
    }
}
