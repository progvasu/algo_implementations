package com.coursera.divide;

import java.io.*;
import java.util.*;

public class KargerMinCut {
    public static int getMinCut(ArrayList<Integer> verts_org, ArrayList<ArrayList<Integer>> edges_org)   {
        ArrayList<Integer> verts = (ArrayList<Integer>)verts_org.clone();
        ArrayList<ArrayList<Integer>> edges = new ArrayList<>(edges_org.size());
        ArrayList<Integer> edge_set;
        int i, random1, random2, vertex1, vertex2 = 0, temp;
        Iterator<Integer> inner;
        
        Iterator<ArrayList<Integer>> outer = edges_org.iterator();
        while (outer.hasNext()) {
            inner = outer.next().iterator();
            edge_set = new ArrayList<>();
            while (inner.hasNext()) {
                edge_set.add(inner.next());
            }
            edges.add(edge_set);
        }
        
        // choosing a random edge
        Random rand = new Random();
        
        while (verts.size() > 2)    {
            
            random1 = rand.nextInt(verts.size());
            vertex1 = verts.get(random1);
            
            // System.out.println(edges.get(vertex1 - 1).size());
            
            random2 = rand.nextInt(edges.get(vertex1 - 1).size());
            inner = edges.get(vertex1 - 1).iterator();
            while (random2 >= 0)    {
                vertex2 = inner.next();
                random2--;
            }
            
            // removing the choosen vertex2
            verts.remove(new Integer(vertex2));
            
            // merging the edges of vertex2 with vertex1
            edges.get(vertex1 - 1).addAll(edges.get(vertex2 - 1));
            // duplicates will be removed automatically
            
            // for the remaining elements in the vertex set verts
            // removing the values of vertex2
            for (i = 0 ; i < verts.size() ; i++)    {
                edge_set = edges.get(verts.get(i) - 1);
                while (edge_set.remove(new Integer(vertex2)))
                    edge_set.add(vertex1);
            }
            
            // removing self edges if any from vertex1
            while (edges.get(vertex1 - 1).remove(new Integer(vertex1))) {
            }
            
            // testing - printing status after each call
//            System.out.println("Vertex choosen = " + vertex1 + " " + vertex2);
//            for (i = 0 ; i < verts.size(); i++) {
//                System.out.println("Vertex = " + verts.get(i));
//                Iterator<Integer> iter = edges.get(verts.get(i) - 1).iterator();
//                while (iter.hasNext())  {
//                    System.out.print(iter.next() + "  ");
//                }
//                System.out.println("");
//            }
            
        }
        
        // what to return
        return edges.get(verts.get(0) - 1).size();
    }
    
    public static void main(String[] args) throws IOException {
        ArrayList<Integer> verts = new ArrayList<>();
        ArrayList<ArrayList<Integer>> edges = new ArrayList<>();
        ArrayList<Integer> edge_set;
        BufferedReader br = new BufferedReader(new FileReader(System.getProperty("user.dir") + "/data/kargerMinCut.txt"));
        StringTokenizer st;
        String current_line;
        int current_vertex, min = 1000, temp;
        
        int i;
        
        // initialize vertices and edges
        while((current_line = br.readLine()) != null)    {
            st = new StringTokenizer(current_line);
	
            current_vertex = Integer.parseInt(st.nextToken());
            verts.add(current_vertex);
            edge_set = new ArrayList<>();
            
            while (st.hasMoreTokens())  {
                current_vertex = Integer.parseInt(st.nextToken());
                edge_set.add(current_vertex);
            }
            
            edges.add(edge_set);
        }
                
        for (i = 0 ; i < 100 ; i++) {
            temp = getMinCut(verts, edges);
            if (min > temp)
                min = temp;
        }
        
        System.out.println(min);
        
        // testing printing out read in values
//        for (i = 0 ; i < verts.size(); i++) {
//            System.out.println("\n" + "Vertex = " + verts.get(i));
//            Iterator<Integer> iter = edges.get(i).iterator();
//            
//            while (iter.hasNext())  {
//                System.out.print(iter.next() + "   ");
//            }
//        }
        
        
    }
}