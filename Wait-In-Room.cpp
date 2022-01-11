#include <bits/stdc++.h>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
int type, query, cmd, burn=0, corona=0, cancer=0, dengue=0, general=0, phn, amn, pin;
string login, pass;
int p1 = 0, p2 = 0;
class SeriousPatient{
public :
   string name;
   string login;
   int age;
   string pass;
   string status;
   string address;
   int phone;
   int days;
   int stat;
   string unit;
   int dues;
};

class PrescribedPatient{
public :
   string name;
   string login;
   int age;
   string pass;
   string address;
   int phone;
   int dues;
   int status;
   string doc;
};
 class Doctor{
 public :
    string id;
    string name; 
    string login;
    string pass;
    string expertise;
    string phone ;
    PrescribedPatient patients[10];
    int seat = 10 ;
    int visit = 1500;
    int num = 0;
    int left = seat - num;
    
};

void AddPatient(int ptype, int p1, int p2, SeriousPatient Spatient[], PrescribedPatient patient[]){
    if(ptype==1) {
            cout<<"Log in ID : ";
            cin>>Spatient[p1].login;
            cout<<"Password : ";
            cin>>Spatient[p1].pass;
            cout<<"Patient account for booking a seat has been created.\n";
            p1++;
        }
        else if(ptype==2){
            cout<<"Log in ID : ";
            cin>>patient[p2].login;
            cout<<"Password : ";
            cin>>patient[p2].pass;
            cout<<"Patient account for booking an appointment has been created.\n";
            p2++;
        }
        else cout<<"Invalid Input!\n";
        }
int ReleasePatient(int i, SeriousPatient Spatient[]){
    if(Spatient[i].dues<=0){
    cout<<Spatient[i].name<<" has been released.\n";
    for(int k = i; k < 149; k++) Spatient[k] = Spatient[k+1];
    return 1;
    }
    else {
        cout<<"Have dues! Can not realease!\n";
        return 0;
    }
}
void SeatStatus(){
    cout<<"Seat left in burn unit : "<<20-burn;
    cout<<"\nSeat left in corona unit : "<<50-corona;
    cout<<"\nSeat left in cancer unit : "<<30-cancer;
    cout<<"\nSeat left in dengue unit : "<<30-dengue;
    cout<<"\nSeat left in general unit : "<<20-general<<endl;
}
void DoctorsAvailable(Doctor doctor[]){
    cout<<setw(10)<<"ID"<<setw(20)<<"Name"<<setw(20)<<"Phone No."<<setw(20)<<"Expertise"<<setw(20)<<"Visit"<<setw(20)<<"Seat left\n"<<endl;
    for(int i = 0; i < 15; i++){
        cout<<setw(10)<<doctor[i].id<<setw(20);
        cout<<setw(20)<<doctor[i].name<<setw(20);
        cout<<setw(20)<<doctor[i].phone<<setw(20);
        cout<<setw(20)<<doctor[i].expertise<<setw(20);
        cout<<setw(20)<<doctor[i].visit<<setw(20)<<doctor[i].left<<endl;
        
    }
}
void BookAppointment( int s1, int s2, int i, PrescribedPatient patient [], Doctor doctor[]){
    cout<<"Name : ";
    cin>>patient[s1].name;
    cout<<"Age : ";
    cin>>patient[s1].age;
    cout<<"Phone : ";
    cin>>patient[s1].phone;
    cout<<"Address : ";
    cin>>patient[s1].address;
    patient[s1].status = 1;
    patient[s1].doc = doctor[s2].name;
    patient[s1].dues = doctor[s2].visit;
    doctor[s2].patients[i]=patient[s1];
    doctor[s2].num++;
}

