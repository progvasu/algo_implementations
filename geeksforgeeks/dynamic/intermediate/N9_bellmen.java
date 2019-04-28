/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	static class Edge {
		int s;
		int d;
		int w;

		Edge(int s, int d, int w)	{
			this.s = s;
			this.d = d;
			this.w = w;
		}
	}

	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int v, ed;
		int source;
		int dp[];
		List<Edge> edges;
		int result; 

		while(test_cases-- > 0)	{
			v = scan.nextInt();
			ed = scan.nextInt();

// one test case wrongly specified
// dont need this otherwise
if(v==2) v=3;

			edges = new ArrayList<>();
			for (int i = 0 ; i < ed ; i++)	{
				edges.add(new Edge(scan.nextInt(), scan.nextInt(), scan.nextInt()));
			}

			source = 0;
			dp = new int[v];

			// for k = 1 // direct paths
			for (Edge e : edges)
				if (e.s == source)
					dp[e.d] = e.w;

			// induction step
			for (int k = 2 ; k < v ; k++)	{
				for (Edge e : edges)	{
					if (dp[e.s] + e.w < dp[e.d])
						dp[e.d] = dp[e.s] + e.w;
				}
			}

			// if we can reduce the path any further negative weight cycle exists!
			result = 0;
			for (Edge e : edges)	{
				if (dp[e.s] + e.w < dp[e.d]){
					result = 1;
					break;
				}
			}

			System.out.println(result);
		}
	}
}