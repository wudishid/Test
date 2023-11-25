#include <iostream>
using namespace std;

template<typename T,int age=5> class A;


template<typename T,int age>
class A
{

public:
    A()
    {
        
    }
    
    A(T InVar):Var(InVar)
    {
        cout<<"Construct"<<Var<<" Age Is "<<age<<endl;
    }

    template<typename E>
    A(const A<E,age>& rhs)
    {
        Var=static_cast<T>(rhs.Var);
        cout<<"Construct"<<Var<<endl;
    }
    
    template<typename E>
    A<T,age>& operator=(const A<E,age>& rhs);
    
    T Var;
};


template<typename T,int age=7>
class XiaoA:public A<T,age>
{
public:
    XiaoA(T InVar):A<T,age>(InVar)
    {
        cout<<"XiaoA "<<this->Var<<endl;
    }
};



template<>
class A<char*>
{
public:
    A(char* InChar):cha(InChar)
    {
        cout<<"Special A Name Is "<<InChar<<endl;
    }

    void Show();

    char* cha;
};

template<class T,int age>
template<class E>
A<T,age>& A<T,age>::operator=(const A<E,age>& rhs)
{
    Var+=static_cast<T>(rhs.Var);
    return *this;
}

void A<char*>::Show()
{
    cout<<"Show"<<cha<<endl;
}

template<typename T,int number=12>
T AddANumber(T InVar)
{
    InVar+=number;
    return InVar;
}

template<>
char* AddANumber<char*>(char* InVar)
{
    cout<<InVar<<endl;
    return nullptr;
}

void AddANumber(char* InVar)
{
    cout<<"Normal "<<InVar<<endl;
}

template<typename T>
ostream& operator<<(ostream& os,const A<T>& rhs)
{
    os<<"Read At:"<<rhs.age<<endl;
    return os;
}

int main(int argc, char* argv[])
{
   cout<<"Hellow"<<endl;
}