void BookSeat(int u, int s1, SeriousPatient Spatient[]){
    cout<<"Name : ";
    cin>>Spatient[s1].name;
    cout<<"Age : ";
    cin>>Spatient[s1].age;
    cout<<"Phone : ";
    cin>>Spatient[s1].phone;
    cout<<"Address : ";
    cin>>Spatient[s1].address;
    cout<<"Number of days : ";
    cin>>Spatient[s1].days;
    Spatient[s1].status="Admitted";
    Spatient[s1].stat = 1;
    switch(u){
        case 1 :
           Spatient[s1].unit = "Burn";
           burn++;
           break;
        case 2 : 
          Spatient[s1].unit = "Corona";
          corona++;
          break;
        case 3 : 
          Spatient[s1].unit = "Cancer";
          cancer++;
          break;
        case 4 : 
          Spatient[s1].unit = "Dengue";
          dengue++;
          break;
        case 5 : 
          Spatient[s1].unit = "General";
          general++;
          break;
        default : cout<<"Invalid!";   
    }
    Spatient[s1].dues = 20000 + Spatient[s1].days*2000;
}

void DisplayPatient(int q,int ptype, SeriousPatient Spatient, PrescribedPatient patient ){
if(ptype==1){
  cout<<"Patient's info : \n";
  cout<<"Name : "<<patient.name<<endl;
  cout<<"Age  : "<<patient.age<<endl;
  cout<<"Phone : "<<patient.phone<<endl;
  cout<<"Address : "<<patient.address<<endl;
  cout<<"Dues : "<<patient.dues<<endl;
  if(q!=1) cout<<"Precribed Doctor : "<<patient.doc<<endl;
}
else if(ptype==2){
  cout<<"Patient's info : \n";
  cout<<"Name : "<<Spatient.name<<endl;
  cout<<"Age  : "<<Spatient.age<<endl;
  cout<<"Phone : "<<Spatient.phone<<endl;
  cout<<"Address : "<<Spatient.address<<endl;
  cout<<"Unit : "<<Spatient.unit<<endl;
  cout<<"Dues : "<<Spatient.dues<<endl;
  cout<<"Status : "<<Spatient.status<<endl;
}
else cout<<"Invalid Input!\n";
}
void DisplayDoctor(int num, int i, Doctor doctor[]){
    SeriousPatient Spatient;
    if(num>0) {
        cout<<doctor[i].name<<"s Patientlist : \n";
        for(int j = 0; j<num; j++){
           cout<<"#"<<j+1<<endl;
           DisplayPatient(1,1,Spatient,doctor[i].patients[j]);
           cout<<endl;
        }
    }
    else cout<<"No patient found for "<<doctor[i].name<<"."<<endl;
}
void OnlinePayment(int ptype, int i, SeriousPatient Spatient[], PrescribedPatient patient[]){
    cout<<"Bkash Phone No. : ";
    cin>>phn;
    cout<<"Amount : ";
    cin>>amn;
    cout<<"PIN : ";
    cin>>pin;
    if(ptype==1){
        patient[i].dues-=amn;
        cout<<patient[i].name<<"'s due is "<<patient[i].dues<<endl;
    }
    else {
        Spatient[i].dues-=amn;
        cout<<Spatient[i].name<<"'s due is "<<Spatient[i].dues<<endl;
    }
}
int main() {
    PrescribedPatient patient [150];
    SeriousPatient Spatient [150];
    Doctor doctor [15];
    ifstream infile;
    string ph,idn,st,vis,nm;
    infile.open("input.txt");
    if(infile.fail()) cout<<"Error opening the file.\n";
    else {
        for(int i = 0; i< 15; i++){
            infile>>doctor[i].id;
            infile>>doctor[i].name;
            infile>>doctor[i].login;
            infile>>doctor[i].pass;
            infile>>doctor[i].phone;
            infile>>doctor[i].expertise;
        }
    }
    while(1){
    cout<<"Log in with :\n1. Doctor's account\n2. Patient's account\n3. Create patient account\n4. Exit\n";
    cin>>type;
    if(type==1){
        int c,ds,t;
    while(1){
        t = 0;
        cout<<"Log In ID : ";
        cin>>login;
        cout<<"Password : ";
        cin>>pass;
        for( ds = 0; ds < 15; ds++) {
            if(doctor[ds].pass.compare(pass)==0 || doctor[ds].login.compare(login)==0){
                t++;
                break;
            }
        }
    if(t==0){
        cout<<"Invalid Password!\nEnter : \n1.To try again\n2. Back to previous menue\n";
        cin>>c;
        if(c==2) break;
    }
    if(t!=0) break;
    }
    if(t!=0 || c!=2){
    while(1){
    cout<<"1. To display doctor's status.\n2. To exit\n";
    cin>>cmd;
    if(cmd==1) {
       
       DisplayDoctor(doctor[ds].num,ds,doctor);
    }
    else if(cmd==2) break;
    else cout<<"Invalid input.\n";
    }
    }
    }
    
    else if(type==2){
    int ptype,t,c,psn;
    cout<<"Enter :\n1. To log in with patient account for appoinment\n2. To log in with patient account for seat-booking\n";
    cin>>ptype;
    while(1){
        cout<<"Log In ID : ";
        cin>>login;
        cout<<"Password : ";
        cin>>pass;
        cout<<endl;
        c=0;
        for(int i = 0; i<150; i++){
            if((Spatient[i].login.compare(login)==0 && Spatient[i].pass.compare(pass)==0 && ptype==2) ||(patient[i].login.compare(login)==0 && patient[i].pass.compare(pass)==0 && ptype==1)) {
                c++;
                psn=i;
                break;
        }
        }
    if(c!=0) break;
    else {
            cout<<"Invalid login id or pass!\nEnter :\n1. To retry\n2. Back to previus menu\n";
            cin>>t;
            if(t==2) break;
        }
    }
    if(t!=2){
    if(ptype==1)  {
    while(1){
    cout<<"Query :\n1. Patient details\n2. Available Doctors\n3. Book an appoinment\n4. Online Payment\n5. Exit\n";
    cin>>query;
    if(query==1) {
      SeriousPatient s;
      if(patient[psn].status==1){
      DisplayPatient(0,ptype,s,patient[psn]);
      }
      else cout<<"Patient has not booked any appoinment.\n";
    }
    else if(query==2) 
        DoctorsAvailable(doctor);
    else if(query==3) {
        if(patient[psn].dues>0) cout<<"No new booking possible.\n";
        else{
        int n;
        cout<<"Enter Doctor's serial : ";
        cin>>n;
        if(patient[psn].doc.compare(doctor[n-1].name)==0) {
            patient[psn].dues = 1500;
            cout<<"Appoinment set again for "<<patient[psn].doc<<".\n";
        }
        else{
        int pn = doctor[n-1].num;
        BookAppointment(psn,n-1,pn,patient,doctor);
        cout<<"Appoinment set for "<<patient[psn].doc<<".\n";
        }
        }
    }
    else if(query==4){
        OnlinePayment(ptype, psn, Spatient, patient );
    }
    else if(query==5) break;
    else cout<<"Invalid Input.\n";
    }
    }
    else if(ptype==2){
        while(1){
    cout<<"Query :\n1. Patient details\n2. Seat status\n3. Book a seat\n4. Online Payment\n5. Release a patient\n6. Exit\n";
    cin>>query;
        if(query==1){
          PrescribedPatient s;
          if(Spatient[psn].stat==1){
          DisplayPatient(0,ptype,Spatient[psn],s);
          }
          else cout<<"Patient has not booked any seat.\n";
        }
    else if(query==2) SeatStatus();
    else if(query==3) {
        if(Spatient[psn].dues>0) cout<<"No new booking possible.\n";
        else{
        int n;
        cout<<"Enter :\n1. Burn\n2. Corona\n3. Cancer\n4. Dengue\n5. General\n";
        cin>>n;
        BookSeat(n,psn,Spatient);
        }
    }
    else if(query==4) {
       OnlinePayment(ptype, psn, Spatient, patient );
    }
    else if(query==5){
        if(ReleasePatient(psn,Spatient)) {
            break;
            break;
        }
    } 
    else if(query==6) break;
    else cout<<"Invalid Input.\n";
        }
    }
    }
    }
    else if(type==3){
        if(p1>=150 || p2>=150) cout<<"No more patient account can't be opened.\n";
        else{
        int ptype;
        cout<<"Enter :\n1. Patient account to book a seat\n2. Patient account to book an appointment\n";
        cin>>ptype;
        AddPatient(ptype,p1,p2,Spatient,patient);
    }
    }
    else if(type==4) break;
    else cout<<"Invalid Input!\n";
    }
}

