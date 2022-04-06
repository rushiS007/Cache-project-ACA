#include <iostream>
#include<vector>
using namespace std;

//defining registers
int R[32]={0};
// R[0]=0;

vector<string>s;
int pf=0,pd=0,pe=0;
string line="";
string opcode="";
vector<string>op;
int cycles=0;
int sz;

// ADD R1, R2, R3
void ADD (string R1,string R2,string R3){
    string r1=R1.substr(1,R1.length()-1);
    string r2=R2.substr(1,R2.length()-1);
    string r3=R3.substr(1,R3.length()-1);
    int n1=stoi(r1);
    int n2=stoi(r2);
    int n3=stoi(r3);
    R[n1]=R[n2]+R[n3];
    cout<<R[n1]<<" "<<R[n2]<<" "<<R[n3]<<endl; 
}

void ADDI (string R1,string R2,string R3){
    string r1=R1.substr(1,R1.length()-1);
    string r2=R2.substr(1,R2.length()-1);
    // string r3=R3.substr(1,R3.length()-1);
    int n1=stoi(r1);
    int n2=stoi(r2);
    int n3=stoi(R3);
    R[n1]=R[n2]+n3;
    cout<<R[n1]<<" "<<R[n2]<<endl; 
}

void SUB (string R1,string R2,string R3){
    string r1=R1.substr(1,R1.length()-1);
    string r2=R2.substr(1,R2.length()-1);
    string r3=R3.substr(1,R3.length()-1);
    int n1=stoi(r1);
    int n2=stoi(r2);
    int n3=stoi(r3);
    R[n1]=R[n2]-R[n3];
    cout<<R[n1]<<" "<<R[n2]<<" "<<R[n3]<<endl; 
}

void MUL (string R1,string R2,string R3){
    string r1=R1.substr(1,R1.length()-1);
    string r2=R2.substr(1,R2.length()-1);
    string r3=R3.substr(1,R3.length()-1);
    int n1=stoi(r1);
    int n2=stoi(r2);
    int n3=stoi(r3);
    R[n1]=R[n2]*R[n3];
    cout<<R[n1]<<" "<<R[n2]<<" "<<R[n3]<<endl; 
}


//under construction 
void DIV (string R1,string R2,string R3){
    string r1=R1.substr(1,R1.length()-1);
    string r2=R2.substr(1,R2.length()-1);
    string r3=R3.substr(1,R3.length()-1);
    int n1=stoi(r1);
    int n2=stoi(r2);
    int n3=stoi(r3);
    R[n1]=R[n2]/R[n3];
    cout<<R[n1]<<" "<<R[n2]<<" "<<R[n3]<<endl; 
}

void AND (string R1,string R2,string R3){
    string r1=R1.substr(1,R1.length()-1);
    string r2=R2.substr(1,R2.length()-1);
    string r3=R3.substr(1,R3.length()-1);
    int n1=stoi(r1);
    int n2=stoi(r2);
    int n3=stoi(r3);
    R[n1]=R[n2]&R[n3];
    cout<<R[n1]<<" "<<R[n2]<<" "<<R[n3]<<endl; 
}

void ANDI (string R1,string R2,string R3){
    string r1=R1.substr(1,R1.length()-1);
    string r2=R2.substr(1,R2.length()-1);
    // string r3=R3.substr(1,R3.length()-1);
    int n1=stoi(r1);
    int n2=stoi(r2);
    int n3=stoi(R3);
    R[n1]=R[n2]&n3;
    cout<<R[n1]<<" "<<R[n2]<<endl; 
}

void OR (string R1,string R2,string R3){
    // cout<<R1<<" "<<R2<<" "<<R3<<endl;
    string r1=R1.substr(1,R1.length()-1);
    string r2=R2.substr(1,R2.length()-1);
    string r3=R3.substr(1,R3.length()-1);
    int n1=stoi(r1);
    int n2=stoi(r2);
    int n3=stoi(r3);
    // cout<<n1<<" "<<n2<<" "<<n3<<endl;
    R[n1]=R[n2]|R[n3];
    cout<<R[n1]<<" "<<R[n2]<<" "<<R[n3]<<endl; 
}

void ORI (string R1,string R2,string R3){
    string r1=R1.substr(1,R1.length()-1);
    string r2=R2.substr(1,R2.length()-1);
    // string r3=R3.substr(1,R3.length()-1);
    int n1=stoi(r1);
    int n2=stoi(r2);
    int n3=stoi(R3);
    R[n1]=R[n2]|n3;
    cout<<R[n1]<<" "<<R[n2]<<endl; 
}

