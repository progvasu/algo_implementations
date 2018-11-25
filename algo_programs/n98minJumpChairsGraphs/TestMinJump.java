package n98minJumpChairsGraphs;

/**
 *
 * @author vasu
 */

public class TestMinJump {
    public static void main(String[] args)  {
        // Example 1
        int no_chairs = 5;
        int[] ai = new int[]{2, 1, 2, 3, 4};
        
        // creating jump graph
        MinJump obj = new MinJump(no_chairs, ai);
        
        // since i have the graph now
        // we could run SSSP to find the shortest path between X and Y
        // or we could run Floyd Warshall's algorithm to find APSP
        // simple from here...
        // implementing Floyd Warshall because of the sole reason of not having 
        // it implemented incase of adjacency list representation
        
        obj.computeMinDist();
    }
}
