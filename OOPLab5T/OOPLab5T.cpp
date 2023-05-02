#include<iostream>
#include<string>
using namespace std;
class Liquid{
protected:
string name;
double density;
public:
Liquid(){
    name= " ";
    density=0.0;
}
Liquid(string Name , double Density){
this->name=name;
this->density=Density;
}
~Liquid(){
    cout<<" Деструктор "<<endl;
}
    double GetDensity(){
        return density;
    }
    void SetDensity(double density){
    this->density=density;
}
    string GetName(){
        return name;
    }
    void SetName(string Name){
    this->name=Name;
}
    friend ostream& operator<<(ostream& os,Liquid Info){
    os<<"Name : "<<Info.name<<endl;
    os<<"Density : "<<Info.density<<endl;
    return os;
}
void print(){
    cout<<"Name : "<<name<<endl;
    cout<<"Density : "<<density<<endl;
}
};
class Alcohol:public Liquid{
private:
double AlcoContent;
public:
Alcohol(){
    AlcoContent=0.0;
}
Alcohol(string Name , double Density, double AlcoContent):Liquid(name,density){
this->AlcoContent=AlcoContent;
}
void print(){
    cout<<"Name : "<<name<<endl;
    cout<<"Density : "<<density<<endl;
    cout<<"Alcohol Content :"<<AlcoContent<<" % "<<endl;
}
 friend ostream& operator<<(ostream& os,Alcohol Info){
    os<<"Name : "<<Info.name<<endl;
    os<<"Density : "<<Info.density<<endl;
    os<<"Alcohol Content :"<<Info.AlcoContent<<" % "<<endl;
    return os;
 }
 void SetAlco(double Alco){
this->AlcoContent=Alco;
 }
};
    
void Exercise1(){
    Liquid Gleb;
    Gleb.print();
    Gleb.SetDensity(0.7);
    Gleb.SetName("Jivchik");
    cout<<Gleb;
    Alcohol Allcash;
    cout<<Allcash;
    Allcash.SetName("Baltika");
    Allcash.SetDensity(0.5);
    Allcash.SetAlco(40);
    Allcash.print();
}
class Wheel{
    private:
    double diametr;
    public:
    Wheel(double diametr){
        this->diametr=diametr;
    }
    double GetDiametr(){
        return diametr;
    }
    void SetDiametr(double diametr){
        this->diametr=diametr;
    }
};
class Bicycle:public Wheel{
    private:
    int transmission;
    public:
    Bicycle(double diametr , int trans):Wheel(diametr){
        this->transmission=trans;
    }
    int GetTrans(){
        return transmission;
    }
    void SetTrans(int trans){
        this->transmission=trans;
    }
};

class Car:public Bicycle{
    private:
    string Mark;
    public:
    Car(double diametr , int trans , string Mark):Bicycle(diametr,trans){
        this->Mark=Mark;
    }
    string GetMark(){
        return Mark;
    }
    void SetMark(string Mark){
        this->Mark=Mark;
    }
};
void Exercise2(){
    Car Mercedes(0.3 , 6 , "Mersedes");
    cout<<"Mark : "<<Mercedes.GetMark()<<" \t "<<"Transmission : "<<Mercedes.GetTrans()<<" \t "<<"Wheel Diametr : "<<Mercedes.GetDiametr()<<endl;
}
    class Person{
        protected :
        string name;
        int Age;
        public:
        Person(){
            name=" ";
            Age=0;
        }
        Person(string name , int Age){
            this->name=name;
            this->Age=Age;
        }
        string GetName(){
            return name;
        }
        void SetName(string name){
            this->name=name;
        }
        void SetAge(int Age){
            this->Age=Age;
        }
        virtual void print(){
            cout<<endl;
            cout<<"Name :"<<name<<endl;
            cout<<"Age :"<<Age;
        }
        Person& operator=(Person& Other){
            if(this!=&Other){
                name=Other.name;
                Age=Other.Age;

            }
            return *this;
        }
        virtual void Write(){
            cout<<endl;
            cout<<"Add your Name :"<<endl;
            cin.ignore();
            getline(cin,name);
            cout<<"Add your Age :"<<endl;
            cin>>Age;
            cin.ignore();
        }
        
    };
    class Teacher:public Person{
        private:
        string subject;
        public:
        Teacher(){
            subject= " ";
        }
        Teacher(string name, int Age , string subject):Person(name,Age){
            this->subject=subject;
        }
        ~Teacher(){
            cout<<"Деструктор "<<endl;
        }
        void print() override{
            cout<<"Name : "<<name<<endl;
            cout<<"Age : "<<Age<<endl;
            cout<<"Subject :"<<subject<<endl;
        }
        void Write()override{
            Person::Write();
            cout<<"Add Subject :"<<endl;
            cin.ignore();
            getline(cin,subject);
        }
        Teacher& operator= (Teacher& other){
            if(this!=&other){
                Person::operator=(other);
                subject=other.subject;
            }
            return *this;
        }

    };
void Exercise3(){
    Person Who;
    Who.print();
    cout<<endl;
    Who.Write();
    Who.print();
    cout<<endl;
    Teacher teacher("John", 35, "Math");
    teacher.print();
    cout<<endl;
    teacher.Write();
    teacher.print();
}
int main(){
    int n;
    cout<<"Choose Exercise :"<<endl;
    if(n==1){
        Exercise1();
    }
    if(n==2){
        Exercise2();
    }
    if(n==3){
        Exercise3();
    }
    return 0;
}
