/*
 *Program to calculate factorial of large nos. in c++.
 *Usual loop method don't work here due to memory constraints.
 *
 *Input:
 *Just enter a number and hit enter.
 *
 *Output:
 *A file FactoResult.txt will be created having factorial asked.
 *Also, on console output, factorial result and no. of digits in it will also appear.
 *
 *Author: Brijesh Goyal
 *brijeshgoyal0808@gmail.com
 *
 */

#include<iostream>
#include<fstream>

using namespace std;

#define size 1000000

void putNumRevInArr(int res[], int n)			//Put the palindrome of the number in array
{
    int i=0;
    while(n)
    {
       res[i++]=n%10;
       n/=10;
    }
}

void copy(int dummy[], int res[])
{
	for(int i=0; dummy[i]!=-1; ++i)
		res[i]=dummy[i];
}

int dispNumInRev(int res[])				//To display the array
{
    ofstream myobj;
    myobj.open("FactoResult.txt");

    int i=0;
    int count=0;
    for(i=0; res[i]!=-1 ; ++i);
    count=i;
    --i;
    for(; i>=0 ; --i)
        {
            myobj<<res[i];
            cout<<res[i];
        }

    return count;
}

int main()
{
    ofstream myobj;
	int n;
	cin>>n;						//Fact number

	int res[size];					//Array to store final result
	fill_n(res, size, -1);				//Array res assigned values -1

	int dummy[size];				//Used for saving mul. res. of two nos.

	putNumRevInArr(res,n);          		//To put the number in reverse in the array

	--n;

	for(int i=n; i>1; --i)
	{
		int carry=0;
		int j=0;
		int num=0;				//Number to be formed after final multiplication of 2 nos. for eg 15*20, num = 300

		fill_n(dummy, size, -1);		//Assigning -1 to whole array @ every multiplication step with a new no.

		while(res[j]!=-1)			//For calculating multiplication of the 2 nos for facto
		{
			int x=i*res[j] + carry;
			//num=num*10 + x%10;
			dummy[j++]=x%10;		//Reusing variable j
			carry=x/10;
		}

		while(carry)				//In continuation of the above loop to complete the process bcoz last carry isn't appended
		{
			//num=num*10 + carry%10;
			dummy[j++]=carry%10;
			carry/=10;
		}
		//j is now at a value where number starts to its left
		//Now num contains the number which is palindrome of the required result.
		copy(dummy, res);
	}

	int count = dispNumInRev(res);			//Display the number in reverse
	//countDigits(res);

	cout<<"\n\ncount = "<<count<<endl;
}

