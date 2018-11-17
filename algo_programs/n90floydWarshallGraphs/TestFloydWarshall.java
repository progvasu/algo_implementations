package n90floydWarshallGraphs;

/**
 *
 * @author vasu
 */

public class TestFloydWarshall {
    public static void main(String[] args)    {
        int graph[][] = {   { 0,    5,  99,   10},
                            {99,    0,   3,   99},
                            {99,   99,   0,    1},
                            {99,   99,  99,    0}     };

//        int graph[][] = {   {0,  3,  6,  99,  99,  99,  99},
//                            {3,  0,  2,   1,  99,  99,  99},
//                            {6,  2,  0,   1,   4,   2,  99},
//                            {99, 1,  1,   0,   2,  99,  99},
//                            {99,99,  4,   2,   0,   2,   1},
//                            {99,99,  2,  99,   2,   0,   1},
//                            {99,99, 99,   4,   1,   1,   0}     };
        
        FloydWarshall obj = new FloydWarshall(graph);

        obj.computeShortestPaths();

        obj.printResult();
        
        obj.printPathBetween(0, 3);
    }
}
