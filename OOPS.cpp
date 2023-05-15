#include<iostream>
using namespace std;
// all members are private by default
    //access modifier : private
    // public , protected 
class abstractemployee
{
    virtual void AskForPromotion()=0;
    //creating like this will allow the class definer to set the rule
    // according to him.
};
   
class employee:abstractemployee
{  
   private:
   string Company;
   int Age;
   protected:
   string Name;
   public:
   // setters and getters are public and can be accessed by anyone 
   void setName(string name)
   {
     Name=name;
   }
   string getName()
   {
    return Name;
   }
   void setCompany(string company)
   {
     Company=company;
   }
   string getCompany()
   {
    return Company;
   }
   void setAge(int age)
   {
    if (age>=18)
     {Age=age;}// we can apply certain rules
   }
   int getAge()
   {
    
    return Age;
   }
   void IntroduceYourself()//class method
   {
     cout<<"Hello my name is "<<Name<<"."
     <<endl<<"I work for "<<Company<<".My age is "<<Age<<"."<<endl;
   }
   //constructor
   employee (string name,string company,int age)
   {
      Name=name;
      Company=company;
      Age=age;
   }
   //abstraction
   //implementation of the method
   void AskForPromotion()
   {
        if (Age>20)
        cout<<Name<<" got promoted."<<endl;
        else
        cout<<Name<<" cannot be promoted."<< endl;;
   }
   virtual void work()
   {
    cout<<Name<<" is checking email"<<endl;
   }
};//class is just like the blueprint for the user defined data type 
//class  developer:employee//developer becomes the child class  and em
//now we make it public to access ask for promotion
// to allow inheritance public
class  developer:public employee{
    public:
    string favProgammingLanguage;
    //creating constructor
    developer(string name,string company,int age,string language):
    employee(name,company,age)
    {
       //now we need not to worry about the name company age
       // cause its already known by the employee class 
       favProgammingLanguage=language;
    }
    void FixBug()
    {
        cout<<getName()<<" fixed bug using "<<favProgammingLanguage<<endl;
        //cout<<Name<<" fixed bug using "<<favProgammingLanguage<<endl;
        //will not work as the name is private here
        //now we will try to make it work
        cout<<Name<<" fixed bug using "<<favProgammingLanguage<<endl;
    }

    // performing polymorphism
    void work()
    {
      cout<<Name<<" is writing code"<<endl;
    }
};

//now we are creating one more inherited class
class teacher:public employee{
    public:
    string Subject;
    
    teacher(string name,string company,int age,string subject):
    employee(name,company,age)
    {
        Subject=subject;
    }
    void prepareLesson()
    {
        cout<<Name<<" is preparing from "<<Subject<<"."<<endl;
    }
    void work()
    {
      cout<<Name<<" is teaching the students "<<Subject<<endl;
    }

};
int main()
{
    /*employee employee1;
    employee1.Name="Saksham";//accessed using dot operator
    employee1.Company="Amazon";
    employee1.Age=19;
    employee1.IntroduceYourself();
    employee employee2;
    employee2.Name="Niharika";//accessed using dot operator
    employee2.Company="Microsoft";
    employee2.Age=19;
    employee2.IntroduceYourself();*/

employee e1("Saksham","Amazon",29);
//e1.IntroduceYourself();
employee e2("Niharika","Microsoft",19);
//e2.IntroduceYourself();
// Now we everytime need to create a new employee

// constructor : is a special type of fucntion/method that is evoked when
// a object of the class is created.

/* Rules for defining constructors
   1.name of the constructor should be similar to the class name.
   2.constructor must be public
   3.cosntructor must not have any return type.*/

/* four basic principles of OOPS
    encapsulation
    abstraction 
    inheritance 
    polymorphism
*/

// ENCAPSULATION : hidden
    //e1.Name="Saksham"; we cannot access this as its private now !
    /*e1.setAge(20);
    e1.IntroduceYourself();
    e2.setName("Niharika Sharma");
    cout<<"The name of the second employee is "<<e2.getName()<<endl;*/


// ABSTRACTION : hiding complex things using simple procedure
    //e1.AskForPromotion();
    //e2.AskForPromotion();
  

//INHERITANCE : creation of parent and child class

   developer d1("Antriksh","Google",21,"c++");
   /*d1.FixBug();
   d1.AskForPromotion();*/

   teacher t1("Suvrt","JUIT",45,"Hindi");
   /*t1.prepareLesson();
   t1.IntroduceYourself();
   t1.AskForPromotion();*/


   //POLYMORPHISM : the most common use of the polymorphism is when a 
   // parent class reference is used to refer to a child class object.
   /*t1.work();
   d1.work();*/
   //invoking the work methods according to different derieved classes.
   
   
   // as developer and teacher is inheriting from the employee 
   employee* e3=&d1;
   employee* e4=&t1;

   e3->work();
   e4->work();
   //it will show error
   // to make it work lets make the work virtual


   
   /* virtual function actually checks the definition of the
   function in the other derieved classes.*/
}
