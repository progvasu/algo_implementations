import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    static int getPrec(char ch)  {
        switch (ch)   {
            case '^':
                return 3;
            case '*':
                return 2;
            case '/':
                return 2;
            case '+':
                return 1;
            case '-':
                return 1;
            default:
                return 0;
        }
    }
    
    static String convertInfixPostFix(String input)   {
        Stack<Character> stack = new Stack<>();
        StringBuilder postfix = new StringBuilder();
        char temp;
        
        for (char ch : input.toCharArray()) {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                postfix.append(ch);
            else if (ch == '(')
                stack.push(ch);
            else if (ch == ')') {
                while (stack.peek() != '(') {
                    postfix.append(stack.pop());
                }
                stack.pop();
            }
            else    {
                if (stack.isEmpty())
                    stack.push(ch);
                else    {
                    while (!stack.isEmpty() && stack.peek() != '(' && getPrec(stack.peek()) >= getPrec(ch))    {
                        postfix.append(stack.pop());
                    }
                    stack.push(ch);
                }
            }
        } // end of for
        
        // empty the entire stack
        while (!stack.isEmpty())
            postfix.append(stack.pop());
            
        return postfix.toString();
    }
    
	public static void main (String[] args) {
	    Scanner scan = new Scanner(System.in);
	    
	    int test_cases = scan.nextInt();
	    String input;
	    String post_fix;
	    
	    while(test_cases-- > 0) {
	        input = scan.next();
	        
	        post_fix = convertInfixPostFix(input);
	        
	        System.out.println(post_fix);
	    }
	}
}