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
        for(i=0;i<N;i++)
        {
            input:
            for(j=0;j<K;j++)
            {
                cin>>C[i][j];
                if(C[i][j]>M||C[i][j]<1)
                {
                    cout<<"Invalid input!! Enter the line again.\n";
                    goto input;
                }
            }
        }
        bool arr[N][K];
        int combinations=(int)pow(M,N);
        int minValue[combinations];
        for(a=0;a<combinations;a++)
        {
            for(i=0;i<N;i++)
                for(j=0;j<K;j++)
                    arr[i][j]=(C[i][j]==(((a/(int)pow(M,i))%M)+1));
            minValue[a]=999999;
            for(int y=0;y<K;y++)
            {
                countt=0;
                for(int x=0;x<N;x++)
                    countt+=(int)arr[x][y];
                if(countt<minValue[a])
                    minValue[a]=countt;
            }
//            cout<<"minValue["<<a<<"]="<<minValue[a]<<endl;
        }
        int maximised=minValue[0],maxIndex=0;;
        for(i=1;i<combinations;i++)
        {
            if(minValue[i]>maximised)
            {
                maximised=minValue[i];
                maxIndex=i;
            }
        }
        cout<<endl;
        for(i=0;i<N;i++)
            cout<<((maxIndex/(int)pow(M,i))%M)+1<<"\t";
        cout<<endl<<endl;
    }
    return 0;
}
