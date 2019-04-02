// same as friend spairing problem

Its simple to be understood...
The task is to find ways for n people,
This can be done as follows.
Reduce the task to nth person and n-1 people
Case 1 (When nth person is single)
Then no of ways in which nth person can be single is 1.
No of ways in which n-1 people can be paired or remain single are f(n-1)
So the total no of ways = 1*f(n-1)
Case 2 (nth person is paired)
no of ways nth person can be paired with n-1 people = n-1
no of ways in which remaining n-2 people can be paired = f(n-2)
total no of ways =(n-1)*f(n-2)

Add Case 1 and Case 2

5
•
Reply
•
Share ›

    Avatar
    magbene aakash mendiratta • 6 months ago

    Your explanation is great just a little change.
    no of ways in which remaining n-2 people can be paired "or remain single" = f(n-2)