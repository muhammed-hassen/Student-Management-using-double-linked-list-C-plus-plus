#include<iostream>
using namespace std;
class node{
	public:
		string name;
		int age;
		string sex;
		node* next;
		node* back;
		
};
class student{
	private:
		node* head;
		node* tail;
	public :
		void insert(string name,int age,string sex,int pos);
		void viewForward();
		void viewBackward();
		void search(string name);
		void delt(string name);
		student()
		{
			head=tail=NULL;
		}
		bool isEmpty()
		{
		  if(head==NULL)
		  	return true;
		else
			return false;
		}
		
};
void student::delt(string name)
{
	if(isEmpty())
	{
		cout<<"\nthe list is empty";
		
	}
	else
	{
		node* temp=head;
		while(temp && temp->name!=name)
		{
			temp=temp->next;
		}
		if(temp)//the item is found
		{
			if(temp->next)//not the last elt
			{
				if(temp->back)//not the first
				{
					temp->next->back=temp->back;
					temp->back->next=temp->next;
					temp->next=temp->back=NULL;
					delete temp;
					cout<<"\nsuccefuly delted from midddle";
				}
				else//the first elt
				{
					head=temp->next;
					temp->next->back=NULL;
					temp->next=NULL;
					delete temp;
					cout<<"\nsuccefuly deleted from the first postion ";
				}
				
			}
			else//the last elemnt
			{
				if(temp->back)//there are previous node
				{
					temp->back->next=NULL;
					tail=temp->back;
					temp->back=NULL;
					delete temp;
					cout<<"\nsuccefuly delted from last postion";
				}
				else//it only elt in the list
				{
					head=tail=NULL;
					delete temp;
					cout<<"\nsucefuly dleted the list becom empty";
				}
				
			}
			
		}
		else{
			cout<<"\nthere is no such record";
		}
	}
}
void student::search(string name)
{
	if(isEmpty())
	{
		cout<<"\nthe list is empty";
	}
	else
	{
		node* temp=head;
		while(temp && temp->name!=name)
		{
			temp=temp->next;
		}
		if(temp)//the elt is found
		{
			cout<<"\nName\tAge\tsex";
			cout<<"\n"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->sex;
		}
		else
		{
			cout<<"\nthere is no such record";
		}
	}
}
void student::insert(string name,int age,string sex,int pos)
{
	node* newnode=new node;
	newnode->name=name;
	newnode->age=age;
	newnode->sex=sex;
	if(pos==0)//case 1 at intial place
	{
		if(isEmpty())//if the list is empty
		{
			head=tail=newnode;
			newnode->next=newnode->back=NULL;
		}
		else
		{
			newnode->next=head;
			head->back=newnode;
			head=newnode;
			newnode->back=NULL;
		}
		cout<<"\nsucefully stored inthe intial place";
	}
	else if(pos>0)//case other option
	{
		node*temp=head;
		int i=1;
		while(temp && pos!=i)
		{
			temp=temp->next;
			i++;
		}
		if(temp)//the postion is valid
		{
			if(temp->next)//if it is the middle element
			{
				newnode->next=temp->next;
				temp->next->back=newnode;
				temp->next=newnode;
				newnode->back=temp;
				cout<<"\nsuccefully inserted in the middle";
			}
			else//insert at last
			{
				
				temp->next=newnode;
				newnode->back=temp;
				newnode->next=NULL;
				tail=newnode;
				cout<<"\nsuccefuly inserted in the last postion";
				
			}
			
		}
		else
		{
			cout<<"\nthe requested postion is out of range";
		}
	}
	else
	{
		cout<<"\nincorrect postion requested";
	}
}
void student::viewBackward()
{
	if(isEmpty())
	{
		cout<<"\nthe list is empty";
	}
	else
	{
		node* temp=tail;
		cout<<"\nName\tAge\tsex";
		while(temp)
		{
			cout<<"\n"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->sex;
			temp=temp->back;
		}
	}
}
void student::viewForward()
{
	if(isEmpty())
	{
		cout<<"\nthe list empty";
	}
	else
	{
	
		node* temp=head;
		cout<<"\nName\tAge\tsex";
		while(temp)
		{
			cout<<"\n"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->sex;
			temp=temp->next;
		}
	}
}
int main()
{
	int choice;
	string name,sex;
	int age,pos;
	student su;
	do
	{
		cout<<"\n========= student Managent ================";
		cout<<"\n1insert";
		cout<<"\n2view forward traverse";
		cout<<"\n3view backward travers";
		cout<<"\n4search";
		cout<<"\n5delete";
		cout<<"\n6exit";
		cin>>choice;
		switch(choice)
		{
			case 1:
				 cout<<"\nEnter name";
				 cin>>name;
				 cout<<"\nEnter age";
				 cin>>age;
				 cout<<"\nEnter sex";
				 cin>>sex;
				 cout<<"\nenter the postion";
				 cin>>pos;
				 su.insert(name,age,sex,pos);
				break;
			case 2:
				su.viewForward();
				break;
			case 3:
				su.viewBackward();
				break;
			case 4:
				cout<<"\nEnter Name";
				cin>>name;
				su.search(name);
				break;
			case 5:
				cout<<"\nEnter name";
				cin>>name;
				su.delt(name);
				break;
		}
		
	}while(choice!=6);
	
	
	
	
	return 0;
}
