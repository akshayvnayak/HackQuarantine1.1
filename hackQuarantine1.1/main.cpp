#include <iostream>
#include<math.h>

using namespace std;




int main()
{
    int T,N,K,M,i,j,k,a,countt;
    cin>>T;
    for(int t=0;t<T;t++)
    {
//        cout<<"s";
        nmk:
        cin>>N>>M>>K;
        if(N>500||N<0||M<1||M>9||K<1||K>1000)
        {
            cout<<"Invalid input!! Enter the line again.\n";
            goto nmk;
        }
        int c[N][K];
        for(i=0;i<N;i++)
        {
            inp:
            for(j=0;j<K;j++)
            {
                cin>>c[i][j];
                if(c[i][j]>M||c[i][j]<1)
                {
                    cout<<"Invalid input!! Enter the line again.\n";
                    goto inp;
                }
            }
        }
//        int a[N][N][N];
//        for(int a=)
//        for(i=0;i<N;i++)
//            for(j=0;j<N;j++)
//                for(k=0;k<N,k++)
//                    a[i][j][k]=k+1;


//        for(i=0;i<N;i++)
//            for(j=0;j<K;j++)
//            {
//
//            }
        bool arr[N][K];
        int combinations=(int)pow(M,N);
        int ans[N],minValue[combinations];
        for(a=0;a<combinations;a++)
        {
            for(i=0;i<N;i++)
            {
                for(j=0;j<K;j++)
                {
                    arr[i][j]=(c[i][j]==(((a/(int)pow(M,i))%M)+1));
//                    if(c[i][j]==((a/(int)pow(M,i))%M)+1)
//                    {
//                        countt++;
//                    }

//                cout<<((a/(int)pow(M,i))%M)+1<<"\t";
//            cout<<endl;
                }
            }
            minValue[a]=999999;
            for(int y=0;y<K;y++)
            {
                countt=0;
                for(int x=0;x<N;x++)
                {
                    countt+=(int)arr[x][y];
                }
//                cout<<countt<<"\t";
                if(countt<minValue[a])
                {
//                    cout<<"sssss";
                    minValue[a]=countt;
//                    for(int z=0;z<N;z++)
//                        ans[z]=c[z][y];
                }
            }
//            cout<<"minValue["<<a<<"]="<<minValue[a]<<endl;
//            for(int x=0;x<N;x++)
//                {
//                    cout<<endl;
//                    for(int y=0;y<K;y++)
//                        cout<<arr[x][y]<<"\t";// <<(((a/(int)pow(M,i))%M)+1)<<"="<<c[x][y]
//                }
//                cout<<endl;
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