void XOR (string R1,string R2,string R3){
    string r1=R1.substr(1,R1.length()-1);
    string r2=R2.substr(1,R2.length()-1);
    string r3=R3.substr(1,R3.length()-1);
    int n1=stoi(r1);
    int n2=stoi(r2);
    int n3=stoi(r3);
    R[n1]=R[n2]^R[n3];
    cout<<R[n1]<<" "<<R[n2]<<" "<<R[n3]<<endl; 
}

void XORI (string R1,string R2,string R3){
    string r1=R1.substr(1,R1.length()-1);
    string r2=R2.substr(1,R2.length()-1);
    // string r3=R3.substr(1,R3.length()-1);
    int n1=stoi(r1);
    int n2=stoi(r2);
    int n3=stoi(R3);
    R[n1]=R[n2]^n3;
    cout<<R[n1]<<" "<<R[n2]<<endl; 
}

void NOR (string R1,string R2,string R3){
    string r1=R1.substr(1,R1.length()-1);
    string r2=R2.substr(1,R2.length()-1);
    string r3=R3.substr(1,R3.length()-1);
    int n1=stoi(r1);
    int n2=stoi(r2);
    int n3=stoi(r3);
    R[n1]= ~(R[n2]|R[n3]);
    cout<<R[n1]<<" "<<R[n2]<<" "<<R[n3]<<endl; 
}

void Fetch(int sz){
    if(pf<sz)
    line=s[pf];
}

void Decode(){
    
    int i=0;
    opcode="";
    op.clear();
    for(;i<line.length() && line[i]!=' ';i++){
        opcode+=line[i];
    }
    i++;
    string str="";
    while(i<line.length()){
            if(line[i]==' ' || line[i]==',' || i==line.length()-1){
                if(i==line.length()-1)str+=line[i];
                if(str!="" && str!="," )
                op.push_back(str);
                str="";
            }
            else{
                str+=line[i];
            }
            i++;
    }
}

void Execute(string opcode, vector<string>&op){
        cout<<opcode<<endl;
        cout<<op[0]<<" "<<op[1]<<" "<<op[2]<<endl;
        if(opcode== "ADD"){   
            ADD(op[0],op[1],op[2]);
        }
        else if(opcode=="ADDI"){
            ADDI(op[0],op[1],op[2]);
        }
        else if(opcode=="SUB"){
            SUB(op[0],op[1],op[2]);
        }
        else if(opcode=="MUL"){
            MUL(op[0],op[1],op[2]);
        }
        else if(opcode=="DIV"){
            DIV(op[0],op[1],op[2]);
        }
        else if(opcode=="AND"){
            AND(op[0],op[1],op[2]);
        }
        else if(opcode=="ANDI"){
            ANDI(op[0],op[1],op[2]);
        }
        else if(opcode=="OR"){
            OR(op[0],op[1],op[2]);
        }
        else if(opcode=="ORI"){
            ORI(op[0],op[1],op[2]);
        }
        else if(opcode=="XOR"){
            XOR(op[0],op[1],op[2]);
        }
        else if(opcode=="XORI"){
            XORI(op[0],op[1],op[2]);
        }
        else if(opcode=="NOR"){
            NOR(op[0],op[1],op[2]);
        }
        else if(opcode=="J"){
            
        }

}

void Cycle(){
    cycles++;
    cout<<cycles<<endl;
    if(opcode!="" && pe<sz)
    {   cout<<"Executing...\n";
        Execute(opcode,op);
        pe++;
    }
    else{
        cout<<"Not executing...\n";
    }
    if(line!="" && pd<sz)
    {   cout<<"Decoding...\n";
        Decode();
        pd++;
    }
    else{
        cout<<"Not decoding...\n";
    }
    if(pf<sz){
    Fetch(sz);
    pf++;
    cout<<"Fetching...\n";
    }
    else{
        cout<<"Not fetching...\n";
    }
}

int main(){

    string line; 
    
    while(getline(cin,line)){
        if(line=="")break;
        s.push_back(line);
    }
    sz=s.size();
    cout<<sz<<endl;
    while(sz!=pe){
    Cycle();
    cout<<pf<<" "<<pd<<" "<<pe<<endl;
    }

//# factorial of 5
// ADDI $1, $0, 6
// ADDI $2, $0, 1
// ADDI $10, $0, 1
// LOOP:
// BEQ $1, $2, END
// MUL $10, $10, $2
// ADDI $2, $2, 1
// J LOOP
// *END:

    }



