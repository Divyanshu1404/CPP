for (int i=0;i<n/2;i++){
            for (int j=0;j<n+2;j++){
                cout<<"-";
            }
            for (int j=0;j<n;j++){
                if(i==0||j==0){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
            }
            cout<<endl;