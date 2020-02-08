#include <bits/stdc++.h>
//#include <power.h>

using namespace std;


//pset


string temp1;



string powerset(string p);
void setcommadelete(string t);
string binary(int a);
string genpset(string l);


//nfatodfa




string nfatransition_table[4][3];
string dfatransition_table[16][3];
string start_state;
string end_state;


void test();
string unio(string temp);
bool isduplicate(string arr[],string temp,int k);
string tran_f(string ch1,char ch2);

int main()

{

        string t;
        string state_set;
        string pset;

    ifstream in;
    //in.open("in_table1.txt");
    in.open("12.txt");
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            in>>t;

            nfatransition_table[i][j]=t;

        }
    }

    in>>start_state;
    in>>end_state;

    in.close();


    state_set+="{";
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            cout<<nfatransition_table[i][j] << " ";

        }
        cout<<endl;
    }
    cout<<"start state:"<< start_state << endl << "end_state:"<<end_state << endl;


     for(int i=0; i<4; i++){
        //for(int j=0; j<3; j++){
            cout<<nfatransition_table[i][0] << " ";
            state_set+=nfatransition_table[i][0];

            if(i<=2){

            state_set+=",";
            }

       // }
        cout<<endl;
    }
    state_set+="}";

    cout<<state_set<<endl;
    pset = powerset(state_set);
    cout<<pset;
    int table_cont=0;
    int l=1;
    for(int n=0;n<16;n++){

        string temp;
    for(int i=l;i<pset.length()-1;i++){
        if(pset[i]!='}'){
            temp+=pset[i];
            //cout<<temp;
        }
        else if(pset[i]=='}'){
            temp+=pset[i];
            l=i+2;
            break;
            //cout<<temp;
        }
    }

        dfatransition_table[n][0]=temp;

        cout<<dfatransition_table[n][0]<<endl;
    }
    for(int n=0;n<15;n++){
        dfatransition_table[n][1]=(tran_f(dfatransition_table[n][0],'0'));
        dfatransition_table[n][2]=(tran_f(dfatransition_table[n][0],'1'));//<<endl;
    }
    cout<<endl<<endl;
    for(int n=0;n<15;n++){
       cout<<dfatransition_table[n][0]<<"   "<<dfatransition_table[n][1]<<"   "<<dfatransition_table[n][2]<<endl;
    }
    //cout<<tran_f("{r}",'1');

}


///------------extended transition function------------------

string tran_f(string ch1,char ch2)
{
    int k=0;
    int count=0;
    string state_set[10];
    string outset[10];
    string outset_comb;
    string outset_comb2;
    for(int i=0;i<ch1.length();i++){
        if(ch1[i] == '{' || ch1[i] == ',' ||ch1[i] == '}'){

        }
        else{
            state_set[count]=ch1[i];
            count++;
        }
    }
    for(int n=0;n<count;n++){
        cout<<state_set[n]<<endl;
    }
    //cout<<ch1<<endl;

    for(int n=0;n<count;n++){

    for(k =0; k<4; k++){
        if(nfatransition_table[k][0] == state_set[n]){
            if(ch2 == '0'){
                outset[n]= nfatransition_table[k][1];
                cout<<endl<<outset[n];
            }
            else{
                outset[n]= nfatransition_table[k][2];
            }
            //break;
        }
    }

    }
    for(int n=0;n<count;n++){

        if(n<count-1){
            outset_comb+=outset[n];
            outset_comb+=",";


        }
        else{
            outset_comb+=outset[n];
        }
    }
    cout<<outset_comb;
    outset_comb2+="{";
    for(int n=1;n<outset_comb.length()-1;n++){
        if(outset_comb[n] == '{' || outset_comb[n] == '}'){

        }
        else{
            outset_comb2+=outset_comb[n];
        }
    }
    outset_comb2+="}";
    cout<<endl<<outset_comb2;
    //return outset_comb2;
    return unio(outset_comb2);


}

///-------------------union----------------
string unio(string temp)
{
    string temp1;
    temp1=temp;
    for(int i =0;i<temp1.length();i++){
        for(int j =i+1;j<temp1.length()-1;j++){
            if(temp1[i] == ','){
                temp1[i]='1';
            }
            if(temp1[i] == temp1[j]){
                temp1[j]='1';
            }
        }
    }
    string temp2;
    temp2+="{";
    for(int i =1;i<temp1.length()-1;i++){
        if(temp1[i]!='1'){
            temp2+=temp1[i];
            temp2+=",";
        }
    }
    temp2.erase(temp2.length()-1,temp2.length());
    temp2+="}";
    return temp2;
}




//powerset


///----------power  set function-------------


string powerset(string p)
{
    setcommadelete(p);
    return genpset(temp1);

}

///-----------------generate set without comma------------------

void setcommadelete(string t)
{
        for(int i=0;i<t.length();i++){
            if(t[i]!=','&&t[i]!='}'&&t[i]!='{'){
                temp1+=t[i];
            }
        }
        //cout<<temp1<<endl;
}


///----------------generate binary value as string------------------

string binary(int a)
{
    //cout<<"c";
    string temp3;
    string k;
    int x=2;
    int r;
    int result=1;
    while(1){
        r=a%x;
        //cout<<r;
        a=a/x;

        if(r == 0){
           k+="0";
           //cout<<k<<endl;
        }
        else if(r==1){
            k+="1";
        }
        if(a == 0){
            break;
        }
    }
    //cout<<k<<k[k.length()]<<"c"<<endl;

    if(k.length() == temp1.length()){
        for(int i=k.length()-1;i>=0;i--){
            temp3+=k[i];
        }
    }
    else{
        int v=temp1.length()-k.length();
        for(int i=0;i<v;i++){
            temp3+="0";
        }
        for(int i=k.length()-1;i>=0;i--){
            temp3+=k[i];
        }
    }

    //cout<<temp3<<endl;
    return temp3;
}

///---------------------generate power set-------------------

string genpset(string l)
{
    string temp2[100];
    string temp4,temp5,temp6;
    int ne=l.length(),f=1,i;
    for(i=1;i<pow(2,ne);i++){
        string bin = binary(i);
        for(int j=0;j<bin.length()&&f;j++){
            if(bin[j] == '1'){
                //cout<<
                temp2[i-1]+=l[j];
            }
        }
    }
    temp2[i-1]+="{}";
    //cout<<"start"<<endl;
    temp4+="{";
    for(i=0;i<pow(2,ne);i++){
        temp4+="{";
        temp4+=temp2[i];
        temp4+="}";
        temp4+=",";


    }


    for(int y=temp4.length()-5;y<=temp4.length();y++){
        temp4[y]=temp4[y+1];
    }
    //temp4.setlenth()
    temp4[temp4.length()-2]='`';
    for(int y=0;y<temp4.length() && temp4[y]!='`';y++){
        temp5+=temp4[y];
    }
    for(int y=0;y<temp5.length();y++){
        if(temp5[y] == '{'||temp5[y] == '}'||temp5[y] == ','){
            temp6+=temp5[y];
        }
        else if(temp5[y+1]!='}'){
            temp6+=temp5[y];
            temp6+=",";
        }
        else{
            temp6+=temp5[y];
        }
    }

    //cout<<temp6<<endl;
    return temp6;

}



