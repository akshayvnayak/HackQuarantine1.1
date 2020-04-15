#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    int T,N,K,M,i,j,a,countt;
    T=5;
//    cin>>T;
    for(int t=0;t<T;t++)        // for T testcases
    {
        nmkInput:
        cin>>N>>M>>K;
        if(N>500||N<0||M<1||M>9||K<1||K>1000)               // Validating according to given condition
        {
            cout<<"Invalid input!! Enter the line again.\n";
            goto nmkInput;
        }
        int C[N][K];
        for(i=0;i<N;i++)                                     //Input of C[][] array
        {
            input:
            for(j=0;j<K;j++)
            {
                cin>>C[i][j];
                if(C[i][j]>M||C[i][j]<1)                                //Input validation
                {
                    cout<<"Invalid input!! Enter the line again.\n";
                    goto input;
                }
            }
        }
        bool correctBox[N][K];                 //This variable is used to store the boolean values. If the arm picks the correct box, then it will be 1 and vice versa.
        int combinations=(int)pow(M,N); //This variable is used to store the number of combinations of the box number
        int minValue,maximised=-1,maxIndex;     //This variable will store the worst case value of each combination

        for(a=0;a<combinations;a++)     //Loop for all the combinations
        {
            for(i=0;i<N;i++)            //Loop to compute the correctBox array
                for(j=0;j<K;j++)
                    correctBox[i][j]=(C[i][j]==(((a/(int)pow(M,i))%M)+1));  // (a/(int)pow(M,i))%M)+1) This expression gives different combinations of the box number.
            minValue=999999;         //Initializing minValue with a large value
            for(int y=0;y<K;y++)        //Loop for finding minValue[a]
            {
                countt=0;
                for(int x=0;x<N;x++)        //Loop for counting the correct boxes selected
                    countt+=(int)correctBox[x][y];
                if(countt<minValue)//Selecting the minimum value of count in the array
                    minValue=countt;
            }
            if(minValue>maximised)
            {
                maximised=minValue;
                maxIndex=a;
            }
        }
//        int maximised=minValue[0],maxIndex=0;   //Variables for optimizing the minValue array
//        for(i=1;i<combinations;i++)             //Loop to traverse all the combinations and to find the maximized minValue index
//        {
//            if(minValue[i]>maximised)           //Choosing the maximized value and maximized index
//            {
//                maximised=minValue[i];
//                maxIndex=i;
//            }
//        }
        cout<<endl;
        for(i=0;i<N;i++)                        //Loop for displaying the maximized combination of output
            cout<<((maxIndex/(int)pow(M,i))%M)+1<<"\t";
        cout<<endl<<endl;
    }
    return 0;
}
