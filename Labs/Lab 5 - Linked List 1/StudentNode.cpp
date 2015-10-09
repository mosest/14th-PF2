//----------------------------------------------
// Purpose: Demonstrate StudentNode ADT
// Author:  John Gauch
//----------------------------------------------

#include <iostream>
using namespace std;

class StudentNode
{
 public:
   // Constructors 
   StudentNode();
   StudentNode(string name, string address, float gpa);
   StudentNode(const StudentNode & node);
   ~StudentNode();

   // Methods
   string getName() const;
   string getAddress() const;
   float getGPA() const;
   StudentNode* getNext() const;
   void setName(string name);
   void setAddress(string address);
   void setGPA(float gpa);
   void setNext(StudentNode* node);
   void print() const;

 private:
	string Name;
	string Address;
	float GPA;
	StudentNode* Next;
};

//----------------------------------------------
StudentNode::StudentNode()
{
   Name = "";
   Address = "";
   GPA = 0;
   Next = NULL;
}

//----------------------------------------------
StudentNode::StudentNode(string name, string address, float gpa)
{
   Name = name;
   Address = address;
   GPA = gpa;
   Next = NULL;
}

//----------------------------------------------
StudentNode::StudentNode(const StudentNode & s)
{
   Name = s.Name;
   Address = s.Address;
   GPA = s.GPA;
   Next = s.Next;
}

//----------------------------------------------
StudentNode::~StudentNode()
{
}

//----------------------------------------------
string StudentNode::getName() const
{
   return Name;
}

//----------------------------------------------
string StudentNode::getAddress() const
{
   return Address;
}

//----------------------------------------------
float StudentNode::getGPA() const
{
   return GPA;
}

//----------------------------------------------
StudentNode* StudentNode::getNext() const
{
   return Next;
}

//----------------------------------------------
void StudentNode::setName(string name)
{
   Name = name;
}

//----------------------------------------------
void StudentNode::setAddress(string address)
{
   Address = address;
}

//----------------------------------------------
void StudentNode::setGPA(float gpa)
{
   GPA = gpa;
}

//----------------------------------------------
void StudentNode::setNext(StudentNode* n)
{
   Next = n;
}

//----------------------------------------------
void StudentNode::print() const
{
	cout << "Name: " << Name << "\n"
		<< "Address: " << Address << "\n" << "GPA: " << GPA << "\n";
	if (Next != NULL)       
	Next->print(); 
}

//----------------------------------------------
int main()
{
	string name; 
	string address;    
	float gpa;    
	StudentNode *head = NULL;    
	for (int i=0; i<3; i++)    
	{
	   cout << "Enter name: ";
	   cin >> name;
	   cout << "Enter address: ";
	   cin >> address;
	   cout << "Enter GPA: ";
	   cin >> gpa;
	   
	   // ADD HERE
	   StudentNode *temporaryPerson = new StudentNode(name, address, gpa);
	   temporaryPerson->setNext(head);
	   head = temporaryPerson;
	}
	head->print(); 
}
