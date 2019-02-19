import java.util.*;
class N13_celebrity_problem
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0)
		{
			int N = sc.nextInt();
			int M[][] = new int[N][N];
			for(int i=0; i<N; i++)
			{
				for(int j=0; j<N; j++)
				{
					M[i][j] = sc.nextInt();
				}
			}
		System.out.println(new GfG().getId(M,N));
		t--;
		}
	}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

class GfG   {
    // The task is to complete this function
    int getId(int M[][], int n) {
        Stack<Integer> stack = new Stack<>();
        
        // initially push all the candidates onto the stack
        for (int i = 0 ; i < n ; i++)
            stack.push(i);
            
        int cand1, cand2;
        
        // pop two elements and check for celebrity status
        while (stack.size() > 1)   {
            cand1 = stack.pop();
            cand2 = stack.pop();
            
            // if cand1 knows cand2 cand1 cannot be a celebrity
            if (M[cand1][cand2] == 1)
                stack.push(cand2);
            else
                stack.push(cand1);
        }
        
        // person remaining onto the stack is the candidate for celebrity
        cand1 = stack.pop();
        System.out.println("CAnd" + cand1);
        
        int result = 1;
        // entire row should be zero
        for (int i = 0 ; i < n ; i++)   {
            if (i != cand1 && M[cand1][i] != 0)   {
                result = 0;
                break;
            }
        }
        
        // entire column should be 1 except when cand1 == cand2 
        // treating as dont care
        for (int i = 0 ; i < n && result != 0 ; i++)    {
            if (i != cand1 && M[i][cand1] != 1) {
                result = 0;
                break;
            }
        }
        
        if (result == 1)
            return cand1;
        else
            return -1;
    }
}