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
    // Adjacencey Matrix
    // we will create only when requested
    private int isAMComputed;
    private int[][] AM;
    
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
        
        // not creating AM by default
        isAMComputed = 0;
    }
    
    
    public void reInitializeVertexs()  {
        for(Vertex vert : allVertexs)   {
            vert.reInitialize();
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
        int src, dest;
        
        // edges are needed in reverse order also
        List<Edge> udir_edges = new ArrayList<>(edges);
        
        for (Edge current : edges)  {
            src = current.getSrc();
            dest = current.getDest();
            
            if (src != dest)    {
                udir_edges.add(new Edge(dest, src, current.getWeight()));
            }
        }
        
        // storing all edges
        setAllEdges(udir_edges);
        
        // adding edges to the graph
        for (Edge current : udir_edges)  {
            adj.get(current.getSrc()).add(current);
        }
    }
    
    // get a single vertex's properties as a vertex object
    public Vertex getVertex(int vert_no)    {
        return allVertexs.get(vert_no);
    }
    
    // get all Vertex List
    public List<Vertex> getAllVertexs() {
        return allVertexs;
    }
    
    public List<Edge> getEdgeList(int vertex)    {
        return adj.get(vertex);
    }
    
    public int[][] getAM()  {
        // if AM not computed compute it
        if (this.isAMComputed == 0)
            computeAM();
        
        return this.AM;
    }
    
    private void computeAM()    {
        // to show that AM is computed
        this.isAMComputed = 1;
        
        // intialize AM
        this.AM = new int[getN()][getN()];
        
        // our representation of AM is such that if the path doesn't exist
        // we give it a heavy weight - 999 our max value - assumption
        for (int i = 0 ; i < getN() ; i++) {
            for (int j = 0 ; j < getN() ; j++)  {
                if (i != j) {
                    AM[i][j] = 999;
                }
            }
        }
        
        // we use the list of all edges to compute it
        for (Edge edge : allEdges)  {
            // to edges of zero weight are given weight 1 to show that an edge exist between them
            if (edge.getWeight() == 0)
                AM[edge.getSrc()][edge.getDest()] = 1;
            else
                AM[edge.getSrc()][edge.getDest()] = edge.getWeight();
        }
    }
    
    public void printGraphAM()  {
        if (this.isAMComputed == 0)
            computeAM();
        
        System.out.println("Adjacency Matrix:");
        // first row vertex numbers
        System.out.printf("%5s", " ");
        for(int i = 0 ; i < getN() ; i++)
            System.out.printf("%5d", i);
        System.out.println("");
        for(int i = 0 ; i < getN() ; i++)   {
            System.out.printf("%5d", i);
            for(int j = 0 ; j < getN() ; j++)   {
                System.out.printf("%5d", AM[i][j]);
            }
            System.out.println("");
        }
        System.out.println("");
    }
    
    public void printGraph() {
        for (int i = 0 ; i < getN() ; i++) {
            // print current vertex and all of its neighbouring vertex's
            for (Edge edge : adj.get(i))   {
                // System.out.print("(" + edge.getSrc() + "|" + i + " --> " + edge.getDest() + ")  ");
                System.out.print("(" + i + " --> " + edge.getDest() + ")  ");
            }
            System.out.println();
        }
        System.out.println();
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
