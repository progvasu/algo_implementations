#include<stdio.h>
#include<stdlib.h>

int checkIfMatch(char *main_string, char *sub_string, int main_start, int sub_len)  {
    int i = 0;
    
    for (i ; i < sub_len ; i++)    {
    	    if (sub_string[i] != main_string[main_start + i - sub_len])
		    return 0;
    }

    return 1;
}

int main()	{
	int main_len = 0, sub_len = 0, temp_len;
	char current_char;
	char *main_string, *sub_string;

	//initially allocating size for 100 characters for main string
	temp_len = 100;
	main_string = malloc(temp_len * sizeof(char));
	sub_string = malloc(temp_len * sizeof(char));

	printf("Enter the main string: ");
	while((current_char = getchar()) != '\n')	{
		if(main_len >= temp_len)
			main_string = realloc(main_string, (temp_len += 10) * sizeof(char));
		main_string[main_len++] = current_char;
	}

	temp_len = 100;
	printf("Enter the sub string: ");
	while((current_char = getchar()) != '\n')	{
		if(sub_len >= temp_len)
			sub_string = realloc(sub_string, (temp_len += 10) * sizeof(char));
		sub_string[sub_len++] = current_char;
	}

	main_string[main_len] = '\0';
	sub_string[sub_len] = '\0';

	int p = 1000003, hash_main, hash_sub;
	hash_main = main_string[0];
	hash_sub = sub_string[0];
	int i, t = 2, result;

	// initial hash
	for (i = 1 ; i < sub_len ; i++)	{
		hash_main = (2 * hash_main + main_string[i]) % p;
		hash_sub = (2 * hash_sub + sub_string[i]) % p;
		t = 2 * t;
	}

	result = checkIfMatch(main_string, sub_string, sub_len, sub_len);

	if (result == 0)    {
		for (i = sub_len ; i < main_len ; i++)	{
            	hash_main = (2 * hash_main + main_string[i] - t * main_string[i - sub_len]) % p;

            	if (hash_main < 0)
        	        hash_main += p;
		if(hash_main == hash_sub)	{
        	        result = checkIfMatch(main_string, sub_string, i + 1, sub_len);
            }

            if (result == 1)
                break;
        }
    }

	if (result == 0)
		printf("False\n");
	else
    		printf("True\n");

	return 0;
}
