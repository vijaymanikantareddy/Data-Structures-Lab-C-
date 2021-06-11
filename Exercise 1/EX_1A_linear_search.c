/* a)Write C program that use both recursive and non recursive functions to perform Linear 
search for a Key value in a given list. 

            ALGORITHM TO PERFORM LINEAR SEARCH FOR A GIVEN LIST
Step1 : start
step2 : declare n,i,val,pos,option
step3 : input n 
step4 : declare arr[n]
step5 : intialize i=0
step6 : IF i<n 
            GO TO step7
        ELSE
           GO TO step9
        [END OF IF]
Step7 : read arr[i]
step8 : i=i+1 , GO TO step6
step9 : take input val
step10: Display "Enter 1 for non recursive function"
step11: Display "Enter 2 for recursive function"
step 12: read option
step13: IF option = 1
           GO TO step 14
        ELSE IF option = 2
             GO TO step 19
        ELSE 
           display "Enter correct option"
             GO TO step 23
               [END OF IF]
step14 : set found=0, pos=-1
step15 : intilize i=0
step16 : repeat step17 while i<=n
step17 : IF arr[i]=val
            set pos= i
          print pos
         go to step23
         [END OF IF]
          set i=i+1
step18: IF pos = -1
           print "value not found"
           [END OF IF]
            GO TO STEP23   
step19 : set pos=0
step20 : IF n>0
           GO TO step21
          ELSE 
           GO TO step23
          [END OF IF]       
step21 : IF arr[n-1]=val
          assign pos=n
         ELSE
            set i=i+1
            GO TO step20
          [END OF IF]
step22: IF pos!=0
           print "element is found"
         ELSE
            print "element not found"
           GO TO step23
step23 : stop
              */

#include<stdio.h>
void linear_search(int val,int n,int arr[*]);		//non-recursive function
int linear_search_re(int val,int n,int arr[*]);		//recursive function
void main()
{
	int n,i,val,pos,option;
	printf("enter the size of array: ");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("enter the value to search: ");
	scanf("%d",&val);
	printf("enter 1 for Non-Recursive Function \n");
	printf("enter 2 for Recursive Function\n ");
	scanf("%d",&option);
	switch(option)
	{
	    case 1:
	    {
	       	linear_search(val,n,arr);
	       	break;
	    }
	    case 2:
	    {
	        pos=linear_search_re(val,n,arr);
	        if(pos!=0)
		        printf("\nelement %d is found at position %d using Recursive function",val,pos);
	        else 
	        	printf("\nelement %d does not found using Recursive function",val);
	        break;	
	    }
	    default:
	        printf("enter correct option! ");
	}
}
void linear_search(int val,int n,int arr[n])	//Non-recursive function
{
	int i,found=0,pos=-1;
	for(i=0;i<n;i++)
	{
		if(arr[i]==val)
		{
			found=1;
			pos=i;
			printf("\nelement %d is found at position %d using Non-Recursive function",val,i+1);
			break;
		}
	}
	if(found==0)
		printf("\nelement %d does not found using Non-Recursive function",val);
}
int linear_search_re(int val,int n,int arr[n])	  //Recursive function
{
	if(n>0)
	{
		if(arr[n-1]==val)
			return n;
		else
			return linear_search_re(val,n-1,arr);	
	}
	return 0;
}
