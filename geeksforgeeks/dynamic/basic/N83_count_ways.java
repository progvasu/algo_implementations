// interesting problem - easy solution
 For each row we have two options:
Build houses in both the spots
Build one house and one office

The first one can be done without any constraints. There is one way of building houses in both the spots at length i. So total ways using this choice = total ways for length i – 1.

For the second choice, if row (i-1) had houses in both spots we have two ways of building a office i.e. (H O) and (O H)
if row(i-1) had an office in one of its two spots we only have one way to build an office in row i.If prev row had (O H) curr row would have (H O) and similarly for prev row = (H O) curr row = (O H).
From the above logic, total ways with this choice = 2 * (choice1(i-1)) + choice2(i-1)

We will build a 2D dp for this.
dp[0][i] indicates choice1 and dp[1][i] indicates choice2 for row i.